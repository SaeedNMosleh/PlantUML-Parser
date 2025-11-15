const PlantUMLNormalizer = require('./src/normalizer');

const normalizer = new PlantUMLNormalizer();

// Test cases from corpus
const testCases = [
  {
    name: 'Note directive left',
    input: `@startuml
:Step;
note left: This is a note
@enduml`
  },
  {
    name: 'Note directive right',
    input: `@startuml
:Step;
note right: Important information
@enduml`
  },
  {
    name: 'Floating note',
    input: `@startuml
:Step;
note left
  This is a multiline note
  with multiple lines
end note
@enduml`
  }
];

testCases.forEach(test => {
  console.log(`\n=== ${test.name} ===`);
  console.log('Original:');
  console.log(test.input);

  const result = normalizer.normalize(test.input);
  console.log('\nNormalized:');
  console.log(result.normalized);
});