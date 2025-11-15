/**
 * Activity diagram specific normalization rules
 *
 * @module normalizer/rules/activity
 */

/**
 * Check if a line is an activity node
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is an activity node
 */
function isActivityNode(trimmed) {
  return /^:.+;$/.test(trimmed);
}

/**
 * Parse activity node content
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { label: string } or null if not an activity node
 */
function parseActivityNode(trimmed) {
  const match = trimmed.match(/^:(.+);$/);
  if (match) {
    return { label: match[1].trim() };
  }
  return null;
}

/**
 * Check if a line is a control flow statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { isControlFlow: boolean, type: string|null }
 */
function isControlFlow(trimmed) {
  const controlPatterns = [
    { pattern: /^if\s*\(/, type: 'if' },
    { pattern: /^elseif\s*\(/, type: 'elseif' },
    { pattern: /^else/, type: 'else' },
    { pattern: /^endif/, type: 'endif' },
    { pattern: /^while\s*\(/, type: 'while' },
    { pattern: /^endwhile/, type: 'endwhile' },
    { pattern: /^repeat$/, type: 'repeat' },
    { pattern: /^repeat\s+while/, type: 'repeat_while' }
  ];

  for (const { pattern, type } of controlPatterns) {
    if (pattern.test(trimmed)) {
      return { isControlFlow: true, type };
    }
  }

  return { isControlFlow: false, type: null };
}

/**
 * Parse if statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { condition: string, thenLabel: string|null }
 */
function parseIfStatement(trimmed) {
  const match = trimmed.match(/^if\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
  if (match) {
    return {
      condition: match[1].trim(),
      thenLabel: match[2] ? match[2].trim() : null
    };
  }
  return null;
}

/**
 * Parse while statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { condition: string, label: string|null }
 */
function parseWhileStatement(trimmed) {
  const match = trimmed.match(/^while\s*\((.+?)\)(?:\s*is\s*\((.+?)\))?$/);
  if (match) {
    return {
      condition: match[1].trim(),
      label: match[2] ? match[2].trim() : null
    };
  }
  return null;
}

/**
 * Parse else statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { label: string|null }
 */
function parseElseStatement(trimmed) {
  const match = trimmed.match(/^else(?:\s*\((.+?)\))?$/);
  if (match) {
    return {
      label: match[1] ? match[1].trim() : null
    };
  }
  return null;
}

/**
 * Parse endwhile statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { label: string|null }
 */
function parseEndwhileStatement(trimmed) {
  const match = trimmed.match(/^endwhile(?:\s*\((.+?)\))?$/);
  if (match) {
    return {
      label: match[1] ? match[1].trim() : null
    };
  }
  return null;
}

/**
 * Check if a line is a partition declaration
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is a partition
 */
function isPartition(trimmed) {
  return trimmed.startsWith('partition ');
}

/**
 * Parse partition declaration
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { name: string, color: string|null, hasOpenBrace: boolean }
 */
function parsePartition(trimmed) {
  const match = trimmed.match(/^partition\s+(.+?)(?:\s+(#[\w]+))?\s*(\{)?$/);
  if (match) {
    let name = match[1].trim();
    // Remove quotes if present
    name = name.replace(/^["']|["']$/g, '');
    const color = match[2] || null;
    const hasOpenBrace = !!match[3];

    return {
      name,
      color,
      hasOpenBrace
    };
  }
  return null;
}

/**
 * Check if a line is a swimlane declaration
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is a swimlane
 */
function isSwimlane(trimmed) {
  return /^\|.+?\|$/.test(trimmed);
}

/**
 * Parse swimlane declaration
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { name: string }
 */
function parseSwimlane(trimmed) {
  const match = trimmed.match(/^\|(.+?)\|$/);
  if (match) {
    return {
      name: match[1].trim()
    };
  }
  return null;
}

/**
 * Check if a line is a fork/split statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { isForkSplit: boolean, type: string|null, subtype: string|null }
 */
function isForkSplit(trimmed) {
  if (trimmed === 'fork') {
    return { isForkSplit: true, type: 'fork', subtype: 'start' };
  }
  if (trimmed === 'fork again') {
    return { isForkSplit: true, type: 'fork', subtype: 'again' };
  }
  if (trimmed === 'end fork') {
    return { isForkSplit: true, type: 'fork', subtype: 'end' };
  }
  if (trimmed === 'split') {
    return { isForkSplit: true, type: 'split', subtype: 'start' };
  }
  if (trimmed === 'split again') {
    return { isForkSplit: true, type: 'split', subtype: 'again' };
  }
  if (trimmed === 'end split') {
    return { isForkSplit: true, type: 'split', subtype: 'end' };
  }

  return { isForkSplit: false, type: null, subtype: null };
}

/**
 * Check if a line is a note
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is a note
 */
function isNote(trimmed) {
  return trimmed.startsWith('note ') || trimmed === 'end note';
}

/**
 * Parse note declaration
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { position: string, content: string|null, isMultiline: boolean }
 */
function parseNote(trimmed) {
  // Single line note: note position: content
  const singleMatch = trimmed.match(/^note\s+(left|right|top|bottom)\s*:\s*(.+)$/);
  if (singleMatch) {
    return {
      position: singleMatch[1],
      content: singleMatch[2].trim(),
      isMultiline: false
    };
  }

  // Multiline note start: note position
  const multiMatch = trimmed.match(/^note\s+(left|right|top|bottom)$/);
  if (multiMatch) {
    return {
      position: multiMatch[1],
      content: null,
      isMultiline: true
    };
  }

  return null;
}

/**
 * Validate activity diagram syntax
 * @param {string[]} lines - Lines to validate
 * @returns {Object} { isValid: boolean, errors: string[] }
 */
function validateActivityDiagram(lines) {
  const errors = [];
  let inDiagram = false;
  let hasStart = false;
  let hasStop = false;
  let ifDepth = 0;
  let whileDepth = 0;
  let partitionDepth = 0;
  let forkDepth = 0;
  let splitDepth = 0;

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    const lineNum = i + 1;

    if (line.startsWith('@startuml')) {
      inDiagram = true;
      continue;
    }

    if (line === '@enduml') {
      inDiagram = false;

      // Check for unclosed structures
      if (ifDepth > 0) {
        errors.push(`Line ${lineNum}: Unclosed if statement (missing ${ifDepth} endif)`);
      }
      if (whileDepth > 0) {
        errors.push(`Line ${lineNum}: Unclosed while loop (missing ${whileDepth} endwhile)`);
      }
      if (partitionDepth > 0) {
        errors.push(`Line ${lineNum}: Unclosed partition (missing ${partitionDepth} closing braces)`);
      }
      if (forkDepth > 0) {
        errors.push(`Line ${lineNum}: Unclosed fork (missing ${forkDepth} 'end fork')`);
      }
      if (splitDepth > 0) {
        errors.push(`Line ${lineNum}: Unclosed split (missing ${splitDepth} 'end split')`);
      }

      continue;
    }

    if (!inDiagram || !line) continue;

    // Track structure depth
    if (line.startsWith('if (')) ifDepth++;
    if (line === 'endif') ifDepth--;
    if (line.startsWith('while (')) whileDepth++;
    if (line.startsWith('endwhile')) whileDepth--;
    if (line.startsWith('partition ')) partitionDepth++;
    if (line === '}' && partitionDepth > 0) partitionDepth--;
    if (line === 'fork') forkDepth++;
    if (line === 'end fork') forkDepth--;
    if (line === 'split') splitDepth++;
    if (line === 'end split') splitDepth--;

    // Track start/stop
    if (line === 'start' || line === '(*)') hasStart = true;
    if (line === 'stop') hasStop = true;

    // Check for negative depth (closing before opening)
    if (ifDepth < 0) {
      errors.push(`Line ${lineNum}: 'endif' without matching 'if'`);
      ifDepth = 0;
    }
    if (whileDepth < 0) {
      errors.push(`Line ${lineNum}: 'endwhile' without matching 'while'`);
      whileDepth = 0;
    }
    if (partitionDepth < 0) {
      errors.push(`Line ${lineNum}: Closing brace without matching 'partition'`);
      partitionDepth = 0;
    }
    if (forkDepth < 0) {
      errors.push(`Line ${lineNum}: 'end fork' without matching 'fork'`);
      forkDepth = 0;
    }
    if (splitDepth < 0) {
      errors.push(`Line ${lineNum}: 'end split' without matching 'split'`);
      splitDepth = 0;
    }
  }

  return {
    isValid: errors.length === 0,
    errors,
    hasStart,
    hasStop
  };
}

module.exports = {
  isActivityNode,
  parseActivityNode,
  isControlFlow,
  parseIfStatement,
  parseWhileStatement,
  parseElseStatement,
  parseEndwhileStatement,
  isPartition,
  parsePartition,
  isSwimlane,
  parseSwimlane,
  isForkSplit,
  isNote,
  parseNote,
  validateActivityDiagram
};
