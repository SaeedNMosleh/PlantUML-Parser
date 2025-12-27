# Package Specifications

## Overview

The PlantUML parser monorepo contains three packages, each serving distinct user needs:

1. **tree-sitter-plantuml** - Core parser library (minimal, reusable)
2. **@plantuml/lsp** - Language Server Protocol implementation (LSP features + incremental caching)
3. **vscode-plantuml** - VSCode extension (editor integration)

This document provides detailed specifications for each package.

---

## Package 1: tree-sitter-plantuml (Parser)

### Purpose

Provide a minimal, high-performance PlantUML parser that can be embedded in any JavaScript/TypeScript application.

### Scope

**Included:**
- ✅ PlantUML normalizer (Pass 1)
- ✅ Tree-sitter grammar parser (Pass 2)
- ✅ TypeScript type definitions
- ✅ Node.js native binding (via node-gyp-build)
- ✅ WebAssembly build (for browsers)
- ✅ Normalizer-only export (lightweight option)
- ✅ Tree-sitter query files (for syntax highlighting)

**Excluded:**
- ❌ LSP server features
- ❌ Incremental caching (LSP concern)
- ❌ Editor-specific integrations
- ❌ CLI tools
- ❌ Formatter implementation

### Target Users

1. **Library consumers** - Developers embedding parser in their apps
2. **Browser applications** - Web-based diagram tools
3. **Build tools** - Documentation generators, CI/CD validation
4. **Other parsers/tools** - Reusable parsing component

### Package Metadata

```json
{
  "name": "tree-sitter-plantuml",
  "version": "2.1.0",
  "description": "PlantUML parser for tree-sitter - Two-Pass Architecture with Browser Support",
  "keywords": ["tree-sitter", "plantuml", "parser", "uml", "diagram", "normalizer", "wasm"],
  "license": "MIT",
  "repository": {
    "type": "git",
    "url": "https://github.com/SaeedNMosleh/PlantUML-Parser",
    "directory": "packages/parser"
  }
}
```

### Exports Configuration

**Entry Points:**

```json
{
  "main": "./dist/wasm.cjs",
  "module": "./dist/wasm.mjs",
  "types": "./dist/wasm.d.ts",
  "exports": {
    ".": {
      "types": "./dist/wasm.d.ts",
      "import": "./dist/wasm.mjs",
      "require": "./dist/wasm.cjs"
    },
    "./native": {
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
    "./tree-sitter-plantuml.wasm": "./tree-sitter-plantuml.wasm",
    "./queries/*": "./queries/*"
  }
}
```

**Design Decision:** WASM is the default export (not native) to ensure zero-friction installation.

### Dependencies

**Production Dependencies:**
```json
{
  "dependencies": {
    "node-addon-api": "^7.0.0",
    "node-gyp-build": "^4.6.0",
    "tree-sitter": "^0.20.6"
  }
}
```

**Peer Dependencies:**
```json
{
  "peerDependencies": {
    "web-tree-sitter": "^0.20.0 || ^0.21.0 || ^0.22.0"
  },
  "peerDependenciesMeta": {
    "web-tree-sitter": {
      "optional": true
    }
  }
}
```

**Optional Dependencies:**
```json
{
  "optionalDependencies": {
    "tree-sitter-cli": "^0.20.8"
  }
}
```

**Design Rationale:**
- `tree-sitter-cli` is optional (only needed for grammar development)
- `web-tree-sitter` is peer dependency (users bring their own version for browsers)
- Minimal dependencies keep package size down

### Size Constraints

**Target:** ~329KB (dist folder)

**Current:** 329KB ✅

**Breakdown:**
- TypeScript compiled output: ~50KB
- WASM binary: ~29KB
- Source maps: ~150KB (optional, dev-only)
- Type definitions: ~100KB

**Hard Limit:** 500KB (must stay under for library users)

### API Surface

#### Primary API: PlantUMLParser Class

