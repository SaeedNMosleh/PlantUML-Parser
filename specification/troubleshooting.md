# Troubleshooting Guide

Common issues and solutions for the PlantUML Parser.

## Build Issues

### Issue: node-gyp rebuild fails

**Symptoms:**
```
Error: Cannot find module 'node-gyp'
gyp ERR! build error
```

**Solution:**
```bash
# Install node-gyp globally
npm install -g node-gyp

# Ensure build tools are installed
# On Windows:
npm install --global windows-build-tools

# On macOS:
xcode-select --install

# On Linux:
sudo apt-get install build-essential

# Rebuild
npm run clean
npm run rebuild
```

---

### Issue: tree-sitter generate fails

**Symptoms:**
```
Error: tree-sitter is not recognized as an internal or external command
```

**Solution:**
```bash
# The repo uses the tree-sitter CLI for `generate`, `parse`, WASM builds, and corpus tests.
# It is an optional dependency so installs can succeed even if the binary download fails.

# Option A (recommended): use the repo-local install
npm install

# Verify installation
tree-sitter --version

# If `tree-sitter` is still not found, install globally
npm install -g tree-sitter-cli

# Generate parser
npm run generate
```

**If install fails with network/proxy errors (e.g. ECONNRESET):**
- Configure `HTTP_PROXY` / `HTTPS_PROXY` for Node/npm (common in corporate networks), then retry `npm install`.
- For JS-only work (like the normalizer), you can bypass install scripts:
  - `npm ci --ignore-scripts`
  - `npm run build:js`
  - `npm run test:normalizer`

---

### Issue: Missing src/parser.c

**Symptoms:**
```
Error: Cannot find src/parser.c
```

**Solution:**
```bash
# Generate parser first
npm run generate

# This creates:
# - src/parser.c
# - src/grammar.json
# - src/node-types.json

# Then build
npm run build:all
```

---

### Issue: Build succeeds but module not found

**Symptoms:**
```javascript
const PlantUMLParser = require('tree-sitter-plantuml');
// Error: Cannot find module 'tree-sitter-plantuml'
```

**Solution:**
```bash
# Ensure you're in the correct directory
cd path/to/PlantUML-Parser

# Verify build artifacts exist
ls build/Release/tree_sitter_plantuml_binding.node

# If missing, rebuild
npm run rebuild

# Test with relative require
const PlantUMLParser = require('./index');
```

---

## Test Failures

### Issue: Integration tests fail with "Invalid language object"

**Symptoms:**
```
TypeError: Invalid language object
    at Parser.setLanguage
```

**Solution:**
```bash
# Ensure native build + dist exist and run integration tests
npm run test:integration
```

---

### Issue: Corpus tests fail

**Symptoms:**
```
Test failed: Expected (activity_node) but got (ERROR)
```

**Solution:**
```bash
# 1. Check if syntax is valid PlantUML
npm run validate

# 2. If validation fails (HTTP 400), syntax is invalid
# Remove or fix the test

# 3. If validation succeeds but test fails:
# Check normalizer - it should produce clean input

# Debug normalizer output:
node -e "
const N = require('./dist/normalizer.cjs');
const n = new N();
console.log(n.normalize(\`YOUR TEST INPUT\`));
"

# 4. Regenerate grammar
npm run generate

# 5. Re-run tests
npm test
```

---

### Issue: PlantUML validation fails

**Symptoms:**
```
PlantUML server rejected syntax (HTTP 400)
```

**Solution:**
```bash
# 1. Verify PlantUML server is running
npm run docker:up

# Test manually
curl http://localhost:8080

# 2. Check syntax against official PlantUML docs
# https://plantuml.com

# 3. If syntax is invalid, update test or remove it

# 4. If syntax is valid, check server connection
docker ps    # Verify container running
docker logs plantuml-validator
```

---

### Issue: Normalizer tests fail

**Symptoms:**
```
Expected normalized output doesn't match actual
```

**Solution:**
```bash
# 1. Check normalizer rules
cat src/normalizer/rules/arrows.ts

# 2. Debug specific normalization
node -e "
const PlantUMLNormalizer = require('./dist/normalizer.cjs');
const normalizer = new PlantUMLNormalizer({ debug: true });
const result = normalizer.normalize(\`YOUR INPUT\`);
console.log('Normalized:', result.normalized);
console.log('Metadata:', result.metadata);
"

# 3. Fix normalizer rule or update test expectation

# 4. Re-run tests
npm run test:normalizer
```

