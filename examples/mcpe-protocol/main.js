const protodefCpp = require('protodef-cpp')

protodefCpp.compile({
  inputJSON: require('./protocol.json').types,
  outputFolder: './',
  // Some stubs as this is only a proof of concept
  typeAliases: [
    ['nbt', 'i8'],
    ['lnbt', 'i8'],
    ['nbtLoop', 'i8'],
    ['uuid', 'u64'],
    ['encapsulated', 'i8'],
    ['slot', 'i8'],
    ['byterot', 'i8'],
    ['restBuffer', 'i8']
  ]
})
