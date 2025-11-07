# Generated Parser Files

This directory contains auto-generated parser files created by tree-sitter.

## Files Generated Here

When you run `npm run generate` or `tree-sitter generate`, the following files will be created:

- **parser.c** - The generated C parser code (do not edit manually)
- **grammar.json** - JSON representation of the grammar (do not edit manually)
- **node-types.json** - Node type definitions for the AST (do not edit manually)

## Important Notes

⚠️ **DO NOT EDIT THESE FILES MANUALLY**

These files are automatically generated from `grammar.js` in the project root.
Any manual changes will be overwritten the next time the parser is generated.

## How to Generate

```bash
# Generate parser from grammar.js
npm run generate

# Or directly with tree-sitter CLI
tree-sitter generate
```

## Gitignore

These generated files are listed in `.gitignore` because:
- They should be regenerated on each build
- They are large and change frequently
- They are deterministically generated from `grammar.js`

## First Time Setup

If you just cloned this repository and these files don't exist:

1. Install dependencies: `npm install`
2. Generate the parser: `npm run generate`
3. Build native bindings: `npm run build`
4. Run tests: `npm test`

See the main [README.md](../README.md) for complete setup instructions.
