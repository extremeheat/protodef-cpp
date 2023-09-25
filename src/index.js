const fs = require('fs')
const { join } = require('path')
const ir = require('./ir')
const compileCpp = require('./compile-cpp')

function compile ({ inputJSON, inputFile, outputFolder, typeAliases }) {
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

  const compiledCppCode = compileCpp.compile(generatedIR)
  const inputFileName = inputFile?.split('/').pop()?.split('.')?.[0] ?? 'protocol'
  const parsedOutputFolder = outputFolder || './'
  const outputFilename = parsedOutputFolder + `${inputFileName}.h`
  fs.writeFileSync(outputFilename, compiledCppCode.lines)
  // Copy over stream.h into the output dir, if it's not already there
  fs.copyFileSync(join(__dirname, '/stream.h'), parsedOutputFolder + 'stream.h')
}

module.exports = { compile }
