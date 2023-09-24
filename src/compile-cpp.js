/* eslint-disable no-return-assign, no-sequences, no-unused-vars */
const fs = require('fs')
const ir = require('./redone.json')
// ir = {
//   // ItemLegacy: ir.ItemLegacy,
//   packet_emote_list: ir.packet_emote_list,
//   // string: ir.string,
//   // packet_available_commands: ir.packet_available_commands,
//   // packet_education_settings: ir.packet_education_settings,
// }

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
  lu16: 'uint16_t',
  lu32: 'uint32_t',
  lu64: 'uint64_t',
  li16: 'int16_t',
  li32: 'int32_t',
  li64: 'int64_t',
  lf32: 'float',
  lf64: 'double',
  bool: 'bool',
  varint: 'int',
  cstring: 'std::string',
  varint64: 'int64_t',
  zigzag32: 'int',
  zigzag64: 'int64_t'
  // buffer: 'std::vector<uint8_t>'
}
const protodefTypeToCppEncode = {
  u8: 'writeUByte',
  u16: 'writeUShortBE',
  u32: 'writeUIntBE',
  u64: 'writeULongBE',
  i8: 'writeByte',
  i16: 'writeShortBE',
  i32: 'writeIntBE',
  i64: 'writeLongBE',
  f32: 'writeFloatBE',
  f64: 'writeDoubleBE',
  lu16: 'writeUShortLE',
  lu32: 'writeUIntLE',
  lu64: 'writeULongLE',
  li16: 'writeShortLE',
  li32: 'writeIntLE',
  li64: 'writeLongLE',
  lf32: 'writeFloatLE',
  lf64: 'writeDoubleLE',
  bool: 'writeBool',
  cstring: 'writeCString',
  // buffer: 'writeBuffer',
  varint: 'writeUnsignedVarInt',
  varint64: 'writeUnsignedVarLong',
  zigzag32: 'writeZigZagVarInt',
  zigzag64: 'writeZigZagVarLong'
}
const protodefTypeSizes = {
  u8: 1,
  u16: 2,
  u32: 4,
  u64: 8,
  i8: 1,
  i16: 2,
  i32: 4,
  i64: 8,
  f32: 4,
  f64: 8,
  lu16: 2,
  lu32: 4,
  lu64: 8,
  li16: 2,
  li32: 4,
  li64: 8,
  lf32: 4,
  lf64: 8,
  bool: 1,
  cstring (args, varName) {
    return `${varName}.length() + 1`
  },
  varint: 'sizeOfVarInt',
  varint64: 'sizeOfVarInt64',
  varlong: 'sizeOfVarInt64',
  zigzag32: 'sizeOfZigZagVarInt',
  zigzag64: 'sizeOfZigZagVarLong'
}
const customTypes = {
  pstring: {
    struct (args, name, makeCallingCode) {
      return makeCallingCode('std::string', name)
    },
    read (args, [name, refName], makeCallingCode) {
      if (args.count) return `if (!stream.readString(${refName}, ${args.count})) return false;`
      const primitiveType = protodefTypeToCpp[args.countType]
      return `
${primitiveType} ${name}_strlen; ${makeCallingCode(args.countType, `${name}_strlen`)};
if (!stream.readString(${refName}, ${name}_strlen)) return false;
`.trim()
    },
    write (args, [name, refName], makeCallingCode) {
      if (args.count) return `WRITE_OR_BAIL(writeString, ${refName});`
      return `
${makeCallingCode(args.countType, [refName, 'length()'])};
WRITE_OR_BAIL(writeString, ${refName});
`.trim()
    },
    size (args, [name, refName], makeCallingCode) {
      if (args.count) return `len += ${args.count};`
      return `
${makeCallingCode(args.countType, [refName, 'length()'])};
len += ${refName}.length();
`.trim()
    }
  },
  buffer: {
    struct (args, name, makeCallingCode) {
      return makeCallingCode('std::vector<uint8_t>', name)
    },
    read (args, [name, refName], makeCallingCode) {
      const typeStr = protodefTypeToCpp[args.countType] || 'int'
      let lines = ''
      if (args.count) {
        lines += `if (!stream.readBuffer(${refName}, ${args.count})) return false;`
      } else {
        lines += `${typeStr} ${name}_len; ${makeCallingCode(args.countType, `${name}_len`)};`
        lines += `if (!stream.readBuffer(${refName}, ${name}_len)) return false;`
      }
      return lines
    },
    write (args, [name, refName], makeCallingCode) {
      if (args.count) return `WRITE_OR_BAIL(writeBuffer, ${refName});`
      return `
${makeCallingCode(args.countType, [refName, 'size()'])};
WRITE_OR_BAIL(writeBuffer, ${refName});
`.trim()
    },
    size (args, [name, refName], makeCallingCode) {
      if (args.count) return `len += ${args.count};`
      return `
${makeCallingCode(args.countType, [refName, 'size()'], false)};
len += ${refName}.size();
`.trim()
    }
  },
  bitflags: {
    type (args, name, makeCallingCode) {
      return `${name}_t`
    },
    struct (args, name, makeCallingCode) {
      const flags = Array.isArray(args.flags)
        ? args.flags.map(toSafeVar)
        : Object.entries(args.flags).reduce((acc, [k, v]) => (acc[v] = k, acc), []).map(toSafeVar)
      let s = `struct ${name}_t {\n`
      for (let i = 0; i < flags.length; i++) {
        const k = flags[i]
        if (!k) continue
        s += `  bool ${k} = false;\n`
      }
      s += `} ${name};`
      return s
    },
    read (args, [name, refName], makeCallingCode) {
      const primitiveType = protodefTypeToCpp[args.type]
      let s = `${primitiveType} ${name}_val;\n`
      s += makeCallingCode(args.type, `${name}_val`) + ';\n'
      if (Array.isArray(args.flags)) {
        const flags = args.flags.map(toSafeVar)
        for (let i = 0; i < flags.length; i++) {
          const flag = flags[i]
          if (!flag) continue
          s += `${refName}.${flag} = ${name}_val & ((${primitiveType})1 << ${i});\n`
        }
      } else {
        for (const [flag, bit] of Object.entries(args.flags)) {
          s += `${refName}.${toSafeVar(flag)} = (${name}_val & ${bit}) == ${bit};\n`
        }
      }
      return s
    },
    write (args, [name, refName], makeCallingCode) {
      const primitiveType = protodefTypeToCpp[args.type]
      let s = `${primitiveType} ${name}_val = 0;\n`
      if (Array.isArray(args.flags)) {
        const flags = args.flags.map(toSafeVar)
        for (let i = 0; i < flags.length; i++) {
          const flag = flags[i]
          if (!flag) continue
          s += `${name}_val |= (${primitiveType})${refName}.${flag} << ${i};\n`
        }
      } else {
        for (const [flag, bit] of Object.entries(args.flags)) {
          s += `if (${refName}.${toSafeVar(flag)}) ${name}_val |= ${bit};\n`
        }
      }
      s += makeCallingCode(args.type, `${name}_val`)
      return s
    },
    size (args, [name, refName], makeCallingCode) {
      const primitiveType = protodefTypeToCpp[args.type]
      let s = `${primitiveType} ${name}_val = 0; /*X*/\n`
      if (Array.isArray(args.flags)) {
        const flags = args.flags.map(toSafeVar)
        for (let i = 0; i < flags.length; i++) {
          const flag = flags[i]
          if (!flag) continue
          s += `${name}_val |= (${primitiveType})${refName}.${flag} << ${i};\n`
        }
      } else {
        for (const [flag, bit] of Object.entries(args.flags)) {
          s += `if (${refName}.${toSafeVar(flag)}) ${name}_val |= ${bit};\n`
        }
      }
      s += makeCallingCode(args.type, `${name}_val`) + ';\n'
      return s
    }
  },
  // bitfield is read as a u8 encapsulating many fields of variable bit size
  // "bitfield", [ { "name": "unused", "size": 1, "signed": false }, { "name": "collapse_enum", "size": 1, "signed": false }, { "name": "has_semantic_constraint", "size": 1, "signed": false }, { "name": "as_chained_command", "size": 1, "signed": false }, { "name": "unknown2", "size": 4, "signed": false } ] ],
  bitfield: {
    struct (args, name, makeCallingCode) {
      let s = 'struct {\n'
      for (const v of args) {
        s += `  int ${v.name} = 0;\n`
      }
      s += `} ${name};`
      return s
    },
    read (args, [name, refName], makeCallingCode) {
      let s = `uint8_t ${name}_val;\n`
      s += `READ_OR_BAIL(${protodefTypeToCppDecode.u8}, ${name}_val);\n`
      let bitOffset = 0
      for (const v of args) {
        s += `${refName}.${v.name} = ${name}_val >> ${bitOffset} & ${v.size};\n`
        bitOffset += v.size
      }
      return s
    },
    write (args, [name, refName], makeCallingCode) {
      let s = `uint8_t ${name}_val = 0;\n`
      let bitOffset = 0
      for (const v of args) {
        s += `${name}_val |= ${refName}.${v.name} << ${bitOffset};\n`
        bitOffset += v.size
      }
      s += `WRITE_OR_BAIL(${protodefTypeToCppEncode.u8}, ${name}_val);\n`
      return s
    },
    size (args, [name], makeCallingCode) {
      return 'len += 1;'
    }
  },
  enum_size_based_on_values_len: {
    type () {
      return ''
    },
    struct (args, name, makeCallingCode) {
      const s = `enum class _EnumType { Byte, Short, Int }; _EnumType ${name};`
      return s
    },
    read (args, [name], makeCallingCode) {
      return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
    },
    write (args, [name], makeCallingCode) {
      return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
    },
    size (args, [name], makeCallingCode) {
      return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
    }
  }
}
const protodefTypeToCppDecode = Object.fromEntries(
  Object.entries(protodefTypeToCppEncode)
    .map(([k, v]) => [k, v.replace('write', 'read')])
)
function addAliasType (newType, baseType) {
  protodefTypeToCpp[newType] = protodefTypeToCpp[baseType]
  protodefTypeToCppEncode[newType] = protodefTypeToCppEncode[baseType]
  protodefTypeToCppDecode[newType] = protodefTypeToCppDecode[baseType]
  protodefTypeSizes[newType] = protodefTypeSizes[baseType]
  if (customTypes[baseType]) customTypes[newType] = customTypes[baseType]
}
// some stubs
addAliasType('nbt', 'i8')
addAliasType('lnbt', 'i8')
addAliasType('nbtLoop', 'i8')
addAliasType('uuid', 'u64')
addAliasType('encapsulated', 'i8')
addAliasType('slot', 'i8')
addAliasType('byterot', 'i8')
addAliasType('restBuffer', 'i8')

