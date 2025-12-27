# Monorepo Architecture: Repository Organization Strategy

## Executive Summary

**Decision: Monorepo with Multiple Packages**

The PlantUML parser project will be organized as a monorepo containing three packages:
1. `tree-sitter-plantuml` - Core parser library
2. `@plantuml/lsp` - Language Server Protocol implementation
3. `vscode-plantuml` - VSCode extension

This structure keeps the parser minimal for library users while enabling powerful LSP features for editor users, following industry best practices used by TypeScript, Pyright, Babel, and other major projects.

---

## Repository Structure

```
tree-sitter-plantuml/                    (monorepo root)
├── packages/
│   ├── parser/                          (tree-sitter-plantuml on npm)
│   │   ├── Parser core: grammar, normalizer, bindings
│   │   ├── Size: ~329KB
│   │   └── Users: Library consumers, browser apps, CLI tools
│   │
│   ├── lsp/                             (@plantuml/lsp on npm)
│   │   ├── LSP server + incremental caching
│   │   ├── Size: ~629KB (includes parser)
│   │   └── Users: VSCode extension, other editors
│   │
│   └── vscode-plantuml/                 (VSCode Marketplace)
│       ├── VSCode extension + LSP client
│       ├── Size: ~2MB (includes VSCode APIs)
│       └── Users: VSCode users only
│
├── package.json                         (Workspace configuration)
├── pnpm-workspace.yaml                  (pnpm workspaces)
└── specification/                       (Shared documentation)
```

### Dependency Graph

```
tree-sitter-plantuml (parser - 329KB)
    ↓ consumed by
@plantuml/lsp (LSP server - 629KB)
    ↓ consumed by
vscode-plantuml (extension - 2MB)
```

---

## Decision Rationale

### Problem Statement

The project needs to serve multiple distinct use cases:

1. **Library users** - Import parser in their applications (need minimal size)
2. **CLI tool users** - Linting, formatting from command line
3. **VSCode users** - Full IDE features with LSP
4. **Grammar contributors** - Develop and test grammar rules

**Question:** Should we organize as:
- **Option A:** Single package (everything bundled)?
- **Option B:** Separate repositories (parser, LSP, extension)?
- **Option C:** Monorepo with multiple packages?

### Option A: Single Package ❌

**Structure:**
```
tree-sitter-plantuml/
├── src/
│   ├── parser/
│   ├── normalizer/
│   ├── lsp/              # LSP server in same package
│   └── extension/        # Extension in same package
└── package.json
```

**Pros:**
- ✅ Simplest structure initially
- ✅ Single version number
- ✅ One package to publish

**Cons:**
- ❌ Library users forced to download 629KB (instead of 329KB)
- ❌ Browser users get Node.js-only LSP code they can't use
- ❌ Package bloat (300KB+ of unused code for most users)
- ❌ Violates single responsibility principle
- ❌ Against tree-sitter ecosystem conventions
- ❌ All dependencies bundled (tree-sitter + vscode-languageserver)

**Impact:**
```javascript
// User wants just the parser
import PlantUMLParser from 'tree-sitter-plantuml';
// ❌ Downloads 629KB including LSP server they won't use
// ❌ Downloads vscode-languageserver dependencies for browser app
```

**Verdict:** **Rejected** - Forces unnecessary bloat on all users.

### Option B: Multiple Repositories ❌

**Structure:**
```
github.com/user/tree-sitter-plantuml     (Parser only)
github.com/user/plantuml-lsp             (LSP server)
github.com/user/vscode-plantuml          (VSCode extension)
```

**Pros:**
- ✅ Clear separation of concerns
- ✅ Independent release cycles possible
- ✅ Smaller individual repos (faster clone)
- ✅ Different contributor groups possible

**Cons:**
- ❌ **Version coordination nightmare**
  - Parser v2.1.0 → LSP needs update → Extension breaks
  - Must coordinate breaking changes across 3 repos
- ❌ **Atomic changes impossible**
  - Grammar change + LSP feature = 2 PRs in different repos
  - Can't test changes together before merge
