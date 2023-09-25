/* eslint-disable camelcase */
const protodefCpp = require('protodef-cpp')

const pc1_18 = require('./pc1_18.json')
const schema = { ...pc1_18.types, ...pc1_18.play.toClient.types }

protodefCpp.compile({
  inputJSON: schema,
  outputFolder: './build/',
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
