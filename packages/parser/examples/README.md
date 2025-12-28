# PlantUML Parser Examples

This directory contains example PlantUML diagrams that demonstrate the features supported by the parser.

## Phase 1: Activity Diagrams ✅

### Basic Activity Flow
**File**: [activity_basic.puml](activity_basic.puml)

Demonstrates:
- Start and stop nodes
- Simple activity nodes
- Sequential flow

### Decision Logic
**File**: [activity_decisions.puml](activity_decisions.puml)

Demonstrates:
- If-then-else decision nodes
- Nested decisions
- Conditional branching

### Loops
**File**: [activity_loops.puml](activity_loops.puml)

Demonstrates:
- While loops
- Loop conditions
- Nested activities within loops

### Partitions and Swimlanes
**File**: [activity_partitions.puml](activity_partitions.puml)

Demonstrates:
- Partitions with colors
- Swimlanes for different actors
- Organized workflow across multiple domains

### Parallel Processing
**File**: [activity_parallel.puml](activity_parallel.puml)

Demonstrates:
- Fork and join nodes
- Parallel execution branches
- Synchronization points

## Testing Examples

You can parse these examples using the tree-sitter CLI:

```bash
# First, generate the parser
npm run generate

# Parse a specific example
tree-sitter parse examples/activity_basic.puml

# Parse with debug output
tree-sitter parse examples/activity_decisions.puml --debug

# Parse all examples
for file in examples/*.puml; do
  echo "Parsing $file..."
  tree-sitter parse "$file"
done
```

## Using with Node.js

```javascript
const Parser = require('tree-sitter');
const PlantUML = require('tree-sitter-plantuml');
const fs = require('fs');

const parser = new Parser();
parser.setLanguage(PlantUML);

// Parse an example file
const source = fs.readFileSync('examples/activity_basic.puml', 'utf8');
const tree = parser.parse(source);

console.log(tree.rootNode.toString());
```

## Future Examples

As more diagram types are implemented, this directory will include:

- **Phase 2**: Sequence diagram examples
- **Phase 3**: Class diagram examples
- **Phase 4**: State diagram examples
- **Phase 5**: Component, Deployment, and Use Case examples

## Contributing Examples

If you have interesting PlantUML diagrams that showcase parser features:

1. Ensure they use only supported features
2. Keep them focused on specific features
3. Add comments to explain complex parts
4. Submit a PR with the new example

## Rendering

To render these diagrams visually:

1. Install PlantUML: https://plantuml.com/download
2. Run: `plantuml examples/activity_basic.puml`
3. This generates `activity_basic.png`

Or use online tools:
- http://www.plantuml.com/plantuml/
- https://plantuml-editor.kkeisuke.com/
