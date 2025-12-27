const fs = require('node:fs');
const path = require('node:path');
const { spawnSync } = require('node:child_process');

const projectRoot = path.join(__dirname, '..');
const wasmPath = path.join(projectRoot, 'tree-sitter-plantuml.wasm');

function run(command, args) {
  const result = spawnSync(command, args, {
    cwd: projectRoot,
    stdio: 'inherit',
    shell: false
  });

  if (result.status !== 0) {
    process.exit(result.status ?? 1);
  }
}

function main() {
  // If the WASM already exists (e.g. checked in or built earlier), do nothing.
  if (fs.existsSync(wasmPath)) return;

  // Ensure `tree-sitter` CLI exists before attempting build-wasm.
  run(process.execPath, [path.join(projectRoot, 'scripts', 'ensure-tree-sitter-cli.js')]);

  // Use the CLI to build the WASM file.
  run('tree-sitter', ['build-wasm']);

  if (!fs.existsSync(wasmPath)) {
    console.error('Expected tree-sitter-plantuml.wasm to be generated, but it was not found.');
    process.exit(1);
  }
}

main();
