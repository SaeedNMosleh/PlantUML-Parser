// Simplified test to check if basic parsing works
const Parser = require('tree-sitter');
const path = require('path');

// Load the binding
const bindingPath = path.join(__dirname, 'build', 'Release', 'tree_sitter_plantuml_binding.node');
const binding = require(bindingPath);

console.log('Binding loaded:', binding);
console.log('Language object:', binding.language);

// Try to create a parser and set the language
const parser = new Parser();

try {
  parser.setLanguage(binding.language);
  console.log('Language set successfully!');

  // Try a simple parse without preprocessing
  const sourceCode = `@startuml
:Hello World;
@enduml`;

  console.log('\nParsing simple PlantUML:');
  console.log(sourceCode);

  const tree = parser.parse(sourceCode);
  console.log('\nParse tree:', tree.rootNode.toString());
  console.log('Has errors:', tree.rootNode.hasError());

} catch (error) {
  console.error('Error:', error.message);
  console.error('Stack:', error.stack);
}