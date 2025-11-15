/**
 * Control flow normalization tests
 */

const PlantUMLNormalizer = require('../../src/normalizer');

describe('Control Flow Normalization', () => {
  let normalizer;

  beforeEach(() => {
    normalizer = new PlantUMLNormalizer();
  });

  describe('If Statements', () => {
    test('normalizes if with condition and label', () => {
      const input = `@startuml
if ( condition ) then ( yes )
  :Task;
endif
@enduml`;

      const expected = `@startuml
if (condition) then (yes)
  :Task;
endif
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('normalizes if without label', () => {
      const input = `@startuml
if (Ready?) then
  :Process;
endif
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('if (Ready?) then');
    });

    test('normalizes if-else', () => {
      const input = `@startuml
if (condition?) then (yes)
  :Task A;
else (no)
  :Task B;
endif
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('if (condition?) then (yes)');
      expect(result.normalized).toContain('else (no)');
      expect(result.normalized).toContain('endif');
    });

    test('normalizes if-elseif-else', () => {
      const input = `@startuml
if (x > 10) then (yes)
  :Large;
elseif (x > 5) then (yes)
  :Medium;
else (no)
  :Small;
endif
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('if (x > 10) then (yes)');
      expect(result.normalized).toContain('elseif (x > 5) then (yes)');
      expect(result.normalized).toContain('else (no)');
    });
  });

  describe('While Loops', () => {
    test('normalizes while with condition and label', () => {
      const input = `@startuml
while ( more data? ) is ( yes )
  :Process item;
endwhile
@enduml`;

      const expected = `@startuml
while (more data?) is (yes)
  :Process item;
endwhile
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toBe(expected);
    });

    test('normalizes while without label', () => {
      const input = `@startuml
while (has data?)
  :Process;
endwhile
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('while (has data?)');
    });

    test('normalizes endwhile with label', () => {
      const input = `@startuml
while (condition?) is (yes)
  :Task;
endwhile (no)
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('endwhile (no)');
    });
  });

  describe('Repeat Loops', () => {
    test('normalizes repeat-while', () => {
      const input = `@startuml
repeat
  :Task;
repeat while (more?) is (yes)
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('repeat');
      expect(result.normalized).toContain('repeat while');
    });

    test('normalizes simple repeat', () => {
      const input = `@startuml
repeat
  :Process;
  :Check;
repeat while (again?)
@enduml`;

      const result = normalizer.normalize(input);
      const repeatCount = (result.normalized.match(/repeat/g) || []).length;
      expect(repeatCount).toBe(2);
    });
  });

  describe('Fork and Split', () => {
    test('normalizes fork', () => {
      const input = `@startuml
fork
  :Task A;
fork again
  :Task B;
end fork
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('fork');
      expect(result.normalized).toContain('fork again');
      expect(result.normalized).toContain('end fork');
    });

    test('normalizes split', () => {
      const input = `@startuml
split
  :Task A;
split again
  :Task B;
end split
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('split');
      expect(result.normalized).toContain('split again');
      expect(result.normalized).toContain('end split');
    });
  });

  describe('Nested Control Flow', () => {
    test('normalizes nested if statements', () => {
      const input = `@startuml
if (outer?) then (yes)
  if (inner?) then (yes)
    :Nested task;
  endif
endif
@enduml`;

      const result = normalizer.normalize(input);
      const ifCount = (result.normalized.match(/if \(/g) || []).length;
      const endifCount = (result.normalized.match(/endif/g) || []).length;
      expect(ifCount).toBe(2);
      expect(endifCount).toBe(2);
    });

    test('normalizes while inside if', () => {
      const input = `@startuml
if (check?) then (yes)
  while (more?) is (yes)
    :Process;
  endwhile
endif
@enduml`;

      const result = normalizer.normalize(input);
      expect(result.normalized).toContain('if (check?) then (yes)');
      expect(result.normalized).toContain('while (more?) is (yes)');
    });
  });
});