```typescript
class PlantUMLParser {
  constructor(options?: ParseOptions);
  parse(source: string, options?: ParseOptions): ParseResult;
  parseNormalized(source: string, options?: ParseOptions): ParsedResult;
  normalize(source: string, options?: ParseOptions): NormalizationResult;
}
```

#### Types Exported

```typescript
export type ParseOptions = {
  preserveComments?: boolean;
  preserveWhitespace?: boolean;
  skipNormalization?: boolean;
  debug?: boolean;
  oldTree?: Tree;  // For incremental parsing
};

export type ParseResult = {
  tree: Tree;
  normalized: string;
  metadata: NormalizationMetadata;
};

export type NormalizationResult = {
  normalized: string;
  metadata: NormalizationMetadata;
  sourceMap: SourceMap;
};

export type NormalizationMetadata = {
  diagramType: 'activity' | 'sequence' | 'class' | 'unknown';
  nodeCount: number;
  hasCircleNodes: boolean;
  hasControlFlow: boolean;
  hasPartitions: boolean;
  hasSwimlanes: boolean;
  usesArrows: boolean;
};
```

#### Alternative Exports

**Normalizer Only:**
```typescript
import PlantUMLNormalizer from 'tree-sitter-plantuml/normalizer';

const normalizer = new PlantUMLNormalizer();
const { normalized, metadata } = normalizer.normalize(source);
```

**Native Binding (Opt-in):**
```typescript
import PlantUMLParser from 'tree-sitter-plantuml/native';
// Faster but requires C compiler to install
```

**WASM (Default):**
```typescript
import { createParser } from 'tree-sitter-plantuml/wasm';
const parser = await createParser({ wasmPath: '/tree-sitter-plantuml.wasm' });
```

### Build Process

**Commands:**
```bash
npm run build:js        # TypeScript → dist/*.{cjs,mjs,d.ts}
npm run build:native    # node-gyp rebuild → build/Release/*.node
npm run build:wasm      # tree-sitter build-wasm → *.wasm
npm run build:all       # All of the above
```

**Build Order:**
1. Tree-sitter generates parser C code (`src/parser.c`)
2. node-gyp compiles native binding
3. Emscripten compiles WASM binary
4. TypeScript compiles to CJS/ESM
5. Type definitions generated

### Testing Strategy

**Test Suites:**
- Normalizer unit tests (59 tests)
- Grammar corpus tests (30 tests)
- Integration tests (17 tests)
- PlantUML validation tests (30 tests)

**Total:** 136 tests, 100% passing

**Test Command:**
```bash
npm test
# Runs: npm run test:normalizer && npm run test:parser && npm run test:integration
```

### Publishing Strategy

