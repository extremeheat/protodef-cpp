if (typeof process !== 'undefined' && parseInt(process.versions.node.split('.')[0]) < 18) {
  console.error('Your node version is currently', process.versions.node)
  console.error('Please update it to a version >= 18.x.x from https://nodejs.org/')
  process.exit(1)
}
const fs = require('fs')
const { join } = require('path')
const ir = require('./ir')
const compileCpp = require('./compile-cpp')

function compile ({ lang, inputJSON, inputFile, outputFolder, typeAliases, customTypes, variables, namespace, outputProtocolFileName }) {
  if (!inputJSON) {
    inputJSON = fs.readFileSync(inputFile, 'utf8')
  }
  const generatedIR = ir.generate(typeof inputJSON === 'string'
    ? JSON.parse(inputJSON)
    : inputJSON)

  if (typeAliases) {
    for (const [a, b] of typeAliases) {
      compileCpp.addAliasType(a, b)
    }
  }

  const compiledCppCode = compileCpp.compile(generatedIR, customTypes, variables, namespace)
  const inputFileName = inputFile?.split('/').pop()?.split('.')?.[0] ?? outputProtocolFileName ?? namespace ?? 'protocol'
  const parsedOutputFolder = outputFolder || './'
  const outputFilename = parsedOutputFolder + `${inputFileName}.h`
  fs.writeFileSync(outputFilename, compiledCppCode.lines)
  // Copy over stream.h into the output dir, if it's not already there
  fs.copyFileSync(join(__dirname, '/stream.h'), parsedOutputFolder + 'stream.h')
}

module.exports = { compile }
