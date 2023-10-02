const protodefCpp = require('protodef-cpp')

protodefCpp.compile({
  inputJSON: require('./nbt.json'),
  outputFolder: './build/',
  // Some stubs as this is only a proof of concept
  typeAliases: [
    ['nbtTagName', 'shortString']
  ],
  variables: {},
  customTypes: {
    compound: {
      type () {
        return 'std::vector<pdef::proto::nbt>'
      },
      struct (args, name, makeCallingCode, inline) {
        if (inline) return this.type()
        return `std::vector<pdef::proto::nbt> ${name};`
      },
      read (args, [name, refName], makeCallingCode) {
        return `
while (stream.peekByte() != -1) {
  if (stream.peekByte() == 0) {
    stream.readIndex++;
    break;
  }
  pdef::proto::nbt ${name}_item;
  pdef::proto::decode::nbt(stream, ${name}_item);
  ${refName}.push_back(std::move(${name}_item));
}
        `
      },
      write (args, [name, refName], makeCallingCode) {
        return `
for (auto& ${name}_item : ${refName}) {
  pdef::proto::encode::nbt(stream, ${name}_item, false);
}
stream.writeByte(0);
`
      },
      size (args, [name, refName], makeCallingCode) {
        return `
size_t ${name}_size = 0;
for (auto& ${name}_item : ${refName}) {
  ${name}_size += pdef::proto::size::nbt(stream, ${name}_item);
}
${name}_size += 1; // 0 tag
len += ${name}_size;
`
      },
      json (args, [name, refName], makeCallingCode) {
        const s = name ? `PDEF_JSON_putStartArr_OR_BAIL(${name});` : 'PDEF_JSON_putToken_OR_BAIL("[");'
        return s + `
for (auto& ${name}_item : ${refName}) {
  pdef::proto::toJSON::nbt(stream, ${name}_item); PDEF_JSON_putToken_OR_BAIL(",");
}
PDEF_JSON_putEndArr_OR_BAIL;
`
      }
    }
  }
})
