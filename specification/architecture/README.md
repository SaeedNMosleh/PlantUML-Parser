# Parser Architecture Specification

## Overview

This document defines the architectural design of the tree-sitter-plantuml parser, detailing its components, data structures, and integration patterns.

## Core Principles

### 1. Separation of Concerns
- **Grammar Layer**: Defines syntax rules (grammar.js)
- **Parser Layer**: Generates and executes parsing logic (parser.c)
- **Query Layer**: Extracts semantic information (*.scm files)
- **Binding Layer**: Provides language-specific APIs (Node.js, Rust)

### 2. Incremental Performance
- Parse only modified regions on edits
- Maintain syntax tree between parses
- Update affected nodes with minimal traversal
- Target <5ms for typical single-line changes

### 3. Error Resilience
- Continue parsing despite syntax errors
- Insert ERROR nodes in AST for invalid syntax
- Maintain valid tree structure around errors
- Provide precise error locations and context

### 4. Lossless Representation
- Preserve all source characters including whitespace
- Include comments as first-class nodes
- Maintain exact source ranges for every node
- Enable perfect source reconstruction from AST

## System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                     Consumer Applications                    │
│  (PlantEdit, LSP Server, IDEs, CLI Tools)                   │
└─────────────────────────────────────────────────────────────┘
                            ↓ ↑
┌─────────────────────────────────────────────────────────────┐
│                    Language Bindings                         │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐     │
│  │   Node.js    │  │     Rust     │  │    Python    │     │
│  │   Binding    │  │   Binding    │  │   Binding    │     │
│  └──────────────┘  └──────────────┘  └──────────────┘     │
└─────────────────────────────────────────────────────────────┘
                            ↓ ↑
┌─────────────────────────────────────────────────────────────┐
│                  Tree-sitter Runtime                         │
│  ┌──────────────────────────────────────────────────────┐  │
│  │              Parser Core (C)                         │  │
│  │  • Incremental parsing engine                        │  │
│  │  • Error recovery system                             │  │
│  │  • Tree manipulation API                             │  │
│  └──────────────────────────────────────────────────────┘  │
│  ┌──────────────────────────────────────────────────────┐  │
│  │              Query Engine (C)                        │  │
│  │  • Pattern matching system                           │  │
│  │  • Predicate evaluation                              │  │
│  │  • Capture binding                                   │  │
│  └──────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────┘
                            ↓ ↑
┌─────────────────────────────────────────────────────────────┐
│              Generated Parser (parser.c)                     │
│  • State machine tables                                      │
│  • Reduction rules                                           │
│  • Symbol metadata                                           │
│  ⚠️  Auto-generated - DO NOT EDIT                           │
└─────────────────────────────────────────────────────────────┘
                            ↑
