#!/usr/bin/env node
const index = require('./index.js')
const path = require('path')
// const fs = require('fs')
const protodefYaml = require('protodef-yaml')
const args = require('basic-args')({
  name: 'protodef-cpp',
  version: require('../package.json').version,
  description: 'protodef-cpp - A C++ compiler for ProtoDef schemas',
  errorOnUnknown: true,
  options: {
    input: { type: String, description: 'Path to ProtoDef JSON/YAML file with protocol data', alias: 'i' },
    lang: { type: String, description: 'What language use compile to. Currently only C++.', default: 'cpp', alias: 'l' },
    output: { type: String, description: 'Output folder', default: './' },
    config: { type: String, description: 'Path to JS file whose exports will be merged into the current options, which allows you to define custom types and variables.', default: null, alias: 't' },
    namespace: { type: String, description: 'What namespace to use, useful if you have multiple protocols', default: 'proto' }
  }
})

const options = {
  inputFile: args.input,
  outputFolder: args.output,
  lang: args.lang,
  namespace: args.namespace
}

if (args.input.endsWith('.yml') || args.input.endsWith('.yaml')) {
  // const input = fs.readFileSync(args.input, 'utf8')
  const json = protodefYaml.compile(args.input)
  options.inputJSON = json
}
if (args.config) {
  const absPath = path.resolve(args.config)
  console.log(`Loading custom types and config from ${absPath}`)
  Object.assign(options, require(absPath))
}

index.compile(options)
