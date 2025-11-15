/**
 * Utility functions for the PlantUML normalizer
 *
 * @module normalizer/utils
 */

/**
 * Create a source map for line number tracking
 * @param {string[]} originalLines - Original source lines
 * @param {string[]} normalizedLines - Normalized source lines
 * @returns {Map<number, number>} Map from normalized line number to original line number
 */
function createSourceMap(originalLines, normalizedLines) {
  const sourceMap = new Map();
  let originalIndex = 0;
  let normalizedIndex = 0;

  // Simple 1:1 mapping for now
  // Could be enhanced for multi-line transformations
  while (originalIndex < originalLines.length && normalizedIndex < normalizedLines.length) {
    sourceMap.set(normalizedIndex, originalIndex);
    originalIndex++;
    normalizedIndex++;
  }

  return sourceMap;
}

/**
 * Calculate statistics about normalization
 * @param {string} original - Original source
 * @param {string} normalized - Normalized source
 * @returns {Object} Statistics object
 */
function calculateStats(original, normalized) {
  const originalLines = original.split('\n');
  const normalizedLines = normalized.split('\n');

  const stats = {
    originalLineCount: originalLines.length,
    normalizedLineCount: normalizedLines.length,
    linesRemoved: originalLines.length - normalizedLines.length,
    originalCharCount: original.length,
    normalizedCharCount: normalized.length,
    charsChanged: Math.abs(original.length - normalized.length),
    transformations: {
      circleNodesToStart: (normalized.match(/\bstart\b/g) || []).length,
      circleNodesToStop: (normalized.match(/\bstop\b/g) || []).length,
      activityNodes: (normalized.match(/:.+;/g) || []).length,
      controlFlows: (normalized.match(/\b(if|while|repeat|fork|split)\b/g) || []).length
    }
  };

  return stats;
}

/**
 * Deep clone an object
 * @param {Object} obj - Object to clone
 * @returns {Object} Cloned object
 */
function deepClone(obj) {
  if (obj === null || typeof obj !== 'object') {
    return obj;
  }

  if (obj instanceof Date) {
    return new Date(obj.getTime());
  }

  if (obj instanceof Array) {
    return obj.map(item => deepClone(item));
  }

  if (obj instanceof Object) {
    const clonedObj = {};
    for (const key in obj) {
      if (obj.hasOwnProperty(key)) {
        clonedObj[key] = deepClone(obj[key]);
      }
    }
    return clonedObj;
  }

  return obj;
}

/**
 * Merge multiple normalization options objects
 * @param {...Object} options - Options objects to merge
 * @returns {Object} Merged options
 */
function mergeOptions(...options) {
  const merged = {
    debug: false,
    preserveComments: true,
    preserveWhitespace: false,
    strict: false
  };

  for (const opt of options) {
    if (opt && typeof opt === 'object') {
      Object.assign(merged, opt);
    }
  }

  return merged;
}

/**
 * Format error message with line context
 * @param {string} message - Error message
 * @param {number} lineNumber - Line number (1-indexed)
 * @param {string} line - Line content
 * @returns {string} Formatted error message
 */
function formatError(message, lineNumber, line) {
  return `Line ${lineNumber}: ${message}\n  ${line}`;
}

/**
 * Extract diagram boundaries from source
 * @param {string[]} lines - Source lines
 * @returns {Array<Object>} Array of {start: number, end: number} objects
 */
function findDiagramBoundaries(lines) {
  const boundaries = [];
  let currentStart = null;

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();

    if (line.startsWith('@startuml')) {
      currentStart = i;
    } else if (line === '@enduml' && currentStart !== null) {
      boundaries.push({ start: currentStart, end: i });
      currentStart = null;
    }
  }

  // Handle unclosed diagram
  if (currentStart !== null) {
    boundaries.push({ start: currentStart, end: lines.length - 1 });
  }

  return boundaries;
}

/**
 * Check if a position is inside a diagram
 * @param {number} position - Line position
 * @param {Array<Object>} boundaries - Diagram boundaries
 * @returns {boolean} True if inside a diagram
 */
function isInsideDiagram(position, boundaries) {
  return boundaries.some(b => position >= b.start && position <= b.end);
}

/**
 * Validate PlantUML syntax markers
 * @param {string} source - Source to validate
 * @returns {Object} { isValid: boolean, errors: string[] }
 */
function validateSyntax(source) {
  const errors = [];
  const lines = source.split('\n');

  let startumlCount = 0;
  let endumlCount = 0;

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    const lineNum = i + 1;

    if (line.startsWith('@startuml')) {
      startumlCount++;
      if (startumlCount > endumlCount + 1) {
        errors.push(`Line ${lineNum}: Nested @startuml detected`);
      }
    }

    if (line === '@enduml') {
      endumlCount++;
      if (endumlCount > startumlCount) {
        errors.push(`Line ${lineNum}: @enduml without matching @startuml`);
      }
    }
  }

  if (startumlCount !== endumlCount) {
    errors.push(`Mismatched diagram boundaries: ${startumlCount} @startuml, ${endumlCount} @enduml`);
  }

  return {
    isValid: errors.length === 0,
    errors
  };
}

/**
 * Remove comments from source
 * @param {string} source - Source with comments
 * @returns {string} Source without comments
 */
