/**
 * Core normalizer tests
 */

const { default: PlantUMLNormalizer } = require('../../dist/normalizer.cjs');

describe('PlantUMLNormalizer', () => {
  let normalizer;

  beforeEach(() => {
    normalizer = new PlantUMLNormalizer();
  });

  describe('Circle Node Normalization', () => {
    test('converts first (*) to start', () => {
      const input = `@startuml
(*)
:Activity 1;
(*)
@enduml`;

      const expected = `@startuml
start
:Activity 1;
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('handles multiple (*) correctly', () => {
      const input = `@startuml
(*)
:Task 1;
(*)
:Task 2;
(*)
@enduml`;

      const expected = `@startuml
start
:Task 1;
stop
:Task 2;
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('handles single (*) as start', () => {
      const input = `@startuml
(*)
:Single task;
@enduml`;

      const expected = `@startuml
start
:Single task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('metadata tracks circle nodes', () => {
      const input = `@startuml
(*)
:Task;
(*)
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.metadata.hasCircleNodes).toBe(true);
      expect(result.metadata.circleNodeCount).toBe(2);
    });
  });

  describe('Activity Node Normalization', () => {
    test('normalizes activity node spacing', () => {
      const input = `@startuml
: Activity with spaces ;
@enduml`;

      const expected = `@startuml
:Activity with spaces;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('preserves activity node content', () => {
      const input = `@startuml
:Process data;
:Transform results;
:Save to database;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain(':Process data;');
      expect(result.normalized).toContain(':Transform results;');
      expect(result.normalized).toContain(':Save to database;');
    });

    test('handles empty activity nodes', () => {
      const input = `@startuml
:;
@enduml`;

      const expected = `@startuml
:;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });
  });

  describe('Diagram Boundaries', () => {
    test('preserves startuml directive', () => {
      const input = `@startuml
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('@startuml');
      expect(result.normalized).toContain('@enduml');
    });

    test('handles startuml with name', () => {
      const input = `@startuml MyDiagram
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('@startuml MyDiagram');
    });

    test('only processes content inside diagram boundaries', () => {
      const input = `Some text before
@startuml
:Task;
@enduml
Some text after`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('Some text before');
      expect(result.normalized).toContain('Some text after');
    });
  });

  describe('Comment Handling', () => {
    test('preserves comments when preserveComments is true', () => {
      const normalizer = new PlantUMLNormalizer({ preserveComments: true });
      const input = `@startuml
' This is a comment
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain("' This is a comment");
    });

    test('removes comments when preserveComments is false', () => {
      const normalizer = new PlantUMLNormalizer({ preserveComments: false });
      const input = `@startuml
' This is a comment
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).not.toContain("' This is a comment");
    });

    test('handles block comments', () => {
      const normalizer = new PlantUMLNormalizer({ preserveComments: true });
      const input = `@startuml
/' Block comment
   multiline '/
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      // Comments should be preserved or removed based on option
    });
  });

  describe('Whitespace Handling', () => {
    test('normalizes whitespace by default', () => {
      const input = `@startuml
:Task;


:Another task;
@enduml`;

      const result = normalizer.normalize(input);
      const lines = result.normalized.split('\n');
      // Empty lines should be collapsed
      const emptyLines = lines.filter(l => l.trim() === '');
      expect(emptyLines.length).toBeLessThan(3);
    });

    test('preserves whitespace when option is set', () => {
      const normalizer = new PlantUMLNormalizer({ preserveWhitespace: true });
      const input = `@startuml
  :Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('  :Task;');
    });
  });

  describe('Metadata Generation', () => {
    test('detects diagram type as activity', () => {
      const input = `@startuml
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.metadata.diagramType).toBe('activity');
    });

    test('counts nodes correctly', () => {
      const input = `@startuml
start
:Task 1;
:Task 2;
:Task 3;
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.metadata.nodeCount).toBeGreaterThan(0);
    });
  });

  describe('Empty and Invalid Input', () => {
    test('handles empty string', () => {
      const result = normalizer.normalize('');
      expect(result.normalized).toBe('');
    });

    test('handles diagram without content', () => {
      const input = `@startuml
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(input);
    });

    test('handles incomplete diagram', () => {
      const input = `@startuml
:Task;`;

      const result = normalizer.normalize(input);
      // Should handle gracefully
      expect(result.normalized).toContain(':Task;');
    });
  });

  describe('Context Management', () => {
    test('resets context between normalizations', () => {
      const input1 = `@startuml
(*)
:Task;
@enduml`;

      const input2 = `@startuml
(*)
:Another task;
@enduml`;

      const result1 = normalizer.normalize(input1);
      const result2 = normalizer.normalize(input2);

      // Both should normalize (*) to start
      expect(result1.normalized).toContain('start');
      expect(result2.normalized).toContain('start');
    });

    test('tracks state correctly within diagram', () => {
      const input = `@startuml
(*)
if (condition?) then (yes)
  :Task;
endif
(*)
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain('stop');
    });
  });

  describe('Complex Scenarios', () => {
    test('normalizes complete activity diagram', () => {
      const input = `@startuml
(*)
:Initialize;
if (Ready?) then (yes)
  :Process;
else (no)
  :Wait;
endif
(*)
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain('stop');
      expect(result.normalized).toContain('if (Ready?) then (yes)');
      expect(result.normalized).toContain('else (no)');
    });

    test('handles nested structures', () => {
      const input = `@startuml
start
if (outer?) then (yes)
  if (inner?) then (yes)
    :Task;
  endif
endif
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('if (outer?) then (yes)');
      expect(result.normalized).toContain('if (inner?) then (yes)');
    });
  });
});