┌─────────────────────────────────────────────────────────────┐
│                Grammar Definition                            │
│  ┌──────────────────────────────────────────────────────┐  │
│  │           grammar.js (Source of Truth)               │  │
│  │                                                       │  │
│  │  • Lexical rules (tokens)                           │  │
│  │  • Syntactic rules (grammar)                        │  │
│  │  • Precedence declarations                          │  │
│  │  • Conflict resolutions                             │  │
│  └──────────────────────────────────────────────────────┘  │
│  ┌──────────────────────────────────────────────────────┐  │
│  │     Optional Custom Scanner (scanner.c)             │  │
│  │  • Complex token recognition                         │  │
│  │  • Context-sensitive lexing                          │  │
│  │  • Indentation tracking                              │  │
│  └──────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────┘
```

## AST Structure

### Node Types Hierarchy

```
source_file
├── diagram
│   ├── @startuml_directive
│   ├── diagram_body
│   │   ├── activity_diagram
│   │   │   ├── activity_node
│   │   │   ├── decision_node
│   │   │   ├── partition
│   │   │   └── flow_edge
│   │   ├── sequence_diagram
│   │   │   ├── participant
│   │   │   ├── message
│   │   │   ├── group
│   │   │   └── activation
│   │   ├── class_diagram
│   │   │   ├── class_declaration
│   │   │   │   ├── class_name
│   │   │   │   ├── field
│   │   │   │   └── method
│   │   │   ├── interface_declaration
│   │   │   ├── relationship
│   │   │   └── package
│   │   ├── state_diagram
│   │   │   ├── state_declaration
│   │   │   ├── transition
│   │   │   ├── composite_state
│   │   │   └── history_state
│   │   └── ...
│   └── @enduml_directive
├── directive
│   ├── title_directive
│   ├── note_directive
│   ├── style_directive
│   └── ...
├── comment
│   ├── line_comment
│   └── block_comment
└── ERROR (for syntax errors)
```

### Node Attributes

Every AST node includes:

```c
struct TSNode {
  uint32_t start_byte;      // Byte offset in source
  uint32_t end_byte;        // End byte offset
  TSPoint start_point;      // Line/column position
  TSPoint end_point;        // End line/column
  uint16_t symbol;          // Node type ID
  // ... internal tree-sitter fields
};
```

**Additional metadata accessible via API:**
- `node.type`: String name (e.g., "class_declaration")
- `node.text`: Source text span
- `node.isNamed`: Whether it's a named node (vs. anonymous like `{`)
- `node.isMissing`: Inserted by error recovery
- `node.isExtra`: Whitespace or comment
- `node.hasError`: Contains syntax errors
- `node.fieldName`: Field name in parent (e.g., "name", "body")

## Grammar Organization

### Structure by Diagram Type

```javascript
module.exports = grammar({
  name: 'plantuml',

  extras: $ => [
    $.comment,
    /\s+/  // Whitespace
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.diagram,
      $.comment
    ),

    diagram: $ => seq(
      $.startuml_directive,
      repeat($._diagram_element),
      $.enduml_directive
    ),

    _diagram_element: $ => choice(
      $.activity_diagram_element,
      $.sequence_diagram_element,
      $.class_diagram_element,
      $.state_diagram_element,
      $.directive,
      $.comment
    ),

    // Activity Diagram Rules
    activity_diagram_element: $ => choice(
      $.activity_node,
      $.decision_node,
      $.partition,
      $.flow_edge,
      // ...
    ),

    activity_node: $ => seq(
      ':',
      $.label,
      ';'
    ),

    decision_node: $ => seq(
      'if',
      '(',
      $.condition,
      ')',
      'then',
      optional(seq('(', $.label, ')')),
      // ...
    ),

    // Sequence Diagram Rules
    sequence_diagram_element: $ => choice(
      $.participant,
      $.message,
      $.group,
      // ...
    ),

    participant: $ => seq(
      choice('participant', 'actor', 'boundary', 'control', 'entity', 'database'),
      field('name', $.identifier),
      optional(seq('as', field('alias', $.identifier))),
      optional($.stereotype)
    ),

    message: $ => seq(
      field('sender', $.identifier),
      field('arrow', $._arrow),
      field('receiver', $.identifier),
      optional(seq(':', field('label', $.message_text)))
    ),

    // Class Diagram Rules
    class_diagram_element: $ => choice(
      $.class_declaration,
      $.interface_declaration,
      $.relationship,
      $.package,
      // ...
    ),

    class_declaration: $ => seq(
      'class',
      field('name', $.identifier),
      optional($.generics),
      optional($.stereotype),
      optional($.class_body)
    ),

    class_body: $ => seq(
      '{',
      repeat(choice(
        $.field,
        $.method,
        $.separator
      )),
      '}'
    ),

    // State Diagram Rules
    state_diagram_element: $ => choice(
      $.state_declaration,
      $.transition,
      $.composite_state,
      // ...
    ),

    // Common Rules
    comment: $ => choice(
      $.line_comment,
      $.block_comment
    ),

    line_comment: $ => token(seq("'", /.*/)),

    block_comment: $ => token(seq(
      "/'",
      /[^*]*\*+([^/*][^*]*\*+)*/,
      "'/")
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    // ...
  }
});
```

### Precedence and Conflicts

Use explicit precedence to resolve ambiguities:

```javascript
precedences: $ => [
  [
    $.multiplicative_expression,
    $.additive_expression,
    $.comparison_expression,
  ],
  // ...
],

conflicts: $ => [
  // Document known grammar conflicts
  [$.class_declaration, $.interface_declaration],
  // ...
]
```

## Error Recovery Strategy

### Automatic Recovery

Tree-sitter's error recovery inserts ERROR nodes while maintaining tree structure:

```
Input:  class User {
          +name string   // Missing colon
          +email: string
        }

AST:    (class_declaration
          name: (identifier)
          body: (class_body
            (field
              visibility: (visibility_modifier)
              name: (identifier)
              (ERROR (identifier)))  // "string" without colon
            (field
              visibility: (visibility_modifier)
              name: (identifier)
              type: (type (identifier)))))
```

### Error Recovery Heuristics

1. **Synchronization Points**: Parser resumes at known delimiters
   - Diagram boundaries: `@startuml`, `@enduml`
   - Structural elements: `}`, `end`, newlines

2. **Missing Token Insertion**: Parser inserts expected tokens
   - Missing semicolons in activity nodes
   - Missing closing braces in class bodies
   - Missing `enduml` directives

3. **Extra Token Skipping**: Parser skips unexpected tokens
   - Invalid keywords in wrong contexts
   - Malformed syntax elements

### Error Node Queries

Extract error information for diagnostics:

```scheme
; queries/errors.scm
(ERROR) @error

; Specific error patterns
(class_body
  (ERROR) @error.missing_semicolon
  (#match? @error.missing_semicolon "^[^;]+$"))
```

## Performance Architecture

### Incremental Parsing

Tree-sitter maintains parse trees between edits:

```typescript
// Initial parse
const tree1 = parser.parse(sourceCode1);

// Edit at line 10
const newTree = parser.parse(
  sourceCode2,
  tree1,  // Previous tree
  {
    startIndex: editStartByte,
    oldEndIndex: editOldEndByte,
    newEndIndex: editNewEndByte,
    startPosition: editStartPoint,
    oldEndPosition: editOldEndPoint,
    newEndPosition: editNewEndPoint
  }
);

// Only affected subtrees are re-parsed
```

### Memory Management

- **Tree Reuse**: Unchanged subtrees share memory with previous parse
- **Node Pooling**: Reuse node allocations across parses
- **Lazy Evaluation**: Field access and child iteration on-demand
- **Reference Counting**: Automatic memory cleanup

### Performance Targets

| Operation | File Size | Target | Strategy |
|-----------|-----------|--------|----------|
| Initial parse | 1K lines | <10ms | Efficient grammar, minimal backtracking |
| Initial parse | 10K lines | <100ms | Optimized state machine, fast lexer |
| Incremental edit | Single line | <1ms | Minimal re-parsing scope |
| Incremental edit | Block (10 lines) | <5ms | Subtree replacement |
| Query execution | 1K nodes | <10ms | Indexed pattern matching |
| Syntax highlighting | Viewport (50 lines) | <5ms | Incremental query updates |

## Query System Architecture

### Query Types

#### 1. Highlights (Syntax Highlighting)

```scheme
; queries/highlights.scm

; Keywords
["class" "interface" "participant" "if" "then" "else"] @keyword

; Directives
["@startuml" "@enduml" "title" "note"] @keyword.directive

; Identifiers
(identifier) @variable

; Types
(class_name) @type
(type) @type

; Operators
[":" "->" "<-" "->>" "<<-"] @operator

; Strings and literals
(string) @string
(number) @number

; Comments
(comment) @comment
```

#### 2. Code Folding

```scheme
; queries/folds.scm

; Fold class bodies
(class_body) @fold

; Fold diagram bodies
(diagram
  (startuml_directive)
  (enduml_directive)) @fold

; Fold multi-line comments
(block_comment) @fold
```

#### 3. Symbol Tags (Code Navigation)

```scheme
; queries/tags.scm

; Class definitions
(class_declaration
  name: (identifier) @name) @definition.class

; Method definitions
(method
  name: (identifier) @name) @definition.method

; Participant definitions
(participant
  name: (identifier) @name) @definition.participant

; References
(identifier) @reference
```

#### 4. Local Scope Analysis

```scheme
; queries/locals.scm

; Scope definitions
(class_body) @scope

; Definitions
(class_declaration
  name: (identifier) @definition)

; References
(type
  (identifier) @reference)
```

### Query Execution

```typescript
// Load query
const query = language.query(`
  (class_declaration
    name: (identifier) @class_name
    body: (class_body
      (method name: (identifier) @method_name)))
`);

// Execute query
const matches = query.matches(tree.rootNode);

matches.forEach(match => {
  match.captures.forEach(capture => {
    console.log(`${capture.name}: ${capture.node.text}`);
  });
});
```

## Integration Patterns

### Language Server Protocol

```typescript
import { createConnection, TextDocuments } from 'vscode-languageserver/node';
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

const parser = new Parser();
parser.setLanguage(PlantUML);
const trees = new Map<string, Parser.Tree>();

// Parse on document open/change
documents.onDidChangeContent(change => {
  const oldTree = trees.get(change.document.uri);
  const newTree = parser.parse(change.document.getText(), oldTree);
  trees.set(change.document.uri, newTree);

  // Extract diagnostics from ERROR nodes
  const errors = findErrorNodes(newTree.rootNode);
  connection.sendDiagnostics({
    uri: change.document.uri,
    diagnostics: errors.map(err => ({
      range: nodeToRange(err),
      message: "Syntax error",
      severity: DiagnosticSeverity.Error
    }))
  });
});
```

### PlantEdit Integration

```typescript
// PlantEdit consumes parser for source mapping
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

class SourceMapper {
  private parser: Parser;
  private tree: Parser.Tree | null = null;

  constructor() {
    this.parser = new Parser();
    this.parser.setLanguage(PlantUML);
  }

  parse(source: string): void {
    this.tree = this.parser.parse(source, this.tree);
  }

  findNodeAt(line: number, column: number): Parser.SyntaxNode | null {
    if (!this.tree) return null;
    return this.tree.rootNode.descendantForPosition({ row: line, column });
  }

  getClassDefinition(className: string): Parser.SyntaxNode | null {
    if (!this.tree) return null;

    const query = this.parser.getLanguage().query(`
      (class_declaration
        name: (identifier) @name
        (#eq? @name "${className}"))
    `);

    const matches = query.matches(this.tree.rootNode);
    return matches[0]?.captures[0].node || null;
  }

  updateSource(
    edit: { startIndex: number, oldEndIndex: number, newEndIndex: number },
    newSource: string
  ): void {
    if (!this.tree) return;

    this.tree.edit(edit);
    this.tree = this.parser.parse(newSource, this.tree);
  }
}
```

## Testing Architecture

### Corpus Test Structure

```
test/corpus/
├── activity_diagrams/
│   ├── basic_nodes.txt
│   ├── decisions.txt
│   ├── partitions.txt
│   └── error_recovery.txt
├── sequence_diagrams/
│   ├── participants.txt
│   ├── messages.txt
│   └── groups.txt
└── ...

Format:
===========================
Test name
===========================
Input source code
----------------------------
(expected_ast_structure)
```

Example:

```
===========================
Activity node with label
===========================
@startuml
:Hello World;
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_node
      label: (label))
    (enduml_directive)))
```

### Performance Benchmarks

```typescript
// benchmarks/parse_performance.ts
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';
import { readFileSync } from 'fs';

const parser = new Parser();
parser.setLanguage(PlantUML);

// Initial parse benchmark
const source = readFileSync('fixtures/large_diagram.puml', 'utf-8');
const start = performance.now();
const tree = parser.parse(source);
const duration = performance.now() - start;

console.log(`Parsed ${source.length} bytes in ${duration.toFixed(2)}ms`);

// Incremental parse benchmark
const editStart = source.indexOf(':');
const newSource = source.slice(0, editStart) + ':Modified;' + source.slice(editStart + 10);

const incStart = performance.now();
const newTree = parser.parse(newSource, tree);
const incDuration = performance.now() - incStart;

console.log(`Incremental parse: ${incDuration.toFixed(2)}ms`);
```

## Build and Distribution

### Build Pipeline

```bash
# 1. Generate parser from grammar
tree-sitter generate

# 2. Compile native bindings
node-gyp rebuild

# 3. Run tests
tree-sitter test

# 4. Package for npm
npm pack
```

### Package Structure

```json
{
  "name": "tree-sitter-plantuml",
  "version": "1.0.0",
  "main": "bindings/node",
  "types": "bindings/node/index.d.ts",
  "files": [
    "grammar.js",
    "binding.gyp",
    "src/parser.c",
    "src/node-types.json",
    "queries/*.scm",
    "bindings/node/*"
  ],
  "tree-sitter": [{
    "scope": "source.plantuml",
    "file-types": ["puml", "plantuml", "pu"]
  }]
}
```

## Security Considerations

### Input Validation
- **Maximum file size**: Reject files >10MB to prevent DoS
- **Recursion depth**: Limit AST depth to prevent stack overflow
- **Timeout**: Abort parsing after 30 seconds

### Memory Safety
- **C parser**: Generated code is memory-safe (no manual memory management)
- **Fuzzing**: Test with malformed input using AFL or libFuzzer
- **Sanitizers**: Build with AddressSanitizer and UndefinedBehaviorSanitizer

---

**Next**: See [Grammar Specification](../grammar/README.md) for detailed grammar rules.
