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
    // Include the trailing line ending when present.
    // `tree-sitter test` corpus extraction can leave a dangling '\r' at the end of
    // input blocks on CRLF files, which would otherwise surface as an EOF error.
    enduml_directive: $ => /@enduml[ \t]*(?:\r?\n|\r)?/,

    // ============= STATEMENTS =============

    _statement: $ => choice(
      $.activity_element,
      $.sequence_element,
      $.directive_statement,
      $.preproc_directive
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
      $.detach,
      $.kill
    ),

    // Sequence element wrapper
    sequence_element: $ => choice(
      $.participant_declaration,
      $.message_statement,
      $.activation_statement,
      $.deactivation_statement,
      $.create_statement,
      $.destroy_statement,
      $.sequence_note,
      $.fragment_block,
      $.ref_block,
      $.box_block,
      $.autonumber_statement
    ),

    // Common directives shared across diagrams
    directive_statement: $ => choice(
      $.title_directive,
      $.skinparam_directive,
      $.skinparam_block,
      $.note_directive
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
        // Allow optional whitespace between arrow and label.
        field('label', $.arrow_label)
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

    // Must be on the same line as the arrow. Allow spaces/tabs before ':' but
    // disallow newlines by using token.immediate.
    arrow_label: $ => token.immediate(/[ \t]*:[^\n;]+/),

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
    _repeat_while: _ => token(/repeat\s+while/),
    repeat_loop: $ => prec.right(seq(
      'repeat',
      repeat1($._statement),
      $._repeat_while,
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

    // Activity note (colon form). Multi-line activity notes intentionally omitted
    // to avoid ambiguity with sequence notes like "note left of".
    note_directive: $ => seq(
      'note',
      field('position', $.note_position),
      ':',
      field('content', $.text_content)
    ),

    note_position: $ => choice('left', 'right', 'top', 'bottom'),
    // Low-precedence line content so explicit terminators like "end note" win.
    note_line: $ => token(prec(-1, /[^\n]+/)),

    skinparam_directive: $ => seq(
      'skinparam',
      field('parameter', $.identifier),
      field('value', $.text_content)
    ),

    skinparam_block: $ => seq(
      'skinparam',
      field('scope', $.identifier),
      '{',
      repeat($.skinparam_block_line),
      '}'
    ),

    skinparam_block_line: $ => /[^\n]+/,

    // ============= PREPROCESSOR DIRECTIVES (includes/macros) =============

    preproc_directive: $ => choice(
      $.include_directive,
      $.includeurl_directive,
      $.import_directive,
      $.define_directive,
      $.undef_directive,
      $.if_directive,
      $.ifdef_directive,
      $.ifndef_directive,
      $.elseif_directive,
      $.else_directive,
      $.endif_directive,
      $.pragma_directive
    ),

    include_directive: $ => seq(
      '!include',
      field('target', $.include_target)
    ),

    includeurl_directive: $ => seq(
      '!includeurl',
      field('target', $.include_target)
    ),

    import_directive: $ => seq(
      '!import',
      field('target', $.include_target)
    ),

    include_target: $ => choice(
      $.string,
      $.angle_string,
      $.path_token
    ),

    angle_string: $ => token(seq('<', /[^>\n]+/, '>')),
    // Exclude quotes and angle brackets so "..." is always parsed as $.string
    // and <...> as $.angle_string.
    path_token: $ => token(/[^\s\n"<>]+/),

    define_directive: $ => seq(
      '!define',
      field('name', $.identifier),
      optional(field('value', $.rest_of_line))
    ),

    undef_directive: $ => seq(
      '!undef',
      field('name', $.identifier)
    ),

    if_directive: $ => seq(
      '!if',
      field('condition', $.rest_of_line)
    ),

    ifdef_directive: $ => seq(
      '!ifdef',
      field('name', $.identifier)
    ),

    ifndef_directive: $ => seq(
      '!ifndef',
      field('name', $.identifier)
    ),

    elseif_directive: $ => seq(
      '!elseif',
      field('condition', $.rest_of_line)
    ),

    else_directive: $ => '!else',

    endif_directive: $ => '!endif',

    pragma_directive: $ => seq(
      '!pragma',
      field('args', $.rest_of_line)
    ),

    // ============= SEQUENCE DIAGRAM =============

    participant_declaration: $ => seq(
      field('kind', $.participant_keyword),
      field('name', choice($.identifier, $.string)),
      optional(seq('as', field('alias', $.identifier))),
      optional(field('stereotype', $.stereotype)),
      optional(field('color', $.color))
    ),

    participant_keyword: $ => choice(
      'participant',
      'actor',
      'boundary',
      'control',
      'entity',
      'database',
      'collections',
      'queue'
    ),

    stereotype: $ => token(seq('<<', /[^>\n]+/, '>>')),

    message_statement: $ => seq(
      field('from', choice($.identifier, $.string)),
      field('arrow', $.message_arrow),
      field('to', choice($.identifier, $.string)),
      optional(field('activation', $.message_activation)),
      optional(field('label', $.message_label))
    ),

    // Arrow token between lifelines.
    // Tree-sitter regex does not support lookaround; this pattern forces at least
    // one of '-', '<', '>' to appear somewhere in the token.
    message_arrow: $ => token(/[^\s:]*[-<>][^\s:]*/),

    message_activation: $ => choice('++', '--', '+', '-'),

    // Message label (rest of the current line), including the ':' separator.
    // token.immediate prevents newlines/other statements from being captured.
    message_label: $ => token.immediate(/\s*:\s*[^\n]+/),

    activation_statement: $ => seq(
      'activate',
      field('target', choice($.identifier, $.string))
    ),

    deactivation_statement: $ => seq(
      'deactivate',
      field('target', choice($.identifier, $.string))
    ),

    create_statement: $ => seq(
      'create',
      field('target', choice($.identifier, $.string))
    ),

    destroy_statement: $ => seq(
      'destroy',
      field('target', choice($.identifier, $.string))
    ),

    autonumber_statement: $ => seq(
      'autonumber',
      optional(field('args', $.rest_of_line))
    ),

    sequence_note: $ => choice(
      // Single-line: note left/right of X: text
      seq(
        'note',
        $.sequence_note_placement,
        ':',
        field('content', $.text_content)
      ),
      // Multi-line: note ... then lines, end note
      seq(
        'note',
        $.sequence_note_placement,
        $._newline,
        repeat1($.note_line),
        $._end_note
      )
    ),

    sequence_note_placement: $ => choice(
      seq('left', 'of', $.participant_ref_list),
      seq('right', 'of', $.participant_ref_list),
      seq('over', $.participant_ref_list)
    ),

    participant_ref_list: $ => seq(
      choice($.identifier, $.string),
      repeat(seq(',', choice($.identifier, $.string)))
    ),

    fragment_block: $ => prec.right(seq(
      field('kind', $.fragment_kind),
      optional(field('label', $.rest_of_line)),
      repeat($._statement),
      repeat($.fragment_else_branch),
      $._end_line
    )),

    fragment_kind: $ => choice('alt', 'opt', 'loop', 'par', 'break', 'critical', 'group'),

    fragment_else_branch: $ => prec.right(seq(
      'else',
      optional(field('label', $.rest_of_line)),
      repeat($._statement)
    )),

    ref_block: $ => choice(
      // Single-line: ref over A,B: text
      seq(
        'ref',
        'over',
        $.participant_ref_list,
        ':',
        field('content', $.text_content)
      ),
      // Multi-line: ref over A,B ... end ref
      seq(
        'ref',
        'over',
        $.participant_ref_list,
        $._newline,
        repeat1($.note_line),
        $._end_ref
      )
    ),

    box_block: $ => seq(
      'box',
      optional(field('title', $.string)),
      optional(field('color', $.color)),
      repeat($._statement),
      $._end_box
    ),

    // (Intentionally no generic catch-all statement: explicit grammar keeps AST accurate
    // and prevents greedy tokens from swallowing valid constructs.)

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

    // Remainder of the current line (including at least one leading whitespace).
    // Use token.immediate to avoid ambiguity: either the rest-of-line exists
    // right here, or it doesn't.
    rest_of_line: $ => token.immediate(/\s+[^\n]+/),

    // Unnamed newline token used to disambiguate multi-line blocks from single-line
    // forms that have trailing content on the same line.
    _newline: $ => token.immediate(/\r?\n/),

    // Hidden token for a bare fragment terminator line: `end` followed by a line break.
    // Includes the line break so it can't match prefixes like `endwhile`/`endif`.
    _end_line: $ => token(prec(3, /end[\t ]*\r?\n/)),

    // Hidden block terminators for multi-line constructs.
    _end_note: $ => token(prec(4, /end note/)),
    _end_ref: $ => token(prec(4, /end ref/)),
    _end_box: $ => token(prec(4, /end box/)),

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
