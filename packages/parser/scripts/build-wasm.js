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
  const forceRebuild = process.env.FORCE_WASM_BUILD === '1';
  const grammarPath = path.join(projectRoot, 'grammar.js');

  // Check if rebuild is needed
  if (!forceRebuild && fs.existsSync(wasmPath)) {
    // Compare mtimes: only rebuild if grammar is newer than WASM
    const grammarMtime = fs.statSync(grammarPath).mtime.getTime();
    const wasmMtime = fs.statSync(wasmPath).mtime.getTime();

    if (wasmMtime >= grammarMtime) {
      console.log('WASM is up to date, skipping rebuild');
      return;
    }
    console.log('Grammar changed, rebuilding WASM...');
  } else if (forceRebuild) {
    console.log('FORCE_WASM_BUILD set, rebuilding WASM...');
  } else {
    console.log('WASM not found, building...');
  }

  // Ensure `tree-sitter` CLI exists before attempting build-wasm.
  run(process.execPath, [path.join(projectRoot, 'scripts', 'ensure-tree-sitter-cli.js')]);

  // Use the CLI to build the WASM file.
  run('tree-sitter', ['build-wasm']);

  if (!fs.existsSync(wasmPath)) {
    console.error('Expected tree-sitter-plantuml.wasm to be generated, but it was not found.');
    process.exit(1);
  }

  console.log('WASM build complete');
}

main();
