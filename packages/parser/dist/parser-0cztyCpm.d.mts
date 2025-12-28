import { e as ParseNormalizedOptions, P as ParserInitOptions, c as ParseOptions, d as ParseResult, b as NormalizationResult, a as PlantUMLNormalizer } from './index-ChK5hs1F.mjs';

interface PlantUMLBackend {
    parseNormalized(source: string, options?: ParseNormalizedOptions): {
        tree: unknown;
    };
    getLanguage(): unknown;
    getParser(): unknown;
}

declare class PlantUMLParser {
    private readonly options;
    private readonly normalizer;
    private readonly backend;
    constructor(backend: PlantUMLBackend, options?: ParserInitOptions);
    parse(source: string, options?: ParseOptions): ParseResult;
    normalize(source: string): NormalizationResult;
    parseNormalized(source: string, options?: ParseOptions): ParseResult;
    parseToJSON(source: string, options?: ParseOptions): unknown;
    getLanguage(): unknown;
    getParser(): unknown;
    getNormalizer(): PlantUMLNormalizer;
}

export { PlantUMLParser as P };
