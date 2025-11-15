/**
 * Arrow normalization rules (ESM version)
 *
 * @module normalizer/rules/arrows
 */

/**
 * Arrow type definitions
 */
export const ARROW_TYPES = {
  SOLID: '->',
  DASHED: '-->',
  THICK: '->>',
  DOTTED: '.>',
  SOLID_LEFT: '<-',
  DASHED_LEFT: '<--',
  THICK_LEFT: '<<-',
  DOTTED_LEFT: '<.'
};

/**
 * Check if a line contains an arrow
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if line contains an arrow
 */
export function containsArrow(trimmed) {
  const arrowPatterns = Object.values(ARROW_TYPES);
  return arrowPatterns.some(pattern => trimmed.includes(pattern));
}

/**
 * Detect arrow type in a line
 * @param {string} trimmed - Trimmed line content
 * @returns {string|null} Arrow type or null if not found
 */
export function detectArrowType(trimmed) {
  // Check in order of specificity (longer patterns first to avoid false matches)
  const orderedArrows = [
    ARROW_TYPES.DASHED,
    ARROW_TYPES.THICK,
    ARROW_TYPES.DASHED_LEFT,
    ARROW_TYPES.THICK_LEFT,
    ARROW_TYPES.DOTTED,
    ARROW_TYPES.DOTTED_LEFT,
    ARROW_TYPES.SOLID,
    ARROW_TYPES.SOLID_LEFT
  ];

  for (const arrow of orderedArrows) {
    if (trimmed.includes(arrow)) {
      return arrow;
    }
  }

  return null;
}

/**
 * Check if arrow has a label
 * @param {string} trimmed - Trimmed line content
 * @returns {boolean} True if arrow has a label
 */
export function hasArrowLabel(trimmed) {
  const arrowType = detectArrowType(trimmed);
  if (!arrowType) return false;

  const parts = trimmed.split(arrowType);
  if (parts.length < 2) return false;

  const afterArrow = parts[1].trim();
  return afterArrow.startsWith(':');
}

/**
 * Parse arrow statement
 * @param {string} trimmed - Trimmed line content
 * @returns {Object|null} { arrowType: string, source: string|null, target: string|null, label: string|null }
 */
export function parseArrow(trimmed) {
  const arrowType = detectArrowType(trimmed);
  if (!arrowType) return null;

  const parts = trimmed.split(arrowType);

  // Source (if present)
  const source = parts[0].trim() || null;

  // Target and label (after arrow)
  const afterArrow = parts[1] ? parts[1].trim() : '';

  let target = null;
  let label = null;

  if (afterArrow) {
    // Check for label: arrow : label
    if (afterArrow.startsWith(':')) {
      label = afterArrow.substring(1).trim();
    } else {
      // Could be target or target with label
      // Pattern: arrow target or arrow : label
      const colonIndex = afterArrow.indexOf(':');
      if (colonIndex !== -1) {
        target = afterArrow.substring(0, colonIndex).trim() || null;
        label = afterArrow.substring(colonIndex + 1).trim() || null;
      } else {
        target = afterArrow;
      }
    }
  }

  return {
    arrowType,
    source,
    target,
    label
  };
}

/**
 * Normalize arrow statement
 * @param {string} trimmed - Trimmed line content
 * @param {string} indent - Indentation to preserve
 * @returns {string|null} Normalized arrow statement or null if not an arrow
 */
export function normalizeArrow(trimmed, indent = '') {
  const parsed = parseArrow(trimmed);
  if (!parsed) return null;

  const { arrowType, source, target, label } = parsed;

  let normalized = '';

  // Add source if present
  if (source) {
    normalized += source;
  }

  if (normalized.length > 0) {
    normalized += ' ';
  }

  // Add arrow
  normalized += arrowType;

  if (target) {
    normalized += ' ' + target;
  }

  // Add label if present (with colon separator)
  if (label) {
    normalized += ' :' + label;
  }

  return `${indent}${normalized}`.trimEnd();
}

/**
 * Validate arrow syntax
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { isValid: boolean, errors: string[] }
 */
