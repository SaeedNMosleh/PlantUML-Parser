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

  word: $ => $.identifier,

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
    [$.while_loop, $.repeat_loop]
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
      $.title_directive,
      $.skinparam_directive,
      $.pragma_directive,
      $.include_directive,
      $.note_directive,
      $.comment,
      $._whitespace
    ),

    // ============= Activity Diagram Elements =============

    // Activity element wrapper (matches test expectations)
    activity_element: $ => choice(
      $.start_node,
      $.stop_node,
      $.activity_node,
      $.decision_node,
      $.while_loop,
      $.repeat_loop,
      $.fork_node,
      $.join_node,
      $.partition,
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

    // If-then-else (decision nodes)
    decision_node: $ => seq(
      'if',
      field('condition', $.condition_expression),
      'then',
      optional(prec(2, field('true_label', $.branch_label))),
      repeat($._statement),
      repeat($.elseif_branch),
      optional($.else_branch),
      'endif'
    ),

    elseif_branch: $ => seq(
      'elseif',
      field('condition', $.condition_expression),
      'then',
      optional(prec(2, field('label', $.branch_label))),
      repeat($._statement)
    ),

    else_branch: $ => seq(
      'else',
      optional(prec(2, field('label', $.branch_label))),
      repeat($._statement)
    ),

    branch_label: $ => seq(
      '(',
      /[^)]+/,
      ')'
    ),

    condition_expression: $ => seq(
      optional($.condition_marker),
      '(',
      /[^)]+/,
      ')'
    ),

    // While loops
    while_loop: $ => seq(
      'while',
      field('condition', $.condition_expression),
      optional(seq('is', field('label', $.branch_label))),
      repeat($._statement),
      'endwhile',
      optional(field('end_label', $.branch_label))
    ),

    // Repeat-while loops
    repeat_loop: $ => prec.left(seq(
      'repeat',
      repeat1($._statement),
      'repeat',
      'while',
      field('condition', $.condition_expression),
      optional(seq('is', field('label', $.branch_label)))
    )),

    loop_label: $ => seq(
      optional($.loop_label_marker),
      '(',
      /[^)]+/,
      ')'
    ),

    end_loop_label: $ => seq(
      optional($.loop_label_marker),
      '(',
      /[^)]+/,
      ')'
    ),

    // Fork and split - flat markers
    fork_node: $ => choice(
      token(seq('fork', /\s+/, 'again')),
      token(seq('split', /\s+/, 'again')),
      'fork',
      'split'
    ),

    join_node: $ => choice(
      seq('end', 'fork'),
      seq('end', 'split')
    ),

    // ============= Directives =============

    title_directive: $ => seq(
      'title',
      field('content', alias(/[^\n]+/, $.text_line))
    ),

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', $.identifier)
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

    partition: $ => seq(
      'partition',
      field('name', optional(choice($.string, $.identifier))),
      optional($.color_spec),
      '{',
      repeat($._statement),
      '}'
    ),

    color_spec: $ => seq(
      '#',
      field('color', $.identifier)
    ),

    // ============= Notes =============

    note_directive: $ => choice(
      $.note_line,
      $.floating_note
    ),

    note_line: $ => seq(
      'note',
      field('position', $.identifier),
      ':',
      field('content', alias(/[^\n]+/, $.text_line))
    ),

    floating_note: $ => seq(
      'note',
      field('position', $.identifier),
      $.content_start,
      repeat1($.note_content_line),
      $.content_end,
      'end',
      'note'
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