**Registry:** npm (https://www.npmjs.com/package/tree-sitter-plantuml)

**Versioning:** Semantic versioning (currently v2.1.0)

**Files Included:**
```json
{
  "files": [
    "grammar.js",
    "binding.gyp",
    "queries",
    "bindings/node/binding.cc",
    "src/parser.c",
    "src/node-types.json",
    "src/tree_sitter",
    "dist",
    "prebuilds",
    "*.wasm"
  ]
}
```

**Publish Process:**
```bash
cd packages/parser
npm run build:all
npm test
npm publish
```

### Installation Experience

**Target Experience:**
```bash
npm install tree-sitter-plantuml
# ✅ Installs in <10 seconds
# ✅ No C compiler required (WASM fallback)
# ✅ Works behind corporate proxies
# ✅ No manual WASM file copying (for Node.js)
```

**Advanced (Opt-in Native):**
```bash
npm install tree-sitter-plantuml/native
# Requires C compiler, Python
# 2-3x faster performance
```

---

## Package 2: @plantuml/lsp (Language Server)

### Purpose

Provide Language Server Protocol implementation for PlantUML with incremental caching for real-time editor features.

### Scope

**Included:**
- ✅ LSP server implementation (stdio, socket, IPC transports)
- ✅ Incremental document caching
- ✅ Diagnostics provider (linter)
- ✅ Completion provider (auto-complete)
- ✅ Hover provider (symbol information)
- ✅ Definition provider (go to definition)
- ✅ Formatting provider (code formatter)
- ✅ Symbol provider (outline, breadcrumbs)
- ✅ Workspace management (multi-file support)

**Excluded:**
- ❌ Editor-specific UI (VSCode extension responsibility)
- ❌ Syntax highlighting (handled by queries in parser package)
- ❌ Command-line interface (future @plantuml/cli package)

### Target Users

1. **VSCode extension** - Primary consumer
2. **Other editors** - Neovim, Emacs, Sublime Text (with LSP clients)
3. **IDE developers** - Building PlantUML support

### Package Metadata

```json
{
  "name": "@plantuml/lsp",
  "version": "0.1.0",
  "description": "Language Server Protocol implementation for PlantUML",
  "keywords": ["lsp", "language-server", "plantuml", "language-server-protocol"],
  "license": "MIT",
  "repository": {
    "type": "git",
    "url": "https://github.com/SaeedNMosleh/PlantUML-Parser",
    "directory": "packages/lsp"
  }
}
```

### Exports Configuration

```json
{
  "main": "./dist/server.js",
  "types": "./dist/server.d.ts",
  "bin": {
    "plantuml-lsp": "./dist/server.js"
  },
  "exports": {
    ".": {
      "types": "./dist/server.d.ts",
      "import": "./dist/server.js",
      "require": "./dist/server.js"
    },
    "./cache": {
      "types": "./dist/cache.d.ts",
      "import": "./dist/cache.js"
    }
  }
}
```

### Dependencies

**Production Dependencies:**
```json
{
  "dependencies": {
    "tree-sitter-plantuml": "^2.1.0",
    "vscode-languageserver": "^9.0.1",
    "vscode-languageserver-textdocument": "^1.0.12"
  }
}
```

**Design Decision:**
- Depends on `tree-sitter-plantuml` parser (separation of concerns)
- Uses VSCode LSP libraries (industry standard, editor-agnostic despite name)

### Size Expectations

**Target:** ~300KB (server code) + 329KB (parser) = ~629KB total

**Acceptable Range:** 500KB - 800KB

**Breakdown:**
- LSP server implementation: ~200KB
- Incremental caching logic: ~50KB
- Feature providers: ~50KB
- Dependencies: vscode-languageserver (~196KB)

### Architecture

#### Server Entry Point

```typescript
// packages/lsp/src/server.ts
import { createConnection, TextDocuments, ProposedFeatures } from 'vscode-languageserver/node';
import { TextDocument } from 'vscode-languageserver-textdocument';
import { PlantUMLDocumentCache } from './cache';
import { DiagnosticsProvider } from './providers/diagnostics';
import { CompletionProvider } from './providers/completion';
// ... other providers

const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);
const cache = new PlantUMLDocumentCache();

connection.onInitialize((params) => {
  return {
    capabilities: {
      textDocumentSync: 1,
      completionProvider: { resolveProvider: true },
      hoverProvider: true,
      definitionProvider: true,
      documentFormattingProvider: true,
      documentSymbolProvider: true
    }
  };
});

documents.onDidChangeContent((change) => {
  const tree = cache.getOrParse(
    change.document.uri,
    change.document.getText(),
    change.document.version
  );

  // Provide diagnostics
  const diagnostics = DiagnosticsProvider.analyze(tree);
  connection.sendDiagnostics({ uri: change.document.uri, diagnostics });
});

connection.onCompletion((params) => {
  const tree = cache.get(params.textDocument.uri);
  return CompletionProvider.provide(tree, params.position);
});

// ... other handlers

documents.listen(connection);
connection.listen();
```

#### Incremental Caching

**File:** `packages/lsp/src/cache.ts`

```typescript
import type { Tree } from 'tree-sitter';
import PlantUMLParser from 'tree-sitter-plantuml';

interface CachedDocument {
  tree: Tree;
  version: number;
  source: string;
}

export class PlantUMLDocumentCache {
  private cache = new Map<string, CachedDocument>();
  private parser: PlantUMLParser;

  constructor() {
    this.parser = new PlantUMLParser();
  }

  /**
   * Get cached tree or parse with incremental updates
   */
  getOrParse(uri: string, source: string, version: number): Tree {
    const cached = this.cache.get(uri);

    // Cache hit with same version
    if (cached && cached.version === version) {
      return cached.tree;
    }

    // Incremental parse if source changed
    if (cached && cached.version < version) {
      const { tree } = this.parser.parse(source, {
        oldTree: cached.tree  // tree-sitter incremental parsing!
      });
      this.cache.set(uri, { tree, version, source });
      return tree;
    }

    // Full parse (new document)
    const { tree } = this.parser.parse(source);
    this.cache.set(uri, { tree, version, source });
    return tree;
  }

  get(uri: string): Tree | undefined {
    return this.cache.get(uri)?.tree;
  }

  invalidate(uri: string): void {
    this.cache.delete(uri);
  }

  clear(): void {
    this.cache.clear();
  }
}
```

**Key Feature:** This is where incremental parsing actually happens - LSP layer caches trees and passes `oldTree` to parser.

#### Feature Providers

**Diagnostics (Linter):**
```typescript
// packages/lsp/src/providers/diagnostics.ts
import type { Diagnostic, DiagnosticSeverity } from 'vscode-languageserver/node';
import type { Tree } from 'tree-sitter';

export class DiagnosticsProvider {
  static analyze(tree: Tree): Diagnostic[] {
    const diagnostics: Diagnostic[] = [];

    // Check for syntax errors
    if (tree.rootNode.hasError) {
      const errorNodes = this.findErrorNodes(tree.rootNode);
      for (const node of errorNodes) {
        diagnostics.push({
          severity: 1, // Error
          range: {
            start: { line: node.startPosition.row, character: node.startPosition.column },
            end: { line: node.endPosition.row, character: node.endPosition.column }
          },
          message: 'Syntax error',
          source: 'plantuml'
        });
      }
    }

    // Use tree-sitter queries for semantic linting
    const emptyLabelQuery = `
      (activity_node
        label: (activity_label) @label
        (#match? @label "^\\\\s*$"))
    `;
    // ... query execution and diagnostic creation

    return diagnostics;
  }
}
```

**Completion:**
```typescript
// packages/lsp/src/providers/completion.ts
export class CompletionProvider {
  static provide(tree: Tree, position: Position): CompletionItem[] {
    // Use tree-sitter queries to find symbols
    const symbolQuery = `
      [
        (partition name: (identifier) @symbol)
        (activity_node label: (activity_label) @symbol)
        (swimlane name: (identifier) @symbol)
      ]
    `;

    // Return completion items
    return symbols.map(symbol => ({
      label: symbol.text,
      kind: CompletionItemKind.Function,
      documentation: `PlantUML ${symbol.type}`
    }));
  }
}
```

### Performance Targets

- **Initial parse (1,000 lines):** <10ms
- **Initial parse (10,000 lines):** <100ms
- **Incremental edit:** <5ms
- **Diagnostics:** <20ms
- **Completion:** <10ms
- **Formatting:** <30ms

### Testing Strategy

**Test Suites:**
- LSP protocol tests (connection, initialization)
- Caching tests (incremental updates)
- Provider tests (diagnostics, completion, hover, etc.)
- Integration tests (full LSP workflow)

**Minimum:** 50 tests before v1.0.0

### Publishing Strategy

**Registry:** npm (https://www.npmjs.com/package/@plantuml/lsp)

**Versioning:**
- Start at v0.1.0 (beta)
- Reach v1.0.0 when all providers implemented and tested

**Binary:**
```bash
# Can be run standalone
npx @plantuml/lsp --stdio
npx @plantuml/lsp --socket=6009
```

---

## Package 3: vscode-plantuml (VSCode Extension)

### Purpose

Provide comprehensive PlantUML language support for Visual Studio Code.

### Scope

**Included:**
- ✅ LSP client (connects to @plantuml/lsp server)
- ✅ Syntax highlighting (tree-sitter queries)
- ✅ Language configuration (brackets, comments, etc.)
- ✅ Extension activation
- ✅ Configuration settings (user preferences)
- ✅ Status bar integration
- ✅ Command palette commands

**Future Additions:**
- 🔄 Diagram preview
- 🔄 Export to PNG/SVG
- 🔄 Snippet library

**Excluded:**
- ❌ Parser implementation (uses @plantuml/lsp)
- ❌ LSP server code (dependency)

### Target Users

1. **PlantUML developers** - Using VSCode for editing diagrams
2. **Documentation writers** - Embedding PlantUML in markdown
3. **Software architects** - Creating system diagrams

### Package Metadata

```json
{
  "name": "vscode-plantuml",
  "displayName": "PlantUML",
  "description": "PlantUML language support for Visual Studio Code",
  "version": "0.1.0",
  "publisher": "yourpublishername",
  "engines": {
    "vscode": "^1.80.0"
  },
  "categories": ["Programming Languages"],
  "keywords": ["plantuml", "uml", "diagram", "modeling"],
  "license": "MIT",
  "repository": {
    "type": "git",
    "url": "https://github.com/SaeedNMosleh/PlantUML-Parser",
    "directory": "packages/vscode-plantuml"
  }
}
```

### Extension Manifest

**File:** `packages/vscode-plantuml/package.json`

```json
{
  "activationEvents": [
    "onLanguage:plantuml"
  ],
  "main": "./dist/extension.js",
  "contributes": {
    "languages": [{
      "id": "plantuml",
      "aliases": ["PlantUML", "plantuml"],
      "extensions": [".puml", ".plantuml", ".pu", ".uml"],
      "configuration": "./language-configuration.json"
    }],
    "grammars": [{
      "language": "plantuml",
      "scopeName": "source.plantuml",
      "path": "./syntaxes/plantuml.tmLanguage.json"
    }],
    "configuration": {
      "title": "PlantUML",
      "properties": {
        "plantuml.lsp.enabled": {
          "type": "boolean",
          "default": true,
          "description": "Enable PlantUML language server"
        },
        "plantuml.diagnostics.enabled": {
          "type": "boolean",
          "default": true,
          "description": "Enable real-time diagnostics"
        },
        "plantuml.format.enabled": {
          "type": "boolean",
          "default": true,
          "description": "Enable automatic formatting"
        }
      }
    }
  }
}
```

### Dependencies

**Production Dependencies:**
```json
{
  "dependencies": {
    "@plantuml/lsp": "^0.1.0",
    "vscode-languageclient": "^9.0.1"
  },
  "devDependencies": {
    "@types/vscode": "^1.80.0",
    "@vscode/vsce": "^2.19.0"
  }
}
```

### Architecture

**File:** `packages/vscode-plantuml/src/extension.ts`

```typescript
import * as path from 'path';
import { workspace, ExtensionContext } from 'vscode';
import {
  LanguageClient,
  LanguageClientOptions,
  ServerOptions,
  TransportKind
} from 'vscode-languageclient/node';

let client: LanguageClient;

export function activate(context: ExtensionContext) {
  // Server options
  const serverModule = context.asAbsolutePath(
    path.join('node_modules', '@plantuml/lsp', 'dist', 'server.js')
  );

  const serverOptions: ServerOptions = {
    run: { module: serverModule, transport: TransportKind.ipc },
    debug: { module: serverModule, transport: TransportKind.ipc }
  };

  // Client options
  const clientOptions: LanguageClientOptions = {
    documentSelector: [{ scheme: 'file', language: 'plantuml' }],
    synchronize: {
      fileEvents: workspace.createFileSystemWatcher('**/*.{puml,plantuml,pu}')
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

### Size Expectations

**Target:** ~2MB (typical for VSCode extensions)

**Breakdown:**
- Extension code: ~100KB
- @plantuml/lsp dependency: ~629KB
- vscode-languageclient: ~200KB
- TextMate grammar: ~50KB
- Other assets: ~1MB (icons, snippets, etc.)

### Build Process

```bash
npm run compile       # TypeScript → dist/
npm run package       # vsce package → *.vsix
npm run publish       # vsce publish
```

### Testing Strategy

**Test Types:**
- Extension activation tests
- LSP client connection tests
- Command execution tests
- Configuration tests

**Minimum:** 20 tests before v1.0.0

### Publishing Strategy

**Marketplace:** Visual Studio Code Marketplace

**Publisher:** TBD (create publisher account)

**Installation:**
```bash
# From marketplace
code --install-extension yourpublisher.vscode-plantuml

# From VSIX
code --install-extension vscode-plantuml-0.1.0.vsix
```

**Versioning:**
- Start at v0.1.0 (beta)
- Reach v1.0.0 when LSP features stable

---

## Package Dependency Matrix

| Package | Depends On | Used By | Size |
|---------|-----------|---------|------|
| **tree-sitter-plantuml** | tree-sitter, node-addon-api | @plantuml/lsp, apps, tools | 329KB |
| **@plantuml/lsp** | tree-sitter-plantuml, vscode-languageserver | vscode-plantuml, other editors | 629KB |
| **vscode-plantuml** | @plantuml/lsp, vscode-languageclient | End users (VSCode) | 2MB |

**Key Insight:** Parser is minimal, consumed by many. Extension is large, consumed by VSCode users only.

---

## Cross-Package Coordination

### Versioning Strategy

**Independent Versioning (Lerna independent mode):**
- Parser: v2.1.0 (stable)
- LSP: v0.1.0 (experimental)
- Extension: v0.1.0 (experimental)

**When to bump versions:**
- Parser: Only for grammar changes, API changes, bug fixes
- LSP: For new LSP features, cache improvements
- Extension: For UI changes, new commands, settings

### Breaking Changes Policy

**Parser (tree-sitter-plantuml):**
- Major version bump for API changes
- Minor version for new features (backward compatible)
- Patch for bug fixes

**LSP (@plantuml/lsp):**
- Can be on v0.x.x until stable
- Major version bump when LSP protocol changes

**Extension (vscode-plantuml):**
- Can be on v0.x.x until stable
- Major version when significant UI changes

### Testing Matrix

| Test Scenario | Parser | LSP | Extension |
|---------------|--------|-----|-----------|
| Unit tests | ✅ 136 tests | ✅ TBD | ✅ TBD |
| Integration tests | ✅ 17 tests | ✅ TBD | ✅ TBD |
| Browser compatibility | ✅ WASM | ❌ N/A | ❌ N/A |
| LSP protocol compliance | ❌ N/A | ✅ TBD | ✅ TBD |
| VSCode activation | ❌ N/A | ❌ N/A | ✅ TBD |

---

## Summary

The three-package structure provides:

1. **tree-sitter-plantuml** - Minimal, reusable parser (329KB)
2. **@plantuml/lsp** - LSP server with caching (629KB)
3. **vscode-plantuml** - Full-featured extension (2MB)

**Benefits:**
- ✅ Library users get minimal package
- ✅ Editor users get full features
- ✅ Clear separation of concerns
- ✅ Independent versioning
- ✅ Easy to add future packages (CLI, formatter, transpiler)

---

**Version**: 2.1.0
**Status**: Specification Document
**Last Updated**: 2025-12-27