- ❌ **Triple CI/CD maintenance**
  - 3 separate GitHub Actions workflows
  - 3 separate test configurations
  - 3 separate deployment pipelines
- ❌ **Code sharing painful**
  - Must publish parser to npm to test LSP changes
  - Can't use local links in development
  - TypeScript path mappings don't work across repos
- ❌ **User confusion**
  - Which repo for issues?
  - Which repo for pull requests?
  - Which repo has the documentation?
- ❌ **Duplicate configuration**
  - tsconfig.json duplicated 3 times
  - jest.config.js duplicated 3 times
  - ESLint config duplicated 3 times

**Real-world example of pain:**
```bash
# Developer wants to add new grammar rule and corresponding LSP feature

# Step 1: Update parser
cd tree-sitter-plantuml
git checkout -b add-sequence-diagrams
# ... make grammar changes ...
git commit -m "Add sequence diagram support"
git push

# Step 2: Publish parser or wait for review/merge
# (Can't test LSP changes until parser is merged!)

# Step 3: Update LSP in different repo
cd ../plantuml-lsp
git checkout -b use-sequence-diagrams
# Update package.json to use new parser version (not published yet!)
# ❌ Can't test locally!
git push

# Step 4: Update extension in third repo
cd ../vscode-plantuml
git checkout -b support-sequence-diagrams
# Same problem - can't test until LSP is published
```

**Verdict:** **Rejected** - Too much coordination overhead for solo/small team.

### Option C: Monorepo with Multiple Packages ✅

**Structure:**
```
tree-sitter-plantuml/                    (single repo)
├── packages/
│   ├── parser/                          (published separately)
│   ├── lsp/                             (published separately)
│   └── vscode-plantuml/                 (published separately)
└── package.json                         (workspace root)
```

**Pros:**
- ✅ **Keep parser minimal** - Library users get 329KB, not 629KB
- ✅ **Atomic commits** - Update parser + LSP + extension in single PR
- ✅ **Easy code sharing** - TypeScript path mapping between packages
- ✅ **Single CI/CD** - One pipeline tests all packages
- ✅ **Clear dependency graph** - Parser → LSP → Extension
- ✅ **Independent versioning** - Parser stable (v2.1), LSP experimental (v0.1)
- ✅ **Shared dev dependencies** - Single node_modules for development
- ✅ **Easy local testing** - Changes tested together before publish
- ✅ **No breaking changes for users** - Existing users keep using `tree-sitter-plantuml`

**Cons:**
- ⚠️ **Initial setup complexity** - Need to configure workspaces (1-2 days)
- ⚠️ **Build coordination** - Must build parser before LSP
- ⚠️ **Learning curve** - Contributors need to understand monorepo structure

**Mitigation:**
- Use pnpm workspaces (best performance, clear syntax)
- Document structure clearly in README
- Provide npm scripts for common tasks
- Add clear contribution guidelines

**Real-world example of benefit:**
```bash
# Developer wants to add new grammar rule and corresponding LSP feature

# Single repository, single PR
cd tree-sitter-plantuml
git checkout -b add-sequence-diagrams

# Update parser
cd packages/parser
# ... make grammar changes ...

# Update LSP immediately (uses local parser via workspace link!)
cd ../lsp
# ... add LSP features ...

# Update extension
cd ../vscode-plantuml
# ... update extension ...

# Test everything together
cd ../..
npm test  # Tests all packages

# Single commit, single PR
git commit -m "Add sequence diagram support across parser, LSP, and extension"
git push
```

**Verdict:** **Selected** - Best balance of separation and coordination.

---

## Industry Best Practices

### How Major Projects Organize

#### Pyright (Python Type Checker + LSP)

**Repository:** `microsoft/pyright` (monorepo)

**Structure:**
```
pyright/
├── packages/
│   ├── pyright-internal/      # Core type checking engine
│   ├── pyright/               # CLI tool
│   └── vscode-pyright/        # VSCode extension
└── lerna.json
```

