# CLAUDE.md - Development Principles for PlantUML Parser

## Zero Tolerance Policy

### 100% Success Rate Required - No Exceptions

- **100% PlantUML Validation** - Every test must be valid PlantUML
- **100% Parser Success** - Every valid input must parse without errors
- **Zero Failures Accepted** - Fix or remove any failing test
- **PlantUML Server is Absolute Truth** - If server rejects it, we don't support it

## Core Architecture Principle

**The Parser is ONE system with ONE purpose:**
- **Input**: Raw PlantUML code (as users write it)
- **Output**: Parsed Abstract Syntax Tree (AST)
- **Components**: Normalizer (Pass 1) + Grammar (Pass 2)

The parser is NOT separate components. It's a single system tested end-to-end.

---

## Design Philosophy

### 1. Normalizer is the Complexity Handler
- **Normalizer handles ALL ambiguities, edge cases, and syntax variations**
- **Grammar should be SIMPLE and conflict-free**
- If grammar is getting complicated, FIX IT IN THE NORMALIZER

### 2. Grammar Only Parses Normalized Output
- Grammar expects clean, unambiguous, normalized PlantUML
- Grammar should NEVER struggle with parsing
- If grammar fails, the normalizer didn't do its job

### 3. PlantUML Syntax is the Source of Truth
- **ALWAYS validate syntax with PlantUML server FIRST**
- Never design features based on assumptions
- If PlantUML server rejects it, we don't support it

---

## Testing Principles

### Primary Tests: End-to-End Integration Tests
```javascript
// This is what we ACTUALLY test:
const input = `@startuml
->: Label with spaces
note left: This is a note
@enduml`;

const parser = new PlantUMLParser();
const result = parser.parse(input);
expect(result.tree.rootNode.hasError).toBe(false);
```

**Integration tests are the PRIMARY metric for success.**

### Secondary Tests: Grammar Corpus Tests
- Only test grammar in isolation with NORMALIZED input
- Corpus tests verify grammar correctness, not system correctness
- Corpus tests use normalizer output as input

### Validation Tests: PlantUML Server
- Verify syntax is valid according to PlantUML server
- Run BEFORE implementing features
- If server rejects syntax, feature is invalid

---

## The 2-Attempt Rule

**If you try to fix something more than 2 times with the same approach, STOP.**

### After 2 Failed Attempts:
1. **STOP immediately**
2. **The approach is WRONG**
3. **Pivot to a different strategy**

### Example:
- ❌ Attempt 1: Tweak grammar for arrow labels → fails
- ❌ Attempt 2: Add precedence to grammar → fails
- 🛑 **STOP** - Wrong approach!
- ✅ Pivot: Fix normalizer to format arrows consistently

### What Counts as "Same Approach":
- Tweaking grammar rules for same issue = same approach
- Adjusting precedence/conflicts for same issue = same approach
- Different normalizer strategies = different approaches
- Grammar vs normalizer fix = different approaches

---

## Decision Framework

### When Grammar Fails to Parse:
1. **First check**: Is the input normalized?
   - If NO → Fix normalizer
   - If YES → Continue to step 2

2. **Second check**: Is this valid PlantUML syntax?
   - If NO → Don't support it
   - If YES → Continue to step 3

3. **Third check**: Can normalizer make this simpler?
   - If YES → Fix normalizer (preferred)
   - If NO → Fix grammar (only if necessary)

### When Tests Fail - Zero Tolerance

1. **PlantUML validation fails** → Remove the test immediately (invalid syntax)
2. **Integration test fails** → Must fix parser/normalizer or remove test
3. **Corpus test fails** → Fix normalizer or grammar immediately
4. **Any test fails** → No partial solutions - fix or remove
5. **Success rate < 100%** → Unacceptable - continue fixing

---

## Success Metrics (In Priority Order)

1. **PlantUML Server Validation** - 100% of syntax must be valid
2. **Integration Tests (Full Pipeline)** - 100% must pass (Primary metric)
3. **Grammar Corpus Tests** - 100% must pass (Grammar verification)
4. **Normalizer Tests** - 100% must pass (All 59 tests)
5. **Zero Grammar Conflicts** - Keep grammar simple
6. **Zero Test Failures** - Not even one failure is acceptable

---

## Common Mistakes to Avoid

### ❌ DON'T:
- Test grammar without normalizer
- Design features without PlantUML server validation
- Try fixing grammar >2 times for same issue
- Make grammar complex to handle edge cases
- Assume syntax is valid without verification

### ✅ DO:
- Test full pipeline (raw input → AST)
- Validate syntax with PlantUML server first
- Use normalizer to handle complexity
- Keep grammar simple and conflict-free
- Pivot after 2 failed attempts

---

## Implementation Checklist

Before implementing ANY feature:
- [ ] Validate syntax with PlantUML server
- [ ] Confirm normalizer can handle it
- [ ] Verify grammar stays simple
- [ ] Write integration test with raw input
- [ ] Write corpus test with normalized input

---

## Remember

**The normalizer exists to make the grammar's job easy.**

If the grammar is struggling, the normalizer isn't doing its job.

---

**This document is the source of truth for development decisions.**
**When in doubt, refer back to these principles.**
