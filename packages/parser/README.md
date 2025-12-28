# tree-sitter-plantuml

High-performance PlantUML parser using tree-sitter with WASM-first architecture.

## Installation

```bash
npm install tree-sitter-plantuml
```

**Zero build tools required!** The package defaults to WebAssembly, which works out-of-the-box without compilation.

## Quick Start

```javascript
import { PlantUMLParser } from 'tree-sitter-plantuml';

const parser = new PlantUMLParser();
const result = parser.parse(`
@startuml
start
:Initialize system;
if (Ready?) then (yes)
  :Process data;
else (no)
  :Show error;
endif
stop
@enduml
`);

console.log(result.tree.rootNode.toString());
console.log(result.normalized);
```

## Features

- ✅ **WASM-first** - Zero build tools, works everywhere (Node.js, browsers)
- ✅ **Two-pass architecture** - Normalizer handles ambiguous syntax, tree-sitter parses
- ✅ **Activity diagrams** - Full support (Phase 1 complete)
- ✅ **TypeScript** - Full type definitions included
- ✅ **Incremental parsing** - Perfect for LSP servers
- ✅ **100% test coverage** - 136 tests passing

## Entry Points

### Default (WASM - Recommended)

```javascript
import { PlantUMLParser } from 'tree-sitter-plantuml';
```

- ✅ Zero compilation required
- ✅ Works in browsers and Node.js
- ✅ Cross-platform (no C compiler needed)

### Native Bindings (Opt-in)

```javascript
import { PlantUMLParser } from 'tree-sitter-plantuml/native';
```

- ~2x performance improvement
- Requires C compiler or prebuilt binaries
- Node.js only

### Normalizer Only

```javascript
import { PlantUMLNormalizer } from 'tree-sitter-plantuml/normalizer';

const normalizer = new PlantUMLNormalizer();
const { normalized } = normalizer.normalize(source);
```

- Lightweight (~10KB)
- No WASM loading
- Perfect for preprocessing

## Browser Usage

```javascript
import { createParser } from 'tree-sitter-plantuml/wasm';

const parser = await createParser({
  wasmPath: '/path/to/tree-sitter-plantuml.wasm'
});

const result = parser.parse(source);
```

## Architecture

```text
PlantUML Source → Normalizer (Pass 1) → tree-sitter Grammar (Pass 2) → AST
```

The two-pass architecture handles PlantUML's ambiguous syntax:
1. **Normalizer**: Transforms ambiguous PlantUML into unambiguous form
2. **Grammar**: Parses normalized PlantUML into AST

## API

### PlantUMLParser

```typescript
class PlantUMLParser {
  constructor(options?: {
    preserveComments?: boolean;
    preserveWhitespace?: boolean;
    skipNormalization?: boolean;
  });

  parse(source: string): {
    tree: Tree;
    normalized: string;
    metadata: NormalizationMetadata;
  };
}
```

### PlantUMLNormalizer

```typescript
class PlantUMLNormalizer {
  constructor(options?: {
    preserveComments?: boolean;
    preserveWhitespace?: boolean;
  });

  normalize(source: string): {
    normalized: string;
    metadata: NormalizationMetadata;
  };
}
```

## Supported Diagrams

- ✅ **Activity Diagrams** (Phase 1 - Complete)
- 🔄 **Sequence Diagrams** (Phase 2 - Planned)
- 🔄 **Class Diagrams** (Phase 3 - Planned)
- 🔄 **State Diagrams** (Phase 4 - Planned)

## Performance

- Initial parse (1,000 lines): ~50ms
- Incremental edit: <5ms (LSP mode)
- Memory overhead: ~10MB per 1,000 lines

## Documentation

- [Main Repository](../../README.md)
- [Architecture](../../specification/architecture.md)
- [API Reference](../../specification/api-reference.md)
- [Testing Guide](../../specification/testing-guide.md)
- [Roadmap](../../specification/ROADMAP.md)

## Monorepo

This package is part of the PlantUML Parser monorepo:

- **tree-sitter-plantuml** (this package) - Core parser
- **@plantuml/lsp** - Language Server Protocol (Phase 8)
- **vscode-plantuml** - VSCode extension (Phase 9)

See [monorepo-architecture.md](../../specification/monorepo-architecture.md) for details.

## Installation Scenarios

### Scenario 1: WASM (Default - Recommended)

```bash
npm install tree-sitter-plantuml
```

- ✅ Works everywhere
- ✅ No compilation
- ✅ No corporate proxy issues

### Scenario 2: Native Bindings (Opt-in)

```bash
npm install tree-sitter-plantuml
# Then use: import { PlantUMLParser } from 'tree-sitter-plantuml/native';
```

Native bindings are automatically built if you have a C compiler, or prebuilt binaries are used.

## Troubleshooting

### Installation hangs behind proxy

**Solution**: The default WASM mode doesn't require any downloads. Just install and use!

### Want native performance

**Solution**: Use `tree-sitter-plantuml/native` import path. If you don't have a C compiler, prebuilt binaries will be used.

### Browser bundle too large

**Solution**: Use `tree-sitter-plantuml/normalizer` for preprocessing without full parser.

## License

MIT

## Contributing

See [CONTRIBUTING.md](../../specification/CONTRIBUTING.md)