export function validateArrow(trimmed) {
  const errors = [];

  const arrowType = detectArrowType(trimmed);
  if (!arrowType) {
    errors.push('No valid arrow type found');
    return { isValid: false, errors };
  }

  const parsed = parseArrow(trimmed);
  if (!parsed) {
    errors.push('Failed to parse arrow statement');
    return { isValid: false, errors };
  }

  // Check for common errors
  const { source, target, label } = parsed;

  // Arrow should have at least a source or label
  if (!source && !target && !label) {
    errors.push('Arrow has no source, target, or label');
  }

  // Check for multiple colons (might indicate error)
  const colonCount = (trimmed.match(/:/g) || []).length;
  if (colonCount > 1) {
    errors.push('Multiple colons found (ambiguous label syntax)');
  }

  return {
    isValid: errors.length === 0,
    errors
  };
}

/**
 * Get arrow direction
 * @param {string} arrowType - Arrow type string
 * @returns {string} 'right', 'left', or 'unknown'
 */
export function getArrowDirection(arrowType) {
  const leftArrows = [
    ARROW_TYPES.SOLID_LEFT,
    ARROW_TYPES.DASHED_LEFT,
    ARROW_TYPES.THICK_LEFT,
    ARROW_TYPES.DOTTED_LEFT
  ];

  const rightArrows = [
    ARROW_TYPES.SOLID,
    ARROW_TYPES.DASHED,
    ARROW_TYPES.THICK,
    ARROW_TYPES.DOTTED
  ];

  if (leftArrows.includes(arrowType)) return 'left';
  if (rightArrows.includes(arrowType)) return 'right';

  return 'unknown';
}

/**
 * Get arrow style
 * @param {string} arrowType - Arrow type string
 * @returns {string} 'solid', 'dashed', 'thick', 'dotted', or 'unknown'
 */
export function getArrowStyle(arrowType) {
  if (arrowType === ARROW_TYPES.SOLID || arrowType === ARROW_TYPES.SOLID_LEFT) {
    return 'solid';
  }
  if (arrowType === ARROW_TYPES.DASHED || arrowType === ARROW_TYPES.DASHED_LEFT) {
    return 'dashed';
  }
  if (arrowType === ARROW_TYPES.THICK || arrowType === ARROW_TYPES.THICK_LEFT) {
    return 'thick';
  }
  if (arrowType === ARROW_TYPES.DOTTED || arrowType === ARROW_TYPES.DOTTED_LEFT) {
    return 'dotted';
  }

  return 'unknown';
}

/**
 * Normalize all arrow patterns
 * @param {string[]} lines - Lines to normalize
 * @returns {string[]} Normalized lines
 */
export function normalizeAllArrows(lines) {
  return lines.map(line => {
    const trimmed = line.trim();
    const indent = line.match(/^(\s*)/)[1];

    if (containsArrow(trimmed)) {
      const normalized = normalizeArrow(trimmed, indent);
      return normalized !== null ? normalized : line;
    }

    return line;
  });
}

/**
 * Common arrow patterns used in activity diagrams
 */
export const COMMON_PATTERNS = {
  // Standalone arrows
  SIMPLE_FLOW: /^->$/,
  DASHED_FLOW: /^-->$/,

  // Arrows with labels
  LABELED_FLOW: /^->\s*:\s*.+$/,
  LABELED_DASHED: /^-->\s*:\s*.+$/,

  // Arrows with source and target
  CONNECTED_FLOW: /^.+\s*->\s*.+$/,
  CONNECTED_DASHED: /^.+\s*-->\s*.+$/
};

/**
 * Match arrow pattern
 * @param {string} trimmed - Trimmed line content
 * @returns {Object} { pattern: string|null, matches: boolean }
 */
export function matchArrowPattern(trimmed) {
  for (const [name, pattern] of Object.entries(COMMON_PATTERNS)) {
    if (pattern.test(trimmed)) {
      return { pattern: name, matches: true };
    }
  }
  return { pattern: null, matches: false };
}
