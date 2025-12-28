# PlantUML Parser Development Roadmap

This document outlines the development plan for the tree-sitter-plantuml parser, organized by implementation phases.

## Diagram Type Support Status

### Phase 1: Foundation ✅ COMPLETED

**Activity Diagrams** - ✅ Fully Supported

- ✅ Basic activity nodes (`:label;`)
- ✅ Start and stop nodes (`start`, `stop`, `(*)`)
- ✅ Decision nodes (`if-then-else`, `elseif`)
- ✅ Loops (`while`, `repeat-while`)
- ✅ Partitions with colors
- ✅ Swimlanes (`|name|`)
- ✅ Fork and join nodes (`fork`, `split`, `end fork`, `end split`)
- ✅ Flow arrows with labels (`->`, `-->`)
- ✅ Detach statements
- ✅ Comments (line `'` and block `/' '/`)
- ✅ Common directives (`title`, `note`, `skinparam`)

**Status**: Phase 1 completed with 35+ corpus tests

---

### Phase 2: Interactions (Planned - Weeks 3-4)

**Sequence Diagrams** - ⏳ Not Yet Implemented

- ⬜ Participant declarations (`participant`, `actor`, `boundary`, `control`, `entity`, `database`)
- ⬜ Participant aliases (`as`)
- ⬜ Participant ordering (`order`)
- ⬜ Message arrows (synchronous, asynchronous, return)
- ⬜ Creation arrows (`->*`)
- ⬜ Destruction arrows (`->x`)
- ⬜ Activation boxes (`activate`, `deactivate`, `++`, `--`)
- ⬜ Message groups (`alt`, `opt`, `loop`, `par`, `break`, `critical`)
- ⬜ Message numbering
- ⬜ Delays (`...`)
- ⬜ Dividers (`==`)
- ⬜ References (`ref over`)
- ⬜ Notes on sequence diagrams

**Target**: 30+ corpus tests, 85%+ coverage

---

### Phase 3: Structure (Planned - Weeks 5-6)

**Class Diagrams** - ⬜ Not Yet Implemented

- ⬜ Class declarations
- ⬜ Interface declarations
- ⬜ Abstract classes
- ⬜ Enum declarations
- ⬜ Fields with visibility (`+`, `-`, `#`, `~`)
- ⬜ Methods with parameters and return types
- ⬜ Static and abstract modifiers (`{static}`, `{abstract}`)
- ⬜ Generics/type parameters (`<T>`)
- ⬜ Relationships:
  - ⬜ Extension/Inheritance (`<|--`, `--|>`)
  - ⬜ Composition (`*--`, `--*`)
  - ⬜ Aggregation (`o--`, `--o`)
  - ⬜ Association (`--`, `<--`, `-->`)
  - ⬜ Dependency (`<..`, `..>`)
  - ⬜ Realization (`<|..`, `..|>`)
- ⬜ Cardinality (`"1"`, `"*"`, `"0..*"`)
- ⬜ Packages
- ⬜ Namespaces
- ⬜ Annotations/Stereotypes

**Target**: 40+ corpus tests, 90%+ coverage

---

### Phase 4: State Machines (Planned - Weeks 7-8)

**State Diagrams** - ⬜ Not Yet Implemented

- ⬜ State declarations
- ⬜ State aliases
- ⬜ Initial state (`[*]`)
- ⬜ Final state (`[*]`)
- ⬜ Transitions with events and guards
- ⬜ Transition actions
- ⬜ Entry actions
- ⬜ Exit actions
- ⬜ Internal transitions
- ⬜ Composite states
- ⬜ Concurrent states (regions)
- ⬜ History states (shallow and deep)
- ⬜ Choice pseudo-states
- ⬜ Fork and join pseudo-states

**Target**: 30+ corpus tests, 90%+ coverage

---

### Phase 5: Extended Types (Planned - Weeks 9-12)

**Component Diagrams** - ⬜ Not Yet Implemented

- ⬜ Component declarations
- ⬜ Interface declarations
- ⬜ Ports
- ⬜ Component relationships
- ⬜ Packages for components
- ⬜ Stereotypes

**Deployment Diagrams** - ⬜ Not Yet Implemented

