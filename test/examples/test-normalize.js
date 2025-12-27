const PlantUMLNormalizer = require('../../dist/normalizer.cjs');

const normalizer = new PlantUMLNormalizer({ debug: false });

// Test 1: Arrow with label
const test1 = `@startuml
:Step 1;
->: Next step
:Step 2;
@enduml`;

console.log("=== Test 1: Arrow with label ===");
const result1 = normalizer.normalize(test1);
console.log("Input:");
console.log(test1);
console.log("\nNormalized:");
console.log(result1.normalized);

// Test 2: Note directive
const test2 = `@startuml
:Step;
note left: This is a note
@enduml`;

console.log("\n=== Test 2: Note directive ===");
const result2 = normalizer.normalize(test2);
console.log("Input:");
console.log(test2);
console.log("\nNormalized:");
console.log(result2.normalized);
