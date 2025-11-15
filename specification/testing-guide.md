# Testing Guide

Complete testing strategy and guide for the PlantUML Parser.

## Testing Architecture

The parser uses a **4-level testing pyramid** ensuring comprehensive validation:

```
┌─────────────────────────────────────────────────┐
│ Level 4: PlantUML Validation (30 tests)        │ <-- Validate against PlantUML server
├─────────────────────────────────────────────────┤
│ Level 3: Integration Tests (17 tests)          │ <-- Full pipeline: source → AST
├─────────────────────────────────────────────────┤
│ Level 2: Grammar Corpus (30 tests)             │ <-- Grammar only (normalized input)
├─────────────────────────────────────────────────┤
│ Level 1: Normalizer Unit Tests (59 tests)      │ <-- Normalizer only
└─────────────────────────────────────────────────┘
```

**Current Status**: 136/136 tests passing (100% ✅)

---

## Level 1: Normalizer Unit Tests

### Location
`test/normalizer/`

### Purpose
Test normalization rules in isolation.

### Framework
Jest

### Running Tests
```bash
npm run test:normalizer    # Run all normalizer tests
npm run test:normalizer -- --watch    # Watch mode
```

### Test Structure

```javascript
// test/normalizer/arrows.test.js
const PlantUMLNormalizer = require('../../src/normalizer');

describe('Arrow Normalization', () => {
  let normalizer;

  beforeEach(() => {
    normalizer = new PlantUMLNormalizer();
  });

  test('consolidates arrow with label', () => {
    const input = `@startuml
->   :   Label
@enduml`;

    const { normalized } = normalizer.normalize(input);

    expect(normalized).toBe(`@startuml
->: Label
@enduml`);
  });

  test('normalizes arrow spacing', () => {
    const input = '->      :    Label with spaces';
    const { normalized } = normalizer.normalize(input);
    expect(normalized).toContain('->: Label with spaces');
  });
});
```

### Current Coverage

**59 tests** covering:
- Arrow consolidation (12 tests)
- Whitespace normalization (8 tests)
- Decision node normalization (10 tests)
- Loop normalization (8 tests)
- Partition formatting (7 tests)
- Note directive handling (6 tests)
- Edge cases (8 tests)

---

## Level 2: Grammar Corpus Tests

### Location
`test/corpus/activity/`

### Purpose
Validate grammar parsing with normalized input.

### Framework
Tree-sitter corpus test format

### Running Tests
```bash
npm test                   # Run all grammar corpus tests
npm test -- --debug        # Show detailed output
```

### Corpus Test Format

```
===========================
Test name
===========================
@startuml
input code (normalized)
@enduml
----------------------------
(expected_ast_structure)
```

### Example Corpus Test

```
===========================
Simple activity node
===========================
@startuml
:Hello World;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element
      (activity_node
        label: (activity_label)))
    (enduml_directive)))
```

### Test Files

```
test/corpus/activity/
├── 01_basic_nodes.txt      # 5 tests - start, stop, activity nodes
├── 02_decisions.txt        # 5 tests - if/then/else/endif
├── 03_loops.txt            # 4 tests - while, repeat loops
├── 04_partitions.txt       # 4 tests - partitions, swimlanes
├── 05_forks.txt            # 4 tests - fork/split nodes
├── 06_directives.txt       # 2 tests - title, skinparam
└── 07_real_world.txt       # 6 tests - real-world examples
```

### Current Coverage

**30 tests** covering all activity diagram elements.

---

## Level 3: Integration Tests

### Location
`test/integration/`

### Purpose
Test full pipeline: raw PlantUML → Normalizer → Grammar → AST

### Framework
Jest

### Running Tests
```bash
npm run test:integration           # Run all integration tests
npm run test:integration -- --watch    # Watch mode
```

### Test Structure

```javascript
// test/integration/full-pipeline.test.js
const PlantUMLParser = require('../../index-fast');

describe('Full Pipeline Tests', () => {
  let parser;

  beforeEach(() => {
    parser = new PlantUMLParser();
  });

  test('parses basic activity diagram', () => {
    const source = `@startuml
start
:Process;
stop
@enduml`;

    const { tree, normalized } = parser.parse(source);

    expect(tree.rootNode.hasError).toBe(false);
    expect(normalized).toContain('start');
    expect(normalized).toContain(':Process;');
    expect(normalized).toContain('stop');
  });

  test('normalizes and parses arrows', () => {
    const source = `@startuml
->   :   Label
@enduml`;

    const { tree, normalized } = parser.parse(source);

    expect(tree.rootNode.hasError).toBe(false);
    expect(normalized).toBe(`@startuml
->: Label
@enduml`);
  });
});
```

### Current Coverage

**17 tests** covering:
- Basic nodes (3 tests)
- Arrows with labels (3 tests)
- Decision nodes (3 tests)
- Loops (2 tests)
- Partitions (2 tests)
- Forks (2 tests)
- Real-world examples (2 tests)

---

## Level 4: PlantUML Validation Tests

### Location
`scripts/validate-plantuml.js`

### Purpose
Validate test syntax against official PlantUML server.

### Running Tests
```bash
# Start PlantUML server
npm run docker:up

# Run validation
npm run validate

# Stop server
npm run docker:down
```

### Validation Process

1. Extract PlantUML code from corpus tests
2. Send to PlantUML server (HTTP POST)
3. Verify server accepts syntax (HTTP 200)
4. Reject if server returns error (HTTP 400)

### Example Output

```
PlantUML Syntax Validation
Validating 30 test cases...
✓ Basic activity node (HTTP 200)
✓ Start and stop nodes (HTTP 200)
✓ Decision node (HTTP 200)
✓ While loop (HTTP 200)
...
✓ 30/30 tests passed (100%)
```