function unretardify (objOrArr) {
  if (objOrArr == null) return []
  if (Array.isArray(objOrArr)) {
    return objOrArr
  } else if (typeof objOrArr === 'object') {
    return ['container', objOrArr]
  }
  return objOrArr
}

function deanonymizeStr (fieldName) {
  return fieldName.replaceAll('?', '').replaceAll(',', '_').replaceAll('/', '_').replaceAll('^', '').replaceAll(':', '_')
}

function promoteToPascalOrSuffix (str, suffixIfAlreadyPascal = true) {
  str = deanonymizeStr(str)
  if (!str) return ''
  // Check if field str starts with lowercase
  if (str[0] === str[0].toLowerCase()) {
    // we can promote name to PascalCase from snake_case
    return str.split('_').map(s => !s ? '_' : s[0].toUpperCase() + s.slice(1)).join('')
    // we need to add a _t suffix
  } else if (suffixIfAlreadyPascal) {
    return str + '_t'
  } else {
    return str
  }
}

// illegal C++ keywords
const illegal = ['byte', 'short', 'int', 'long', 'float', 'double', 'bool', 'default', 'break', 'void',
  'case', 'char', 'class', 'const', 'continue', 'do', 'else', 'enum', 'extern', 'for', 'goto', 'if', 'inline',
  'namespace', 'new', 'operator', 'private', 'protected', 'public', 'return', 'sizeof', 'static', 'struct',
  'switch', 'template', 'this', 'throw', 'try', 'typedef', 'union', 'unsigned', 'virtual', 'while', 'auto',
  'catch', 'const_cast', 'delete', 'dynamic_cast', 'explicit', 'export', 'false', 'friend', 'mutable', 'nullptr',
  'reinterpret_cast', 'static_cast', 'static_assert', 'thread_local', 'typeid', 'typename', 'using']
