import { P as PlantUMLParser } from './parser-0cztyCpm.mjs';
import { P as ParserInitOptions } from './index-ChK5hs1F.mjs';
export { N as NormalizationMetadata, b as NormalizationResult, c as ParseOptions, d as ParseResult, a as PlantUMLNormalizer, S as SourceMap } from './index-ChK5hs1F.mjs';

type WasmInitOptions = {
    wasmPath?: string;
};

declare class PlantUMLParserWasm extends PlantUMLParser {
    private constructor();
    static create(options?: ParserInitOptions & WasmInitOptions): Promise<PlantUMLParserWasm>;
}
declare function createParser(options?: ParserInitOptions & WasmInitOptions): Promise<PlantUMLParserWasm>;

export { ParserInitOptions, PlantUMLParserWasm, createParser };