**Pattern:** Core engine → CLI tool → Editor extension (same as our design)

#### Babel (JavaScript Compiler)

**Repository:** `babel/babel` (monorepo)

**Structure:**
```
babel/
├── packages/
│   ├── babel-core/            # Core compiler
│   ├── babel-cli/             # CLI tool
│   ├── babel-parser/          # Parser only
│   └── ... (140+ packages)
└── lerna.json
```

**Pattern:** Monorepo with many focused packages, independent versioning

#### Tree-sitter Ecosystem

**Finding:** Tree-sitter grammar repositories DO NOT include LSP servers.

**Examples:**
- `tree-sitter/tree-sitter-typescript` - Grammar only, ~500KB
- `tree-sitter/tree-sitter-rust` - Grammar only, ~800KB
- `tree-sitter/tree-sitter-python` - Grammar only, ~600KB

**LSP servers are separate:**
- `typescript-language-server/typescript-language-server` - Separate repo
- `rust-analyzer/rust-analyzer` - Separate repo (uses rustc parser)

**Why separation?**
1. Grammar packages are polyglot (published to npm, PyPI, crates.io, etc.)
2. LSP servers are language-specific (Node.js, Rust, Python)
3. Different user bases (parser used by many tools, LSP only by editors)

**Our adaptation:**
- Same repo (monorepo) for easier coordination
- Separate packages (maintains separation of concerns)
- Best of both worlds

#### rust-analyzer (Rust LSP)

**Repository:** `rust-analyzer/rust-analyzer` (separate from rustc)

**Structure:**
- Separate repository from Rust compiler
- Shares parser component but maintains organizational separation
- Recently moved under Rust organization but kept separate repo

**Pattern:** LSP servers can be separate even when sharing parser code

**Our adaptation:** We keep in same repo because we're smaller team and need tighter coordination.

---

## User Personas Analysis

### Persona 1: Library Users

**Profile:**
- Developers building apps that parse PlantUML
- Examples: Build tools, documentation generators, custom editors

**Needs:**
- Minimal bundle size (every KB matters)
- Just the parser API
- TypeScript types
- Works in Node.js and browser

**Package:** `tree-sitter-plantuml` (329KB)

**Usage:**
```javascript
import PlantUMLParser from 'tree-sitter-plantuml';
const parser = new PlantUMLParser();
const { tree, normalized } = parser.parse(source);
// Use AST for custom processing
```

**Don't want:**
- ❌ LSP server code
- ❌ VSCode dependencies
- ❌ Editor-specific features

**Impact of monorepo:** ✅ Gets minimal parser package, unaffected by LSP/extension complexity

### Persona 2: CLI Tool Users

**Profile:**
- Developers running linter/formatter in CI/CD
- Examples: Pre-commit hooks, automated code quality checks

**Needs:**
- Command-line interface
- Fast validation
- Exit codes for CI/CD

**Package:** `@plantuml/cli` (future package)

**Usage:**
```bash
npx plantuml-lint myfile.puml
npx plantuml-format --check ./diagrams/
```

**Don't want:**
- ❌ VSCode dependencies
- ❌ Editor-specific features
- ⚠️ Might want incremental caching (for watch mode)

**Impact of monorepo:** ✅ Future CLI package can depend on parser only (small) or LSP (with caching) as needed

### Persona 3: VSCode Extension Users

**Profile:**
- PlantUML developers using VSCode
- Need real-time feedback while editing

**Needs:**
- Syntax highlighting
- Real-time diagnostics
- Auto-completion
- Hover information
- Go to definition
- Formatting
- **Fast performance** (incremental parsing critical)

**Package:** `vscode-plantuml` (installs automatically from marketplace)

**Features:**
- LSP client connects to `@plantuml/lsp` server
- Tree-sitter queries for syntax highlighting
- Incremental caching for performance

**Don't care about:**
- Package size (extensions are large anyway)
- Parser internals (just want features to work)

**Impact of monorepo:** ✅ Gets full-featured extension with automatic updates, all packages work together

