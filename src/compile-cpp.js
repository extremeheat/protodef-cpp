const fs = require('fs')
let ir = require('./redone.json')
// ir = {
//   ItemLegacy: ir.ItemLegacy,
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
  zigzag64: 'int64_t',
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
    read (args, name, makeCallingCode) {
      return `
int ${name}_strlen; ${makeCallingCode(args.countType, `${name}_strlen`)};
if (!stream.readString(obj.${name}, ${name}_strlen)) return false;
`.trim()
    },
    write (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, 'length()'])};
stream.writeString(obj.${name});
`.trim()
    },
    size (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, 'length()'])};
  len += obj.${name}.length();
`.trim()
    }
  },
  buffer: {
    struct (args, name, makeCallingCode) {
      return makeCallingCode('std::vector<uint8_t>', name)
    },
    read (args, name, makeCallingCode) {
      const typeStr = protodefTypeToCpp[args.countType] || 'int'
      let lines = ''
      if (args.count) {
        lines += `if (!stream.readBuffer(obj.${name}, ${args.count})) return false;`        
      } else {
        lines += `${typeStr} ${name}_len; ${makeCallingCode(args.countType, `${name}_len`)};`
        lines += `if (!stream.readBuffer(obj.${name}, ${name}_len)) return false;`
      }
      return lines
    },
    write (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, 'size()'])};
stream.writeBuffer(obj.${name});
`.trim()
    },
    size (args, name, makeCallingCode) {
      return `
${makeCallingCode(args.countType, ['obj', name, 'size()'])};
len += obj.${name}.size();
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
  return fieldName.replaceAll('?', '').replaceAll(',', '_').replaceAll('^', '').replaceAll(':', '_')
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

function toSafeVar (name) {
  // add a _ suffix to reserved keywords in C++
  const illegal = ['byte', 'short', 'int', 'long', 'float', 'double', 'bool', 'default', 'break']
  if (illegal.includes(name)) name += '_'
  // check if name starts with a number
  if (!isNaN(name[0])) name = '_' + name
  return name
}

