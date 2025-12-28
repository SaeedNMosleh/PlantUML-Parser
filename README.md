# PlantUML Parser (tree-sitter-plantuml)

A high-performance [tree-sitter](https://tree-sitter.github.io/) parser for PlantUML using a **two-pass architecture** (Normalizer + Grammar) to handle PlantUML's ambiguous syntax.

## Monorepo Structure

This repository contains multiple packages for PlantUML tooling:

- **[packages/parser/](./packages/parser/)** - Core PlantUML parser (tree-sitter based) - ✅ **Phase 1 Complete**
- **[packages/lsp/](./packages/lsp/)** - Language Server Protocol implementation - 🔄 **Phase 8 Planned**
- **[packages/vscode-plantuml/](./packages/vscode-plantuml/)** - VSCode extension - 🔄 **Phase 9 Planned**

See [specification/monorepo-architecture.md](./specification/monorepo-architecture.md) for architecture details.

## At a Glance

```bash
npm install tree-sitter-plantuml
```

```javascript
import PlantUMLParser from 'tree-sitter-plantuml';

const parser = new PlantUMLParser();
const result = parser.parse('@startuml\nstart\n:Hello World;\nstop\n@enduml');
console.log(result.tree.rootNode.toString());
```

## Table of Contents

- [At a Glance](#at-a-glance)
- [Quick Start](#quick-start)
- [Status: Phase 1 Complete](#status-phase-1-complete-)
- [Features](#features)
- [Architecture](#architecture)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [From npm](#from-npm-when-published)
  - [Development Setup](#development-setup)
  - [Installation Troubleshooting](#installation-troubleshooting)
- [Usage](#usage)
  - [Parse PlantUML](#parse-plantuml)
  - [Normalize Only](#normalize-only)
  - [Parse Normalized Input](#parse-normalized-input)
- [Common Issues](#common-issues)
- [Browser Usage](#browser-usage)
  - [Setup Checklist](#setup-checklist)
  - [Quick Start (Browser)](#quick-start-browser)
  - [Usage with Module Bundlers](#usage-with-module-bundlers)
  - [Normalizer Only (Lightweight)](#normalizer-only-lightweight---no-wasm)
  - [TypeScript Support](#typescript-support)
- [Testing](#testing)
- [Development](#development)
- [Project Structure](#project-structure)
- [Documentation](#documentation)
- [Roadmap](#roadmap)
- [Performance](#performance)
- [Contributing](#contributing)
- [Integration](#integration)
- [Resources](#resources)
- [License](#license)

## Quick Start

```bash
# Install dependencies (monorepo)
# NOTE: This repo uses npm workspaces. Running `npm install` inside a package
# like `packages/parser` will still resolve the workspace root and install into
# the root `node_modules`.
npm install

# Build the parser package
npm --workspace packages/parser run build:all

# Run parser tests
npm --workspace packages/parser test
```

```javascript
// CommonJS
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser();
const source = `@startuml
start
:Initialize system;
if (Ready?) then (yes)
  :Process data;
else (no)
  :Show error;
endif
stop
@enduml`;

const result = parser.parse(source);
console.log('AST:', result.tree.rootNode.toString());
console.log('Normalized:', result.normalized);
```

```javascript
// ESM / TypeScript
import PlantUMLParser from 'tree-sitter-plantuml';

const parser = new PlantUMLParser();
const result = parser.parse(source);
console.log('AST:', result.tree.rootNode.toString());
```

## Status: Phase 1 Complete ✅

**100% Test Success Rate** - All 136 tests passing:
- ✅ 30/30 PlantUML validation tests (100%)
- ✅ 59/59 Normalizer tests (100%)
- ✅ 30/30 Grammar tests (100%)
- ✅ 17/17 Integration tests (100%)

**Activity Diagrams Fully Supported:**
- Basic activity nodes (`:label;`)
- Start and stop nodes (`start`, `stop`, `(*)`)
- Decision nodes (`if-then-else`, `elseif`)
- Loops (`while`, `repeat-while`)
- Partitions with colors
- Swimlanes (`|name|`)
- Fork and join nodes
- Flow arrows with labels
- Comments (line and block)
- Directives (`title`, `skinparam`)

**Next:** Phase 2 - Sequence Diagrams (planned)

## Features

- **Two-Pass Architecture**: Normalizer resolves ambiguities, Grammar parses clean syntax
- **100% Success Rate**: Zero-tolerance testing policy ensures reliability
- **Incremental Parsing**: Sub-millisecond updates for typical edits
- **Error Recovery**: Graceful handling of syntax errors
- **Lossless Parsing**: Preserves all source information
- **PlantUML Validated**: All test cases validated against PlantUML server

## Architecture

### Two-Pass Parser Design

```
┌─────────────────┐     ┌──────────────────┐     ┌─────────────┐
│ PlantUML Source │ --> │    Normalizer    │ --> │   Grammar   │ --> AST
│   (ambiguous)   │     │ (JavaScript/TS)  │     │(tree-sitter)│
└─────────────────┘     └──────────────────┘     └─────────────┘
                              Pass 1                   Pass 2
```

**Pass 1 - Normalizer**: Transforms ambiguous PlantUML into unambiguous normalized form
- Converts `(*)` to explicit `start`/`stop`
- Normalizes arrows, control flow, partitions
- Handles all PlantUML syntax variations
- Pure JavaScript, no external dependencies

**Pass 2 - Grammar**: Parses normalized PlantUML with simple tree-sitter grammar
- No external scanner needed
- No preprocessing markers
- Clean, conflict-free grammar rules

See [specification/architecture.md](./specification/architecture.md) for details.

## Installation

### Prerequisites

- Node.js 16+
- C compiler (gcc, clang, or MSVC)
- Python 3.x (for node-gyp)

### From npm (when published)

```bash
npm install tree-sitter-plantuml
```

### Development Setup

```bash
# Clone repository
git clone https://github.com/SaeedNMosleh/PlantUML-Parser.git
cd PlantUML-Parser

# Install dependencies (workspace root)
npm install

# Generate parser and build native bindings
npm --workspace packages/parser run build:all
```

### Installation Troubleshooting

**Issue: `npm install` or `npm ci` hangs during installation**

This is usually caused by the optional `tree-sitter-cli` dependency trying to download a binary from GitHub, which may fail behind corporate proxies or firewalls (e.g., Zscaler).

**Solutions:**

1. **Skip optional dependencies** (Recommended for users):
   ```bash
   npm ci --omit=optional
   # or
   npm install --no-optional
   ```

2. **Skip all install scripts**:
   ```bash
   npm ci --ignore-scripts
   ```

3. **Set proxy environment variables** (if behind a corporate proxy):
   ```bash
   # PowerShell (Windows)
   $env:HTTPS_PROXY = "http://your-proxy:port"
   $env:NODE_EXTRA_CA_CERTS = "C:\path\to\your\ca-cert.crt"
   npm install

   # Bash (Linux/Mac)
   export HTTPS_PROXY=http://your-proxy:port
   export NODE_EXTRA_CA_CERTS=/path/to/your/ca-cert.crt
   npm install
   ```

**Note:** The `tree-sitter-cli` is only needed for grammar development. End users and library consumers don't need it.

For more troubleshooting, see [specification/troubleshooting.md](./specification/troubleshooting.md).

## Usage

### Parse PlantUML

**CommonJS:**
```javascript
const PlantUMLParser = require('tree-sitter-plantuml');

const parser = new PlantUMLParser({
  preserveComments: true,
  preserveWhitespace: false
});

const result = parser.parse(source);
// result.tree - tree-sitter AST
// result.normalized - normalized PlantUML
// result.metadata - diagram metadata
```

**ESM / TypeScript:**
```typescript
import PlantUMLParser from 'tree-sitter-plantuml';
import type { ParseResult, ParseOptions } from 'tree-sitter-plantuml';

const options: ParseOptions = {
  preserveComments: true,
  preserveWhitespace: false
};

const parser = new PlantUMLParser(options);
const result: ParseResult = parser.parse(source);
```

### Normalize Only

```javascript
const { normalized, metadata } = parser.normalize(source);
console.log('Normalized PlantUML:', normalized);
console.log('Metadata:', metadata);
```

### Parse Normalized Input

```javascript
// Skip normalization if input is already normalized
const result = parser.parseNormalized(normalizedSource);
```

See [specification/api-reference.md](./specification/api-reference.md) for complete API documentation.

## Common Issues

### 1. Module Import/Export Errors

**Error: "Cannot use import statement outside a module"**

**Solutions:**
- Add `"type": "module"` to your package.json for ESM, or
- Use `.mjs` file extension for ES modules, or
- Use CommonJS `require()` instead

**Error: "require() of ES Module not supported"**

**Solution:**
- Use `import` instead of `require()` for ESM packages
- Check that your bundler/runtime supports the module format

### 2. TypeScript Type Resolution

**Error: "Cannot find module 'tree-sitter-plantuml' or its corresponding type declarations"**

**Solutions:**
- Ensure `tree-sitter-plantuml` is installed in `dependencies` (not devDependencies)
- Check that `dist/*.d.ts` files exist after installation
- Try: `npm install --no-optional` if installation was incomplete

### 3. Browser: WASM File Not Found

**Error: "Failed to fetch tree-sitter-plantuml.wasm"**

**Solutions:**
- Copy `node_modules/tree-sitter-plantuml/tree-sitter-plantuml.wasm` to your `public/` directory
- Configure your bundler (Vite/Webpack/Rollup) to include `.wasm` files as assets
- Check that the WASM file is being served with correct MIME type: `application/wasm`

### 4. node-gyp Build Failures

**Error: "gyp ERR! build error" or "Error: Could not find any native bindings"**

**Solutions:**
- Install build prerequisites:
  - **Windows**: `npm install --global windows-build-tools`
  - **Mac**: Install Xcode Command Line Tools: `xcode-select --install`
  - **Linux**: `sudo apt-get install build-essential` (Debian/Ubuntu)
- Use prebuilt binaries: `npm install --no-optional` (skips optional tree-sitter-cli)
- For browser-only usage: Use `tree-sitter-plantuml/wasm` entry point (no native binding needed)

### 5. Corporate Proxy/Firewall Issues

**Symptom: Installation hangs or times out**

See [Installation Troubleshooting](#installation-troubleshooting) above for proxy configuration.

**Need More Help?**

See the comprehensive [Troubleshooting Guide](./specification/troubleshooting.md) for detailed solutions to build issues, runtime errors, and performance problems.

## Browser Usage

The parser supports browser environments via **WebAssembly (WASM)**. The two-pass architecture makes it especially powerful for browsers:
- **Pass 1 (Normalizer)**: Pure JavaScript, runs natively in browsers (no WASM needed)
- **Pass 2 (Parser)**: Tree-sitter WASM for full parsing

### Setup Checklist

Before using the parser in the browser, ensure you have:

- [ ] Installed dependencies: `npm install tree-sitter-plantuml web-tree-sitter`
- [ ] Copied WASM file from `node_modules/tree-sitter-plantuml/tree-sitter-plantuml.wasm` to your `public/` directory
- [ ] Configured your bundler (Vite/Webpack/Rollup) to handle `.wasm` files (see bundler examples below)
- [ ] Verified WASM file is served with MIME type `application/wasm`

### Quick Start (Browser)

Use the `tree-sitter-plantuml/wasm` entrypoint in browsers. It dynamically imports `web-tree-sitter` (an optional peer dependency) and loads `tree-sitter-plantuml.wasm`.

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';

// Ensure the WASM file is publicly reachable (example: copy it to /public).
// Source file: node_modules/tree-sitter-plantuml/tree-sitter-plantuml.wasm
const parser = await createParser({ wasmPath: '/tree-sitter-plantuml.wasm' });

const source = `@startuml
start
:Task;
stop
@enduml`;

const result = parser.parse(source);
console.log('AST:', result.tree.rootNode.toString());
console.log('Normalized:', result.normalized);
```

### Installation for Browser Projects

```bash
npm install tree-sitter-plantuml web-tree-sitter
```

### Usage with Module Bundlers

#### Vite

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';
import wasmUrl from 'tree-sitter-plantuml/tree-sitter-plantuml.wasm?url';

// Initialize parser
const parser = await createParser({ wasmPath: wasmUrl });

// Parse PlantUML
const result = parser.parse(plantUMLSource);
```

**vite.config.js:**
```javascript
export default {
  assetsInclude: ['**/*.wasm']
}
```

#### Webpack

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';
import wasmUrl from 'tree-sitter-plantuml/tree-sitter-plantuml.wasm';

const parser = await createParser({ wasmPath: wasmUrl });
const result = parser.parse(source);
```

**webpack.config.js:**
```javascript
module.exports = {
  module: {
    rules: [
      {
        test: /\.wasm$/,
        type: 'asset/resource'
      }
    ]
  }
};
```

#### Rollup

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';

const parser = await createParser({
  wasmPath: '/path/to/tree-sitter-plantuml.wasm'
});
```

**rollup.config.js:**
```javascript
export default {
  plugins: [
    copy({
      targets: [
        {
          src: 'node_modules/tree-sitter-plantuml/*.wasm',
          dest: 'dist'
        }
      ]
    })
  ]
};
```

### Normalizer Only (Lightweight - No WASM)

If you only need normalization without full parsing (e.g., for preprocessing), you can use the normalizer standalone:

```javascript
import PlantUMLNormalizer from 'tree-sitter-plantuml/normalizer';

const normalizer = new PlantUMLNormalizer({
  preserveComments: true,
  preserveWhitespace: false
});

const source = `@startuml
(*)
:Task;
(*)
@enduml`;

const { normalized, metadata } = normalizer.normalize(source);
console.log('Normalized:', normalized);
// Output:
// @startuml
// start
// :Task;
// stop
// @enduml

console.log('Metadata:', metadata);
// { diagramType: 'activity', nodeCount: 3, hasCircleNodes: true, ... }
```

**Benefits:**
- No WASM loading (faster initialization)
- Smaller bundle size (~10KB vs ~30KB)
- Perfect for preprocessing pipelines

### API Reference (Browser)

#### createParser(options)

Convenience function to create and initialize parser in one step.

```javascript
const parser = await createParser({
  wasmPath: '/path/to/tree-sitter-plantuml.wasm',  // Required in some bundlers
  debug: false,                                      // Enable debug logging
  preserveComments: true,                           // Keep comments during normalization
  preserveWhitespace: false,                        // Preserve original whitespace
  skipNormalization: false                          // Skip normalization step
});
```

#### PlantUMLParserWasm

Manual initialization (for more control):

```javascript
import { PlantUMLParserWasm } from 'tree-sitter-plantuml/wasm';

const parser = await PlantUMLParserWasm.create({
  wasmPath: '/path/to/tree-sitter-plantuml.wasm'
});

const result = parser.parse(source);
```

### Important Notes

1. **WASM File Serving**: Ensure `.wasm` files are served with the correct MIME type:
   ```
   Content-Type: application/wasm
   ```

2. **Async Initialization**: Always `await` the parser initialization:
   ```javascript
   const parser = await createParser({ wasmPath });
   ```

3. **CORS**: If loading WASM from a CDN, ensure CORS headers are set correctly.

4. **Bundle Size**:
   - Full parser (WASM): ~30KB
   - Normalizer only: ~10KB
   - web-tree-sitter runtime: ~100KB

5. **Node.js vs Browser**:
   - Node.js: Use `require('tree-sitter-plantuml')` or `import` from `'tree-sitter-plantuml'` (native binding, faster - supports both CommonJS and ESM)
   - Browser: Use `import` from `'tree-sitter-plantuml/wasm'` (WebAssembly)

### TypeScript Support

Full TypeScript definitions are included:

```typescript
import { createParser, PlantUMLParserWasm, PlantUMLNormalizer } from 'tree-sitter-plantuml/wasm';
import type { ParseResult, NormalizationResult, ParserInitOptions } from 'tree-sitter-plantuml/wasm';

const options: ParserInitOptions = {
  debug: true
};

const parser: PlantUMLParserWasm = await createParser({
  wasmPath: '/tree-sitter-plantuml.wasm',
  ...options
});

const result: ParseResult = parser.parse(source);
```

### Building WASM Yourself

To rebuild the WASM file:

```bash
# Requires Docker or Emscripten
npm run build:wasm

# Or build both native and WASM
npm run build:all
```

The WASM file will be generated at `tree-sitter-plantuml.wasm` (~29KB).

## Testing

### Run All Tests with Validation

```bash
# Validate PlantUML syntax + run all tests
npm run test:100

# Individual test suites
npm run validate           # Validate against PlantUML server
npm run test:normalizer    # Normalizer unit tests
npm run test:parser        # Grammar corpus tests
npm run test:integration   # Full pipeline tests
```

### PlantUML Server for Validation

```bash
# Start PlantUML server with Docker
npm run docker:up

# Or manually with docker-compose
docker-compose up -d

# Validate all test cases
npm run validate
```

## Development

### Modify Grammar

1. Edit `grammar.js`
2. Regenerate parser: `npm run generate`
3. Rebuild (native + wasm + JS): `npm run build:all`
4. Run tests: `npm test`

### Add Tests

Create test cases in `test/corpus/activity/` following tree-sitter format:

```
===========================
Test name
===========================
@startuml
start
:Hello World;
stop
@enduml
----------------------------
(source_file
  (diagram
    (startuml_directive)
    (activity_element (start_node))
    (activity_element (activity_node label: (activity_label)))
    (activity_element (stop_node))
    (enduml_directive)))
```

See [specification/testing-guide.md](./specification/testing-guide.md) for testing strategy.

## Project Structure

```
PlantUML-Parser/                  # Monorepo root
├── packages/
│   ├── parser/                   # Core parser package (tree-sitter-plantuml)
│   │   ├── grammar.js            # Grammar definition
│   │   ├── dist/                 # Built JS/TS outputs (CJS + ESM + types)
│   │   │   ├── wasm.cjs/.mjs/.d.ts      # WASM entry (default)
│   │   │   ├── index.cjs/.mjs/.d.ts     # Node-native entry (`/native`)
│   │   │   └── normalizer.cjs/.mjs/.d.ts# Normalizer-only (`/normalizer`)
│   │   ├── src/
│   │   │   ├── core/             # Runtime-agnostic orchestrator
│   │   │   ├── normalizer/       # Normalizer (Pass 1)
│   │   │   ├── runtimes/         # Node-native + WASM backends
│   │   │   ├── parser.c          # Generated parser (Pass 2)
│   │   │   └── node-types.json   # Generated node types
│   │   ├── test/                 # All parser tests
│   │   ├── bindings/node/        # Node addon source
│   │   ├── prebuilds/            # Prebuilt native binaries
│   │   └── package.json          # Parser package metadata
│   ├── lsp/                      # LSP server (Phase 8 - Planned)
│   │   └── package.json          # @plantuml/lsp
│   └── vscode-plantuml/          # VSCode extension (Phase 9 - Planned)
│       └── package.json          # vscode-plantuml
├── specification/                # Complete documentation
├── package.json                  # Workspace root
├── pnpm-workspace.yaml           # pnpm workspace config
├── tsconfig.base.json            # Shared TypeScript config
└── jest.config.base.js           # Shared Jest config
```

## Documentation

- [Architecture](./specification/architecture.md) - Two-pass parser design
- [Normalizer](./specification/normalizer.md) - Normalization rules and API
- [Grammar](./specification/grammar.md) - Grammar specification
- [API Reference](./specification/api-reference.md) - Complete API documentation
- [Testing Guide](./specification/testing-guide.md) - Testing strategy
- [Contributing](./specification/CONTRIBUTING.md) - Development principles
- [Roadmap](./specification/ROADMAP.md) - Future diagram types
- [Troubleshooting](./specification/troubleshooting.md) - Common issues

## Roadmap

### ✅ Phase 1: Activity Diagrams (Complete)

- All activity diagram features supported
- 100% test success rate
- PlantUML validation passing

### ⏳ Phase 7: Monorepo Restructure (In Progress)

- Monorepo structure with 3 packages
- WASM-first installation (zero build tools)
- Prebuilt binaries via CI/CD
- See [ROADMAP.md](./specification/ROADMAP.md#phase-7-monorepo-restructure-planned---week-17)

### 🔄 Phase 2: Sequence Diagrams (Planned)

- Participants, messages, activation boxes
- Message groups (alt, opt, loop, etc.)
- Estimated: 4-6 weeks

### ⏳ Phase 3: Class Diagrams (Planned)
- Classes, interfaces, relationships
- Visibility modifiers, methods, fields
- Estimated: 4-6 weeks

### ⏳ Phase 4+: State, Component, Deployment, Use Case
See [specification/ROADMAP.md](./specification/ROADMAP.md) for complete roadmap.

## Performance

Tree-sitter provides excellent performance:
- **Initial parse**: <100ms for 10,000-line files
- **Incremental update**: <5ms for typical single-line edits
- **Memory overhead**: <10MB for 1,000-line documents

## Contributing

Contributions welcome! Please see [specification/CONTRIBUTING.md](./specification/CONTRIBUTING.md) for:
- Development principles (100% success rate policy)
- Code style guidelines
- Testing requirements
- Pull request process

**Priority Areas:**
- Phase 2: Sequence Diagrams
- Performance optimization
- Additional test cases
- Documentation improvements

## Integration

### VSCode Extension (Planned)
- Syntax highlighting with tree-sitter queries
- Code folding, symbol extraction
- LSP server integration

### Language Server Protocol (Planned)
- Real-time diagnostics
- Auto-completion
- Hover information

See [specification/integration-guide.md](./specification/integration-guide.md) for details.

## Resources

- [PlantUML Official Documentation](https://plantuml.com/)
- [Tree-sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Project Specification](./specification/README.md)
- [GitHub Issues](https://github.com/SaeedNMosleh/PlantUML-Parser/issues)

## License

MIT

## Links

- **Repository**: https://github.com/SaeedNMosleh/PlantUML-Parser
- **Issues**: https://github.com/SaeedNMosleh/PlantUML-Parser/issues
- **Documentation**: [specification/](./specification/)

---

**Version**: 2.1.0
**Status**: Phase 1 Complete - Activity Diagrams
**Last Updated**: 2025-12-27
