const fs = require('fs')
// const basicJSON = require('./sample.json')

// struct ScoreEntries {
//   enum : int {
//     Change,
//     Remove
//   } type;
//   struct EntriesStruct {
//     int scoreboard_id;
//     std::string objective_name;
//     int score;
//     enum : int {
//       player,
//       entity,
//       fake_player
//     } entry_type;
//     int entity_unique_id;
//     std::string custom_name;
//   } *entries;
//   int entries_count;
// };

// const want = {
//   ScoreEntries: {
//     type: ['u8', ['change', 'remove']],
//     entries: ['array', 'varint', {
//       scoreboard_id: ['varint'],
//       objective_name: ['string'],
//       score: ['varint'],
//       _: [
//         'switch', '../type', {
//           remove: ['^entry_type']
//         }
//       ],
//       '?entry_type': ['u8', ['player', 'entity', 'fake_player']],
//       '?entity_unique_id': ['varint'],
//       '?custom_name': ['string']
//     }]
//   }
// }


// Resolve switch statements' compareTo's
function preprocess (schema) {
  function fixCompareToType (type) {
    let fix = type.replaceAll('../', '')
    if (fix.startsWith('/')) return type
    return fix.split('.')[0]
  }

  function walkBackwardAndInject (untilMatch, parent, injectable) {
    let current = parent
    while (current) {
      for (const _current of current) {
        if (_current.name === untilMatch) {
          Object.assign(_current, injectable)
          console.log('Injected', injectable, 'into', _current)
          return _current
        }
      }
      if (!current.parent) {
        console.log('Top most', current)
      }
      current = current.parent
    }
  }

  function visitContainer (container, parent) {
    container.parent = parent
    for (const { name, type } of container) {
      visitType(type, container)
    }
  }

  function visitType (type, parent) {
    if (typeof type === 'string') {
      return
    } else if (Array.isArray(type)) {
      type.parent = parent
      const [name, ...args] = type
      if (name === 'container') {
        visitContainer(args[0], parent)
      } else if (name === 'switch') {
        const cases = args[0].fields
        let compareTo = fixCompareToType(args[0].compareTo);
        if (compareTo.startsWith('/')) {
          // Special case, ignore for now
        } else {
          console.log('Injecting compareTo', compareTo)
          const injectedObj = walkBackwardAndInject(compareTo, parent, { comparedTo: true })
          if (injectedObj) {
            // TODO: handle more than just mapper
            if (injectedObj.type[0] === 'mapper') args[0].compareToType = 'mapper'
            else args[0].compareToType = injectedObj.type
          } else throw Error('Could not find compareTo ' + compareTo)
        }
        for (const [caseName, caseType] of Object.entries(cases)) {
          visitType(caseType, parent)
        }
      } else if (name === 'array') {
        if (typeof args[0].count === 'string') {
          console.log('Injecting array count', args)
          const injectedObj = walkBackwardAndInject(args[0].count, parent, { counted: true })
          if (injectedObj) {
            args[0].countVarType = injectedObj.type
          } else throw Error('Could not find count variable: ' + args[0].count)
        }
        visitType(args[0].type, parent)
      }
    }
  }

  for (const typeName in schema) {
    visitType(schema[typeName], schema)
  }
}

