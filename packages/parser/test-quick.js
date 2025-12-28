// Quick test to verify WASM parser works
const { PlantUMLNormalizer } = require('./dist/normalizer.cjs');

console.log('Testing normalizer...');
const normalizer = new PlantUMLNormalizer();
const source = `@startuml
start
:Hello World;
stop
@enduml`;

const result = normalizer.normalize(source);
console.log('✅ Normalizer works!');
console.log('Input:', source);
console.log('\nOutput:', result.normalized);
console.log('\nMetadata:', result.metadata);