---

## Grammar Issues

### Issue: Grammar conflicts detected

**Symptoms:**
```
Unresolved conflict for symbol sequence:
  'if'  •  '('  …
```

**Solution:**
```javascript
// The two-pass architecture should prevent conflicts
// If you see conflicts, the normalizer isn't doing its job

// 1. Check if input is normalized
const { normalized } = normalizer.normalize(input);

// 2. Grammar should parse normalized input cleanly
// Add normalization rule to handle ambiguity

// 3. Regenerate grammar
npm run generate

// 4. Verify zero conflicts
tree-sitter generate
// Should output: "Generating grammar... Done"
// No conflict warnings
```

**Note**: Current grammar has **zero conflicts** because normalizer handles all ambiguities.

---

### Issue: Unexpected ERROR nodes in AST

**Symptoms:**
```javascript
const { tree } = parser.parse(source);
console.log(tree.rootNode.hasError);  // true
```

**Solution:**
```bash
# 1. Find ERROR nodes
node -e "
const PlantUMLParser = require('tree-sitter-plantuml');
const parser = new PlantUMLParser();
const { tree } = parser.parse(\`YOUR INPUT\`);

function findErrors(node, depth = 0) {
  const indent = '  '.repeat(depth);
  if (node.type === 'ERROR') {
    console.log(\`\${indent}ERROR at \${node.startPosition.row}:\${node.startPosition.column}\`);
    console.log(\`\${indent}Text: \${node.text}\`);
  }
  for (let child of node.children) {
    findErrors(child, depth + 1);
  }
}

findErrors(tree.rootNode);
"

# 2. Check if input is normalized
const { normalized } = parser.normalize(input);
console.log(normalized);

# 3. Fix syntax or update normalizer to handle it
```

---

## Performance Issues

### Issue: Parsing is very slow

**Symptoms:**
```
Integration tests take >100 seconds
```

**Solution:**
```bash
# Prefer the focused test suites when iterating:
npm run test:normalizer     # Fast feedback on normalization
npm run test:parser         # Grammar corpus tests
npm run test:integration    # End-to-end pipeline
```

---

### Issue: Memory usage too high

**Symptoms:**
```
JavaScript heap out of memory
```

**Solution:**
```bash
# Increase Node.js memory limit
export NODE_OPTIONS="--max-old-space-size=4096"

# Or run with flag
node --max-old-space-size=4096 your-script.js

# Check for memory leaks:
node --inspect your-script.js
# Use Chrome DevTools to profile memory
```

---

### Issue: Incremental parsing not working

**Symptoms:**
```javascript
// Edits don't seem to use incremental parsing
const tree2 = parser.parse(newSource, { oldTree: tree1 });
// Still slow
```

**Solution:**
```javascript
// Ensure you're passing oldTree correctly
const PlantUMLParser = require('tree-sitter-plantuml');
const parser = new PlantUMLParser();

// Initial parse
const source1 = `@startuml\n:Process;\n@enduml`;
const { tree: tree1 } = parser.parse(source1);

// Modified source
const source2 = `@startuml\n:Modified Process;\n@enduml`;

// Incremental parse
const { tree: tree2 } = parser.parse(source2, { oldTree: tree1 });

// Verify incremental parsing occurred
// (Check performance - should be faster)
```

---

## Runtime Errors

### Issue: "Cannot read property 'type' of null"

**Symptoms:**
```javascript
const label = node.childForFieldName('label');
console.log(label.type);  // TypeError: Cannot read property 'type' of null
```

**Solution:**
```javascript
// Always check if child exists before accessing
const label = node.childForFieldName('label');
if (label) {
  console.log(label.type);
} else {
  console.log('No label field');
}

// Or use optional chaining
console.log(label?.type);
```

---

### Issue: Normalizer throws error on valid input

**Symptoms:**
```javascript
const { normalized } = normalizer.normalize(input);
// Throws: Unexpected token
```

**Solution:**
```bash
# 1. Check if input has special characters
node -e "
const input = \`YOUR INPUT\`;
console.log('Input length:', input.length);
console.log('Input bytes:', Buffer.from(input));
"

# 2. Ensure UTF-8 encoding
const fs = require('fs');
const input = fs.readFileSync('file.puml', 'utf-8');

# 3. Check normalizer debug output
const normalizer = new PlantUMLNormalizer({ debug: true });
const result = normalizer.normalize(input);
```

