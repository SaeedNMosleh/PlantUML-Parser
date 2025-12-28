const fs = require('node:fs');
const path = require('node:path');

const prebuildify = require('prebuildify');

const target = process.env.PREBUILD_TARGET || process.versions.node;

const projectRoot = path.join(__dirname, '..');

let cache;

// In some environments (corporate proxies / custom CAs), node-gyp's header download can fail.
// prebuildify also uses a different devdir layout than node-gyp's default cache.
// If we already have headers cached, seed prebuildify's devdir from the node-gyp cache.
if (process.platform === 'win32' && process.env.LOCALAPPDATA) {
  const nodeGypCacheVersionDir = path.join(process.env.LOCALAPPDATA, 'node-gyp', 'Cache', target);
  const nodeGypIncludeDir = path.join(nodeGypCacheVersionDir, 'include', 'node');

  const prebuildifyCacheBase = path.join(process.env.LOCALAPPDATA, 'node-gyp', 'Cache', 'prebuildify');
  const prebuildifyVersionDir = path.join(prebuildifyCacheBase, 'node', target);

  if (fs.existsSync(nodeGypIncludeDir) && !fs.existsSync(prebuildifyVersionDir)) {
    fs.mkdirSync(path.dirname(prebuildifyVersionDir), { recursive: true });
    fs.cpSync(nodeGypCacheVersionDir, prebuildifyVersionDir, { recursive: true });
  }

  if (fs.existsSync(path.join(prebuildifyVersionDir, 'include', 'node'))) {
    cache = prebuildifyCacheBase;
  }
}

prebuildify(
  {
    cwd: projectRoot,
    out: projectRoot,
    napi: true,
    strip: true,
    targets: [target],
    cache
  },
  (err) => {
    if (err) {
      console.error(err);
      process.exit(1);
    }
  }
);
