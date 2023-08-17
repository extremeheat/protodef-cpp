const fs = require('fs')
let ir = require('./redone.json')
ir = {
  packet_available_commands: ir.packet_available_commands,
  // packet_education_settings: ir.packet_education_settings,
}

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
  string: 'std::string',
  buffer: 'std::vector<uint8_t>'
}
const protodefTypeToCppEncode = {
  u8: 'writeByte',
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
  buffer: 'writeBuffer',
  varint: 'writeUnsignedVarInt',
  varint64: 'writeUnsignedVarLong',
  zigzag32: 'writeZigZagVarInt',
  zigzag64: 'writeZigZagVarLong',
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
  zigzag64: 'sizeOfZigZagVarLong',
}
const customTypes = {
  pstring: {
    read (args, name, makeCallingCode) {
      return `
int ${name}_strlen = ${makeCallingCode(args.countType)};
obj->${name} = stream->readString(${name}_strlen);
`.trim()
    },
    write (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, 'obj->' + name + '.length()')};
stream->writeString(obj->${name}, 'obj->${name}.length()');
`.trim()
    },
    size (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, 'obj->' + name + '.length()')};
size += obj->${name}.length();
`.trim()
    },
    struct (args, name, makeCallingCode) {
      return `std::string ${name};`.trim()
    }
  },
}

const protodefTypeToCppDecode = Object.fromEntries(
  Object.entries(protodefTypeToCppEncode)
    .map(([k, v]) => [k, v.replace('write', 'read')])
)

function unretardify(objOrArr) {
  if (objOrArr == null) return []
  if (Array.isArray(objOrArr)) {
    return objOrArr
  } else if (typeof objOrArr === 'object') {
    return ['container', objOrArr]
  }
  return objOrArr
}

function deanonymizeStr(fieldName) {
  return fieldName.replaceAll('?', '').replaceAll(',', '_').replaceAll('^', '')
}

function promoteToPascalOrSuffix(str) {
  str = deanonymizeStr(str)
  // Check if field str starts with lowercase
  if (str[0] === str[0].toLowerCase()) {
    // we can promote name to PascalCase from snake_case
    return str.split('_').map(s => s[0].toUpperCase() + s.slice(1)).join('')
  } else {
    // we need to add a _t suffix
    return str + '_t'
  }
}

function toSafeVar(name) {
  // add a _ suffix to reserved keywords in C++
  const illegal = ['byte', 'short', 'int', 'long', 'float', 'double', 'bool']
  if (illegal.includes(name)) return name + '_'
  return name
}

const headers = `
#define WRITE_OR_BAIL(fn, val) if (!fn(stream, val)) { return false; }
`
const footer = `
#undef WRITE_OR_BAIL
`

