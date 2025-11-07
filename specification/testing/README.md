# Testing Specification

## Overview

This document defines the testing strategy for tree-sitter-plantuml, including corpus tests, performance benchmarks, error recovery validation, and integration tests.

## Testing Philosophy

### Comprehensive Coverage
- **Every grammar rule** must have at least one positive test case
- **Common variations** of syntax should be tested
- **Error conditions** must be validated for graceful recovery
- **Real-world examples** from actual PlantUML usage

### Incremental Development
- Tests written **before** implementing grammar rules (TDD)
- Each phase gates completion on passing tests
- Regression tests added for every bug fix

### Performance Validation
- Automated benchmarks prevent performance regressions
- Incremental parsing verified on realistic edits
- Memory usage monitored for large files

## Corpus Test Organization

### Directory Structure

```
test/corpus/
├── common/
│   ├── comments.txt
│   ├── directives.txt
│   ├── colors.txt
│   └── stereotypes.txt
├── activity/
│   ├── 01_basic_nodes.txt
│   ├── 02_decisions.txt
│   ├── 03_loops.txt
│   ├── 04_partitions.txt
│   ├── 05_forks.txt
│   ├── 90_error_recovery.txt
│   └── 99_real_world.txt
├── sequence/
│   ├── 01_participants.txt
│   ├── 02_messages.txt
│   ├── 03_activations.txt
│   ├── 04_groups.txt
│   ├── 05_notes.txt
│   ├── 90_error_recovery.txt
│   └── 99_real_world.txt
├── class/
│   ├── 01_basic_classes.txt
│   ├── 02_fields_methods.txt
│   ├── 03_relationships.txt
│   ├── 04_interfaces.txt
│   ├── 05_packages.txt
│   ├── 06_generics.txt
│   ├── 90_error_recovery.txt
│   └── 99_real_world.txt
├── state/
│   ├── 01_basic_states.txt
│   ├── 02_transitions.txt
│   ├── 03_composite_states.txt
│   ├── 04_history_states.txt
│   ├── 90_error_recovery.txt
│   └── 99_real_world.txt
├── component/
│   ├── 01_basic_components.txt
│   ├── 02_interfaces.txt
│   └── 90_error_recovery.txt
└── usecase/
    ├── 01_actors_usecases.txt
    ├── 02_relationships.txt
    └── 90_error_recovery.txt
```

### Test File Format

Tree-sitter corpus tests use this format:

```
===========================
Test Name
===========================
Input PlantUML source code
----------------------------
(expected_ast)
```

Multiple tests per file:

```
===========================
First Test
===========================
@startuml
:Hello;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node label: (activity_label))
    (enduml_directive)))

===========================
Second Test
===========================
@startuml
:World;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node label: (activity_label))
    (enduml_directive)))
```

## Phase 1 Tests: Activity Diagrams

### 01_basic_nodes.txt

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
    (activity_node
      label: (activity_label))
    (enduml_directive)))

===========================
Activity node with arrow
===========================
@startuml
:Step 1;
-> Next step;
:Step 2;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node
      label: (activity_label))
    (flow_arrow
      label: (text_line))
    (activity_node
      label: (activity_label))
    (enduml_directive)))

===========================
Start and stop nodes
===========================
@startuml
start
:Process;
stop
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (start_node)
    (activity_node
      label: (activity_label))
    (stop_node)
    (enduml_directive)))

===========================
Multiline activity label
===========================
@startuml
:This is a very
long activity that
spans multiple lines;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node
      label: (activity_label
        (text_line)
        (text_line)
        (text_line)))
    (enduml_directive)))
```

### 02_decisions.txt

```
===========================
Simple if-then-else
===========================
@startuml
if (Condition?) then (yes)
  :Action A;
else (no)
  :Action B;
endif
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (decision_node
      condition: (condition_expression)
      true_label: (text_line)
      (activity_node label: (activity_label))
      (else_branch
        label: (text_line)
        (activity_node label: (activity_label))))
    (enduml_directive)))

===========================
If-then without else
===========================
@startuml
if (Check?) then (yes)
  :Do something;
endif
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (decision_node
      condition: (condition_expression)
      true_label: (text_line)
      (activity_node label: (activity_label)))
    (enduml_directive)))

===========================
If-elseif-else chain
===========================
@startuml
if (x < 0) then (true)
  :Negative;
elseif (x == 0) then (true)
  :Zero;
