import PlantUMLParser from './core/parser';
import PlantUMLNormalizer from './normalizer';
import { createNodeNativeBackend } from './runtimes/node-native';
import type { ParserInitOptions } from './core/types';

export default class PlantUMLParserNode extends PlantUMLParser {
  constructor(options: ParserInitOptions = {}) {
    super(createNodeNativeBackend(), options);
  }
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
