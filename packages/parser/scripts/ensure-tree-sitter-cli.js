const fs = require('node:fs');
const path = require('node:path');
const { spawnSync } = require('node:child_process');

function getLocalTreeSitterBin() {
  const binName = process.platform === 'win32' ? 'tree-sitter.cmd' : 'tree-sitter';
  const binPath = path.join(__dirname, '..', 'node_modules', '.bin', binName);
  return fs.existsSync(binPath) ? binPath : null;
}

function canRunTreeSitter(command) {
  const result = spawnSync(command, ['--version'], {
    stdio: 'ignore',
    shell: false
  });
  return result.status === 0;
}

function main() {
  const localBin = getLocalTreeSitterBin();

  if (localBin && canRunTreeSitter(localBin)) {
    return;
  }

  if (canRunTreeSitter('tree-sitter')) {
    return;
  }

  // tree-sitter-cli is an optionalDependency. If it failed to download, installs should still succeed,
  // but contributor scripts that require `tree-sitter` need a clear message.
  console.error('tree-sitter CLI is required for this command, but was not found.');
  console.error('');
  console.error('Fix options:');
  console.error('- Re-run install (network/proxy permitting): npm install');
  console.error('- Install the CLI globally: npm install -g tree-sitter-cli');
  console.error('- If you are behind a proxy, ensure HTTP_PROXY/HTTPS_PROXY are set for Node/npm.');
  console.error('');
  console.error('Tip: JS-only tasks (like normalizer tests) can run with:');
  console.error('  npm ci --ignore-scripts && npm run build:js && npm run test:normalizer');

  process.exit(1);
}

main();