### Persona 4: Grammar Contributors

**Profile:**
- Open source contributors improving parser
- Grammar developers, test writers

**Needs:**
- Easy development setup
- Fast test cycle
- Clear contribution guidelines
- Ability to test changes across all packages

**Package:** Development environment only

**Workflow:**
```bash
git clone https://github.com/user/tree-sitter-plantuml
cd tree-sitter-plantuml
pnpm install        # Installs all workspace dependencies
pnpm test           # Tests all packages

# Make changes to grammar
cd packages/parser
vim grammar.js

# Test immediately, including LSP features
cd ../lsp
npm test            # Uses local parser via workspace link!
```

**Don't want:**
- ❌ Complex multi-repo setup
- ❌ Version coordination pain
- ❌ Inability to test cross-package changes

**Impact of monorepo:** ✅ Simple setup, easy testing, atomic commits

---

## Package Size Analysis

### Current State (Single Package)

**tree-sitter-plantuml v2.1.0:**
- Dist folder: 329KB
- Dependencies:
  - `tree-sitter` (776KB)
  - `node-addon-api` (small)
  - `node-gyp-build` (small)
- Total installed: ~1.1MB

### If We Add LSP to Single Package

**tree-sitter-plantuml v3.0.0 (hypothetical):**
- Dist folder: 629KB (+91% increase)
- Dependencies:
  - `tree-sitter` (776KB)
  - `node-addon-api` (small)
  - `node-gyp-build` (small)
  - `vscode-languageserver` (196KB) ← NEW
  - `vscode-languageserver-textdocument` (20KB) ← NEW
  - `vscode-languageserver-protocol` (50KB) ← NEW
- Total installed: ~1.4MB

**Impact on users:**
- Library user building browser app: Downloads 300KB of LSP code they can't use
- Bundle size bloat: 329KB → 629KB (+91%)

### Monorepo with Separate Packages

**tree-sitter-plantuml (parser):**
- Dist folder: 329KB (unchanged)
- Total installed: ~1.1MB (unchanged)

**@plantuml/lsp:**
- Dist folder: ~300KB (LSP server code)
- Dependencies:
  - `tree-sitter-plantuml` (329KB via npm link)
  - `vscode-languageserver` (196KB)
  - `vscode-languageserver-textdocument` (20KB)
- Total installed: ~1.5MB (for LSP users only)

**vscode-plantuml:**
- Extension bundle: ~2MB (typical for VSCode extensions)
- Dependencies:
  - `@plantuml/lsp` (server)
  - `vscode-languageclient` (LSP client)
- Users download from marketplace (size not critical)

**Winner:** Monorepo keeps parser minimal, adds LSP only where needed.

---

## Workspace Configuration

### Tool Selection: pnpm Workspaces

**Why pnpm?**
- ✅ Fastest package manager (3x faster than npm)
- ✅ Efficient disk usage (hardlinks, no duplication)
- ✅ Strict dependency resolution (no phantom dependencies)
- ✅ Best workspace support
- ✅ Drop-in replacement for npm

**Alternative considered:**
- **Lerna**: Good but requires extra tool, pnpm workspaces are native
- **Yarn workspaces**: Good but pnpm is faster
- **npm workspaces**: Built-in but slower than pnpm

**Configuration:**

`pnpm-workspace.yaml`:
```yaml
packages:
  - 'packages/*'
```

`package.json` (root):
```json
{
  "name": "tree-sitter-plantuml-monorepo",
  "private": true,
  "scripts": {
    "build": "pnpm -r build",
    "test": "pnpm -r test",
    "clean": "pnpm -r clean"
  }
}
```

**Usage:**
```bash
pnpm install                    # Installs all workspace dependencies
pnpm -r build                   # Builds all packages in order
pnpm --filter parser test       # Tests specific package
pnpm --filter lsp dev           # Runs dev server for LSP
```

---

## Benefits of Monorepo Approach

### 1. Atomic Commits

