import type { ParseNormalizedOptions, ParseResult } from './types';

export interface PlantUMLBackend {
  parseNormalized(source: string, options?: ParseNormalizedOptions): { tree: unknown };
  getLanguage(): unknown;
  getParser(): unknown;
}

export type BackendFactory = () => PlantUMLBackend;
