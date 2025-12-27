# Integration Guide

Guide to integrating the PlantUML Parser into your applications.

## Installation

### npm

```bash
npm install tree-sitter-plantuml
```

### yarn

```bash
yarn add tree-sitter-plantuml
```

### pnpm

```bash
pnpm add tree-sitter-plantuml
```

---

## Quick Start

### Basic Usage

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser();

const source = `@startuml
start
:Process data;
if (valid) then (yes)
  :Accept;
else (no)
  :Reject;
endif
stop
@enduml`;

const { tree, normalized, metadata } = parser.parse(source);

if (!tree.rootNode.hasError) {
  console.log('Parse successful!');
  console.log('Normalized:', normalized);
}
```

---

## Node.js Integration

### CommonJS

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');
const { PlantUMLNormalizer } = require('tree-sitter-plantuml');

const parser = new PlantUMLParser();
const normalizer = new PlantUMLNormalizer();
```

### ES Modules

```javascript
import PlantUMLParser, { PlantUMLNormalizer } from 'tree-sitter-plantuml';

const parser = new PlantUMLParser();
const normalizer = new PlantUMLNormalizer();
```

### TypeScript

```typescript
import PlantUMLParser, { PlantUMLNormalizer } from 'tree-sitter-plantuml';
import type { ParseResult, NormalizationResult } from 'tree-sitter-plantuml';

const parser = new PlantUMLParser();
const result: ParseResult = parser.parse(source);
```

---

## Use Cases

### 1. Syntax Validation

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function validatePlantUML(source) {
  const parser = new PlantUMLParser();
  const { tree } = parser.parse(source);

  if (tree.rootNode.hasError) {
    const errors = findErrors(tree.rootNode);
    return { valid: false, errors };
  }

  return { valid: true };
}

function findErrors(node) {
  const errors = [];

  if (node.type === 'ERROR') {
    errors.push({
      position: node.startPosition,
      text: node.text
    });
  }

  for (let child of node.children) {
    errors.push(...findErrors(child));
  }

  return errors;
}

// Usage
const result = validatePlantUML(`@startuml
:Process;
invalid syntax
@enduml`);

console.log(result);
// { valid: false, errors: [ { position: { row: 2, column: 0 }, text: 'invalid syntax' } ] }
```

---

### 2. Syntax Highlighting

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function getTokens(source) {
  const parser = new PlantUMLParser();
  const { tree } = parser.parse(source);

  const tokens = [];

  function walk(node) {
    if (node.isNamed) {
      tokens.push({
        type: node.type,
        text: node.text,
        start: node.startPosition,
        end: node.endPosition
      });
    }

    for (let child of node.children) {
      walk(child);
    }
  }

  walk(tree.rootNode);
  return tokens;
}

// Usage
const tokens = getTokens(`@startuml
:Process;
@enduml`);

console.log(tokens);
// [
//   { type: 'source_file', text: '...', ... },
//   { type: 'diagram', text: '...', ... },
//   { type: 'activity_node', text: ':Process;', ... },
//   ...
// ]
```

---

### 3. Code Navigation

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function findNodeAtPosition(source, line, column) {
  const parser = new PlantUMLParser();
  const { tree } = parser.parse(source);

  return tree.rootNode.descendantForPosition({ row: line, column });
}

// Usage
const source = `@startuml
start
:Process data;
stop
@enduml`;

const node = findNodeAtPosition(source, 2, 5);
console.log(node.type);        // 'activity_node'
console.log(node.text);        // ':Process data;'
```

---

### 4. Extracting Diagram Elements

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function extractActivityNodes(source) {
  const parser = new PlantUMLParser();
  const { tree } = parser.parse(source);

  const activities = [];

  function walk(node) {
    if (node.type === 'activity_node') {
      const label = node.childForFieldName('label');
      activities.push({
        label: label?.text || '',
        position: node.startPosition
      });
    }

    for (let child of node.children) {
      walk(child);
    }
  }

  walk(tree.rootNode);
  return activities;
}

// Usage
const activities = extractActivityNodes(`@startuml
:Step 1;
:Step 2;
:Step 3;
@enduml`);

console.log(activities);
// [
//   { label: 'Step 1', position: { row: 1, column: 0 } },
//   { label: 'Step 2', position: { row: 2, column: 0 } },
//   { label: 'Step 3', position: { row: 3, column: 0 } }
// ]
```

---

