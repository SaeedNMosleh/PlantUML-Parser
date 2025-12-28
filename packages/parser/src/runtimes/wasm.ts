import type { PlantUMLBackend } from '../core/backend';

// web-tree-sitter is an optional peer dependency.
// This module is intended to be imported via `tree-sitter-plantuml/wasm`.

export type WasmInitOptions = {
  wasmPath?: string;
};

export async function createWasmBackend(options: WasmInitOptions = {}): Promise<PlantUMLBackend> {
  // Dynamic import keeps Node-native users from pulling web-tree-sitter.
  const webTreeSitter = await import('web-tree-sitter');
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  const Parser: any = (webTreeSitter as any).default ?? webTreeSitter;

  await Parser.init();

  const parser = new Parser();
  const wasmPath = options.wasmPath ?? 'tree-sitter-plantuml.wasm';

  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  const language = await (Parser as any).Language.load(wasmPath);
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  (parser as any).setLanguage(language);

  return {
    parseNormalized(source: string) {
      // eslint-disable-next-line @typescript-eslint/no-explicit-any
      const tree = (parser as any).parse(source);
      return { tree };
    },
    getLanguage() {
      return language;
    },
    getParser() {
      return parser;
    }
  };
}
