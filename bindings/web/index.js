'use strict';

/**
 * PlantUML Parser - Web/WASM Bindings for Browser Usage
 *
 * This module provides browser-compatible bindings using WebAssembly.
 * Requires web-tree-sitter as a peer dependency.
 *
 * Usage:
 *   import { createParser } from 'tree-sitter-plantuml/wasm';
 *   const parser = await createParser({ wasmPath: '/path/to/tree-sitter-plantuml.wasm' });
 *   const result = parser.parse(source);
 */

const PlantUMLNormalizer = require('../../src/normalizer');

// Detect environment and load appropriate Parser
let Parser;
const isBrowser = typeof window !== 'undefined' || typeof importScripts !== 'undefined';

if (isBrowser) {
  // In browser, web-tree-sitter should be loaded via script tag or bundled
  if (typeof window !== 'undefined' && typeof window.TreeSitter !== 'undefined') {
    Parser = window.TreeSitter;
  } else if (typeof TreeSitter !== 'undefined') {
    // For web workers or other browser contexts
    Parser = TreeSitter;
  } else {
    throw new Error(
      'web-tree-sitter not found. ' +
      'Please load web-tree-sitter before using tree-sitter-plantuml/wasm.\n\n' +
      'Add to your HTML:\n' +
      '  <script src="https://cdn.jsdelivr.net/npm/web-tree-sitter@0.22.6"></script>\n\n' +
      'Or install via npm:\n' +
      '  npm install web-tree-sitter'
    );
  }
} else {
  // In Node.js, require web-tree-sitter
  try {
    Parser = require('web-tree-sitter');
  } catch (error) {
    throw new Error(
      'web-tree-sitter not found. Install it with:\n' +
      '  npm install web-tree-sitter\n\n' +
      'For Node.js native bindings (faster), use:\n' +
      '  const PlantUMLParser = require("tree-sitter-plantuml");\n'
    );
  }
}

/**
 * PlantUML Parser for Web/Browser environments (using WASM)
 *
 * @example
 * // In browser:
 * import { createParser } from 'tree-sitter-plantuml/wasm';
 * const parser = await createParser();
 * const result = parser.parse(source);
 *
 * @example
 * // With custom WASM path:
 * const parser = await createParser({
 *   wasmPath: '/assets/tree-sitter-plantuml.wasm'
 * });
 */
class PlantUMLParserWeb {
  /**
   * Create a new PlantUML parser instance for web/browser
   * NOTE: Must call init() before using!
   *
   * @param {Object} options - Configuration options
   * @param {boolean} options.debug - Enable debug mode (default: false)
   * @param {boolean} options.preserveComments - Preserve comments during normalization (default: true)
   * @param {boolean} options.preserveWhitespace - Preserve original whitespace (default: false)
   * @param {boolean} options.skipNormalization - Skip normalization step (default: false)
   * @param {string} options.wasmPath - Path to .wasm file (default: 'tree-sitter-plantuml.wasm')
   */
  constructor(options = {}) {
    this.options = {
      debug: false,
      preserveComments: true,
      preserveWhitespace: false,
      skipNormalization: false,
      wasmPath: null,
      ...options
    };

    this.normalizer = new PlantUMLNormalizer(this.options);
    this.parser = null;
    this.language = null;
    this.initialized = false;
  }

  /**
   * Initialize the parser by loading WASM
   * MUST be called before parsing!
   *
   * @param {string} wasmPath - Optional path to WASM file (overrides constructor option)
   * @returns {Promise<PlantUMLParserWeb>} This instance (for chaining)
   *
   * @example
   * const parser = new PlantUMLParserWeb();
   * await parser.init('/path/to/tree-sitter-plantuml.wasm');
   * const result = parser.parse(source);
   */
  async init(wasmPath) {
    if (this.initialized) {
      if (this.options.debug) {
        console.log('[PlantUMLParserWeb] Already initialized, skipping');
      }
      return this;
    }

    try {
      // Initialize web-tree-sitter (only needed once globally)
      await Parser.init();

      // Create parser instance
      this.parser = new Parser();

      // Determine WASM path
      const path = wasmPath || this.options.wasmPath || 'tree-sitter-plantuml.wasm';

      if (this.options.debug) {
        console.log('[PlantUMLParserWeb] Loading WASM from:', path);
      }

      // Load PlantUML language WASM
      this.language = await Parser.Language.load(path);
      this.parser.setLanguage(this.language);

      this.initialized = true;

      if (this.options.debug) {
        console.log('[PlantUMLParserWeb] Initialization complete');
      }

      return this;
    } catch (error) {
      throw new Error(
        `Failed to initialize PlantUML WASM parser: ${error.message}\n\n` +
        'Make sure:\n' +
        '1. web-tree-sitter is loaded\n' +
        '2. tree-sitter-plantuml.wasm file is accessible\n' +
        '3. WASM file is served with correct MIME type (application/wasm)\n\n' +
        `Original error: ${error.stack}`
      );
    }
  }