**Before (multi-repo):**
```
tree-sitter-plantuml PR #123: Add sequence diagrams
plantuml-lsp PR #45: Support sequence diagrams (depends on parser#123)
vscode-plantuml PR #67: UI for sequence diagrams (depends on lsp#45)
```
Three PRs, complex coordination, can't test together.

**After (monorepo):**
```
tree-sitter-plantuml PR #123: Add sequence diagrams
  Modified:
    packages/parser/grammar.js
    packages/lsp/src/providers/completion.ts
    packages/vscode-plantuml/src/extension.ts
```
One PR, tested together, atomic deployment.

### 2. Shared Configuration

**Before (multi-repo):**
- `tree-sitter-plantuml/tsconfig.json`
- `plantuml-lsp/tsconfig.json` (duplicate!)
- `vscode-plantuml/tsconfig.json` (duplicate!)

**After (monorepo):**
- `tsconfig.base.json` (shared settings)
- `packages/parser/tsconfig.json` (extends base)
- `packages/lsp/tsconfig.json` (extends base)
- `packages/vscode-plantuml/tsconfig.json` (extends base)

**Benefits:** Update shared config once, applies to all packages.

### 3. Easy Local Development

**TypeScript path mapping:**
```json
{
  "compilerOptions": {
    "paths": {
      "@plantuml/parser": ["./packages/parser/src"],
      "@plantuml/lsp": ["./packages/lsp/src"]
    }
  }
}
```

**LSP package uses parser:**
```typescript
// packages/lsp/src/server.ts
import PlantUMLParser from '@plantuml/parser';  // Local workspace link!

const parser = new PlantUMLParser();
// Changes to parser immediately reflected in LSP during development
```

No need to:
- ❌ Publish parser to test LSP changes
- ❌ Use `npm link` (error-prone)
- ❌ Copy files manually

### 4. Single CI/CD Pipeline

**.github/workflows/ci.yml:**
```yaml
name: CI

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - uses: pnpm/action-setup@v2
      - run: pnpm install
      - run: pnpm -r build       # Builds all packages
      - run: pnpm -r test        # Tests all packages
      - run: pnpm -r lint        # Lints all packages
```

**Benefits:**
- One workflow file instead of three
- Test all packages together
- Catch integration issues early

### 5. Independent Versioning

**Lerna configuration:**
```json
{
  "version": "independent",
  "packages": ["packages/*"]
}
```

**Versions:**
- `tree-sitter-plantuml`: v2.1.0 (stable)
- `@plantuml/lsp`: v0.1.0 (experimental)
- `vscode-plantuml`: v0.1.0 (experimental)

**Benefits:**
- Parser doesn't get version bump for LSP bug fixes
- Can mark LSP as beta without affecting parser's stable status
- Semantic versioning applies per package

---

## Disadvantages and Mitigations

### Disadvantage 1: Initial Setup Complexity

**Problem:** Setting up workspaces takes 1-2 days.

**Mitigation:**
- Clear documentation in README
- Setup script: `npm run setup`
- Detailed contribution guidelines

### Disadvantage 2: Build Order Matters

**Problem:** Must build parser before LSP.

**Mitigation:**
- Use TypeScript project references (automatic build order)
- pnpm has built-in topological sorting
- Root `build` script handles order:
```json
{
  "scripts": {
    "build": "pnpm -r --workspace-concurrency=1 build"
  }
}
```

### Disadvantage 3: Risk of Tight Coupling

**Problem:** Easy to create dependencies between packages.

**Mitigation:**
- Clear dependency graph documentation
- Code review focuses on package boundaries
- Only allow dependencies in one direction:
  ```
  Parser ← LSP ← Extension
  (LSP can import Parser, but Parser cannot import LSP)
  ```

---

## Migration Strategy

### Current State

```
tree-sitter-plantuml/
├── src/
├── grammar.js
├── package.json
└── ... (all files in root)
```

### Phase 1: Create Structure (Day 1)

