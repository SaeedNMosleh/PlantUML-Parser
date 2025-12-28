# Testing Guide

## Quick Start

```bash
# Navigate to parser package
cd packages/parser

# Install dependencies (first time only)
npm install

# Run all tests
npm test
```

## Test Commands

### Run Specific Test Suites

```bash
# Normalizer tests (59 tests, ~5 seconds)
npm run test:normalizer

# Parser/Grammar tests (30 tests, ~10 seconds)
npm run test:parser

# Integration tests (17 tests, ~15 seconds)
npm run test:integration
```

### Complete Test Suite

```bash
# All tests + validation (136 tests)
npm run test:all

# CI-compatible test run
npm run test:ci

# Verify 100% success rate
npm run test:100
```

## Build Commands

```bash
# Build JavaScript/TypeScript output
npm run build:js

# Build native bindings (requires C compiler)
npm run build:native

# Build WASM binary
npm run build:wasm

# Build everything
npm run build:all
```

## Development Workflow

```bash
# 1. Make changes to grammar or normalizer
# 2. Regenerate parser if grammar changed
npm run generate

# 3. Build the changes
npm run build:all

# 4. Run tests
npm test

# 5. Validate against PlantUML server (requires Docker)
npm run validate
```

## Test Structure

```
packages/parser/test/
├── corpus/activity/     # Grammar corpus tests (30 tests)
├── normalizer/          # Normalizer unit tests (59 tests)
├── integration/         # Full pipeline tests (17 tests)
└── fixtures/            # Test PlantUML files
```

## Expected Output

When all tests pass:

```
PASS  test/normalizer/*.test.ts (59 tests)
PASS  test/corpus/activity/*.txt (30 tests)
PASS  test/integration/*.test.ts (17 tests)

Test Suites: 3 passed, 3 total
Tests:       136 passed, 136 total
```

## Troubleshooting

### "jest not found"

```bash
# Make sure you're in the parser package
cd packages/parser
npm install
```

### "tree-sitter command not found"

This is expected! `tree-sitter-cli` is now a devDependency. Use:

```bash
npm run generate  # Uses npx to run tree-sitter
npm run parse     # Uses npx to run tree-sitter
```

### Tests fail after restructuring

```bash
# Clean and rebuild
npm run clean
npm run build:all
npm test
```

## Using pnpm Workspaces (Alternative)

```bash
# Install pnpm globally
npm install -g pnpm

# Install all workspace dependencies
pnpm install

# Run parser tests
pnpm --filter tree-sitter-plantuml test

# Build all packages
pnpm -r build
```

## Performance Benchmarks

- **Normalizer tests**: ~5 seconds
- **Parser tests**: ~10 seconds
- **Integration tests**: ~15 seconds
- **Total (all 136 tests)**: ~30 seconds

## See Also

- [specification/testing-guide.md](./specification/testing-guide.md) - Detailed testing strategy
- [specification/CONTRIBUTING.md](./specification/CONTRIBUTING.md) - Development guidelines
