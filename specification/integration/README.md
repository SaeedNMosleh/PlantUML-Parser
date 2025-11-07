# Integration Specification

## Overview

This document defines how tree-sitter-plantuml integrates with various consumers including PlantEdit, Language Server Protocol implementations, IDE extensions, and other tools.

## Package Distribution

### npm Package Structure

```json
{
  "name": "tree-sitter-plantuml",
  "version": "1.0.0",
  "description": "Tree-sitter grammar for PlantUML",
  "main": "bindings/node",
  "types": "bindings/node/index.d.ts",
  "repository": {
    "type": "git",
    "url": "https://github.com/tree-sitter/tree-sitter-plantuml"
  },
  "keywords": [
    "tree-sitter",
    "parser",
    "plantuml",
    "uml",
    "diagram",
    "incremental"
  ],
  "author": "PlantUML Parser Team",
  "license": "MIT",
  "files": [
    "grammar.js",
    "binding.gyp",
    "bindings/node/*",
    "bindings/rust/*",
    "queries/*.scm",
    "src/parser.c",
    "src/scanner.c",
    "src/tree_sitter/*",
    "src/node-types.json"
  ],
  "dependencies": {
    "nan": "^2.17.0"
  },
  "devDependencies": {
    "tree-sitter-cli": "^0.20.0",
    "typescript": "^5.0.0",
    "@types/node": "^20.0.0"
  },
  "scripts": {
    "build": "tree-sitter generate && node-gyp rebuild",
    "test": "tree-sitter test",
    "parse": "tree-sitter parse"
  },
  "tree-sitter": [
    {
      "scope": "source.plantuml",
      "file-types": [
        "puml",
        "plantuml",
        "pu"
      ],
      "highlights": "queries/highlights.scm",
      "injections": "queries/injections.scm",
      "locals": "queries/locals.scm",
      "tags": "queries/tags.scm",
      "folds": "queries/folds.scm"
    }
  ]
}
```

### TypeScript Type Definitions

```typescript
// bindings/node/index.d.ts

declare module 'tree-sitter-plantuml' {
  import { Language } from 'tree-sitter';

  const language: Language;
  export default language;

  // Exported for convenience
  export interface DiagramType {
    ACTIVITY: 'activity';
    SEQUENCE: 'sequence';
    CLASS: 'class';
    STATE: 'state';
    COMPONENT: 'component';
    USECASE: 'usecase';
  }

  export interface PlantUMLNode {
    type: string;
    text: string;
    startPosition: { row: number; column: number };
    endPosition: { row: number; column: number };
    startIndex: number;
    endIndex: number;
    isNamed: boolean;
    isMissing: boolean;
    hasError: boolean;
  }

  // Utility functions
  export function detectDiagramType(source: string): DiagramType | null;
  export function extractClasses(tree: any): ClassInfo[];
  export function extractParticipants(tree: any): ParticipantInfo[];

  interface ClassInfo {
    name: string;
    position: { row: number; column: number };
    fields: FieldInfo[];
    methods: MethodInfo[];
  }

  interface FieldInfo {
    name: string;
    type: string;
    visibility: 'public' | 'private' | 'protected' | 'package';
  }

  interface MethodInfo {
    name: string;
    parameters: ParameterInfo[];
    returnType: string;
    visibility: 'public' | 'private' | 'protected' | 'package';
  }

  interface ParameterInfo {
    name: string;
    type: string;
  }

  interface ParticipantInfo {
    name: string;
    alias?: string;
    type: 'participant' | 'actor' | 'boundary' | 'control' | 'entity' | 'database';
  }
}
```

### Installation

```bash
# npm
npm install tree-sitter-plantuml

# yarn
yarn add tree-sitter-plantuml

# pnpm
pnpm add tree-sitter-plantuml
```

## PlantEdit Integration

### Architecture Overview

PlantEdit uses tree-sitter-plantuml for source code analysis and source mapping:

```
┌─────────────────────────────────────────┐
│            PlantEdit                     │
├─────────────────────────────────────────┤
│  Visual Editor Layer                    │
│  ↓ ↑                                    │
│  Domain Model Layer                     │
│  ↓ ↑                                    │
│  Source Mapping Layer ←──────────┐     │
│                                   │     │
└───────────────────────────────────│─────┘
                                    │
                           ┌────────┴─────────┐
                           │  tree-sitter-    │
                           │    plantuml      │
                           └──────────────────┘
```

### Integration Example

