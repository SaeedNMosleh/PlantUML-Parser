const Parser = require('tree-sitter');

// Test 1: Load binding directly
console.log('Test 1: Loading binding directly...');
let binding;
try {
  binding = require('./build/Release/tree_sitter_plantuml_binding.node');
  console.log('✓ Binding loaded:', Object.keys(binding));
  console.log('  Language type:', typeof binding.language);
  console.log('  Language:', binding.language);
} catch (e) {
  console.log('✗ Failed to load binding:', e.message);
  process.exit(1);
}

// Test 2: Try setting language
console.log('\nTest 2: Setting language in parser...');
const parser = new Parser();
try {
  parser.setLanguage(binding.language);
  console.log('✓ Language set successfully');
} catch (e) {
  console.log('✗ Failed to set language:', e.message);
  console.log('  Error stack:', e.stack);

  // Try to understand what's wrong
  console.log('\nDebug info:');
  console.log('  binding.language constructor:', binding.language?.constructor?.name);
  console.log('  Is External?', binding.language?.toString?.().includes('External'));

  // Check if we can call the language function
  if (typeof binding.language === 'function') {
    console.log('  Language is a function, trying to call it...');
    try {
      const result = binding.language();
      console.log('  Function result:', result);
    } catch (e2) {
      console.log('  Function call failed:', e2.message);
    }
  }
}

// Test 3: Try parsing if language was set
const testInput = '@startuml\n:Test;\n@enduml';
if (parser.getLanguage()) {
  console.log('\nTest 3: Parsing test input...');
  try {
    const tree = parser.parse(testInput);
    console.log('✓ Parse successful');
    console.log('  Root type:', tree.rootNode.type);
    console.log('  Has errors:', tree.rootNode.hasError);
  } catch (e) {
    console.log('✗ Parse failed:', e.message);
  }
} else {
  console.log('\nTest 3: Skipped (no language set)');
}