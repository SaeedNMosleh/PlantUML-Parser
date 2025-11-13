/**
 * PlantUML Tree-sitter Grammar
 *
 * This grammar works with preprocessed PlantUML code that contains
 * disambiguation markers. The preprocessing stage resolves all ambiguities,
 * allowing this grammar to be clean and conflict-free.
 *
 * @file PlantUML grammar for tree-sitter
 * @author PlantUML Parser Team
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'plantuml',

  // External scanner tokens (from scanner.c)
  externals: $ => [
    $.start_marker,       // «START»
    $.stop_marker,        // «STOP»
    $.label_marker,       // «LABEL»
    $.content_start,      // «CONTENT_START»
    $.content_end,        // «CONTENT_END»
    $.arrow_label_marker, // «ARROW_LABEL»
    $.activity_marker,    // «ACTIVITY»
    $.condition_marker,   // «CONDITION»
    $.loop_label_marker,  // «LOOP_LABEL»
    $.note_content_line,  // Multiline note content
    $.error_sentinel      // Error recovery
  ],

  // Minimal conflicts for structural ambiguities (not semantic ones)
  conflicts: $ => [
    [$.activity_element, $._flow_source],
    [$.activity_element, $._flow_target],
    [$.while_statement, $.repeat_statement]
  ],

  // Precedence rules for clean parsing
  precedences: $ => [
    ['arrow_label', 'activity'],
    ['control_flow', 'statement']
  ],

  extras: $ => [
    /\s/  // Whitespace
  ],

  rules: {
    // Root rule - changed from source_file to match existing tests
    source_file: $ => repeat($._element),

    _element: $ => choice(
      $.diagram,
      $.comment,
      $._whitespace
    ),

    // Diagram structure
    diagram: $ => seq(
      $.startuml_directive,
      repeat($._statement),
      $.enduml_directive
    ),

    startuml_directive: $ => /@startuml(?:[ \t]+[^ \t\n\r]+)?/,
    enduml_directive: $ => /@enduml/,

    // Statements
    _statement: $ => choice(
      $.activity_element,
      $.control_flow_statement,
      $.directive_statement,
      $.partition_statement,
      $.note_statement,
      $.comment,
      $._whitespace
    ),

    // ============= Activity Diagram Elements =============

    // Activity element wrapper (matches test expectations)
    activity_element: $ => choice(
      $.start_node,
      $.stop_node,
      $.activity_node,
      $.flow_arrow,
      $.detach,
      $.kill,
      $.swimlane
    ),

    start_node: $ => choice(
      'start',
      seq(
        field('marker', $.start_marker),
        '(*)'
      )
    ),

    stop_node: $ => choice(
      'stop',
      seq(
        field('marker', $.stop_marker),
        '(*)'
      )
    ),

    // Activity nodes
    activity_node: $ => seq(
      ':',
      field('label', $.activity_label),
      ';'
    ),

    activity_label: $ => $.text_line,

    text_line: $ => /[^;]+/,

    // Flow arrows and labels
    flow_arrow: $ => prec.left(seq(
      optional(field('source', $._flow_source)),
      $.arrow,
      optional(field('target', $._flow_target)),
      optional(';')
    )),

    _flow_source: $ => choice(
      $.identifier,
      $.activity_node,
      $.start_node,
      $.stop_node
    ),

    _flow_target: $ => choice(
      $.identifier,
      $.activity_node,
      $.start_node,
      $.stop_node
    ),

    arrow: $ => prec.left(seq(
      field('style', optional($.arrow_style)),
      field('type', $.arrow_type),
      field('label', optional($.arrow_label))
    )),

    arrow_style: $ => choice(
      '-[', // Colored/styled arrow start
      '['   // Alternative style
    ),

    arrow_type: $ => choice(
      /->+/,   // Right arrow (one or more dashes)
      /<-+/,   // Left arrow
      /-->+/,  // Long right arrow
      /<--+/,  // Long left arrow
      /\.>+/,  // Dotted right arrow
      /<\.+/,  // Dotted left arrow
      '=>',    // Thick arrow
      '<='     // Thick left arrow
    ),

    arrow_label: $ => seq(
      optional(':'),
      optional($.arrow_label_marker),
      field('text', /[^;\n]+/)
    ),

    // Detach and kill
    detach: $ => 'detach',
    kill: $ => 'kill',

    // Swimlanes
    swimlane: $ => seq(
      '|',
      field('name', $.identifier),
      '|'
    ),

    // ============= Control Flow =============

    control_flow_statement: $ => choice(
      $.if_statement,
      $.while_statement,
      $.repeat_statement,
      $.fork_statement,
      $.split_statement
    ),

    // If-then-else (with marked conditions)
    if_statement: $ => seq(
      'if',
      field('condition', $.condition),
      optional('then'),
      field('then_branch', repeat($._statement)),
      repeat($.elseif_clause),
      optional($.else_clause),
      'endif'
    ),

    elseif_clause: $ => seq(
      'elseif',
      field('condition', $.condition),
      optional('then'),
      field('branch', repeat($._statement))
    ),

    else_clause: $ => seq(
      'else',
      field('branch', repeat($._statement))
    ),

    condition: $ => seq(
      optional($.condition_marker),
      '(',
      field('expression', /[^)]+/),
      ')'
    ),

    // While loops (with marked labels)
    while_statement: $ => seq(
      'while',
      field('condition', $.condition),
      optional($.loop_label),
      field('body', repeat($._statement)),
      'endwhile',
      optional($.end_loop_label)
    ),

    // Repeat-while loops
    repeat_statement: $ => prec.left(seq(
      'repeat',
      field('body', repeat($._statement)),
      'repeat',
      'while',
      field('condition', $.condition),
      optional($.loop_label)
    )),

    loop_label: $ => seq(
      optional($.loop_label_marker),
      '(',
      field('label', /[^)]+/),
      ')'
    ),

    end_loop_label: $ => seq(
      optional($.loop_label_marker),
      '(',
      field('label', /[^)]+/),
      ')'
    ),

    // Fork and split
    fork_statement: $ => prec.left(seq(
      'fork',
      optional($.fork_label),
      repeat($._statement),
      repeat($.fork_again),
      'end',
      'fork',
      optional($.fork_label)
    )),

    fork_again: $ => prec.left(seq(
      'fork',
      'again',
      optional($.fork_label),
      repeat($._statement)
    )),

    fork_label: $ => seq(
      ':',
      field('label', /[^;\n]+/)
    ),

    split_statement: $ => prec.left(seq(
      'split',
      repeat($._statement),
      repeat($.split_again),
      'end',
      'split'
    )),

    split_again: $ => prec.left(seq(
      'split',
      'again',
      repeat($._statement)
    )),

    // ============= Directives =============

    directive_statement: $ => choice(
      $.title_directive,
      $.skinparam_directive,
      $.pragma_directive,
      $.include_directive
    ),

    title_directive: $ => seq(
      'title',
      field('text', $.directive_text)
    ),

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', $.directive_value)
    ),

    pragma_directive: $ => seq(
      '!pragma',
      field('name', $.identifier),
      field('value', optional($.directive_value))
    ),

    include_directive: $ => seq(
      '!include',
      field('path', $.string)
    ),

    directive_text: $ => /[^\n]+/,
    directive_value: $ => /[^\n]+/,

    // ============= Partitions =============

    partition_statement: $ => seq(
      'partition',
      field('name', optional($.string)),
      optional($.color_spec),
      '{',
      repeat($._statement),
      '}'
    ),

    color_spec: $ => seq(
      '#',
      field('color', /[A-Fa-f0-9]{3,8}|\w+/)
    ),

    // ============= Notes =============

    note_statement: $ => choice(
      $.inline_note,
      $.multiline_note,
      $.floating_note
    ),

    inline_note: $ => seq(
      'note',
      field('position', $.note_position),
      ':',
      field('content', $.note_text)
    ),

    multiline_note: $ => seq(
      'note',
      field('position', $.note_position),
      $.content_start,
      field('content', repeat($.note_content_line)),
      $.content_end,
      'end',
      'note'
    ),

    floating_note: $ => seq(
      'note',
      choice(
        seq('"', field('content', /[^"]+/), '"'),
        seq(
          'as',
          field('id', $.identifier),
          $.content_start,
          field('content', repeat($.note_content_line)),
          $.content_end,
          'end',
          'note'
        )
      )
    ),

    note_position: $ => choice(
      'left',
      'right',
      'top',
      'bottom',
      seq('over', field('target', $.identifier))
    ),

    note_text: $ => /[^\n]+/,

    // ============= Common Elements =============

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    comment: $ => choice(
      $.line_comment,
      $.block_comment
    ),

    line_comment: $ => seq(
      "'",
      /.*/
    ),

    block_comment: $ => seq(
      "/'",
      /[^/]*/,
      "'/"
    ),

    _whitespace: $ => /\s+/
  }
});