### Current Coverage

**30 validation tests** - all corpus tests validated against PlantUML server.

---

## Writing New Tests

### 1. Write Normalizer Test

```javascript
// test/normalizer/new-feature.test.js
const PlantUMLNormalizer = require('../../src/normalizer');

describe('New Feature Normalization', () => {
  test('normalizes new syntax', () => {
    const normalizer = new PlantUMLNormalizer();
    const input = `raw input`;
    const { normalized } = normalizer.normalize(input);

    expect(normalized).toBe(`expected normalized output`);
  });
});
```

### 2. Add Corpus Test

```
===========================
New feature test
===========================
@startuml
normalized input
@enduml
----------------------------
(expected_ast)
```

### 3. Add Integration Test

```javascript
// test/integration/new-feature.test.js
const PlantUMLParser = require('../../index-fast');

test('parses new feature end-to-end', () => {
  const parser = new PlantUMLParser();
  const source = `raw input`;

  const { tree, normalized } = parser.parse(source);

  expect(tree.rootNode.hasError).toBe(false);
  // Additional assertions...
});
```

### 4. Validate Against PlantUML Server

```bash
# Add test case to corpus
# Run validation
npm run validate

# Verify HTTP 200 response
```

---

## Test Commands

### Run All Tests

```bash
npm run test:all           # All 136 tests
npm run test:100           # All tests + success message
```

### Run Individual Suites

```bash
npm run test:normalizer    # 59 normalizer tests
npm test                   # 30 grammar corpus tests
npm run test:integration   # 17 integration tests
npm run validate           # 30 PlantUML validation tests
```

### Test with Coverage

```bash
npm run test:normalizer -- --coverage    # Normalizer coverage
npm run test:integration -- --coverage   # Integration coverage
```

### Watch Mode

```bash
npm run test:normalizer -- --watch
npm run test:integration -- --watch
```

---

## Zero Tolerance Policy

**100% test success rate required.**

### Policy

1. **No failing tests allowed** - Fix or remove
2. **PlantUML server is truth** - All syntax must be valid
3. **Integration tests are primary** - End-to-end success is key
4. **Fix in 2 attempts** - If not fixed after 2 tries, pivot approach

### When Tests Fail

**Option 1: Fix the code**
```bash
# Make fix
npm run test:all    # Verify fix
```

**Option 2: Fix the test**
```bash
# Correct test expectations
npm run test:all    # Verify correction
```

**Option 3: Remove invalid test**
```bash
# If PlantUML server rejects syntax, remove test
git rm test/corpus/activity/invalid-test.txt
npm run test:all    # Verify removal
```

---

## Corpus Test Examples

### Basic Node Test

```
===========================
Activity node
===========================
@startuml
:Process data;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element
      (activity_node
        label: (activity_label)))
    (enduml_directive)))
```

### Decision Node Test

```
===========================
If-then-else
===========================
@startuml
if (valid) then (yes)
  :Accept;
else (no)
  :Reject;
endif
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element
      (decision_node
        condition: (condition)
        true_label: (branch_label)
        (activity_element
          (activity_node label: (activity_label)))
        (else_branch
          label: (branch_label)
          (activity_element
            (activity_node label: (activity_label))))))
    (enduml_directive)))
```

### Loop Test

```
===========================
While loop
===========================
@startuml
while (has items) is (yes)
  :Process item;
endwhile (done)
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element
      (while_loop
        condition: (condition)
        label: (branch_label)
        (activity_element
          (activity_node label: (activity_label)))
        end_label: (branch_label)))
    (enduml_directive)))
```

### Partition Test

```
===========================
Partition with color
===========================
@startuml
partition "Backend" #lightblue {
  :Process;
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element
      (partition
        name: (string)
        color: (color)
        (activity_element
          (activity_node label: (activity_label)))))
    (enduml_directive)))
```

---

## Test Directory Structure

```
test/
├── corpus/
│   └── activity/
│       ├── 01_basic_nodes.txt
│       ├── 02_decisions.txt
│       ├── 03_loops.txt
│       ├── 04_partitions.txt
│       ├── 05_forks.txt
│       ├── 06_directives.txt
│       └── 07_real_world.txt
├── normalizer/
│   ├── arrows.test.js
│   ├── decisions.test.js
│   ├── loops.test.js
│   ├── partitions.test.js
│   ├── notes.test.js
│   └── edge-cases.test.js
├── integration/
│   ├── full-pipeline.test.js
│   ├── error-handling.test.js
│   └── incremental-parsing.test.js
├── fixtures/
│   ├── test-arrow-label.puml
│   ├── test-simple-flow.puml
│   └── test-note-minimal.puml
└── examples/
    ├── test-normalize.js
    └── test-parse.js
```

---

## Future Test Expansion

### Phase 2: Sequence Diagrams

Will add:
- `test/corpus/sequence/` (~30 tests)
- `test/normalizer/sequence.test.js` (~20 tests)
- `test/integration/sequence.test.js` (~10 tests)

### Phase 3: Class Diagrams

Will add:
- `test/corpus/class/` (~40 tests)
- `test/normalizer/class.test.js` (~25 tests)
- `test/integration/class.test.js` (~12 tests)

See [ROADMAP.md](./ROADMAP.md) for full phase plan.

---

## Related Documentation

- **[Architecture](./architecture.md)** - Two-pass parser design
- **[Grammar](./grammar.md)** - Grammar specification
- **[API Reference](./api-reference.md)** - Parser API
- **[CONTRIBUTING](./CONTRIBUTING.md)** - Development principles
- **[Troubleshooting](./troubleshooting.md)** - Common issues

---

**Current Test Results**: 136/136 passing (100% ✅)
**Version**: 2.0.0
**Last Updated**: 2025-11-15
