'use strict';

/**
 * PlantUML Parser - Main Entry Point (Node.js with Native Bindings)
 *
 * This is the high-level API for parsing PlantUML in Node.js environments.
 * For browser usage, use require('tree-sitter-plantuml/wasm') instead.
 *
 * Two-Pass Architecture:
 * 1. Normalizer (Pass 1): Transforms ambiguous PlantUML → normalized form
 * 2. Parser (Pass 2): Parses normalized PlantUML into AST
 */

const Parser = require('tree-sitter');
const PlantUMLNormalizer = require('./src/normalizer');

// Load the native binding
let binding;
let language;

try {
  // Try to load from build directory first
  binding = require('./build/Release/tree_sitter_plantuml_binding.node');
  language = binding.language;
} catch (error1) {
  try {
    // Fallback to Debug build
    binding = require('./build/Debug/tree_sitter_plantuml_binding.node');
    language = binding.language;
  } catch (error2) {
    try {
      // Use bindings/node loader (which tries node-gyp-build)
      binding = require('./bindings/node');
      language = binding.language;
    } catch (error3) {
      throw new Error(
        'Failed to load tree-sitter-plantuml native binding. ' +
        'Run `npm run build` to compile the native module.\n\n' +
        'For browser usage without native bindings, use:\n' +
        '  const PlantUMLParser = require("tree-sitter-plantuml/wasm");\n'
      );
    }
  }
}

/**
 * Main PlantUML Parser class (Node.js with native bindings)
 *
 * @example
 * const PlantUMLParser = require('tree-sitter-plantuml');
 * const parser = new PlantUMLParser();
 *
 * const source = `@startuml
 * start
 * :Task;
 * stop
 * @enduml`;
 *
 * const result = parser.parse(source);
 * console.log(result.tree.rootNode.toString());
 */
class PlantUMLParser {
  /**
   * Create a new PlantUML parser instance
   * @param {Object} options - Configuration options
   * @param {boolean} options.debug - Enable debug mode (default: false)
   * @param {boolean} options.preserveComments - Preserve comments during normalization (default: true)
   * @param {boolean} options.preserveWhitespace - Preserve original whitespace (default: false)
   * @param {boolean} options.skipNormalization - Skip normalization step (default: false)
   */
  constructor(options = {}) {
    this.options = {
      debug: false,
      preserveComments: true,
      preserveWhitespace: false,
      skipNormalization: false,
      ...options
    };

    // Initialize tree-sitter parser with native bindings
    this.parser = new Parser();
    this.language = language;
    this.parser.setLanguage(this.language);

    // Initialize normalizer
    this.normalizer = new PlantUMLNormalizer(this.options);
  }

  /**
   * Parse PlantUML source code (two-pass architecture)
   *
   * @param {string} source - Raw PlantUML source code
   * @param {Object} options - Parse options
   * @param {boolean} options.skipNormalization - Skip normalization for this parse (default: false)
   * @returns {Object} { tree: Tree, normalized: string, metadata: Object }
   */
  parse(source, options = {}) {
    const skipNorm = options.skipNormalization ?? this.options.skipNormalization;

    let normalized, metadata;

    if (!skipNorm) {
      // Pass 1: Normalize
      const result = this.normalizer.normalize(source);
      normalized = result.normalized;
      metadata = result.metadata;
    } else {
      // Skip normalization
      normalized = source;
      metadata = {};
    }

    // Pass 2: Parse with tree-sitter
    const tree = this.parser.parse(normalized);

    return { tree, normalized, metadata };
  }

  /**
   * Normalize PlantUML source without parsing
   * Useful for debugging or when you only need normalization
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
}

// Export main parser class
module.exports = PlantUMLParser;

// Export normalizer class for standalone use
module.exports.PlantUMLNormalizer = PlantUMLNormalizer;

// Export language for direct tree-sitter usage
module.exports.language = language;
