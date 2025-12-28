const fs = require('node:fs');
const path = require('node:path');
const { spawnSync } = require('node:child_process');

function getLocalTreeSitterBin() {
  const binDir = path.join(__dirname, '..', 'node_modules', '.bin');

  if (process.platform === 'win32') {
    const exePath = path.join(binDir, 'tree-sitter.exe');
    if (fs.existsSync(exePath)) return exePath;

    const cmdPath = path.join(binDir, 'tree-sitter.cmd');
    if (fs.existsSync(cmdPath)) return cmdPath;

    return null;
  }

  const binPath = path.join(binDir, 'tree-sitter');
  return fs.existsSync(binPath) ? binPath : null;
}

function canRunTreeSitter(command) {
  const result = spawnSync(command, ['--version'], {
    stdio: 'ignore',
    shell: false
  });
  return result.status === 0;
}

function getPinnedTreeSitterVersion() {
  try {
    const pkgJsonPath = path.join(__dirname, '..', 'package.json');
    const pkg = JSON.parse(fs.readFileSync(pkgJsonPath, 'utf8'));
    const spec =
      (pkg.optionalDependencies && pkg.optionalDependencies['tree-sitter-cli']) ||
      (pkg.devDependencies && pkg.devDependencies['tree-sitter-cli']);
    if (typeof spec === 'string') {
      const m = spec.match(/(\d+\.\d+\.\d+)/);
      if (m) return m[1];
    }
  } catch {
    // ignore
  }
  return '0.20.8';
}

function tryBootstrapTreeSitterOnWindows() {
  if (process.platform !== 'win32') return false;

  const version = getPinnedTreeSitterVersion();
  const scriptPath = path.join(__dirname, 'download-tree-sitter-cli.ps1');
  const outDir = path.join(__dirname, '..', 'node_modules', '.bin');

  if (!fs.existsSync(scriptPath)) return false;

  const result = spawnSync(
    'powershell.exe',
    [
      '-NoProfile',
      '-ExecutionPolicy',
      'Bypass',
      '-File',
      scriptPath,
      '-Version',
      version,
      '-OutDir',
      outDir
    ],
    {
      stdio: 'inherit',
      shell: false
    }
  );

  return result.status === 0;
}

function main() {
  const localBin = getLocalTreeSitterBin();

  if (localBin && canRunTreeSitter(localBin)) {
    return;
  }

  // On Windows behind corporate proxies, the official tree-sitter-cli installer (Node-based)
  // can fail even when PowerShell can download successfully. Try a PowerShell bootstrap.
  if (tryBootstrapTreeSitterOnWindows()) {
    const bootstrappedBin = getLocalTreeSitterBin();
    if (bootstrappedBin && canRunTreeSitter(bootstrappedBin)) {
      return;
    }
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
  console.error('- Windows: this repo can auto-download the binary via PowerShell if proxy allows.');
  console.error('');
  console.error('Tip: JS-only tasks (like normalizer tests) can run with:');
  console.error('  npm ci --ignore-scripts && npm run build:js && npm run test:normalizer');

  process.exit(1);
}

main();
