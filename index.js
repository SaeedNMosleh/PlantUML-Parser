'use strict';

const Parser = require('tree-sitter');
const PlantUMLNormalizer = require('./src/normalizer');

// Load the native binding directly
let binding;
let language;

try {
  // Try direct path to compiled binding
  binding = require('./build/Release/tree_sitter_plantuml_binding.node');
  language = binding.language;
} catch (error) {
  try {
    // Fallback to bindings/node module
    binding = require('./bindings/node');
    language = binding.language;
  } catch (error2) {
    throw new Error(`Failed to load tree-sitter-plantuml binding. Run 'npm run build' first. Error: ${error2.message}`);
  }
}

if (!language) {
  throw new Error('Tree-sitter PlantUML language object is unavailable. Build the parser via `npm run build`.');
}

const nodeTypeInfo = binding.nodeTypeInfo;

class PlantUMLParser {
  constructor(options = {}) {
    this.options = {
      debug: false,
      preserveComments: true,
      preserveWhitespace: false,
      skipNormalization: false,
      ...options
    };

    this.normalizerOptions = {
      debug: this.options.debug,
      preserveComments: this.options.preserveComments,
      preserveWhitespace: this.options.preserveWhitespace
    };

    this.parser = new Parser();
    this.language = language;
    this.parser.setLanguage(this.language);

    this.normalizer = new PlantUMLNormalizer(this.normalizerOptions);
  }

  createNormalizer(overrides = {}) {
    const hasOverrides = overrides && Object.keys(overrides).length > 0;
    if (!hasOverrides) {
      return this.normalizer;
    }

    return new PlantUMLNormalizer({
      ...this.normalizerOptions,
      ...overrides
    });
  }

  parse(source, options = {}) {
    const effectiveSkip = options.skipNormalization ?? this.options.skipNormalization;

    if (effectiveSkip) {
      const tree = this.parser.parse(source, options.oldTree);
      return { tree };
    }

    const normalizer = this.createNormalizer(options.normalizerOptions);
    const { normalized, metadata } = normalizer.normalize(source);
    const tree = this.parser.parse(normalized, options.oldTree);

    return { tree, normalized, metadata };
  }

  parseNormalized(source, options = {}) {
    const tree = this.parser.parse(source, options.oldTree);
    return { tree };
  }

  normalize(source, overrides = {}) {
    const normalizer = this.createNormalizer(overrides);
    return normalizer.normalize(source);
  }

  parseToJSON(source, options = {}) {
    const { tree } = this.parse(source, options);
    return this.treeToJSON(tree.rootNode);
  }

  treeToJSON(node) {
    const result = {
      type: node.type,
      named: node.isNamed(),
      startPosition: node.startPosition,
      endPosition: node.endPosition,
      children: []
    };

    for (let i = 0; i < node.childCount; i += 1) {
      result.children.push(this.treeToJSON(node.child(i)));
    }

    return result;
  }

  getLanguage() {
    return this.language;
  }

  getParser() {
    return this.parser;
  }

  getNormalizer() {
    return this.normalizer;
  }
}

module.exports = PlantUMLParser;
module.exports.language = language;
if (nodeTypeInfo) {
  module.exports.nodeTypeInfo = nodeTypeInfo;
}
module.exports.PlantUMLNormalizer = PlantUMLNormalizer;