import PlantUMLNormalizer from '../normalizer';
import type { PlantUMLBackend } from './backend';
import type { NormalizationResult, ParseOptions, ParseResult, ParserInitOptions } from './types';

export default class PlantUMLParser {
  private readonly options: Required<ParserInitOptions>;
  private readonly normalizer: PlantUMLNormalizer;
  private readonly backend: PlantUMLBackend;

  constructor(backend: PlantUMLBackend, options: ParserInitOptions = {}) {
    this.backend = backend;
    this.options = {
      debug: options.debug ?? false,
      preserveComments: options.preserveComments ?? true,
      preserveWhitespace: options.preserveWhitespace ?? false,
      skipNormalization: options.skipNormalization ?? false
    };

    this.normalizer = new PlantUMLNormalizer({
      debug: this.options.debug,
      preserveComments: this.options.preserveComments,
      preserveWhitespace: this.options.preserveWhitespace
    });
  }

  parse(source: string, options: ParseOptions = {}): ParseResult {
    const skip = options.skipNormalization ?? this.options.skipNormalization;

    if (skip) {
      return this.backend.parseNormalized(source, { oldTree: options.oldTree });
    }

    const norm = this.normalize(source);
    const parsed = this.backend.parseNormalized(norm.normalized, { oldTree: options.oldTree });

    return {
      tree: parsed.tree,
      normalized: norm.normalized,
      metadata: norm.metadata
    };
  }

  normalize(source: string): NormalizationResult {
    return this.normalizer.normalize(source);
  }

  parseNormalized(source: string, options: ParseOptions = {}): ParseResult {
    const parsed = this.backend.parseNormalized(source, { oldTree: options.oldTree });
    return { tree: parsed.tree };
  }

  parseToJSON(source: string, options: ParseOptions = {}): unknown {
    const { tree } = this.parse(source, options);
    // Tree-sitter nodes serialize poorly; keep simple for now.
    // Consumers should walk tree.rootNode.
    // eslint-disable-next-line @typescript-eslint/no-explicit-any
    return (tree as any)?.rootNode ?? tree;
  }

  getLanguage(): unknown {
    return this.backend.getLanguage();
  }

  getParser(): unknown {
    return this.backend.getParser();
  }

  getNormalizer(): PlantUMLNormalizer {
    return this.normalizer;
  }
}