else (false)
  :Positive;
endif
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (decision_node
      condition: (condition_expression)
      true_label: (text_line)
      (activity_node label: (activity_label))
      (elseif_branch
        condition: (condition_expression)
        label: (text_line)
        (activity_node label: (activity_label)))
      (else_branch
        label: (text_line)
        (activity_node label: (activity_label))))
    (enduml_directive)))
```

### 03_loops.txt

```
===========================
Repeat-while loop
===========================
@startuml
repeat
  :Read data;
repeat while (More data?) is (yes)
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (repeat_while
      (activity_node label: (activity_label))
      condition: (condition_expression)
      label: (text_line))
    (enduml_directive)))

===========================
While loop
===========================
@startuml
while (Has items?) is (yes)
  :Process item;
endwhile (no)
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (while_loop
      condition: (condition_expression)
      label: (text_line)
      (activity_node label: (activity_label))
      end_label: (text_line))
    (enduml_directive)))
```

### 04_partitions.txt

```
===========================
Simple partition
===========================
@startuml
partition "Database Operations" {
  :Query;
  :Update;
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (partition
      name: (quoted_identifier)
      (activity_node label: (activity_label))
      (activity_node label: (activity_label)))
    (enduml_directive)))

===========================
Partition with color
===========================
@startuml
partition Backend #LightBlue {
  :Process;
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (partition
      name: (identifier)
      color: (color_spec (color))
      (activity_node label: (activity_label)))
    (enduml_directive)))

===========================
Swimlanes
===========================
@startuml
|User|
:Login;
|System|
:Authenticate;
|Database|
:Check credentials;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (swimlane name: (text_line))
    (activity_node label: (activity_label))
    (swimlane name: (text_line))
    (activity_node label: (activity_label))
    (swimlane name: (text_line))
    (activity_node label: (activity_label))
    (enduml_directive)))
```

### 90_error_recovery.txt

```
===========================
Missing semicolon
===========================
@startuml
:Step 1
:Step 2;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node
      label: (activity_label))
    (ERROR)
    (activity_node
      label: (activity_label))
    (enduml_directive)))

===========================
Missing endif
===========================
@startuml
if (Condition?) then (yes)
  :Action;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (decision_node
      condition: (condition_expression)
      true_label: (text_line)
      (activity_node label: (activity_label)))
    (enduml_directive)))

===========================
Invalid keyword in activity
===========================
@startuml
:Step 1;
invalid keyword here
:Step 2;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node label: (activity_label))
    (ERROR)
    (activity_node label: (activity_label))
    (enduml_directive)))
```

## Phase 2 Tests: Sequence Diagrams

### 01_participants.txt

```
===========================
Simple participant
===========================
@startuml
participant User
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (enduml_directive)))

===========================
Participant with alias
===========================
@startuml
participant "Web Server" as WS
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (participant_declaration
      type: (participant_type)
      name: (quoted_identifier)
      alias: (identifier))
    (enduml_directive)))

===========================
Multiple participant types
===========================
@startuml
actor User
boundary UI
control Controller
entity Model
database DB
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (participant_declaration
      type: (participant_type)
      name: (identifier))
    (enduml_directive)))

===========================
Participant with order
===========================
@startuml
participant Last order 30
participant First order 10
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (participant_declaration
      type: (participant_type)
      name: (identifier)
      order: (order_spec (number)))
    (participant_declaration
      type: (participant_type)
      name: (identifier)
      order: (order_spec (number)))
    (enduml_directive)))
```

### 02_messages.txt

```
===========================
Simple synchronous message
===========================
@startuml
Alice -> Bob: Hello
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (message
      sender: (participant_ref (identifier))
      arrow: (sync_arrow)
      receiver: (participant_ref (identifier))
      label: (message_text))
    (enduml_directive)))

===========================
Return message
===========================
@startuml
Bob --> Alice: Response
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (message
      sender: (participant_ref (identifier))
      arrow: (return_arrow)
      receiver: (participant_ref (identifier))
      label: (message_text))
    (enduml_directive)))

===========================
Message without label
===========================
@startuml
Alice -> Bob
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (message
      sender: (participant_ref (identifier))
      arrow: (sync_arrow)
      receiver: (participant_ref (identifier)))
    (enduml_directive)))

