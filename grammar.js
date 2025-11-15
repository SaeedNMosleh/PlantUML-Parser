/**
 * PlantUML Tree-sitter Grammar - Simplified Two-Pass Architecture
 *
 * This grammar is designed to parse NORMALIZED PlantUML code.
 * All ambiguities are resolved by the normalizer (Pass 1), allowing this
 * grammar to be clean, simple, and conflict-free.
 *
 * Key Design Principles:
 * - NO external scanner (all parsing in grammar rules)
 * - NO preprocessing markers (normalizer removes ambiguities)
 * - NO conflicts (normalized input is unambiguous)
 * - Simple, maintainable rules
 *
 * @file PlantUML grammar for tree-sitter (Pass 2 of two-pass parser)
 * @author PlantUML Parser Team
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'plantuml',

  word: $ => $.identifier,

  // NO externals - everything is in the grammar
  extras: $ => [
    /\s/,  // Whitespace
    $.line_comment,
    $.block_comment
  ],

  // Minimal structural conflicts (unavoidable with current design)
  conflicts: $ => [],

  rules: {
    // ============= ROOT =============

    source_file: $ => repeat($._element),

    _element: $ => choice(
      $.diagram,
      $.line_comment,
      $.block_comment
    ),

    // ============= DIAGRAM STRUCTURE =============

    diagram: $ => seq(
      $.startuml_directive,
      repeat($._statement),
      $.enduml_directive
    ),

    startuml_directive: $ => /@startuml(?:[ \t]+[^\n]*)?/,
    enduml_directive: $ => /@enduml/,

    // ============= STATEMENTS =============

    _statement: $ => choice(
      $.activity_element
    ),

    // Activity element wrapper (for compatibility with existing tests)
    activity_element: $ => choice(
      $.start_node,
      $.stop_node,
      $.activity_node,
      $.flow_arrow,
      $.decision_node,
      $.while_loop,
      $.repeat_loop,
      $.partition,
      $.swimlane,
      $.fork_node,
      $.join_node,
      $.split_node,
      $.split_join_node,
      $.title_directive,
      $.note_directive,
      $.skinparam_directive,
      $.detach,
      $.kill
    ),

    // ============= SIMPLE NODES (normalized from (*)) =============

    start_node: $ => 'start',
    stop_node: $ => 'stop',

    // ============= ACTIVITY NODES (already normalized) =============

    activity_node: $ => seq(
      ':',
      field('label', $.activity_label),
      ';'
    ),

    activity_label: $ => /[^;\n]+/,

    // ============= ARROWS (normalized format) =============

    flow_arrow: $ => choice(
      seq(
        field('type', $.arrow_type),
        field('label', alias(token.immediate(/:[^\n;]+/), $.arrow_label))
      ),
      field('type', $.arrow_type)
    ),

    arrow_endpoint: $ => choice(
      $.identifier,
      'start',
      'stop'
    ),

    arrow_type: $ => choice(
      '->',
      '-->',
      '->>',
      '.>',
      '<-',
      '<--',
      '<<-',
      '<.'
    ),

    arrow_label: $ => token(/:[^\n;]+/),

    // ============= CONTROL FLOW (normalized format) =============

    // If-then-else statements
    decision_node: $ => seq(
      'if',
      field('condition', $.condition),
      'then',
      optional(field('true_label', $.branch_label)),
      repeat($._statement),
      repeat($.elseif_branch),
      optional($.else_branch),
      'endif'
    ),

    elseif_branch: $ => seq(
      'elseif',
      field('condition', $.condition),
      'then',
      optional(field('label', $.branch_label)),
      repeat($._statement)
    ),

    else_branch: $ => seq(
      'else',
      optional(field('label', $.branch_label)),
      repeat($._statement)
    ),

    condition: $ => seq('(', /[^)]+/, ')'),
    branch_label: $ => seq('(', /[^)]+/, ')'),

    // While loops
    while_loop: $ => seq(
      'while',
      field('condition', $.condition),
      optional(seq('is', field('label', $.branch_label))),
      repeat($._statement),
      'endwhile',
      optional(field('end_label', $.branch_label))
    ),

    // Repeat-while loops
    repeat_loop: $ => prec.right(seq(
      'repeat',
      repeat1($._statement),
      'repeat',
      'while',
      field('condition', $.condition),
      optional(seq('is', field('label', $.branch_label)))
    )),

    // ============= GROUPING (normalized format) =============

    partition: $ => prec.right(choice(
      // Partition with braces
      seq(
        'partition',
        field('name', $.string),
        optional(field('color', $.color)),
        '{',
        repeat($._statement),
        '}'
      ),
      // Partition without braces (inline)
      seq(
        'partition',
        field('name', $.string),
        optional(field('color', $.color))
      )
    )),

    swimlane: $ => seq(
      '|',
      field('name', $.swimlane_name),
      '|'
    ),

    swimlane_name: $ => /[^|]+/,

    // ============= FORK/SPLIT =============

    fork_node: $ => choice(
      token(seq('fork', /\s+/, 'again')),
      'fork'
    ),

    join_node: $ => seq('end', 'fork'),

    split_node: $ => choice(
      token(seq('split', /\s+/, 'again')),
      'split'
    ),

    split_join_node: $ => seq('end', 'split'),

    // ============= DIRECTIVES (normalized format) =============

    title_directive: $ => seq(
      'title',
      field('content', $.text_content)
    ),

    note_directive: $ => choice(
      // Multi-line note
      seq(
        'note',
        field('position', $.note_position),
        repeat1($.note_line),
        'end',
        'note'
      ),
      // Single line note: note position: content
      seq(
        'note',
        field('position', $.note_position),
        ':',
        field('content', $.text_content)
      )
    ),

    note_position: $ => choice('left', 'right', 'top', 'bottom'),
    note_line: $ => /[^\n]+/,

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', $.text_content)
    ),

    // ============= SPECIAL NODES =============

    detach: $ => 'detach',
    kill: $ => 'kill',

    // ============= BASIC ELEMENTS =============

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    string: $ => seq(
      '"',
      /[^"]*/,
      '"'
    ),

    color: $ => seq('#', /[a-zA-Z0-9]+/),

    text_content: $ => /[^\n]+/,

    // ============= COMMENTS =============

    line_comment: $ => token(seq("'", /.*/)),

    block_comment: $ => token(seq(
      "/'",
      repeat(choice(
        /[^']/,
        /'[^/]/
      )),
      "'/"
    ))
  }
});
