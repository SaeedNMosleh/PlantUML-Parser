# PlantUML Parser Specification

## Overview

This specification defines a **tree-sitter-based parser for PlantUML**, designed as a standalone, reusable component that can be consumed by diagram editors, IDEs, and other tools requiring PlantUML source code analysis.

## Current Implementation Status

**Last Updated**: 2025-11-13

### What's Working
- ✅ **Parser Generation**: Grammar compiles successfully with tree-sitter
- ✅ **Native Binding**: C/C++ binding builds without errors
- ✅ **Grammar Definition**: Complete grammar for Activity diagrams (Phase 1)
- ✅ **Test Suite**: 35+ corpus tests ready for activity diagrams
- ✅ **Preprocessor**: Resolves PlantUML ambiguities (e.g., `(*)` as START vs STOP)
- ✅ **External Scanner**: Context-sensitive token recognition

### Critical Blocker
- ❌ **Runtime Parsing**: Tree-sitter binding compatibility issue
  - **Symptom**: Binding loads but is rejected with "Invalid language object"
  - **Impact**: Cannot parse any PlantUML code at runtime
  - **Affects**: All diagram types, all functionality
  - **Status**: Under investigation

### Architecture Decision
The current implementation uses a **preprocessing approach**:
1. **Normalizer**: Standardizes syntax variations
2. **Semantic Preprocessor**: Resolves PlantUML's context-dependent ambiguities
3. **Scanner**: Recognizes preprocessing markers
4. **Grammar**: Defines structure without semantic ambiguities

This approach acknowledges that PlantUML's ambiguous syntax (same tokens mean different things in different contexts) cannot be handled by traditional tree-sitter patterns alone.

## Project Vision

Create a high-performance, incremental PlantUML parser that:

- **Parses PlantUML source code** into Abstract Syntax Trees (AST)
- **Supports incremental parsing** with sub-millisecond updates for typical edits
- **Handles syntax errors gracefully** through automatic error recovery
- **Preserves all source information** including whitespace and comments for lossless round-trips
- **Provides rich queries** for syntax highlighting, code folding, and symbol extraction
- **Integrates seamlessly** with Language Server Protocol (LSP) implementations

## Why Tree-sitter?

Tree-sitter was selected after evaluating multiple parsing technologies based on these critical requirements:

| Feature | Tree-sitter | ANTLR4 | Peggy | Langium |
|---------|------------|--------|-------|---------|
| Incremental parsing | ✅ <1ms | ❌ Full reparse | ❌ Full reparse | ⚠️ Limited |
| Error recovery | ✅ Automatic | ⚠️ Manual | ⚠️ Manual | ✅ Good |
| Lossless parsing | ✅ Full CST | ❌ AST only | ❌ AST only | ⚠️ Partial |
| IDE integration | ✅ Native | ⚠️ Adapters needed | ⚠️ Custom | ✅ Built-in |
| Ecosystem maturity | ✅ GitHub, VSCode | ✅ Mature | ⚠️ Limited | ⚠️ Growing |

**Key advantages:**

- **Performance**: Incremental parsing under 1 millisecond for typical edits enables real-time feedback
- **Resilience**: Automatic error recovery allows continuous parsing even with syntax errors
- **Completeness**: Concrete syntax trees preserve all source information for round-trip conversion
- **Proven**: Used by GitHub for code navigation, VSCode for syntax highlighting, and Neovim for advanced editing

## Architecture

The parser consists of:

```
tree-sitter-plantuml/
├── grammar.js              # Declarative grammar definition
├── src/
│   ├── parser.c            # Generated parser (auto-generated, do not edit)
│   ├── scanner.c           # Custom lexer (if needed for complex tokens)
│   └── node-types.json     # Generated AST node type definitions
├── queries/
│   ├── highlights.scm      # Syntax highlighting queries
│   ├── folds.scm          # Code folding queries
│   ├── tags.scm           # Symbol extraction queries
│   └── locals.scm         # Scope analysis queries
├── test/
│   └── corpus/            # Corpus-based tests
│       ├── activity.txt
│       ├── sequence.txt
│       ├── class.txt
│       └── ...
└── bindings/
    ├── node/              # Node.js bindings
    └── rust/              # Rust bindings (future)
```

## Specification Structure

This specification is organized into focused documents:

### [Architecture](./architecture/README.md)
- Parser system design
- AST structure and node types
- Integration patterns
- Performance considerations

### [Grammar](./grammar/README.md)
- Grammar rules for each diagram type
- Token definitions and precedence
- Error recovery strategies
- Incremental parsing optimizations

### [Testing](./testing/README.md)
- Corpus test organization
- Coverage requirements
- Error recovery test cases
- Performance benchmarks

### [Integration](./integration/README.md)
- npm package structure
- Language Server Protocol integration
- PlantEdit integration patterns
- IDE plugin support

## Development Phases

The parser will be developed incrementally, prioritizing diagram types by usage frequency and complexity:

### Phase 1: Foundation (Weeks 1-2)
- **Activity Diagrams**: Basic nodes, decisions, partitions
- **Core Infrastructure**: Build system, test framework, CI/CD
- **Deliverable**: Parse 80%+ of activity diagrams with 20+ corpus tests