```typescript
// plantedit/src/parser/SourceMapper.ts

import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';
import { DiagramModel, Node, Edge } from './domain';

export class SourceMapper {
  private parser: Parser;
  private tree: Parser.Tree | null = null;
  private source: string = '';

  constructor() {
    this.parser = new Parser();
    this.parser.setLanguage(PlantUML);
  }

  /**
   * Parse PlantUML source and maintain tree for incremental updates
   */
  parse(source: string): void {
    this.source = source;
    this.tree = this.parser.parse(source, this.tree);
  }

  /**
   * Find AST node at specific line/column position
   */
  findNodeAt(line: number, column: number): Parser.SyntaxNode | null {
    if (!this.tree) return null;
    return this.tree.rootNode.descendantForPosition({
      row: line,
      column: column
    });
  }

  /**
   * Get source range for a domain model node
   */
  getSourceRange(nodeId: string): {
    start: { line: number; column: number };
    end: { line: number; column: number };
  } | null {
    // Implementation maps domain node ID to AST node position
    const astNode = this.findASTNodeById(nodeId);
    if (!astNode) return null;

    return {
      start: astNode.startPosition,
      end: astNode.endPosition
    };
  }

  /**
   * Update source code when domain model changes
   */
  updateSource(edit: SourceEdit): string {
    if (!this.tree) return this.source;

    // Apply edit to tree
    this.tree.edit({
      startIndex: edit.startIndex,
      oldEndIndex: edit.oldEndIndex,
      newEndIndex: edit.newEndIndex,
      startPosition: edit.startPosition,
      oldEndPosition: edit.oldEndPosition,
      newEndPosition: edit.newEndPosition
    });

    // Generate new source
    const newSource = applyEdit(this.source, edit);

    // Incremental re-parse
    this.tree = this.parser.parse(newSource, this.tree);
    this.source = newSource;

    return newSource;
  }

  /**
   * Extract all class definitions from source
   */
  extractClasses(): ClassInfo[] {
    if (!this.tree) return [];

    const query = this.parser.getLanguage().query(`
      (class_declaration
        name: (identifier) @class_name
        body: (class_body)? @body) @class
    `);

    const matches = query.matches(this.tree.rootNode);

    return matches.map(match => {
      const classNode = match.captures.find(c => c.name === 'class')?.node;
      const nameNode = match.captures.find(c => c.name === 'class_name')?.node;
      const bodyNode = match.captures.find(c => c.name === 'body')?.node;

      return {
        name: nameNode?.text || '',
        position: classNode?.startPosition || { row: 0, column: 0 },
        fields: this.extractFields(bodyNode),
        methods: this.extractMethods(bodyNode)
      };
    });
  }

  /**
   * Map visual element click to source code position
   */
  mapVisualToSource(elementId: string): {
    line: number;
    column: number;
  } | null {
    // Implementation depends on domain model structure
    const classes = this.extractClasses();
    const targetClass = classes.find(c => c.name === elementId);

    return targetClass ? {
      line: targetClass.position.row,
      column: targetClass.position.column
    } : null;
  }

  private extractFields(bodyNode: Parser.SyntaxNode | undefined): FieldInfo[] {
    if (!bodyNode) return [];

    const query = this.parser.getLanguage().query(`
      (field_declaration
        visibility: (visibility)? @vis
        name: (identifier) @field_name
        type: (type_reference)? @type)
    `);

    const matches = query.matches(bodyNode);

    return matches.map(match => ({
      name: match.captures.find(c => c.name === 'field_name')?.node.text || '',
      type: match.captures.find(c => c.name === 'type')?.node.text || '',
      visibility: this.parseVisibility(
        match.captures.find(c => c.name === 'vis')?.node.text
      )
    }));
  }

  private extractMethods(bodyNode: Parser.SyntaxNode | undefined): MethodInfo[] {
    // Similar to extractFields
    return [];
  }

  private parseVisibility(vis?: string): 'public' | 'private' | 'protected' | 'package' {
    switch (vis) {
      case '+': return 'public';
      case '-': return 'private';
      case '#': return 'protected';
      case '~': return 'package';
      default: return 'public';
    }
  }

  private findASTNodeById(nodeId: string): Parser.SyntaxNode | null {
    // Implementation maps domain node IDs to AST nodes
    // This requires maintaining a mapping between the two
    return null;
  }
}

interface SourceEdit {
  startIndex: number;
  oldEndIndex: number;
  newEndIndex: number;
  startPosition: { row: number; column: number };
  oldEndPosition: { row: number; column: number };
  newEndPosition: { row: number; column: number };
  newText: string;
}

function applyEdit(source: string, edit: SourceEdit): string {
  return source.slice(0, edit.startIndex) +
         edit.newText +
         source.slice(edit.oldEndIndex);
}
```

