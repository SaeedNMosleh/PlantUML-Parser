# Testing Guide

## Quick Start

```bash
# Install dependencies (workspace root)
# NOTE: This repo uses npm workspaces. Even if you run `npm install` inside
# `packages/parser`, npm will install into the workspace root `node_modules`.
npm install

# Run all parser tests
npm --workspace packages/parser test
```

## Test Commands

### Run Specific Test Suites

```bash
# Normalizer tests (59 tests, ~5 seconds)
npm --workspace packages/parser run test:normalizer

# Parser/Grammar tests (30 tests, ~10 seconds)
npm --workspace packages/parser run test:parser

# Integration tests (17 tests, ~15 seconds)
npm --workspace packages/parser run test:integration
```

### Complete Test Suite

```bash
# All tests + validation (136 tests)
npm --workspace packages/parser run test:all

# CI-compatible test run
npm --workspace packages/parser run test:ci

# Verify 100% success rate
npm --workspace packages/parser run test:100
```

## Build Commands

```bash
# Build JavaScript/TypeScript output
npm --workspace packages/parser run build:js

# Build native bindings (requires C compiler)
npm --workspace packages/parser run build:native

# Build WASM binary
npm --workspace packages/parser run build:wasm

# Build everything
npm --workspace packages/parser run build:all
```

## Development Workflow

```bash
# 1. Make changes to grammar or normalizer
# 2. Regenerate parser if grammar changed
npm --workspace packages/parser run generate

# 3. Build the changes
npm --workspace packages/parser run build:all

# 4. Run tests
npm --workspace packages/parser test

# 5. Validate against PlantUML server (requires Docker)
npm --workspace packages/parser run validate
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
# Install dependencies at the workspace root
npm install
```

### "tree-sitter command not found"

This is expected! `tree-sitter-cli` is now a devDependency. Use:

```bash
npm --workspace packages/parser run generate
npm --workspace packages/parser run parse
```

### Tests fail after restructuring

```bash
# Clean and rebuild
npm --workspace packages/parser run clean
npm --workspace packages/parser run build:all
npm --workspace packages/parser test
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
