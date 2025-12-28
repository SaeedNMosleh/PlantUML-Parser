# vscode-plantuml

> VSCode extension for PlantUML with full LSP support

**Status**: 🔄 **Planned for Phase 9** (Weeks 22-24)

This package will provide a comprehensive VSCode extension for PlantUML with syntax highlighting, diagnostics, auto-completion, formatting, and other advanced editor features powered by the PlantUML Language Server.

## Planned Features

### Core Features (Phase 9)

- **Syntax Highlighting** - Tree-sitter based highlighting for accurate colorization
- **Real-time Diagnostics** - Syntax errors and semantic warnings as you type
- **Auto-completion** - Intelligent keyword, symbol, and snippet completion
- **Hover Information** - Documentation and type information on hover
- **Go to Definition** - Jump to partition/swimlane/node definitions
- **Format Document** - Automatic code formatting with style preservation
- **Outline View** - Document structure in sidebar and breadcrumbs

### Configuration Options

```json
{
  "plantuml.lsp.enable": true,
  "plantuml.diagnostics.enable": true,
  "plantuml.format.enable": true,
  "plantuml.format.indentSize": 2
}
```

### Future Enhancements (Post Phase 9)

- Diagram preview (live rendering)
- Export to PNG/SVG
- Snippet library
- Code actions (quick fixes)
- Refactoring support

## Architecture

```text
VSCode Extension (vscode-plantuml)
    ↓
LSP Client (vscode-languageclient)
    ↓
LSP Server (@plantuml/lsp)
    ↓
Parser (tree-sitter-plantuml)
```

## Dependencies

- **@plantuml/lsp**: Language Server implementation (workspace dependency)
- **vscode-languageclient**: VSCode LSP client library

## Installation (Future)

Once published to VSCode Marketplace:

1. Open VSCode
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "PlantUML Language Support"
4. Click Install

## Package Size

Target: ~2MB (includes extension + LSP client)

## Development

This extension will be developed after:
- ✅ Phase 1: Activity Diagrams (Complete)
- ⏳ Phase 7: Monorepo Restructure (In Progress)
- 🔄 Phase 2-6: Additional diagram types
- 🔄 Phase 8: LSP Server implementation

## Documentation

For full technical specifications, see:
- [packages.md](../../specification/packages.md#package-3-vscode-plantuml-vscode-extension)
- [ROADMAP.md](../../specification/ROADMAP.md#phase-9-vscode-extension-planned---weeks-22-24)
- [monorepo-architecture.md](../../specification/monorepo-architecture.md)

---

**Current Focus**: Phase 7 (Monorepo Restructure) in progress
**Next**: Phase 2 (Sequence Diagrams), then Phase 8 (LSP), then Phase 9 (VSCode Extension)