### Round-Trip Editing Example

```typescript
// Example: User renames a class in visual editor

// 1. User clicks "User" class and renames to "Customer"
const domainModel = loadDiagram();
const userClass = domainModel.nodes.find(n => n.name === 'User');

// 2. Update domain model
userClass.name = 'Customer';

// 3. Map change back to source
const sourceMapper = new SourceMapper();
sourceMapper.parse(originalSource);

const classPosition = sourceMapper.mapVisualToSource('User');
if (classPosition) {
  // Find exact position of "User" identifier
  const astNode = sourceMapper.findNodeAt(
    classPosition.line,
    classPosition.column
  );

  // Generate edit
  const edit: SourceEdit = {
    startIndex: astNode.startIndex,
    oldEndIndex: astNode.endIndex,
    newEndIndex: astNode.startIndex + 'Customer'.length,
    startPosition: astNode.startPosition,
    oldEndPosition: astNode.endPosition,
    newEndPosition: {
      row: astNode.endPosition.row,
      column: astNode.startPosition.column + 'Customer'.length
    },
    newText: 'Customer'
  };

  // Apply edit
  const newSource = sourceMapper.updateSource(edit);

  // Save updated source
  saveFile(newSource);
}
```

## Language Server Protocol Integration

### LSP Server Implementation

```typescript
// lsp-server/src/server.ts

import {
  createConnection,
  TextDocuments,
  Diagnostic,
  DiagnosticSeverity,
  ProposedFeatures,
  InitializeParams,
  DidChangeConfigurationNotification,
  CompletionItem,
  CompletionItemKind,
  TextDocumentPositionParams,
  TextDocumentSyncKind,
  InitializeResult
} from 'vscode-languageserver/node';

import { TextDocument } from 'vscode-languageserver-textdocument';
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

// Create connection and document manager
const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);

// Parser instance
const parser = new Parser();
parser.setLanguage(PlantUML);

// Cache parse trees per document
const trees = new Map<string, Parser.Tree>();

// Initialize server
connection.onInitialize((params: InitializeParams) => {
  const result: InitializeResult = {
    capabilities: {
      textDocumentSync: TextDocumentSyncKind.Incremental,
      completionProvider: {
        resolveProvider: true
      },
      hoverProvider: true,
      definitionProvider: true,
      referencesProvider: true,
      documentSymbolProvider: true,
      documentHighlightProvider: true,
      foldingRangeProvider: true,
      semanticTokensProvider: {
        legend: {
          tokenTypes: ['keyword', 'class', 'interface', 'method', 'variable'],
          tokenModifiers: ['declaration', 'definition', 'readonly', 'static']
        },
        full: true
      }
    }
  };
  return result;
});

// Parse document and provide diagnostics
documents.onDidChangeContent(change => {
  const document = change.document;
  const oldTree = trees.get(document.uri);

  // Parse with incremental update
  const newTree = parser.parse(document.getText(), oldTree);
  trees.set(document.uri, newTree);

  // Extract diagnostics from ERROR nodes
  const diagnostics = extractDiagnostics(newTree, document);

  connection.sendDiagnostics({
    uri: document.uri,
    diagnostics
  });
});

function extractDiagnostics(
  tree: Parser.Tree,
  document: TextDocument
): Diagnostic[] {
  const diagnostics: Diagnostic[] = [];

  // Query for ERROR nodes
  const query = parser.getLanguage().query('(ERROR) @error');
  const matches = query.matches(tree.rootNode);

  matches.forEach(match => {
    const errorNode = match.captures[0].node;

    diagnostics.push({
      severity: DiagnosticSeverity.Error,
      range: {
        start: {
          line: errorNode.startPosition.row,
          character: errorNode.startPosition.column
        },
        end: {
          line: errorNode.endPosition.row,
          character: errorNode.endPosition.column
        }
      },
      message: generateErrorMessage(errorNode, document),
      source: 'tree-sitter-plantuml'
    });
  });

  return diagnostics;
}

function generateErrorMessage(
  errorNode: Parser.SyntaxNode,
  document: TextDocument
): string {
  // Analyze error context
  const parent = errorNode.parent;
  const text = errorNode.text;

  if (parent?.type === 'class_body') {
    return `Syntax error in class body: unexpected '${text}'`;
  }

  if (parent?.type === 'diagram') {
    return `Invalid diagram element: '${text}'`;
  }

  return `Syntax error: unexpected '${text}'`;
}

// Provide code completion
connection.onCompletion(
  (params: TextDocumentPositionParams): CompletionItem[] => {
    const document = documents.get(params.textDocument.uri);
    if (!document) return [];

    const tree = trees.get(params.textDocument.uri);
    if (!tree) return [];

    // Find node at cursor position
    const node = tree.rootNode.descendantForPosition({
      row: params.position.line,
      column: params.position.character
    });

    // Provide context-aware completions
    return getCompletionsForContext(node);
  }
);

function getCompletionsForContext(node: Parser.SyntaxNode | null): CompletionItem[] {
  if (!node) return [];

  const completions: CompletionItem[] = [];

  // Inside diagram body
  if (node.type === 'diagram' || node.parent?.type === 'diagram') {
    completions.push(
      { label: 'class', kind: CompletionItemKind.Keyword },
      { label: 'interface', kind: CompletionItemKind.Keyword },
      { label: 'participant', kind: CompletionItemKind.Keyword },
      { label: 'state', kind: CompletionItemKind.Keyword }
    );
  }

  // Inside class body
  if (node.type === 'class_body' || node.parent?.type === 'class_body') {
    completions.push(
      { label: '+', kind: CompletionItemKind.Operator, detail: 'public' },
      { label: '-', kind: CompletionItemKind.Operator, detail: 'private' },
      { label: '#', kind: CompletionItemKind.Operator, detail: 'protected' },
      { label: '~', kind: CompletionItemKind.Operator, detail: 'package' }
    );
  }

  return completions;
}

// Provide hover information
connection.onHover(params => {
  const document = documents.get(params.textDocument.uri);
  if (!document) return null;

  const tree = trees.get(params.textDocument.uri);
  if (!tree) return null;

  const node = tree.rootNode.descendantForPosition({
    row: params.position.line,
    column: params.position.character
  });

  if (node?.type === 'class_declaration') {
    const className = node.childForFieldName('name')?.text || '';
    return {
      contents: {
        kind: 'markdown',
        value: `**Class**: \`${className}\`\n\nPosition: Line ${node.startPosition.row + 1}`
      }
    };
  }

  return null;
});

