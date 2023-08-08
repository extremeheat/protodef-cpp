const fs = require('fs')
const basicJSON = require('./sample.json')

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

const protodefTypeToCpp = {
  u8: 'uint8_t',
  u16: 'uint16_t',
  u32: 'uint32_t',
  u64: 'uint64_t',
  i8: 'int8_t',
  i16: 'int16_t',
  i32: 'int32_t',
  i64: 'int64_t',
  f32: 'float',
  f64: 'double',
  bool: 'bool',
  varint: 'int',
  string: 'std::string',
  buffer: 'std::vector<uint8_t>'
}

const want = {
  ScoreEntries: {
    type: ['u8', ['change', 'remove']],
    entries: ['array', 'varint', {
      scoreboard_id: ['varint'],
      objective_name: ['string'],
      score: ['varint'],
      _: [
        'switch', '../type', {
          remove: ['^entry_type'],
        }
      ],
      '?entry_type': ['u8', ['player', 'entity', 'fake_player']],
      '?entity_unique_id': ['varint'],
      '?custom_name': ['string']
    }]
  }
}

// Yes, it's a mess. I'm sorry.
function debloatSchema(bloatedSchema) {
  let i = 0

  class Scope {
    constructor() {
      this.vars = {}
    }
  
    get(name) {
      return this.vars[name]
    }
  
    set(name, type) {
      if (Object.hasOwn(this.vars, name)) {
        const old = this.vars[name]
        this.vars[name + ',']
      }
      this.vars[name] = type
    }
  }

  function disambiguateField(name, type, inside) {
    const [n] = name.split(',')
    for (const key in inside) {
      if (key.startsWith(n + ',') || key === n) {
        const v = inside[key]
        if (v[0] === type) continue // no type conflict
        // there is a type conflict
        delete inside[key]
        if (typeof v[0] === 'string') inside[key + ',' + v[0]] = v
        else inside[key + ',' + (i++)] = v
        if (typeof type === 'string') return name + ',' + type
        else return name + ',' + (i++)
      }
    }
    return name
  }

  function visit(root, simplified = {}, isAnonIteration = false) {
    console.log('Disambiguating fields...', JSON.stringify(root))

    function handleSwitch(newName, args, anon, simplified) {
      const next = {}
      const sharedScope = {}
      for (const field in args.fields) {
        const val = args.fields[field]
        if (typeof val === 'string') {
          next[field] = [val]
          sharedScope[''] = [val]
        } else if (Array.isArray(val)) {
          const [_actualType, _args] = val
          if (_actualType === 'container') {
            next[field] = {}
            visit(_args, next[field])
            visit(_args, sharedScope)
            if (anon) visit(_args, simplified, true)
          } else if (_actualType === 'switch') {
            throw new Error('Nested switch not supported')
          } else if (_actualType === 'mapper') {
            next[field] = ['mapper', _args.type, _args.mappings]
            if (anon) simplified['?' + field] = ['mapper', _args.type, _args.mappings]
            sharedScope['mapper,' + (i++)] = ['mapper', _args.type, _args.mappings]
          } else if (_actualType === 'array') {
            const children = {}
            next[field] = ['array', _args.countType, _args.count, children]
            visit(_args.type[1], children)
            if (anon) simplified['?' + field] = ['array', _args.countType, _args.count, children]
            sharedScope['array,' + (i++)] = ['array', _args.countType, _args.count, children]
          }
        }
      }
      if (anon) {
        simplified[newName] = ['switch', args.compareTo, next]
      } else {
        simplified[newName + '?'] = ['switch', args.compareTo, next]
        // simplified[newName] = sharedScope
        for (const key in sharedScope) {
          simplified['?' + newName + ',' + key] = sharedScope[key]
        }
      }
    }

    function handleType(name, type, anon, simplified) {
      if (typeof type === 'string') type = [type]
      let newName = anon ? ('_' + i++) : name
      newName = isAnonIteration ? ('?' + newName) : newName
      newName = disambiguateField(newName, type, simplified)
      const [actualType, args] = type
      if (actualType === 'container') {
        simplified[newName] = {}
        visit(args, simplified[newName])
        if (anon) visit(args, simplified, true)
      } else if (actualType === 'switch') {
        handleSwitch(newName, args, anon, simplified)
      } else if (actualType === 'mapper') {
        simplified[newName] = ['mapper', args.type, args.mappings]
      } else if (actualType === 'array') {
        // visit(args.type[1], children)
        if (typeof args.type === 'string') {
          simplified[newName] = ['array', args.countType, args.count, [args.type]]
        } else {
          const children = {}
          simplified[newName] = ['array', args.countType, args.count, children]
          handleType(null, args.type, true, children)
        }
      } else {
        console.warn('! Unknown type', actualType, args)
        simplified[newName] = [actualType, args]
      }
    }

    function handleContainer () {
      for (const { name, type, anon } of root) {
        if (typeof type === 'string') {
          let newName = isAnonIteration ? ('?' + name) : name
          newName = disambiguateField(newName, type, simplified)
          simplified[newName] = [type]
          continue
        } else if (Array.isArray(type)) {
          handleType(name, type, anon, simplified)
        }
      }
    }

    handleContainer()
  }

  const simplified = {}
  for (const name in bloatedSchema) {
    simplified[name] = {}
    const type = bloatedSchema[name]
    if (Array.isArray(type)) {
      if (type[0] === 'container') {
        visit(bloatedSchema[name][1], simplified[name])
      } else {
        // visit() only takes containers, so we have to wrap&unwrap it
        const obj = {}
        visit([{ name, type }], obj)
        simplified[name] = obj[name]
      }
    }
    else simplified[name] = [type]
  }
  // console.dir(simplified, { depth: null })
  return simplified
}

// debloatSchema(basicJSON)
const redone = debloatSchema(require('./protocol.json').types)
fs.writeFileSync('./redone.json', JSON.stringify(redone, null, 2))