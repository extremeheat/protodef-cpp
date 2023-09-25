#!/usr/bin/env node
const index = require('./index.js')
const fs = require('fs')
const protodefYaml = require('protodef-yaml')
const args = require('basic-args')({
  name: 'protodef-cpp',
  version: '1.0.0',
  description: 'protodef-cpp - A C++ compiler for ProtoDef schemas',
  errorOnUnknown: true,
  options: {
    input: { type: String, description: 'Path to ProtoDef JSON/YAML file with protocol data', alias: 'i' },
    lang: { type: String, description: 'What language use compile to. Currently only C++.', default: 'cpp' },
    output: { type: String, description: 'Output folder', default: './' },
    customTypes: { type: String, description: 'Path to custom types file', default: null },
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
if (args.customTypes) {
  const jsCode = fs.readFileSync(args.customTypes, 'utf8')
  options.customTypes = eval(jsCode) // eslint-disable-line no-eval
}

index.compile(options)