function removeComments(source) {
  const lines = source.split('\n');
  const filtered = [];
  let inBlockComment = false;

  for (const line of lines) {
    const trimmed = line.trim();

    // Check for block comment start
    if (trimmed.startsWith("/'")) {
      inBlockComment = true;
      continue;
    }

    // Check for block comment end
    if (trimmed.startsWith("'/")) {
      inBlockComment = false;
      continue;
    }

    // Skip if in block comment
    if (inBlockComment) {
      continue;
    }

    // Skip line comments
    if (trimmed.startsWith("'")) {
      continue;
    }

    filtered.push(line);
  }

  return filtered.join('\n');
}

/**
 * Normalize line endings to \n
 * @param {string} source - Source with mixed line endings
 * @returns {string} Source with \n line endings
 */
function normalizeLineEndings(source) {
  return source.replace(/\r\n/g, '\n').replace(/\r/g, '\n');
}

/**
 * Count occurrences of a pattern in source
 * @param {string} source - Source to search
 * @param {RegExp|string} pattern - Pattern to count
 * @returns {number} Number of occurrences
 */
function countOccurrences(source, pattern) {
  if (typeof pattern === 'string') {
    return (source.match(new RegExp(pattern, 'g')) || []).length;
  }
  return (source.match(new RegExp(pattern.source, 'g')) || []).length;
}

/**
 * Extract all activity labels from source
 * @param {string} source - Source to extract from
 * @returns {string[]} Array of activity labels
 */
function extractActivityLabels(source) {
  const labels = [];
  const pattern = /:(.+?);/g;
  let match;

  while ((match = pattern.exec(source)) !== null) {
    labels.push(match[1].trim());
  }

  return labels;
}

/**
 * Extract all conditions from control flow statements
 * @param {string} source - Source to extract from
 * @returns {string[]} Array of conditions
 */
function extractConditions(source) {
  const conditions = [];
  const patterns = [
    /if\s*\((.+?)\)/g,
    /while\s*\((.+?)\)/g,
    /repeat\s+while\s*\((.+?)\)/g
  ];

  for (const pattern of patterns) {
    let match;
    while ((match = pattern.exec(source)) !== null) {
      conditions.push(match[1].trim());
    }
  }

  return conditions;
}

/**
 * Check if source contains a specific diagram type
 * @param {string} source - Source to check
 * @param {string} diagramType - Diagram type to check for
 * @returns {boolean} True if contains diagram type
 */
function containsDiagramType(source, diagramType) {
  const lines = source.split('\n');

  for (const line of lines) {
    const trimmed = line.trim();

    switch (diagramType.toLowerCase()) {
      case 'activity':
        if (trimmed.startsWith(':') || trimmed === 'start' || trimmed === 'stop' || trimmed === '(*)') {
          return true;
        }
        break;
      case 'sequence':
        if (trimmed.includes('participant') || trimmed.includes('actor')) {
          return true;
        }
        break;
      case 'class':
        if (trimmed.includes('class ') || trimmed.includes('interface ')) {
          return true;
        }
        break;
      case 'state':
        if (trimmed.includes('state ') || trimmed.includes('[*]')) {
          return true;
        }
        break;
      default:
        return false;
    }
  }

  return false;
}

/**
 * Pretty print normalization metadata
 * @param {Object} metadata - Metadata from normalizer
 * @returns {string} Formatted metadata string
 */
function prettyPrintMetadata(metadata) {
  const lines = [
    'Normalization Metadata:',
    '  Diagram Type: ' + (metadata.diagramType || 'unknown'),
    '  Node Count: ' + metadata.nodeCount,
    '  Circle Nodes: ' + metadata.circleNodeCount,
    '  Has Circle Nodes: ' + metadata.hasCircleNodes
  ];

  return lines.join('\n');
}

/**
 * Compare two normalized outputs
 * @param {string} output1 - First output
 * @param {string} output2 - Second output
 * @returns {Object} { isEqual: boolean, differences: string[] }
 */
function compareOutputs(output1, output2) {
  const lines1 = output1.split('\n');
  const lines2 = output2.split('\n');

  const differences = [];

  const maxLength = Math.max(lines1.length, lines2.length);

  for (let i = 0; i < maxLength; i++) {
    const line1 = lines1[i] || '';
    const line2 = lines2[i] || '';

    if (line1 !== line2) {
      differences.push({
        line: i + 1,
        expected: line1,
        actual: line2
      });
    }
  }

  return {
    isEqual: differences.length === 0,
    differences
  };
}

/**
 * Benchmark a normalization function
 * @param {Function} fn - Function to benchmark
 * @param {string} source - Source to normalize
 * @param {number} iterations - Number of iterations
 * @returns {Object} { avgTime: number, minTime: number, maxTime: number, totalTime: number }
 */
function benchmark(fn, source, iterations = 100) {
  const times = [];

  for (let i = 0; i < iterations; i++) {
    const start = Date.now();
    fn(source);
    const end = Date.now();
    times.push(end - start);
  }

  const totalTime = times.reduce((a, b) => a + b, 0);
  const avgTime = totalTime / iterations;
  const minTime = Math.min(...times);
  const maxTime = Math.max(...times);

  return {
    avgTime,
    minTime,
    maxTime,
    totalTime,
    iterations
  };
}

module.exports = {
  createSourceMap,
  calculateStats,
  deepClone,
  mergeOptions,
  formatError,
  findDiagramBoundaries,
  isInsideDiagram,
  validateSyntax,
  removeComments,
  normalizeLineEndings,
  countOccurrences,
  extractActivityLabels,
  extractConditions,
  containsDiagramType,
  prettyPrintMetadata,
  compareOutputs,
  benchmark
};