function toSafeVar (name) {
  if (!name) return
  // add a _ suffix to reserved keywords in C++
  if (illegal.includes(name)) name += '_'
  // check if name starts with a number
  if (!isNaN(name[0])) name = '_' + name
  return name
}
// this is for switch statements where we need to use the variable name as a case
function toSafeVarSwitch (name) {
  for (const ill of illegal) {
    if (name.includes('.' + ill + ' ')) {
      name = name.replaceAll('.' + ill + ' ', '.' + ill + '_')
    } else if (name.endsWith('.' + ill)) {
      name = name + '_'
    }
  }
  return name
}

const filterNull = (arr) => (Array.isArray(arr[0]) ? arr[0] : arr).filter(x => !!x)
const dotJoin = (...arr) => filterNull(arr).map(toSafeVar).join('.')
const colonJoin = (...arr) => filterNull(arr).map(toSafeVar).join('::')
const escapeComment = (cmt) => cmt.replaceAll('*', '|')

function parseCompareToType (compareToType) {
  const levelsUp = compareToType.split('../').length - 1
  return [levelsUp, compareToType.replaceAll('../', '')]
}

const headers = `
#include <string>
#include <vector>
#include <optional>
#include "stream.h"
#define WRITE_OR_BAIL(fn, val) if (!stream.fn(val)) { return false; }
#define READ_OR_BAIL(fn, val) if (!stream.fn(val)) { return false; }
#define EXPECT_OR_BAIL(val) if (!val) { return false; }
`
const footer = `
#undef WRITE_OR_BAIL
#undef READ_OR_BAIL
`

