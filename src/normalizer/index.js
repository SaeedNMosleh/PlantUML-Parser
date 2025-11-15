/**
 * PlantUML Normalizer - Removes ALL ambiguities from PlantUML syntax
 *
 * This is Pass 1 of the two-pass parser architecture.
 * It transforms ambiguous PlantUML into unambiguous normalized form.
 *
 * Transformations:
 * 1. (*) → 'start' or 'stop' based on context
 * 2. Implicit arrows → Explicit arrows
 * 3. Ambiguous keywords → Explicit keywords
 * 4. Whitespace normalization
 * 5. Control flow normalization
 * 6. Grouping normalization
 *
 * @module normalizer
 */

const { normalizeArrow: normalizeArrowRule } = require('./rules/arrows');

class PlantUMLNormalizer {
  /**
   * Create a new PlantUML normalizer
   * @param {Object} options - Configuration options
   * @param {boolean} options.debug - Enable debug mode
   * @param {boolean} options.preserveComments - Preserve comments (default: true)
   * @param {boolean} options.preserveWhitespace - Preserve original whitespace (default: false)
   */
  constructor(options = {}) {
    this.debug = options.debug || false;
    this.preserveComments = options.preserveComments !== false;
    this.preserveWhitespace = options.preserveWhitespace || false;
    this.diagramType = null;
    this.context = {
      hasSeenContent: false,
      inDiagram: false,
      lastNodeType: null,
      nodeCount: 0,
      circleNodePositions: [],
      inFloatingNote: false,
      inPartition: 0,
      inFork: false,
      inSplit: false
    };
  }

  /**
   * Main normalization entry point
   * @param {string} source - Raw PlantUML source
   * @returns {Object} { normalized: string, metadata: Object }
   */
  normalize(source) {
    // Reset context for each normalization
    this.resetContext();

    // Split into lines for line-by-line processing
    const lines = source.split('\n');
    const normalizedLines = [];

    for (let i = 0; i < lines.length; i++) {
      const line = lines[i];
      const normalized = this.normalizeLine(line, i, lines);

      if (normalized !== null) { // null means skip line
        if (Array.isArray(normalized)) {
          normalizedLines.push(...normalized);
        } else {
          normalizedLines.push(normalized);
        }
      }
    }

    // Post-processing pass
    const postProcessed = this.postProcess(normalizedLines);

    return {
      normalized: postProcessed.join('\n'),
      metadata: this.getMetadata()
    };
  }

  /**
   * Normalize a single line
   * @param {string} line - Original line
   * @param {number} lineIndex - Line number
   * @param {string[]} allLines - All lines for lookahead
   * @returns {string|string[]|null} Normalized line(s) or null to skip
   */
  normalizeLine(line, lineIndex, allLines) {
    const trimmed = line.trim();

    // Update context
    this.updateContext(trimmed);

    // Skip empty lines (preserve if preserveWhitespace is true)
    if (!trimmed) {
      return this.preserveWhitespace ? line : '';
    }

    // Handle diagram boundaries
    if (trimmed.startsWith('@startuml')) {
      this.context.inDiagram = true;
      this.detectDiagramType(allLines, lineIndex);
      return line;
    }

    if (trimmed === '@enduml') {
      this.context.inDiagram = false;
      return line;
    }

    // Only process lines inside diagram
    if (!this.context.inDiagram) return line;

    // Handle comments
    if (trimmed.startsWith("'") || trimmed.startsWith("/'") || trimmed.startsWith("'/")) {
      return this.preserveComments ? line : null;
    }

    // Apply transformation rules in order
    let normalized = line;

    // Rule 1: Convert (*) to explicit start/stop
    const circleResult = this.normalizeCircleNode(normalized, trimmed);
    if (circleResult !== normalized) {
      return circleResult;
    }

    // Rule 2: Normalize activity nodes
    const activityResult = this.normalizeActivityNode(normalized, trimmed);
    if (activityResult !== normalized) {
      return activityResult;
    }

    // Rule 3: Normalize arrows
    const arrowResult = this.normalizeArrow(normalized, trimmed);
    if (arrowResult !== normalized) {
      return arrowResult;
    }

    // Rule 4: Normalize control flow
    const controlResult = this.normalizeControlFlow(normalized, trimmed);
    if (controlResult !== normalized) {
      return controlResult;
    }

    // Rule 5: Normalize partitions and groups
    const groupingResult = this.normalizeGrouping(normalized, trimmed);
    if (groupingResult !== normalized) {
      return groupingResult;
    }

    // Rule 6: Normalize notes
    const noteResult = this.normalizeNote(normalized, trimmed);
    if (noteResult !== normalized) {
      return noteResult;
    }

    // Rule 7: Normalize directives
    const directiveResult = this.normalizeDirective(normalized, trimmed);
    if (directiveResult !== normalized) {
      return directiveResult;
    }

    return normalized;
  }

