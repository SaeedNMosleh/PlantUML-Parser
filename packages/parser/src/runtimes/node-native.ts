import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createRequire } from 'node:module';

import type { PlantUMLBackend } from '../core/backend';

function getRuntimeFileName(): string {
  // In CJS builds, __filename exists.
  // In ESM builds, use import.meta.url.
  // eslint-disable-next-line no-undef
  if (typeof __filename !== 'undefined') return __filename;
  return fileURLToPath(import.meta.url);
}

function findPackageRoot(startDir: string): string {
  let current = startDir;
  for (;;) {
    if (fs.existsSync(path.join(current, 'package.json'))) return current;
    const parent = path.dirname(current);
    if (parent === current) throw new Error('Failed to locate package root (package.json).');
    current = parent;
  }
}

function loadNativeBinding(): { language: unknown } {
  const require = createRequire(
    // eslint-disable-next-line no-undef
    typeof __filename !== 'undefined' ? __filename : import.meta.url
  );
  const startDir = path.dirname(getRuntimeFileName());
  const root = findPackageRoot(startDir);

  // node-gyp-build will prefer prebuilds/ when present.
  // eslint-disable-next-line @typescript-eslint/no-var-requires
  const load = require('node-gyp-build');
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  const binding: any = load(root);

  if (!binding?.language) {
    throw new Error('Native binding loaded but did not expose language.');
  }

  return { language: binding.language };
}

export function createNodeNativeBackend(): PlantUMLBackend {
  const require = createRequire(
    // eslint-disable-next-line no-undef
    typeof __filename !== 'undefined' ? __filename : import.meta.url
  );

  // eslint-disable-next-line @typescript-eslint/no-var-requires
  const TreeSitter = require('tree-sitter');
  const Parser = TreeSitter;

  const { language } = loadNativeBinding();
  const parser = new Parser();

  // Tree-sitter expects a native language object.
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  (parser as any).setLanguage(language as any);

  return {
    parseNormalized(source: string, options?: { oldTree?: unknown }) {
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      const oldTree = options?.oldTree as any;
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      const tree = (parser as any).parse(source, oldTree);
      return { tree };
    },
    getLanguage() {
      return language;
    },
    getParser() {
      return parser;
    }
  };
}