- ⬜ Node declarations
- ⬜ Artifact declarations
- ⬜ Deployment relationships
- ⬜ Stereotypes

**Use Case Diagrams** - ⬜ Not Yet Implemented

- ⬜ Actor declarations
- ⬜ Use case declarations
- ⬜ Use case relationships:
  - ⬜ Association
  - ⬜ Include (`<<include>>`)
  - ⬜ Extend (`<<extend>>`)
  - ⬜ Generalization
- ⬜ System boundaries (`rectangle`)

**Object Diagrams** - ⬜ Not Yet Implemented

- ⬜ Object declarations
- ⬜ Object fields with values
- ⬜ Object relationships

**Timing Diagrams** - ⬜ Not Yet Implemented

- ⬜ Robust timeline syntax
- ⬜ Concise timeline syntax
- ⬜ Clock notation
- ⬜ Timing constraints

**Target**: 20+ corpus tests per diagram type, 90%+ coverage

---

### Phase 6: Production Ready (Planned - Weeks 13-16)

**Quality & Performance** - ⬜ Not Yet Implemented

- ⬜ 100+ total corpus tests across all diagram types
- ⬜ 95%+ code coverage
- ⬜ Performance benchmarks:
  - ⬜ <100ms for 10K lines (initial parse)
  - ⬜ <5ms for single-line edit (incremental)
  - ⬜ <10MB memory overhead per 1K lines
- ⬜ Error recovery tests for all diagram types
- ⬜ Real-world example tests

**Documentation** - ⬜ Not Yet Implemented

- ⬜ Complete API documentation
- ⬜ Integration guides for:
  - ⬜ VSCode extensions
  - ⬜ Language Server Protocol
  - ⬜ PlantEdit integration
  - ⬜ Custom editor integration
- ⬜ Grammar authoring guide
- ⬜ Contributing guidelines
- ⬜ Architecture documentation

**Release** - ⬜ Not Yet Implemented

- ⬜ npm package v1.0.0
- ⬜ GitHub release with binaries
- ⬜ Documentation website
- ⬜ Example projects
- ⬜ Migration guide from other parsers

---

## LSP & Tooling Milestones

### Phase 7: Monorepo Restructure (Planned - Week 17)

**Repository Organization** - ⏳ In Progress

- ⏳ Create monorepo structure with `packages/` directory
- ⏳ Move parser to `packages/parser/`
- ⏳ Setup workspace configuration (pnpm workspaces)
- ⏳ Create placeholder `packages/lsp/` structure
- ⏳ Create placeholder `packages/vscode-plantuml/` structure
- ⏳ Update documentation for monorepo architecture
- ⏳ Test that all 136 tests still pass after restructure

**Installation Improvements** - ⏳ In Progress

- ⏳ Make WASM the default export (zero build tools required)
- ⏳ Setup prebuild CI/CD for native binaries
- ⏳ Move `tree-sitter-cli` to devDependencies
- ⏳ Create postinstall script with helpful messages
- ⏳ Update README with installation scenarios
- ⏳ Test installation on Windows, macOS, Linux

**Target**: Parser package stays at ~329KB, zero-friction installation

See [installation-improvements.md](./installation-improvements.md) and [monorepo-architecture.md](./monorepo-architecture.md).

---

### Phase 8: LSP Server (Planned - Weeks 18-21)

**Core LSP Implementation** - ⬜ Not Yet Implemented

- ⬜ LSP server initialization (stdio, socket, IPC transports)
- ⬜ Document synchronization protocol
- ⬜ Incremental document caching
- ⬜ Configuration management
- ⬜ Workspace folder support

**Language Features** - ⬜ Not Yet Implemented

- ⬜ **Diagnostics** (Linter)
  - ⬜ Syntax error detection
  - ⬜ Semantic linting (empty labels, unreachable code)
  - ⬜ PlantUML best practices warnings
  - ⬜ Tree-sitter query-based lint rules
- ⬜ **Completion** (Auto-complete)
  - ⬜ Keyword completion (`start`, `stop`, `if`, `while`, etc.)
  - ⬜ Symbol completion (partition names, swimlanes)
  - ⬜ Snippet completion (common patterns)
  - ⬜ Context-aware suggestions
