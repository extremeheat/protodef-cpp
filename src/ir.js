/* eslint-disable no-return-assign, no-sequences, no-unused-vars */
const fs = require('fs')

// Resolve switch statements' compareTo's
function preprocess (schema, logging) {
  const log = logging ? console.log : () => {}
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
    let nonAnonLevelsUp = 0
    while (current) {
      for (const _current of current) {
        if (_current.name === untilMatch) {
          Object.assign(_current, injectable)
          _current.usedLevelsDown = nonAnonLevelsUp
          return _current
        }
      }
      // if (!current.parent) console.log('Top most')
      if (current.scopeIsAnon) nonAnonLevelsUp--
      nonAnonLevelsUp++
      // console.dir(current, { depth: null })
      current = current.parent
    }
  }

  function visitContainer (container, parent, anon) {
    container.scopeIsAnon = !!anon
    container.parent = parent
    for (const { name, type, anon } of container) {
      visitType(type, container, anon)
    }
  }

  function visitType (type, parent, anon) {
    if (typeof type === 'string') {
      // pass
    } else if (Array.isArray(type)) {
      type.scopeIsAnon = !!anon
      type.parent = parent

      if (schema[type[0]] && (schema[type[0]][0] === 'switch')) {
        log('Inlining root switch', type[0])
        const rootSwitch = schema[type[0]][1]
        const next = { ...rootSwitch, ...type[1] }
        type[0] = 'switch'
        type[1] = next
        log('Inlined root switch', JSON.stringify(type))
      }

      const [name, ...args] = type
      if (name === 'container') {
        visitContainer(args[0], parent, anon)
      } else if (name === 'switch') {
        const cases = args[0].fields
        cases.default = args[0].default
        const [compareTo, shouldReplace] = fixCompareToType(args[0].compareTo)
        if (shouldReplace) {
          log('Replacing compareTo', args[0].compareTo, '->', shouldReplace)
          args[0].compareTo = shouldReplace
        }
        if (compareTo.startsWith('/')) {
          // Root variables, these are specially defined by the user
        } else {
          log('Injecting compareTo', compareTo)
          const injectedObj = walkBackwardAndInject(compareTo, parent, { comparedTo: true })
          if (injectedObj) {
            // TODO: handle more than just mapper
            if (injectedObj.type[0] === 'mapper') args[0].compareToType = 'mapper'
            else args[0].compareToType = injectedObj.type
            if (!args[0].compareToType) throw Error('Could not find compareTo ' + compareTo)
            // else console.log('Found compareTo', compareTo, '->', args[0].compareToType)
            args[0].compareToType = '../'.repeat(injectedObj.usedLevelsDown) + '' + args[0].compareToType
          } else throw Error('Could not find compareTo ' + compareTo)
        }
        for (const [caseName, caseType] of Object.entries(cases)) {
          visitType(caseType, parent, anon)
        }
      } else if (name === 'array') {
        if (typeof args[0].count === 'string') {
          const injectedObj = walkBackwardAndInject(args[0].count, parent, { counted: true })
          if (injectedObj) {
            args[0].countVarType = injectedObj.type
          } else throw Error('Could not find count variable: ' + args[0].count)
        }
        visitType(args[0].type, parent)
      } else if (name === 'option') {
        // TODO: proper backend support for option
        // turn this into a switch
        const nextContainer = [
          { name: 'has', type: 'bool' },
          {
            name: 'value',
            type: [
              'switch',
              { compareTo: 'has', compareToType: 'bool', fields: { true: args[0] } }
            ]
          }
        ]
        type[0] = 'container'
        type[1] = nextContainer
        // Now visit the new container
        visitContainer(nextContainer, parent, anon)
      }
    }
  }

  for (const typeName in schema) {
    const rootType = schema[typeName]
    // mcdata-pc handling
    const typename = rootType[0]
    if (typename === 'switch') {
      log('Ignoring root-level switch statement [', typeName, '], will be inlined later')
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

function processSchema (bloatedSchema, logging) {
  const debugLog = logging ? console.log : () => {}
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
          if (log) debugLog('Type Groups with dupes', typeGroups, Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))
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
              debugLog('Combined ', [...typeGroups[group]], 'into', newKey, 'with', group)
            }
            for (const k of rest) {
              delete this.vars[k]
            }
          }
          // console.log('After pruning', Object.entries(this.vars).map(([k, v]) => [k, JSON.stringify(v)]))
          this.typesForKey[key] = next
        }
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
    // debugLog('Visiting...', JSON.stringify(root), isAnonIteration ? '(anon)' : '')

    function handleSwitch (newName, args, anon, simplified) {
      const next = new Scope()
      const sharedScope = new Scope()
      if (args.fields.default && (args.default !== args.fields.default)) throw new Error('`default` is a reserved field in switch, please rename')
      if (args.default) args.fields.default = args.default
      for (const field in args.fields) {
        const val = args.fields[field]
        if (typeof val === 'string') {
          next.add(field, [val])
          if (val === 'void') continue
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
            const nextField = new Scope()
            handleSwitch(field, _args, false, nextField)
            for (const f in nextField.vars) {
              if (f.endsWith('?')) {
                next.add(field, nextField.vars[f])
              } else {
                sharedScope.add(field, nextField.vars[f])
              }
            }
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
            }
          } else {
            debugLog('Unknown type', _actualType, _args)
            sharedScope.add(field, [_actualType, _args])
            next.add(field, [_actualType, _args])
          }
        }
      }

      simplified.add(newName + '?', ['switch', fixCompareToType(args.compareTo), args.compareToType, next])
      if (!args.compareToType) throw new Error('Missing compareToType ' + JSON.stringify(args))
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
    const [n] = cleanName(name)
    // console.log('Visiting switch', name, switchType, optionalsInNS, n)
    const isAnon = name.startsWith('_')
    const [compareTo, compareToType, cases] = switchType
    // Move default to the end
    if (cases.default) {
      const defaultCase = cases.default
      delete cases.default
      cases.default = defaultCase
    }

    for (const caseName in cases) {
      const type = fixType(cases[caseName])
      if (type[0] === 'void') continue // void is important for switch statements with a case==0 and default
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
            // console.log('Added', optionalsInNS[N][json], 'to', cases[caseName][fieldName])
          } else {
            // console.log('Optionals so far', optionalsInNS, cases[caseName][fieldName])
            throw new Error('Error in anon switch during postprocess for ' + fieldName)
          }
        }
      } else {
        const json = JSON.stringify(type)
        if (optionalsInNS[n][json]) {
          if (Array.isArray(cases[caseName])) { queueForAssignment(cases[caseName], 5, optionalsInNS[n][json]) } else { queueForAssignment(cases[caseName], '*name', optionalsInNS[n][json]) }
          // console.log('Added')
        } else {
          // console.log('Optionals so far', optionalsInNS, cases[caseName])
          throw new Error(`Error in switch during postprocess ${caseName} ${json} ${n}`)
        }
      }
      // console.log('Would visit', caseName, cases[caseName])
      visitType(caseName, cases[caseName])
    }
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
  generate (schema) {
    const pp = preprocess(schema)
    const from = processSchema(pp)
    const cloned = JSON.parse(JSON.stringify(from))
    // fs.writeFileSync('tmp.json', JSON.stringify(cloned, null, 2))
    const final = postprocess(cloned)
    return final
  }
}

// if (!module.parent) {
//   const schema = require('./__tmp/protocol.json').types
//   // move mcpe_packet to the end
//   const oldmcpePacket = schema.mcpe_packet
//   delete schema.mcpe_packet
//   schema.mcpe_packet = oldmcpePacket
//   const final = module.exports.generate(schema)
//   fs.writeFileSync('./redone.json', JSON.stringify(final, null, 2))
// }

// Broken: Shaped recipes with array-array nesting and input=width*height
//  this should be specially handled in the IR with a new multidimensional array
//  to avoid a lot of complexity in the generator
// Broken: can't use `default` as a field name in switch

// IR:
// Object key with a "?" prefix is promoted field from a switch or anonymous container
// Object key with a "?" suffix is a switch
// Object key with a "^" suffix is a variable that will be used later in a switch or array count: it needs to be ready in for a local nested scope
// Object key with a "_" prefix is an anonymous field.
// Object key with a "*name" name signifies a key whose value points to the promoted variable name of a switch's case