===========================
Various arrow types
===========================
@startuml
A -> B: Sync
A ->> B: Async
A -) B: Async
A ->* B: Create
A ->x B: Destroy
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (message
      sender: (participant_ref)
      arrow: (sync_arrow)
      receiver: (participant_ref)
      label: (message_text))
    (message
      sender: (participant_ref)
      arrow: (async_arrow)
      receiver: (participant_ref)
      label: (message_text))
    (message
      sender: (participant_ref)
      arrow: (async_arrow)
      receiver: (participant_ref)
      label: (message_text))
    (message
      sender: (participant_ref)
      arrow: (creation_arrow)
      receiver: (participant_ref)
      label: (message_text))
    (message
      sender: (participant_ref)
      arrow: (destruction_arrow)
      receiver: (participant_ref)
      label: (message_text))
    (enduml_directive)))
```

### 04_groups.txt

```
===========================
Alternative group
===========================
@startuml
alt Successful case
  A -> B: Request
  B --> A: Success
else Failure case
  B --> A: Error
end
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (group
      type: (group_type)
      label: (text_line)
      (message ...)
      (message ...)
      (alt_branch
        label: (text_line)
        (message ...)))
    (enduml_directive)))

===========================
Optional group
===========================
@startuml
opt Extra processing
  A -> B: Optional request
end
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (group
      type: (group_type)
      label: (text_line)
      (message ...))
    (enduml_directive)))

===========================
Loop group
===========================
@startuml
loop 1000 times
  A -> B: Request
end
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (group
      type: (group_type)
      label: (text_line)
      (message ...))
    (enduml_directive)))
```

## Phase 3 Tests: Class Diagrams

### 01_basic_classes.txt

```
===========================
Empty class
===========================
@startuml
class User
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (class_declaration
      name: (identifier))
    (enduml_directive)))

===========================
Class with body
===========================
@startuml
class User {
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (class_declaration
      name: (identifier)
      body: (class_body))
    (enduml_directive)))

===========================
Abstract class
===========================
@startuml
abstract class Shape
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (abstract_class_declaration
      name: (identifier))
    (enduml_directive)))

===========================
Interface
===========================
@startuml
interface Drawable
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (interface_declaration
      name: (identifier))
    (enduml_directive)))
```

### 02_fields_methods.txt

```
===========================
Class with fields
===========================
@startuml
class User {
  +id: Long
  -password: String
  #email: String
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (class_declaration
      name: (identifier)
      body: (class_body
        (field_declaration
          visibility: (visibility)
          name: (identifier)
          type: (type_reference (identifier)))
        (field_declaration
          visibility: (visibility)
          name: (identifier)
          type: (type_reference (identifier)))
        (field_declaration
          visibility: (visibility)
          name: (identifier)
          type: (type_reference (identifier)))))
    (enduml_directive)))

===========================
Class with methods
===========================
@startuml
class Calculator {
  +add(a: int, b: int): int
  +subtract(a: int, b: int): int
  -validate(): boolean
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (class_declaration
      name: (identifier)
      body: (class_body
        (method_declaration
          visibility: (visibility)
          name: (identifier)
          parameters: (parameter_list
            (parameters
              (parameter name: (identifier) type: (type_reference))
              (parameter name: (identifier) type: (type_reference))))
          return_type: (type_reference (identifier)))
        (method_declaration ...)
        (method_declaration ...)))
    (enduml_directive)))

===========================
Static and abstract modifiers
===========================
@startuml
class Example {
  {static} +count: int
  {abstract} +process(): void
}
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (class_declaration
      name: (identifier)
      body: (class_body
        (field_declaration
          modifier: (field_modifier)
          visibility: (visibility)
          name: (identifier)
          type: (type_reference))
        (method_declaration
          modifier: (method_modifier)
          visibility: (visibility)
          name: (identifier)
          parameters: (parameter_list)
          return_type: (type_reference))))
    (enduml_directive)))
```

### 03_relationships.txt

```
===========================
Inheritance
===========================
@startuml
Child --|> Parent
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (relationship
      from: (class_reference (identifier))
      arrow: (extension_arrow)
      to: (class_reference (identifier)))
    (enduml_directive)))

===========================
Composition
===========================
@startuml
Car *-- Engine
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (relationship
      from: (class_reference (identifier))
      arrow: (composition_arrow)
      to: (class_reference (identifier)))
    (enduml_directive)))

