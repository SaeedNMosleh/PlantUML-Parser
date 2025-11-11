// Minimal test grammar
module.exports = grammar({
  name: 'plantuml',

  externals: $ => [],

  rules: {
    source_file: $ => seq(
      '@startuml',
      '@enduml'
    )
  }
});
