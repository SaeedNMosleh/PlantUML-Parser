import { normalizeArrow as normalizeArrowRule } from './rules/arrows';
import type { NormalizationMetadata, NormalizationResult } from '../core/types';

type NormalizerOptions = {
  debug?: boolean;
  preserveComments?: boolean;
  preserveWhitespace?: boolean;
};

type NormalizerContext = {
  hasSeenContent: boolean;
  inDiagram: boolean;
  lastNodeType: string | null;
  nodeCount: number;
  circleNodePositions: number[];
  inFloatingNote: boolean;
  inPartition: number;
  inFork: boolean;
  inSplit: boolean;
};

export default class PlantUMLNormalizer {
  private debug: boolean;
  private preserveComments: boolean;
  private preserveWhitespace: boolean;
  private diagramType: string | null;
  private context: NormalizerContext;

  constructor(options: NormalizerOptions = {}) {
    this.debug = options.debug ?? false;
    this.preserveComments = options.preserveComments !== false;
    this.preserveWhitespace = options.preserveWhitespace ?? false;
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

  normalize(source: string): NormalizationResult {
    this.resetContext();

    const lines = source.split('\n');
    const normalizedLines: string[] = [];
    const normalizedLineToOriginalLine: number[] = [];

    for (let i = 0; i < lines.length; i++) {
      const line = lines[i];
      const normalized = this.normalizeLine(line, i, lines);

      if (normalized !== null) {
        if (Array.isArray(normalized)) {
          normalizedLines.push(...normalized);
          for (let k = 0; k < normalized.length; k++) normalizedLineToOriginalLine.push(i);
        } else {
          normalizedLines.push(normalized);
          normalizedLineToOriginalLine.push(i);
        }
      }
    }

    const postProcessed = this.postProcess(normalizedLines);

    return {
      normalized: postProcessed.join('\n'),
      metadata: {
        ...this.getMetadata(),
        sourceMap: { normalizedLineToOriginalLine }
      }
    };
  }

  private normalizeLine(line: string, lineIndex: number, allLines: string[]): string | string[] | null {
    const trimmed = line.trim();

    this.updateContext(trimmed);

    if (!trimmed) {
      return this.preserveWhitespace ? line : '';
    }

    if (trimmed.startsWith('@startuml')) {
      this.context.inDiagram = true;
      this.detectDiagramType(allLines, lineIndex);
      return line;
    }

    if (trimmed === '@enduml') {
      this.context.inDiagram = false;
      return line;
    }

    if (!this.context.inDiagram) return line;

    if (trimmed.startsWith("'") || trimmed.startsWith("/'") || trimmed.startsWith("'/")) {
      return this.preserveComments ? line : null;
    }

    let normalized = line;

    const circleResult = this.normalizeCircleNode(normalized, trimmed);
    if (circleResult !== normalized) return circleResult;

    const activityResult = this.normalizeActivityNode(normalized, trimmed);
    if (activityResult !== normalized) return activityResult;

    const arrowResult = this.normalizeArrow(normalized, trimmed);
    if (arrowResult !== normalized) return arrowResult;

    const controlResult = this.normalizeControlFlow(normalized, trimmed);
    if (controlResult !== normalized) return controlResult;

    const groupingResult = this.normalizeGrouping(normalized, trimmed);
    if (groupingResult !== normalized) return groupingResult;

    const noteResult = this.normalizeNote(normalized, trimmed);
    if (noteResult !== normalized) return noteResult;

    const directiveResult = this.normalizeDirective(normalized, trimmed);
    if (directiveResult !== normalized) return directiveResult;

    return normalized;
  }

  private getIndent(line: string): string {
    const match = line.match(/^(\s*)/);
    return match ? match[1] : '';
  }

  private normalizeCircleNode(line: string, trimmed: string): string {
    if (trimmed !== '(*)') return line;

    this.context.circleNodePositions.push(this.context.nodeCount);

    if (!this.context.hasSeenContent) {
      this.context.hasSeenContent = true;
      this.context.lastNodeType = 'start';
      this.context.nodeCount++;
      return this.preserveWhitespace ? line.replace('(*)', 'start') : 'start';
    }

    this.context.lastNodeType = 'stop';
    this.context.nodeCount++;
    return this.preserveWhitespace ? line.replace('(*)', 'stop') : 'stop';
  }

  private normalizeActivityNode(line: string, trimmed: string): string {
    const activityMatch = trimmed.match(/^:(.+);$/);
    if (activityMatch) {
      this.context.hasSeenContent = true;
      this.context.lastNodeType = 'activity';
      this.context.nodeCount++;

      const content = activityMatch[1].trim();
      const indent = this.getIndent(line);
      return `${indent}:${content};`;
    }
    return line;
  }

  private normalizeArrow(line: string, trimmed: string): string {
    const indent = this.getIndent(line);
    const normalized = normalizeArrowRule(trimmed, indent);

    if (normalized !== null) {
      this.context.hasSeenContent = true;
      return normalized;
    }

    return line;
  }

  private normalizeControlFlow(line: string, trimmed: string): string {
    const indent = this.getIndent(line);

    if (trimmed.startsWith('if ') || trimmed.match(/^if\s*\(/)) {
      this.context.hasSeenContent = true;

      const match = trimmed.match(/^if\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` (${match[2].trim()})` : '';
        return `${indent}if (${condition}) then${label}`;
      }

      const simpleMatch = trimmed.match(/^if\s*\((.+?)\)\s*then$/);
      if (simpleMatch) {
        const condition = simpleMatch[1].trim();
        return `${indent}if (${condition}) then`;
      }
    }

    if (trimmed.startsWith('while ') || trimmed.match(/^while\s*\(/)) {
      this.context.hasSeenContent = true;
      const match = trimmed.match(/^while\s*\((.+?)\)(?:\s*is\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` is (${match[2].trim()})` : '';
        return `${indent}while (${condition})${label}`;
      }
    }

    if (trimmed === 'repeat') {
      this.context.hasSeenContent = true;
      return `${indent}repeat`;
    }

    const controlKeywords = ['else', 'elseif', 'endif', 'endwhile'] as const;
    for (const keyword of controlKeywords) {
      if (trimmed === keyword || trimmed.startsWith(keyword + ' ') || trimmed.startsWith(keyword + '(')) {
        if (keyword === 'else') {
          const match = trimmed.match(/^else(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : '';
            return `${indent}else${label}`;
          }
        }

        if (keyword === 'elseif') {
          const match = trimmed.match(/^elseif\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
          if (match) {
            const condition = match[1].trim();
            const label = match[2] ? ` (${match[2].trim()})` : '';
            return `${indent}elseif (${condition}) then${label}`;
          }
        }

        if (keyword === 'endwhile') {
          const match = trimmed.match(/^endwhile(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : '';
            return `${indent}endwhile${label}`;
          }
        }

        if (trimmed === keyword) {
          return `${indent}${keyword}`;
        }
      }
    }

    if (trimmed === 'fork' || trimmed === 'fork again' || trimmed === 'end fork') {
      return `${indent}${trimmed}`;
    }

    if (trimmed === 'split' || trimmed === 'split again' || trimmed === 'end split') {
      return `${indent}${trimmed}`;
    }

    // Pass-through for repeat while (legacy kept as-is)
    if (trimmed.startsWith('repeat while')) {
      this.context.hasSeenContent = true;
      return `${indent}${trimmed.replace(/\s+/g, ' ').trim()}`;
    }

    return line;
  }

  private normalizeGrouping(line: string, trimmed: string): string {
    if (trimmed.startsWith('partition ')) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';

      const match = trimmed.match(/^partition\s+(.+?)(?:\s+(#[\w]+))?\s*\{?$/);
      if (match) {
        const name = match[1].trim().replace(/^["']|["']$/g, '');
        const color = match[2] ? ` ${match[2]}` : '';
        const hasOpenBrace = trimmed.endsWith('{');
        this.context.inPartition++;
        return `${indent}partition "${name}"${color}${hasOpenBrace ? ' {' : ''}`;
      }
    }

    if (trimmed === '}' && this.context.inPartition > 0) {
      this.context.inPartition--;
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';
      return `${indent}}`;
    }

    const swimlaneMatch = trimmed.match(/^\|(.+?)\|$/);
    if (swimlaneMatch) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';
      const name = swimlaneMatch[1].trim();
      return `${indent}|${name}|`;
    }

    return line;
  }

  private normalizeNote(line: string, trimmed: string): string {
    if (trimmed.startsWith('note ')) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';

      const singleLineMatch = trimmed.match(/^note\s+(left|right|top|bottom)\s*:\s*(.+)$/);
      if (singleLineMatch) {
        const position = singleLineMatch[1];
        const content = singleLineMatch[2].trim();
        return `${indent}note ${position}: ${content}`;
      }

      const multiLineMatch = trimmed.match(/^note\s+(left|right|top|bottom)$/);
      if (multiLineMatch) {
        this.context.inFloatingNote = true;
        const position = multiLineMatch[1];
        return `${indent}note ${position}`;
      }
    }

    if (trimmed === 'end note' && this.context.inFloatingNote) {
      this.context.inFloatingNote = false;
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';
      return `${indent}end note`;
    }

    if (this.context.inFloatingNote) return line;

    return line;
  }

  private normalizeDirective(line: string, trimmed: string): string {
    if (trimmed.startsWith('title ')) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';
      const title = trimmed.substring(6).trim();
      return `${indent}title ${title}`;
    }

    if (trimmed.startsWith('skinparam ')) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : '';
      const match = trimmed.match(/^skinparam\s+(\w+)\s+(.+)$/);
      if (match) {
        const param = match[1];
        const value = match[2].trim();
        return `${indent}skinparam ${param} ${value}`;
      }
    }

    return line;
  }

  private postProcess(lines: string[]): string[] {
    // Legacy placeholder: no structural modifications today.
    // Future: refine circle node interpretation across the diagram.
    void lines;
    return lines;
  }

  private detectDiagramType(lines: string[], startIndex: number): void {
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

  private updateContext(_trimmed: string): void {
    // Intentionally left minimal; nodeCount updated in rules.
  }

  private resetContext(): void {
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

  private getMetadata(): NormalizationMetadata {
    return {
      diagramType: this.diagramType,
      nodeCount: this.context.nodeCount,
      hasCircleNodes: this.context.circleNodePositions.length > 0,
      circleNodeCount: this.context.circleNodePositions.length
    };
  }

  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  private log(...args: any[]): void {
    if (this.debug) {
      // eslint-disable-next-line no-console
      console.log('[PlantUMLNormalizer]', ...args);
    }
  }
}