  /**
   * Rule 1: Convert (*) to explicit start/stop
   * First (*) → 'start'
   * Last (*) → 'stop' (determined by looking ahead)
   * Middle (*) → 'stop'
   */
  normalizeCircleNode(line, trimmed) {
    if (trimmed !== '(*)') return line;

    // Store position for later analysis
    this.context.circleNodePositions.push(this.context.nodeCount);

    // Determine if this is start or stop
    if (!this.context.hasSeenContent) {
      // First (*) is always start
      this.context.hasSeenContent = true;
      this.context.lastNodeType = 'start';
      this.context.nodeCount++;
      return this.preserveWhitespace ? line.replace('(*)', 'start') : 'start';
    } else {
      // For now, treat as stop (will be refined in post-processing)
      this.context.lastNodeType = 'stop';
      this.context.nodeCount++;
      return this.preserveWhitespace ? line.replace('(*)', 'stop') : 'stop';
    }
  }

  /**
   * Rule 2: Normalize activity nodes
   * Ensure consistent formatting: :text;
   */
  normalizeActivityNode(line, trimmed) {
    // Match activity node pattern
    const activityMatch = trimmed.match(/^:(.+);$/);
    if (activityMatch) {
      this.context.hasSeenContent = true;
      this.context.lastNodeType = 'activity';
      this.context.nodeCount++;

      // Ensure no extra spaces around colons and semicolons
      const content = activityMatch[1].trim();

      const indentMatch = line.match(/^(\s*)/);
      const indent = indentMatch ? indentMatch[1] : '';

      return `${indent}:${content};`;
    }
    return line;
  }

  /**
   * Rule 3: Normalize arrows
   * Convert various arrow styles to consistent format
   */
  normalizeArrow(line, trimmed) {
    const indentMatch = line.match(/^(\s*)/);
    const indent = indentMatch ? indentMatch[1] : '';
    const normalized = normalizeArrowRule(trimmed, indent);

    if (normalized !== null) {
      this.context.hasSeenContent = true;
      return normalized;
    }

    return line;
  }