function visitRoot(root, mode) {
  let structLines = headers + 'namespace pdef::proto {\n'
  let encodeLines = 'namespace pdef::proto::encode {\n'
  let decodeLines = 'namespace pdef::proto::decode {\n'

  function structFromContainer(name, container, structPaddingLevel = 0) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const push = (str) => { structLines += pad(str) + '\n' }

    console.log(`struct ${name} {\n`)

    push(`struct ${name} {`)
    for (let [fieldName, fieldType] of Object.entries(container)) {
      fieldType = unretardify(fieldType)
      console.log(`  ${fieldName}: ${fieldType}`)
      if (fieldName.endsWith('?')) continue // When generating structs, we ignore switches
      if (fieldType.length === 1) {
        const n = deanonymizeStr(fieldName)
        const typeName = fieldType[0]
        const isArray = root[typeName] && root[typeName][0] === 'array'
        if (typeName === 'void') continue // TODO: remove this in the IR
        else if (protodefTypeToCpp[typeName]) push(`  ${protodefTypeToCpp[typeName]} ${n};`)
        else if (isArray) push(`  std::vector<pdef::proto::${typeName}> ${n};`)
        else if (fieldName.startsWith('?')) push(`  std::optional<pdef::proto::${typeName}> ${n};`)
        else push(`  pdef::proto::${typeName} ${n};`)
      } else {
        switch (fieldType[0]) {
          case 'container':
          case 'array':
          case 'mapper': {
            // We need 2 separate fields in the struct for this.
            // One for the enum, and one for the actual value.
            // For example when writing:
            // stream->color = Color::red;
            // We can either use PascalCase for the enum, or add a _t suffix.
            let newName = promoteToPascalOrSuffix(fieldName)
            visitType(newName, fieldType, structPaddingLevel)
            if (fieldType[0] === 'array') {
              const actualType = fieldType[3][0]
              if (protodefTypeToCpp[actualType]) newName = protodefTypeToCpp[actualType]
              push(`  std::vector<${newName}> ${deanonymizeStr(fieldName)};`)
            } else if (fieldName.startsWith('?')) {
              push(`  std::optional<${newName}> ${deanonymizeStr(fieldName)};`)
            } else {
              push(`  ${newName} ${deanonymizeStr(fieldName)};`)
            }
            break
          }
        }
      }
    }
    push('};')
    console.log(`{\n`)
  }

  function structFromMapper(name, mapper, structPaddingLevel) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    let enumLines = []
    const [enumType, enumValues] = mapper
    for (const [k, v] of Object.entries(enumValues)) {
      enumLines.push(`  ${v} = ${k},`)
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

  function encodeType (fieldName, fieldType, structPaddingLevel = 0, objName = 'obj') {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }
    const makeEncodeStr = (type, varName) => protodefTypeToCppEncode[type] 
      ? `WRITE_OR_BAIL(${protodefTypeToCppEncode[type]}, ${Array.isArray(varName) ? varName.join('.') : varName})`
      : `pdef::proto::encode::${type}(stream, ${Array.isArray(varName) ? varName.join('.') : varName})`

    console.log(`.  ${fieldName}: ${fieldType}`)
    fieldType = unretardify(fieldType)
    if (fieldName.startsWith('?')) return

    const typeName = fieldType[0]
    const n = deanonymizeStr(fieldName)
    if (fieldName.endsWith('^')) {
      // Declare as a local variable
      pushEncode(`  ${protodefTypeToCpp[typeName] ?? ('pdef::proto::'+typeName)} ${n} = obj.${n};`)
    }
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    if (typeName === 'void') return // TODO: remove this in the IR
    const builtinEncodeFn = protodefTypeToCppEncode[typeName]
    if (builtinEncodeFn) pushEncode('  ' + makeEncodeStr(typeName, [objName, n]) + '; /*0*/')
    else if (isRootArray) {
      const lengthType = root[typeName][1]
      pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*2*/`)
      pushEncode(`  for (const auto &v : ${objName}.${n}) { ${makeEncodeStr(typeName, 'v')}; } /*6*/`)
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
          const [lengthVariable,lengthTyp] = lengthVar
          pushEncode(`  ${makeEncodeStr(lengthTyp, [lengthVariable, 'size()'])}; /*1*/`)
        } else {
          pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*1*/`)
        }
        const actualType = unretardify(fieldType[3])
        if (actualType[0] === 'container') {
          // inline
          pushEncode(`  for (const auto &v : ${objName}.${n}) {`)
          encodingFromContainer(newName, actualType[1], structPaddingLevel + 1, 'v', true)
          pushEncode('  }')
        } else {
          pushEncode(`  for (const auto &v : ${objName}.${n}) { ${makeEncodeStr(actualType, 'v')}; /*3*/ }`)
        }
      } else if (typeName === 'switch') {
        const compareTo = fieldType[1]
        const compareToType = fieldType[2].length === 1 ? fieldType[2] : promoteToPascalOrSuffix(compareTo)
        const cases = fieldType[3]
        pushEncode(`  switch (${compareTo}) {`)
        for (const [caseName, caseType] of Object.entries(cases)) {
          if (compareToType === 'bool')
            pushEncode(`    case ${caseName}: {`)
          else
            pushEncode(`    case ${compareToType}::${toSafeVar(caseName)}: {`)
          // encodingFromContainer(caseName, caseType, structPaddingLevel + 2, objName)
          visitType(n, caseType, structPaddingLevel + 2)
          pushEncode('      break;')
          pushEncode('    }')
        }
        pushEncode('  }')
      } else if (typeName === 'mapper')  {
        const actualType = fieldType[1]
        pushEncode(`  ${makeEncodeStr(actualType, [objName, n])}; /*4*/`)
      } else {
        // we'd call into the specific encode function for this type
        pushEncode(`  ${makeEncodeStr(Array.isArray(fieldType)?fieldType[0]:fieldType, [objName, n])}; /*4*/`)
      }
    }
  }

  function encodingFromContainer(name, container, structPaddingLevel = 0, objName = 'obj', excludeHeaders) {
    if (mode !== 'encode') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }

    if (!excludeHeaders) pushEncode(`void ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj) {`)
    for (let [fieldName, fieldType] of Object.entries(container)) {
      encodeType(fieldName, fieldType, structPaddingLevel, objName)
    }
    if (!excludeHeaders) pushEncode('}')
  }

  function visitType(structName, type, structPaddingLevel = 0, objName = 'obj') {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const [typeName, ...typeArgs] = unretardify(type)
    console.log(typeName, typeArgs)
    if (typeName === 'native') {
      structLines += `// ${structName} is built in\n`
    } else if (typeName === 'array') {
      const [countType, count, type] = typeArgs
      if (!Array.isArray(type) && typeof type === 'object') { // a container
        structFromContainer(structName, type, structPaddingLevel + 1)
      }
    } else if (typeName === 'container') {
      structFromContainer(structName, typeArgs[0], structPaddingLevel + 1)
      encodingFromContainer(structName, typeArgs[0], structPaddingLevel + 1)
    } else if (typeName === 'mapper') {
      structFromMapper(structName, typeArgs, structPaddingLevel + 1)
    } else {
      encodeType(structName, typeName, structPaddingLevel, objName)
      // pushEncode(`  pdef6::proto::encode::${typeName}(stream, ${objName}.${structName});`)
    }
  }

  for (const structName in root) {
    // console.log(root[structName])
    visitType(structName, root[structName])
  }

  structLines += '}\n'
  encodeLines += '}\n'
  decodeLines += '}\n'

  return mode === 'struct' ? structLines : encodeLines
}

function visit(ir) {
  const structLines = visitRoot(ir, 'struct')
  const encodeLines = visitRoot(ir, 'encode')
  return { structLines, encodeLines, decodeLines: '' }
}

let compiled = visit(ir)
fs.writeFileSync('structs.h', compiled.structLines + '\n' + compiled.encodeLines + '\n' + compiled.decodeLines)
// console.log(structLines)

x = `
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
`