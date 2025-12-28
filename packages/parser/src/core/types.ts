export type Point = { row: number; column: number };
export type Range = { start: Point; end: Point };

export type SourceMap = {
  /** For each normalized line index, the originating original line index. */
  normalizedLineToOriginalLine: number[];
};

export type NormalizationMetadata = {
  diagramType?: string | null;
  nodeCount?: number;
  hasCircleNodes?: boolean;
  circleNodeCount?: number;
  sourceMap?: SourceMap;
};

export type NormalizationResult = {
  normalized: string;
  metadata: NormalizationMetadata;
};

export type ParseOptions = {
  skipNormalization?: boolean;
  oldTree?: unknown;
};

export type ParseNormalizedOptions = {
  oldTree?: unknown;
};

export type ParseResult = {
  tree: unknown;
  normalized?: string;
  metadata?: NormalizationMetadata;
};

export type ParserInitOptions = {
  debug?: boolean;
  preserveComments?: boolean;
  preserveWhitespace?: boolean;
  skipNormalization?: boolean;
};
