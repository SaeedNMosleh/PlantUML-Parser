/**
 * Arrow normalization rules (ported from legacy JS implementation)
 */

const ARROW_TYPES = {
  SOLID: '->',
  DASHED: '-->',
  THICK: '->>',
  DOTTED: '.>',
  SOLID_LEFT: '<-',
  DASHED_LEFT: '<--',
  THICK_LEFT: '<<-',
  DOTTED_LEFT: '<.'
} as const;

type ArrowType = (typeof ARROW_TYPES)[keyof typeof ARROW_TYPES];

function detectArrowType(trimmed: string): ArrowType | null {
  const orderedArrows: ArrowType[] = [
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
    if (trimmed.includes(arrow)) return arrow;
  }
  return null;
}

function parseArrow(trimmed: string): {
  arrowType: ArrowType;
  source: string | null;
  target: string | null;
  label: string | null;
} | null {
  const arrowType = detectArrowType(trimmed);
  if (!arrowType) return null;

  const parts = trimmed.split(arrowType);
  const source = parts[0]?.trim() || null;
  const afterArrow = parts[1] ? parts[1].trim() : '';

  let target: string | null = null;
  let label: string | null = null;

  if (afterArrow) {
    if (afterArrow.startsWith(':')) {
      label = afterArrow.substring(1).trim();
    } else {
      const colonIndex = afterArrow.indexOf(':');
      if (colonIndex !== -1) {
        target = afterArrow.substring(0, colonIndex).trim() || null;
        label = afterArrow.substring(colonIndex + 1).trim() || null;
      } else {
        target = afterArrow;
      }
    }
  }

  return { arrowType, source, target, label };
}

export function normalizeArrow(trimmed: string, indent = ''): string | null {
  const parsed = parseArrow(trimmed);
  if (!parsed) return null;

  const { arrowType, source, target, label } = parsed;

  let normalized = '';
  if (source) normalized += source;
  if (normalized.length > 0) normalized += ' ';
  normalized += arrowType;
  if (target) normalized += ' ' + target;
  if (label) normalized += ' :' + label;

  return `${indent}${normalized}`.trimEnd();
}