### 5. Code Formatting/Prettification

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function formatPlantUML(source) {
  const parser = new PlantUMLParser();

  // Normalization cleans up formatting
  const { normalized } = parser.normalize(source);

  return normalized;
}

// Usage
const messy = `@startuml
->   :   Label
if(condition)then(yes)
:Action;
endif
@enduml`;

const clean = formatPlantUML(messy);
console.log(clean);
// @startuml
// ->: Label
// if (condition) then (yes)
// :Action;
// endif
// @enduml
```

---

### 6. Diagram Analysis

```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

function analyzeDiagram(source) {
  const parser = new PlantUMLParser();
  const { tree } = parser.parse(source);

  const stats = {
    activityNodes: 0,
    decisionNodes: 0,
    loops: 0,
    partitions: 0
  };

  function walk(node) {
    switch (node.type) {
      case 'activity_node':
        stats.activityNodes++;
        break;
      case 'decision_node':
        stats.decisionNodes++;
        break;
      case 'while_loop':
      case 'repeat_loop':
        stats.loops++;
        break;
      case 'partition':
        stats.partitions++;
        break;
    }

    for (let child of node.children) {
      walk(child);
    }
  }

  walk(tree.rootNode);
  return stats;
}

// Usage
const stats = analyzeDiagram(`@startuml
partition "Module A" {
  :Task 1;
  if (check) then (yes)
    :Task 2;
  endif
}
@enduml`);

console.log(stats);
// { activityNodes: 2, decisionNodes: 1, loops: 0, partitions: 1 }
```

---

## Web Application Integration

### Client-Side (Browser)

Use the `tree-sitter-plantuml/wasm` entrypoint for browser/WASM usage. It dynamically imports `web-tree-sitter` (an optional peer dependency) and loads the shipped `tree-sitter-plantuml.wasm`.

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';

// Ensure the WASM file is publicly reachable (example: copy it to /public).
// Source file: node_modules/tree-sitter-plantuml/tree-sitter-plantuml.wasm
const parser = await createParser({ wasmPath: '/tree-sitter-plantuml.wasm' });

const source = `@startuml
:Process;
@enduml`;

const { tree, normalized, metadata } = parser.parse(source);
console.log('Root node:', tree.rootNode);
console.log('Normalized:', normalized);
console.log('Metadata:', metadata);
```

### Server-Side (Express)

```javascript
const express = require('express');
const PlantUMLParser = require('tree-sitter-plantuml');

const app = express();
app.use(express.json());

const parser = new PlantUMLParser();

app.post('/parse', (req, res) => {
  try {
    const { source } = req.body;
    const { tree, normalized, metadata } = parser.parse(source);

    if (tree.rootNode.hasError) {
      return res.status(400).json({
        error: 'Parse failed',
        hasError: true
      });
    }

    res.json({
      success: true,
      normalized,
      metadata,
      hasError: false
    });
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

app.listen(3000, () => {
  console.log('Parser API running on port 3000');
});
```

---

## CLI Tool Integration

### Simple CLI

```javascript
#!/usr/bin/env node
const fs = require('fs');
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser();
const filePath = process.argv[2];

if (!filePath) {
  console.error('Usage: parse-plantuml <file.puml>');
  process.exit(1);
}

const source = fs.readFileSync(filePath, 'utf-8');
const { tree, normalized, metadata } = parser.parse(source);

if (tree.rootNode.hasError) {
  console.error('Parse failed!');
  process.exit(1);
}

console.log('Parse successful!');
console.log('Stats:', metadata);
```

Usage:
```bash
./parse-plantuml.js diagram.puml
```

---

## Testing Integration

### Jest

```javascript
// __tests__/parser.test.js
const PlantUMLParser = require('tree-sitter-plantuml');

describe('PlantUML Parser', () => {
  let parser;

  beforeEach(() => {
    parser = new PlantUMLParser();
  });

  test('parses valid diagram', () => {
    const source = `@startuml
:Process;
@enduml`;

    const { tree } = parser.parse(source);
    expect(tree.rootNode.hasError).toBe(false);
  });

  test('detects invalid syntax', () => {
    const source = `@startuml
invalid syntax
@enduml`;

    const { tree } = parser.parse(source);
    expect(tree.rootNode.hasError).toBe(true);
  });
});
```

### Mocha

```javascript
const assert = require('assert');
const PlantUMLParser = require('tree-sitter-plantuml');

describe('PlantUML Parser', () => {
  it('should parse valid diagram', () => {
    const parser = new PlantUMLParser();
    const { tree } = parser.parse(`@startuml\n:Process;\n@enduml`);

    assert.strictEqual(tree.rootNode.hasError, false);
  });
});
```

