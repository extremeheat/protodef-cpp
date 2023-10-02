## minecraft-nbt

This example dumps Minecraft NBT (a custom binary format) data to JSON.

### Setup

Running the `./download.cmd` script will download the ProtoDef schema for Minecraft NBT from prismarine-nbt (`nbt.json`) as well as the latest .NBT file (`bigtest.nbt`) used to test prismarine-nbt. This is preran and already committed to the repo, so this step can be skipped if there's no upstream changes.

### Usage

* First, we can compile the NBT to C++ headers with Node.js

```
node main.js
```

Which will generate the header files in build/. Inside `main.js` is a custom defined type, compound, that reads data in a loop until a null-terminator (0x00, "NBT_End") is read.

* Inside `app.cpp` is an example program to use the compiled protocol code

We can compile it with Clang like such:

```sh
clang++ app.cpp -std=c++20 -ferror-limit=9999 -o app.exe
```

Then run `./app.exe` which should print JSON to the terminal/standard output.

It should look like:
```json
{
  "type": 10,
  "name": "Level",
  "value_compound": [
    {
      "type": 4,
      "name": "longTest",
      "value_i64": 9223372036854775807
    },
    {
      "type": 2,
      "name": "shortTest",
      "value_i16": 32767
    },
    {
      "type": 8,
      "name": "stringTest",
      "value_shortString": "HELLO WORLD THIS IS A TEST STRING ├à├ä├û!"
    },
    {
      "type": 5,
      "name": "floatTest",
      "value_f32": 0.4982
    },
    {
      "type": 3,
      "name": "intTest",
      "value_i32": 2147483647
    },
    {
      "type": 10,
      "name": "nested compound test",
      "value_compound": [
        {
          "type": 10,
          "name": "ham",
          "value_compound": [
            {
              "type": 8,
              "name": "name",
              "value_shortString": "Hampus"
            },
            {
              "type": 5,
              "name": "value",
              "value_f32": 0.75
            }
          ]
        },
        {
          "type": 10,
          "name": "egg",
          "value_compound": [
            {
              "type": 8,
              "name": "name",
              "value_shortString": "Eggbert"
            },
            {
              "type": 5,
              "name": "value",
              "value_f32": 0.5
            }
          ]
        }
      ]
    },
    {
      "type": 9,
      "name": "listTest (long)",
      "value_list": {
        "type": 4,
        "value_i64_array": [
          11,
          12,
          13,
          14,
          15
        ]
      }
    },
    {
      "type": 9,
      "name": "listTest (compound)",
      "value_list": {
        "type": 10,
        "value_compound_array": [
          [
            {
              "type": 8,
              "name": "name",
              "value_shortString": "Compound tag #0"
            },
            {
              "type": 4,
              "name": "created-on",
              "value_i64": 1264099775885
            }
          ],
          [
            {
              "type": 8,
              "name": "name",
              "value_shortString": "Compound tag #1"
            },
            {
              "type": 4,
              "name": "created-on",
              "value_i64": 1264099775885
            }
          ]
        ]
      }
    },
    {
      "type": 1,
      "name": "byteTest",
      "value_i8": 127
    },
    {
      "type": 7,
      "name": "byteArrayTest (the first 1000 values of (n*n*255+n*7)%100, starting with n=0 (0, 62, 34, 16, 8, ...))",
      "value_byteArray": [
        0, (... shrunk for brevity ...),
        48
      ]
    },
    {
      "type": 6,
      "name": "doubleTest",
      "value_f64": 0.4931
    }
  ]
}
```