===========================
Aggregation
===========================
@startuml
Department o-- Employee
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (relationship
      from: (class_reference (identifier))
      arrow: (aggregation_arrow)
      to: (class_reference (identifier)))
    (enduml_directive)))

===========================
Association with cardinality
===========================
@startuml
Student "1" -- "0..*" Course: enrolls in
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (relationship
      from: (class_reference
        (identifier)
        (cardinality))
      arrow: (association_arrow)
      to: (class_reference
        (identifier)
        (cardinality))
      label: (text_line))
    (enduml_directive)))
```

## Performance Benchmarks

### Benchmark Suite Structure

```typescript
// benchmarks/performance.test.ts

import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';
import { readFileSync } from 'fs';
import { performance } from 'perf_hooks';

describe('Performance Benchmarks', () => {
  let parser: Parser;

  beforeEach(() => {
    parser = new Parser();
    parser.setLanguage(PlantUML);
  });

  describe('Initial Parse Performance', () => {
    test('Small file (100 lines) parses under 10ms', () => {
      const source = readFileSync('fixtures/small_activity.puml', 'utf-8');
      const start = performance.now();
      const tree = parser.parse(source);
      const duration = performance.now() - start;

      expect(tree.rootNode.hasError).toBe(false);
      expect(duration).toBeLessThan(10);
    });

    test('Medium file (1000 lines) parses under 50ms', () => {
      const source = readFileSync('fixtures/medium_class.puml', 'utf-8');
      const start = performance.now();
      const tree = parser.parse(source);
      const duration = performance.now() - start;

      expect(tree.rootNode.hasError).toBe(false);
      expect(duration).toBeLessThan(50);
    });

    test('Large file (10000 lines) parses under 100ms', () => {
      const source = readFileSync('fixtures/large_sequence.puml', 'utf-8');
      const start = performance.now();
      const tree = parser.parse(source);
      const duration = performance.now() - start;

      expect(tree.rootNode.hasError).toBe(false);
      expect(duration).toBeLessThan(100);
    });
  });

  describe('Incremental Parse Performance', () => {
    test('Single character insertion under 1ms', () => {
      const source = readFileSync('fixtures/medium_class.puml', 'utf-8');
      const tree = parser.parse(source);

      // Insert single character
      const editPos = 500;
      const newSource = source.slice(0, editPos) + 'x' + source.slice(editPos);

      tree.edit({
        startIndex: editPos,
        oldEndIndex: editPos,
        newEndIndex: editPos + 1,
        startPosition: { row: 10, column: 5 },
        oldEndPosition: { row: 10, column: 5 },
        newEndPosition: { row: 10, column: 6 }
      });

      const start = performance.now();
      const newTree = parser.parse(newSource, tree);
      const duration = performance.now() - start;

      expect(duration).toBeLessThan(1);
    });

    test('Single line edit under 5ms', () => {
      const source = readFileSync('fixtures/medium_class.puml', 'utf-8');
      const tree = parser.parse(source);

      // Replace line
      const lines = source.split('\n');
      const targetLine = 10;
      lines[targetLine] = '  +newField: String';
      const newSource = lines.join('\n');

      const editStart = lines.slice(0, targetLine).join('\n').length + 1;
      const oldLineLength = source.split('\n')[targetLine].length;
      const newLineLength = lines[targetLine].length;

      tree.edit({
        startIndex: editStart,
        oldEndIndex: editStart + oldLineLength,
        newEndIndex: editStart + newLineLength,
        startPosition: { row: targetLine, column: 0 },
        oldEndPosition: { row: targetLine, column: oldLineLength },
        newEndPosition: { row: targetLine, column: newLineLength }
      });

      const start = performance.now();
      const newTree = parser.parse(newSource, tree);
      const duration = performance.now() - start;

      expect(duration).toBeLessThan(5);
    });
  });

  describe('Query Performance', () => {
    test('Syntax highlighting query under 10ms', () => {
      const source = readFileSync('fixtures/medium_class.puml', 'utf-8');
      const tree = parser.parse(source);

      const query = parser.getLanguage().query(`
        [(class_name) (identifier)] @variable
        ["class" "interface"] @keyword
      `);

      const start = performance.now();
      const matches = query.matches(tree.rootNode);
      const duration = performance.now() - start;

      expect(matches.length).toBeGreaterThan(0);
      expect(duration).toBeLessThan(10);
    });
  });

  describe('Memory Usage', () => {
    test('Parse tree size reasonable for large files', () => {
      const source = readFileSync('fixtures/large_sequence.puml', 'utf-8');
      const before = process.memoryUsage().heapUsed;
      const tree = parser.parse(source);
      const after = process.memoryUsage().heapUsed;
      const overhead = (after - before) / (1024 * 1024);  // MB

      expect(overhead).toBeLessThan(10);  // Less than 10MB overhead
    });
  });
});
```

### Performance Targets

| Metric | Target | Test Method |
|--------|--------|-------------|
| Initial parse (1K lines) | <10ms | Benchmark suite |
| Initial parse (10K lines) | <100ms | Benchmark suite |
| Incremental (1 char) | <1ms | Benchmark suite |
| Incremental (1 line) | <5ms | Benchmark suite |
| Query execution | <10ms | Benchmark suite |
| Memory overhead | <10MB/1K lines | Memory profiling |

## Integration Tests

### LSP Integration

```typescript
// test/integration/lsp.test.ts

