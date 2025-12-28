# @plantuml/lsp

> Language Server Protocol implementation for PlantUML

**Status**: 🔄 **Planned for Phase 8** (Weeks 18-21)

This package will provide a full-featured Language Server Protocol (LSP) implementation for PlantUML, enabling rich editor features in VSCode, Neovim, and other LSP-compatible editors.

## Planned Features

### Core LSP Capabilities

- **Diagnostics** - Real-time syntax error detection and semantic linting
- **Completion** - Intelligent auto-complete for keywords, symbols, and snippets
- **Hover** - Documentation and type information on hover
- **Go to Definition** - Jump to partition/swimlane/node definitions
- **Formatting** - Automatic code formatting with style preservation
- **Document Symbols** - Outline view and breadcrumb navigation

### Performance Targets

- Initial parse (10,000 lines): <100ms
- Incremental edit: <5ms
- Diagnostics: <20ms
- Completion: <10ms
- Formatting: <30ms

## Architecture

This package will use the [tree-sitter-plantuml](../parser/) parser with incremental caching for optimal performance:

```typescript
import { PlantUMLDocumentCache } from '@plantuml/lsp';
import { PlantUMLParser } from 'tree-sitter-plantuml';

const cache = new PlantUMLDocumentCache();
const tree = cache.getOrParse(uri, source, version);
// Incremental parsing automatically reuses unchanged nodes!
```

## Dependencies

- **tree-sitter-plantuml**: Core parser (workspace dependency)
- **vscode-languageserver**: LSP protocol implementation

## Roadmap

See [ROADMAP.md](../../specification/ROADMAP.md#phase-8-lsp-server-planned---weeks-18-21) for detailed implementation plan.

## Package Size

Target: ~629KB (including parser + incremental caching)

## Documentation

For full technical specifications, see:
- [packages.md](../../specification/packages.md#package-2-plantuml-lsp-language-server)
- [monorepo-architecture.md](../../specification/monorepo-architecture.md)

---

**Current Focus**: Phase 7 (Monorepo Restructure) in progress
**Next**: Phase 2 (Sequence Diagrams), then Phase 8 (LSP Server)