// Provide document symbols (outline)
connection.onDocumentSymbol(params => {
  const tree = trees.get(params.textDocument.uri);
  if (!tree) return [];

  const query = parser.getLanguage().query(`
    (class_declaration name: (identifier) @class_name) @class
    (interface_declaration name: (identifier) @interface_name) @interface
    (participant_declaration name: (identifier) @participant_name) @participant
  `);

  const matches = query.matches(tree.rootNode);

  return matches.map(match => {
    const node = match.captures[0].node;
    return {
      name: node.text,
      kind: getSymbolKind(node.parent?.type || ''),
      range: {
        start: { line: node.startPosition.row, character: node.startPosition.column },
        end: { line: node.endPosition.row, character: node.endPosition.column }
      },
      selectionRange: {
        start: { line: node.startPosition.row, character: node.startPosition.column },
        end: { line: node.endPosition.row, character: node.endPosition.column }
      }
    };
  });
});

function getSymbolKind(type: string): number {
  const SymbolKind = {
    Class: 5,
    Interface: 11,
    Method: 6,
    Field: 8
  };

  switch (type) {
    case 'class_declaration': return SymbolKind.Class;
    case 'interface_declaration': return SymbolKind.Interface;
    case 'method_declaration': return SymbolKind.Method;
    case 'field_declaration': return SymbolKind.Field;
    default: return 1; // File
  }
}

// Listen on the connection
documents.listen(connection);
connection.listen();
```

### VSCode Extension Integration

```typescript
// vscode-extension/src/extension.ts

import * as vscode from 'vscode';
import * as path from 'path';
import {
  LanguageClient,
  LanguageClientOptions,
  ServerOptions,
  TransportKind
} from 'vscode-languageclient/node';

let client: LanguageClient;

