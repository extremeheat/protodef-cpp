/* eslint-disable camelcase */
// This example demonstrates some more advanced usage with namespacing
// and custom types aliases
const protodefCpp = require('protodef-cpp')

const baseSchema = require('./pc1_18.json')

for (const mode in baseSchema) {
  if (mode === 'types') continue
  for (const direction in baseSchema[mode]) {
    const schema = { ...baseSchema.types, ...baseSchema[mode][direction].types }
    const namespace = `pc1_18_${mode}_${direction}`
    protodefCpp.compile({
      inputJSON: schema,
      outputFolder: './build/',
      namespace,
      // Some stubs as this is only a proof of concept
      typeAliases: [
        ['nbt', 'i8'],
        ['varlong', 'varint'],
        ['nbtLoop', 'i8'],
        ['UUID', 'u64'],
        ['slot', 'i8'],
        ['restBuffer', 'i8'],
        ['optionalNbt', 'i8'],
        ['entityMetadataLoop', 'i8'],
        ['topBitSetTerminatedArray', 'i8']
      ]
    })
  }
}