import { createConnection, TextDocuments } from 'vscode-languageserver/node';
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

describe('LSP Integration', () => {
  test('Provides diagnostics for syntax errors', () => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const source = `
@startuml
class User {
  +id Long  // Missing colon
}
@enduml
    `;

    const tree = parser.parse(source);
    const errors = findErrorNodes(tree.rootNode);

    expect(errors.length).toBeGreaterThan(0);
    expect(errors[0].type).toBe('ERROR');
  });

  test('Supports incremental document updates', () => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const doc1 = '@startuml\nclass A\n@enduml';
    const tree1 = parser.parse(doc1);

    const doc2 = '@startuml\nclass A\nclass B\n@enduml';
    const tree2 = parser.parse(doc2, tree1);

    expect(tree2.rootNode.hasError).toBe(false);
  });
});
```

### PlantEdit Integration

```typescript
// test/integration/plantedit.test.ts

import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

describe('PlantEdit Integration', () => {
  test('Maps AST nodes to source positions', () => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const source = `
@startuml
class User {
  +name: String
}
@enduml
    `;

    const tree = parser.parse(source);
    const classNode = tree.rootNode
      .descendantForPosition({ row: 2, column: 6 });

    expect(classNode?.type).toBe('class_declaration');
    expect(classNode?.text).toContain('User');
  });

  test('Extracts class definitions for domain model', () => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const source = `
@startuml
class User {
  +id: Long
}
class Post {
  +title: String
}
@enduml
    `;

    const tree = parser.parse(source);
    const query = parser.getLanguage().query(`
      (class_declaration name: (identifier) @class_name)
    `);

    const matches = query.matches(tree.rootNode);
    const classNames = matches.map(m => m.captures[0].node.text);

    expect(classNames).toEqual(['User', 'Post']);
  });
});
```

## Test Coverage Requirements

### Phase-Gated Requirements

| Phase | Corpus Tests | Coverage | Error Tests |
|-------|--------------|----------|-------------|
| Phase 1 | 20+ activity | 80%+ | 5+ |
| Phase 2 | 30+ sequence | 85%+ | 5+ |
| Phase 3 | 40+ class | 90%+ | 5+ |
| Phase 4 | 30+ state | 90%+ | 5+ |
| Phase 5 | 20+ component/use case | 90%+ | 3+ |
| Phase 6 | 100+ total | 95%+ | 20+ |

### Quality Gates

Each phase must pass:
- ✅ All corpus tests pass
- ✅ Coverage meets target
- ✅ Error recovery tests pass
- ✅ Performance benchmarks pass
- ✅ No memory leaks detected
- ✅ Integration tests pass

## Continuous Integration

### GitHub Actions Workflow

```yaml
# .github/workflows/test.yml
name: Test

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - uses: actions/setup-node@v2
        with:
          node-version: '18'

      - name: Install tree-sitter CLI
        run: npm install -g tree-sitter-cli

      - name: Generate parser
        run: tree-sitter generate

      - name: Run corpus tests
        run: tree-sitter test

      - name: Build native bindings
        run: npm install

      - name: Run unit tests
        run: npm test

      - name: Run benchmarks
        run: npm run bench

      - name: Check coverage
        run: npm run coverage

      - name: Upload coverage
        uses: codecov/codecov-action@v2
```

---

**Next**: See [Integration Specification](../integration/README.md) for packaging and consumption details.