### Phase 2: Interactions (Weeks 3-4)
- **Sequence Diagrams**: Participants, messages, groups, activation
- **Refinement**: Error recovery improvements, performance optimization
- **Deliverable**: Parse 80%+ of sequence diagrams with 30+ corpus tests

### Phase 3: Structure (Weeks 5-6)
- **Class Diagrams**: Classes, interfaces, relationships, packages
- **Enhancement**: Advanced queries for code navigation
- **Deliverable**: Parse 80%+ of class diagrams with 40+ corpus tests

### Phase 4: State Machines (Weeks 7-8)
- **State Diagrams**: States, transitions, composite states, history
- **Maturation**: Performance tuning, comprehensive error messages
- **Deliverable**: Parse 80%+ of state diagrams with 30+ corpus tests

### Phase 5: Extended Types (Weeks 9-12)
- **Component Diagrams**: Components, interfaces, dependencies
- **Deployment Diagrams**: Nodes, artifacts, connections
- **Use Case Diagrams**: Actors, use cases, relationships
- **Deliverable**: 95%+ parse success across all diagram types

### Phase 6: Production Ready (Weeks 13-16)
- **Quality**: 100+ total corpus tests, 95%+ code coverage
- **Performance**: <100ms for 10K lines, <5ms incremental updates
- **Documentation**: Complete API docs, integration guides
- **Release**: npm package v1.0.0, GitHub repository with MIT license

## Success Metrics

### Functional Requirements
- ✅ Parse 95%+ of real-world PlantUML diagrams across all major types
- ✅ Support all standard PlantUML syntax elements per diagram type
- ✅ Gracefully handle syntax errors without failing parse
- ✅ Preserve source locations for every AST node

### Performance Requirements
- ✅ Initial parse: <100ms for 10,000-line files
- ✅ Incremental update: <5ms for typical single-line edits
- ✅ Memory overhead: <10MB for standard 1,000-line documents
- ✅ Query execution: <10ms for syntax highlighting queries

### Quality Requirements
- ✅ 100+ passing corpus tests covering all diagram types
- ✅ Error recovery tests for common syntax mistakes
- ✅ 95%+ code coverage in grammar rules
- ✅ Zero crashes on malformed input

### Integration Requirements
- ✅ npm package with TypeScript type definitions
- ✅ Language Server Protocol compatibility
- ✅ VSCode extension support
- ✅ PlantEdit integration with source mapping

## Integration with PlantEdit

The parser integrates with PlantEdit (and other consumers) through:

1. **npm Package**: Install via `npm install tree-sitter-plantuml`
2. **AST Access**: Tree-sitter Node API for traversing syntax trees
3. **Incremental Updates**: Only re-parse edited regions for performance
4. **Query Support**: Extract specific diagram elements (e.g., all class names)
5. **Source Mapping**: Link AST nodes back to exact source locations
6. **Error Information**: Detailed syntax error messages with positions

**Example integration:**

```typescript
import Parser from 'tree-sitter';
import PlantUML from 'tree-sitter-plantuml';

const parser = new Parser();
parser.setLanguage(PlantUML);

const sourceCode = `
@startuml
class User {
  +name: string
  +email: string
}
@enduml
`;

const tree = parser.parse(sourceCode);
const rootNode = tree.rootNode;

// Navigate AST
console.log(rootNode.toString());

// Incremental update
const newCode = sourceCode.replace('User', 'Customer');
const newTree = parser.parse(newCode, tree);  // Fast incremental parse
```

## Technology Stack

### Core
- **Tree-sitter CLI**: Grammar compilation and test runner
- **C/C++**: Generated parser code (performance-critical)
- **Node.js**: Primary runtime for grammar development and testing

### Development
- **TypeScript**: Type definitions and integration examples
- **Jest**: Unit testing for grammar rules
- **GitHub Actions**: CI/CD pipeline
- **npm**: Package distribution

### Quality
- **tree-sitter test**: Corpus-based testing framework
- **tree-sitter parse**: Manual testing and debugging
- **tree-sitter highlight**: Syntax highlighting validation
- **Benchmark suite**: Performance regression testing

## Repository Structure

This parser will be developed as an independent open-source project:

- **Repository**: `tree-sitter-plantuml` (separate from PlantEdit)
- **License**: MIT (compatible with tree-sitter ecosystem)
- **Package**: `@plantuml/tree-sitter-plantuml` on npm
- **Community**: Public issue tracker, contribution guidelines, documentation

## Next Steps

1. **Read the detailed specifications** in the subdirectories
2. **Review the architecture document** to understand system design
3. **Study the grammar specification** for implementation details
4. **Examine the testing strategy** for quality assurance approach
5. **Explore integration patterns** for consuming the parser

## References

- [Tree-sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [PlantUML Language Reference](https://plantuml.com/)
- [PlantEdit System Architecture](https://github.com/SaeedNMosleh/PlantEdit/tree/main/specification)
- [Tree-sitter Parsers Gallery](https://github.com/tree-sitter)

---

**Version**: 1.0.0
**Last Updated**: 2025-11-07
**Status**: Draft Specification
