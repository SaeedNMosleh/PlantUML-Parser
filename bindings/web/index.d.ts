/**
 * TypeScript definitions for tree-sitter-plantuml Web/WASM bindings
 */

import { Tree, Parser as TreeSitterParser } from 'web-tree-sitter';

/**
 * Configuration options for PlantUML parser
 */
export interface PlantUMLParserOptions {
  /**
   * Enable debug mode with verbose logging
   * @default false
   */
  debug?: boolean;

  /**
   * Preserve comments during normalization
   * @default true
   */
  preserveComments?: boolean;

  /**
   * Preserve original whitespace formatting
   * @default false
   */
  preserveWhitespace?: boolean;

  /**
   * Skip normalization step entirely
   * @default false
   */
  skipNormalization?: boolean;

  /**
   * Path to the WASM file
   * @default 'tree-sitter-plantuml.wasm'
   */
  wasmPath?: string;
}

/**
 * Options for individual parse operations
 */
export interface ParseOptions {
  /**
   * Skip normalization for this specific parse operation
   */
  skipNormalization?: boolean;
}

/**
 * Metadata about the parsed PlantUML diagram
 */
export interface NormalizationMetadata {
  /**
   * Detected diagram type (e.g., 'activity', 'sequence', 'class')
   */
  diagramType: string | null;

  /**
   * Total number of nodes found
   */
  nodeCount: number;

  /**
   * Whether the diagram contains circle nodes (*)
   */
  hasCircleNodes: boolean;

  /**
   * Count of circle nodes that were normalized
   */
  circleNodeCount: number;
}

/**
 * Result of normalization operation
 */
export interface NormalizationResult {
  /**
   * Normalized PlantUML source code
   */
  normalized: string;

  /**
   * Metadata about the normalization
   */
  metadata: NormalizationMetadata;
}

/**
 * Result of parse operation
 */
export interface ParseResult {
  /**
   * Tree-sitter syntax tree
   */
  tree: Tree;

  /**
   * Normalized PlantUML source (if normalization was performed)
   */
  normalized: string;

  /**
   * Metadata about the normalization (if normalization was performed)
   */
  metadata: NormalizationMetadata | Record<string, never>;
}

/**
 * PlantUML normalizer class (browser-compatible, pure JavaScript)
 * Can be used standalone without WASM for normalization-only workflows
 */
export class PlantUMLNormalizer {
  /**
   * Create a new normalizer instance
   * @param options - Configuration options
   */
  constructor(options?: {
    debug?: boolean;
    preserveComments?: boolean;
    preserveWhitespace?: boolean;
  });

  /**
   * Normalize PlantUML source code
   * @param source - Raw PlantUML source code
   * @returns Normalized source and metadata
   */
  normalize(source: string): NormalizationResult;
}

/**
 * PlantUML Parser for Web/Browser environments (using WASM)
 *
 * @example
 * ```typescript
 * import { createParser } from 'tree-sitter-plantuml/wasm';
 *
 * const parser = await createParser({
 *   wasmPath: '/assets/tree-sitter-plantuml.wasm'
 * });
 *
 * const result = parser.parse(`@startuml
 * start
 * :Task;
 * stop
 * @enduml`);
 *
 * console.log(result.tree.rootNode.toString());
 * ```
 */
export class PlantUMLParserWeb {
  /**
   * Create a new PlantUML parser instance for web/browser
   * NOTE: Must call init() before using!
   *
   * @param options - Configuration options
   */
  constructor(options?: PlantUMLParserOptions);

  /**
   * Initialize the parser by loading WASM
   * MUST be called before parsing!
   *
   * @param wasmPath - Optional path to WASM file (overrides constructor option)
   * @returns This instance (for chaining)
   *
   * @example
   * ```typescript
   * const parser = new PlantUMLParserWeb();
   * await parser.init('/path/to/tree-sitter-plantuml.wasm');
   * ```
   */
  init(wasmPath?: string): Promise<PlantUMLParserWeb>;

  /**
   * Parse PlantUML source code (two-pass architecture)
   *
   * @param source - Raw PlantUML source code
   * @param options - Parse options
   * @returns Parse result with tree, normalized source, and metadata
   * @throws Error if parser is not initialized
   */
  parse(source: string, options?: ParseOptions): ParseResult;

  /**
   * Normalize PlantUML source without parsing
   * Useful for debugging or when you only need normalization
   * Does NOT require initialization (no WASM needed)
   *
   * @param source - Raw PlantUML source code
   * @returns Normalized source and metadata
   */
  normalize(source: string): NormalizationResult;

  /**
   * Parse already-normalized PlantUML source
   * Skips the normalization step
   *
   * @param source - Pre-normalized PlantUML source
   * @returns Parse result
   */
  parseNormalized(source: string): ParseResult;

  /**
   * Check if parser is initialized
   * @returns true if init() has been called successfully
   */
  isInitialized(): boolean;
}

/**
 * Convenience function to create and initialize parser in one step
 *
 * @param options - Configuration options
 * @returns Initialized parser instance
 *
 * @example
 * ```typescript
 * import { createParser } from 'tree-sitter-plantuml/wasm';
 *
 * const parser = await createParser({
 *   wasmPath: '/assets/tree-sitter-plantuml.wasm',
 *   debug: true
 * });
 *
 * const result = parser.parse(source);
 * ```
 */
export function createParser(options?: PlantUMLParserOptions): Promise<PlantUMLParserWeb>;

// Default export is the parser class
export default PlantUMLParserWeb;