- ⬜ **Hover** (Symbol Information)
  - ⬜ Element documentation
  - ⬜ Type information
  - ⬜ Quick reference
- ⬜ **Definition** (Go to Definition)
  - ⬜ Jump to partition/swimlane definitions
  - ⬜ Jump to activity node definitions
  - ⬜ Cross-file references (imports)
- ⬜ **Formatting** (Code Formatter)
  - ⬜ Indent normalization
  - ⬜ Consistent arrow formatting
  - ⬜ Comment preservation
  - ⬜ User-configurable style
- ⬜ **Symbols** (Outline / Breadcrumbs)
  - ⬜ Document symbol provider
  - ⬜ Workspace symbol provider
  - ⬜ Hierarchical outline

**Performance Targets:**

- ⬜ Initial parse (10,000 lines): <100ms
- ⬜ Incremental edit: <5ms
- ⬜ Diagnostics: <20ms
- ⬜ Completion: <10ms
- ⬜ Formatting: <30ms

**Testing:**

- ⬜ 50+ LSP protocol tests
- ⬜ Feature provider tests
- ⬜ Integration tests with real editors

**Package**: `@plantuml/lsp` (~629KB including parser dependency)

See [packages.md](./packages.md#package-2-plantuml-lsp-language-server).

---

### Phase 9: VSCode Extension (Planned - Weeks 22-24)

**Extension Core** - ⬜ Not Yet Implemented

- ⬜ Extension activation
- ⬜ LSP client setup
- ⬜ Language configuration (brackets, comments)
- ⬜ Status bar integration

**Features** - ⬜ Not Yet Implemented

- ⬜ Syntax highlighting (tree-sitter queries)
- ⬜ Real-time diagnostics
- ⬜ Auto-completion
- ⬜ Hover information
- ⬜ Go to definition
- ⬜ Format document
- ⬜ Outline view / breadcrumbs

**Configuration** - ⬜ Not Yet Implemented

- ⬜ Enable/disable LSP features
- ⬜ Diagnostics settings
- ⬜ Formatter options
- ⬜ Performance settings

**Future Enhancements** - 🔄 Planned for Later

- 🔄 Diagram preview (live rendering)
- 🔄 Export to PNG/SVG
- 🔄 Snippet library
- 🔄 Code actions (quick fixes)
- 🔄 Refactoring support

**Package**: `vscode-plantuml` (~2MB, VSCode Marketplace)

See [packages.md](./packages.md#package-3-vscode-plantuml-vscode-extension).

---

### Phase 10: CLI Tools (Planned - Weeks 25-26)

**Command-Line Interface** - 🔄 Future

- 🔄 `plantuml-lint` - Standalone linter
- 🔄 `plantuml-format` - Standalone formatter
- 🔄 `plantuml-parse` - AST output tool
- 🔄 CI/CD integration examples
- 🔄 Pre-commit hook templates

**Package**: `@plantuml/cli` (future package)

---

### Phase 11: Transpiler (Planned - Post v1.0)

**Code Generation** - 🔄 Future

- 🔄 PlantUML → Python classes
- 🔄 PlantUML → TypeScript interfaces
- 🔄 AST → Custom formats
- 🔄 Preserve comments in output
- 🔄 Source map generation

**Package**: `@plantuml/transpiler` (future package)

---

## Additional Diagram Types (Future)

These diagram types may be added after the core implementation:

### Priority 2 (Post v1.0)

**Network Diagrams** - ⬜ Not Planned Yet

- ⬜ Network node declarations
- ⬜ Network connections

**Mind Maps** - ⬜ Not Planned Yet

- ⬜ Root node
- ⬜ Child nodes
- ⬜ Node styling

**Work Breakdown Structure (WBS)** - ⬜ Not Planned Yet

- ⬜ WBS elements
- ⬜ Hierarchy

**Gantt Charts** - ⬜ Not Planned Yet

- ⬜ Task declarations
- ⬜ Dependencies
- ⬜ Milestones
- ⬜ Duration syntax

**Entity Relationship Diagrams (ERD)** - ⬜ Not Planned Yet

- ⬜ Entity declarations
- ⬜ Attributes
- ⬜ Relationships with cardinality

**Archimate Diagrams** - ⬜ Not Planned Yet

- ⬜ Archimate elements
- ⬜ Archimate relationships

**JSON/YAML Diagrams** - ⬜ Not Planned Yet

- ⬜ JSON syntax
- ⬜ YAML syntax

---

## Common Features (Cross-Cutting)

### Styling & Appearance

- ✅ Colors (hex and named)
- ✅ Skinparam directives
- ⬜ Sprite definitions
- ⬜ Style definitions
- ⬜ Themes

### Documentation

- ✅ Line comments (`'`)
- ✅ Block comments (`/' '/`)
- ✅ Notes (floating and attached)
- ⬜ Legend
- ⬜ Header/Footer

### Layout & Organization

- ✅ Partitions
- ✅ Swimlanes
- ⬜ Pages (for large diagrams)
- ⬜ Scale
- ⬜ Direction (top to bottom, left to right)

### Advanced Features

- ⬜ Preprocessing:
  - ⬜ `!include` directives
  - ⬜ `!define` macros
  - ⬜ `!if` conditionals
  - ⬜ `!function` and `!procedure`
- ⬜ Link support (`[[url]]`)
- ⬜ Tooltip support
- ⬜ Hyperlinks in diagrams

---

## Success Metrics

### Functional Requirements

- ✅ Parse 95%+ of real-world PlantUML diagrams (Phase 1: Activity only)
- ⬜ Support all standard PlantUML syntax elements
- ✅ Gracefully handle syntax errors
- ✅ Preserve source locations for every AST node

### Performance Requirements

- ⬜ Initial parse: <100ms for 10,000-line files
- ⬜ Incremental update: <5ms for typical single-line edits
- ⬜ Memory overhead: <10MB for standard 1,000-line documents
- ⬜ Query execution: <10ms for syntax highlighting queries

### Quality Requirements

- ✅ Phase 1: 35+ passing corpus tests (Activity Diagrams)
- ⬜ Final: 100+ passing corpus tests (all diagram types)
- ⬜ Error recovery tests for common syntax mistakes
- ⬜ 95%+ code coverage in grammar rules
- ⬜ Zero crashes on malformed input

### Integration Requirements

- ⬜ npm package with TypeScript type definitions
- ⬜ Language Server Protocol compatibility
- ⬜ VSCode extension support
- ⬜ PlantEdit integration with source mapping

---

## Timeline

### Diagram Types

| Phase | Duration | Diagram Types | Status |
|-------|----------|---------------|--------|
| Phase 1 | Weeks 1-2 | Activity | ✅ Complete |
| Phase 2 | Weeks 3-4 | Sequence | ⏳ Planned |
| Phase 3 | Weeks 5-6 | Class | ⏳ Planned |
| Phase 4 | Weeks 7-8 | State | ⏳ Planned |
| Phase 5 | Weeks 9-12 | Component, Deployment, Use Case | ⏳ Planned |
| Phase 6 | Weeks 13-16 | Quality, Documentation, Release | ⏳ Planned |

### LSP & Tooling

| Phase | Duration | Focus | Status |
|-------|----------|-------|--------|
| Phase 7 | Week 17 | Monorepo Restructure + Installation Fixes | ⏳ In Progress |
| Phase 8 | Weeks 18-21 | LSP Server (diagnostics, completion, hover, etc.) | ⏳ Planned |
| Phase 9 | Weeks 22-24 | VSCode Extension | ⏳ Planned |
| Phase 10 | Weeks 25-26 | CLI Tools (linter, formatter) | ⏳ Planned |
| Phase 11 | Post v1.0 | Transpiler (PlantUML → Python/TypeScript) | 🔄 Future |

---

## Contributing

We welcome contributions! If you'd like to help implement any of the planned features:

1. Check the roadmap to see what's planned
2. Review the [specification](./specification/README.md)
3. Create an issue to discuss your implementation plan
4. Submit a pull request with tests

Priority areas for contribution:
- 🔥 Phase 2: Sequence Diagrams
- 🔥 Error recovery improvements
- 🔥 Performance optimization
- 📝 Documentation improvements
- ✅ Additional test cases

---

**Last Updated**: 2025-11-07
**Current Version**: 0.1.0 (Phase 1)
**Next Milestone**: Phase 2 - Sequence Diagrams
