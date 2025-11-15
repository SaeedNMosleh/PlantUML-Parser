# PlantUML Parser (tree-sitter-plantuml)

A high-performance [tree-sitter](https://tree-sitter.github.io/) parser for PlantUML using a **two-pass architecture** (Normalizer + Grammar) to handle PlantUML's ambiguous syntax.

## Quick Start

```bash
# Install dependencies
npm install

# Build the parser
npm run build

# Run all tests
npm test
```

```javascript
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

# Install dependencies
npm install

# Generate parser and build native bindings
npm run build
```

## Usage

### Parse PlantUML

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
3. Rebuild bindings: `npm run build`
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
PlantUML-Parser/
├── grammar.js                  # Grammar definition
├── index.js                    # Main entry point (PlantUMLParser)
├── src/
│   ├── normalizer/             # Normalizer (Pass 1)
│   │   ├── index.js            # Core normalizer
│   │   ├── rules/              # Transformation rules
│   │   └── utils.js            # Helper functions
│   ├── parser.c                # Generated parser (Pass 2)
│   └── node-types.json         # Generated node types
├── test/
│   ├── corpus/activity/        # Grammar corpus tests
│   ├── normalizer/             # Normalizer unit tests
│   ├── integration/            # Full pipeline tests
│   └── fixtures/               # Test PlantUML files
├── bindings/node/              # Node.js native bindings
├── specification/              # Complete documentation
├── examples/                   # Example PlantUML files
└── docker-compose.yml          # PlantUML server setup
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

### ⏳ Phase 2: Sequence Diagrams (Planned)
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

**Version**: 2.0.0
**Status**: Phase 1 Complete - Activity Diagrams
**Last Updated**: 2025-11-15
