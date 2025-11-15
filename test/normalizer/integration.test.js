/**
 * Normalizer integration tests
 */

const PlantUMLNormalizer = require('../../src/normalizer');

describe('Normalizer Integration Tests', () => {
  let normalizer;

  beforeEach(() => {
    normalizer = new PlantUMLNormalizer();
  });

  describe('Real-world Scenarios', () => {
    test('normalizes complete workflow diagram', () => {
      const input = `@startuml
(*)
:Initialize system;
if (Has data?) then (yes)
  while (More items?) is (yes)
    :Process item;
  endwhile (done)
else (no)
  :Load data;
endif
:Finalize;
(*)
@enduml`;

      const result = normalizer.normalize(input);

      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain('stop');
      expect(result.normalized).toContain(':Initialize system;');
      expect(result.normalized).toContain(':Finalize;');
      expect(result.metadata.diagramType).toBe('activity');
    });

    test('normalizes diagram with partitions', () => {
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

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('partition "Phase 1" #LightBlue {');
      expect(result.normalized).toContain('partition "Phase 2" {');
      expect(result.normalized).toContain('}');
    });

    test('normalizes diagram with notes', () => {
      const input = `@startuml
start
:Task;
note right: This is important
:Another task;
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('note right: This is important');
    });

    test('normalizes diagram with fork and merge', () => {
      const input = `@startuml
start
fork
  :Parallel task 1;
fork again
  :Parallel task 2;
fork again
  :Parallel task 3;
end fork
:Merge point;
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('fork');
      expect(result.normalized).toContain('fork again');
      expect(result.normalized).toContain('end fork');
    });
  });

  describe('Edge Cases and Error Handling', () => {
    test('handles missing @enduml', () => {
      const input = `@startuml
start
:Task;`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('start');
      expect(result.normalized).toContain(':Task;');
    });

    test('handles multiple diagrams in one source', () => {
      const input = `@startuml
start
:Task 1;
stop
@enduml

@startuml
start
:Task 2;
stop
@enduml`;

      const result = normalizer.normalize(input);
      const startumlCount = (result.normalized.match(/@startuml/g) || []).length;
      const endumlCount = (result.normalized.match(/@enduml/g) || []).length;
      expect(startumlCount).toBe(2);
      expect(endumlCount).toBe(2);
    });

    test('handles complex nested structures', () => {
      const input = `@startuml
start
partition "Main" {
  if (x?) then (yes)
    while (y?) is (yes)
      fork
        :Task A;
      fork again
        :Task B;
      end fork
    endwhile
  endif
}
stop
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('partition');
      expect(result.normalized).toContain('if (x?) then (yes)');
      expect(result.normalized).toContain('while (y?) is (yes)');
      expect(result.normalized).toContain('fork');
    });
  });

  describe('Options and Configuration', () => {
    test('respects preserveComments option', () => {
      const input = `@startuml
' Comment 1
start
' Comment 2
:Task;
@enduml`;

      const withComments = new PlantUMLNormalizer({ preserveComments: true });
      const withoutComments = new PlantUMLNormalizer({ preserveComments: false });

      const result1 = withComments.normalize(input);
      const result2 = withoutComments.normalize(input);

      expect(result1.normalized).toContain("' Comment");
      expect(result2.normalized).not.toContain("' Comment");
    });

    test('respects preserveWhitespace option', () => {
      const input = `@startuml
start
  :Indented task;
stop
@enduml`;

      const withWhitespace = new PlantUMLNormalizer({ preserveWhitespace: true });
      const withoutWhitespace = new PlantUMLNormalizer({ preserveWhitespace: false });

      const result1 = withWhitespace.normalize(input);
      const result2 = withoutWhitespace.normalize(input);

      expect(result1.normalized).toContain('  :Indented task;');
      expect(result2.normalized).toContain('  :Indented task;');
    });
  });

  describe('Metadata Generation', () => {
    test('generates complete metadata', () => {
      const input = `@startuml
(*)
:Task 1;
:Task 2;
(*)
@enduml`;

      const result = normalizer.normalize(input);

      expect(result.metadata).toHaveProperty('diagramType');
      expect(result.metadata).toHaveProperty('nodeCount');
      expect(result.metadata).toHaveProperty('hasCircleNodes');
      expect(result.metadata).toHaveProperty('circleNodeCount');

      expect(result.metadata.diagramType).toBe('activity');
      expect(result.metadata.hasCircleNodes).toBe(true);
      expect(result.metadata.circleNodeCount).toBe(2);
    });
  });
});
