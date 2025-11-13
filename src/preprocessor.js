/**
 * PlantUML Preprocessing Pipeline
 *
 * This module preprocesses PlantUML source code to resolve ambiguities
 * that make tree-sitter parsing difficult. It adds explicit markers to
 * context-dependent syntax, making the grammar simpler and more reliable.
 *
 * AMBIGUITIES ADDRESSED:
 *
 * 1. Start/Stop Node Ambiguity
 *    Problem: (*) can mean start_node or stop_node depending on position
 *    Solution: Replace with «START»(*) or «STOP»(*) based on context
 *
 * 2. While Loop End Label Ambiguity
 *    Problem: "endwhile (label)" parsing fails, parser closes loop early
 *    Solution: Add «LABEL» marker: "endwhile «LABEL»(label)"
 *
 * 3. Floating Note Content Ambiguity
 *    Problem: External scanner fails to recognize multiline note content
 *    Solution: Wrap content with «CONTENT_START»/«CONTENT_END»
 *
 * @module preprocessor
 */

class PlantUMLPreprocessor {
  /**
   * Create a new preprocessor instance
   * @param {Object} options - Configuration options
   * @param {boolean} options.preserveLineNumbers - Keep source line mapping (default: true)
   * @param {boolean} options.debug - Enable debug output (default: false)
   * @param {Array<string>} options.enabledRules - Which rules to apply (default: all)
   */
  constructor(options = {}) {
    this.preserveLineNumbers = options.preserveLineNumbers ?? true;
    this.debug = options.debug ?? false;
    this.enabledRules = options.enabledRules ?? ['start-stop', 'end-label', 'floating-note'];
  }

  /**
   * Preprocess PlantUML source code
   * @param {string} source - Original PlantUML source
   * @returns {Object} Result object with processed code and source map
   * @returns {string} result.processed - Preprocessed source code
   * @returns {Map<number, number>} result.sourceMap - Map from processed line to original line
   * @returns {Object} result.stats - Statistics about applied transformations
   */
  preprocess(source) {
    const lines = source.split('\n');
    const sourceMap = new Map(); // preprocessed line number -> original line number
    const stats = {
      startStopReplacements: 0,
      endLabelAnnotations: 0,
      floatingNoteMarkers: 0
    };

    // Initialize parsing state
    const state = {
      inDiagram: false,
      hasSeenActivity: false,
      inFloatingNote: false,
      lineNumber: 0
    };

    const processedLines = [];

    for (let i = 0; i < lines.length; i++) {
      const line = lines[i];
      state.lineNumber = i;

      // Track original line numbers
      const currentOutputLine = processedLines.length;

      // Update diagram state
      this._updateState(line, state);

      // Apply preprocessing rules
      let processedLine = line;
      let addedLines = [];

      if (this.enabledRules.includes('start-stop')) {
        const result = this._disambiguateStartStop(processedLine, state, stats);
        processedLine = result.line;
      }

      if (this.enabledRules.includes('end-label')) {
        const result = this._annotateEndLabels(processedLine, state, stats);
        processedLine = result.line;
      }

      if (this.enabledRules.includes('floating-note')) {
        const result = this._markFloatingNoteContent(processedLine, state, stats);
        processedLine = result.line;
        addedLines = result.addedLines || [];
      }

      // Add processed line(s) with source mapping
      processedLines.push(processedLine);
      sourceMap.set(currentOutputLine, i);

      // Handle any additional lines added by preprocessing
      for (let j = 0; j < addedLines.length; j++) {
        processedLines.push(addedLines[j]);
        sourceMap.set(processedLines.length - 1, i); // Map to original line
      }
    }

    if (this.debug) {
      console.log('Preprocessing stats:', stats);
    }

    return {
      processed: processedLines.join('\n'),
      sourceMap,
      stats
    };
  }

  /**
   * Update parsing state based on current line
   * @private
   */
  _updateState(line, state) {
    const trimmed = line.trim();

    // Track diagram boundaries
    if (trimmed === '@startuml' || trimmed.startsWith('@startuml ')) {
      state.inDiagram = true;
      state.hasSeenActivity = false;
    } else if (trimmed === '@enduml') {
      state.inDiagram = false;
      state.hasSeenActivity = false;
    }

    // Track activity content
    // Activity nodes: :Label;
    if (/^\s*:.+;/.test(line)) {
      state.hasSeenActivity = true;
    }

    // Decision nodes also count as activity
    if (/^\s*(if|while|repeat|fork|split|partition|swimlane)\b/.test(line)) {
      state.hasSeenActivity = true;
    }
  }