function visitRoot (root, mode) {
  let structLines = headers + 'namespace pdef::proto {\n/*FWD_DECLS*/\n'
  let sizeLines = 'namespace pdef::proto::size {\n/*FWD_DECLS*/\n'
  let encodeLines = 'namespace pdef::proto::encode {\n/*FWD_DECLS*/\n'
  let decodeLines = 'namespace pdef::proto::decode {\n/*FWD_DECLS*/\n'
  const structFwds = []
  const sizeFwds = []
  const encodeFwds = []
  const decodeFwds = []

  const nativeTypes = []
  for (const [key, val] of Object.entries(root)) {
    if (val[0] === 'native') nativeTypes.push(key)
  }

  function structFromContainer (name, container, structPaddingLevel = 0) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const push = (str) => { structLines += pad(str) + '\n' }

    structFwds.push(`struct ${name};`)
    push(`struct ${name} {`)
    for (const [fieldName, fieldType] of Object.entries(container)) {
      if (fieldName.startsWith('*')) continue
      structForType(fieldName, fieldType, structPaddingLevel)
    }
    push('};')
    console.log('{\n')
  }

  function structForType (fieldName, fieldType, structPaddingLevel, anonymouslyWrite) {
    let ret = ''
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const push = (str) => {
      if (anonymouslyWrite) ret += pad(str) + '\n'
      else structLines += pad(str) + '\n'
    }

    fieldType = unretardify(fieldType)
    console.log(`  ${fieldName}: ${fieldType}`)
    if (fieldName.endsWith('?')) return // When generating structs, we ignore switches
    let typeName = fieldType[0]
    const oldTypeName = typeName
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    const shouldInlineFromRoot = checkShouldInlineFromRoot(typeName)
    if (shouldInlineFromRoot) {
      fieldType = unretardify(root[typeName])
      typeName = fieldType[0]
      // push('// inlined from root')
    } else {
      // push('// not inlined from root: ' + typeName)
    }
    const n = deanonymizeStr(fieldName)

    const isAnon = fieldName.startsWith('?')
    // TODO: DFS to determine array level
    function typeStrForType (typename, varname, arrayLevel = 0, typeInLocalScope, treatAsAnon) {
      // we shouldn't wrap primitives (OR length encapsulated) in std::optional, it's unnecessary
      const asAnon = treatAsAnon !== false && isAnon && !protodefTypeSizes[typename] && (typename !== 'std::string' && !typename.startsWith('std::vector'))
      let s = ''
      if (arrayLevel) for (let i = 0; i < arrayLevel; i++) s += 'std::vector<'
      else if (asAnon) s += 'std::optional<'
      s += typeInLocalScope ? typename : `pdef::proto::${typename}`
      if (arrayLevel) for (let i = 0; i < arrayLevel; i++) s += '>'
      else if (asAnon) s += '>'
      if (!anonymouslyWrite) s += ` ${toSafeVar(varname)};`
      return s
    }

    if (typeName === 'void') return // TODO: remove this in the IR
    else if (protodefTypeToCpp[typeName]) push(`  ${typeStrForType(protodefTypeToCpp[typeName], n, 0, true, false)} /*0.0*/`)
    else if (typeName === 'container' || typeName === 'array' || typeName === 'mapper') {
      // We need 2 separate fields in the struct for this.
      // One for the enum, and one for the actual value.
      // For example when writing:
      // stream->color = Color::red;
      // We can either use PascalCase for the enum, or add a _t suffix.
      const newName = promoteToPascalOrSuffix(fieldName)
      if (!anonymouslyWrite) visitType(newName, fieldType, structPaddingLevel)
      // TODO: per above TODO, we need to use DFS to determine array level
      if (fieldType[0] === 'array') {
        let arrayLevel = 1
        let actualType = unretardify(fieldType[3])
        let typename = actualType[0] === 'container' ? newName : actualType[0]
        if (typename === 'array') {
          actualType = unretardify(actualType[3])
          typename = actualType[0] === 'container' ? newName : actualType[0]
          arrayLevel++
          if (typename === 'array') {
            actualType = unretardify(actualType[3])
            typename = actualType[0] === 'container' ? newName : actualType[0]
            arrayLevel++
            if (typename === 'array') {
              throw new Error('Only up to 3D arrays are supported')
            }
          }
        }
        // TODO: some recursion is needed here to determine the type of the array
        // const inLocalScope = actualType[0] === 'container' || protodefTypeToCpp[typename]
        let parsedType = structForType(fieldName, actualType, structPaddingLevel, true)
        if (parsedType.startsWith('std::optional')) {
          parsedType = parsedType.replace('std::optional<', '').replace('>', '')
          // arrayLevel--
        }
        if (!parsedType.startsWith('//')) { push(`  ${typeStrForType(parsedType, n, arrayLevel, true)} /*3.0*/`) }
        // push(`  std::vector<${newName}> ${deanonymizeStr(fieldName)}; /*3*/`)
      } else {
        const treatAsAnon = typeName !== 'mapper'
        push(`  ${typeStrForType(newName, n, false, true, treatAsAnon)} /*3.2*/`)
        // push(`  ${newName} ${deanonymizeStr(fieldName)}; /*3*/`)
      }
    } else if (customTypes[typeName]) {
      const typeImpl = customTypes[typeName]
      const structCode = typeImpl.struct(fieldType[1], n, (typename, varname) => typeStrForType(typename, varname, 0, true))
      structCode.split('\n').forEach(e => push('  ' + e + ' /*6.0*/'))
    } else if (root[typeName] && root[typeName][0] !== 'native') {
      if (isRootArray) {
        const rootArrayType = root[oldTypeName][3]
        push(`  ${typeStrForType(Array.isArray(rootArrayType) ? rootArrayType[0] : oldTypeName, n, 1)} /*1.0*/`)
      } else {
        push(`  ${typeStrForType(typeName, n)} /*4.0*/`)
      }
    } else if (!['switch'].includes(typeName)) {
      // push(` // ERROR: unknown type ${typeName} L${structPaddingLevel} /*6.1*/`)
      throw new Error(`Missing custom type ${typeName}`)
    }
    return ret.trim()
  }

  function structFromMapper (name, mapper, structPaddingLevel) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const enumLines = []
    const [enumType, enumValues] = mapper
    for (const [k, v] of Object.entries(enumValues)) {
      enumLines.push(`  ${toSafeVar(promoteToPascalOrSuffix(v, false))} = ${k},`)
    }
    // console.log(enumLines, structPaddingLevel)
    const updatedType = protodefTypeToCpp[enumType] || `pdef::proto::${enumType}`
    const l = [
      `enum class ${name} : ${updatedType} {`,
      ...enumLines,
      '};\n'
    ].map(pad).join('\n')
    structLines += l
    console.log(l)
  }

  let sizeIx = 0
  function makeSizeStr (type, varName, isAnon) {
    const s = protodefTypeSizes[type]
    if (typeof s === 'number') return `len += ${s}`
    else if (typeof s === 'string') return `len += stream.${protodefTypeSizes[type]}(${Array.isArray(varName) ? dotJoin(...varName) : toSafeVar(varName)})`
    const name = Array.isArray(varName) ? dotJoin(varName) : toSafeVar(varName)
    const sizeVar = `len_${sizeIx++}`
    return `${isAnon ? `EXPECT_OR_BAIL(${name}); ` : ''}size_t ${sizeVar} = pdef::proto::size::${type}(stream, ${isAnon ? '*' : ''}${name}); EXPECT_OR_BAIL(${sizeVar}); len += ${sizeVar}`
  }
  const makeEncodeStr = (type, varName, isAnon) => protodefTypeToCppEncode[type]
    ? `WRITE_OR_BAIL(${protodefTypeToCppEncode[type]}, (${protodefTypeToCpp[type]})${Array.isArray(varName) ? dotJoin(varName) : toSafeVar(varName)})`
    : `pdef::proto::encode::${type}(stream, ${isAnon ? '*' : ''}${Array.isArray(varName) ? dotJoin(varName) : varName})`

  function makeDecodeStr (type, varName, maybe) {
    const name = Array.isArray(varName) ? dotJoin(varName) : varName
    if (protodefTypeToCppDecode[type]) {
      // const cast = protodefTypeToCpp[type] ? `(${protodefTypeToCpp[type]}&)` : ''
      return `READ_OR_BAIL(${protodefTypeToCppDecode[type]}, ${name})`
    } else {
      let s = ''
      if (maybe) s += `${name} = {}; pdef::proto::decode::${type}(stream, *${name})`
      else s += `pdef::proto::decode::${type}(stream, ${name})`
      return s
    }
  }

  function checkShouldInlineFromRoot (typeName) {
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    let shouldInlineFromRoot = Array.isArray(root[typeName]) && root[typeName][0] !== 'native'
    if (shouldInlineFromRoot && isRootArray) {
      // an array can be its own container. we only inline if the type is an array of primitives
      shouldInlineFromRoot = Array.isArray(root[typeName][3])
    }
    return shouldInlineFromRoot
  }

  function encodeType (fieldName, fieldType, structPaddingLevel = 0, objPath, _, objectName) {
    if (!Array.isArray(objPath)) throw new Error('objPath is required')
    const objName = objectName ?? (objPath.length > 1 ? 'v' : 'obj')
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushSizeEncode = (str) => (pushSize(str), pushEncode(str))
    const pushAll = (str) => (pushSize(str), pushEncode(str), pushDecode(str))
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }
    pushAll(`// ${objectName} ${objName}`)

    console.log(`.  ${fieldName}: ${fieldType}`)
    fieldType = unretardify(fieldType)
    if (fieldName.startsWith('?')) return

    let typeName = fieldType[0]
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    const shouldInlineFromRoot = checkShouldInlineFromRoot(typeName)

    const variableName = fieldType[5] || fieldType['*name'] || fieldName
    const isAnon = variableName.startsWith('?')
    // const ctx = `/*~${variableName} < ${fieldName}*/`
    const n = deanonymizeStr(variableName) + ((deanonymizeStr(variableName) !== deanonymizeStr(fieldName)) ? '' : '')

    if (shouldInlineFromRoot) {
      fieldType = unretardify(root[typeName])
      typeName = fieldType[0]
      // pushAll('// inlined from root')
    }
    // In case it's modified

    if (typeName === 'void') return // TODO: remove this in the IR

    const structPropName = dotJoin(objName, n)
    let typePropName = protodefTypeToCpp[typeName] ?? `pdef::proto::${colonJoin(objPath)}::${typeName}`

    const builtinEncodeFn = protodefTypeToCppEncode[typeName]
    if (builtinEncodeFn) {
      if (fieldName.endsWith('^')) {
        pushSizeEncode(`  const ${typePropName} &${n} = ${structPropName}; /*0.1*/`)
      } else {
        pushSize(`  ${makeSizeStr(typeName, [objName, n])}; /*0.2*/`)
      }
      pushEncode('  ' + makeEncodeStr(typeName, [objName, n]) + '; /*0.4*/')
      pushDecode('  ' + makeDecodeStr(typeName, [objName, n], isAnon) + '; /*0.5*/')
      // .... this ^ needs to be similarly handled in each case below for read/write/size
      if (fieldName.endsWith('^')) pushDecode(`  ${typePropName} &${n} = ${structPropName}; /*0.6*/`)
    } else if (isRootArray && !shouldInlineFromRoot) {
      // A root array can be its own container. We only inline if the type is an array of primitives.
      // So, here we consider the type to be a structure that already has compiled read/write/size functions.
      const rootType = root[typeName]
      const lengthType = rootType[1]
      const lengthVar = rootType[2] // Not really possible from root
      pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*2.1*/`)
      pushEncode(`  for (const auto &v : ${structPropName}) { ${makeEncodeStr(typeName, 'v')}; } /*2.2*/`)
      // TODO: Can't decode into .size() ! We need a separate variable for this.
      pushSize(`  ${makeSizeStr(lengthType, [objName, n, 'size()'])}; /*2.4*/`)
      pushSize(`  for (const auto &v : ${structPropName}) { ${makeSizeStr(typeName, 'v')}; } /*2.5*/`)
      const typeStr = protodefTypeToCpp[lengthType] || 'int'
      pushDecode(`  ${typeStr} ${n}_len; /*2.3*/`)
      // pushDecode(`  ${makeDecodeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*2.3*/`)
      pushDecode(`  ${makeDecodeStr(lengthType, [n + '_len'])}; /*2.6*/`)
      // Resize the std::vector so it has enough space to fit length
      pushDecode(`  ${structPropName}.resize(${n}_len); /*2.7*/`)
      pushDecode(`  for (int i = 0; i < ${n}_len; i++) { ${makeDecodeStr(typeName, [objName, n + '[i]'], false)}; } /*2.8*/`)
      // pushDecode(`  for (auto &v : ${structPropName}) { ${makeDecodeStr(typeName, 'v', isAnon)}; } /*6*/`)
    } else {
      // We need 2 separate fields in the struct for this.
      // One for the enum, and one for the actual value.
      // For example when writing:
      // stream->color = Color::red;
      // We can either use PascalCase for the enum, or add a _t suffix.
      if (typeName === 'array') {
        const newName = promoteToPascalOrSuffix(fieldName)
        const lengthType = fieldType[1]
        const lengthVar = fieldType[2]
        if (lengthVar) {
          // console.log('lengthVar', fieldType, lengthVar)
          const [lengthVariable, lengthTyp] = lengthVar
          pushSize(`  ${makeSizeStr(lengthTyp, [lengthVariable])}; /*1.1*/`)
          pushEncode(`  ${makeEncodeStr(lengthTyp, [lengthVariable])}; /*1.2*/`)
          // Resize the std::vector so it has enough space to fit length
          pushDecode(`  ${structPropName}.resize(${lengthVariable}); /*1.6*/`)
        } else {
          pushSize(`  ${makeSizeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*1.3*/`)
          pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*1.4*/`)
          const typeStr = protodefTypeToCpp[lengthType] || 'int'
          pushDecode(`  ${typeStr} ${n}_len; ${makeDecodeStr(lengthType, [n + '_len'])}; /*1.5*/`)
          // Resize the std::vector so it has enough space to fit length
          pushDecode(`  ${structPropName}.resize(${n}_len); /*1.6*/`)
        }
        const actualType = unretardify(fieldType[3])
        if (actualType[0] === 'container') {
          const arrayStructName = promoteToPascalOrSuffix(n)
          typePropName = `pdef::proto::${colonJoin(objPath)}::${arrayStructName}`
          const vName = 'v' + (structPaddingLevel + 1)
          // inline
          pushSizeEncode(`  for (const auto &${vName} : ${dotJoin(objName, n)}) { /*5.20*/`)
          if (lengthVar) {
            pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5.21*/`)
            pushDecode(`    ${typePropName} &${vName} = ${dotJoin(objName, n)}[i]; /*5.22*/`)
          } else {
            pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5*/`)
            pushDecode(`    ${typePropName} &${vName} = ${dotJoin(objName, n)}[i]; /*5.23*/`)
          }
          encodingFromContainer(newName, actualType[1], structPaddingLevel + 1, structPaddingLevel === 0 ? objPath.concat('') : objPath.concat(promoteToPascalOrSuffix(n)), true, vName)
          pushSizeEncode('  }')
          pushDecode('  }')
        } else if (actualType[0] === 'array') {
          const [, actualLengthType, actualLengthVar, _actualActualType] = actualType
          const actualActualType = unretardify(_actualActualType)
          if (actualActualType[0] === 'array') { // 3D array, max supported depth
            throw new Error('TODO: Only up to 2D arrays are supported')
          } else { // 2D array
            pushSizeEncode(`  for (const auto &v : ${structPropName}) { /*5.1*/`)
            if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5.2*/`)
            else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5.2*/`)
            if (actualLengthVar) {
              const [actualLengthVariable, actualLengthTyp] = actualLengthVar
              pushSize(`    ${makeSizeStr(actualLengthTyp, [actualLengthVariable])}; /*5.3*/`)
              pushEncode(`    ${makeEncodeStr(actualLengthTyp, [actualLengthVariable])}; /*5.4*/`)
              const typeStr = protodefTypeToCpp[actualLengthTyp] || 'int'
              pushDecode(`    ${typeStr} ${n}_len2; ${makeDecodeStr(actualLengthTyp, [n + '_len2'])}; /*5.5*/`)
              pushDecode(`    ${structPropName}[i].resize(${n}_len2); /*5.10*/`)
            } else {
              pushSize(`    ${makeSizeStr(actualLengthType, [objName, n, 'size()'], isAnon)}; /*5.6*/`)
              pushEncode(`    ${makeEncodeStr(actualLengthType, [objName, n, 'size()'], isAnon)}; /*5.7*/`)
              const typeStr = protodefTypeToCpp[actualLengthType] || 'int'
              pushDecode(`    ${typeStr} ${n}_len2; ${makeDecodeStr(actualLengthType, [n + '_len2'])}; /*5.8*/`)
              pushDecode(`    ${structPropName}[i].resize(${n}_len2); /*5.9*/`)
            }
            pushSizeEncode('    for (const auto &v : v) { /*5.10*/')
            if (actualLengthVar) pushDecode(`    for (int j = 0; j < ${actualLengthVar[0]}; j++) { /*5.11*/`)
            else pushDecode(`    for (int j = 0; j < ${n}_len2; j++) { /*5.11*/`)

            if (actualActualType[0] === 'container') {
              encodingFromContainer(newName, actualActualType[1], structPaddingLevel + 2, structPaddingLevel === 0 ? objPath.concat('') : objPath.concat(promoteToPascalOrSuffix(n)), true)
            } else {
              pushSize(`      ${makeSizeStr(actualActualType[0], 'v')}; /*5.12*/`)
              pushEncode(`      ${makeEncodeStr(actualActualType[0], 'v')}; /*5.13*/`)
              pushDecode(`      ${makeDecodeStr(actualActualType[0], [objName, n + '[i][j]'])}; /*5.14*/`)
            }
            pushSizeEncode('    }')
            pushDecode('    }')
            pushSizeEncode('  }')
            pushDecode('  }')
          }
          // pushSizeEncode(`  for (const auto &v : ${structPropName}) { /*5.7*/`)
          // if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5.8*/`)
          // else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5.9*/`)
          // const actualActualType = unretardify(actualType[3])
          // encodeType('', actualType, structPaddingLevel + 1, objPath, true)
          // pushSizeEncode('  }')
          // pushDecode('  }')
        } else {
          const vName = 'v' + (structPaddingLevel + 1)
          pushEncode(`  for (const auto &${vName} : ${structPropName}) { /*3.1*/`)
          pushSize(`  for (const auto &${vName} : ${structPropName}) {`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) {`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) {`)
          pushDecode(`    auto &${vName} = ${structPropName}[i]; /*3.4*/`)
          // visitType('', actualType, structPaddingLevel + 1, objPath.concat(n), true)
          // fieldName, fieldType, structPaddingLevel = 0, objPath, objectName
          encodeType('', actualType, structPaddingLevel + 1, objPath.concat(n), undefined, vName)
          pushEncode('  }')
          pushSize('  }')
          pushDecode('  }')
        }
      } else if (typeName === 'switch') {
        const compareTo = Array.isArray(fieldType[1]) ? fieldType[1][2] : fieldType[1]
        const [levelsUp, _compareToType] = parseCompareToType(fieldType[2])
        const pathToCompareTo = (levelsUp ? objPath.slice(0, -levelsUp) : objPath) // + `/*${objPath.join(',')}*/`
        const compareToType = (_compareToType && _compareToType !== 'mapper') ? _compareToType : promoteToPascalOrSuffix(compareTo)
        const compareToName = promoteToPascalOrSuffix(compareTo)
        const cases = fieldType[3]
        pushAll(`  switch (${toSafeVarSwitch(compareTo)}) { /*8.0*/`)
        for (const [caseName, caseType] of Object.entries(cases)) {
          // let absName
          // if (Array.isArray(caseType)) {
          //   absName = caseType[5]
          // } else {
          //   absName = caseType['*name']
          // }
          // if(!absName) console.log('no absName', caseType)
          // absName = deanonymizeStr(absName)
          if (compareToType === 'bool') { pushAll(`    case ${caseName}: { /*8.0*/`) } else if ((['true', 'false'].includes(caseName) && (_compareToType !== 'mapper')) || !isNaN(caseName)) { pushAll(`    case ${caseName}: { /*8.1*/`) } else if (caseName === 'default') { pushAll('    default: { /*8.1*/') } else if (caseName.startsWith('/')) { pushAll(`    case pdef::proto::${toSafeVar(caseName).replace('/', '')}: { /*8.2*/`) } else { pushAll(`    case pdef::proto::${colonJoin(pathToCompareTo)}::${compareToName}::${toSafeVar(promoteToPascalOrSuffix(caseName))}: { /*8.3*/`) }
          // encodingFromContainer(caseName, caseType, structPaddingLevel + 2, objName)
          let realName = isAnon ? null : caseType[5] || caseType['*name']
          const isScoped = isAnon ? false : !Array.isArray(caseType)
          if (realName) {
            realName = deanonymizeStr(realName)
            // TODO: handle optional fields
            const structureName = promoteToPascalOrSuffix(realName)
            if (!Array.isArray(caseType)) {
              pushDecode(`       ${objName}.${realName} = {}; pdef::proto::${colonJoin(objPath)}::${structureName} &v = *${objName}.${realName}; /*8.4*/`)
              // "expect or bail" is not needed here because we already checked the switch case
              pushEncode(`      const pdef::proto::${colonJoin(objPath)}::${structureName} &v = *${objName}.${realName}; /*8.5*/`)
              pushSize(`      EXPECT_OR_BAIL(${objName}.${realName}); const pdef::proto::${colonJoin(objPath)}::${structureName} &v = *${objName}.${realName}; /*8.6*/`)
            }
          }
          visitType(n, caseType, structPaddingLevel + 2, (isScoped && realName) ? objPath.concat(promoteToPascalOrSuffix(realName)) : objPath, true, objectName)
          pushAll('      break;')
          pushAll('    } /*8.7*/')
        }
        if (!cases.default) pushAll('    default: break; /*avoid unhandled case warning*/')
        pushAll('  } /*8.8*/')
      } else if (typeName === 'mapper') {
        const actualType = fieldType[1]
        if (fieldName.endsWith('^')) {
          pushSizeEncode(`  const pdef::proto::${colonJoin(objPath)}::${promoteToPascalOrSuffix(fieldName)} &${n} = ${structPropName}; /*0.3*/`)
        }
        const castStr = `(${protodefTypeToCpp[actualType]}&)`
        pushSize(`  ${makeSizeStr(actualType, [castStr + objName, n])}; /*${fieldName}: ${actualType}*/ /*7.0*/`)
        pushEncode(`  ${makeEncodeStr(actualType, [castStr + objName, n])}; /*7.1*/`)
        pushDecode(`  ${makeDecodeStr(actualType, [castStr + objName, n])}; /*7.2*/`)
        if (fieldName.endsWith('^')) {
          pushDecode(`  const pdef::proto::${colonJoin(objPath)}::${promoteToPascalOrSuffix(fieldName)} &${n} = ${structPropName}; /*0.7*/`)
        }
      } else if (typeName === 'container') {
        const structureName = promoteToPascalOrSuffix(fieldName)
        const varName = `${structPropName}`
        pushDecode(`  const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${structPropName} = {}; /*${JSON.stringify(objPath)}*/ /*7.3*/`)
        pushEncode(`  const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${isAnon ? '*' : ''}${structPropName}; /*${JSON.stringify(objPath)}*/ /*7.4*/`)
        pushSize(`  ${isAnon ? `EXPECT_OR_BAIL(${varName}); ` : ''}const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${isAnon ? '*' : ''}${structPropName}; /*${JSON.stringify(objPath)}*/ /*7.4*/`)
      } else {
        // TODO: handle custom types
        // we'd call into the specific encode function for this type
        let structVarType
        if (Array.isArray(fieldType)) {
          const actualType = fieldType[0]
          if (customTypes[actualType]) {
            const typeImpl = customTypes[actualType]
            structVarType = typeImpl.type?.(fieldType[1], n)
            const structVarRef = `${objName}`
            const sizeCode = typeImpl.size(fieldType[1], [n, structPropName], (type, args, anon) => makeSizeStr(type, args, anon ?? isAnon)).split('\n').map(e => pad('  ' + e.trim())).join('\n').trim()
            const encodeCode = typeImpl.write(fieldType[1], [n, structPropName], (type, args, anon) => makeEncodeStr(type, args, anon ?? isAnon)).split('\n').map(e => pad('  ' + e.trim())).join('\n').trim()
            const decodeCode = typeImpl.read(fieldType[1], [n, structPropName], (type, args, anon) => makeDecodeStr(type, args, anon ?? isAnon)).split('\n').map(e => pad('  ' + e.trim())).join('\n').trim()
            pushSize(`  ${sizeCode} /*${fieldName}: ${actualType}*/ /*4.1*/`)
            pushEncode(`  ${encodeCode} /*${n}: ${actualType}*/ /*4.2*/`)
            pushDecode(`  ${decodeCode} /*${n}: ${actualType}*/ /*4.3*/`)
          } else if (root[actualType] && root[actualType][0] !== 'native') {
            pushSize(`  ${makeSizeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*${escapeComment(n)}*/ /*4.4*/`)
            pushEncode(`  ${makeEncodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*${typeName}*/ /*4.5*/`)
            pushDecode(`  ${makeDecodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*${objName}*/ /*4.6*/`)
          } else {
            console.warn('Do not know how to handle unknown type: ' + actualType)
            pushSize(`// ERROR: unknown type ${actualType} /*4.1*/`)
            pushEncode(`// ERROR: unknown type ${actualType} /*4.2*/`)
            pushDecode(`// ERROR: unknown type ${actualType} /*4.3*/`)
            throw new Error('Unknown type: ' + actualType)
          }
        }

        if (fieldName.endsWith('^')) {
          const varType = structVarType ?? typeName
          if (varType) { // structVarType being '' means scoping is not needed, maybe handled
            const typename = protodefTypeToCpp[varType] || `pdef::proto::${colonJoin(objPath)}::${varType}`
            pushSizeEncode(`  const ${typename} &${n} = ${structPropName}; /*0.1*/`)
            pushDecode(`  ${typename} &${n} = ${structPropName}; /*0.7*/`)
          }
        }
      }
    }
  }

  function writeHeader (name, structPaddingLevel) {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }
    pushEncode(`bool ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj, bool allocate = true) {`)
    pushEncode(`  if (allocate) { auto writeSize = pdef::proto::size::${name}(stream, obj); if (!writeSize) return false; stream.reserve(writeSize); }`)
    pushDecode(`bool ${name}(pdef::Stream &stream, pdef::proto::${name} &obj) {`)
    pushSize(`size_t ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj) {`)
    pushSize('  size_t len = 0;')
    encodeFwds.push(`bool ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj, bool allocate);`)
    decodeFwds.push(`bool ${name}(pdef::Stream &stream, pdef::proto::${name} &obj);`)
    sizeFwds.push(`size_t ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj);`)
  }

  function writeFooter (name, structPaddingLevel) {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }
    pushSize('  return len;')
    pushSize('}')
    pushEncode('  return true;')
    pushEncode('}')
    pushDecode('  return true;')
    pushDecode('}')
  }

  function encodingFromContainer (name, container, structPaddingLevel = 0, objPath, excludeHeaders, objName) {
    if (!Array.isArray(objPath)) throw new Error('objPath is required')
    if (mode === 'struct') return

    if (!excludeHeaders) {
      writeHeader(name, structPaddingLevel)
    }
    for (const [fieldName, fieldType] of Object.entries(container)) {
      if (fieldName.startsWith('*')) continue
      encodeType(fieldName, fieldType, structPaddingLevel, objPath, undefined, objName)
    }
    if (!excludeHeaders) {
      writeFooter(name, structPaddingLevel)
    }
  }

  function visitType (structName, type, structPaddingLevel = 0, objPath, excludeHeaders, objName) {
    objPath ||= [structName]
    // const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const [typeName, ...typeArgs] = unretardify(type)
    console.log(typeName, typeArgs)
    if (typeName === 'native') {
      structLines += `// ${structName} is built in\n`
    } else if (typeName === 'array') {
      const [countType, count, _type] = typeArgs
      if (!Array.isArray(_type) && typeof _type === 'object') { // a container
        structFromContainer(structName, _type, structPaddingLevel + 1)
        // encode type with typeArgs as type
        // if it's a top-level we need to add a header/footer as only encodingFromContainer will add it
        if (structPaddingLevel === 0) {
          writeHeader(structName, structPaddingLevel)
          encodingFromContainer(structName, _type, structPaddingLevel + 1, objPath, true)
        } else {
          encodeType(structName, unretardify(type), structPaddingLevel, objPath, excludeHeaders, objName)
        }
        if (structPaddingLevel === 0) writeFooter(structName, structPaddingLevel)
      } else if (structPaddingLevel) {
        encodeType(structName, unretardify(type), structPaddingLevel, objPath, excludeHeaders, objName)
      }
    } else if (typeName === 'container') {
      structFromContainer(structName, typeArgs[0], structPaddingLevel + 1)
      encodingFromContainer(structName, typeArgs[0], structPaddingLevel + 1, objPath, excludeHeaders, objName)
    } else if (typeName === 'mapper') {
      structFromMapper(structName, typeArgs, structPaddingLevel + 1)
    } else if (structPaddingLevel) {
      structForType(structName, type, structPaddingLevel + 1)
      encodeType(structName, type, structPaddingLevel, objPath, excludeHeaders, objName)
      // pushEncode(`  pdef6::proto::encode::${typeName}(stream, ${objName}.${structName});`)
    }
  }

  for (const structName in root) {
    // console.log(root[structName])
    visitType(structName, root[structName])
  }

  structLines += '}\n'
  sizeLines += '}\n'
  encodeLines += '}\n'
  decodeLines += '}\n' + footer

  structLines = structLines.replace('/*FWD_DECLS*/', structFwds.join('\n'))
  sizeLines = sizeLines.replace('/*FWD_DECLS*/', sizeFwds.join('\n'))
  encodeLines = encodeLines.replace('/*FWD_DECLS*/', encodeFwds.join('\n'))
  decodeLines = decodeLines.replace('/*FWD_DECLS*/', decodeFwds.join('\n'))

  return { structLines, sizeLines, encodeLines, decodeLines }
}