const filterNull = (arr) => (Array.isArray(arr[0]) ? arr[0] : arr).filter(x => !!x)
const dotJoin = (...arr) => filterNull(arr).map(toSafeVar).join('.')
const colonJoin = (...arr) => filterNull(arr).map(toSafeVar).join('::')
const escapeComment = (cmt) => cmt.replaceAll('*', '|')

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
    let oldTypeName = typeName
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
      let newName = promoteToPascalOrSuffix(fieldName)
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
        const inLocalScope = actualType[0] === 'container' || protodefTypeToCpp[typename]
        let parsedType = structForType(fieldName, actualType, structPaddingLevel, true)
        if (parsedType.startsWith('std::optional')) {
          parsedType = parsedType.replace('std::optional<','').replace('>','')
          // arrayLevel--
        }
        if (!parsedType.startsWith('//')) 
          push(`  ${typeStrForType(parsedType, n, arrayLevel, true)} /*3.0*/`)
        // push(`  std::vector<${newName}> ${deanonymizeStr(fieldName)}; /*3*/`)
      } else {
        const treatAsAnon = typeName !== 'mapper'
        push(`  ${typeStrForType(newName, n, false, true, treatAsAnon)} /*3.2*/`)
        // push(`  ${newName} ${deanonymizeStr(fieldName)}; /*3*/`)
      }
    } else if (customTypes[typeName]) {
      const typeImpl = customTypes[typeName]
      const structCode = typeImpl.struct(fieldType, n, (typename, varname) => typeStrForType(typename, varname, 0, true))
      structCode.split('\n').forEach(e => push('  ' + e + ` /*5.0*/`))
    } else if (root[typeName] && root[typeName][0] !== 'native') {
      if (isRootArray) {
        const rootArrayType = root[oldTypeName][3]
        push(`  ${typeStrForType(Array.isArray(rootArrayType) ? rootArrayType[0] : oldTypeName, n, 1)} /*1.0*/`)
      } else {
        push(`  ${typeStrForType(typeName, n)} /*4.0*/`)
      } 
    } else {
      push(` // ERROR: unknown type ${typeName} L${structPaddingLevel} /*5.1*/`)
      // throw new Error(`Missing custom type ${typeName}`)
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
    const name = Array.isArray(varName) ? varName.map(toSafeVar).join('.') : toSafeVar(varName)
    const sizeVar = `len_${sizeIx++}`
    return `${isAnon ? `EXPECT_OR_BAIL(${name}); ` : ''}size_t ${sizeVar} = pdef::proto::size::${type}(stream, ${isAnon ? '*' : ''}${name}); EXPECT_OR_BAIL(${sizeVar}); len += ${sizeVar}`
  }
  const makeEncodeStr = (type, varName, isAnon) => protodefTypeToCppEncode[type]
    ? `WRITE_OR_BAIL(${protodefTypeToCppEncode[type]}, ${Array.isArray(varName) ? varName.map(toSafeVar).join('.') : toSafeVar(varName)})`
    : `pdef::proto::encode::${type}(stream, ${isAnon ? '*' : ''}${Array.isArray(varName) ? varName.map(toSafeVar).join('.') : varName})`

  function makeDecodeStr (type, varName, maybe) {
    const name = Array.isArray(varName) ? varName.join('.') : varName
    if (protodefTypeToCppDecode[type]) {
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

  function encodeType (fieldName, fieldType, structPaddingLevel = 0, objPath) {
    if (!Array.isArray(objPath)) throw new Error('objPath is required')
    const objName = objPath.length > 1 ? 'v' : 'obj'
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
    const pushSize = (str) => { sizeLines += pad(str) + '\n' }
    const pushEncode = (str) => { encodeLines += pad(str) + '\n' }
    const pushSizeEncode = (str) => (pushSize(str), pushEncode(str))
    const pushAll = (str) => (pushSize(str), pushEncode(str), pushDecode(str))
    const pushDecode = (str) => { decodeLines += pad(str) + '\n' }

    console.log(`.  ${fieldName}: ${fieldType}`)
    fieldType = unretardify(fieldType)
    if (fieldName.startsWith('?')) return

    let typeName = fieldType[0]
    const isRootArray = root[typeName] && root[typeName][0] === 'array'
    const shouldInlineFromRoot = checkShouldInlineFromRoot(typeName)

    const variableName = fieldType[5] || fieldType['*name'] || fieldName
    const isAnon = variableName.startsWith('?')
    const n = deanonymizeStr(variableName) + ((deanonymizeStr(variableName) !== deanonymizeStr(fieldName)) ? `/*~${variableName} < ${fieldName}*/` : '')
    
    if (shouldInlineFromRoot) {
      fieldType = unretardify(root[typeName])
      typeName = fieldType[0]
      // pushAll('// inlined from root')
    }
    // In case it's modified

    if (typeName === 'void') return // TODO: remove this in the IR

    const structPropName = dotJoin(objName, n)

    const builtinEncodeFn = protodefTypeToCppEncode[typeName]
    if (builtinEncodeFn) {
      if (fieldName.endsWith('^')) {
        pushSizeEncode(`  const ${protodefTypeToCpp[typeName] ?? ('pdef::proto::' + typeName)} &${n} = ${structPropName}; /*0.1*/`)
      } else {
        pushSize(`  ${makeSizeStr(typeName, [objName, n])}; /*0.2*/`)
      }
      pushEncode('  ' + makeEncodeStr(typeName, [objName, n]) + '; /*0.4*/')
      pushDecode('  ' + makeDecodeStr(typeName, [objName, n], isAnon) + '; /*0.5*/')
      // .... this ^ needs to be similarly handled in each case below for read/write/size
      if (fieldName.endsWith('^')) pushDecode(`  const ${protodefTypeToCpp[typeName] ?? ('pdef::proto::' + typeName)} &${n} = ${structPropName}; /*0.6*/`)
    } else if (isRootArray && !shouldInlineFromRoot) {
      const lengthType = root[typeName][1]
      pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'])}; /*2.1*/`)
      pushEncode(`  for (const auto &v : ${structPropName}) { ${makeEncodeStr(typeName, 'v')}; } /*6*/`)
      // TODO: Can't decode into .size() ! We need a separate variable for this.
      pushDecode(`  ${makeDecodeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*2.3*/`)
      pushDecode(`  for (auto &v : ${structPropName}) { ${makeDecodeStr(typeName, 'v', isAnon)}; } /*6*/`)
      pushSize(`  ${makeSizeStr(lengthType, [objName, n, 'size()'])}; /*2.4*/`)
      pushSize(`  for (const auto &v : ${structPropName}) { ${makeSizeStr(typeName, 'v')}; } /*6*/`)
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
          pushSize(`  ${makeSizeStr(lengthTyp, [lengthVariable, 'size()'])}; /*1.1*/`)
          pushEncode(`  ${makeEncodeStr(lengthTyp, [lengthVariable, 'size()'])}; /*1.2*/`)
          // pushDecode(`  int ${lengthVariable}_len = *${lengthVariable}_ptr; /*1*/`)
        } else {
          pushSize(`  ${makeSizeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*1.3*/`)
          pushEncode(`  ${makeEncodeStr(lengthType, [objName, n, 'size()'], isAnon)}; /*1.4*/`)
          const typeStr = protodefTypeToCpp[lengthType] || 'int'
          pushDecode(`  ${typeStr} ${n}_len; /*1.5*/`)
          pushDecode(`  ${makeDecodeStr(lengthType, [n + '_len'])}; /*1.5*/`)
        }
        const actualType = unretardify(fieldType[3])
        if (actualType[0] === 'container') {
          // inline
          pushSizeEncode(`  for (const auto &v : ${[objName, n].join('.')}) { /*5*/`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5*/`), pushDecode(`    auto &v = ${[objName, n].join('.')}[i]; /*5.1*/`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5*/`), pushDecode(`    auto &v = ${[objName, n].join('.')}[i]; /*5.1*/`)
          encodingFromContainer(newName, actualType[1], structPaddingLevel + 1, structPaddingLevel === 0 ? objPath.concat('') : objPath.concat(promoteToPascalOrSuffix(n)), true)
          pushSizeEncode('  }')
          pushDecode('  }')
        } else if (actualType[0] === 'array') {
          pushSizeEncode(`  for (const auto &v : ${structPropName}) { /*5*/`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { /*5*/`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { /*5*/`)
          const actualActualType = unretardify(actualType[3])
          encodeType('', actualType, structPaddingLevel + 1, objPath, true)
          pushSizeEncode('  }')
          pushDecode('  }')
        } else {
          pushEncode(`  for (const auto &v : ${structPropName}) { ${makeEncodeStr(actualType, 'v')}; /*3.1*/ }`)
          pushSize(`  for (const auto &v : ${structPropName}) { ${makeSizeStr(actualType, 'v')}; /*3.2*/ }`)
          if (lengthVar) pushDecode(`  for (int i = 0; i < ${lengthVar[0]}; i++) { ${makeDecodeStr(actualType, [objName, n + '[i]'])}; /*3.3*/ }`)
          else pushDecode(`  for (int i = 0; i < ${n}_len; i++) { ${makeDecodeStr(actualType, [objName, n + '[i]'])}; /*3.4*/ }`)
        }
      } else if (typeName === 'switch') {
        const compareTo = Array.isArray(fieldType[1]) ? fieldType[1][2] : fieldType[1]
        const _compareToType = fieldType[2]
        const compareToType = (fieldType[2] && fieldType[2] !== 'mapper') ? fieldType[2] : promoteToPascalOrSuffix(compareTo)
        const cases = fieldType[3]
        pushAll(`  switch (${compareTo}) { /*8.0*/`)
        for (const [caseName, caseType] of Object.entries(cases)) {
          // let absName
          // if (Array.isArray(caseType)) {
          //   absName = caseType[5]
          // } else {
          //   absName = caseType['*name']
          // }
          // if(!absName) console.log('no absName', caseType)
          // absName = deanonymizeStr(absName)
          if (compareToType === 'bool') { pushAll(`    case ${caseName}: { /*8.0*/`) } 
          else if ((['true', 'false'].includes(caseName) && (_compareToType !== 'mapper')) || !isNaN(caseName)) { pushAll(`    case ${caseName}: { /*8.1*/`) }
          else if (caseName === 'default') { pushAll(`    default: { /*8.1*/`) }
          else if (caseName.startsWith('/')) { pushAll(`    case pdef::proto::${toSafeVar(caseName).replace('/', '')}: { /*8.2*/`) }
          else { pushAll(`    case pdef::proto::${colonJoin(objPath)}::${compareToType}::${toSafeVar(promoteToPascalOrSuffix(caseName))}: { /*8.3*/`) }
          // encodingFromContainer(caseName, caseType, structPaddingLevel + 2, objName)
          let realName = isAnon ? null : caseType[5] || caseType['*name']
          const isScoped = isAnon ? false : !Array.isArray(caseType)
          if (realName) {
            realName = deanonymizeStr(realName)
            // TODO: handle optional fields
            const structureName = promoteToPascalOrSuffix(realName)
            if (!Array.isArray(caseType)) {
              pushDecode(`      const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${objName}.${realName} = {}; /*8.4*/`)
              // "expect or bail" is not needed here because we already checked the switch case
              pushEncode(`      const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${objName}.${realName}; /*8.5*/`)
              pushSize(`      EXPECT_OR_BAIL(${objName}.${realName}); const pdef::proto::${colonJoin(objPath)}::${structureName} &v = *${objName}.${realName}; /*8.6*/`)
            }
          }
          visitType(n, caseType, structPaddingLevel + 2, (isScoped && realName) ? objPath.concat(promoteToPascalOrSuffix(realName)) : objPath, true)
          pushAll('      break;')
          pushAll('    } /*8.7*/')
        }
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
        pushEncode(`  const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${isAnon ? `*` : ''}${structPropName}; /*${JSON.stringify(objPath)}*/ /*7.4*/`)
        pushSize(`  ${isAnon ? `EXPECT_OR_BAIL(${varName}); ` : ''}const pdef::proto::${colonJoin(objPath)}::${structureName} &v = ${isAnon ? `*` : ''}${structPropName}; /*${JSON.stringify(objPath)}*/ /*7.4*/`)
      } else {
        // TODO: handle custom types
        // we'd call into the specific encode function for this type
        if (fieldName.endsWith('^')) {
          pushSizeEncode(`  const ${protodefTypeToCpp[typeName] ?? ('pdef::proto::' + typeName)} &${n} = ${structPropName}; /*0.1*/`)
        }
        if (Array.isArray(fieldType)) {
          const actualType = fieldType[0]
          if (customTypes[actualType]) {
            const typeImpl = customTypes[actualType]
            const sizeCode = typeImpl.size(fieldType[1], n, (type, args) => makeSizeStr(type, args, isAnon))
            const encodeCode = typeImpl.write(fieldType[1], n, (type, args) => makeEncodeStr(type, args, isAnon))
            const decodeCode = typeImpl.read(fieldType[1], n, (type, args) => makeDecodeStr(type, args, isAnon))
            pushSize(`  ${sizeCode.replaceAll('obj', objName)} /*${fieldName}: ${actualType}*/ /*4.1*/`)
            pushEncode(`  ${encodeCode.replaceAll('obj', objName)} /*${n}: ${actualType}*/ /*4.2*/`)
            pushDecode(`  ${decodeCode.replaceAll('obj', objName)} /*${n}: ${actualType}*/ /*4.3*/`)
          } else if (root[actualType] && root[actualType][0] !== 'native') {
            pushSize(`  ${makeSizeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*${escapeComment(n)}*/ /*4.4*/`)
            pushEncode(`  ${makeEncodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*${typeName}*/ /*4.5*/`)
            pushDecode(`  ${makeDecodeStr(Array.isArray(fieldType) ? fieldType[0] : fieldType, [objName, n], isAnon)}; /*4.6*/`)
          } else {
            console.warn('Do not know how to handle unknown type: ' + actualType)
            pushSize(`// ERROR: unknown type ${actualType} /*4.1*/`)
            pushEncode(`// ERROR: unknown type ${actualType} /*4.2*/`)
            pushDecode(`// ERROR: unknown type ${actualType} /*4.3*/`)
          }
        } else {

        }
        if (fieldName.endsWith('^')) {
          pushDecode(`  const ${protodefTypeToCpp[typeName] ?? ('pdef::proto::' + typeName)} &${n} = ${structPropName}; /*0.7*/`)
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
    pushEncode(`  if (allocate) { auto writeSize = pdef::proto::size::${name}(stream, obj); if (!writeSize) return false; stream.reserve(stream, writeSize); }`)
    pushDecode(`bool ${name}(pdef::Stream &stream, pdef::proto::${name} &obj) {`)
    pushSize(`size_t ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj) {`)
    pushSize('  size_t len = 0;')
    encodeFwds.push(`bool ${name}(pdef::Stream &stream, const pdef::proto::${name} &obj, bool allocate = true);`)
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

  function encodingFromContainer (name, container, structPaddingLevel = 0, objPath, excludeHeaders) {
    if (!Array.isArray(objPath)) throw new Error('objPath is required')
    if (mode === 'struct') return

    if (!excludeHeaders) {
      writeHeader(name, structPaddingLevel)
    }
    for (const [fieldName, fieldType] of Object.entries(container)) {
      if (fieldName.startsWith('*')) continue
      encodeType(fieldName, fieldType, structPaddingLevel, objPath)
    }
    if (!excludeHeaders) {
      writeFooter(name, structPaddingLevel)
    }
  }

  function visitType (structName, type, structPaddingLevel = 0, objPath, excludeHeaders) {
    objPath ||= [structName]
    const pad = (str) => '  '.repeat(structPaddingLevel) + str
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
          encodeType(structName, unretardify(type), structPaddingLevel, objPath, excludeHeaders)
        }
        if (structPaddingLevel === 0) writeFooter(structName, structPaddingLevel)        
      } else if (structPaddingLevel) {
        encodeType(structName, unretardify(type), structPaddingLevel, objPath, excludeHeaders)
      }
    } else if (typeName === 'container') {
      structFromContainer(structName, typeArgs[0], structPaddingLevel + 1)
      encodingFromContainer(structName, typeArgs[0], structPaddingLevel + 1, objPath, excludeHeaders)
    } else if (typeName === 'mapper') {
      structFromMapper(structName, typeArgs, structPaddingLevel + 1)
    } else if (structPaddingLevel) {
        structForType(structName, type, structPaddingLevel + 1)
        encodeType(structName, type, structPaddingLevel, objPath, excludeHeaders)
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


//TODO: packet_crafting_data size is broken
