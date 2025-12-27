# API Reference

Complete API documentation for the PlantUML Parser.

## Table of Contents

- [PlantUMLParser](#plantumlparser) - Main parser class
- [PlantUMLNormalizer](#plantum lnormalizer) - Normalization engine
- [Usage Examples](#usage-examples)
- [Type Definitions](#type-definitions)

---

## PlantUMLParser

Main parser class that combines normalization (Pass 1) and parsing (Pass 2).

### Constructor

```javascript
new PlantUMLParser(options?)
```

**Parameters:**
- `options` (Object, optional): Configuration options
  - `debug` (boolean): Enable debug mode. Default: `false`
  - `preserveComments` (boolean): Preserve comments in normalized output. Default: `true`
  - `preserveWhitespace` (boolean): Preserve original whitespace. Default: `false`
  - `skipNormalization` (boolean): Skip normalization pass. Default: `false`

**Returns:** PlantUMLParser instance

**Example:**
```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser({
  debug: false,
  preserveComments: true,
  preserveWhitespace: false,
  skipNormalization: false
});
```

---

### Methods

#### parse()

Parse PlantUML source code into an Abstract Syntax Tree.

```javascript
parser.parse(source, options?)
```

**Parameters:**
- `source` (string): PlantUML source code
- `options` (Object, optional):
  - `skipNormalization` (boolean): Skip normalization for this parse. Overrides constructor option.
  - `oldTree` (Tree): Previous parse tree for incremental parsing

**Returns:** Object
```typescript
{
  tree: Tree,              // Tree-sitter AST
  normalized?: string,     // Normalized source (if normalization enabled)
  metadata?: Object        // Normalization metadata (if normalization enabled)
}
```

**Example:**
```javascript
const source = `
@startuml
start
:Process;
if (condition) then (yes)
  :Action;
else (no)
  :Skip;
endif
stop
@enduml
`;

const result = parser.parse(source);

console.log('Has errors:', result.tree.rootNode.hasError);
console.log('Normalized:', result.normalized);
console.log('Metadata:', result.metadata);
```

---

#### parseNormalized()

Parse already-normalized PlantUML source (skip normalization step).

```javascript
parser.parseNormalized(source, options?)
```

**Parameters:**
- `source` (string): Normalized PlantUML source
- `options` (Object, optional):
  - `oldTree` (Tree): Previous parse tree for incremental parsing

**Returns:** Object
```typescript
{
  tree: Tree  // Tree-sitter AST
}
```

**Example:**
```javascript
const normalized = `@startuml
start
:Process;
stop
@enduml`;

const { tree } = parser.parseNormalized(normalized);
```

---

#### normalize()

Normalize PlantUML source without parsing.

```javascript
parser.normalize(source, overrides?)
```

**Parameters:**
- `source` (string): PlantUML source code
- `overrides` (Object, optional): Override normalizer options

**Returns:** Object
```typescript
{
  normalized: string,      // Normalized PlantUML
  metadata: Object         // Normalization metadata
}
```

**Example:**
```javascript
const result = parser.normalize(`
@startuml
->   :   Label
@enduml
`);

console.log(result.normalized);
// @startuml
// ->: Label
// @enduml

console.log(result.metadata);
// {
//   diagramType: 'activity',
//   nodeCount: 0,
//   hasCircleNodes: false,
//   circleNodeCount: 0,
//   sourceMap: { normalizedLineToOriginalLine: [/* ... */] }
// }
```

---

#### parseToJSON()

Parse source and convert AST to JSON.

```javascript
parser.parseToJSON(source, options?)
```

**Parameters:**
- `source` (string): PlantUML source code
- `options` (Object, optional): Same as `parse()`

**Returns:** Object - JSON representation of AST

**Example:**
```javascript
const json = parser.parseToJSON(`
@startuml
start
:Process;
stop
@enduml
`);

console.log(JSON.stringify(json, null, 2));
```

---

#### getLanguage()

Get the tree-sitter language object.

```javascript
parser.getLanguage()
```

**Returns:** Language - Tree-sitter language object

**Example:**
```javascript
const language = parser.getLanguage();
console.log(language.version);  // Grammar version
```

---

#### getParser()

Get the underlying tree-sitter parser instance.

```javascript
parser.getParser()
```

**Returns:** Parser - Tree-sitter Parser instance

**Example:**
```javascript
const tsParser = parser.getParser();
console.log(tsParser.getLanguage());
```

---

#### getNormalizer()

Get the normalizer instance.

```javascript
parser.getNormalizer()
```

**Returns:** PlantUMLNormalizer

**Example:**
```javascript
const normalizer = parser.getNormalizer();
const result = normalizer.normalize(source);
```

---

## PlantUMLNormalizer

Normalization engine that transforms ambiguous PlantUML into normalized form.

### Constructor

```javascript
new PlantUMLNormalizer(options?)
```

**Parameters:**
- `options` (Object, optional):
  - `debug` (boolean): Enable debug logging. Default: `false`
  - `preserveComments` (boolean): Keep comments in output. Default: `true`
  - `preserveWhitespace` (boolean): Keep original whitespace. Default: `false`

**Returns:** PlantUMLNormalizer instance

**Example:**
```javascript
const PlantUMLNormalizer = require('tree-sitter-plantuml').PlantUMLNormalizer;

const normalizer = new PlantUMLNormalizer({
  debug: false,
  preserveComments: true,
  preserveWhitespace: false
});
```

---

### Methods

#### normalize()

Normalize PlantUML source code.

```javascript
normalizer.normalize(source)
```

**Parameters:**
- `source` (string): Raw PlantUML source

**Returns:** Object
```typescript
{
  normalized: string,      // Normalized PlantUML
  metadata: Object         // Normalization metadata
}
```

**Metadata Fields:**
- `diagramType` (string | null): Detected diagram type (best-effort)
- `nodeCount` (number): Count of certain normalized nodes (best-effort)
- `hasCircleNodes` (boolean): Whether `(*)` appeared in the diagram
- `circleNodeCount` (number): Number of `(*)` occurrences
- `sourceMap` (object): Mapping from normalized lines back to original lines

**Example:**
```javascript
const source = `@startuml
->      :    Label with spaces
@enduml`;

const { normalized, metadata } = normalizer.normalize(source);

console.log(normalized);
// @startuml
// ->: Label with spaces
// @enduml

console.log(metadata);
// {
//   diagramType: 'activity',
//   nodeCount: 0,
//   hasCircleNodes: false,
//   circleNodeCount: 0,
//   sourceMap: { normalizedLineToOriginalLine: [/* ... */] }
// }
```

---

## Usage Examples

### Basic Parsing

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser();
const source = `
@startuml
start
:Hello World;
stop
@enduml
`;

const { tree, normalized } = parser.parse(source);

if (!tree.rootNode.hasError) {
  console.log('Parse successful!');
  console.log('Normalized source:', normalized);
} else {
  console.error('Parse failed');
}
```

---

### Error Handling

```javascript
const source = `@startuml
start
invalid syntax here
:Process;
stop
@enduml`;

const { tree } = parser.parse(source);

// Check for errors
if (tree.rootNode.hasError) {
  // Find ERROR nodes
  const findErrors = (node) => {
    if (node.type === 'ERROR') {
      console.error(`Error at line ${node.startPosition.row}:${node.startPosition.column}`);
      console.error(`Invalid syntax: ${node.text}`);
    }
    for (let child of node.children) {
      findErrors(child);
    }
  };

  findErrors(tree.rootNode);
}
```

---

### Incremental Parsing

```javascript
// Initial parse
const source1 = `@startuml
start
:Process;
stop
@enduml`;

const result1 = parser.parse(source1);

// Edit document
const source2 = `@startuml
start
:Modified Process;
stop
@enduml`;

// Incremental parse (faster - only re-parses changed subtree)
const result2 = parser.parse(source2, { oldTree: result1.tree });

console.log('Parse successful:', !result2.tree.rootNode.hasError);
```

---

### Normalization Only

```javascript
const source = `@startuml
->   :   Label
if(condition)then(yes)
:Action;
endif
@enduml`;

const { normalized, metadata } = parser.normalize(source);

console.log('Normalized:');
console.log(normalized);
// @startuml
// ->: Label
// if (condition) then (yes)
// :Action;
// endif
// @enduml

console.log('Diagram type:', metadata.diagramType);
console.log('Source map:', metadata.sourceMap);
```

---

### Walking the AST

```javascript
const { tree } = parser.parse(source);

function walk(node, indent = 0) {
  const prefix = '  '.repeat(indent);
  console.log(`${prefix}${node.type} [${node.startPosition.row}:${node.startPosition.column}]`);

  for (let child of node.namedChildren) {
    walk(child, indent + 1);
  }
}

walk(tree.rootNode);
```

---

### Finding Specific Nodes

```javascript
const { tree } = parser.parse(source);

// Find all activity nodes
function findActivityNodes(node) {
  const results = [];

  if (node.type === 'activity_node') {
    const label = node.childForFieldName('label');
    results.push({
      label: label?.text,
      position: node.startPosition
    });
  }

  for (let child of node.children) {
    results.push(...findActivityNodes(child));
  }

  return results;
}

const activities = findActivityNodes(tree.rootNode);
console.log('Activity nodes:', activities);
// [
//   { label: 'Process', position: { row: 2, column: 0 } },
//   { label: 'Action', position: { row: 4, column: 2 } }
// ]
```

---

### Custom Parser Options

```javascript
// Configure normalization behavior at construction time
const parser = new PlantUMLParser({
  preserveComments: false,
  preserveWhitespace: true
});

const result = parser.parse(source);
```

---

## Type Definitions

### Tree

Tree-sitter syntax tree.

```typescript
interface Tree {
  rootNode: SyntaxNode;
  edit(edit: Edit): void;
}
```

### SyntaxNode

Individual node in the syntax tree.

```typescript
interface SyntaxNode {
  type: string;
  text: string;
  startPosition: Point;
  endPosition: Point;
  startIndex: number;
  endIndex: number;
  children: SyntaxNode[];
  namedChildren: SyntaxNode[];
  childCount: number;
  namedChildCount: number;
  hasError: boolean;
  isNamed: boolean;
  isMissing: boolean;
  parent: SyntaxNode | null;

  child(index: number): SyntaxNode | null;
  namedChild(index: number): SyntaxNode | null;
  childForFieldName(name: string): SyntaxNode | null;
  descendantsOfType(type: string): SyntaxNode[];
}
```

### Point

Position in source code.

```typescript
interface Point {
  row: number;     // Line number (0-indexed)
  column: number;  // Column number (0-indexed)
}
```

### Edit

Edit operation for incremental parsing.

```typescript
interface Edit {
  startIndex: number;
  oldEndIndex: number;
  newEndIndex: number;
  startPosition: Point;
  oldEndPosition: Point;
  newEndPosition: Point;
}
```

### ParseOptions

Options for parsing.

```typescript
interface ParseOptions {
  skipNormalization?: boolean;
  oldTree?: Tree;
}
```

### ParserInitOptions

Options for the parser constructor (`new PlantUMLParser(options)`).

```typescript
interface ParserInitOptions {
  debug?: boolean;
  preserveComments?: boolean;
  preserveWhitespace?: boolean;
  skipNormalization?: boolean;
}
```

### NormalizerOptions

Options for the normalizer constructor (`new PlantUMLNormalizer(options)`).

```typescript
interface NormalizerOptions {
  debug?: boolean;
  preserveComments?: boolean;
  preserveWhitespace?: boolean;
}
```

### NormalizationResult

Result of normalization.

```typescript
interface NormalizationResult {
  normalized: string;
  metadata: {
    diagramType?: string | null;
    nodeCount?: number;
    hasCircleNodes?: boolean;
    circleNodeCount?: number;
    sourceMap?: {
      normalizedLineToOriginalLine: number[];
    };
  };
}
```

### ParseResult

Result of full parse (with normalization).

```typescript
interface ParseResult {
  tree: Tree;
  normalized?: string;     // Only if normalization enabled
  metadata?: {             // Only if normalization enabled
    diagramType?: string | null;
    nodeCount?: number;
    hasCircleNodes?: boolean;
    circleNodeCount?: number;
    sourceMap?: {
      normalizedLineToOriginalLine: number[];
    };
  };
}
```

---

## Node Type Reference

### Activity Diagram Nodes

| Node Type | Description | Fields |
|-----------|-------------|--------|
| `source_file` | Root node | - |
| `diagram` | PlantUML diagram | - |
| `startuml_directive` | `@startuml` directive | - |
| `enduml_directive` | `@enduml` directive | - |
| `activity_element` | Wrapper for activity elements | - |
| `start_node` | Start node (`start`) | - |
| `stop_node` | Stop node (`stop`) | - |
| `activity_node` | Activity node (`:Label;`) | `label` |
| `flow_arrow` | Flow arrow (`->`, `-->`, etc.) | `type`, `label` (optional) |
| `decision_node` | If/then/else statement | `condition`, `true_label`, branches |
| `elseif_branch` | Elseif branch | `condition`, `label` |
| `else_branch` | Else branch | `label` |
| `while_loop` | While loop | `condition`, `label`, `end_label` |
| `repeat_loop` | Repeat-while loop | `condition`, `label` |
| `partition` | Partition | `name`, `color` (optional) |
| `swimlane` | Swimlane | `name` |
| `fork_node` | Fork node | - |
| `join_node` | Join node | - |
| `split_node` | Split node | - |
| `split_join_node` | Split join node | - |
| `title_directive` | Title directive | `content` |
| `skinparam_directive` | Skinparam directive | `parameter`, `value` |
| `note_directive` | Note directive | `position`, `content` |
| `detach` | Detach node | - |
| `kill` | Kill node | - |
| `line_comment` | Line comment (`'`) | - |
| `block_comment` | Block comment (`/' ... '/`) | - |

---

## Related Documentation

- **[Architecture](./architecture.md)** - Two-pass parser architecture
- **[Grammar](./grammar.md)** - Grammar specification
- **[Normalizer](./normalizer.md)** - Normalization rules
- **[Integration Guide](./integration-guide.md)** - Using the parser in applications
- **[Testing Guide](./testing-guide.md)** - Testing strategies

---

**Version**: 2.1.0
**Last Updated**: 2025-12-27