function visit (ir) {
  const { structLines } = visitRoot(ir, 'struct')
  const { sizeLines } = visitRoot(ir, 'size')
  const { encodeLines } = visitRoot(ir, 'encode')
  const { decodeLines } = visitRoot(ir, 'decode')
  return { structLines, sizeLines, encodeLines, decodeLines }
}

const compiled = visit(ir)
fs.writeFileSync('structs.h', compiled.structLines + '\n' + compiled.sizeLines + '\n' + compiled.encodeLines + '\n' + compiled.decodeLines)
// console.log(structLines)

const wanted = `
namespace pdef::proto::encode {
  void packet_toast_request(pdef::Stream &stream, const pdef::proto::packet_toast_request &value) {
    stream->writeString(value.title);
    stream->writeString(value.message);
  }
  void packet_request_permissions(pdef::Stream &stream, const pdef::proto::packet_request_permissions &value) {
    stream->writeInt64(value.entity_unique_id);
    stream->writeInt32(static_cast<int32_t>(value.permission_level));
    stream->writeInt32(static_cast<int32_t>(value.requested_permissions));
  }
}

pdef::Stream stream;
pdef::proto::packet_available_commands commands_packet {
  .values_len = 0,
  .enum_values = {},
  .suffixes = {},
  .enums = {},
  .command_data = {},
  .dynamic_enums = {},
  .enum_constraints = {},
};
pdef::proto::encode::packet_available_commands(stream, commands_packet);
char *data = stream->data();
size_t size = stream->size();

pdef::Stream stream2;
stream2.readFromBuffer(data, size);
mcpe_packet packet;
pdef::proto::decode::mcpe_packet(stream2, packet);
if (packet.entity_metadata)
`

// TODO: packet_crafting_data size is broken
// packet_set_score: switch compareTo's need to have correct ../ in front of them in the IR
// so we know how many levels up to go to find the enum type. Currently we
// assume the type is in the same level as the switch, which is not always true.
