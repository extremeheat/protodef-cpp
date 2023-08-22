const fs = require('fs')
const ir = require('./redone.json')
// ir = {
//   string: ir.string,
//   packet_available_commands: ir.packet_available_commands,
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
  cstring: 'std::string'
  // buffer: 'std::vector<uint8_t>'
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
      return `using ${name} = std::string;`
    },
    read (args, name, makeCallingCode) {
      return `
int ${name}_strlen = ${makeCallingCode(args.countType)};
obj->${name} = stream->readString(${name}_strlen);
`.trim()
    },
    write (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, '.length()'])};
stream->writeString(obj->${name}, 'obj->${name}.length()');
`.trim()
    },
    size (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, '.length()'])};
size += obj->${name}.length();
`.trim()
    }
  }
}

const protodefTypeToCppDecode = Object.fromEntries(
  Object.entries(protodefTypeToCppEncode)
    .map(([k, v]) => [k, v.replace('write', 'read')])
)

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
  return fieldName.replaceAll('?', '').replaceAll(',', '_').replaceAll('^', '')
}

function promoteToPascalOrSuffix (str) {
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

function toSafeVar (name) {
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

function visitRoot (root, mode) {
  let structLines = headers + 'namespace pdef::proto {\n'
  let sizeLines = 'namespace pdef::proto::size {\n'
  let encodeLines = 'namespace pdef::proto::encode {\n'
  let decodeLines = 'namespace pdef::proto::decode {\n'

  const nativeTypes = []
  for (const [key, val] of Object.entries(root)) {
    if (val[0] === 'native') nativeTypes.push(key)
  }

  function structFromContainer (name, container, structPaddingLevel = 0) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const push = (str) => { structLines += pad(str) + '\n' }

    push(`struct ${name} {`)
    for (const [fieldName, fieldType] of Object.entries(container)) {
      if (fieldName.startsWith('*')) continue
      structForType(fieldName, fieldType, structPaddingLevel)
    }
    push('};')
    console.log('{\n')
  }

  function structForType (fieldName, fieldType, structPaddingLevel) {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const push = (str) => { structLines += pad(str) + '\n' }

    fieldType = unretardify(fieldType)
    console.log(`  ${fieldName}: ${fieldType}`)
    if (fieldName.endsWith('?')) return // When generating structs, we ignore switches
    const typeName = fieldType[0]
    const n = deanonymizeStr(typeName)

    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    if (typeName === 'void') return // TODO: remove this in the IR
    else if (protodefTypeToCpp[typeName]) push(`  ${protodefTypeToCpp[typeName]} ${n};`)
    else if (isRootArray) push(`  std::vector<pdef::proto::${typeName}> ${n};`)
    else if (fieldName.startsWith('?')) push(`  std::optional<pdef::proto::${typeName}> ${n};`)
    else if (typeName === 'container' || typeName === 'array' || typeName === 'mapper') {
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
    } else if (nativeTypes.includes(typeName) || customTypes[typeName]) {
      return// TODO
      const typeImpl = customTypes[typeName]
      if (!typeImpl) throw new Error(`Missing custom type ${typeName}`)
      const structCode = typeImpl.struct(fieldType, fieldName, structPaddingLevel)
      push(`// custom ${typeName} L${structPaddingLevel}`)
      structCode.split('\n').forEach(push)
    } else push(`  pdef::proto::${typeName} ${n};`)
  }

  function structFromMapper (name, mapper, structPaddingLevel) {
    if (mode !== 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const enumLines = []
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

  function makeSizeStr (type, varName) {
    const s = protodefTypeSizes[type]
    if (typeof s === 'number') return `len += ${s}`
    else if (typeof s === 'string') return `len += stream.${protodefTypeSizes[type]}(${Array.isArray(varName) ? varName.join('.') : varName})`
    return `len += pdef::proto::size::${type}(${Array.isArray(varName) ? varName.join('.') : varName})`
  }
  const makeEncodeStr = (type, varName) => protodefTypeToCppEncode[type]
    ? `WRITE_OR_BAIL(${protodefTypeToCppEncode[type]}, ${Array.isArray(varName) ? varName.join('.') : varName})`
    : `pdef::proto::encode::${type}(stream, ${Array.isArray(varName) ? varName.join('.') : varName})`

  const makeDecodeStr = (type, varName) => protodefTypeToCppDecode[type]
    ? `READ_OR_BAIL(${protodefTypeToCppDecode[type]}, ${Array.isArray(varName) ? varName.join('.') : varName})`
    : `pdef::proto::decode::${type}(stream, ${Array.isArray(varName) ? varName.join('.') : varName})`

  function encodeType (fieldName, fieldType, structPaddingLevel = 0, objName = 'obj') {
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushSizeEncode = (str) => (pushSize(str), pushEncode(str))
    const pushAll = (str) => (pushSize(str), pushEncode(str), pushDecode(str))
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }

    console.log(`.  ${fieldName}: ${fieldType}`)
    fieldType = unretardify(fieldType)
    if (fieldName.startsWith('?')) return

    const typeName = fieldType[0]
    const n = deanonymizeStr(fieldName)
    if (fieldName.endsWith('^')) {
      // Declare as a local variable
      pushSizeEncode(`  ${protodefTypeToCpp[typeName] ?? ('pdef::proto::' + typeName)} ${n} = obj.${n}; /*0*/`)
    } else if (protodefTypeSizes[typeName]) pushSize(`  ${makeSizeStr(typeName)}; /*${fieldName}: ${typeName}*/ /*0*/`)
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    if (typeName === 'void') return // TODO: remove this in the IR

    const builtinEncodeFn = protodefTypeToCppEncode[typeName]
    if (builtinEncodeFn) {
      pushEncode('  ' + makeEncodeStr(typeName, [objName, n]) + '; /*0*/')
      pushDecode('  ' + makeDecodeStr(typeName, [objName, n]) + '; /*0*/')
    } else if (isRootArray) {
      const lengthType = root[typeName][1]
      pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*2*/`)
      pushEncode(`  for (const auto &v : ${objName}.${n}) { ${makeEncodeStr(typeName, 'v')}; } /*6*/`)
      pushDecode(`  ${makeDecodeStr(lengthType, [objName, n, 'size()'])}; /*2*/`)
      pushDecode(`  for (auto &v : ${objName}.${n}) { ${makeDecodeStr(typeName, 'v')}; } /*6*/`)
      pushSize(`  len += ${makeSizeStr(lengthType, [objName, n, 'size()'])}; /*2*/`)
      pushSize(`  for (const auto &v : ${objName}.${n}) { len += ${makeSizeStr(typeName, 'v')}; } /*6*/`)
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
          pushSize(`  ${makeSizeStr(lengthTyp, [lengthVariable, 'size()'])}; /*1*/`)
          pushEncode(`  ${makeEncodeStr(lengthTyp, [lengthVariable, 'size()'])}; /*1*/`)
          pushDecode(`  int ${lengthVariable}_len = ${objName}.${lengthVariable}.length(); /*1*/`)
        } else {
          pushSize(`  ${makeSizeStr(lengthType, [objName, n, 'size()'])}; /*1*/`)
          pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*1*/`)
          pushDecode(`  int ${n}_len;`)
          pushDecode(`  ${makeDecodeStr(lengthType, [n + '_len'])}; /*1*/`)
        }
        const actualType = unretardify(fieldType[3])
        if (actualType[0] === 'container') {
          // inline
          pushSizeEncode(`  for (const auto &v : ${objName}.${n}) { /*5*/`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5*/`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5*/`)
          encodingFromContainer(newName, actualType[1], structPaddingLevel + 1, 'v', true)
          pushSizeEncode('  }')
          pushDecode('  }')
        } else {
          pushEncode(`  for (const auto &v : ${objName}.${n}) { ${makeEncodeStr(actualType, 'v')}; /*3*/ }`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}_len; i++) { ${makeDecodeStr(actualType, [objName, n + '[i]'])}; /*3*/ }`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { ${makeDecodeStr(actualType, [objName, n + '[i]'])}; /*3*/ }`)
        }
      } else if (typeName === 'switch') {
        const compareTo = Array.isArray(fieldType[1]) ? fieldType[1][2] : fieldType[1]
        const compareToType = fieldType[2] ? fieldType[2] : promoteToPascalOrSuffix(compareTo)
        const cases = fieldType[3]
        pushAll(`  switch (${compareTo}) {`)
        for (const [caseName, caseType] of Object.entries(cases)) {
          let absName
          if (Array.isArray(caseType)) {
            absName = caseType[5]
          } else {
            absName = caseType['*name']
          }
          // if(!absName) console.log('no absName', caseType)
          // absName = deanonymizeStr(absName)
          if (compareToType === 'bool') { pushAll(`    case ${caseName}: {`) } else { pushAll(`    case ${compareToType}::${toSafeVar(caseName)}: {`) }
          // encodingFromContainer(caseName, caseType, structPaddingLevel + 2, objName)
          visitType(n, caseType, structPaddingLevel + 2, objName)
          pushAll('      break;')
          pushAll('    }')
        }
        pushEncode('  }')
      } else if (typeName === 'mapper') {
        const actualType = fieldType[1]
        pushSize(`  ${makeSizeStr(actualType, [objName, n])}; /*${fieldName}: ${actualType}*/ /*7*/`)
        pushEncode(`  ${makeEncodeStr(actualType, [objName, n])}; /*7*/`)
        pushDecode(`  ${makeDecodeStr(actualType, [objName, n])}; /*7*/`)
      } else {
        // we'd call into the specific encode function for this type
        pushSize(`  ${makeSizeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n])}; /*${fieldName}*/ /*4*/`)
        pushEncode(`  ${makeEncodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n])}; /*4*/`)
        pushDecode(`  ${makeDecodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n])}; /*4*/`)
      }
    }
  }

  function encodingFromContainer (name, container, structPaddingLevel = 0, objName = 'obj', excludeHeaders) {
    if (mode === 'struct') return
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }

    if (!excludeHeaders) {
      pushEncode(`bool ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj, bool allocate = true) {`)
      pushEncode(`  if (allocate) stream.reserve(stream, pdef::proto::size::${name}(obj));`)
      pushDecode(`bool ${name}(pdef::Stream &stream, pdef::proto::${name} &obj) {`)
      pushSize(`size_t ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj) {`)
      pushSize('  size_t len = 0;')
    }
    for (const [fieldName, fieldType] of Object.entries(container)) {
      if (fieldName.startsWith('*')) continue
      encodeType(fieldName, fieldType, structPaddingLevel, objName)
    }
    if (!excludeHeaders) {
      pushSize('  return len;')
      pushSize('}')
      pushEncode('  return true;')
      pushEncode('}')
      pushDecode('  return true;')
      pushDecode('}')
    }
  }

  function visitType (structName, type, structPaddingLevel = 0, objName = 'obj') {
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
      structForType(structName, type, structPaddingLevel + 1)
      encodeType(structName, type, structPaddingLevel, objName)
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
  decodeLines += '}\n'

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
