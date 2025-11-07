/**
 * @file PlantUML grammar for tree-sitter
 * @author PlantUML Parser Team
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'plantuml',

  extras: $ => [
    $.comment,
    /\s/  // Whitespace
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.diagram,
      $.comment
    ),

    diagram: $ => seq(
      $.startuml_directive,
      repeat($._diagram_element),
      $.enduml_directive
    ),

    startuml_directive: $ => seq(
      '@startuml',
      optional($.identifier)
    ),

    enduml_directive: $ => '@enduml',

    _diagram_element: $ => choice(
      $.activity_element,
      $._common_directive,
      $.comment
    ),

    // ===========================
    // Activity Diagram Elements
    // ===========================

    activity_element: $ => choice(
      $.activity_node,
      $.start_node,
      $.stop_node,
      $.decision_node,
      $.fork_node,
      $.join_node,
      $.partition,
      $.swimlane,
      $.flow_arrow,
      $.repeat_while,
      $.while_loop,
      $.detach_statement
    ),

    // Activity node: :label;
    activity_node: $ => seq(
      ':',
      field('label', $.activity_label),
      ';'
    ),

    activity_label: $ => choice(
      $.text_line,
      $.multiline_text
    ),

    multiline_text: $ => seq(
      $.text_line,
      repeat(seq('\\n', $.text_line))
    ),

    // Start node
    start_node: $ => choice(
      'start',
      seq('(', '*', ')'),
      '(*)',
      '(*top)'
    ),

    // Stop node
    stop_node: $ => choice(
      'stop',
      'end',
      seq('(', '*', ')'),
      '(*)'
    ),

    // Decision node: if-then-else
    decision_node: $ => seq(
      'if',
      '(',
      field('condition', $.condition_expression),
      ')',
      optional('is'),
      'then',
      optional(seq('(', field('true_label', $.text_line), ')')),
      repeat($._diagram_element),
      repeat($.elseif_branch),
      optional($.else_branch),
      'endif'
    ),

    elseif_branch: $ => seq(
      'elseif',
      '(',
      field('condition', $.condition_expression),
      ')',
      optional('is'),
      'then',
      optional(seq('(', field('label', $.text_line), ')')),
      repeat($._diagram_element)
    ),

    else_branch: $ => seq(
      'else',
      optional(seq('(', field('label', $.text_line), ')')),
      repeat($._diagram_element)
    ),

    condition_expression: $ => /[^)]+/,

    // Fork/Join nodes
    fork_node: $ => choice(
      'fork',
      seq('fork', 'again'),
      'split',
      seq('split', 'again')
    ),

    join_node: $ => choice(
      seq('end', 'fork'),
      seq('end', 'split')
    ),

    // Partition
    partition: $ => seq(
      'partition',
      field('name', choice($.identifier, $.quoted_identifier)),
      optional($.color_spec),
      '{',
      repeat($._diagram_element),
      '}'
    ),

    // Swimlane
    swimlane: $ => seq(
      '|',
      field('name', $.swimlane_name),
      '|'
    ),

    swimlane_name: $ => /[^|\n]+/,

    color_spec: $ => seq(
      '#',
      $.color
    ),

    color: $ => token(choice(
      /[A-Za-z][A-Za-z0-9_]*/,  // Named color
      /[0-9A-Fa-f]{6}/,          // Hex color
      /[0-9A-Fa-f]{3}/           // Short hex
    )),

    // Flow arrow
    flow_arrow: $ => choice(
      seq('->', optional(field('label', $.arrow_label)), ';'),
      seq('-->', optional(field('label', $.arrow_label)), ';')
    ),

    arrow_label: $ => /[^;\n]+/,

    // Repeat-while loop
    repeat_while: $ => seq(
      'repeat',
      optional(seq(':', field('repeat_label', $.text_line))),
      repeat($._diagram_element),
      'repeat',
      'while',
      '(',
      field('condition', $.condition_expression),
      ')',
      optional('is'),
      optional(seq('(', field('label', $.text_line), ')')),
      optional(seq(choice('->', '-->'), optional($.arrow_label)))
    ),

    // While loop
    while_loop: $ => seq(
      'while',
      '(',
      field('condition', $.condition_expression),
      ')',
      optional('is'),
      optional(seq('(', field('label', $.text_line), ')')),
      repeat($._diagram_element),
      'endwhile',
      optional(seq('(', field('end_label', $.text_line), ')'))
    ),

    // Detach
    detach_statement: $ => 'detach',

    // ===========================
    // Common Directives
    // ===========================

    _common_directive: $ => choice(
      $.title_directive,
      $.note_directive,
      $.skinparam_directive
    ),

    title_directive: $ => seq(
      'title',
      field('content', $.text_line)
    ),

    note_directive: $ => choice(
      $.floating_note,
      $.note_line
    ),

    floating_note: $ => seq(
      'note',
      field('position', choice('left', 'right', 'top', 'bottom')),
      optional(seq('of', field('target', $.identifier))),
      optional(':'),
      field('content', $.note_content),
      'end',
      'note'
    ),

    note_line: $ => seq(
      'note',
      field('position', choice('left', 'right')),
      optional(':'),
      field('content', $.text_line)
    ),

    note_content: $ => repeat1($.text_line),

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', choice($.identifier, $.color, $.number, $.string))
    ),

    // ===========================
    // Comments
    // ===========================

    comment: $ => choice(
      $.line_comment,
      $.block_comment
    ),

    line_comment: $ => token(seq(
      "'",
      /[^\n]*/
    )),

    block_comment: $ => token(seq(
      "/'",
      repeat(choice(
        /[^*]/,
        /\*[^/]/
      )),
      "'/"
    )),

    // ===========================
    // Basic Tokens
    // ===========================

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    quoted_identifier: $ => seq(
      '"',
      /[^"]+/,
      '"'
    ),

    text_line: $ => /[^\n;]+/,

    number: $ => /\d+/,

    string: $ => choice(
      seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
      seq("'", repeat(choice(/[^'\\]/, /\\./)), "'")
    ),
  }
});
