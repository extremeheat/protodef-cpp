const protodefCpp = require('protodef-cpp')

const schema = require('./protocol.json').types
// move mcpe_packet to the end
const oldmcpePacket = schema.mcpe_packet
delete schema.mcpe_packet
schema.mcpe_packet = oldmcpePacket

protodefCpp.compile({
  inputJSON: schema,
  outputFolder: './build/',
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
  ],
  variables: {
    ShieldItemID: ['u32', 0]
  },
  customTypes: {
    enum_size_based_on_values_len: {
      type () {
        return ''
      },
      struct (args, name, makeCallingCode) {
        const s = `enum class _EnumType { Byte, Short, Int }; _EnumType ${name};`
        return s
      },
      read (args, [name], makeCallingCode) {
        return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
      },
      write (args, [name], makeCallingCode) {
        return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
      },
      size (args, [name], makeCallingCode) {
        return `pdef::proto::packet_available_commands::_EnumType ${name}; if (values_len <= 0xff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Byte; } else if (values_len <= 0xffff) { ${name} = pdef::proto::packet_available_commands::_EnumType::Short; } else { ${name} = pdef::proto::packet_available_commands::_EnumType::Int; }`
      }
    }
  }
})
