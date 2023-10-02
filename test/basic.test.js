/* eslint-env mocha */
const { join } = require('path')
const cp = require('child_process')
const fs = require('fs')

describe('c++ compile tests', () => {
  it('minecraft bedrock protocol', () => {
    const newWd = join(__dirname, '../examples/mcpe-protocol/')
    process.chdir(newWd)
    require('../examples/mcpe-protocol/main.js')
    console.log('WD', newWd)
    cp.execSync('clang++ structs.cpp -std=c++20 -ferror-limit=9999 -o structs.exe', {
      cwd: newWd
    })
  }).timeout(30000)

  it('minecraft nbt decode', () => {
    const newWd = join(__dirname, '../examples/minecraft-nbt/')
    process.chdir(newWd)
    require('../examples/minecraft-nbt/main.js')
    console.log('WD', newWd)
    cp.execSync('clang++ app.cpp -std=c++20 -ferror-limit=9999 -o app.exe', {
      cwd: newWd
    })
  }).timeout(30000)

  it('minecraft java protocol', () => {
    const newWd = join(__dirname, '../examples/mcpc-protocol/')
    process.chdir(newWd)
    require('../examples/mcpc-protocol/main.js')
    console.log('WD', newWd)
    for (const file of fs.readdirSync('./build')) {
      if (!file.endsWith('.h')) continue
      const cmd = `clang++ ./build/${file} -std=c++20 -ferror-limit=9999`
      console.log('>', cmd)
      cp.execSync(cmd, {
        cwd: newWd,
        stdio: 'inherit'
      })
    }
  }).timeout(30000)
})
