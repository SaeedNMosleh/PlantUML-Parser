/**
 * Arrow normalization tests
 */

const PlantUMLNormalizer = require('../../src/normalizer');

describe('Arrow Normalization', () => {
  let normalizer;

  beforeEach(() => {
    normalizer = new PlantUMLNormalizer();
  });

  describe('Basic Arrows', () => {
    test('normalizes simple arrow', () => {
      const input = `@startuml
start
->
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('->');
    });

    test('normalizes dashed arrow', () => {
      const input = `@startuml
start
-->
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('-->');
    });

    test('normalizes thick arrow', () => {
      const input = `@startuml
start
->>
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('->>');
    });

    test('normalizes dotted arrow', () => {
      const input = `@startuml
start
.>
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('.>');
    });
  });

  describe('Arrows with Labels', () => {
    test('normalizes arrow with label spacing', () => {
      const input = `@startuml
start
->  : Label with spaces
:Task;
@enduml`;

      const expected = `@startuml
start
-> :Label with spaces
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('normalizes dashed arrow with label', () => {
      const input = `@startuml
start
-->  :  Yes
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('--> :Yes');
    });

    test('preserves label content', () => {
      const input = `@startuml
start
-> :Complex label with 123 and symbols!
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('Complex label with 123 and symbols!');
    });
  });

  describe('Arrows with Source and Target', () => {
    test('normalizes arrow with source and target', () => {
      const input = `@startuml
NodeA  ->  NodeB
@enduml`;

      const expected = `@startuml
NodeA -> NodeB
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('normalizes dashed arrow with nodes', () => {
      const input = `@startuml
Start  -->  End
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('Start --> End');
    });
  });

  describe('Edge Cases', () => {
    test('handles arrow at start of diagram', () => {
      const input = `@startuml
->
:First task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('->');
    });

    test('handles multiple arrows in sequence', () => {
      const input = `@startuml
start
->
->
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      const arrowCount = (result.normalized.match(/->/g) || []).length;
      expect(arrowCount).toBe(2);
    });

    test('handles arrow without label', () => {
      const input = `@startuml
start
->
:Task;
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('->');
    });
  });
});