```bash
# Create packages directory
mkdir -p packages/parser

# Move files (using git mv to preserve history)
git mv src packages/parser/
git mv grammar.js packages/parser/
git mv binding.gyp packages/parser/
git mv package.json packages/parser/
git mv tsconfig.json packages/parser/
git mv tsup.config.ts packages/parser/
git mv dist packages/parser/
# ... move all parser-related files
```

### Phase 2: Create Workspace Config (Day 2)

```bash
# Create root package.json
cat > package.json <<EOF
{
  "name": "tree-sitter-plantuml-monorepo",
  "private": true,
  "workspaces": ["packages/*"]
}
EOF

# Create pnpm-workspace.yaml
cat > pnpm-workspace.yaml <<EOF
packages:
  - 'packages/*'
EOF

# Create shared configs
cat > tsconfig.base.json <<EOF
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "ESNext",
    "strict": true
  }
}
EOF
```

### Phase 3: Test Migration (Day 2-3)

```bash
# Install using pnpm
pnpm install

# Build parser
cd packages/parser
pnpm build

# Test parser
pnpm test

# Verify 136/136 tests still pass
```

### Phase 4: Create Placeholder Packages (Day 3)

```bash
# Create LSP package structure
mkdir -p packages/lsp/src
cat > packages/lsp/package.json <<EOF
{
  "name": "@plantuml/lsp",
  "version": "0.1.0",
  "dependencies": {
    "tree-sitter-plantuml": "workspace:*"
  }
}
EOF

# Create extension package structure
mkdir -p packages/vscode-plantuml/src
cat > packages/vscode-plantuml/package.json <<EOF
{
  "name": "vscode-plantuml",
  "version": "0.1.0",
  "dependencies": {
    "@plantuml/lsp": "workspace:*"
  }
}
EOF
```

### Breaking Changes for End Users

**None!**

The parser package will still be published as `tree-sitter-plantuml` with the same API.

```javascript
// Before
import PlantUMLParser from 'tree-sitter-plantuml';

// After (exactly the same)
import PlantUMLParser from 'tree-sitter-plantuml';
```

**Only internal organization changes**, not user-facing API.

---

## Future Extensibility

### Easy to Add New Packages

**Future packages:**
- `@plantuml/cli` - Command-line linter/formatter
- `@plantuml/formatter` - Standalone formatter library
- `@plantuml/transpiler` - PlantUML → Python/TypeScript
- `@plantuml/web-components` - Web component for rendering

**Process:**
```bash
# Add new package
mkdir -p packages/cli
cd packages/cli
npm init -y

# Automatically part of workspace
cd ../..
pnpm install  # Links to other workspace packages
pnpm -r build  # Builds new package too
```

### Monorepo Scales Well

**Examples of large monorepos:**
- **Babel**: 140+ packages
- **React**: 50+ packages
- **Vue**: 30+ packages
- **Jest**: 40+ packages

**Our projection:**
- Currently: 1 package
- After restructure: 3 packages
- Future: 5-7 packages (plenty of room to grow)

---

## Conclusion

The monorepo approach with multiple packages provides the best balance for this project:

✅ **Keeps parser minimal** (329KB) for library users
✅ **Enables powerful LSP** (~629KB) for editor users
✅ **Maintains clear separation** between concerns
✅ **Simplifies coordination** with atomic commits
✅ **Follows industry standards** (Pyright, Babel, Vue, React)
✅ **Scales for future growth** (CLI, formatter, transpiler packages)
✅ **No breaking changes** for existing users

The initial setup investment (1-2 days) pays for itself immediately with:
- Faster development velocity
- Easier testing
- Better code organization
- Professional project structure

---

## References

- **Pyright monorepo**: https://github.com/microsoft/pyright
- **Babel monorepo**: https://github.com/babel/babel
- **pnpm workspaces**: https://pnpm.io/workspaces
- **Lerna**: https://lerna.js.org/
- **TypeScript project references**: https://www.typescriptlang.org/docs/handbook/project-references.html

---

**Version**: 2.1.0
**Status**: Decision Document
**Last Updated**: 2025-12-27
