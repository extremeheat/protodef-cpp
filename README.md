# protodef-cpp
[![NPM version](https://img.shields.io/npm/v/protodef-cpp.svg?logo=npm)](http://npmjs.com/package/protodef-cpp)
[![Build Status](https://img.shields.io/github/actions/workflow/status/extremeheat/protodef-cpp/ci.yml.svg?label=CI&logo=github)](https://github.com/extremeheat/protodef-cpp/actions?query=workflow%3A%22CI%22)
[![Try it on gitpod](https://img.shields.io/static/v1.svg?label=try&message=on%20gitpod&color=brightgreen&logo=gitpod)](https://gitpod.io/#https://github.com/extremeheat/protodef-cpp)
[![Official Discord](https://img.shields.io/static/v1.svg?label=PrismarineJS&message=Discord&color=blue&logo=discord)](https://discord.gg/GsEFRM8)

C++ compiler in Node.js for ProtoDef schemas, a lighter and more versatile alternative to Protocol Buffers or FlatBuffers that can support any binary format.

See the ProtoDef specification at https://github.com/ProtoDef-io/ProtoDef.

### Features
* Header-only : No dependencies other than the C or C++ standard libraries
* Arrays, enums, nested structures, optional fields, variable-length integers/strings, custom types, etc. See ProtoDef spec for more details
* Built-in support for dumping JSON for utility/debugging on top of binary encode/decode

## Install
```cmd
npm install protodef-cpp
```

## Usage

### via npx / command line 

Feed the CLI tool a .json or .yaml file, and optionally specify a directory to write the generated files to.
Two header files will be written: a "streams.h", containing a binary stream implementation used by the encoder/decoder (if you don't already have one), 
and a "protocol.h" header file (name will vary depending on your input name), containing the generated encoder/decoder code.

```go
$ npx protodef-cpp --help
protodef-cpp - v1.0.0
protodef-cpp - A C++ compiler for ProtoDef schemas

Options:
  --input, -i   Path to ProtoDef JSON/YAML file with protocol data
  --lang, -l    What language use compile to. Currently only C++.  (default: cpp)
  --output      Output folder  (default: ./)
  --config, -t  Path to JS file whose exports will be merged into the current options, which allows you to define custom types and variables.
  --namespace   What namespace to use, useful if you have multiple protocols.  (default: proto)
```

If you have multiple protocols specified inside one JSON file, please use the programmatic API instead ([example](https://github.com/extremeheat/protodef-cpp/blob/master/examples/mcpc-protocol/main.js)).

### via code / programmatic API

```js
const protodefCpp = require('protodef-cpp')
protodefCpp.compile({
  inputFile: 'protocol.json',
  outputFolder: './',
  lang: 'cpp',
  namespace: 'proto',
})
```

### Example

protocol.yml:

```yaml
string: ["pstring", { countType: "varint" }]
packet_video_stream_connect:
  server_uri: string
  frame_send_frequency: lf32
  action: u8 =>
     1: none
     2: close
  resolution_x: li32
  resolution_y: li32
```

<!-- <details>
<summary>Custom Types implementation in JavaScript</summary>
Inside types.js:

```js
module.exports = {
 pstring: {
    struct (args, name, makeCallingCode) {
      return makeCallingCode('std::string', name)
    },
    read (args, [name, refName], makeCallingCode) {
      if (args.count) return `if (!stream.readString(${refName}, ${args.count})) return false;`
      const primitiveType = protodefTypeToCpp[args.countType]
      return `
        ${primitiveType} ${name}_strlen; ${makeCallingCode(args.countType, `${name}_strlen`)};
        if (!stream.readString(${refName}, ${name}_strlen)) return false;
      `.trim()
    },
    write (args, [name, refName], makeCallingCode) {
      if (args.count) return `WRITE_OR_BAIL(writeString, ${refName});`
      return `
        ${makeCallingCode(args.countType, [refName, 'length()'])};
        WRITE_OR_BAIL(writeString, ${refName});
      `.trim()
    },
    size (args, [name, refName], makeCallingCode) {
      if (args.count) return `len += ${args.count};`
      return `
        ${makeCallingCode(args.countType, [refName, 'length()'])};
        len += ${refName}.length();
      `.trim()
    }
  }
}
```
</details> -->

Command line:
```cmd
npx protodef-cpp -i protocol.yml --lang cpp
```

Done! You should now have a "protocol.h" file in your current directory. Here's how you would encode a structure:

```cpp
#include "protocol.h"

int main () {
  pdef::proto::packet_video_stream_connect packet {
    .server_uri = "wss://example.com",
    .frame_send_frequency = 60.0f,
    .action = pdef::proto::packet_video_stream_connect::Action::None,
    .resolution_x = 1920,
    .resolution_y = 1080,
  };
  pdef::Stream stream(0);
  pdef::proto::encode::packet_video_stream_connect(stream, packet);
  stream.dumpToStdout();
  return 0;
}
```

See [examples/](https://github.com/extremeheat/protodef-cpp/tree/master/examples) for more examples.