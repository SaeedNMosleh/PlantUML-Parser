import PlantUMLParser from './core/parser';
import PlantUMLNormalizer from './normalizer';
import { createWasmBackend, type WasmInitOptions } from './runtimes/wasm';
import type { ParserInitOptions } from './core/types';

export class PlantUMLParserWasm extends PlantUMLParser {
  private constructor(backend: Awaited<ReturnType<typeof createWasmBackend>>, options: ParserInitOptions = {}) {
    super(backend, options);
  }

  static async create(options: ParserInitOptions & WasmInitOptions = {}): Promise<PlantUMLParserWasm> {
    const backend = await createWasmBackend({ wasmPath: options.wasmPath });
    return new PlantUMLParserWasm(backend, options);
  }
}

export async function createParser(options: ParserInitOptions & WasmInitOptions = {}): Promise<PlantUMLParserWasm> {
  return PlantUMLParserWasm.create(options);
}

export { PlantUMLNormalizer };
export type {
  NormalizationMetadata,
  NormalizationResult,
  ParseOptions,
  ParseResult,
  ParserInitOptions,
  SourceMap
} from './core/types';