  /**
   * Rule 4: Normalize control flow structures
   */
  normalizeControlFlow(line, trimmed) {
    const indentMatch = line.match(/^(\s*)/);
    const indent = indentMatch ? indentMatch[1] : '';

    // If-then-else normalization
    if (trimmed.startsWith('if ') || trimmed.match(/^if\s*\(/)) {
      this.context.hasSeenContent = true;

      // Pattern: if (condition) then (label)
      const match = trimmed.match(/^if\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` (${match[2].trim()})` : '';
        return `${indent}if (${condition}) then${label}`;
      }

      // Pattern: if (condition) then
      const simpleMatch = trimmed.match(/^if\s*\((.+?)\)\s*then$/);
      if (simpleMatch) {
        const condition = simpleMatch[1].trim();
        return `${indent}if (${condition}) then`;
      }
    }

    // While loop normalization
    if (trimmed.startsWith('while ') || trimmed.match(/^while\s*\(/)) {
      this.context.hasSeenContent = true;

      const match = trimmed.match(/^while\s*\((.+?)\)(?:\s*is\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` is (${match[2].trim()})` : '';
        return `${indent}while (${condition})${label}`;
      }
    }

    // Repeat normalization
    if (trimmed === 'repeat') {
      this.context.hasSeenContent = true;
      return `${indent}repeat`;
    }

    // Normalize else/elseif/endif/endwhile
    const controlKeywords = ['else', 'elseif', 'endif', 'endwhile'];
    for (const keyword of controlKeywords) {
      if (trimmed === keyword || trimmed.startsWith(keyword + ' ') || trimmed.startsWith(keyword + '(')) {

        // Handle else with label: else (label)
        if (keyword === 'else') {
          const match = trimmed.match(/^else(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : '';
            return `${indent}else${label}`;
          }
        }

        // Handle elseif with condition: elseif (condition) then (label)
        if (keyword === 'elseif') {
          const match = trimmed.match(/^elseif\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
          if (match) {
            const condition = match[1].trim();
            const label = match[2] ? ` (${match[2].trim()})` : '';
            return `${indent}elseif (${condition}) then${label}`;
          }
        }

        // Handle endwhile with label: endwhile (label)
        if (keyword === 'endwhile') {
          const match = trimmed.match(/^endwhile(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : '';
            return `${indent}endwhile${label}`;
          }
        }

        // Simple keyword
        if (trimmed === keyword) {
          return `${indent}${keyword}`;
        }
      }
    }

    // Fork and split
    if (trimmed === 'fork' || trimmed === 'fork again' || trimmed === 'end fork') {
      return `${indent}${trimmed}`;
    }

    if (trimmed === 'split' || trimmed === 'split again' || trimmed === 'end split') {
      return `${indent}${trimmed}`;
    }

    return line;
  }

  /**
   * Rule 5: Normalize grouping constructs
   */
  normalizeGrouping(line, trimmed) {
    // Partition normalization
    if (trimmed.startsWith('partition ')) {
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';

      // Pattern: partition Name #color {
      const match = trimmed.match(/^partition\s+(.+?)(?:\s+(#[\w]+))?\s*\{?$/);
      if (match) {
        const name = match[1].trim().replace(/^["']|["']$/g, ''); // Remove quotes if present
        const color = match[2] ? ` ${match[2]}` : '';
        const hasOpenBrace = trimmed.endsWith('{');
        this.context.inPartition++;
        return `${indent}partition "${name}"${color}${hasOpenBrace ? ' {' : ''}`;
      }
    }

    // Closing brace for partition
    if (trimmed === '}' && this.context.inPartition > 0) {
      this.context.inPartition--;
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';
      return `${indent}}`;
    }

    // Swimlane normalization: |Name| → |Name|
    const swimlaneMatch = trimmed.match(/^\|(.+?)\|$/);
    if (swimlaneMatch) {
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';
      const name = swimlaneMatch[1].trim();
      return `${indent}|${name}|`;
    }

    return line;
  }

  /**
   * Rule 6: Normalize notes
   */
  normalizeNote(line, trimmed) {
    // Note directive patterns
    // note left: text
    // note right: text
    // note left
    //   multiline content
    // end note

    if (trimmed.startsWith('note ')) {
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';

      // Single line note: note position: text
      const singleLineMatch = trimmed.match(/^note\s+(left|right|top|bottom)\s*:\s*(.+)$/);
      if (singleLineMatch) {
        const position = singleLineMatch[1];
        const content = singleLineMatch[2].trim();
        return `${indent}note ${position}: ${content}`;
      }

      // Multiline note start: note position
      const multiLineMatch = trimmed.match(/^note\s+(left|right|top|bottom)$/);
      if (multiLineMatch) {
        this.context.inFloatingNote = true;
        const position = multiLineMatch[1];
        return `${indent}note ${position}`;
      }
    }

    // End note
    if (trimmed === 'end note' && this.context.inFloatingNote) {
      this.context.inFloatingNote = false;
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';
      return `${indent}end note`;
    }

    // Inside multiline note - preserve content
    if (this.context.inFloatingNote) {
      return line;
    }

    return line;
  }

  /**
   * Rule 7: Normalize directives
   */
  normalizeDirective(line, trimmed) {
    // Title directive
    if (trimmed.startsWith('title ')) {
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';
      const title = trimmed.substring(6).trim();
      return `${indent}title ${title}`;
    }

    // Skinparam directive
    if (trimmed.startsWith('skinparam ')) {
      const indent = this.preserveWhitespace ? line.match(/^(\s*)/)[1] : '';
      const match = trimmed.match(/^skinparam\s+(\w+)\s+(.+)$/);
      if (match) {
        const param = match[1];
        const value = match[2].trim();
        return `${indent}skinparam ${param} ${value}`;
      }
    }

    return line;
  }

  /**
   * Post-processing: Refine transformations with full context
   */
  postProcess(lines) {
    // Find all 'stop' nodes and verify the last one
    const stopIndices = [];
    lines.forEach((line, i) => {
      if (line.trim() === 'stop') {
        stopIndices.push(i);
      }
    });

    // If we have multiple stops, check if the last one should remain stop
    // This requires looking at what comes after each stop
    if (stopIndices.length > 1) {
      for (let i = 0; i < stopIndices.length - 1; i++) {
        const stopIdx = stopIndices[i];
        // Check if there's activity after this stop
        let hasActivityAfter = false;
        for (let j = stopIdx + 1; j < lines.length; j++) {
          const line = lines[j].trim();
          if (line.startsWith(':') || line === 'start' ||
              line.startsWith('if ') || line.startsWith('while ')) {
            hasActivityAfter = true;
            break;
          }
          if (line === '@enduml') break;
        }

        // If there's activity after, this might be a junction point
        // Keep as 'stop' for now - could be refined further
      }
    }

    return lines;
  }

  /**
   * Detect diagram type from content
   */
  detectDiagramType(lines, startIndex) {
    // Look ahead for type indicators
    for (let i = startIndex + 1; i < Math.min(startIndex + 20, lines.length); i++) {
      const line = lines[i].trim();

      if (line.includes('participant') || line.includes('actor')) {
        this.diagramType = 'sequence';
        break;
      }
      if (line.includes('class ') || line.includes('interface ')) {
        this.diagramType = 'class';
        break;
      }
      if (line.includes('state ')) {
        this.diagramType = 'state';
        break;
      }
      if (line.startsWith(':') || line.includes('start') || line.includes('(*)')) {
        this.diagramType = 'activity';
        break;
      }
    }
  }

  /**
   * Update context based on current line
   */
  updateContext(trimmed) {
    // Update node count for any significant content
    // (already handled in specific rules)
  }

  /**
   * Reset context for new normalization
   */
  resetContext() {
    this.context = {
      hasSeenContent: false,
      inDiagram: false,
      lastNodeType: null,
      nodeCount: 0,
      circleNodePositions: [],
      inFloatingNote: false,
      inPartition: 0,
      inFork: false,
      inSplit: false
    };
    this.diagramType = null;
  }

  /**
   * Get metadata about the normalization
   */
  getMetadata() {
    return {
      diagramType: this.diagramType,
      nodeCount: this.context.nodeCount,
      hasCircleNodes: this.context.circleNodePositions.length > 0,
      circleNodeCount: this.context.circleNodePositions.length
    };
  }

  /**
   * Enable debug logging
   */
  log(...args) {
    if (this.debug) {
      console.log('[PlantUMLNormalizer]', ...args);
    }
  }
}

module.exports = PlantUMLNormalizer;
