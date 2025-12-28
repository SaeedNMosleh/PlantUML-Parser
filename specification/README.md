# PlantUML Parser Specification

Complete technical specification for the tree-sitter-plantuml parser implementing a two-pass architecture (Normalizer + Grammar) for handling PlantUML's ambiguous syntax.

## Quick Navigation

### Core Documentation
- **[Architecture](./architecture.md)** - Two-pass parser design and system overview
- **[Normalizer](./normalizer.md)** - Pass 1: Normalization rules and API
- **[Grammar](./grammar.md)** - Pass 2: Grammar specification for activity diagrams
- **[API Reference](./api-reference.md)** - Complete PlantUMLParser and Normalizer API

### Architecture Decisions

- **[Parser Technology Comparison](./parser-technology-comparison.md)** - Why tree-sitter over ANTLR and Peggy
- **[Monorepo Architecture](./monorepo-architecture.md)** - Repository organization strategy
- **[Packages](./packages.md)** - Package specifications (parser, LSP, VSCode)
- **[Installation Improvements](./installation-improvements.md)** - Zero-friction installation plan

### Development Guides
- **[Contributing](./CONTRIBUTING.md)** - Development principles and guidelines
- **[Testing Guide](./testing-guide.md)** - Testing strategy and corpus test format
- **[Troubleshooting](./troubleshooting.md)** - Common issues and solutions

### Planning & Integration

- **[Roadmap](./ROADMAP.md)** - Future diagram types and LSP tooling (Phases 2-11)
- **[Integration Guide](./integration-guide.md)** - npm package, VSCode, LSP integration
- **[Migration Guide](./migration-v1-to-v2.md)** - Upgrading from v1.x to v2.0

## Architecture Overview

```
┌─────────────────┐     ┌──────────────────┐     ┌─────────────┐
│ PlantUML Source │ --> │    Normalizer    │ --> │   Grammar   │ --> AST
│   (ambiguous)   │     │ (JavaScript/TS)  │     │(tree-sitter)│
└─────────────────┘     └──────────────────┘     └─────────────┘
                              Pass 1                   Pass 2
```

### Pass 1: Normalizer
- **Purpose**: Transform ambiguous PlantUML into unambiguous normalized form
- **Implementation**: Pure JavaScript (`src/normalizer/`)
- **Rules**: 7 transformation rules for activity diagrams
- **Output**: Clean, unambiguous PlantUML text

### Pass 2: Grammar
- **Purpose**: Parse normalized PlantUML into Abstract Syntax Tree
- **Implementation**: Tree-sitter grammar (`grammar.js`)
- **Features**: No external scanner, no conflicts, simple rules
- **Output**: Tree-sitter AST with full source locations

## Current Status

**Phase 1: Activity Diagrams** ✅ **Complete**

- **Test Success**: 100% (136/136 tests passing)
- **PlantUML Validation**: 100% (30/30 tests)
- **Grammar Tests**: 100% (30/30 tests)
- **Normalizer Tests**: 100% (59/59 tests)
- **Integration Tests**: 100% (17/17 tests)

**Phase 7: Monorepo Restructure** ⏳ **In Progress**

- **Documentation**: ✅ Complete (4 strategic decision documents)
- **Repository Structure**: 🔄 Planned (moving to packages/ layout)
- **Installation Improvements**: 🔄 Planned (WASM default, prebuilt binaries)

**Next**: Complete Phase 7, then Phase 2 - Sequence Diagrams

## Key Design Principles

1. **Zero Tolerance**: 100% test success rate required
2. **PlantUML is Truth**: All syntax validated against PlantUML server
3. **Normalizer Handles Complexity**: Grammar stays simple
4. **Two-Pass Separation**: Clear separation of concerns
5. **Integration First**: End-to-end tests are primary success metric

## Document Organization

### By Topic

**Architecture & Design:**
- [Architecture](./architecture.md)
- [Normalizer](./normalizer.md)
- [Grammar](./grammar.md)

**Strategic Decisions:**

- [Parser Technology Comparison](./parser-technology-comparison.md)
- [Monorepo Architecture](./monorepo-architecture.md)
- [Packages](./packages.md)
- [Installation Improvements](./installation-improvements.md)

**Usage & API:**
- [API Reference](./api-reference.md)
- [Integration Guide](./integration-guide.md)

**Development:**
- [Contributing](./CONTRIBUTING.md)
- [Testing Guide](./testing-guide.md)
- [Troubleshooting](./troubleshooting.md)

**Planning:**
- [Roadmap](./ROADMAP.md)
- [Migration Guide](./migration-v1-to-v2.md)

### By Audience

**For Users:**

- Start with [API Reference](./api-reference.md)
- Then [Integration Guide](./integration-guide.md)
- Check [Troubleshooting](./troubleshooting.md) if issues arise
- See [Installation Improvements](./installation-improvements.md) for installation help

**For Contributors:**

- Start with [Contributing](./CONTRIBUTING.md)
- Read [Architecture](./architecture.md)
- Review strategic decisions: [Parser Technology](./parser-technology-comparison.md), [Monorepo](./monorepo-architecture.md), [Packages](./packages.md)
- Follow [Testing Guide](./testing-guide.md)
- Check [Roadmap](./ROADMAP.md) for next features

**For Migrators:**

- Read [Migration Guide](./migration-v1-to-v2.md)
- Check [API Reference](./api-reference.md) for new API
- Review [Architecture](./architecture.md) for design changes

**For Architects:**

- Understand the technology choice: [Parser Technology Comparison](./parser-technology-comparison.md)
- Repository structure: [Monorepo Architecture](./monorepo-architecture.md)
- Package design: [Packages](./packages.md)
- Future roadmap: [Roadmap](./ROADMAP.md) (Phases 7-11 for LSP & tooling)

## Getting Help

- **Issues**: [GitHub Issues](https://github.com/SaeedNMosleh/PlantUML-Parser/issues)
- **Troubleshooting**: [troubleshooting.md](./troubleshooting.md)
- **Questions**: Open a discussion on GitHub

## Version Information

- **Current Version**: 2.1.0
- **Architecture**: Two-Pass (Normalizer + Grammar)
- **Status**: Phase 1 Complete
- **Last Updated**: 2025-12-27

---

**Main Repository**: [PlantUML-Parser](https://github.com/SaeedNMosleh/PlantUML-Parser)
