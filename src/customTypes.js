class CppOpsGroup {
  constructor (primitivesMap, sizerMap, encoderMap, decoderMap, toSafeVar, joinType, currentPaddingLevel) {
    this.ops = []
    this.lines = ''
    this.primitivesMap = primitivesMap
    this.sizerMap = sizerMap
    this.encoderMap = encoderMap
    this.decoderMap = decoderMap
    this.toSafeVar = toSafeVar
    this.joinType = joinType
    this.initialPadding = currentPaddingLevel || 0
    this.encoder2Primitive = Object.fromEntries(Object.entries(this.encoderMap).map(([k, v]) => [v, k]))
  }

  joinVarNameIfNeeded (varName) {
    return Array.isArray(varName) ? this.joinType(...varName) : this.toSafeVar(varName)
  }

  resolveType (type) {
    if (!type) throw Error('type is required')
    return this.primitivesMap[type] || type
  }

  pushType (name, options) {
    this.ops.push(['type', name, options?.marker])
  }

  pushStructField (name, type, options) {
    type = this.resolveType(type)
    this.ops.push(['assignment', `${type} ${name};\n`, options?.marker])
  }

  pushPrimitiveStruct (name, fields, embedded, options) {
    let topLevel = `struct ${name} {\n`
    let embeddedStr = ''
    for (const { type, varName, defaultValue } of fields) {
      topLevel += `  ${type} ${varName}${defaultValue ? ` = ${defaultValue}` : ''};\n`
    }
    if (embedded) {
      topLevel += '};\n'
      embeddedStr = `  ${name} ${name};\n`
    } else {
      topLevel += `} ${name};\n`
    }
    this.ops.push(['primitiveStruct', topLevel, embeddedStr, options?.marker])
    return [topLevel, embeddedStr]
  }

  pushStreamReadOrBail (op, varName, arg, options) {
    this.ops.push(['read', arg
      ? `if (!stream.${op}(${varName}, ${arg})) return false;\n`
      : `if (!stream.${op}(${varName})) return false;\n`, options?.marker])
  }

  pushStreamWriteOrBail (op, varName, arg, options) {
    this.ops.push(['write', arg
      ? `if (!stream.${op}(${varName}, ${arg})) return false;\n`
      : `if (!stream.${op}(${varName})) return false;\n`, options?.marker])
  }

  // Assignments
  pushTempVariable (name, type, options) {
    type = this.resolveType(type)
    this.ops.push(['tempVar', `${type} ${name};\n`, options?.marker, options])
  }

  pushAssignment (varName, value, type, options) {
    type = this.resolveType(type)
    this.ops.push(['assignment', `${type} ${varName} = ${value};\n`, options?.marker])
  }

  pushPropAssignment (varName, prop, value, options) {
    this.ops.push(['assignment', `${varName}.${prop} = ${value};\n`, options?.marker])
  }

  pushPropORAssignment (varName, prop, value, options) {
    this.ops.push(['assignment', `${varName}.${prop} |= ${value};\n`, options?.marker])
  }

  pushORAssignment (varName, value, options) {
    this.ops.push(['assignment', `${varName} |= ${value};\n`, options?.marker])
  }

  // Conditions
  pushPropIfBooleanStatement (varName, prop, options) {
    this.ops.push(['if', `if (${varName}.${prop}) {\n`, options?.marker])
    this.ops.push(['indentInc'])
  }

  pushEndIf (options) {
    // Try and inline the `if` if it's only one statement (just for compactness/no diff between old impl)
    const i = this.ops.length - 3
    if (this.ops[i][0] === 'if') {
      // remove ending \n and opening curly brace
      this.ops[i][1] = this.ops[i][1].slice(0, -2)
      this.ops[i][3] = { shouldResetCursor: false }
      this.ops[i + 1] = ['noop']
      this.ops[i + 2][3] = { padWith: ' ' }
    } else {
      this.ops.push(['indentDec'])
      this.ops.push(['endif', '}\n', options?.marker])
    }
  }

  // Reads
  pushRead (type, intoVar, options) {
    type = this.decoderMap[type] || type
    this.ops.push(['read', `READ_OR_BAIL(${type}, ${intoVar});`, options?.marker, options])
  }

  pushWrite (type, fromVar, options) {
    const encoder = this.encoderMap[type] || type
    const primitive = this.primitivesMap[this.encoder2Primitive[encoder]]
    fromVar = this.joinVarNameIfNeeded(fromVar)
    const maybeCast = primitive ? `(${primitive})` : ''
    this.ops.push(['write', `WRITE_OR_BAIL(${encoder}, ${maybeCast}${fromVar});`, options?.marker, options])
  }

  pushSizeIncrementConst (typeOrSize, options) {
    const size = this.sizerMap[typeOrSize] || typeOrSize
    if (typeof size !== 'number') throw Error(`size must be a number, got ${size}`)
    this.ops.push(['size', `len += ${size};\n`, options?.marker])
  }

  pushSizeIncrementByVar (varName, options) {
    this.ops.push(['size', `len += ${varName};\n`, options?.marker])
  }

  // When writing std::string, you need to prefix it with its length, which will depend
  // on the type of length prefix you're using.
  pushSizeIncrementByLengthOfString (prefixType, varName, options) {
    const name = this.joinVarNameIfNeeded(varName) + '.length()'
    const decodeFn = this.sizerMap[prefixType]
    const s = typeof decodeFn === 'number'
      ? `len += ${decodeFn};`
      : `len += stream.${decodeFn}(${name});`
    this.ops.push(['size', `${s}\nlen += ${name};`, options?.marker])
  }

  // A 'buffer' is a std::vector<uint8_t> in C++. Only difference is need to call .size()
  pushSizeIncrementByLengthOfBuffer (prefixType, varName, options) {
    const name = this.joinVarNameIfNeeded(varName) + '.size()'
    const decodeFn = this.sizerMap[prefixType]
    const s = typeof decodeFn === 'number'
      ? `len += ${decodeFn};`
      : `len += stream.${decodeFn}(${name});`
    this.ops.push(['size', `${s}\nlen += ${name};`, options?.marker])
  }

  pushSizeIncrementByType (type, varName, options) {
    const name = this.joinVarNameIfNeeded(varName)
    const decodeFn = this.sizerMap[type]
    const s = typeof decodeFn === 'number'
      ? `len += ${decodeFn};`
      : `len += stream.${decodeFn}(${name});`
    this.ops.push(['size', `${s}\n`, options?.marker])
  }

  pushJsonString (key, refName, options) {
    if (!key && !options.anonymous) throw Error('options.anonymous must be true if key is not provided')
    const op = key ? `PDEF_JSON_putString_OR_BAIL(${key}, ${refName})` : `PDEF_JSON_putStringAnon_OR_BAIL(${refName})`
    this.ops.push(['json', op, options?.marker])
  }

  pushRaw (str, options) {
    this.ops.push(['raw', str, options?.marker])
  }

  encode (currentPaddingLevel) {
    let str = ''
    // This `forElevation` is just a special case where we have to write some data outside of the normal sequence
    let forElevation = ''
    let indent = currentPaddingLevel ? (currentPaddingLevel * 2) : this.initialPadding
    function pad (str) {
      const lines = str.split('\n')
      return lines.map(l => ' '.repeat(indent) + l).join('\n')
    }
    for (const [op, ...args] of this.ops) {
      if (op === 'indentInc') {
        indent += 2
      } else if (op === 'indentDec') {
        indent -= 2
      } else if (op === 'primitiveStruct') {
        const [topLevel, embeddedStr, marker] = args
        const markerStr = marker ? ` /*${marker}*/` : ''
        forElevation += pad(topLevel + markerStr) + '\n'
        str += pad(embeddedStr.trimEnd() + markerStr) + '\n'
      } else if (op !== 'noop') {
        const [s, marker, options] = args
        const newLine = (options?.shouldResetCursor === false) ? '' : '\n'
        const markerStr = marker ? ` /*${marker}*/` : ''
        if (options?.padWith) {
          str += options.padWith + s.trimEnd() + markerStr + newLine
        } else {
          str += pad(s.trimEnd() + markerStr) + newLine
        }
      }
    }
    return [str.trim(), forElevation.trim()]
  }
}

// I worry this is too much abstraction... maybe writing out the code is better
// than trying to abstract it away. We could reduce the need for this custom codegen
// by adding more built-in types to protodef-cpp.

if (!module.parent) {
  const cpp = new CppOpsGroup()
  cpp.pushType('position_t')
  cpp.pushPrimitiveStruct('position_t', [
    { type: 'int32_t', varName: 'x', defaultValue: '0' },
    { type: 'int32_t', varName: 'y', defaultValue: '0' },
    { type: 'int32_t', varName: 'z', defaultValue: '0' }
  ])
  console.log(...cpp.encode())
}

module.exports = { CppOpsGroup }