  /**
   * Parse PlantUML source code (two-pass architecture)
   *
   * @param {string} source - Raw PlantUML source code
   * @param {Object} options - Parse options
   * @param {boolean} options.skipNormalization - Skip normalization for this parse
   * @returns {Object} { tree: Tree, normalized: string, metadata: Object }
   *
   * @throws {Error} If parser is not initialized
   */
  parse(source, options = {}) {
    if (!this.initialized) {
      throw new Error(
        'Parser not initialized. Call await parser.init() before parsing.\n\n' +
        'Example:\n' +
        '  const parser = new PlantUMLParserWeb();\n' +
        '  await parser.init();\n' +
        '  const result = parser.parse(source);'
      );
    }

    const skipNorm = options.skipNormalization ?? this.options.skipNormalization;

    let normalized, metadata;

    if (!skipNorm) {
      // Pass 1: Normalize
      const result = this.normalizer.normalize(source);
      normalized = result.normalized;
      metadata = result.metadata;

      if (this.options.debug) {
        console.log('[PlantUMLParserWeb] Normalization complete:', {
          originalLength: source.length,
          normalizedLength: normalized.length,
          metadata
        });
      }
    } else {
      // Skip normalization
      normalized = source;
      metadata = {};
    }

    // Pass 2: Parse with tree-sitter WASM
    const tree = this.parser.parse(normalized);

    if (this.options.debug) {
      console.log('[PlantUMLParserWeb] Parsing complete:', {
        rootNodeType: tree.rootNode.type,
        childCount: tree.rootNode.childCount
      });
    }

    return { tree, normalized, metadata };
  }

  /**
   * Normalize PlantUML source without parsing
   * Useful for debugging or when you only need normalization
   * Does NOT require initialization (no WASM needed)
   *
   * @param {string} source - Raw PlantUML source code
   * @returns {Object} { normalized: string, metadata: Object }
   */
  normalize(source) {
    return this.normalizer.normalize(source);
  }

  /**
   * Parse already-normalized PlantUML source
   * Skips the normalization step
   *
   * @param {string} source - Pre-normalized PlantUML source
   * @returns {Object} { tree: Tree, normalized: string, metadata: Object }
   */
  parseNormalized(source) {
    return this.parse(source, { skipNormalization: true });
  }

  /**
   * Check if parser is initialized
   * @returns {boolean}
   */
  isInitialized() {
    return this.initialized;
  }
}

/**
 * Convenience function to create and initialize parser in one step
 *
 * @param {Object} options - Configuration options (same as PlantUMLParserWeb constructor)
 * @returns {Promise<PlantUMLParserWeb>} Initialized parser instance
 *
 * @example
 * import { createParser } from 'tree-sitter-plantuml/wasm';
 *
 * const parser = await createParser({
 *   wasmPath: '/assets/tree-sitter-plantuml.wasm'
 * });
 *
 * const result = parser.parse(source);
 */
async function createParser(options = {}) {
  const parser = new PlantUMLParserWeb(options);
  await parser.init(options.wasmPath);
  return parser;
}

// Export main class and convenience function
module.exports = PlantUMLParserWeb;
module.exports.PlantUMLParserWeb = PlantUMLParserWeb;
module.exports.createParser = createParser;
module.exports.PlantUMLNormalizer = PlantUMLNormalizer;