// Yes, it's a mess. I'm sorry.
function debloatSchema (bloatedSchema) {
  let i = 0

  class Scope {
    constructor () {
      this.vars = {}
      this.typesForKey = {}
      this.uniqueKeys = []
      this.didSimplify = false
    }

    get (name) {
      return this.vars[name]
    }

    _set (name, type) {
      if (this.didSimplify) throw Error('Cannot add to scope after deduplication')
      if (this.uniqueKeys.includes(name)) {
        if (Object.hasOwn(this.vars, name)) {
          // If name is taken, make sure to add a suffix to existing name
          const old = this.vars[name]
          this.vars[name + ',' + (i++)] = old
          this.vars[name + ',' + (i++)] = type
        } else {
          this.vars[name + ',' + (i++)] = type
        }
      } else {
        this.uniqueKeys.push(name)
        this.vars[name] = type
      }
      const [n] = name.split(',')
      this.typesForKey[n] ??= []
      this.typesForKey[n].push(type)
    }

    add (name, type) { return this._set(name, type) }
    addMaybe (name, type) { return this._set('?' + name, type) }

    dedupeAnon () {
      const deleteAllAnonSubTypes = (forKey) => {
        for (const key in this.vars) {
          if (key.startsWith(forKey + ',') || key === forKey) {
            delete this.vars[key]
          }
        }
      }

      for (const key in this.typesForKey) {
        if (!key.startsWith('?')) continue
        const types = this.typesForKey[key]
        const first = types[0]
        if (types.every(t => JSON.stringify(t) === JSON.stringify(first))) {
          // console.log('Deduping all the same', key, types)
          deleteAllAnonSubTypes(key)
          this.vars[key] = first
          this.typesForKey[key] = [first]
        } else {
          const found = []
          const next = []
          // console.log('Deduping some the same', key)
          const typeGroups = {}
          for (const type of types) {
            const str = JSON.stringify(type)
            if (!found.includes(str)) {
              found.push(str)
              next.push(type)
            }
            typeGroups[str] ??= new Set()
            for (const _key in this.vars) {
              // console.log(_key, key)
              if (_key.startsWith(key + ',') || _key === key) {
                const val = this.vars[_key]
                // console.log('val',JSON.stringify(val))
                // console.log('val', str)
                if (JSON.stringify(val) === str) typeGroups[str].add(_key)
              }
            }
          }
          // console.log('Type Groups', typeGroups, Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))
          // console.log('Before pruning', Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))

          for (const group in typeGroups) {
            if (group === '["void"]') {
              // delete everything
              for (const k of typeGroups[group]) {
                delete this.vars[k]
              }
              continue
            }
            const [first, ...rest] = typeGroups[group]
            // See if we have a better name for `first`
            let name = first
            const f = JSON.parse(group)
            if (f.length === 1 && typeof f[0] === 'string') {
              name = `${key},${f[0]}`
              const old = this.vars[first]
              delete this.vars[first]
              this.vars[name] = old
            }
            // console.log('First', first, name)
            // this.vars[name] = JSON.parse(group)
            for (const k of rest) {
              delete this.vars[k]
            }
          }
          // console.log('After pruning', Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))
          this.typesForKey[key] = next
        }

        // if (key.includes('destination')) {
        //   console.dir(this.typesForKey, {depth: null})
        //   console.dir(this.vars, {depth: null})
        //   // console.log(JSON.stringify(this.typesForKey['?block_action,array'][0]))
        //   // console.log(JSON.stringify(this.vars['?block_action,array']))
        //   throw Error()
        // }
      }

      // Make sure we actually did simplify things
      for (const key in this.typesForKey) {
        const set = new Set()
        const types = this.typesForKey[key]
        for (const type of types) {
          const str = JSON.stringify(type)
          if (set.has(str)) {
            console.log(this.vars)
            console.log(this.typesForKey)
            throw Error('Deduplication failed')
          }
          set.add(str)
        }
      }

      this.didSimplify = true
    }

    finish () {
      this.dedupeAnon()
    }

    toJSON () {
      return this.vars
      // return { ...this.vars, didSimplify: this.didSimplify }
    }
  }

  function fixCompareToType (type) {
    let fix = type.replaceAll('../', '')
    if (fix.startsWith('/')) return type
    if (fix.includes('.') || fix.includes('||')) {
      // update_flags.initialisation || update_flags.decoration || update_flags.texture
      // -> [update_flags, [initialisation, decoration, texture]]
      const n = fix.includes('.') ? fix.split('.')[0] : fix.split('||')[0]
      return [n, fix.split('||').map(e => e.split('.')[1]), type, type.includes('||') ? 'bool' : null]
    }
    return fix
  }

  function visit (root, simplified, isAnonIteration = false) {
    // console.log('Visiting...', JSON.stringify(root), isAnonIteration ? '(anon)' : '')

    function handleSwitch (newName, args, anon, simplified) {
      const next = new Scope()
      const sharedScope = new Scope()
      if (args.fields.default && (args.default !== args.fields.default)) throw new Error('`default` is a reserved field in switch, please rename')
      if (args.default) args.fields.default = args.default
      for (const field in args.fields) {
        const val = args.fields[field]
        if (typeof val === 'string') {
          if (val === 'void') continue
          next.add(field, [val])
          sharedScope.add('', [val])
        } else if (Array.isArray(val)) {
          const [_actualType, _args] = val
          if (_actualType === 'container') {
            const nextField = new Scope()
            visit(_args, nextField)
            if (anon) {
              visit(_args, sharedScope)
            } else {
              sharedScope.add(field, nextField)
            }
            next.add(field, nextField)
            // if (anon) visit(_args, simplified, true)
            nextField.finish()
          } else if (_actualType === 'switch') {
            // throw new Error('Nested switch not supported')
            const nextField = new Scope()
            handleSwitch(field, _args, false, nextField)
            // console.log('NextScope for switch')
            // console.dir(nextField, { depth: null })
            for (const f in nextField.vars) {
              if (f.endsWith('?')) {
                next.add(field, nextField.vars[f])
              } else {
                sharedScope.add(field, nextField.vars[f])
              }
            }
            // handleSwitch(field, _args, false, sharedScope)
            // next.add(field, nextField/*.get('default?')*/)
            // if (anon) handleSwitch(field, _args, true, simplified)
            nextField.finish()
          } else if (_actualType === 'mapper') {
            // This is adding to the nested scope of the switch:
            next.add(field, ['mapper', _args.type, _args.mappings])
            // This is added to the parent for each type combo of the switch:
            sharedScope.add('mapper', ['mapper', _args.type, _args.mappings])
            // This just adds all the children of the switch to the parent, without any wrapper:
            // if (anon) simplified.addMaybe(field, ['mapper', _args.type, _args.mappings])
          } else if (_actualType === 'array') {
            const count = _args.count ? [_args.count, _args.countVarType] : null
            if (typeof _args.type === 'string') {
              next.add(field, ['array', _args.countType, count, [_args.type]])
              sharedScope.add('array', ['array', _args.countType, count, [_args.type]])
            } else {
              if (_args.type[0] === 'switch') {
                throw new Error('Nested switch-array-switch not supported, please rewrite schema')
              }
              const children = new Scope()
              // visit(_args.type[1], children)
              if (anon) {
                simplified.addMaybe(field, ['array', _args.countType, count, children])
                throw new Error('Anon switch cannot have an arrays as child : would have an undefined name')
              } else {
                handleType(field, _args.type, false, children)
                const unwrap = children.get(field)
                next.add(field, ['array', _args.countType, count, unwrap])
                sharedScope.add('array', ['array', _args.countType, count, unwrap])
              }
              children.finish()
              // if (newName.includes('block_action')) {
              //   console.dir(children, {depth: null})
              //   throw Error()
              // }
            }
          }
        }
      }

      simplified.add(newName + '?', ['switch', fixCompareToType(args.compareTo), args.compareToType, next])
      // simplified[newName] = sharedScope
      for (const key in sharedScope.vars) {
        simplified.addMaybe(anon ? key : newName, sharedScope.vars[key])
      }

      // if (args.fields[0] === 'void')  {
      //   console.log('Shared Scope', sharedScope)
      //   console.log('Result', simplified)
      // }

      // if (anon) {
      //   simplified.add(newName, ['switch', args.compareTo, next])
      //   // anon is handled above
      // } else {

      // }
      next.finish()
      // sharedScope.finish()
    }

    function handleType (name, type, anon, simplified) {
      if (typeof type === 'string') type = [type]
      const newName = anon ? ('_' + i++) : name
      const addToScope = (...a) => isAnonIteration ? simplified.addMaybe(...a) : simplified.add(...a)
      // this is handled inside Scope:
      // newName = isAnonIteration ? ('?' + newName) : newName
      // newName = disambiguateField(newName, type, simplified)
      const [actualType, args] = type
      if (actualType === 'container') {
        const scope = new Scope()
        visit(args, scope)
        addToScope(newName, scope)
        if (anon) visit(args, simplified, true)
        scope.finish()
      } else if (actualType === 'switch') {
        handleSwitch(newName, args, anon, simplified)
      } else if (actualType === 'mapper') {
        addToScope(newName, ['mapper', args.type, args.mappings])
      } else if (actualType === 'array') {
        // visit(args.type[1], children)
        const count = args.count ? [args.count, args.countVarType] : null
        if (typeof args.type === 'string') {
          addToScope(newName, ['array', args.countType, count, [args.type]])
        } else {
          if (args.type[0] === 'switch') {
            handleSwitch(newName, args.type[1], anon, simplified)
          } else {
            const children = new Scope()
            handleType('array', args.type, false, children)
            const unwrap = children.get('array') || children.get('?array')
            if (!unwrap) {
              console.dir(children, { depth: null })
              throw new Error('No array in children')
            }
            addToScope(newName, ['array', args.countType, count, unwrap])
            children.finish()
          }

          // if (newName.includes('block_action')) {
          //   console.dir(children, {depth: null})
          //   throw Error()
          // }
        }
      } else {
        // console.warn('! Unknown type', actualType, args)
        addToScope(newName, [actualType, args])
      }
    }

    function handleContainer () {
      for (let { name, type, anon, comparedTo } of root) {
        if (comparedTo) name += '^'
        if (typeof type === 'string') {
          isAnonIteration ? simplified.addMaybe(name, [type]) : simplified.add(name, [type])
          continue
        } else if (Array.isArray(type)) {
          handleType(name, type, anon, simplified)
        }
      }
    }

    handleContainer()
  }

  const simplified = new Scope()
  for (const name in bloatedSchema) {
    const type = bloatedSchema[name]
    if (Array.isArray(type)) {
      if (type[0] === 'container') {
        const nextScope = new Scope()
        visit(bloatedSchema[name][1], nextScope)
        simplified.add(name, nextScope)
        nextScope.finish()
      } else {
        // visit() only takes containers, so we have to wrap&unwrap it
        const obj = new Scope()
        visit([{ name, type }], obj)
        simplified.add(name, obj.get(name))
        obj.finish()
      }
    } else simplified.add(name, [type])
  }
  simplified.finish()
  // console.dir(simplified, { depth: null })
  return simplified
}

module.exports = {
  generate (from) {
    return debloatSchema(from)
  }
}

if (!module.parent) {
// debloatSchema(basicJSON)
  const pp = preprocess(require('./protocol.json').types)
  const redone = debloatSchema(require('./protocol.json').types)
  // const redone = debloatSchema(require('./proto2.json').types)
  fs.writeFileSync('./redone.json', JSON.stringify(redone, null, 2))
}


// Broken: Shaped recipes with array-array nesting and input=width*height