  /**
   * RULE 1: Disambiguate (*) tokens into start_node or stop_node
   *
   * Problem: (*) is ambiguous - could be start or stop based on context
   * Solution: First (*) in diagram = «START»(*), subsequent = «STOP»(*)
   *
   * @private
   */
  _disambiguateStartStop(line, state, stats) {
    const trimmed = line.trim();

    // Only process standalone (*) lines
    if (trimmed === '(*)' && state.inDiagram) {
      if (!state.hasSeenActivity) {
        // First (*) or before any activity = START
        stats.startStopReplacements++;
        return {
          line: line.replace('(*)', '«START»(*)'),
          replaced: true
        };
      } else {
        // After activity content = STOP
        stats.startStopReplacements++;
        return {
          line: line.replace('(*)', '«STOP»(*)'),
          replaced: true
        };
      }
    }

    return { line, replaced: false };
  }

  /**
   * RULE 2: Annotate while loop end labels
   *
   * Problem: "endwhile (label)" fails to parse - loop closes early
   * Solution: Add «LABEL» marker to make end label explicit
   *
   * Example:
   *   Input:  endwhile (no)
   *   Output: endwhile «LABEL»(no)
   *
   * @private
   */
  _annotateEndLabels(line, state, stats) {
    // Match "endwhile" followed by optional whitespace and "("
    // This indicates an optional end label
    if (/endwhile\s*\(/.test(line)) {
      stats.endLabelAnnotations++;
      return {
        line: line.replace(/endwhile\s*\(/, 'endwhile «LABEL»('),
        annotated: true
      };
    }

    return { line, annotated: false };
  }

  /**
   * RULE 3: Mark floating note content boundaries
   *
   * Problem: External scanner struggles with multiline note content
   * Solution: Add explicit markers for content block boundaries
   *
   * Example:
   *   Input:  note left
   *             Content line 1
   *             Content line 2
   *           end note
   *
   *   Output: note left
   *           «CONTENT_START»
   *             Content line 1
   *             Content line 2
   *           «CONTENT_END»
   *           end note
   *
   * @private
   */
  _markFloatingNoteContent(line, state, stats) {
    const trimmed = line.trim();
    const addedLines = [];

    // Detect start of floating note (note without colon on same line)
    // Pattern: "note left", "note right", "note top", "note bottom"
    // Optionally followed by: "of <identifier>"
    const floatingNoteStart = /^note\s+(left|right|top|bottom)(?:\s+of\s+\w+)?\s*$/;

    if (floatingNoteStart.test(trimmed)) {
      // This is a floating note (no colon, content on next lines)
      state.inFloatingNote = true;
      stats.floatingNoteMarkers++;

      // Add content begin marker on next line
      addedLines.push('«CONTENT_START»');

      return { line, addedLines };
    }

    // Detect end of floating note
    if (state.inFloatingNote && /^end\s+note/.test(trimmed)) {
      state.inFloatingNote = false;

      // We need to insert «CONTENT_END» BEFORE "end note"
      // Return the marker as current line, and "end note" as added line
      return {
        line: '«CONTENT_END»',
        addedLines: [line]
      };
    }

    return { line, addedLines };
  }

  /**
   * Get statistics about the last preprocessing operation
   * @returns {Object} Statistics object
   */
  getStats() {
    return this._lastStats || {};
  }

  /**
   * Check if a line was modified by preprocessing
   * @param {string} original - Original line
   * @param {string} processed - Processed line
   * @returns {boolean} True if line was modified
   */
  wasModified(original, processed) {
    return original !== processed;
  }
}

// Export for Node.js and browser environments
if (typeof module !== 'undefined' && module.exports) {
  module.exports = { PlantUMLPreprocessor };
} else if (typeof window !== 'undefined') {
  window.PlantUMLPreprocessor = PlantUMLPreprocessor;
}
