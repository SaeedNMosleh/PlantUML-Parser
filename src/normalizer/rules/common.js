/**
 * Common normalization rules used across all diagram types
 *
 * @module normalizer/rules/common
 */

/**
 * Detect if a line is a circle node (*)
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is a circle node
 */
function isCircleNode(trimmed) {
  return trimmed === '(*)';
}

/**
 * Detect if a line is a comment
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line is a comment
 */
function isComment(trimmed) {
  return trimmed.startsWith("'") || trimmed.startsWith("/'") || trimmed.startsWith("'/");
}

/**
 * Detect if a line is a diagram boundary
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { isStart: boolean, isEnd: boolean }
 */
function isDiagramBoundary(trimmed) {
  return {
    isStart: trimmed.startsWith('@startuml'),
    isEnd: trimmed === '@enduml'
  };
}

/**
 * Detect if a line is a directive
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { isDirective: boolean, type: string|null }
 */
function isDirective(trimmed) {
  const directives = ['title', 'skinparam', 'legend', 'header', 'footer', 'caption'];
  for (const directive of directives) {
    if (trimmed.startsWith(directive + ' ')) {
      return { isDirective: true, type: directive };
    }
  }
  return { isDirective: false, type: null };
}

/**
 * Extract indentation from a line
 * @param {string} line - Original line with whitespace
 * @returns {string} Indentation string
 */
function getIndentation(line) {
  const match = line.match(/^(\s*)/);
  return match ? match[1] : '';
}

/**
 * Normalize whitespace in a line
 * @param {string} text - Text to normalize
 * @param {boolean} preserveMultiple - Whether to preserve multiple spaces
 * @returns {string} Normalized text
 */
function normalizeWhitespace(text, preserveMultiple = false) {
  if (preserveMultiple) {
    return text.trim();
  }
  return text.trim().replace(/\s+/g, ' ');
}

/**
 * Check if a string is wrapped in quotes
 * @param {string} str - String to check
 * @returns {boolean} True if wrapped in quotes
 */
function isQuoted(str) {
  return (str.startsWith('"') && str.endsWith('"')) ||
         (str.startsWith("'") && str.endsWith("'"));
}

/**
 * Remove quotes from a string if present
 * @param {string} str - String to process
 * @returns {string} String without quotes
 */
function removeQuotes(str) {
  if (isQuoted(str)) {
    return str.slice(1, -1);
  }
  return str;
}

/**
 * Add quotes to a string if not already quoted
 * @param {string} str - String to process
 * @returns {string} Quoted string
 */
function ensureQuoted(str) {
  if (isQuoted(str)) {
    return str;
  }
  return `"${str}"`;
}

/**
 * Check if a line contains an arrow
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line contains an arrow
 */
function containsArrow(trimmed) {
  const arrowPatterns = ['->', '-->', '->>', '.>', '<-', '<--', '<<-', '<.'];
  return arrowPatterns.some(pattern => trimmed.includes(pattern));
}

/**
 * Detect diagram type from content
 * @param {string[]} lines - All lines to analyze
 * @param {number} startIndex - Index to start looking from
 * @returns {string|null} Detected diagram type or null
 */
function detectDiagramType(lines, startIndex = 0) {
  const lookAheadLimit = Math.min(startIndex + 20, lines.length);

  for (let i = startIndex; i < lookAheadLimit; i++) {
    const line = lines[i].trim();

    // Sequence diagram indicators
    if (line.includes('participant') || line.includes('actor') ||
        line.match(/\w+\s*->\s*\w+\s*:/)) {
      return 'sequence';
    }

    // Class diagram indicators
    if (line.includes('class ') || line.includes('interface ') ||
        line.includes('abstract ') || line.includes('enum ')) {
      return 'class';
    }

    // State diagram indicators
    if (line.includes('state ') || line.match(/\[\*\]\s*-->/)) {
      return 'state';
    }

    // Use case diagram indicators
    if (line.includes('usecase') || line.includes('actor :')) {
      return 'usecase';
    }

    // Component diagram indicators
    if (line.includes('component') || line.includes('package ')) {
      return 'component';
    }

    // Activity diagram indicators (default for many cases)
    if (line.startsWith(':') || line.includes('start') ||
        line.includes('(*)') || line.startsWith('if (') ||
        line.startsWith('while (')) {
      return 'activity';
    }
  }

  return null;
}

/**
 * Validate PlantUML color code
 * @param {string} color - Color code to validate
 * @returns {boolean} True if valid color code
 */
function isValidColor(color) {
  // Check hex color: #RGB, #RRGGBB, #RRGGBBAA
  if (/^#[0-9A-Fa-f]{3}$/.test(color) ||
      /^#[0-9A-Fa-f]{6}$/.test(color) ||
      /^#[0-9A-Fa-f]{8}$/.test(color)) {
    return true;
  }

  // Check named colors (common PlantUML colors)
  const namedColors = [
    'AliceBlue', 'AntiqueWhite', 'Aqua', 'Aquamarine', 'Azure', 'Beige',
    'Bisque', 'Black', 'BlanchedAlmond', 'Blue', 'BlueViolet', 'Brown',
    'LightBlue', 'LightGreen', 'LightGray', 'DarkGray', 'Gray',
    'Red', 'Green', 'Yellow', 'Orange', 'Pink', 'Purple', 'White'
  ];

  return namedColors.some(nc => nc.toLowerCase() === color.toLowerCase());
}

module.exports = {
  isCircleNode,
  isComment,
  isDiagramBoundary,
  isDirective,
  getIndentation,
  normalizeWhitespace,
  isQuoted,
  removeQuotes,
  ensureQuoted,
  containsArrow,
  detectDiagramType,
  isValidColor
};
