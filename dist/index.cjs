"use strict";
var __create = Object.create;
var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __getProtoOf = Object.getPrototypeOf;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __export = (target, all) => {
  for (var name in all)
    __defProp(target, name, { get: all[name], enumerable: true });
};
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toESM = (mod, isNodeMode, target) => (target = mod != null ? __create(__getProtoOf(mod)) : {}, __copyProps(
  // If the importer is in node compatibility mode or this is not an ESM
  // file that has been converted to a CommonJS file using a Babel-
  // compatible transform (i.e. "__esModule" has not been set), then set
  // "default" to the CommonJS "module.exports" for node compatibility.
  isNodeMode || !mod || !mod.__esModule ? __defProp(target, "default", { value: mod, enumerable: true }) : target,
  mod
));
var __toCommonJS = (mod) => __copyProps(__defProp({}, "__esModule", { value: true }), mod);

// src/index.ts
var src_exports = {};
__export(src_exports, {
  PlantUMLNormalizer: () => PlantUMLNormalizer,
  default: () => PlantUMLParserNode
});
module.exports = __toCommonJS(src_exports);

// src/normalizer/rules/arrows.ts
var ARROW_TYPES = {
  SOLID: "->",
  DASHED: "-->",
  THICK: "->>",
  DOTTED: ".>",
  SOLID_LEFT: "<-",
  DASHED_LEFT: "<--",
  THICK_LEFT: "<<-",
  DOTTED_LEFT: "<."
};
function detectArrowType(trimmed) {
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
    if (trimmed.includes(arrow)) return arrow;
  }
  return null;
}
function parseArrow(trimmed) {
  const arrowType = detectArrowType(trimmed);
  if (!arrowType) return null;
  const parts = trimmed.split(arrowType);
  const source = parts[0]?.trim() || null;
  const afterArrow = parts[1] ? parts[1].trim() : "";
  let target = null;
  let label = null;
  if (afterArrow) {
    if (afterArrow.startsWith(":")) {
      label = afterArrow.substring(1).trim();
    } else {
      const colonIndex = afterArrow.indexOf(":");
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
function normalizeArrow(trimmed, indent = "") {
  const parsed = parseArrow(trimmed);
  if (!parsed) return null;
  const { arrowType, source, target, label } = parsed;
  let normalized = "";
  if (source) normalized += source;
  if (normalized.length > 0) normalized += " ";
  normalized += arrowType;
  if (target) normalized += " " + target;
  if (label) normalized += " :" + label;
  return `${indent}${normalized}`.trimEnd();
}

// src/normalizer/index.ts
var PlantUMLNormalizer = class {
  debug;
  preserveComments;
  preserveWhitespace;
  diagramType;
  context;
  constructor(options = {}) {
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
  normalize(source) {
    this.resetContext();
    const lines = source.split("\n");
    const normalizedLines = [];
    const normalizedLineToOriginalLine = [];
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
      normalized: postProcessed.join("\n"),
      metadata: {
        ...this.getMetadata(),
        sourceMap: { normalizedLineToOriginalLine }
      }
    };
  }
  normalizeLine(line, lineIndex, allLines) {
    const trimmed = line.trim();
    this.updateContext(trimmed);
    if (!trimmed) {
      return this.preserveWhitespace ? line : "";
    }
    if (trimmed.startsWith("@startuml")) {
      this.context.inDiagram = true;
      this.detectDiagramType(allLines, lineIndex);
      return line;
    }
    if (trimmed === "@enduml") {
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
  getIndent(line) {
    const match = line.match(/^(\s*)/);
    return match ? match[1] : "";
  }
  normalizeCircleNode(line, trimmed) {
    if (trimmed !== "(*)") return line;
    this.context.circleNodePositions.push(this.context.nodeCount);
    if (!this.context.hasSeenContent) {
      this.context.hasSeenContent = true;
      this.context.lastNodeType = "start";
      this.context.nodeCount++;
      return this.preserveWhitespace ? line.replace("(*)", "start") : "start";
    }
    this.context.lastNodeType = "stop";
    this.context.nodeCount++;
    return this.preserveWhitespace ? line.replace("(*)", "stop") : "stop";
  }
  normalizeActivityNode(line, trimmed) {
    const activityMatch = trimmed.match(/^:(.+);$/);
    if (activityMatch) {
      this.context.hasSeenContent = true;
      this.context.lastNodeType = "activity";
      this.context.nodeCount++;
      const content = activityMatch[1].trim();
      const indent = this.getIndent(line);
      return `${indent}:${content};`;
    }
    return line;
  }
  normalizeArrow(line, trimmed) {
    const indent = this.getIndent(line);
    const normalized = normalizeArrow(trimmed, indent);
    if (normalized !== null) {
      this.context.hasSeenContent = true;
      return normalized;
    }
    return line;
  }
  normalizeControlFlow(line, trimmed) {
    const indent = this.getIndent(line);
    if (trimmed.startsWith("if ") || trimmed.match(/^if\s*\(/)) {
      this.context.hasSeenContent = true;
      const match = trimmed.match(/^if\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` (${match[2].trim()})` : "";
        return `${indent}if (${condition}) then${label}`;
      }
      const simpleMatch = trimmed.match(/^if\s*\((.+?)\)\s*then$/);
      if (simpleMatch) {
        const condition = simpleMatch[1].trim();
        return `${indent}if (${condition}) then`;
      }
    }
    if (trimmed.startsWith("while ") || trimmed.match(/^while\s*\(/)) {
      this.context.hasSeenContent = true;
      const match = trimmed.match(/^while\s*\((.+?)\)(?:\s*is\s*\((.+?)\))?$/);
      if (match) {
        const condition = match[1].trim();
        const label = match[2] ? ` is (${match[2].trim()})` : "";
        return `${indent}while (${condition})${label}`;
      }
    }
    if (trimmed === "repeat") {
      this.context.hasSeenContent = true;
      return `${indent}repeat`;
    }
    const controlKeywords = ["else", "elseif", "endif", "endwhile"];
    for (const keyword of controlKeywords) {
      if (trimmed === keyword || trimmed.startsWith(keyword + " ") || trimmed.startsWith(keyword + "(")) {
        if (keyword === "else") {
          const match = trimmed.match(/^else(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : "";
            return `${indent}else${label}`;
          }
        }
        if (keyword === "elseif") {
          const match = trimmed.match(/^elseif\s*\((.+?)\)\s*then(?:\s*\((.+?)\))?$/);
          if (match) {
            const condition = match[1].trim();
            const label = match[2] ? ` (${match[2].trim()})` : "";
            return `${indent}elseif (${condition}) then${label}`;
          }
        }
        if (keyword === "endwhile") {
          const match = trimmed.match(/^endwhile(?:\s*\((.+?)\))?$/);
          if (match) {
            const label = match[1] ? ` (${match[1].trim()})` : "";
            return `${indent}endwhile${label}`;
          }
        }
        if (trimmed === keyword) {
          return `${indent}${keyword}`;
        }
      }
    }
    if (trimmed === "fork" || trimmed === "fork again" || trimmed === "end fork") {
      return `${indent}${trimmed}`;
    }
    if (trimmed === "split" || trimmed === "split again" || trimmed === "end split") {
      return `${indent}${trimmed}`;
    }
    if (trimmed.startsWith("repeat while")) {
      this.context.hasSeenContent = true;
      return `${indent}${trimmed.replace(/\s+/g, " ").trim()}`;
    }
    return line;
  }
  normalizeGrouping(line, trimmed) {
    if (trimmed.startsWith("partition ")) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      const match = trimmed.match(/^partition\s+(.+?)(?:\s+(#[\w]+))?\s*\{?$/);
      if (match) {
        const name = match[1].trim().replace(/^["']|["']$/g, "");
        const color = match[2] ? ` ${match[2]}` : "";
        const hasOpenBrace = trimmed.endsWith("{");
        this.context.inPartition++;
        return `${indent}partition "${name}"${color}${hasOpenBrace ? " {" : ""}`;
      }
    }
    if (trimmed === "}" && this.context.inPartition > 0) {
      this.context.inPartition--;
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      return `${indent}}`;
    }
    const swimlaneMatch = trimmed.match(/^\|(.+?)\|$/);
    if (swimlaneMatch) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      const name = swimlaneMatch[1].trim();
      return `${indent}|${name}|`;
    }
    return line;
  }
  normalizeNote(line, trimmed) {
    if (trimmed.startsWith("note ")) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
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
    if (trimmed === "end note" && this.context.inFloatingNote) {
      this.context.inFloatingNote = false;
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      return `${indent}end note`;
    }
    if (this.context.inFloatingNote) return line;
    return line;
  }
  normalizeDirective(line, trimmed) {
    if (trimmed.startsWith("title ")) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      const title = trimmed.substring(6).trim();
      return `${indent}title ${title}`;
    }
    if (trimmed.startsWith("skinparam ")) {
      const indent = this.preserveWhitespace ? this.getIndent(line) : "";
      const match = trimmed.match(/^skinparam\s+(\w+)\s+(.+)$/);
      if (match) {
        const param = match[1];
        const value = match[2].trim();
        return `${indent}skinparam ${param} ${value}`;
      }
    }
    return line;
  }
  postProcess(lines) {
    void lines;
    return lines;
  }
  detectDiagramType(lines, startIndex) {
    for (let i = startIndex + 1; i < Math.min(startIndex + 20, lines.length); i++) {
      const line = lines[i].trim();
      if (line.includes("participant") || line.includes("actor")) {
        this.diagramType = "sequence";
        break;
      }
      if (line.includes("class ") || line.includes("interface ")) {
        this.diagramType = "class";
        break;
      }
      if (line.includes("state ")) {
        this.diagramType = "state";
        break;
      }
      if (line.startsWith(":") || line.includes("start") || line.includes("(*)")) {
        this.diagramType = "activity";
        break;
      }
    }
  }
  updateContext(_trimmed) {
  }
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
  getMetadata() {
    return {
      diagramType: this.diagramType,
      nodeCount: this.context.nodeCount,
      hasCircleNodes: this.context.circleNodePositions.length > 0,
      circleNodeCount: this.context.circleNodePositions.length
    };
  }
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  log(...args) {
    if (this.debug) {
      console.log("[PlantUMLNormalizer]", ...args);
    }
  }
};

// src/core/parser.ts
var PlantUMLParser = class {
  options;
  normalizer;
  backend;
  constructor(backend, options = {}) {
    this.backend = backend;
    this.options = {
      debug: options.debug ?? false,
      preserveComments: options.preserveComments ?? true,
      preserveWhitespace: options.preserveWhitespace ?? false,
      skipNormalization: options.skipNormalization ?? false
    };
    this.normalizer = new PlantUMLNormalizer({
      debug: this.options.debug,
      preserveComments: this.options.preserveComments,
      preserveWhitespace: this.options.preserveWhitespace
    });
  }
  parse(source, options = {}) {
    const skip = options.skipNormalization ?? this.options.skipNormalization;
    if (skip) {
      return this.backend.parseNormalized(source, { oldTree: options.oldTree });
    }
    const norm = this.normalize(source);
    const parsed = this.backend.parseNormalized(norm.normalized, { oldTree: options.oldTree });
    return {
      tree: parsed.tree,
      normalized: norm.normalized,
      metadata: norm.metadata
    };
  }
  normalize(source) {
    return this.normalizer.normalize(source);
  }
  parseNormalized(source, options = {}) {
    const parsed = this.backend.parseNormalized(source, { oldTree: options.oldTree });
    return { tree: parsed.tree };
  }
  parseToJSON(source, options = {}) {
    const { tree } = this.parse(source, options);
    return tree?.rootNode ?? tree;
  }
  getLanguage() {
    return this.backend.getLanguage();
  }
  getParser() {
    return this.backend.getParser();
  }
  getNormalizer() {
    return this.normalizer;
  }
};

// src/runtimes/node-native.ts
var import_node_fs = __toESM(require("fs"));
var import_node_path = __toESM(require("path"));
var import_node_url = require("url");
var import_node_module = require("module");
var import_meta = {};
function getRuntimeFileName() {
  if (typeof __filename !== "undefined") return __filename;
  return (0, import_node_url.fileURLToPath)(import_meta.url);
}
function findPackageRoot(startDir) {
  let current = startDir;
  for (; ; ) {
    if (import_node_fs.default.existsSync(import_node_path.default.join(current, "package.json"))) return current;
    const parent = import_node_path.default.dirname(current);
    if (parent === current) throw new Error("Failed to locate package root (package.json).");
    current = parent;
  }
}
function loadNativeBinding() {
  const require2 = (0, import_node_module.createRequire)(
    // eslint-disable-next-line no-undef
    typeof __filename !== "undefined" ? __filename : import_meta.url
  );
  const startDir = import_node_path.default.dirname(getRuntimeFileName());
  const root = findPackageRoot(startDir);
  const load = require2("node-gyp-build");
  const binding = load(root);
  if (!binding?.language) {
    throw new Error("Native binding loaded but did not expose language.");
  }
  return { language: binding.language };
}
function createNodeNativeBackend() {
  const require2 = (0, import_node_module.createRequire)(
    // eslint-disable-next-line no-undef
    typeof __filename !== "undefined" ? __filename : import_meta.url
  );
  const TreeSitter = require2("tree-sitter");
  const Parser = TreeSitter;
  const { language } = loadNativeBinding();
  const parser = new Parser();
  parser.setLanguage(language);
  return {
    parseNormalized(source, options) {
      const oldTree = options?.oldTree;
      const tree = parser.parse(source, oldTree);
      return { tree };
    },
    getLanguage() {
      return language;
    },
    getParser() {
      return parser;
    }
  };
}

// src/index.ts
var PlantUMLParserNode = class extends PlantUMLParser {
  constructor(options = {}) {
    super(createNodeNativeBackend(), options);
  }
};
// Annotate the CommonJS export names for ESM import in node:
0 && (module.exports = {
  PlantUMLNormalizer
});
//# sourceMappingURL=index.cjs.map