---

## Docker Issues

### Issue: PlantUML server not starting

**Symptoms:**
```bash
npm run docker:up
# Error: Cannot connect to Docker daemon
```

**Solution:**
```bash
# On Windows with WSL:
# 1. Start Docker Desktop

# 2. Verify Docker is running
docker ps

# 3. Start PlantUML container
npm run docker:up

# 4. Verify container is running
docker ps | grep plantuml

# 5. Test connection
curl http://localhost:8080

# If port conflict:
# Edit docker-compose.yml to use different port
ports:
  - "8081:8080"
```

---

### Issue: PlantUML validation timing out

**Symptoms:**
```
Request timeout after 30 seconds
```

**Solution:**
```bash
# 1. Check PlantUML server logs
docker logs plantuml-validator

# 2. Restart container
npm run docker:down
npm run docker:up

# 3. Verify server is responding
curl -X POST http://localhost:8080/svg/ \
  -d '@startuml\n:Test;\n@enduml'

# Should return SVG
```

---

## Windows-Specific Issues

### Issue: npm scripts fail on Windows

**Symptoms:**
```
'rm' is not recognized as an internal or external command
```

**Solution:**
```bash
# Use WSL (recommended)
wsl
npm run clean

# Or use cross-platform commands
# Edit package.json:
{
  "scripts": {
    "clean": "rimraf build coverage"
  }
}

# Install rimraf
npm install --save-dev rimraf
```

---

### Issue: Path separators cause issues

**Symptoms:**
```
Error: Cannot find module 'd:\path\to\module'
```

**Solution:**
```javascript
// Use path.join for cross-platform paths
const path = require('path');
const modulePath = path.join(__dirname, 'src', 'normalizer');

// Or use forward slashes (work on Windows too)
const PlantUMLNormalizer = require('./dist/normalizer.cjs');
```

---

## Getting Help

### Check Documentation

1. [Architecture](./architecture.md) - Two-pass design
2. [API Reference](./api-reference.md) - Complete API
3. [Testing Guide](./testing-guide.md) - Testing strategies
4. [Integration Guide](./integration-guide.md) - Integration examples

### Debug Mode

```javascript
// Enable debug mode
const parser = new PlantUMLParser({ debug: true });
const normalizer = new PlantUMLNormalizer({ debug: true });

// This will log normalization steps and metadata
```

### Verbose Test Output

```bash
# Grammar tests
npm test -- --debug

# Normalizer tests
npm run test:normalizer -- --verbose

# Integration tests
npm run test:integration -- --verbose
```

### File an Issue

If you can't resolve the issue:

1. Check existing issues: https://github.com/SaeedNMosleh/PlantUML-Parser/issues
2. Create new issue with:
   - PlantUML source causing the issue
   - Expected behavior
   - Actual behavior
   - Error messages
   - Node.js version (`node --version`)
   - OS version

---

## Common Gotchas

### 1. Forgetting to normalize

```javascript
// ❌ Wrong - parsing raw input without normalization
const { tree } = parser.parseNormalized(rawInput);

// ✅ Correct - parse with normalization (default)
const { tree } = parser.parse(rawInput);

// Or normalize explicitly
const { normalized } = parser.normalize(rawInput);
const { tree } = parser.parseNormalized(normalized);
```

### 2. Using wrong test parser

```javascript
// ❌ Wrong - importing internal source files instead of the published entrypoint
// (example) require('./src/index.ts')

// ✅ Correct - import the published entrypoint / built outputs
const PlantUMLParser = require('tree-sitter-plantuml');
```

### 3. Not checking for null

```javascript
// ❌ Wrong - assumes field exists
const label = node.childForFieldName('label');
console.log(label.text);  // Crashes if label is null

// ✅ Correct - check first
const label = node.childForFieldName('label');
if (label) {
  console.log(label.text);
}
```

### 4. Modifying tree during traversal

```javascript
// ❌ Wrong - modifying while iterating
for (let child of node.children) {
  node.children.splice(0, 1);  // Don't modify during iteration!
}

// ✅ Correct - collect first, then modify
const children = [...node.children];
for (let child of children) {
  // Process child
}
```

---

**Version**: 2.1.0
**Last Updated**: 2025-12-27
