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
    /\s/  // Whitespace
  ],

  conflicts: $ => [
    [$.start_node, $.stop_node],
    [$.stop_node, $.join_node],
    [$.activity_label, $.multiline_text],
    [$.note_line, $.note_content],
    [$.repeat_while, $.while_loop]
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
      '(*top)',
      prec.dynamic(2, '(*)'),
      prec.dynamic(2, seq('(', '*', ')'))
    ),

    // Stop node
    stop_node: $ => choice(
      'stop',
      'end',
      prec.dynamic(1, '(*)'),
      prec.dynamic(1, seq('(', '*', ')'))
    ),

    // Decision node: if-then-else
    decision_node: $ => seq(
      'if',
      '(',
      field('condition', $.condition_expression),
      ')',
      'then',
      optional(seq('(', field('true_label', $.branch_label), ')')),
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
      'then',
      optional(seq('(', field('label', $.branch_label), ')')),
      repeat($._diagram_element)
    ),

    else_branch: $ => seq(
      'else',
      optional(seq('(', field('label', $.branch_label), ')')),
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
    repeat_while: $ => prec.left(seq(
      'repeat',
      optional(seq(token.immediate(':'), field('repeat_label', alias(token(/[^\n]+/), $.branch_label)))),
      repeat($._diagram_element),
      'repeat',
      'while',
      '(',
      field('condition', $.condition_expression),
      ')',
      'is',
      '(',
      field('label', $.branch_label),
      ')',
      optional(seq(choice('->', '-->'), optional($.arrow_label)))
    )),

    // While loop
    while_loop: $ => prec.left(seq(
      'while',
      '(',
      field('condition', $.condition_expression),
      ')',
      'is',
      '(',
      field('label', $.branch_label),
      ')',
      repeat($._diagram_element),
      'endwhile',
      optional(seq(token.immediate('('), field('end_label', $.branch_label), ')'))
    )),

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
      $.note_line,
      $.floating_note
    ),

    floating_note: $ => prec.right(1, seq(
      'note',
      field('position', alias(choice('left', 'right', 'top', 'bottom'), $.identifier)),
      optional(seq('of', field('target', $.identifier))),
      optional(':'),
      field('content', $.note_content),
      seq('end', 'note')
    )),

    note_line: $ => seq(
      'note',
      field('position', alias(choice('left', 'right'), $.identifier)),
      optional(':'),
      field('content', $.text_line)
    ),

    note_content: $ => prec.left(repeat1($.text_line)),

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', $.identifier)
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

    branch_label: $ => /[^)\n]+/,

    number: $ => /\d+/,

    string: $ => choice(
      seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
      seq("'", repeat(choice(/[^'\\]/, /\\./)), "'")
    ),
  }
});