export function activate(context: vscode.ExtensionContext) {
  // Server options
  const serverModule = context.asAbsolutePath(
    path.join('server', 'out', 'server.js')
  );

  const serverOptions: ServerOptions = {
    run: { module: serverModule, transport: TransportKind.ipc },
    debug: {
      module: serverModule,
      transport: TransportKind.ipc,
      options: { execArgv: ['--nolazy', '--inspect=6009'] }
    }
  };

  // Client options
  const clientOptions: LanguageClientOptions = {
    documentSelector: [
      { scheme: 'file', language: 'plantuml' }
    ],
    synchronize: {
      fileEvents: vscode.workspace.createFileSystemWatcher('**/*.{puml,plantuml,pu}')
    }
  };

  // Create and start client
  client = new LanguageClient(
    'plantumlLanguageServer',
    'PlantUML Language Server',
    serverOptions,
    clientOptions
  );

  client.start();
}

export function deactivate(): Thenable<void> | undefined {
  if (!client) {
    return undefined;
  }
  return client.stop();
}
```

## CLI Tool Integration

### Standalone Parser CLI

```typescript
// cli/src/index.ts

import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';
import { readFileSync } from 'fs';
import { Command } from 'commander';

const program = new Command();

program
  .name('plantuml-parse')
  .description('Parse PlantUML files using tree-sitter')
  .version('1.0.0');

program
  .command('parse <file>')
  .description('Parse a PlantUML file and output AST')
  .option('-f, --format <format>', 'Output format (json|sexp)', 'sexp')
  .action((file, options) => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const source = readFileSync(file, 'utf-8');
    const tree = parser.parse(source);

    if (options.format === 'json') {
      console.log(JSON.stringify(treeToJSON(tree.rootNode), null, 2));
    } else {
      console.log(tree.rootNode.toString());
    }
  });

program
  .command('validate <file>')
  .description('Validate a PlantUML file for syntax errors')
  .action(file => {
    const parser = new Parser();
    parser.setLanguage(PlantUML);

    const source = readFileSync(file, 'utf-8');
    const tree = parser.parse(source);

    if (tree.rootNode.hasError) {
      const errors = findErrors(tree.rootNode);
      console.error(`Found ${errors.length} syntax errors:`);
      errors.forEach(err => {
        console.error(`  Line ${err.startPosition.row + 1}: ${err.text}`);
      });
      process.exit(1);
    } else {
      console.log('✓ No syntax errors');
    }
  });

program.parse();

function treeToJSON(node: Parser.SyntaxNode): any {
  const result: any = {
    type: node.type,
    text: node.text
  };

  if (node.childCount > 0) {
    result.children = [];
    for (let i = 0; i < node.childCount; i++) {
      result.children.push(treeToJSON(node.child(i)!));
    }
  }

  return result;
}

function findErrors(node: Parser.SyntaxNode): Parser.SyntaxNode[] {
  const errors: Parser.SyntaxNode[] = [];

  if (node.type === 'ERROR' || node.isMissing) {
    errors.push(node);
  }

  for (let i = 0; i < node.childCount; i++) {
    errors.push(...findErrors(node.child(i)!));
  }

  return errors;
}
```

## Build and Release Process

### Release Checklist

1. **Version Bump**
   ```bash
   npm version patch|minor|major
   ```

2. **Generate Parser**
   ```bash
   tree-sitter generate
   ```

3. **Run Tests**
   ```bash
   npm test
   npm run bench
   ```

4. **Build Native Bindings**
   ```bash
   npm install
   npm run build
   ```

5. **Publish to npm**
   ```bash
   npm publish
   ```

6. **Create GitHub Release**
   ```bash
   git tag v1.0.0
   git push origin v1.0.0
   ```

### Automated Release (GitHub Actions)

```yaml
# .github/workflows/release.yml
name: Release

on:
  push:
    tags:
      - 'v*'

jobs:
  publish:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - uses: actions/setup-node@v2
        with:
          node-version: '18'
          registry-url: 'https://registry.npmjs.org'

      - name: Install dependencies
        run: npm ci

      - name: Build
        run: npm run build

      - name: Test
        run: npm test

      - name: Publish to npm
        run: npm publish
        env:
          NODE_AUTH_TOKEN: ${{ secrets.NPM_TOKEN }}

      - name: Create GitHub Release
        uses: actions/create-release@v1
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
        with:
          tag_name: ${{ github.ref }}
          release_name: Release ${{ github.ref }}
          draft: false
          prerelease: false
```

---

**Summary**: This specification completes the integration guide for tree-sitter-plantuml, covering package distribution, PlantEdit integration, LSP implementation, and release processes.
