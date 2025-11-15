# Browser Tests for PlantUML Parser

This directory contains browser-based tests for the ESM/WASM version of the PlantUML parser.

## Running the Tests

### Option 1: Local Web Server

```bash
# Using Python
python -m http.server 8000

# Using Node.js http-server
npx http-server

# Then open:
http://localhost:8000/test/browser/esm-test.html
```

### Option 2: VS Code Live Server

1. Install "Live Server" extension in VS Code
2. Right-click on `esm-test.html`
3. Select "Open with Live Server"

## What's Being Tested

### Test 1: Normalizer Only (No WASM)
- Tests the pure JavaScript normalizer
- Runs entirely in the browser without WASM
- Demonstrates lightweight usage (no tree-sitter needed)
- Should work immediately without any server setup

### Test 2: Full Parsing with WASM
- Tests the complete parser with WASM
- Loads `tree-sitter-plantuml.wasm`
- Demonstrates full parsing capabilities
- Requires the WASM file to be accessible

## Files

- `esm-test.html` - Interactive browser test page
- `README.md` - This file

## Expected Results

All tests should pass with:
- ✅ Test 1: Normalizer successfully converts `(*)` to `start`/`stop`
- ✅ Test 2: WASM parser generates valid syntax tree

## Troubleshooting

### CORS Errors
If you see CORS errors when loading the WASM file, make sure you're using a local web server (not `file://` protocol).

### Module Not Found
Make sure you're running from the repository root directory or adjust the import paths in the HTML file.

### WASM File Not Found
Make sure you've built the WASM file first:
```bash
npm run build:wasm
```