---

## Future Integrations

### VSCode Extension (Planned)

```typescript
// src/extension.ts
import * as vscode from 'vscode';
import PlantUMLParser from 'tree-sitter-plantuml';

export function activate(context: vscode.ExtensionContext) {
  const parser = new PlantUMLParser();

  // Syntax highlighting
  const highlightProvider = vscode.languages.registerDocumentSemanticTokensProvider(
    { language: 'plantuml' },
    new PlantUMLHighlightProvider(parser)
  );

  // Diagnostics
  const diagnosticCollection = vscode.languages.createDiagnosticCollection('plantuml');

  context.subscriptions.push(highlightProvider, diagnosticCollection);
}
```

### Language Server Protocol (Planned)

```typescript
// src/server.ts
import {
  createConnection,
  TextDocuments,
  ProposedFeatures,
  InitializeParams,
  TextDocumentSyncKind
} from 'vscode-languageserver/node';

import { TextDocument } from 'vscode-languageserver-textdocument';
import PlantUMLParser from 'tree-sitter-plantuml';

const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);
const parser = new PlantUMLParser();

documents.onDidChangeContent(change => {
  const { tree } = parser.parse(change.document.getText());
  // Provide diagnostics, completions, etc.
});

connection.listen();
```

---

## Package Configuration

### package.json

```json
{
  "name": "tree-sitter-plantuml",
  "version": "2.1.0",
  "description": "Tree-sitter parser for PlantUML with two-pass architecture",
  "main": "./dist/index.cjs",
  "module": "./dist/index.mjs",
  "types": "./dist/index.d.ts",
  "exports": {
    ".": {
      "types": "./dist/index.d.ts",
      "import": "./dist/index.mjs",
      "require": "./dist/index.cjs"
    },
    "./wasm": {
      "types": "./dist/wasm.d.ts",
      "import": "./dist/wasm.mjs",
      "require": "./dist/wasm.cjs"
    },
    "./normalizer": {
      "types": "./dist/normalizer.d.ts",
      "import": "./dist/normalizer.mjs",
      "require": "./dist/normalizer.cjs"
    },
    "./tree-sitter-plantuml.wasm": "./tree-sitter-plantuml.wasm"
  },
  "keywords": [
    "tree-sitter",
    "parser",
    "plantuml",
    "uml",
    "diagram"
  ],
  "author": "PlantUML Parser Team",
  "license": "MIT",
  "repository": {
    "type": "git",
    "url": "https://github.com/SaeedNMosleh/PlantUML-Parser"
  },
  "scripts": {
    "generate": "tree-sitter generate",
    "build:all": "npm run generate && npm run build:native && npm run build:wasm && npm run build:js",
    "test": "npm run build:all && npm run test:normalizer && npm run test:parser",
    "test:all": "npm run validate && npm test && npm run test:integration"
  }
}
```

---

## Build from Source

### Prerequisites

```bash
# Install Node.js 18+
node --version

# Install tree-sitter CLI
npm install -g tree-sitter-cli

# Install build tools
npm install -g node-gyp
```

### Build Steps

```bash
# Clone repository
git clone https://github.com/SaeedNMosleh/PlantUML-Parser.git
cd PlantUML-Parser

# Install dependencies
npm install

# Generate parser
npm run generate

# Build native binding
npm run build:all

# Run tests
npm run test:all
```

---

## Troubleshooting

### Build Errors

**Problem**: `node-gyp rebuild` fails

**Solution**:
```bash
npm run clean
npm run rebuild
```

### Parser Not Loading

**Problem**: `Cannot find module 'tree-sitter-plantuml'`

**Solution**:
```bash
npm install
npm run build:all
```

### Tests Failing

**Problem**: Tests fail after changes

**Solution**:
```bash
npm run generate    # Regenerate parser
npm run test:all    # Run all tests
```

See [Troubleshooting Guide](./troubleshooting.md) for more issues.

---

## Related Documentation

- **[API Reference](./api-reference.md)** - Complete API documentation
- **[Architecture](./architecture.md)** - Two-pass parser design
- **[Testing Guide](./testing-guide.md)** - Testing strategies
- **[Troubleshooting](./troubleshooting.md)** - Common issues and solutions

---

**Status**: Phase 1 (Activity Diagrams) Complete ✅
**Version**: 2.1.0
**Last Updated**: 2025-12-27
