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
    const fix = type.replaceAll('../', '')
    if (fix.startsWith('/')) return [type]
    // mcdata-pc
    if (fix.includes('/')) { // if we *still* have a slash, it's likely supposed to be a dot
      const x = fix.replaceAll('/', '.')
      return [x.split('.')[0], x]
    }
    // end mcdata-pc
    return [fix.split('.')[0]]
  }

  function walkBackwardAndInject (untilMatch, parent, injectable) {
    let current = parent
    while (current) {
      for (const _current of current) {
        if (_current.name === untilMatch) {
          Object.assign(_current, injectable)
          // console.log('Injected', injectable, 'into', _current)
          return _current
        }
      }
      if (!current.parent) {
        // console.log('Top most', current)
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

    } else if (Array.isArray(type)) {
      type.parent = parent

      if (schema[type[0]] && (schema[type[0]][0] === 'switch')) {
        console.log('Inlining root switch', type[0])
        const rootSwitch = schema[type[0]][1]
        const next = { ...rootSwitch, ...type[1] }
        type[0] = 'switch'
        type[1] = next
        console.log('Inlined root switch', JSON.stringify(type))
      }

      const [name, ...args] = type
      if (name === 'container') {
        visitContainer(args[0], parent)
      } else if (name === 'switch') {
        const cases = args[0].fields
        cases.default = args[0].default
        const [compareTo, shouldReplace] = fixCompareToType(args[0].compareTo)
        if (shouldReplace) {
          console.log('Replacing compareTo', args[0].compareTo, '->', shouldReplace)
          args[0].compareTo = shouldReplace
        }
        if (compareTo.startsWith('/')) {
          // Special case, ignore for now
        } else {
          console.log('Injecting compareTo', compareTo)
          const injectedObj = walkBackwardAndInject(compareTo, parent, { comparedTo: true })
          if (injectedObj) {
            // TODO: handle more than just mapper
            if (injectedObj.type[0] === 'mapper') args[0].compareToType = 'mapper'
            else args[0].compareToType = injectedObj.type
            if (!args[0].compareToType) throw Error('Could not find compareTo ' + compareTo)
            // else console.log('Found compareTo', compareTo, '->', args[0].compareToType)
          } else throw Error('Could not find compareTo ' + compareTo)
        }
        for (const [caseName, caseType] of Object.entries(cases)) {
          visitType(caseType, parent)
        }
      } else if (name === 'array') {
        if (typeof args[0].count === 'string') {
          // console.log('Injecting array count', args)
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
    const rootType = schema[typeName]
    // mcdata-pc handling
    const typename = rootType[0]
    if (typename === 'switch') {
      console.log('Ignoring root-level switch statement [', typeName, '], will be inlined later')
      continue
    }
    // end mcdata-pc handling
    visitType(rootType, schema)
  }
  // mcdata handling: delete all root-level switch statements as they've been inlined
  for (const typeName in schema) {
    const rootType = schema[typeName]
    const typename = rootType[0]
    if (typename === 'switch') {
      delete schema[typeName]
    }
  }
  // end mcdata handling
  return schema
}

// Yes, it's a mess.
function debloatSchema (bloatedSchema) {
  let i = 0

  class Scope {
    constructor () {
      this.vars = {}
      this.varMetadata = {}
      this.typesForKey = {}
      this.uniqueKeys = []
      this.didSimplify = false
    }

    get (name) {
      return this.vars[name]
    }

    _set (name, type, metadata) {
      if (this.didSimplify) throw Error('Cannot add to scope after deduplication')
      function setSafe (obj, key, val) {
        if (obj[key]) throw Error('Cannot overwrite ' + key)
        obj[key] = val
      }
      if (this.uniqueKeys.includes(name)) {
        if (Object.hasOwn(this.vars, name)) {
          // If name is taken, make sure to add a suffix to existing name
          const old = this.vars[name]
          const oldMeta = this.varMetadata[name]
          delete this.vars[name]
          delete this.varMetadata[name]
          setSafe(this.vars, name + ',' + (oldMeta || i++), old)
          const n = name + ',' + (metadata || i++)
          setSafe(this.vars, n, type)
          this.varMetadata[n] = metadata
        } else {
          const n = name + ',' + (metadata || i++)
          setSafe(this.vars, n, type)
          this.varMetadata[n] = metadata
        }
      } else {
        this.uniqueKeys.push(name)
        this.vars[name] = type
        this.varMetadata[name] = metadata
      }
      const [n] = name.split(',')
      this.typesForKey[n] ??= []
      this.typesForKey[n].push(type)
    }

    add (name, type, metadata) { return this._set(name, type, metadata) }
    addMaybe (name, type, metadata) { return this._set('?' + name, type, metadata) }

    dedupeAnon () {
      // TODO: this function causes reordering of the object keys, which is not ideal
      // it's ok because it only is adding "?" prefix fields that are only used in struct
      // generation and not for size/encode/decode step (for those steps "?" prefix are ignored).
      const deleteAllAnonSubTypes = (forKey) => {
        for (const key in this.vars) {
          if (key.startsWith(forKey + ',') || key === forKey) {
            delete this.vars[key]
          }
        }
      }

      for (const key in this.typesForKey) {
        if (!key.startsWith('?')) continue
        // console.log('With key', key)
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
          let log = false
          for (const typeGroup in typeGroups) {
            if (typeGroups[typeGroup].size > 1) log = true
          }
          if (log) console.log('Type Groups with dupes', typeGroups, Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))
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
            } else if (typeGroups[group].size > 1) {
              const bodies = []
              for (const entry of typeGroups[group]) {
                const [header, body] = entry.split(',')
                bodies.push(body)
                delete this.vars[entry]
              }
              const body = bodies.join('_or_')
              const newKey = `${key},${body}`
              this.vars[newKey] = JSON.parse(group)
              console.log('Combined ', [...typeGroups[group]], 'into', newKey, 'with', group)
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
    const fix = type.replaceAll('../', '')
    if (fix.startsWith('/')) return type
    if (fix.includes('.') || fix.includes('||')) {
      // update_flags.initialisation || update_flags.decoration || update_flags.texture
      // -> [update_flags, [initialisation, decoration, texture]]
      const n = fix.includes('.') ? fix.split('.')[0] : fix.split('||')[0]
      return [n, fix.split('||').map(e => e.split('.')[1]), type, type.includes('||') ? 'bool' : null]
    }
    return fix
  }

  function sanitizeMapper (type) {
    const vals = []
    let i = 0
    for (const key in type) {
      const val = type[key]
      if (vals.includes(val)) {
        type[key] = val + '_' + (i++)
      }
      vals.push(val)
    }
    return type
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
            next.add(field, ['mapper', _args.type, sanitizeMapper(_args.mappings)])
            // This is added to the parent for each type combo of the switch:
            sharedScope.add('mapper', ['mapper', _args.type, sanitizeMapper(_args.mappings)])
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
          } else {
            console.log('Unknown type', _actualType, _args)
            sharedScope.add(field, [_actualType, _args])
            next.add(field, [_actualType, _args])
          }
        }
      }

      simplified.add(newName + '?', ['switch', fixCompareToType(args.compareTo), args.compareToType, next])
      if (!args.compareToType) throw new Error('Missing compareToType ' + JSON.stringify(args))
      // simplified[newName] = sharedScope
      for (const key in sharedScope.vars) {
        simplified.addMaybe(anon ? key : newName, sharedScope.vars[key], key)
      }
      // console.log('Shared Scope', sharedScope)
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
        addToScope(newName, ['mapper', args.type, sanitizeMapper(args.mappings)])
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
      for (let { name, type, anon, comparedTo, counted } of root) {
        if (comparedTo || counted) name += '^'
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

function postprocess (schema) {
  const fixType = (v) => Array.isArray(v) ? v : (['container', v])
  const cleanName = name => name.replaceAll('?', '').replaceAll('^', '').split(',')

  const assignmentQueue = []
  function queueForAssignment (obj, name, type) {
    assignmentQueue.push([obj, name, type])
  }

  function visitContainer (name, container, optionalsInNS) {
    // console.log('Visiting container', name, container, optionalsInNS)
    const maybes = name.startsWith('_') ? optionalsInNS : {}
    // first we collect all the optionals
    for (const name in container) {
      const [n] = cleanName(name)
      const type = fixType(container[name])
      if (name.startsWith('?')) {
        maybes[n] ??= {}
        maybes[n][JSON.stringify(type)] ??= name
      }
    }
    // if (Object.keys(maybes).length > 0) console.log('maybes', maybes)
    // then we can actually recurse
    for (const name in container) {
      const [n] = cleanName(name)
      const type = fixType(container[name])
      if (!name.startsWith('?')) {
        const j = JSON.stringify(type)
        if (maybes[n]?.[j]) {
          // console.log('Found maybe', maybes[n][j], name)
          // container[name][5] = maybes[j]
          throw Error()
        }
      }
      visitType(name, type, maybes)
    }
  }
  function visitSwitch (name, switchType, optionalsInNS) {
    // console.log('visiting switch', name, switchType, optionalsInNS)
    const [n] = cleanName(name)
    // console.log('Visiting switch', name, switchType, optionalsInNS, n)
    const isAnon = name.startsWith('_')
    const [compareTo, compareToType, cases] = switchType
    for (const caseName in cases) {
      const type = fixType(cases[caseName])
      if (type[0] === 'switch') {
        // console.log('Visiting nested switch', caseName, type)
        visitSwitch(n, type.slice(1), optionalsInNS)
        break
      }
      if (isAnon) {
        for (const fieldName in cases[caseName]) {
          const json = JSON.stringify(cases[caseName][fieldName])
          const [N] = cleanName(fieldName)
          if (optionalsInNS[N][json]) {
            if (Array.isArray(cases[caseName][fieldName])) { queueForAssignment(cases[caseName][fieldName], 5, optionalsInNS[N][json]) } else { queueForAssignment(cases[caseName][fieldName], '*name', optionalsInNS[N][json]) }
            // console.log('Added!', optionalsInNS[N][json], 'to', cases[caseName][fieldName])
          } else {
            // console.log('Optionals so far', optionalsInNS, cases[caseName][fieldName])
            throw new Error('Error in anon switch during postprocess for ' + fieldName)
          }
        }
      } else {
        const json = JSON.stringify(type)
        if (optionalsInNS[n][json]) {
          if (Array.isArray(cases[caseName])) { queueForAssignment(cases[caseName], 5, optionalsInNS[n][json]) } else { queueForAssignment(cases[caseName], '*name', optionalsInNS[n][json]) }
          // console.log('Added!')
        } else {
          // console.log('Optionals so far', optionalsInNS, cases[caseName])
          throw new Error(`Error in switch during postprocess ${caseName} ${json} ${n}`)
        }
      }
      // console.log('Would visit', caseName, cases[caseName])
      visitType(caseName, cases[caseName])
    }
    // if (name.includes('_1406')) {
    //   console.log('dbg', isAnon)
    //   process.exit()
    // }
  }
  function visitType (name, type, optionalsInNS) {
    const [typeName, ...args] = fixType(type)
    // console.log('Visiting type', name, typeName, type, optionalsInNS)
    if (name.startsWith('*')) return // Special handling only applicable to generator
    if (typeName === 'container') {
      visitContainer(name, args[0], optionalsInNS)
    } else if (typeName === 'switch') {
      visitSwitch(name, args, optionalsInNS)
    } else if (typeName === 'array') {
      const actualType = fixType(args[2])
      // console.log('actualType', actualType)
      if (actualType[0] === 'container') {
        visitContainer(name, actualType[1], optionalsInNS)
      }
    }
  }
  for (const name in schema) {
    const type = schema[name]
    visitType(name, type)
  }

  // console.log('Assignment Q', assignmentQueue)
  for (const [obj, name, type] of assignmentQueue) {
    obj[name] = type
  }

  return schema
}

module.exports = {
  generate (from) {
    return debloatSchema(from)
  }
}

if (!module.parent) {
  // debloatSchema(basicJSON)
  // const pc1_18 = require('./pc1_18.json')
  // let schema = { ...pc1_18.types, ...pc1_18.play.toClient.types } 
  let schema = require('./protocol.json').types
  // move mcpe_packet to the end
  const oldmcpe_packet = schema.mcpe_packet
  delete schema.mcpe_packet
  schema.mcpe_packet = oldmcpe_packet
  // schema = {
  //   // ItemLegacy:schema.ItemLegacy,
  //   // Recipes:schema.Recipes,
  //   packet_text: schema.packet_text,
  //   packet_interact: schema.packet_interact,
  // }
  const pp = preprocess(schema)
  const redone = debloatSchema(pp)
  // const redone = debloatSchema(require('./proto2.json').types)
  const json = JSON.stringify(redone, null, 2)
  fs.writeFileSync('./redone.json', JSON.stringify(redone, null, 2))
  const final = postprocess(JSON.parse(json, null, 2))
  fs.writeFileSync('./redone.json', JSON.stringify(final, null, 2))
}

// Broken: Shaped recipes with array-array nesting and input=width*height

// IR:
// Object key with a "?" prefix is promoted field from a switch or anonymous container
// Object key with a "?" suffix is a switch
// Object key with a "^" suffix is a variable that will be used later in a switch or array count: it needs to be ready in for a local nested scope
// Object key with a "_" prefix is an anonymous field.
// Object key with a "*name" name signifies a key whose value points to the promoted variable name of a switch's case
