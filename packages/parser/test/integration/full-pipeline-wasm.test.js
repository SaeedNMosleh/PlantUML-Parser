/**
 * Full pipeline integration tests (WASM Runtime)
 * Tests the complete flow: Raw PlantUML → Normalizer → Parser → AST
 * Uses WASM backend (web-tree-sitter) instead of native Node.js binding
 */

const { createParser } = require('../../dist/wasm.cjs');
const path = require('path');

describe('Full Pipeline Integration (WASM)', () => {
  let parser;

  beforeEach(async () => {
    // Create WASM parser with explicit path for CI stability
    parser = await createParser({
      wasmPath: path.resolve(__dirname, '../../tree-sitter-plantuml.wasm')
    });
  });

  function rootHasError(tree) {
    const root = tree.rootNode;
    // tree-sitter (node) exposes `hasError()` as a method.
    // Some runtimes expose it as a boolean property.
    return typeof root.hasError === 'function' ? root.hasError() : root.hasError;
  }

  describe('Simple Diagrams', () => {
    test('parses simple activity diagram with (*) nodes', () => {
      const input = `@startuml
(*)
:Task;
(*)
@enduml`;

      const result = parser.parse(input);

      expect(result).toHaveProperty('tree');
      expect(result).toHaveProperty('normalized');
      expect(result).toHaveProperty('metadata');

      // Verify normalization converted (*) to start/stop
      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain('stop');
      expect(result.normalized).toContain(':Task;');

      // Verify tree was created
      expect(result.tree.rootNode.type).toBe('source_file');
      expect(rootHasError(result.tree)).toBe(false);
    });

    test('parses activity diagram with explicit start/stop', () => {
      const input = `@startuml
start
:Initialize;
:Process;
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.metadata.diagramType).toBe('activity');
      expect(result.metadata.nodeCount).toBeGreaterThan(0);
    });
  });

  describe('Control Flow', () => {
    test('parses if-then-else statement', () => {
      const input = `@startuml
start
if (Ready?) then (yes)
  :Process;
else (no)
  :Wait;
endif
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('if (Ready?) then (yes)');
      expect(result.normalized).toContain('else (no)');
      expect(result.normalized).toContain('endif');
    });

    test('parses while loop', () => {
      const input = `@startuml
start
while (More data?) is (yes)
  :Process item;
endwhile (done)
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('while (More data?) is (yes)');
      expect(result.normalized).toContain('endwhile (done)');
    });

    test('parses repeat-while loop', () => {
      const input = `@startuml
start
repeat
  :Task;
repeat while (Again?)
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('repeat');
      expect(result.normalized).toContain('repeat while');
    });
  });

  describe('Complex Scenarios', () => {
    test('parses diagram with nested control structures', () => {
      const input = `@startuml
start
if (Has data?) then (yes)
  while (More items?) is (yes)
    if (Valid?) then (yes)
      :Process;
    else (no)
      :Skip;
    endif
  endwhile
endif
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.metadata.diagramType).toBe('activity');
    });

    test('parses diagram with partitions', () => {
      const input = `@startuml
start
partition "Phase 1" #LightBlue {
  :Task 1;
  :Task 2;
}
partition "Phase 2" {
  :Task 3;
}
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('partition "Phase 1" #LightBlue {');
      expect(result.normalized).toContain('partition "Phase 2" {');
    });

    test('parses diagram with arrows and labels', () => {
      const input = `@startuml
start
:Task 1;
-> :Next step
:Task 2;
--> :Another way
:Task 3;
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('->');
      expect(result.normalized).toContain('-->');
    });

    test('parses diagram with fork and join', () => {
      const input = `@startuml
start
fork
  :Parallel A;
fork again
  :Parallel B;
end fork
:Merge;
stop
@enduml`;

      const result = parser.parse(input);

      expect(rootHasError(result.tree)).toBe(false);
      expect(result.normalized).toContain('fork');
      expect(result.normalized).toContain('fork again');
      expect(result.normalized).toContain('end fork');
    });
  });

  describe('Metadata', () => {
    test('provides correct metadata for activity diagram', () => {
      const input = `@startuml
(*)
:Task 1;
:Task 2;
(*)
@enduml`;

      const result = parser.parse(input);

      expect(result.metadata).toHaveProperty('diagramType');
      expect(result.metadata).toHaveProperty('nodeCount');
      expect(result.metadata).toHaveProperty('hasCircleNodes');
      expect(result.metadata).toHaveProperty('circleNodeCount');

      expect(result.metadata.diagramType).toBe('activity');
      expect(result.metadata.hasCircleNodes).toBe(true);
      expect(result.metadata.circleNodeCount).toBe(2);
    });
  });

  describe('API Methods', () => {
    test('parseToJSON returns valid JSON structure', () => {
      const input = `@startuml
start
:Task;
stop
@enduml`;

      const json = parser.parseToJSON(input);

      expect(json).toHaveProperty('type');
      expect(json).toHaveProperty('startPosition');
      expect(json).toHaveProperty('endPosition');
      expect(json.type).toBe('source_file');
    });

    test('normalize method returns only normalization result', () => {
      const input = `@startuml
(*)
:Task;
(*)
@enduml`;

      const result = parser.normalize(input);

      expect(result).toHaveProperty('normalized');
      expect(result).toHaveProperty('metadata');
      expect(result).not.toHaveProperty('tree');

      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain('stop');
    });

    test('parseNormalized skips normalization', () => {
      const normalizedInput = `@startuml
start
:Task;
stop
@enduml`;

      const result = parser.parseNormalized(normalizedInput);

      expect(result).toHaveProperty('tree');
      expect(result).not.toHaveProperty('normalized');
      expect(result).not.toHaveProperty('metadata');
    });
  });

  describe('Options', () => {
    test('respects preserveComments option', async () => {
      const input = `@startuml
' This is a comment
start
:Task;
stop
@enduml`;

      const withComments = await createParser({
        wasmPath: path.resolve(__dirname, '../../tree-sitter-plantuml.wasm'),
        preserveComments: true
      });
      const withoutComments = await createParser({
        wasmPath: path.resolve(__dirname, '../../tree-sitter-plantuml.wasm'),
        preserveComments: false
      });

      const result1 = withComments.parse(input);
      const result2 = withoutComments.parse(input);

      expect(result1.normalized).toContain("' This is a comment");
      expect(result2.normalized).not.toContain("' This is a comment");
    });

    test('skipNormalization option works', async () => {
      const input = `@startuml
start
:Task;
stop
@enduml`;

      const skipParser = await createParser({
        wasmPath: path.resolve(__dirname, '../../tree-sitter-plantuml.wasm'),
        skipNormalization: true
      });
      const result = skipParser.parse(input);

      expect(result).toHaveProperty('tree');
      expect(result).not.toHaveProperty('normalized');
      expect(result).not.toHaveProperty('metadata');
    });
  });

  describe('Error Handling', () => {
    test('handles empty input', () => {
      const result = parser.parse('');

      expect(result).toHaveProperty('tree');
      expect(result.metadata.nodeCount).toBe(0);
    });

    test('handles malformed PlantUML gracefully', () => {
      const input = `@startuml
:Incomplete activity
@enduml`;

      // Should not throw
      expect(() => parser.parse(input)).not.toThrow();
    });
  });
});
