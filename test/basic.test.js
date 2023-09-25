/* eslint-env mocha */
const { join } = require('path')
const cp = require('child_process')

describe('basic', () => {
  it('test', () => {
    const newWd = join(__dirname, '../examples/mcpe-protocol/')
    process.chdir(newWd)
    require('../examples/mcpe-protocol/main.js')
    console.log('WD', newWd)
    cp.execSync('clang++ structs.cpp -std=c++20 -ferror-limit=9999 -o structs.exe', {
      cwd: newWd
    })
  }).timeout(10000)
})
