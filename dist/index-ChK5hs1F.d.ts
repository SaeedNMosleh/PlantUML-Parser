type SourceMap = {
    /** For each normalized line index, the originating original line index. */
    normalizedLineToOriginalLine: number[];
};
type NormalizationMetadata = {
    diagramType?: string | null;
    nodeCount?: number;
    hasCircleNodes?: boolean;
    circleNodeCount?: number;
    sourceMap?: SourceMap;
};
type NormalizationResult = {
    normalized: string;
    metadata: NormalizationMetadata;
};
type ParseOptions = {
    skipNormalization?: boolean;
    oldTree?: unknown;
};
type ParseNormalizedOptions = {
    oldTree?: unknown;
};
type ParseResult = {
    tree: unknown;
    normalized?: string;
    metadata?: NormalizationMetadata;
};
type ParserInitOptions = {
    debug?: boolean;
    preserveComments?: boolean;
    preserveWhitespace?: boolean;
    skipNormalization?: boolean;
};

type NormalizerOptions = {
    debug?: boolean;
    preserveComments?: boolean;
    preserveWhitespace?: boolean;
};
declare class PlantUMLNormalizer {
    private debug;
    private preserveComments;
    private preserveWhitespace;
    private diagramType;
    private context;
    constructor(options?: NormalizerOptions);
    normalize(source: string): NormalizationResult;
    private normalizeLine;
    private getIndent;
    private normalizeCircleNode;
    private normalizeActivityNode;
    private normalizeArrow;
    private normalizeControlFlow;
    private normalizeGrouping;
    private normalizeNote;
    private normalizeDirective;
    private postProcess;
    private detectDiagramType;
    private updateContext;
    private resetContext;
    private getMetadata;
    private log;
}

export { type NormalizationMetadata as N, type ParserInitOptions as P, type SourceMap as S, PlantUMLNormalizer as a, type NormalizationResult as b, type ParseOptions as c, type ParseResult as d, type ParseNormalizedOptions as e };
