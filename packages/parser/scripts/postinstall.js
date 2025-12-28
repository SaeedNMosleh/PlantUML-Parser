#!/usr/bin/env node

/**
 * Post-installation script for tree-sitter-plantuml
 * Provides helpful information about installation options
 */

const fs = require('fs');
const path = require('path');

const GREEN = '\x1b[32m';
const YELLOW = '\x1b[33m';
const BLUE = '\x1b[34m';
const RESET = '\x1b[0m';
const BOLD = '\x1b[1m';

console.log(`
${BOLD}${GREEN}✓ tree-sitter-plantuml installed successfully!${RESET}

${BOLD}Default Mode: WebAssembly (WASM)${RESET}
  ${GREEN}✓${RESET} Zero build tools required
  ${GREEN}✓${RESET} Works in Node.js and browsers
  ${GREEN}✓${RESET} Cross-platform without compilation

${BOLD}Usage:${RESET}
  ${BLUE}// WASM (default - recommended)${RESET}
  import { PlantUMLParser } from 'tree-sitter-plantuml';

  ${BLUE}// Native bindings (opt-in for ~2x performance)${RESET}
  import { PlantUMLParser } from 'tree-sitter-plantuml/native';

  ${BLUE}// Normalizer only${RESET}
  import { PlantUMLNormalizer } from 'tree-sitter-plantuml/normalizer';

${BOLD}Installation Scenarios:${RESET}
`);

// Check if prebuilt binaries exist
const prebuildDir = path.join(__dirname, '..', 'prebuilds');
const hasPrebuilds = fs.existsSync(prebuildDir) &&
                     fs.readdirSync(prebuildDir).length > 0;

if (hasPrebuilds) {
  console.log(`  ${GREEN}✓${RESET} Prebuilt native binaries detected`);
  console.log(`    Available for opt-in via 'tree-sitter-plantuml/native'`);
} else {
  console.log(`  ${YELLOW}ℹ${RESET} No prebuilt binaries found`);
  console.log(`    Using WASM (zero-friction installation)`);
  console.log(`    Native bindings available if you run: npm run build:native`);
}

// Check if build directory exists (successful native compilation)
const buildDir = path.join(__dirname, '..', 'build');
if (fs.existsSync(buildDir)) {
  console.log(`  ${GREEN}✓${RESET} Native bindings compiled successfully`);
}

console.log(`
${BOLD}Troubleshooting:${RESET}
  • Behind a proxy? WASM works without GitHub downloads
  • Missing compiler? Use WASM (default) - no compilation needed
  • Browser usage? WASM is the only option

${BOLD}Documentation:${RESET}
  Repository: https://github.com/SaeedNMosleh/PlantUML-Parser
  Issues:     https://github.com/SaeedNMosleh/PlantUML-Parser/issues

${GREEN}Happy parsing! 🎉${RESET}
`);

// Silent exit - don't fail installation if this script has issues
process.exit(0);
