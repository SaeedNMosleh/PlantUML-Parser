#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 233
#define LARGE_STATE_COUNT 44
#define SYMBOL_COUNT 120
#define ALIAS_COUNT 0
#define TOKEN_COUNT 76
#define EXTERNAL_TOKEN_COUNT 11
#define FIELD_COUNT 17
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 30

enum {
  sym_identifier = 1,
  sym_startuml_directive = 2,
  sym_enduml_directive = 3,
  anon_sym_start = 4,
  anon_sym_LPAREN_STAR_RPAREN = 5,
  anon_sym_stop = 6,
  anon_sym_COLON = 7,
  anon_sym_SEMI = 8,
  sym_text_line = 9,
  anon_sym_DASH_LBRACK = 10,
  anon_sym_LBRACK = 11,
  aux_sym_arrow_type_token1 = 12,
  aux_sym_arrow_type_token2 = 13,
  aux_sym_arrow_type_token3 = 14,
  aux_sym_arrow_type_token4 = 15,
  aux_sym_arrow_type_token5 = 16,
  aux_sym_arrow_type_token6 = 17,
  anon_sym_EQ_GT = 18,
  anon_sym_LT_EQ = 19,
  aux_sym_arrow_label_token1 = 20,
  sym_detach = 21,
  sym_kill = 22,
  anon_sym_PIPE = 23,
  anon_sym_if = 24,
  anon_sym_then = 25,
  anon_sym_endif = 26,
  anon_sym_elseif = 27,
  anon_sym_else = 28,
  anon_sym_LPAREN = 29,
  aux_sym_branch_label_token1 = 30,
  anon_sym_RPAREN = 31,
  anon_sym_while = 32,
  anon_sym_is = 33,
  anon_sym_endwhile = 34,
  anon_sym_repeat = 35,
  aux_sym_fork_node_token1 = 36,
  aux_sym_fork_node_token2 = 37,
  anon_sym_fork = 38,
  anon_sym_split = 39,
  anon_sym_end = 40,
  anon_sym_title = 41,
  aux_sym_title_directive_token1 = 42,
  anon_sym_skinparam = 43,
  anon_sym_BANGpragma = 44,
  anon_sym_BANGinclude = 45,
  anon_sym_partition = 46,
  anon_sym_LBRACE = 47,
  anon_sym_RBRACE = 48,
  anon_sym_POUND = 49,
  anon_sym_note = 50,
  anon_sym_left = 51,
  anon_sym_right = 52,
  anon_sym_top = 53,
  anon_sym_bottom = 54,
  anon_sym_over = 55,
  anon_sym_DQUOTE = 56,
  aux_sym_string_token1 = 57,
  anon_sym_SQUOTE = 58,
  aux_sym_string_token2 = 59,
  aux_sym_line_comment_token1 = 60,
  anon_sym_SLASH_SQUOTE = 61,
  aux_sym_block_comment_token1 = 62,
  anon_sym_SQUOTE_SLASH = 63,
  sym__whitespace = 64,
  sym_start_marker = 65,
  sym_stop_marker = 66,
  sym_label_marker = 67,
  sym_content_start = 68,
  sym_content_end = 69,
  sym_arrow_label_marker = 70,
  sym_activity_marker = 71,
  sym_condition_marker = 72,
  sym_loop_label_marker = 73,
  sym_note_content_line = 74,
  sym_error_sentinel = 75,
  sym_source_file = 76,
  sym__element = 77,
  sym_diagram = 78,
  sym__statement = 79,
  sym_activity_element = 80,
  sym_start_node = 81,
  sym_stop_node = 82,
  sym_activity_node = 83,
  sym_activity_label = 84,
  sym_flow_arrow = 85,
  sym__flow_source = 86,
  sym__flow_target = 87,
  sym_arrow = 88,
  sym_arrow_style = 89,
  sym_arrow_type = 90,
  sym_arrow_label = 91,
  sym_swimlane = 92,
  sym_decision_node = 93,
  sym_elseif_branch = 94,
  sym_else_branch = 95,
  sym_branch_label = 96,
  sym_condition_expression = 97,
  sym_while_loop = 98,
  sym_repeat_loop = 99,
  sym_fork_node = 100,
  sym_join_node = 101,
  sym_title_directive = 102,
  sym_skinparam_directive = 103,
  sym_pragma_directive = 104,
  sym_include_directive = 105,
  sym_directive_value = 106,
  sym_partition = 107,
  sym_color_spec = 108,
  sym_note_directive = 109,
  sym_note_line = 110,
  sym_floating_note = 111,
  sym_string = 112,
  sym_comment = 113,
  sym_line_comment = 114,
  sym_block_comment = 115,
  aux_sym_source_file_repeat1 = 116,
  aux_sym_diagram_repeat1 = 117,
  aux_sym_decision_node_repeat1 = 118,
  aux_sym_floating_note_repeat1 = 119,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_startuml_directive] = "startuml_directive",
  [sym_enduml_directive] = "enduml_directive",
  [anon_sym_start] = "start",
  [anon_sym_LPAREN_STAR_RPAREN] = "(*)",
  [anon_sym_stop] = "stop",
  [anon_sym_COLON] = ":",
  [anon_sym_SEMI] = ";",
  [sym_text_line] = "text_line",
  [anon_sym_DASH_LBRACK] = "-[",
  [anon_sym_LBRACK] = "[",
  [aux_sym_arrow_type_token1] = "arrow_type_token1",
  [aux_sym_arrow_type_token2] = "arrow_type_token2",
  [aux_sym_arrow_type_token3] = "arrow_type_token3",
  [aux_sym_arrow_type_token4] = "arrow_type_token4",
  [aux_sym_arrow_type_token5] = "arrow_type_token5",
  [aux_sym_arrow_type_token6] = "arrow_type_token6",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_LT_EQ] = "<=",
  [aux_sym_arrow_label_token1] = "arrow_label_token1",
  [sym_detach] = "detach",
  [sym_kill] = "kill",
  [anon_sym_PIPE] = "|",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_endif] = "endif",
  [anon_sym_elseif] = "elseif",
  [anon_sym_else] = "else",
  [anon_sym_LPAREN] = "(",
  [aux_sym_branch_label_token1] = "branch_label_token1",
  [anon_sym_RPAREN] = ")",
  [anon_sym_while] = "while",
  [anon_sym_is] = "is",
  [anon_sym_endwhile] = "endwhile",
  [anon_sym_repeat] = "repeat",
  [aux_sym_fork_node_token1] = "fork_node_token1",
  [aux_sym_fork_node_token2] = "fork_node_token2",
  [anon_sym_fork] = "fork",
  [anon_sym_split] = "split",
  [anon_sym_end] = "end",
  [anon_sym_title] = "title",
  [aux_sym_title_directive_token1] = "title_directive_token1",
  [anon_sym_skinparam] = "skinparam",
  [anon_sym_BANGpragma] = "!pragma",
  [anon_sym_BANGinclude] = "!include",
  [anon_sym_partition] = "partition",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_POUND] = "#",
  [anon_sym_note] = "note",
  [anon_sym_left] = "left",
  [anon_sym_right] = "right",
  [anon_sym_top] = "top",
  [anon_sym_bottom] = "bottom",
  [anon_sym_over] = "over",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token2] = "string_token2",
  [aux_sym_line_comment_token1] = "line_comment_token1",
  [anon_sym_SLASH_SQUOTE] = "/'",
  [aux_sym_block_comment_token1] = "block_comment_token1",
  [anon_sym_SQUOTE_SLASH] = "'/",
  [sym__whitespace] = "_whitespace",
  [sym_start_marker] = "start_marker",
  [sym_stop_marker] = "stop_marker",
  [sym_label_marker] = "label_marker",
  [sym_content_start] = "content_start",
  [sym_content_end] = "content_end",
  [sym_arrow_label_marker] = "arrow_label_marker",
  [sym_activity_marker] = "activity_marker",
  [sym_condition_marker] = "condition_marker",
  [sym_loop_label_marker] = "loop_label_marker",
  [sym_note_content_line] = "note_content_line",
  [sym_error_sentinel] = "error_sentinel",
  [sym_source_file] = "source_file",
  [sym__element] = "_element",
  [sym_diagram] = "diagram",
  [sym__statement] = "_statement",
  [sym_activity_element] = "activity_element",
  [sym_start_node] = "start_node",
  [sym_stop_node] = "stop_node",
  [sym_activity_node] = "activity_node",
  [sym_activity_label] = "activity_label",
  [sym_flow_arrow] = "flow_arrow",
  [sym__flow_source] = "_flow_source",
  [sym__flow_target] = "_flow_target",
  [sym_arrow] = "arrow",
  [sym_arrow_style] = "arrow_style",
  [sym_arrow_type] = "arrow_type",
  [sym_arrow_label] = "arrow_label",
  [sym_swimlane] = "swimlane",
  [sym_decision_node] = "decision_node",
  [sym_elseif_branch] = "elseif_branch",
  [sym_else_branch] = "else_branch",
  [sym_branch_label] = "branch_label",
  [sym_condition_expression] = "condition_expression",
  [sym_while_loop] = "while_loop",
  [sym_repeat_loop] = "repeat_loop",
  [sym_fork_node] = "fork_node",
  [sym_join_node] = "join_node",
  [sym_title_directive] = "title_directive",
  [sym_skinparam_directive] = "skinparam_directive",
  [sym_pragma_directive] = "pragma_directive",
  [sym_include_directive] = "include_directive",
  [sym_directive_value] = "directive_value",
  [sym_partition] = "partition",
  [sym_color_spec] = "color_spec",
  [sym_note_directive] = "note_directive",
  [sym_note_line] = "note_line",
  [sym_floating_note] = "floating_note",
  [sym_string] = "string",
  [sym_comment] = "comment",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_diagram_repeat1] = "diagram_repeat1",
  [aux_sym_decision_node_repeat1] = "decision_node_repeat1",
  [aux_sym_floating_note_repeat1] = "floating_note_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_startuml_directive] = sym_startuml_directive,
  [sym_enduml_directive] = sym_enduml_directive,
  [anon_sym_start] = anon_sym_start,
  [anon_sym_LPAREN_STAR_RPAREN] = anon_sym_LPAREN_STAR_RPAREN,
  [anon_sym_stop] = anon_sym_stop,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_text_line] = sym_text_line,
  [anon_sym_DASH_LBRACK] = anon_sym_DASH_LBRACK,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym_arrow_type_token1] = aux_sym_arrow_type_token1,
  [aux_sym_arrow_type_token2] = aux_sym_arrow_type_token2,
  [aux_sym_arrow_type_token3] = aux_sym_arrow_type_token3,
  [aux_sym_arrow_type_token4] = aux_sym_arrow_type_token4,
  [aux_sym_arrow_type_token5] = aux_sym_arrow_type_token5,
  [aux_sym_arrow_type_token6] = aux_sym_arrow_type_token6,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [aux_sym_arrow_label_token1] = aux_sym_arrow_label_token1,
  [sym_detach] = sym_detach,
  [sym_kill] = sym_kill,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_endif] = anon_sym_endif,
  [anon_sym_elseif] = anon_sym_elseif,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [aux_sym_branch_label_token1] = aux_sym_branch_label_token1,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_is] = anon_sym_is,
  [anon_sym_endwhile] = anon_sym_endwhile,
  [anon_sym_repeat] = anon_sym_repeat,
  [aux_sym_fork_node_token1] = aux_sym_fork_node_token1,
  [aux_sym_fork_node_token2] = aux_sym_fork_node_token2,
  [anon_sym_fork] = anon_sym_fork,
  [anon_sym_split] = anon_sym_split,
  [anon_sym_end] = anon_sym_end,
  [anon_sym_title] = anon_sym_title,
  [aux_sym_title_directive_token1] = aux_sym_title_directive_token1,
  [anon_sym_skinparam] = anon_sym_skinparam,
  [anon_sym_BANGpragma] = anon_sym_BANGpragma,
  [anon_sym_BANGinclude] = anon_sym_BANGinclude,
  [anon_sym_partition] = anon_sym_partition,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_note] = anon_sym_note,
  [anon_sym_left] = anon_sym_left,
  [anon_sym_right] = anon_sym_right,
  [anon_sym_top] = anon_sym_top,
  [anon_sym_bottom] = anon_sym_bottom,
  [anon_sym_over] = anon_sym_over,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [aux_sym_line_comment_token1] = aux_sym_line_comment_token1,
  [anon_sym_SLASH_SQUOTE] = anon_sym_SLASH_SQUOTE,
  [aux_sym_block_comment_token1] = aux_sym_block_comment_token1,
  [anon_sym_SQUOTE_SLASH] = anon_sym_SQUOTE_SLASH,
  [sym__whitespace] = sym__whitespace,
  [sym_start_marker] = sym_start_marker,
  [sym_stop_marker] = sym_stop_marker,
  [sym_label_marker] = sym_label_marker,
  [sym_content_start] = sym_content_start,
  [sym_content_end] = sym_content_end,
  [sym_arrow_label_marker] = sym_arrow_label_marker,
  [sym_activity_marker] = sym_activity_marker,
  [sym_condition_marker] = sym_condition_marker,
  [sym_loop_label_marker] = sym_loop_label_marker,
  [sym_note_content_line] = sym_note_content_line,
  [sym_error_sentinel] = sym_error_sentinel,
  [sym_source_file] = sym_source_file,
  [sym__element] = sym__element,
  [sym_diagram] = sym_diagram,
  [sym__statement] = sym__statement,
  [sym_activity_element] = sym_activity_element,
  [sym_start_node] = sym_start_node,
  [sym_stop_node] = sym_stop_node,
  [sym_activity_node] = sym_activity_node,
  [sym_activity_label] = sym_activity_label,
  [sym_flow_arrow] = sym_flow_arrow,
  [sym__flow_source] = sym__flow_source,
  [sym__flow_target] = sym__flow_target,
  [sym_arrow] = sym_arrow,
  [sym_arrow_style] = sym_arrow_style,
  [sym_arrow_type] = sym_arrow_type,
  [sym_arrow_label] = sym_arrow_label,
  [sym_swimlane] = sym_swimlane,
  [sym_decision_node] = sym_decision_node,
  [sym_elseif_branch] = sym_elseif_branch,
  [sym_else_branch] = sym_else_branch,
  [sym_branch_label] = sym_branch_label,
  [sym_condition_expression] = sym_condition_expression,
  [sym_while_loop] = sym_while_loop,
  [sym_repeat_loop] = sym_repeat_loop,
  [sym_fork_node] = sym_fork_node,
  [sym_join_node] = sym_join_node,
  [sym_title_directive] = sym_title_directive,
  [sym_skinparam_directive] = sym_skinparam_directive,
  [sym_pragma_directive] = sym_pragma_directive,
  [sym_include_directive] = sym_include_directive,
  [sym_directive_value] = sym_directive_value,
  [sym_partition] = sym_partition,
  [sym_color_spec] = sym_color_spec,
  [sym_note_directive] = sym_note_directive,
  [sym_note_line] = sym_note_line,
  [sym_floating_note] = sym_floating_note,
  [sym_string] = sym_string,
  [sym_comment] = sym_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_diagram_repeat1] = aux_sym_diagram_repeat1,
  [aux_sym_decision_node_repeat1] = aux_sym_decision_node_repeat1,
  [aux_sym_floating_note_repeat1] = aux_sym_floating_note_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_startuml_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_enduml_directive] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_start] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_STAR_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_stop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [sym_text_line] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_arrow_type_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arrow_type_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arrow_type_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arrow_type_token4] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arrow_type_token5] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arrow_type_token6] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_arrow_label_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_detach] = {
    .visible = true,
    .named = true,
  },
  [sym_kill] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_elseif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_branch_label_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_is] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endwhile] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_repeat] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_fork_node_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fork_node_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_fork] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_split] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_title] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_title_directive_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_skinparam] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANGpragma] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANGinclude] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_partition] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_note] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_left] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_right] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_top] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bottom] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_over] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_line_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_block_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym_start_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_stop_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_label_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_content_start] = {
    .visible = true,
    .named = true,
  },
  [sym_content_end] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_label_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_activity_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_loop_label_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_note_content_line] = {
    .visible = true,
    .named = true,
  },
  [sym_error_sentinel] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__element] = {
    .visible = false,
    .named = true,
  },
  [sym_diagram] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_activity_element] = {
    .visible = true,
    .named = true,
  },
  [sym_start_node] = {
    .visible = true,
    .named = true,
  },
  [sym_stop_node] = {
    .visible = true,
    .named = true,
  },
  [sym_activity_node] = {
    .visible = true,
    .named = true,
  },
  [sym_activity_label] = {
    .visible = true,
    .named = true,
  },
  [sym_flow_arrow] = {
    .visible = true,
    .named = true,
  },
  [sym__flow_source] = {
    .visible = false,
    .named = true,
  },
  [sym__flow_target] = {
    .visible = false,
    .named = true,
  },
  [sym_arrow] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_style] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_type] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_label] = {
    .visible = true,
    .named = true,
  },
  [sym_swimlane] = {
    .visible = true,
    .named = true,
  },
  [sym_decision_node] = {
    .visible = true,
    .named = true,
  },
  [sym_elseif_branch] = {
    .visible = true,
    .named = true,
  },
  [sym_else_branch] = {
    .visible = true,
    .named = true,
  },
  [sym_branch_label] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_while_loop] = {
    .visible = true,
    .named = true,
  },
  [sym_repeat_loop] = {
    .visible = true,
    .named = true,
  },
  [sym_fork_node] = {
    .visible = true,
    .named = true,
  },
  [sym_join_node] = {
    .visible = true,
    .named = true,
  },
  [sym_title_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_skinparam_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_pragma_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_include_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_directive_value] = {
    .visible = true,
    .named = true,
  },
  [sym_partition] = {
    .visible = true,
    .named = true,
  },
  [sym_color_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_note_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_note_line] = {
    .visible = true,
    .named = true,
  },
  [sym_floating_note] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_diagram_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_decision_node_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_floating_note_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_color = 1,
  field_condition = 2,
  field_content = 3,
  field_end_label = 4,
  field_label = 5,
  field_marker = 6,
  field_name = 7,
  field_parameter = 8,
  field_path = 9,
  field_position = 10,
  field_source = 11,
  field_style = 12,
  field_target = 13,
  field_text = 14,
  field_true_label = 15,
  field_type = 16,
  field_value = 17,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_color] = "color",
  [field_condition] = "condition",
  [field_content] = "content",
  [field_end_label] = "end_label",
  [field_label] = "label",
  [field_marker] = "marker",
  [field_name] = "name",
  [field_parameter] = "parameter",
  [field_path] = "path",
  [field_position] = "position",
  [field_source] = "source",
  [field_style] = "style",
  [field_target] = "target",
  [field_text] = "text",
  [field_true_label] = "true_label",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 2},
  [9] = {.index = 9, .length = 1},
  [10] = {.index = 10, .length = 2},
  [11] = {.index = 12, .length = 1},
  [12] = {.index = 13, .length = 1},
  [13] = {.index = 14, .length = 2},
  [14] = {.index = 16, .length = 2},
  [15] = {.index = 18, .length = 1},
  [16] = {.index = 19, .length = 2},
  [17] = {.index = 21, .length = 3},
  [18] = {.index = 24, .length = 1},
  [19] = {.index = 25, .length = 2},
  [20] = {.index = 27, .length = 2},
  [21] = {.index = 29, .length = 1},
  [22] = {.index = 30, .length = 2},
  [23] = {.index = 32, .length = 2},
  [24] = {.index = 34, .length = 2},
  [25] = {.index = 36, .length = 1},
  [26] = {.index = 37, .length = 3},
  [27] = {.index = 40, .length = 3},
  [28] = {.index = 43, .length = 2},
  [29] = {.index = 45, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 0},
  [1] =
    {field_marker, 0},
  [2] =
    {field_content, 1},
  [3] =
    {field_name, 1},
  [4] =
    {field_path, 1},
  [5] =
    {field_source, 0},
  [6] =
    {field_target, 1},
  [7] =
    {field_style, 0},
    {field_type, 1},
  [9] =
    {field_text, 0},
  [10] =
    {field_label, 1},
    {field_type, 0},
  [12] =
    {field_label, 1},
  [13] =
    {field_condition, 1},
  [14] =
    {field_parameter, 1},
    {field_value, 2},
  [16] =
    {field_name, 1},
    {field_value, 2},
  [18] =
    {field_color, 1},
  [19] =
    {field_source, 0},
    {field_target, 2},
  [21] =
    {field_label, 2},
    {field_style, 0},
    {field_type, 1},
  [24] =
    {field_text, 1},
  [25] =
    {field_condition, 1},
    {field_end_label, 3},
  [27] =
    {field_content, 3},
    {field_position, 1},
  [29] =
    {field_text, 2},
  [30] =
    {field_condition, 1},
    {field_true_label, 3},
  [32] =
    {field_condition, 1},
    {field_label, 3},
  [34] =
    {field_condition, 1},
    {field_end_label, 4},
  [36] =
    {field_condition, 4},
  [37] =
    {field_condition, 1},
    {field_end_label, 5},
    {field_label, 3},
  [40] =
    {field_condition, 1},
    {field_end_label, 6},
    {field_label, 3},
  [43] =
    {field_condition, 4},
    {field_label, 6},
  [45] =
    {field_position, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [1] = sym_text_line,
  },
  [20] = {
    [3] = sym_text_line,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 3,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 12,
  [20] = 12,
  [21] = 21,
  [22] = 22,
  [23] = 12,
  [24] = 24,
  [25] = 25,
  [26] = 5,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 12,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 39,
  [41] = 38,
  [42] = 12,
  [43] = 37,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 60,
  [108] = 57,
  [109] = 60,
  [110] = 57,
  [111] = 111,
  [112] = 57,
  [113] = 57,
  [114] = 60,
  [115] = 60,
  [116] = 60,
  [117] = 57,
  [118] = 102,
  [119] = 102,
  [120] = 102,
  [121] = 102,
  [122] = 111,
  [123] = 111,
  [124] = 111,
  [125] = 102,
  [126] = 111,
  [127] = 111,
  [128] = 128,
  [129] = 128,
  [130] = 128,
  [131] = 128,
  [132] = 128,
  [133] = 128,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 136,
  [138] = 136,
  [139] = 136,
  [140] = 136,
  [141] = 136,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 67,
  [151] = 99,
  [152] = 94,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 160,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 97,
  [167] = 167,
  [168] = 163,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 56,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 58,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 177,
  [212] = 187,
  [213] = 181,
  [214] = 180,
  [215] = 182,
  [216] = 184,
  [217] = 198,
  [218] = 218,
  [219] = 219,
  [220] = 187,
  [221] = 187,
  [222] = 187,
  [223] = 187,
  [224] = 224,
  [225] = 202,
  [226] = 201,
  [227] = 172,
  [228] = 178,
  [229] = 229,
  [230] = 173,
  [231] = 231,
  [232] = 224,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(59);
      if (lookahead == '!') ADVANCE(35);
      if (lookahead == '"') ADVANCE(225);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '\'') ADVANCE(228);
      if (lookahead == '(') ADVANCE(147);
      if (lookahead == ')') ADVANCE(150);
      if (lookahead == '-') ADVANCE(15);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == ':') ADVANCE(66);
      if (lookahead == ';') ADVANCE(69);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(18);
      if (lookahead == '@') ADVANCE(31);
      if (lookahead == '[') ADVANCE(75);
      if (lookahead == 'f') ADVANCE(218);
      if (lookahead == 's') ADVANCE(219);
      if (lookahead == '{') ADVANCE(210);
      if (lookahead == '|') ADVANCE(144);
      if (lookahead == '}') ADVANCE(211);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == ';') ADVANCE(69);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(242);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == ';') ADVANCE(69);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '}') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(243);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(244);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == ';') ADVANCE(69);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '@') ADVANCE(119);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(245);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '}') ADVANCE(213);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(246);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '@') ADVANCE(176);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(159);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(225);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '\'') ADVANCE(228);
      if (lookahead == '(') ADVANCE(13);
      if (lookahead == '{') ADVANCE(210);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 10:
      if (lookahead == '\'') ADVANCE(235);
      END_STATE();
    case 11:
      if (lookahead == '\'') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      END_STATE();
    case 12:
      if (lookahead == ')') ADVANCE(65);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(81);
      if (lookahead == '.') ADVANCE(90);
      if (lookahead == '=') ADVANCE(96);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '[') ADVANCE(72);
      END_STATE();
    case 16:
      if (lookahead == '/') ADVANCE(240);
      END_STATE();
    case 17:
      if (lookahead == '>') ADVANCE(87);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(93);
      END_STATE();
    case 19:
      if (lookahead == '>') ADVANCE(84);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(204);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(40);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(53);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(30);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(207);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(45);
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 32:
      if (lookahead == 'g') ADVANCE(42);
      END_STATE();
    case 33:
      if (lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 34:
      if (lookahead == 'g') ADVANCE(25);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 37:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 38:
      if (lookahead == 'l') ADVANCE(62);
      END_STATE();
    case 39:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 40:
      if (lookahead == 'l') ADVANCE(52);
      END_STATE();
    case 41:
      if (lookahead == 'm') ADVANCE(38);
      END_STATE();
    case 42:
      if (lookahead == 'm') ADVANCE(21);
      END_STATE();
    case 43:
      if (lookahead == 'm') ADVANCE(39);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 45:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(151);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(153);
      END_STATE();
    case 48:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 49:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 52:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 53:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 54:
      if (lookahead == 'u') ADVANCE(43);
      END_STATE();
    case 55:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(61);
      END_STATE();
    case 56:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(71);
      END_STATE();
    case 57:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(149);
      END_STATE();
    case 58:
      if (eof) ADVANCE(59);
      if (lookahead == '!') ADVANCE(35);
      if (lookahead == '\'') ADVANCE(228);
      if (lookahead == '(') ADVANCE(147);
      if (lookahead == '-') ADVANCE(15);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == ':') ADVANCE(66);
      if (lookahead == ';') ADVANCE(69);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(18);
      if (lookahead == '@') ADVANCE(31);
      if (lookahead == '[') ADVANCE(75);
      if (lookahead == 'f') ADVANCE(218);
      if (lookahead == 's') ADVANCE(219);
      if (lookahead == '|') ADVANCE(144);
      if (lookahead == '}') ADVANCE(211);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(247);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_startuml_directive);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_startuml_directive);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_enduml_directive);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_enduml_directive);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_enduml_directive);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_LPAREN_STAR_RPAREN);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(71);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_DASH_LBRACK);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_DASH_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_DASH_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_arrow_type_token1);
      if (lookahead == '>') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_arrow_type_token1);
      if (lookahead == '>') ADVANCE(79);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_arrow_type_token1);
      if (lookahead == '>') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_arrow_type_token2);
      if (lookahead == '-') ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_arrow_type_token2);
      if (lookahead == '-') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_arrow_type_token2);
      if (lookahead == '-') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_arrow_type_token3);
      if (lookahead == '>') ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_arrow_type_token3);
      if (lookahead == '>') ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_arrow_type_token3);
      if (lookahead == '>') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_arrow_type_token5);
      if (lookahead == '>') ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_arrow_type_token5);
      if (lookahead == '>') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_arrow_type_token5);
      if (lookahead == '>') ADVANCE(89);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_arrow_type_token6);
      if (lookahead == '.') ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_arrow_type_token6);
      if (lookahead == '.') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_arrow_type_token6);
      if (lookahead == '.') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(24);
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(242);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '}') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(244);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '\'') ADVANCE(229);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(109);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == '<') ADVANCE(107);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '@') ADVANCE(119);
      if (lookahead == '[') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(134);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead == '|') ADVANCE(145);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(26);
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\n') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\'') ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '-') ADVANCE(82);
      if (lookahead == '.') ADVANCE(91);
      if (lookahead == '=') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == '>') ADVANCE(79);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '>') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '>') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '>') ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'a') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'a') ADVANCE(124);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'c') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'd') ADVANCE(118);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'd') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'e') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'e') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'g') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'g') ADVANCE(114);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'i') ADVANCE(132);
      if (lookahead == 'p') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'i') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'i') ADVANCE(131);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'k') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'l') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'l') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'l') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'm') ADVANCE(113);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'm') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'n') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'n') ADVANCE(115);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'n') ADVANCE(117);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'o') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'p') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'r') ADVANCE(112);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'r') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 't') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'u') ADVANCE(116);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == 'u') ADVANCE(130);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_arrow_label_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_branch_label_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(149);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_branch_label_token1);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_fork_node_token1);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_fork_node_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_fork_node_token2);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_fork_node_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(24);
      if (lookahead == 'a') ADVANCE(178);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(243);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(245);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '}') ADVANCE(213);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(246);
      if (lookahead == '!') ADVANCE(180);
      if (lookahead == '\'') ADVANCE(230);
      if (lookahead == '-') ADVANCE(164);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == ':') ADVANCE(68);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '=') ADVANCE(166);
      if (lookahead == '@') ADVANCE(176);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead == '|') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(159);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(26);
      if (lookahead == 'a') ADVANCE(179);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(160);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\n') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0) ADVANCE(203);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\'') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '-') ADVANCE(83);
      if (lookahead == '.') ADVANCE(92);
      if (lookahead == '=') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '-') ADVANCE(167);
      if (lookahead == '>') ADVANCE(80);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '>') ADVANCE(89);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '>') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '>') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'a') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'a') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'a') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'a') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'c') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'd') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'd') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'e') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'e') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'g') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'g') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'g') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'i') ADVANCE(190);
      if (lookahead == 'p') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'i') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'i') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'i') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'k') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'l') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'l') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'l') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'm') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'm') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'n') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'n') ADVANCE(152);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'n') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'n') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'o') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'p') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'r') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'r') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 't') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'u') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == 'u') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_title_directive_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_BANGpragma);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_BANGpragma);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_BANGpragma);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_BANGinclude);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_BANGinclude);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_BANGinclude);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(227);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(227);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(231);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(232);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(232);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_line_comment_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(234);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_SLASH_SQUOTE);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_SLASH_SQUOTE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(143);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_SLASH_SQUOTE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(203);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(238);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(239);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(239);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_SQUOTE_SLASH);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(101);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(242);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(243);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(157);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(244);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(245);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(158);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\n') ADVANCE(246);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(159);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(247);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'd') ADVANCE(2);
      if (lookahead == 'e') ADVANCE(3);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'k') ADVANCE(6);
      if (lookahead == 'l') ADVANCE(7);
      if (lookahead == 'n') ADVANCE(8);
      if (lookahead == 'o') ADVANCE(9);
      if (lookahead == 'p') ADVANCE(10);
      if (lookahead == 'r') ADVANCE(11);
      if (lookahead == 's') ADVANCE(12);
      if (lookahead == 't') ADVANCE(13);
      if (lookahead == 'w') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == 'l') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 4:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 5:
      if (lookahead == 'f') ADVANCE(20);
      if (lookahead == 's') ADVANCE(21);
      END_STATE();
    case 6:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 9:
      if (lookahead == 'v') ADVANCE(25);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(26);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(27);
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'k') ADVANCE(29);
      if (lookahead == 'p') ADVANCE(30);
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 13:
      if (lookahead == 'h') ADVANCE(32);
      if (lookahead == 'i') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 'h') ADVANCE(35);
      END_STATE();
    case 15:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 17:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(39);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 23:
      if (lookahead == 'f') ADVANCE(42);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == 'p') ADVANCE(46);
      END_STATE();
    case 28:
      if (lookahead == 'g') ADVANCE(47);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(49);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 33:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 34:
      if (lookahead == 'p') ADVANCE(54);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(55);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_end);
      if (lookahead == 'i') ADVANCE(59);
      if (lookahead == 'w') ADVANCE(60);
      END_STATE();
    case 40:
      if (lookahead == 'k') ADVANCE(61);
      END_STATE();
    case 41:
      if (lookahead == 'l') ADVANCE(62);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(66);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 47:
      if (lookahead == 'h') ADVANCE(68);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(69);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(71);
      END_STATE();
    case 51:
      if (lookahead == 'p') ADVANCE(72);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(73);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_top);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(75);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 57:
      if (lookahead == 'c') ADVANCE(77);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead == 'i') ADVANCE(78);
      END_STATE();
    case 59:
      if (lookahead == 'f') ADVANCE(79);
      END_STATE();
    case 60:
      if (lookahead == 'h') ADVANCE(80);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_fork);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_kill);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_left);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_note);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(81);
      END_STATE();
    case 67:
      if (lookahead == 'a') ADVANCE(82);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 69:
      if (lookahead == 'p') ADVANCE(84);
      END_STATE();
    case 70:
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 71:
      if (lookahead == 't') ADVANCE(86);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_stop);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 76:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 77:
      if (lookahead == 'h') ADVANCE(90);
      END_STATE();
    case 78:
      if (lookahead == 'f') ADVANCE(91);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_endif);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(92);
      END_STATE();
    case 81:
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 82:
      if (lookahead == 't') ADVANCE(94);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_right);
      END_STATE();
    case 84:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_split);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_start);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_bottom);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_detach);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_elseif);
      END_STATE();
    case 92:
      if (lookahead == 'l') ADVANCE(96);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(97);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_repeat);
      END_STATE();
    case 95:
      if (lookahead == 'r') ADVANCE(98);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 97:
      if (lookahead == 'o') ADVANCE(100);
      END_STATE();
    case 98:
      if (lookahead == 'a') ADVANCE(101);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_endwhile);
      END_STATE();
    case 100:
      if (lookahead == 'n') ADVANCE(102);
      END_STATE();
    case 101:
      if (lookahead == 'm') ADVANCE(103);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_partition);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_skinparam);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 58},
  [2] = {.lex_state = 58, .external_lex_state = 2},
  [3] = {.lex_state = 58, .external_lex_state = 2},
  [4] = {.lex_state = 58, .external_lex_state = 2},
  [5] = {.lex_state = 58, .external_lex_state = 2},
  [6] = {.lex_state = 58, .external_lex_state = 2},
  [7] = {.lex_state = 58, .external_lex_state = 2},
  [8] = {.lex_state = 58, .external_lex_state = 2},
  [9] = {.lex_state = 58, .external_lex_state = 2},
  [10] = {.lex_state = 58, .external_lex_state = 2},
  [11] = {.lex_state = 58, .external_lex_state = 2},
  [12] = {.lex_state = 58, .external_lex_state = 2},
  [13] = {.lex_state = 58, .external_lex_state = 2},
  [14] = {.lex_state = 58, .external_lex_state = 2},
  [15] = {.lex_state = 58, .external_lex_state = 2},
  [16] = {.lex_state = 58, .external_lex_state = 2},
  [17] = {.lex_state = 58, .external_lex_state = 2},
  [18] = {.lex_state = 58, .external_lex_state = 2},
  [19] = {.lex_state = 58, .external_lex_state = 2},
  [20] = {.lex_state = 58, .external_lex_state = 2},
  [21] = {.lex_state = 58, .external_lex_state = 2},
  [22] = {.lex_state = 58, .external_lex_state = 2},
  [23] = {.lex_state = 58, .external_lex_state = 2},
  [24] = {.lex_state = 58, .external_lex_state = 2},
  [25] = {.lex_state = 58, .external_lex_state = 2},
  [26] = {.lex_state = 58, .external_lex_state = 2},
  [27] = {.lex_state = 58, .external_lex_state = 2},
  [28] = {.lex_state = 58, .external_lex_state = 2},
  [29] = {.lex_state = 58, .external_lex_state = 2},
  [30] = {.lex_state = 58, .external_lex_state = 2},
  [31] = {.lex_state = 58, .external_lex_state = 2},
  [32] = {.lex_state = 58, .external_lex_state = 2},
  [33] = {.lex_state = 58, .external_lex_state = 2},
  [34] = {.lex_state = 58, .external_lex_state = 2},
  [35] = {.lex_state = 58, .external_lex_state = 2},
  [36] = {.lex_state = 58, .external_lex_state = 2},
  [37] = {.lex_state = 58, .external_lex_state = 2},
  [38] = {.lex_state = 58, .external_lex_state = 2},
  [39] = {.lex_state = 58, .external_lex_state = 2},
  [40] = {.lex_state = 58, .external_lex_state = 2},
  [41] = {.lex_state = 58, .external_lex_state = 2},
  [42] = {.lex_state = 58, .external_lex_state = 2},
  [43] = {.lex_state = 58, .external_lex_state = 2},
  [44] = {.lex_state = 58, .external_lex_state = 2},
  [45] = {.lex_state = 58, .external_lex_state = 2},
  [46] = {.lex_state = 58, .external_lex_state = 2},
  [47] = {.lex_state = 58, .external_lex_state = 2},
  [48] = {.lex_state = 58, .external_lex_state = 2},
  [49] = {.lex_state = 58, .external_lex_state = 2},
  [50] = {.lex_state = 58, .external_lex_state = 2},
  [51] = {.lex_state = 58, .external_lex_state = 2},
  [52] = {.lex_state = 58, .external_lex_state = 2},
  [53] = {.lex_state = 58, .external_lex_state = 2},
  [54] = {.lex_state = 58, .external_lex_state = 2},
  [55] = {.lex_state = 58, .external_lex_state = 2},
  [56] = {.lex_state = 58, .external_lex_state = 2},
  [57] = {.lex_state = 1, .external_lex_state = 3},
  [58] = {.lex_state = 58, .external_lex_state = 2},
  [59] = {.lex_state = 58, .external_lex_state = 2},
  [60] = {.lex_state = 1, .external_lex_state = 3},
  [61] = {.lex_state = 58, .external_lex_state = 2},
  [62] = {.lex_state = 58, .external_lex_state = 2},
  [63] = {.lex_state = 58, .external_lex_state = 2},
  [64] = {.lex_state = 58, .external_lex_state = 2},
  [65] = {.lex_state = 58, .external_lex_state = 2},
  [66] = {.lex_state = 58, .external_lex_state = 2},
  [67] = {.lex_state = 58, .external_lex_state = 2},
  [68] = {.lex_state = 58, .external_lex_state = 2},
  [69] = {.lex_state = 58, .external_lex_state = 2},
  [70] = {.lex_state = 58, .external_lex_state = 2},
  [71] = {.lex_state = 58, .external_lex_state = 2},
  [72] = {.lex_state = 58, .external_lex_state = 2},
  [73] = {.lex_state = 58, .external_lex_state = 2},
  [74] = {.lex_state = 58, .external_lex_state = 2},
  [75] = {.lex_state = 58, .external_lex_state = 2},
  [76] = {.lex_state = 58, .external_lex_state = 2},
  [77] = {.lex_state = 58, .external_lex_state = 2},
  [78] = {.lex_state = 58, .external_lex_state = 2},
  [79] = {.lex_state = 58, .external_lex_state = 2},
  [80] = {.lex_state = 58, .external_lex_state = 2},
  [81] = {.lex_state = 58, .external_lex_state = 2},
  [82] = {.lex_state = 58, .external_lex_state = 2},
  [83] = {.lex_state = 58, .external_lex_state = 2},
  [84] = {.lex_state = 58, .external_lex_state = 2},
  [85] = {.lex_state = 58, .external_lex_state = 2},
  [86] = {.lex_state = 58, .external_lex_state = 2},
  [87] = {.lex_state = 58, .external_lex_state = 2},
  [88] = {.lex_state = 58, .external_lex_state = 2},
  [89] = {.lex_state = 58, .external_lex_state = 2},
  [90] = {.lex_state = 58, .external_lex_state = 2},
  [91] = {.lex_state = 58, .external_lex_state = 2},
  [92] = {.lex_state = 58, .external_lex_state = 2},
  [93] = {.lex_state = 58, .external_lex_state = 2},
  [94] = {.lex_state = 58, .external_lex_state = 2},
  [95] = {.lex_state = 58, .external_lex_state = 2},
  [96] = {.lex_state = 58, .external_lex_state = 2},
  [97] = {.lex_state = 58, .external_lex_state = 2},
  [98] = {.lex_state = 58, .external_lex_state = 2},
  [99] = {.lex_state = 58, .external_lex_state = 2},
  [100] = {.lex_state = 58, .external_lex_state = 2},
  [101] = {.lex_state = 58, .external_lex_state = 2},
  [102] = {.lex_state = 1, .external_lex_state = 3},
  [103] = {.lex_state = 58, .external_lex_state = 2},
  [104] = {.lex_state = 58, .external_lex_state = 2},
  [105] = {.lex_state = 58, .external_lex_state = 2},
  [106] = {.lex_state = 58, .external_lex_state = 2},
  [107] = {.lex_state = 4, .external_lex_state = 3},
  [108] = {.lex_state = 4, .external_lex_state = 3},
  [109] = {.lex_state = 1, .external_lex_state = 3},
  [110] = {.lex_state = 1, .external_lex_state = 3},
  [111] = {.lex_state = 5, .external_lex_state = 2},
  [112] = {.lex_state = 1, .external_lex_state = 3},
  [113] = {.lex_state = 6, .external_lex_state = 3},
  [114] = {.lex_state = 1, .external_lex_state = 3},
  [115] = {.lex_state = 6, .external_lex_state = 3},
  [116] = {.lex_state = 1, .external_lex_state = 3},
  [117] = {.lex_state = 1, .external_lex_state = 3},
  [118] = {.lex_state = 1, .external_lex_state = 3},
  [119] = {.lex_state = 1, .external_lex_state = 3},
  [120] = {.lex_state = 6, .external_lex_state = 3},
  [121] = {.lex_state = 4, .external_lex_state = 3},
  [122] = {.lex_state = 7, .external_lex_state = 2},
  [123] = {.lex_state = 5, .external_lex_state = 2},
  [124] = {.lex_state = 8, .external_lex_state = 2},
  [125] = {.lex_state = 1, .external_lex_state = 3},
  [126] = {.lex_state = 5, .external_lex_state = 2},
  [127] = {.lex_state = 5, .external_lex_state = 2},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 58},
  [135] = {.lex_state = 58},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 9},
  [144] = {.lex_state = 9},
  [145] = {.lex_state = 9},
  [146] = {.lex_state = 9},
  [147] = {.lex_state = 9},
  [148] = {.lex_state = 58},
  [149] = {.lex_state = 58},
  [150] = {.lex_state = 58},
  [151] = {.lex_state = 58},
  [152] = {.lex_state = 58},
  [153] = {.lex_state = 9},
  [154] = {.lex_state = 0, .external_lex_state = 4},
  [155] = {.lex_state = 0, .external_lex_state = 5},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0, .external_lex_state = 4},
  [159] = {.lex_state = 0, .external_lex_state = 4},
  [160] = {.lex_state = 0, .external_lex_state = 4},
  [161] = {.lex_state = 0, .external_lex_state = 5},
  [162] = {.lex_state = 0, .external_lex_state = 4},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 56},
  [165] = {.lex_state = 9},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0, .external_lex_state = 6},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0, .external_lex_state = 7},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 231},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 233},
  [178] = {.lex_state = 57},
  [179] = {.lex_state = 9},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 11},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 9},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 9},
  [188] = {.lex_state = 9},
  [189] = {.lex_state = 2},
  [190] = {.lex_state = 9},
  [191] = {.lex_state = 3},
  [192] = {.lex_state = 9},
  [193] = {.lex_state = 9},
  [194] = {.lex_state = 3},
  [195] = {.lex_state = 9},
  [196] = {.lex_state = 9},
  [197] = {.lex_state = 9},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 9},
  [201] = {.lex_state = 226},
  [202] = {.lex_state = 57},
  [203] = {.lex_state = 9},
  [204] = {.lex_state = 9},
  [205] = {.lex_state = 9},
  [206] = {.lex_state = 57},
  [207] = {.lex_state = 9},
  [208] = {.lex_state = 9},
  [209] = {.lex_state = 9},
  [210] = {.lex_state = 9},
  [211] = {.lex_state = 233},
  [212] = {.lex_state = 9},
  [213] = {.lex_state = 11},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 9},
  [220] = {.lex_state = 9},
  [221] = {.lex_state = 9},
  [222] = {.lex_state = 9},
  [223] = {.lex_state = 9},
  [224] = {.lex_state = 238},
  [225] = {.lex_state = 57},
  [226] = {.lex_state = 226},
  [227] = {.lex_state = 231},
  [228] = {.lex_state = 57},
  [229] = {.lex_state = 9},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 238},
};

enum {
  ts_external_token_start_marker = 0,
  ts_external_token_stop_marker = 1,
  ts_external_token_label_marker = 2,
  ts_external_token_content_start = 3,
  ts_external_token_content_end = 4,
  ts_external_token_arrow_label_marker = 5,
  ts_external_token_activity_marker = 6,
  ts_external_token_condition_marker = 7,
  ts_external_token_loop_label_marker = 8,
  ts_external_token_note_content_line = 9,
  ts_external_token_error_sentinel = 10,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_start_marker] = sym_start_marker,
  [ts_external_token_stop_marker] = sym_stop_marker,
  [ts_external_token_label_marker] = sym_label_marker,
  [ts_external_token_content_start] = sym_content_start,
  [ts_external_token_content_end] = sym_content_end,
  [ts_external_token_arrow_label_marker] = sym_arrow_label_marker,
  [ts_external_token_activity_marker] = sym_activity_marker,
  [ts_external_token_condition_marker] = sym_condition_marker,
  [ts_external_token_loop_label_marker] = sym_loop_label_marker,
  [ts_external_token_note_content_line] = sym_note_content_line,
  [ts_external_token_error_sentinel] = sym_error_sentinel,
};

static const bool ts_external_scanner_states[8][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_start_marker] = true,
    [ts_external_token_stop_marker] = true,
    [ts_external_token_label_marker] = true,
    [ts_external_token_content_start] = true,
    [ts_external_token_content_end] = true,
    [ts_external_token_arrow_label_marker] = true,
    [ts_external_token_activity_marker] = true,
    [ts_external_token_condition_marker] = true,
    [ts_external_token_loop_label_marker] = true,
    [ts_external_token_note_content_line] = true,
    [ts_external_token_error_sentinel] = true,
  },
  [2] = {
    [ts_external_token_start_marker] = true,
    [ts_external_token_stop_marker] = true,
  },
  [3] = {
    [ts_external_token_start_marker] = true,
    [ts_external_token_stop_marker] = true,
    [ts_external_token_arrow_label_marker] = true,
  },
  [4] = {
    [ts_external_token_condition_marker] = true,
  },
  [5] = {
    [ts_external_token_content_end] = true,
    [ts_external_token_note_content_line] = true,
  },
  [6] = {
    [ts_external_token_note_content_line] = true,
  },
  [7] = {
    [ts_external_token_content_start] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_startuml_directive] = ACTIONS(1),
    [sym_enduml_directive] = ACTIONS(1),
    [anon_sym_start] = ACTIONS(1),
    [anon_sym_stop] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_DASH_LBRACK] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [aux_sym_arrow_type_token1] = ACTIONS(1),
    [aux_sym_arrow_type_token2] = ACTIONS(1),
    [aux_sym_arrow_type_token3] = ACTIONS(1),
    [aux_sym_arrow_type_token4] = ACTIONS(1),
    [aux_sym_arrow_type_token5] = ACTIONS(1),
    [aux_sym_arrow_type_token6] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [sym_detach] = ACTIONS(1),
    [sym_kill] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_endif] = ACTIONS(1),
    [anon_sym_elseif] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_is] = ACTIONS(1),
    [anon_sym_endwhile] = ACTIONS(1),
    [anon_sym_repeat] = ACTIONS(1),
    [aux_sym_fork_node_token1] = ACTIONS(1),
    [aux_sym_fork_node_token2] = ACTIONS(1),
    [anon_sym_fork] = ACTIONS(1),
    [anon_sym_split] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_title] = ACTIONS(1),
    [anon_sym_skinparam] = ACTIONS(1),
    [anon_sym_BANGpragma] = ACTIONS(1),
    [anon_sym_BANGinclude] = ACTIONS(1),
    [anon_sym_partition] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_note] = ACTIONS(1),
    [anon_sym_left] = ACTIONS(1),
    [anon_sym_right] = ACTIONS(1),
    [anon_sym_top] = ACTIONS(1),
    [anon_sym_bottom] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(1),
    [sym_start_marker] = ACTIONS(1),
    [sym_stop_marker] = ACTIONS(1),
    [sym_label_marker] = ACTIONS(1),
    [sym_content_start] = ACTIONS(1),
    [sym_content_end] = ACTIONS(1),
    [sym_arrow_label_marker] = ACTIONS(1),
    [sym_activity_marker] = ACTIONS(1),
    [sym_condition_marker] = ACTIONS(1),
    [sym_loop_label_marker] = ACTIONS(1),
    [sym_note_content_line] = ACTIONS(1),
    [sym_error_sentinel] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(231),
    [sym__element] = STATE(134),
    [sym_diagram] = STATE(134),
    [sym_comment] = STATE(134),
    [sym_line_comment] = STATE(150),
    [sym_block_comment] = STATE(150),
    [aux_sym_source_file_repeat1] = STATE(134),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_startuml_directive] = ACTIONS(5),
    [anon_sym_SQUOTE] = ACTIONS(7),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(9),
    [sym__whitespace] = ACTIONS(11),
  },
  [2] = {
    [sym__statement] = STATE(4),
    [sym_activity_element] = STATE(4),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_elseif_branch] = STATE(145),
    [sym_else_branch] = STATE(208),
    [sym_branch_label] = STATE(7),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(4),
    [sym_skinparam_directive] = STATE(4),
    [sym_pragma_directive] = STATE(4),
    [sym_include_directive] = STATE(4),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(4),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(4),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(4),
    [aux_sym_decision_node_repeat1] = STATE(145),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(31),
    [anon_sym_elseif] = ACTIONS(33),
    [anon_sym_else] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(37),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(63),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [3] = {
    [sym__statement] = STATE(28),
    [sym_activity_element] = STATE(28),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(28),
    [sym_skinparam_directive] = STATE(28),
    [sym_pragma_directive] = STATE(28),
    [sym_include_directive] = STATE(28),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(28),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(28),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(28),
    [sym_identifier] = ACTIONS(69),
    [sym_enduml_directive] = ACTIONS(69),
    [anon_sym_start] = ACTIONS(69),
    [anon_sym_stop] = ACTIONS(69),
    [anon_sym_COLON] = ACTIONS(69),
    [anon_sym_DASH_LBRACK] = ACTIONS(69),
    [anon_sym_LBRACK] = ACTIONS(69),
    [aux_sym_arrow_type_token1] = ACTIONS(69),
    [aux_sym_arrow_type_token2] = ACTIONS(69),
    [aux_sym_arrow_type_token3] = ACTIONS(69),
    [aux_sym_arrow_type_token4] = ACTIONS(69),
    [aux_sym_arrow_type_token5] = ACTIONS(69),
    [aux_sym_arrow_type_token6] = ACTIONS(69),
    [anon_sym_EQ_GT] = ACTIONS(69),
    [anon_sym_LT_EQ] = ACTIONS(69),
    [sym_detach] = ACTIONS(69),
    [sym_kill] = ACTIONS(69),
    [anon_sym_PIPE] = ACTIONS(69),
    [anon_sym_if] = ACTIONS(69),
    [anon_sym_endif] = ACTIONS(69),
    [anon_sym_elseif] = ACTIONS(69),
    [anon_sym_else] = ACTIONS(69),
    [anon_sym_while] = ACTIONS(69),
    [anon_sym_is] = ACTIONS(71),
    [anon_sym_endwhile] = ACTIONS(73),
    [anon_sym_repeat] = ACTIONS(69),
    [aux_sym_fork_node_token1] = ACTIONS(69),
    [aux_sym_fork_node_token2] = ACTIONS(69),
    [anon_sym_fork] = ACTIONS(69),
    [anon_sym_split] = ACTIONS(69),
    [anon_sym_end] = ACTIONS(69),
    [anon_sym_title] = ACTIONS(69),
    [anon_sym_skinparam] = ACTIONS(69),
    [anon_sym_BANGpragma] = ACTIONS(69),
    [anon_sym_BANGinclude] = ACTIONS(69),
    [anon_sym_partition] = ACTIONS(69),
    [anon_sym_RBRACE] = ACTIONS(69),
    [anon_sym_note] = ACTIONS(69),
    [anon_sym_SQUOTE] = ACTIONS(69),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(69),
    [sym__whitespace] = ACTIONS(75),
    [sym_start_marker] = ACTIONS(75),
    [sym_stop_marker] = ACTIONS(75),
  },
  [4] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_elseif_branch] = STATE(144),
    [sym_else_branch] = STATE(190),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(12),
    [sym_skinparam_directive] = STATE(12),
    [sym_pragma_directive] = STATE(12),
    [sym_include_directive] = STATE(12),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(12),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(12),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(12),
    [aux_sym_decision_node_repeat1] = STATE(144),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(77),
    [anon_sym_elseif] = ACTIONS(33),
    [anon_sym_else] = ACTIONS(35),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(79),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [5] = {
    [sym__statement] = STATE(33),
    [sym_activity_element] = STATE(33),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(33),
    [sym_skinparam_directive] = STATE(33),
    [sym_pragma_directive] = STATE(33),
    [sym_include_directive] = STATE(33),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(33),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(33),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(33),
    [sym_identifier] = ACTIONS(81),
    [sym_enduml_directive] = ACTIONS(81),
    [anon_sym_start] = ACTIONS(81),
    [anon_sym_stop] = ACTIONS(81),
    [anon_sym_COLON] = ACTIONS(81),
    [anon_sym_DASH_LBRACK] = ACTIONS(81),
    [anon_sym_LBRACK] = ACTIONS(81),
    [aux_sym_arrow_type_token1] = ACTIONS(81),
    [aux_sym_arrow_type_token2] = ACTIONS(81),
    [aux_sym_arrow_type_token3] = ACTIONS(81),
    [aux_sym_arrow_type_token4] = ACTIONS(81),
    [aux_sym_arrow_type_token5] = ACTIONS(81),
    [aux_sym_arrow_type_token6] = ACTIONS(81),
    [anon_sym_EQ_GT] = ACTIONS(81),
    [anon_sym_LT_EQ] = ACTIONS(81),
    [sym_detach] = ACTIONS(81),
    [sym_kill] = ACTIONS(81),
    [anon_sym_PIPE] = ACTIONS(81),
    [anon_sym_if] = ACTIONS(81),
    [anon_sym_endif] = ACTIONS(81),
    [anon_sym_elseif] = ACTIONS(81),
    [anon_sym_else] = ACTIONS(81),
    [anon_sym_while] = ACTIONS(81),
    [anon_sym_endwhile] = ACTIONS(83),
    [anon_sym_repeat] = ACTIONS(81),
    [aux_sym_fork_node_token1] = ACTIONS(81),
    [aux_sym_fork_node_token2] = ACTIONS(81),
    [anon_sym_fork] = ACTIONS(81),
    [anon_sym_split] = ACTIONS(81),
    [anon_sym_end] = ACTIONS(81),
    [anon_sym_title] = ACTIONS(81),
    [anon_sym_skinparam] = ACTIONS(81),
    [anon_sym_BANGpragma] = ACTIONS(81),
    [anon_sym_BANGinclude] = ACTIONS(81),
    [anon_sym_partition] = ACTIONS(81),
    [anon_sym_RBRACE] = ACTIONS(81),
    [anon_sym_note] = ACTIONS(81),
    [anon_sym_SQUOTE] = ACTIONS(81),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(85),
    [sym_start_marker] = ACTIONS(85),
    [sym_stop_marker] = ACTIONS(85),
  },
  [6] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_elseif_branch] = STATE(147),
    [sym_else_branch] = STATE(229),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(12),
    [sym_skinparam_directive] = STATE(12),
    [sym_pragma_directive] = STATE(12),
    [sym_include_directive] = STATE(12),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(12),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(12),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(12),
    [aux_sym_decision_node_repeat1] = STATE(147),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(87),
    [anon_sym_elseif] = ACTIONS(33),
    [anon_sym_else] = ACTIONS(35),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(79),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [7] = {
    [sym__statement] = STATE(6),
    [sym_activity_element] = STATE(6),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_elseif_branch] = STATE(146),
    [sym_else_branch] = STATE(192),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(6),
    [sym_skinparam_directive] = STATE(6),
    [sym_pragma_directive] = STATE(6),
    [sym_include_directive] = STATE(6),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(6),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(6),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(6),
    [aux_sym_decision_node_repeat1] = STATE(146),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(89),
    [anon_sym_elseif] = ACTIONS(33),
    [anon_sym_else] = ACTIONS(35),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(91),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [8] = {
    [sym__statement] = STATE(10),
    [sym_activity_element] = STATE(10),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_branch_label] = STATE(9),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(10),
    [sym_skinparam_directive] = STATE(10),
    [sym_pragma_directive] = STATE(10),
    [sym_include_directive] = STATE(10),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(10),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(10),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(10),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(93),
    [anon_sym_elseif] = ACTIONS(93),
    [anon_sym_else] = ACTIONS(93),
    [anon_sym_LPAREN] = ACTIONS(37),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(95),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [9] = {
    [sym__statement] = STATE(11),
    [sym_activity_element] = STATE(11),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(11),
    [sym_skinparam_directive] = STATE(11),
    [sym_pragma_directive] = STATE(11),
    [sym_include_directive] = STATE(11),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(11),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(11),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(11),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(97),
    [anon_sym_elseif] = ACTIONS(97),
    [anon_sym_else] = ACTIONS(97),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(99),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [10] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(12),
    [sym_skinparam_directive] = STATE(12),
    [sym_pragma_directive] = STATE(12),
    [sym_include_directive] = STATE(12),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(12),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(12),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(12),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(101),
    [anon_sym_elseif] = ACTIONS(101),
    [anon_sym_else] = ACTIONS(101),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(79),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [11] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(12),
    [sym_skinparam_directive] = STATE(12),
    [sym_pragma_directive] = STATE(12),
    [sym_include_directive] = STATE(12),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(12),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(12),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(12),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(23),
    [aux_sym_arrow_type_token2] = ACTIONS(23),
    [aux_sym_arrow_type_token3] = ACTIONS(23),
    [aux_sym_arrow_type_token4] = ACTIONS(23),
    [aux_sym_arrow_type_token5] = ACTIONS(23),
    [aux_sym_arrow_type_token6] = ACTIONS(23),
    [anon_sym_EQ_GT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(103),
    [anon_sym_elseif] = ACTIONS(103),
    [anon_sym_else] = ACTIONS(103),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(51),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(79),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [12] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(131),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(139),
    [sym_arrow_type] = STATE(57),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(12),
    [sym_skinparam_directive] = STATE(12),
    [sym_pragma_directive] = STATE(12),
    [sym_include_directive] = STATE(12),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(12),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(12),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(12),
    [sym_identifier] = ACTIONS(105),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(120),
    [aux_sym_arrow_type_token2] = ACTIONS(120),
    [aux_sym_arrow_type_token3] = ACTIONS(120),
    [aux_sym_arrow_type_token4] = ACTIONS(120),
    [aux_sym_arrow_type_token5] = ACTIONS(120),
    [aux_sym_arrow_type_token6] = ACTIONS(120),
    [anon_sym_EQ_GT] = ACTIONS(120),
    [anon_sym_LT_EQ] = ACTIONS(120),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_endif] = ACTIONS(132),
    [anon_sym_elseif] = ACTIONS(132),
    [anon_sym_else] = ACTIONS(132),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_repeat] = ACTIONS(137),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(152),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(170),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [13] = {
    [sym__statement] = STATE(25),
    [sym_activity_element] = STATE(25),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(133),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(141),
    [sym_arrow_type] = STATE(112),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_branch_label] = STATE(24),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(25),
    [sym_skinparam_directive] = STATE(25),
    [sym_pragma_directive] = STATE(25),
    [sym_include_directive] = STATE(25),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(25),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(25),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(25),
    [sym_identifier] = ACTIONS(179),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(181),
    [aux_sym_arrow_type_token2] = ACTIONS(181),
    [aux_sym_arrow_type_token3] = ACTIONS(181),
    [aux_sym_arrow_type_token4] = ACTIONS(181),
    [aux_sym_arrow_type_token5] = ACTIONS(181),
    [aux_sym_arrow_type_token6] = ACTIONS(181),
    [anon_sym_EQ_GT] = ACTIONS(181),
    [anon_sym_LT_EQ] = ACTIONS(181),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(183),
    [anon_sym_LPAREN] = ACTIONS(37),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(185),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(187),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [14] = {
    [sym__statement] = STATE(28),
    [sym_activity_element] = STATE(28),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(28),
    [sym_skinparam_directive] = STATE(28),
    [sym_pragma_directive] = STATE(28),
    [sym_include_directive] = STATE(28),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(28),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(28),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(28),
    [sym_identifier] = ACTIONS(189),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(191),
    [aux_sym_arrow_type_token2] = ACTIONS(191),
    [aux_sym_arrow_type_token3] = ACTIONS(191),
    [aux_sym_arrow_type_token4] = ACTIONS(191),
    [aux_sym_arrow_type_token5] = ACTIONS(191),
    [aux_sym_arrow_type_token6] = ACTIONS(191),
    [anon_sym_EQ_GT] = ACTIONS(191),
    [anon_sym_LT_EQ] = ACTIONS(191),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_is] = ACTIONS(193),
    [anon_sym_endwhile] = ACTIONS(73),
    [anon_sym_repeat] = ACTIONS(195),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(197),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(199),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [15] = {
    [sym__statement] = STATE(28),
    [sym_activity_element] = STATE(28),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(28),
    [sym_skinparam_directive] = STATE(28),
    [sym_pragma_directive] = STATE(28),
    [sym_include_directive] = STATE(28),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(28),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(28),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(28),
    [sym_identifier] = ACTIONS(69),
    [anon_sym_start] = ACTIONS(69),
    [anon_sym_stop] = ACTIONS(69),
    [anon_sym_COLON] = ACTIONS(69),
    [anon_sym_DASH_LBRACK] = ACTIONS(69),
    [anon_sym_LBRACK] = ACTIONS(69),
    [aux_sym_arrow_type_token1] = ACTIONS(69),
    [aux_sym_arrow_type_token2] = ACTIONS(69),
    [aux_sym_arrow_type_token3] = ACTIONS(69),
    [aux_sym_arrow_type_token4] = ACTIONS(69),
    [aux_sym_arrow_type_token5] = ACTIONS(69),
    [aux_sym_arrow_type_token6] = ACTIONS(69),
    [anon_sym_EQ_GT] = ACTIONS(69),
    [anon_sym_LT_EQ] = ACTIONS(69),
    [sym_detach] = ACTIONS(69),
    [sym_kill] = ACTIONS(69),
    [anon_sym_PIPE] = ACTIONS(69),
    [anon_sym_if] = ACTIONS(69),
    [anon_sym_while] = ACTIONS(69),
    [anon_sym_is] = ACTIONS(201),
    [anon_sym_endwhile] = ACTIONS(69),
    [anon_sym_repeat] = ACTIONS(69),
    [aux_sym_fork_node_token1] = ACTIONS(69),
    [aux_sym_fork_node_token2] = ACTIONS(69),
    [anon_sym_fork] = ACTIONS(69),
    [anon_sym_split] = ACTIONS(69),
    [anon_sym_end] = ACTIONS(69),
    [anon_sym_title] = ACTIONS(69),
    [anon_sym_skinparam] = ACTIONS(69),
    [anon_sym_BANGpragma] = ACTIONS(69),
    [anon_sym_BANGinclude] = ACTIONS(69),
    [anon_sym_partition] = ACTIONS(69),
    [anon_sym_note] = ACTIONS(69),
    [anon_sym_SQUOTE] = ACTIONS(69),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(69),
    [sym__whitespace] = ACTIONS(75),
    [sym_start_marker] = ACTIONS(75),
    [sym_stop_marker] = ACTIONS(75),
  },
  [16] = {
    [sym__statement] = STATE(20),
    [sym_activity_element] = STATE(20),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(20),
    [sym_skinparam_directive] = STATE(20),
    [sym_pragma_directive] = STATE(20),
    [sym_include_directive] = STATE(20),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(20),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(20),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(20),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(209),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(211),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [17] = {
    [sym__statement] = STATE(16),
    [sym_activity_element] = STATE(16),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(16),
    [sym_skinparam_directive] = STATE(16),
    [sym_pragma_directive] = STATE(16),
    [sym_include_directive] = STATE(16),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(16),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(16),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(16),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(213),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(215),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [18] = {
    [sym__statement] = STATE(33),
    [sym_activity_element] = STATE(33),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(33),
    [sym_skinparam_directive] = STATE(33),
    [sym_pragma_directive] = STATE(33),
    [sym_include_directive] = STATE(33),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(33),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(33),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(33),
    [sym_identifier] = ACTIONS(189),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(191),
    [aux_sym_arrow_type_token2] = ACTIONS(191),
    [aux_sym_arrow_type_token3] = ACTIONS(191),
    [aux_sym_arrow_type_token4] = ACTIONS(191),
    [aux_sym_arrow_type_token5] = ACTIONS(191),
    [aux_sym_arrow_type_token6] = ACTIONS(191),
    [anon_sym_EQ_GT] = ACTIONS(191),
    [anon_sym_LT_EQ] = ACTIONS(191),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_endwhile] = ACTIONS(83),
    [anon_sym_repeat] = ACTIONS(195),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(197),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(217),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [19] = {
    [sym__statement] = STATE(19),
    [sym_activity_element] = STATE(19),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(132),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(140),
    [sym_arrow_type] = STATE(113),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(19),
    [sym_skinparam_directive] = STATE(19),
    [sym_pragma_directive] = STATE(19),
    [sym_include_directive] = STATE(19),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(19),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(19),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(19),
    [sym_identifier] = ACTIONS(219),
    [sym_enduml_directive] = ACTIONS(132),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(222),
    [aux_sym_arrow_type_token2] = ACTIONS(222),
    [aux_sym_arrow_type_token3] = ACTIONS(222),
    [aux_sym_arrow_type_token4] = ACTIONS(222),
    [aux_sym_arrow_type_token5] = ACTIONS(222),
    [aux_sym_arrow_type_token6] = ACTIONS(222),
    [anon_sym_EQ_GT] = ACTIONS(222),
    [anon_sym_LT_EQ] = ACTIONS(222),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_repeat] = ACTIONS(137),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(225),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(228),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [20] = {
    [sym__statement] = STATE(20),
    [sym_activity_element] = STATE(20),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(20),
    [sym_skinparam_directive] = STATE(20),
    [sym_pragma_directive] = STATE(20),
    [sym_include_directive] = STATE(20),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(20),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(20),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(20),
    [sym_identifier] = ACTIONS(231),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(234),
    [aux_sym_arrow_type_token2] = ACTIONS(234),
    [aux_sym_arrow_type_token3] = ACTIONS(234),
    [aux_sym_arrow_type_token4] = ACTIONS(234),
    [aux_sym_arrow_type_token5] = ACTIONS(234),
    [aux_sym_arrow_type_token6] = ACTIONS(234),
    [anon_sym_EQ_GT] = ACTIONS(234),
    [anon_sym_LT_EQ] = ACTIONS(234),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_repeat] = ACTIONS(137),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(237),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_RBRACE] = ACTIONS(132),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(240),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [21] = {
    [sym__statement] = STATE(30),
    [sym_activity_element] = STATE(30),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(133),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(141),
    [sym_arrow_type] = STATE(112),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(30),
    [sym_skinparam_directive] = STATE(30),
    [sym_pragma_directive] = STATE(30),
    [sym_include_directive] = STATE(30),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(30),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(30),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(30),
    [sym_identifier] = ACTIONS(179),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(181),
    [aux_sym_arrow_type_token2] = ACTIONS(181),
    [aux_sym_arrow_type_token3] = ACTIONS(181),
    [aux_sym_arrow_type_token4] = ACTIONS(181),
    [aux_sym_arrow_type_token5] = ACTIONS(181),
    [aux_sym_arrow_type_token6] = ACTIONS(181),
    [anon_sym_EQ_GT] = ACTIONS(181),
    [anon_sym_LT_EQ] = ACTIONS(181),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(243),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(185),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(245),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [22] = {
    [sym__statement] = STATE(20),
    [sym_activity_element] = STATE(20),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(20),
    [sym_skinparam_directive] = STATE(20),
    [sym_pragma_directive] = STATE(20),
    [sym_include_directive] = STATE(20),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(20),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(20),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(20),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(247),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(211),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [23] = {
    [sym__statement] = STATE(23),
    [sym_activity_element] = STATE(23),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(23),
    [sym_skinparam_directive] = STATE(23),
    [sym_pragma_directive] = STATE(23),
    [sym_include_directive] = STATE(23),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(23),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(23),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(23),
    [sym_identifier] = ACTIONS(249),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(252),
    [aux_sym_arrow_type_token2] = ACTIONS(252),
    [aux_sym_arrow_type_token3] = ACTIONS(252),
    [aux_sym_arrow_type_token4] = ACTIONS(252),
    [aux_sym_arrow_type_token5] = ACTIONS(252),
    [aux_sym_arrow_type_token6] = ACTIONS(252),
    [anon_sym_EQ_GT] = ACTIONS(252),
    [anon_sym_LT_EQ] = ACTIONS(252),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_endwhile] = ACTIONS(132),
    [anon_sym_repeat] = ACTIONS(255),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(258),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(261),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [24] = {
    [sym__statement] = STATE(21),
    [sym_activity_element] = STATE(21),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(133),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(141),
    [sym_arrow_type] = STATE(112),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(21),
    [sym_skinparam_directive] = STATE(21),
    [sym_pragma_directive] = STATE(21),
    [sym_include_directive] = STATE(21),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(21),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(21),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(21),
    [sym_identifier] = ACTIONS(179),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(181),
    [aux_sym_arrow_type_token2] = ACTIONS(181),
    [aux_sym_arrow_type_token3] = ACTIONS(181),
    [aux_sym_arrow_type_token4] = ACTIONS(181),
    [aux_sym_arrow_type_token5] = ACTIONS(181),
    [aux_sym_arrow_type_token6] = ACTIONS(181),
    [anon_sym_EQ_GT] = ACTIONS(181),
    [anon_sym_LT_EQ] = ACTIONS(181),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(264),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(185),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(266),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [25] = {
    [sym__statement] = STATE(30),
    [sym_activity_element] = STATE(30),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(133),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(141),
    [sym_arrow_type] = STATE(112),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(30),
    [sym_skinparam_directive] = STATE(30),
    [sym_pragma_directive] = STATE(30),
    [sym_include_directive] = STATE(30),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(30),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(30),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(30),
    [sym_identifier] = ACTIONS(179),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(181),
    [aux_sym_arrow_type_token2] = ACTIONS(181),
    [aux_sym_arrow_type_token3] = ACTIONS(181),
    [aux_sym_arrow_type_token4] = ACTIONS(181),
    [aux_sym_arrow_type_token5] = ACTIONS(181),
    [aux_sym_arrow_type_token6] = ACTIONS(181),
    [anon_sym_EQ_GT] = ACTIONS(181),
    [anon_sym_LT_EQ] = ACTIONS(181),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_endif] = ACTIONS(268),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(185),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(245),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [26] = {
    [sym__statement] = STATE(33),
    [sym_activity_element] = STATE(33),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(33),
    [sym_skinparam_directive] = STATE(33),
    [sym_pragma_directive] = STATE(33),
    [sym_include_directive] = STATE(33),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(33),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(33),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(33),
    [sym_identifier] = ACTIONS(81),
    [anon_sym_start] = ACTIONS(81),
    [anon_sym_stop] = ACTIONS(81),
    [anon_sym_COLON] = ACTIONS(81),
    [anon_sym_DASH_LBRACK] = ACTIONS(81),
    [anon_sym_LBRACK] = ACTIONS(81),
    [aux_sym_arrow_type_token1] = ACTIONS(81),
    [aux_sym_arrow_type_token2] = ACTIONS(81),
    [aux_sym_arrow_type_token3] = ACTIONS(81),
    [aux_sym_arrow_type_token4] = ACTIONS(81),
    [aux_sym_arrow_type_token5] = ACTIONS(81),
    [aux_sym_arrow_type_token6] = ACTIONS(81),
    [anon_sym_EQ_GT] = ACTIONS(81),
    [anon_sym_LT_EQ] = ACTIONS(81),
    [sym_detach] = ACTIONS(81),
    [sym_kill] = ACTIONS(81),
    [anon_sym_PIPE] = ACTIONS(81),
    [anon_sym_if] = ACTIONS(81),
    [anon_sym_while] = ACTIONS(81),
    [anon_sym_endwhile] = ACTIONS(81),
    [anon_sym_repeat] = ACTIONS(81),
    [aux_sym_fork_node_token1] = ACTIONS(81),
    [aux_sym_fork_node_token2] = ACTIONS(81),
    [anon_sym_fork] = ACTIONS(81),
    [anon_sym_split] = ACTIONS(81),
    [anon_sym_end] = ACTIONS(81),
    [anon_sym_title] = ACTIONS(81),
    [anon_sym_skinparam] = ACTIONS(81),
    [anon_sym_BANGpragma] = ACTIONS(81),
    [anon_sym_BANGinclude] = ACTIONS(81),
    [anon_sym_partition] = ACTIONS(81),
    [anon_sym_note] = ACTIONS(81),
    [anon_sym_SQUOTE] = ACTIONS(81),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(85),
    [sym_start_marker] = ACTIONS(85),
    [sym_stop_marker] = ACTIONS(85),
  },
  [27] = {
    [sym__statement] = STATE(32),
    [sym_activity_element] = STATE(32),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(32),
    [sym_skinparam_directive] = STATE(32),
    [sym_pragma_directive] = STATE(32),
    [sym_include_directive] = STATE(32),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(32),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(32),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(32),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(270),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(272),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [28] = {
    [sym__statement] = STATE(23),
    [sym_activity_element] = STATE(23),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(23),
    [sym_skinparam_directive] = STATE(23),
    [sym_pragma_directive] = STATE(23),
    [sym_include_directive] = STATE(23),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(23),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(23),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(23),
    [sym_identifier] = ACTIONS(189),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(191),
    [aux_sym_arrow_type_token2] = ACTIONS(191),
    [aux_sym_arrow_type_token3] = ACTIONS(191),
    [aux_sym_arrow_type_token4] = ACTIONS(191),
    [aux_sym_arrow_type_token5] = ACTIONS(191),
    [aux_sym_arrow_type_token6] = ACTIONS(191),
    [anon_sym_EQ_GT] = ACTIONS(191),
    [anon_sym_LT_EQ] = ACTIONS(191),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_endwhile] = ACTIONS(274),
    [anon_sym_repeat] = ACTIONS(195),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(197),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(276),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [29] = {
    [sym__statement] = STATE(20),
    [sym_activity_element] = STATE(20),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(20),
    [sym_skinparam_directive] = STATE(20),
    [sym_pragma_directive] = STATE(20),
    [sym_include_directive] = STATE(20),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(20),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(20),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(20),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(278),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(211),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [30] = {
    [sym__statement] = STATE(30),
    [sym_activity_element] = STATE(30),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(133),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(141),
    [sym_arrow_type] = STATE(112),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(30),
    [sym_skinparam_directive] = STATE(30),
    [sym_pragma_directive] = STATE(30),
    [sym_include_directive] = STATE(30),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(30),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(30),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(30),
    [sym_identifier] = ACTIONS(280),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(283),
    [aux_sym_arrow_type_token2] = ACTIONS(283),
    [aux_sym_arrow_type_token3] = ACTIONS(283),
    [aux_sym_arrow_type_token4] = ACTIONS(283),
    [aux_sym_arrow_type_token5] = ACTIONS(283),
    [aux_sym_arrow_type_token6] = ACTIONS(283),
    [anon_sym_EQ_GT] = ACTIONS(283),
    [anon_sym_LT_EQ] = ACTIONS(283),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_endif] = ACTIONS(132),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_repeat] = ACTIONS(137),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(286),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(289),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [31] = {
    [sym__statement] = STATE(22),
    [sym_activity_element] = STATE(22),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(22),
    [sym_skinparam_directive] = STATE(22),
    [sym_pragma_directive] = STATE(22),
    [sym_include_directive] = STATE(22),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(22),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(22),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(22),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(278),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(292),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [32] = {
    [sym__statement] = STATE(20),
    [sym_activity_element] = STATE(20),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(20),
    [sym_skinparam_directive] = STATE(20),
    [sym_pragma_directive] = STATE(20),
    [sym_include_directive] = STATE(20),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(20),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(20),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(20),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(213),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(211),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [33] = {
    [sym__statement] = STATE(23),
    [sym_activity_element] = STATE(23),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(128),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(137),
    [sym_arrow_type] = STATE(110),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(23),
    [sym_skinparam_directive] = STATE(23),
    [sym_pragma_directive] = STATE(23),
    [sym_include_directive] = STATE(23),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(23),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(23),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(23),
    [sym_identifier] = ACTIONS(189),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(191),
    [aux_sym_arrow_type_token2] = ACTIONS(191),
    [aux_sym_arrow_type_token3] = ACTIONS(191),
    [aux_sym_arrow_type_token4] = ACTIONS(191),
    [aux_sym_arrow_type_token5] = ACTIONS(191),
    [aux_sym_arrow_type_token6] = ACTIONS(191),
    [anon_sym_EQ_GT] = ACTIONS(191),
    [anon_sym_LT_EQ] = ACTIONS(191),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_endwhile] = ACTIONS(294),
    [anon_sym_repeat] = ACTIONS(195),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(197),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(276),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [34] = {
    [sym__statement] = STATE(29),
    [sym_activity_element] = STATE(29),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(129),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(136),
    [sym_arrow_type] = STATE(108),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(29),
    [sym_skinparam_directive] = STATE(29),
    [sym_pragma_directive] = STATE(29),
    [sym_include_directive] = STATE(29),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(29),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(29),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(29),
    [sym_identifier] = ACTIONS(203),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(205),
    [aux_sym_arrow_type_token2] = ACTIONS(205),
    [aux_sym_arrow_type_token3] = ACTIONS(205),
    [aux_sym_arrow_type_token4] = ACTIONS(205),
    [aux_sym_arrow_type_token5] = ACTIONS(205),
    [aux_sym_arrow_type_token6] = ACTIONS(205),
    [anon_sym_EQ_GT] = ACTIONS(205),
    [anon_sym_LT_EQ] = ACTIONS(205),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(207),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(296),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(298),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [35] = {
    [sym__statement] = STATE(19),
    [sym_activity_element] = STATE(19),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(132),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(140),
    [sym_arrow_type] = STATE(113),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(19),
    [sym_skinparam_directive] = STATE(19),
    [sym_pragma_directive] = STATE(19),
    [sym_include_directive] = STATE(19),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(19),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(19),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(19),
    [sym_identifier] = ACTIONS(300),
    [sym_enduml_directive] = ACTIONS(302),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(304),
    [aux_sym_arrow_type_token2] = ACTIONS(304),
    [aux_sym_arrow_type_token3] = ACTIONS(304),
    [aux_sym_arrow_type_token4] = ACTIONS(304),
    [aux_sym_arrow_type_token5] = ACTIONS(304),
    [aux_sym_arrow_type_token6] = ACTIONS(304),
    [anon_sym_EQ_GT] = ACTIONS(304),
    [anon_sym_LT_EQ] = ACTIONS(304),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(306),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(308),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [36] = {
    [sym__statement] = STATE(35),
    [sym_activity_element] = STATE(35),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(132),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(140),
    [sym_arrow_type] = STATE(113),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(35),
    [sym_skinparam_directive] = STATE(35),
    [sym_pragma_directive] = STATE(35),
    [sym_include_directive] = STATE(35),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(35),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(35),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(35),
    [sym_identifier] = ACTIONS(300),
    [sym_enduml_directive] = ACTIONS(310),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(304),
    [aux_sym_arrow_type_token2] = ACTIONS(304),
    [aux_sym_arrow_type_token3] = ACTIONS(304),
    [aux_sym_arrow_type_token4] = ACTIONS(304),
    [aux_sym_arrow_type_token5] = ACTIONS(304),
    [aux_sym_arrow_type_token6] = ACTIONS(304),
    [anon_sym_EQ_GT] = ACTIONS(304),
    [anon_sym_LT_EQ] = ACTIONS(304),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(306),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(312),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [37] = {
    [sym__statement] = STATE(42),
    [sym_activity_element] = STATE(42),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(42),
    [sym_skinparam_directive] = STATE(42),
    [sym_pragma_directive] = STATE(42),
    [sym_include_directive] = STATE(42),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(42),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(42),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(42),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(318),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(322),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [38] = {
    [sym__statement] = STATE(43),
    [sym_activity_element] = STATE(43),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(43),
    [sym_skinparam_directive] = STATE(43),
    [sym_pragma_directive] = STATE(43),
    [sym_include_directive] = STATE(43),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(43),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(43),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(43),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(324),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(326),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [39] = {
    [sym__statement] = STATE(43),
    [sym_activity_element] = STATE(43),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(43),
    [sym_skinparam_directive] = STATE(43),
    [sym_pragma_directive] = STATE(43),
    [sym_include_directive] = STATE(43),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(43),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(43),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(43),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(326),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [40] = {
    [sym__statement] = STATE(37),
    [sym_activity_element] = STATE(37),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(37),
    [sym_skinparam_directive] = STATE(37),
    [sym_pragma_directive] = STATE(37),
    [sym_include_directive] = STATE(37),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(37),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(37),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(37),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(328),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [41] = {
    [sym__statement] = STATE(43),
    [sym_activity_element] = STATE(43),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(43),
    [sym_skinparam_directive] = STATE(43),
    [sym_pragma_directive] = STATE(43),
    [sym_include_directive] = STATE(43),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(43),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(43),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(43),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(330),
    [anon_sym_repeat] = ACTIONS(41),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(326),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
  [42] = {
    [sym__statement] = STATE(42),
    [sym_activity_element] = STATE(42),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(42),
    [sym_skinparam_directive] = STATE(42),
    [sym_pragma_directive] = STATE(42),
    [sym_include_directive] = STATE(42),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(42),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(42),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(42),
    [sym_identifier] = ACTIONS(332),
    [anon_sym_start] = ACTIONS(108),
    [anon_sym_stop] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(114),
    [anon_sym_DASH_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [aux_sym_arrow_type_token1] = ACTIONS(335),
    [aux_sym_arrow_type_token2] = ACTIONS(335),
    [aux_sym_arrow_type_token3] = ACTIONS(335),
    [aux_sym_arrow_type_token4] = ACTIONS(335),
    [aux_sym_arrow_type_token5] = ACTIONS(335),
    [aux_sym_arrow_type_token6] = ACTIONS(335),
    [anon_sym_EQ_GT] = ACTIONS(335),
    [anon_sym_LT_EQ] = ACTIONS(335),
    [sym_detach] = ACTIONS(123),
    [sym_kill] = ACTIONS(123),
    [anon_sym_PIPE] = ACTIONS(126),
    [anon_sym_if] = ACTIONS(129),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_repeat] = ACTIONS(137),
    [aux_sym_fork_node_token1] = ACTIONS(140),
    [aux_sym_fork_node_token2] = ACTIONS(140),
    [anon_sym_fork] = ACTIONS(140),
    [anon_sym_split] = ACTIONS(140),
    [anon_sym_end] = ACTIONS(143),
    [anon_sym_title] = ACTIONS(146),
    [anon_sym_skinparam] = ACTIONS(149),
    [anon_sym_BANGpragma] = ACTIONS(338),
    [anon_sym_BANGinclude] = ACTIONS(155),
    [anon_sym_partition] = ACTIONS(158),
    [anon_sym_note] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(164),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(167),
    [sym__whitespace] = ACTIONS(341),
    [sym_start_marker] = ACTIONS(173),
    [sym_stop_marker] = ACTIONS(176),
  },
  [43] = {
    [sym__statement] = STATE(42),
    [sym_activity_element] = STATE(42),
    [sym_start_node] = STATE(66),
    [sym_stop_node] = STATE(66),
    [sym_activity_node] = STATE(66),
    [sym_flow_arrow] = STATE(106),
    [sym__flow_source] = STATE(130),
    [sym_arrow] = STATE(45),
    [sym_arrow_style] = STATE(138),
    [sym_arrow_type] = STATE(117),
    [sym_swimlane] = STATE(106),
    [sym_decision_node] = STATE(106),
    [sym_while_loop] = STATE(106),
    [sym_repeat_loop] = STATE(106),
    [sym_fork_node] = STATE(106),
    [sym_join_node] = STATE(106),
    [sym_title_directive] = STATE(42),
    [sym_skinparam_directive] = STATE(42),
    [sym_pragma_directive] = STATE(42),
    [sym_include_directive] = STATE(42),
    [sym_partition] = STATE(106),
    [sym_note_directive] = STATE(42),
    [sym_note_line] = STATE(96),
    [sym_floating_note] = STATE(96),
    [sym_comment] = STATE(42),
    [sym_line_comment] = STATE(67),
    [sym_block_comment] = STATE(67),
    [aux_sym_diagram_repeat1] = STATE(42),
    [sym_identifier] = ACTIONS(314),
    [anon_sym_start] = ACTIONS(15),
    [anon_sym_stop] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_DASH_LBRACK] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(21),
    [aux_sym_arrow_type_token1] = ACTIONS(316),
    [aux_sym_arrow_type_token2] = ACTIONS(316),
    [aux_sym_arrow_type_token3] = ACTIONS(316),
    [aux_sym_arrow_type_token4] = ACTIONS(316),
    [aux_sym_arrow_type_token5] = ACTIONS(316),
    [aux_sym_arrow_type_token6] = ACTIONS(316),
    [anon_sym_EQ_GT] = ACTIONS(316),
    [anon_sym_LT_EQ] = ACTIONS(316),
    [sym_detach] = ACTIONS(25),
    [sym_kill] = ACTIONS(25),
    [anon_sym_PIPE] = ACTIONS(27),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(39),
    [anon_sym_repeat] = ACTIONS(344),
    [aux_sym_fork_node_token1] = ACTIONS(43),
    [aux_sym_fork_node_token2] = ACTIONS(43),
    [anon_sym_fork] = ACTIONS(43),
    [anon_sym_split] = ACTIONS(43),
    [anon_sym_end] = ACTIONS(45),
    [anon_sym_title] = ACTIONS(47),
    [anon_sym_skinparam] = ACTIONS(49),
    [anon_sym_BANGpragma] = ACTIONS(320),
    [anon_sym_BANGinclude] = ACTIONS(53),
    [anon_sym_partition] = ACTIONS(55),
    [anon_sym_note] = ACTIONS(57),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(61),
    [sym__whitespace] = ACTIONS(322),
    [sym_start_marker] = ACTIONS(65),
    [sym_stop_marker] = ACTIONS(67),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(348), 1,
      anon_sym_SEMI,
    ACTIONS(350), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    STATE(50), 4,
      sym_start_node,
      sym_stop_node,
      sym_activity_node,
      sym__flow_target,
    ACTIONS(346), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [56] = 4,
    ACTIONS(354), 1,
      anon_sym_SEMI,
    ACTIONS(356), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    STATE(61), 4,
      sym_start_node,
      sym_stop_node,
      sym_activity_node,
      sym__flow_target,
    ACTIONS(352), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [112] = 4,
    ACTIONS(37), 1,
      anon_sym_LPAREN,
    STATE(75), 1,
      sym_branch_label,
    ACTIONS(360), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(358), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [165] = 4,
    ACTIONS(37), 1,
      anon_sym_LPAREN,
    STATE(88), 1,
      sym_branch_label,
    ACTIONS(364), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(362), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [218] = 4,
    ACTIONS(37), 1,
      anon_sym_LPAREN,
    STATE(84), 1,
      sym_branch_label,
    ACTIONS(368), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(366), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [271] = 4,
    ACTIONS(37), 1,
      anon_sym_LPAREN,
    STATE(100), 1,
      sym_branch_label,
    ACTIONS(372), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(370), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [324] = 3,
    ACTIONS(376), 1,
      anon_sym_SEMI,
    ACTIONS(378), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(374), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [374] = 2,
    ACTIONS(382), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(380), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [422] = 2,
    ACTIONS(386), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(384), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [470] = 2,
    ACTIONS(390), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(388), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [518] = 2,
    ACTIONS(394), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(392), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [566] = 2,
    ACTIONS(398), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(396), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [614] = 2,
    ACTIONS(402), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(400), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_is,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [662] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 38,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [716] = 2,
    ACTIONS(414), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(412), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_is,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [764] = 2,
    ACTIONS(418), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(416), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [812] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 38,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [866] = 3,
    ACTIONS(426), 1,
      anon_sym_SEMI,
    ACTIONS(428), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(424), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [916] = 2,
    ACTIONS(432), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(430), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [964] = 2,
    ACTIONS(436), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(434), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1012] = 2,
    ACTIONS(440), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(438), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1060] = 2,
    ACTIONS(444), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(442), 40,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1108] = 3,
    ACTIONS(451), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(448), 10,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
    ACTIONS(446), 29,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1157] = 2,
    ACTIONS(455), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(453), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1204] = 2,
    ACTIONS(459), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(457), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1251] = 2,
    ACTIONS(463), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(461), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1298] = 2,
    ACTIONS(467), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(465), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1345] = 2,
    ACTIONS(471), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(469), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1392] = 2,
    ACTIONS(475), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(473), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1439] = 2,
    ACTIONS(479), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(477), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1486] = 2,
    ACTIONS(483), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(481), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1533] = 2,
    ACTIONS(487), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(485), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1580] = 2,
    ACTIONS(491), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(489), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1627] = 2,
    ACTIONS(495), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(493), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1674] = 2,
    ACTIONS(499), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(497), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1721] = 2,
    ACTIONS(503), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(501), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1768] = 2,
    ACTIONS(507), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(505), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1815] = 2,
    ACTIONS(511), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(509), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1862] = 2,
    ACTIONS(515), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(513), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1909] = 2,
    ACTIONS(519), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(517), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [1956] = 2,
    ACTIONS(523), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(521), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2003] = 2,
    ACTIONS(527), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(525), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2050] = 2,
    ACTIONS(531), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(529), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2097] = 2,
    ACTIONS(535), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(533), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2144] = 2,
    ACTIONS(539), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(537), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2191] = 2,
    ACTIONS(543), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(541), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2238] = 2,
    ACTIONS(547), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(545), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2285] = 2,
    ACTIONS(551), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(549), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2332] = 2,
    ACTIONS(555), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(553), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2379] = 2,
    ACTIONS(559), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(557), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2426] = 2,
    ACTIONS(563), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(561), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2473] = 2,
    ACTIONS(567), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(565), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2520] = 2,
    ACTIONS(571), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(569), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2567] = 2,
    ACTIONS(575), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(573), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2614] = 2,
    ACTIONS(579), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(577), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2661] = 2,
    ACTIONS(583), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(581), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2708] = 2,
    ACTIONS(587), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(585), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2755] = 2,
    ACTIONS(591), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(589), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2802] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 39,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [2849] = 2,
    ACTIONS(599), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(597), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2896] = 2,
    ACTIONS(603), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(601), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2943] = 2,
    ACTIONS(607), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(605), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [2990] = 2,
    ACTIONS(451), 3,
      sym_start_marker,
      sym_stop_marker,
      sym__whitespace,
    ACTIONS(446), 39,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [3037] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3089] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3141] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3193] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3245] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 37,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_else,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3295] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3347] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 36,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3399] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3451] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 36,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3503] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(54), 1,
      sym_arrow_label,
    ACTIONS(422), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(420), 35,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3554] = 5,
    ACTIONS(406), 1,
      aux_sym_arrow_label_token1,
    ACTIONS(410), 1,
      sym_arrow_label_marker,
    STATE(63), 1,
      sym_arrow_label,
    ACTIONS(408), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(404), 35,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3605] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 37,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3650] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 37,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3695] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 37,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3740] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 37,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3785] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 35,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3833] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 35,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3881] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 35,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3929] = 2,
    ACTIONS(595), 3,
      sym_start_marker,
      sym_stop_marker,
      sym_arrow_label_marker,
    ACTIONS(593), 36,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      aux_sym_arrow_label_token1,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [3973] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 35,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [4021] = 4,
    ACTIONS(611), 1,
      aux_sym_title_directive_token1,
    STATE(82), 1,
      sym_directive_value,
    ACTIONS(613), 2,
      sym_start_marker,
      sym_stop_marker,
    ACTIONS(609), 34,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token4,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
      sym_detach,
      sym_kill,
      anon_sym_PIPE,
      anon_sym_if,
      anon_sym_while,
      anon_sym_repeat,
      aux_sym_fork_node_token1,
      aux_sym_fork_node_token2,
      anon_sym_fork,
      anon_sym_split,
      anon_sym_end,
      anon_sym_title,
      anon_sym_skinparam,
      anon_sym_BANGpragma,
      anon_sym_BANGinclude,
      anon_sym_partition,
      anon_sym_note,
      sym_identifier,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
      sym__whitespace,
  [4068] = 6,
    ACTIONS(191), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(110), 1,
      sym_arrow_type,
    STATE(137), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(617), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4094] = 6,
    ACTIONS(205), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(108), 1,
      sym_arrow_type,
    STATE(136), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(619), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4120] = 6,
    ACTIONS(316), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(117), 1,
      sym_arrow_type,
    STATE(138), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(621), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4146] = 6,
    ACTIONS(23), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(57), 1,
      sym_arrow_type,
    STATE(139), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(623), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4172] = 6,
    ACTIONS(304), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(113), 1,
      sym_arrow_type,
    STATE(140), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(625), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4198] = 6,
    ACTIONS(181), 1,
      aux_sym_arrow_type_token4,
    STATE(44), 1,
      sym_arrow,
    STATE(112), 1,
      sym_arrow_type,
    STATE(141), 1,
      sym_arrow_style,
    ACTIONS(615), 2,
      anon_sym_DASH_LBRACK,
      anon_sym_LBRACK,
    ACTIONS(627), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4224] = 7,
    ACTIONS(5), 1,
      sym_startuml_directive,
    ACTIONS(7), 1,
      anon_sym_SQUOTE,
    ACTIONS(9), 1,
      anon_sym_SLASH_SQUOTE,
    ACTIONS(629), 1,
      ts_builtin_sym_end,
    ACTIONS(631), 1,
      sym__whitespace,
    STATE(150), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(135), 4,
      sym__element,
      sym_diagram,
      sym_comment,
      aux_sym_source_file_repeat1,
  [4250] = 7,
    ACTIONS(633), 1,
      ts_builtin_sym_end,
    ACTIONS(635), 1,
      sym_startuml_directive,
    ACTIONS(638), 1,
      anon_sym_SQUOTE,
    ACTIONS(641), 1,
      anon_sym_SLASH_SQUOTE,
    ACTIONS(644), 1,
      sym__whitespace,
    STATE(150), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(135), 4,
      sym__element,
      sym_diagram,
      sym_comment,
      aux_sym_source_file_repeat1,
  [4276] = 3,
    ACTIONS(205), 1,
      aux_sym_arrow_type_token4,
    STATE(107), 1,
      sym_arrow_type,
    ACTIONS(619), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4292] = 3,
    ACTIONS(191), 1,
      aux_sym_arrow_type_token4,
    STATE(109), 1,
      sym_arrow_type,
    ACTIONS(617), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4308] = 3,
    ACTIONS(316), 1,
      aux_sym_arrow_type_token4,
    STATE(116), 1,
      sym_arrow_type,
    ACTIONS(621), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4324] = 3,
    ACTIONS(23), 1,
      aux_sym_arrow_type_token4,
    STATE(60), 1,
      sym_arrow_type,
    ACTIONS(623), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4340] = 3,
    ACTIONS(304), 1,
      aux_sym_arrow_type_token4,
    STATE(115), 1,
      sym_arrow_type,
    ACTIONS(625), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4356] = 3,
    ACTIONS(181), 1,
      aux_sym_arrow_type_token4,
    STATE(114), 1,
      sym_arrow_type,
    ACTIONS(627), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4372] = 2,
    ACTIONS(649), 1,
      aux_sym_arrow_type_token4,
    ACTIONS(647), 7,
      aux_sym_arrow_type_token1,
      aux_sym_arrow_type_token2,
      aux_sym_arrow_type_token3,
      aux_sym_arrow_type_token5,
      aux_sym_arrow_type_token6,
      anon_sym_EQ_GT,
      anon_sym_LT_EQ,
  [4385] = 7,
    ACTIONS(651), 1,
      sym_identifier,
    ACTIONS(653), 1,
      anon_sym_LBRACE,
    ACTIONS(655), 1,
      anon_sym_POUND,
    ACTIONS(657), 1,
      anon_sym_DQUOTE,
    ACTIONS(659), 1,
      anon_sym_SQUOTE,
    STATE(156), 1,
      sym_string,
    STATE(218), 1,
      sym_color_spec,
  [4407] = 5,
    ACTIONS(35), 1,
      anon_sym_else,
    ACTIONS(661), 1,
      anon_sym_endif,
    ACTIONS(663), 1,
      anon_sym_elseif,
    STATE(219), 1,
      sym_else_branch,
    STATE(153), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [4424] = 5,
    ACTIONS(35), 1,
      anon_sym_else,
    ACTIONS(663), 1,
      anon_sym_elseif,
    ACTIONS(665), 1,
      anon_sym_endif,
    STATE(190), 1,
      sym_else_branch,
    STATE(153), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [4441] = 5,
    ACTIONS(35), 1,
      anon_sym_else,
    ACTIONS(663), 1,
      anon_sym_elseif,
    ACTIONS(667), 1,
      anon_sym_endif,
    STATE(229), 1,
      sym_else_branch,
    STATE(153), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [4458] = 5,
    ACTIONS(35), 1,
      anon_sym_else,
    ACTIONS(663), 1,
      anon_sym_elseif,
    ACTIONS(669), 1,
      anon_sym_endif,
    STATE(196), 1,
      sym_else_branch,
    STATE(153), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [4475] = 2,
    ACTIONS(671), 2,
      ts_builtin_sym_end,
      sym__whitespace,
    ACTIONS(673), 3,
      sym_startuml_directive,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [4485] = 2,
    ACTIONS(675), 2,
      ts_builtin_sym_end,
      sym__whitespace,
    ACTIONS(677), 3,
      sym_startuml_directive,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [4495] = 2,
    ACTIONS(455), 2,
      ts_builtin_sym_end,
      sym__whitespace,
    ACTIONS(453), 3,
      sym_startuml_directive,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [4505] = 2,
    ACTIONS(583), 2,
      ts_builtin_sym_end,
      sym__whitespace,
    ACTIONS(581), 3,
      sym_startuml_directive,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [4515] = 2,
    ACTIONS(563), 2,
      ts_builtin_sym_end,
      sym__whitespace,
    ACTIONS(561), 3,
      sym_startuml_directive,
      anon_sym_SQUOTE,
      anon_sym_SLASH_SQUOTE,
  [4525] = 4,
    ACTIONS(679), 1,
      anon_sym_endif,
    ACTIONS(681), 1,
      anon_sym_elseif,
    ACTIONS(684), 1,
      anon_sym_else,
    STATE(153), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [4539] = 3,
    ACTIONS(686), 1,
      anon_sym_LPAREN,
    ACTIONS(688), 1,
      sym_condition_marker,
    STATE(204), 1,
      sym_condition_expression,
  [4549] = 3,
    ACTIONS(690), 1,
      sym_content_end,
    ACTIONS(692), 1,
      sym_note_content_line,
    STATE(161), 1,
      aux_sym_floating_note_repeat1,
  [4559] = 3,
    ACTIONS(655), 1,
      anon_sym_POUND,
    ACTIONS(694), 1,
      anon_sym_LBRACE,
    STATE(186), 1,
      sym_color_spec,
  [4569] = 3,
    ACTIONS(696), 1,
      anon_sym_DQUOTE,
    ACTIONS(698), 1,
      anon_sym_SQUOTE,
    STATE(77), 1,
      sym_string,
  [4579] = 3,
    ACTIONS(686), 1,
      anon_sym_LPAREN,
    ACTIONS(688), 1,
      sym_condition_marker,
    STATE(193), 1,
      sym_condition_expression,
  [4589] = 3,
    ACTIONS(700), 1,
      anon_sym_LPAREN,
    ACTIONS(702), 1,
      sym_condition_marker,
    STATE(14), 1,
      sym_condition_expression,
  [4599] = 3,
    ACTIONS(700), 1,
      anon_sym_LPAREN,
    ACTIONS(702), 1,
      sym_condition_marker,
    STATE(3), 1,
      sym_condition_expression,
  [4609] = 3,
    ACTIONS(704), 1,
      sym_content_end,
    ACTIONS(706), 1,
      sym_note_content_line,
    STATE(161), 1,
      aux_sym_floating_note_repeat1,
  [4619] = 3,
    ACTIONS(700), 1,
      anon_sym_LPAREN,
    ACTIONS(702), 1,
      sym_condition_marker,
    STATE(15), 1,
      sym_condition_expression,
  [4629] = 2,
    ACTIONS(709), 1,
      anon_sym_LPAREN,
    STATE(5), 1,
      sym_branch_label,
  [4636] = 2,
    ACTIONS(711), 1,
      sym_text_line,
    STATE(175), 1,
      sym_activity_label,
  [4643] = 1,
    ACTIONS(713), 2,
      anon_sym_fork,
      anon_sym_split,
  [4648] = 1,
    ACTIONS(575), 2,
      anon_sym_LBRACE,
      anon_sym_POUND,
  [4653] = 2,
    ACTIONS(715), 1,
      sym_note_content_line,
    STATE(155), 1,
      aux_sym_floating_note_repeat1,
  [4660] = 2,
    ACTIONS(709), 1,
      anon_sym_LPAREN,
    STATE(26), 1,
      sym_branch_label,
  [4667] = 2,
    ACTIONS(709), 1,
      anon_sym_LPAREN,
    STATE(18), 1,
      sym_branch_label,
  [4674] = 2,
    ACTIONS(717), 1,
      anon_sym_COLON,
    ACTIONS(719), 1,
      sym_content_start,
  [4681] = 1,
    ACTIONS(721), 1,
      aux_sym_title_directive_token1,
  [4685] = 1,
    ACTIONS(723), 1,
      aux_sym_string_token2,
  [4689] = 1,
    ACTIONS(725), 1,
      anon_sym_LPAREN,
  [4693] = 1,
    ACTIONS(727), 1,
      anon_sym_PIPE,
  [4697] = 1,
    ACTIONS(729), 1,
      anon_sym_SEMI,
  [4701] = 1,
    ACTIONS(731), 1,
      anon_sym_SEMI,
  [4705] = 1,
    ACTIONS(733), 1,
      aux_sym_line_comment_token1,
  [4709] = 1,
    ACTIONS(735), 1,
      aux_sym_branch_label_token1,
  [4713] = 1,
    ACTIONS(737), 1,
      anon_sym_end,
  [4717] = 1,
    ACTIONS(739), 1,
      anon_sym_RPAREN,
  [4721] = 1,
    ACTIONS(741), 1,
      anon_sym_SQUOTE_SLASH,
  [4725] = 1,
    ACTIONS(743), 1,
      anon_sym_DQUOTE,
  [4729] = 1,
    ACTIONS(745), 1,
      sym_identifier,
  [4733] = 1,
    ACTIONS(743), 1,
      anon_sym_SQUOTE,
  [4737] = 1,
    ACTIONS(747), 1,
      anon_sym_LBRACE,
  [4741] = 1,
    ACTIONS(749), 1,
      anon_sym_LBRACE,
  [4745] = 1,
    ACTIONS(751), 1,
      sym_identifier,
  [4749] = 1,
    ACTIONS(753), 1,
      sym_identifier,
  [4753] = 1,
    ACTIONS(755), 1,
      aux_sym_title_directive_token1,
  [4757] = 1,
    ACTIONS(661), 1,
      anon_sym_endif,
  [4761] = 1,
    ACTIONS(757), 1,
      aux_sym_arrow_label_token1,
  [4765] = 1,
    ACTIONS(667), 1,
      anon_sym_endif,
  [4769] = 1,
    ACTIONS(759), 1,
      anon_sym_then,
  [4773] = 1,
    ACTIONS(761), 1,
      aux_sym_arrow_label_token1,
  [4777] = 1,
    ACTIONS(763), 1,
      sym_identifier,
  [4781] = 1,
    ACTIONS(765), 1,
      anon_sym_endif,
  [4785] = 1,
    ACTIONS(767), 1,
      sym_identifier,
  [4789] = 1,
    ACTIONS(769), 1,
      anon_sym_RPAREN,
  [4793] = 1,
    ACTIONS(771), 1,
      anon_sym_RPAREN,
  [4797] = 1,
    ACTIONS(402), 1,
      anon_sym_then,
  [4801] = 1,
    ACTIONS(773), 1,
      aux_sym_string_token1,
  [4805] = 1,
    ACTIONS(775), 1,
      aux_sym_branch_label_token1,
  [4809] = 1,
    ACTIONS(777), 1,
      anon_sym_note,
  [4813] = 1,
    ACTIONS(779), 1,
      anon_sym_then,
  [4817] = 1,
    ACTIONS(414), 1,
      anon_sym_then,
  [4821] = 1,
    ACTIONS(781), 1,
      aux_sym_branch_label_token1,
  [4825] = 1,
    ACTIONS(783), 1,
      anon_sym_LPAREN_STAR_RPAREN,
  [4829] = 1,
    ACTIONS(665), 1,
      anon_sym_endif,
  [4833] = 1,
    ACTIONS(785), 1,
      anon_sym_LPAREN_STAR_RPAREN,
  [4837] = 1,
    ACTIONS(787), 1,
      sym_identifier,
  [4841] = 1,
    ACTIONS(789), 1,
      aux_sym_line_comment_token1,
  [4845] = 1,
    ACTIONS(791), 1,
      sym_identifier,
  [4849] = 1,
    ACTIONS(793), 1,
      anon_sym_SQUOTE_SLASH,
  [4853] = 1,
    ACTIONS(795), 1,
      anon_sym_RPAREN,
  [4857] = 1,
    ACTIONS(797), 1,
      anon_sym_DQUOTE,
  [4861] = 1,
    ACTIONS(797), 1,
      anon_sym_SQUOTE,
  [4865] = 1,
    ACTIONS(799), 1,
      anon_sym_RPAREN,
  [4869] = 1,
    ACTIONS(801), 1,
      anon_sym_LBRACE,
  [4873] = 1,
    ACTIONS(803), 1,
      anon_sym_endif,
  [4877] = 1,
    ACTIONS(805), 1,
      sym_identifier,
  [4881] = 1,
    ACTIONS(807), 1,
      sym_identifier,
  [4885] = 1,
    ACTIONS(809), 1,
      sym_identifier,
  [4889] = 1,
    ACTIONS(811), 1,
      sym_identifier,
  [4893] = 1,
    ACTIONS(813), 1,
      aux_sym_block_comment_token1,
  [4897] = 1,
    ACTIONS(815), 1,
      aux_sym_branch_label_token1,
  [4901] = 1,
    ACTIONS(817), 1,
      aux_sym_string_token1,
  [4905] = 1,
    ACTIONS(819), 1,
      aux_sym_string_token2,
  [4909] = 1,
    ACTIONS(821), 1,
      aux_sym_branch_label_token1,
  [4913] = 1,
    ACTIONS(669), 1,
      anon_sym_endif,
  [4917] = 1,
    ACTIONS(823), 1,
      anon_sym_LPAREN,
  [4921] = 1,
    ACTIONS(825), 1,
      ts_builtin_sym_end,
  [4925] = 1,
    ACTIONS(827), 1,
      aux_sym_block_comment_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(44)] = 0,
  [SMALL_STATE(45)] = 56,
  [SMALL_STATE(46)] = 112,
  [SMALL_STATE(47)] = 165,
  [SMALL_STATE(48)] = 218,
  [SMALL_STATE(49)] = 271,
  [SMALL_STATE(50)] = 324,
  [SMALL_STATE(51)] = 374,
  [SMALL_STATE(52)] = 422,
  [SMALL_STATE(53)] = 470,
  [SMALL_STATE(54)] = 518,
  [SMALL_STATE(55)] = 566,
  [SMALL_STATE(56)] = 614,
  [SMALL_STATE(57)] = 662,
  [SMALL_STATE(58)] = 716,
  [SMALL_STATE(59)] = 764,
  [SMALL_STATE(60)] = 812,
  [SMALL_STATE(61)] = 866,
  [SMALL_STATE(62)] = 916,
  [SMALL_STATE(63)] = 964,
  [SMALL_STATE(64)] = 1012,
  [SMALL_STATE(65)] = 1060,
  [SMALL_STATE(66)] = 1108,
  [SMALL_STATE(67)] = 1157,
  [SMALL_STATE(68)] = 1204,
  [SMALL_STATE(69)] = 1251,
  [SMALL_STATE(70)] = 1298,
  [SMALL_STATE(71)] = 1345,
  [SMALL_STATE(72)] = 1392,
  [SMALL_STATE(73)] = 1439,
  [SMALL_STATE(74)] = 1486,
  [SMALL_STATE(75)] = 1533,
  [SMALL_STATE(76)] = 1580,
  [SMALL_STATE(77)] = 1627,
  [SMALL_STATE(78)] = 1674,
  [SMALL_STATE(79)] = 1721,
  [SMALL_STATE(80)] = 1768,
  [SMALL_STATE(81)] = 1815,
  [SMALL_STATE(82)] = 1862,
  [SMALL_STATE(83)] = 1909,
  [SMALL_STATE(84)] = 1956,
  [SMALL_STATE(85)] = 2003,
  [SMALL_STATE(86)] = 2050,
  [SMALL_STATE(87)] = 2097,
  [SMALL_STATE(88)] = 2144,
  [SMALL_STATE(89)] = 2191,
  [SMALL_STATE(90)] = 2238,
  [SMALL_STATE(91)] = 2285,
  [SMALL_STATE(92)] = 2332,
  [SMALL_STATE(93)] = 2379,
  [SMALL_STATE(94)] = 2426,
  [SMALL_STATE(95)] = 2473,
  [SMALL_STATE(96)] = 2520,
  [SMALL_STATE(97)] = 2567,
  [SMALL_STATE(98)] = 2614,
  [SMALL_STATE(99)] = 2661,
  [SMALL_STATE(100)] = 2708,
  [SMALL_STATE(101)] = 2755,
  [SMALL_STATE(102)] = 2802,
  [SMALL_STATE(103)] = 2849,
  [SMALL_STATE(104)] = 2896,
  [SMALL_STATE(105)] = 2943,
  [SMALL_STATE(106)] = 2990,
  [SMALL_STATE(107)] = 3037,
  [SMALL_STATE(108)] = 3089,
  [SMALL_STATE(109)] = 3141,
  [SMALL_STATE(110)] = 3193,
  [SMALL_STATE(111)] = 3245,
  [SMALL_STATE(112)] = 3295,
  [SMALL_STATE(113)] = 3347,
  [SMALL_STATE(114)] = 3399,
  [SMALL_STATE(115)] = 3451,
  [SMALL_STATE(116)] = 3503,
  [SMALL_STATE(117)] = 3554,
  [SMALL_STATE(118)] = 3605,
  [SMALL_STATE(119)] = 3650,
  [SMALL_STATE(120)] = 3695,
  [SMALL_STATE(121)] = 3740,
  [SMALL_STATE(122)] = 3785,
  [SMALL_STATE(123)] = 3833,
  [SMALL_STATE(124)] = 3881,
  [SMALL_STATE(125)] = 3929,
  [SMALL_STATE(126)] = 3973,
  [SMALL_STATE(127)] = 4021,
  [SMALL_STATE(128)] = 4068,
  [SMALL_STATE(129)] = 4094,
  [SMALL_STATE(130)] = 4120,
  [SMALL_STATE(131)] = 4146,
  [SMALL_STATE(132)] = 4172,
  [SMALL_STATE(133)] = 4198,
  [SMALL_STATE(134)] = 4224,
  [SMALL_STATE(135)] = 4250,
  [SMALL_STATE(136)] = 4276,
  [SMALL_STATE(137)] = 4292,
  [SMALL_STATE(138)] = 4308,
  [SMALL_STATE(139)] = 4324,
  [SMALL_STATE(140)] = 4340,
  [SMALL_STATE(141)] = 4356,
  [SMALL_STATE(142)] = 4372,
  [SMALL_STATE(143)] = 4385,
  [SMALL_STATE(144)] = 4407,
  [SMALL_STATE(145)] = 4424,
  [SMALL_STATE(146)] = 4441,
  [SMALL_STATE(147)] = 4458,
  [SMALL_STATE(148)] = 4475,
  [SMALL_STATE(149)] = 4485,
  [SMALL_STATE(150)] = 4495,
  [SMALL_STATE(151)] = 4505,
  [SMALL_STATE(152)] = 4515,
  [SMALL_STATE(153)] = 4525,
  [SMALL_STATE(154)] = 4539,
  [SMALL_STATE(155)] = 4549,
  [SMALL_STATE(156)] = 4559,
  [SMALL_STATE(157)] = 4569,
  [SMALL_STATE(158)] = 4579,
  [SMALL_STATE(159)] = 4589,
  [SMALL_STATE(160)] = 4599,
  [SMALL_STATE(161)] = 4609,
  [SMALL_STATE(162)] = 4619,
  [SMALL_STATE(163)] = 4629,
  [SMALL_STATE(164)] = 4636,
  [SMALL_STATE(165)] = 4643,
  [SMALL_STATE(166)] = 4648,
  [SMALL_STATE(167)] = 4653,
  [SMALL_STATE(168)] = 4660,
  [SMALL_STATE(169)] = 4667,
  [SMALL_STATE(170)] = 4674,
  [SMALL_STATE(171)] = 4681,
  [SMALL_STATE(172)] = 4685,
  [SMALL_STATE(173)] = 4689,
  [SMALL_STATE(174)] = 4693,
  [SMALL_STATE(175)] = 4697,
  [SMALL_STATE(176)] = 4701,
  [SMALL_STATE(177)] = 4705,
  [SMALL_STATE(178)] = 4709,
  [SMALL_STATE(179)] = 4713,
  [SMALL_STATE(180)] = 4717,
  [SMALL_STATE(181)] = 4721,
  [SMALL_STATE(182)] = 4725,
  [SMALL_STATE(183)] = 4729,
  [SMALL_STATE(184)] = 4733,
  [SMALL_STATE(185)] = 4737,
  [SMALL_STATE(186)] = 4741,
  [SMALL_STATE(187)] = 4745,
  [SMALL_STATE(188)] = 4749,
  [SMALL_STATE(189)] = 4753,
  [SMALL_STATE(190)] = 4757,
  [SMALL_STATE(191)] = 4761,
  [SMALL_STATE(192)] = 4765,
  [SMALL_STATE(193)] = 4769,
  [SMALL_STATE(194)] = 4773,
  [SMALL_STATE(195)] = 4777,
  [SMALL_STATE(196)] = 4781,
  [SMALL_STATE(197)] = 4785,
  [SMALL_STATE(198)] = 4789,
  [SMALL_STATE(199)] = 4793,
  [SMALL_STATE(200)] = 4797,
  [SMALL_STATE(201)] = 4801,
  [SMALL_STATE(202)] = 4805,
  [SMALL_STATE(203)] = 4809,
  [SMALL_STATE(204)] = 4813,
  [SMALL_STATE(205)] = 4817,
  [SMALL_STATE(206)] = 4821,
  [SMALL_STATE(207)] = 4825,
  [SMALL_STATE(208)] = 4829,
  [SMALL_STATE(209)] = 4833,
  [SMALL_STATE(210)] = 4837,
  [SMALL_STATE(211)] = 4841,
  [SMALL_STATE(212)] = 4845,
  [SMALL_STATE(213)] = 4849,
  [SMALL_STATE(214)] = 4853,
  [SMALL_STATE(215)] = 4857,
  [SMALL_STATE(216)] = 4861,
  [SMALL_STATE(217)] = 4865,
  [SMALL_STATE(218)] = 4869,
  [SMALL_STATE(219)] = 4873,
  [SMALL_STATE(220)] = 4877,
  [SMALL_STATE(221)] = 4881,
  [SMALL_STATE(222)] = 4885,
  [SMALL_STATE(223)] = 4889,
  [SMALL_STATE(224)] = 4893,
  [SMALL_STATE(225)] = 4897,
  [SMALL_STATE(226)] = 4901,
  [SMALL_STATE(227)] = 4905,
  [SMALL_STATE(228)] = 4909,
  [SMALL_STATE(229)] = 4913,
  [SMALL_STATE(230)] = 4917,
  [SMALL_STATE(231)] = 4921,
  [SMALL_STATE(232)] = 4925,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(222),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(211),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repeat_loop, 5, .production_id = 25),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repeat_loop, 5, .production_id = 25),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repeat_loop, 7, .production_id = 28),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repeat_loop, 7, .production_id = 28),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 3, .production_id = 12),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 4, .production_id = 23),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 4, .production_id = 12),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 5, .production_id = 23),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(131),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(55),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(53),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(164),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(142),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(102),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(106),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(197),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(158),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(159),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(39),
  [140] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(103),
  [143] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(165),
  [146] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(189),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(188),
  [152] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(222),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(157),
  [158] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(143),
  [161] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(183),
  [164] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(211),
  [167] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(224),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(12),
  [173] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(209),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(207),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_branch, 1),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [219] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(132),
  [222] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(120),
  [225] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(187),
  [228] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(19),
  [231] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(129),
  [234] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(121),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(221),
  [240] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(20),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_branch, 3, .production_id = 11),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [249] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(128),
  [252] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(118),
  [255] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(40),
  [258] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(220),
  [261] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(23),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_branch, 2, .production_id = 11),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_branch, 2),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [280] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(133),
  [283] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(119),
  [286] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(223),
  [289] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(30),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [310] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [316] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(212),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [332] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(130),
  [335] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(125),
  [338] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(212),
  [341] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(42),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [346] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 2, .production_id = 6),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 2, .production_id = 6),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 1),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 1),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 5, .production_id = 23),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 5, .production_id = 23),
  [362] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 6, .production_id = 23),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 6, .production_id = 23),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 4, .production_id = 12),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 4, .production_id = 12),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 3, .production_id = 12),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 3, .production_id = 12),
  [374] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 3, .production_id = 16),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 3, .production_id = 16),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_label, 2, .production_id = 18),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_label, 2, .production_id = 18),
  [384] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_node, 2, .production_id = 2),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_node, 2, .production_id = 2),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stop_node, 1),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_node, 1),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow, 3, .production_id = 17),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow, 3, .production_id = 17),
  [396] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_node, 1),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_node, 1),
  [400] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition_expression, 3),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_expression, 3),
  [404] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow, 1, .production_id = 1),
  [406] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow, 1, .production_id = 1),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [412] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition_expression, 4),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_expression, 4),
  [416] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_activity_node, 3, .production_id = 11),
  [418] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_activity_node, 3, .production_id = 11),
  [420] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow, 2, .production_id = 8),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow, 2, .production_id = 8),
  [424] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 2, .production_id = 7),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [428] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 2, .production_id = 7),
  [430] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_label, 1, .production_id = 9),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_label, 1, .production_id = 9),
  [434] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow, 2, .production_id = 10),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow, 2, .production_id = 10),
  [438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_label, 3, .production_id = 21),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_label, 3, .production_id = 21),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stop_node, 2, .production_id = 2),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_node, 2, .production_id = 2),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_activity_element, 1),
  [448] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_activity_element, 1), REDUCE(sym__flow_source, 1),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_activity_element, 1),
  [453] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1),
  [457] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 4, .production_id = 4),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 4, .production_id = 4),
  [461] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_branch_label, 3),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_branch_label, 3),
  [465] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 2),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 2),
  [469] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 4),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 4),
  [473] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_swimlane, 3, .production_id = 4),
  [475] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_swimlane, 3, .production_id = 4),
  [477] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 5),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 5),
  [481] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 6, .production_id = 12),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 6, .production_id = 12),
  [485] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 6, .production_id = 26),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 6, .production_id = 26),
  [489] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 5, .production_id = 4),
  [491] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 5, .production_id = 4),
  [493] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_directive, 2, .production_id = 5),
  [495] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_directive, 2, .production_id = 5),
  [497] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 6, .production_id = 4),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 6, .production_id = 4),
  [501] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 7, .production_id = 22),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 7, .production_id = 22),
  [505] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_skinparam_directive, 3, .production_id = 13),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_skinparam_directive, 3, .production_id = 13),
  [509] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_value, 1),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_value, 1),
  [513] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pragma_directive, 3, .production_id = 14),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pragma_directive, 3, .production_id = 14),
  [517] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_directive, 2, .production_id = 3),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_directive, 2, .production_id = 3),
  [521] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 5, .production_id = 24),
  [523] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 5, .production_id = 24),
  [525] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 3),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 3),
  [529] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_join_node, 2),
  [531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_join_node, 2),
  [533] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 7, .production_id = 12),
  [535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 7, .production_id = 12),
  [537] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 7, .production_id = 27),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 7, .production_id = 27),
  [541] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_floating_note, 7, .production_id = 29),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_floating_note, 7, .production_id = 29),
  [545] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 8, .production_id = 22),
  [547] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 8, .production_id = 22),
  [549] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 6, .production_id = 22),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 6, .production_id = 22),
  [553] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 5, .production_id = 22),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 5, .production_id = 22),
  [557] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 3, .production_id = 6),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 3, .production_id = 6),
  [561] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_line_comment, 2),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_comment, 2),
  [565] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 3, .production_id = 7),
  [567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 3, .production_id = 7),
  [569] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_directive, 1),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note_directive, 1),
  [573] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [577] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 5, .production_id = 12),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 5, .production_id = 12),
  [581] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 3),
  [583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 3),
  [585] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 4, .production_id = 19),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 4, .production_id = 19),
  [589] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 4, .production_id = 12),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 4, .production_id = 12),
  [593] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_type, 1),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_type, 1),
  [597] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fork_node, 1),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fork_node, 1),
  [601] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 4, .production_id = 16),
  [603] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 4, .production_id = 16),
  [605] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_line, 4, .production_id = 20),
  [607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note_line, 4, .production_id = 20),
  [609] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pragma_directive, 2, .production_id = 4),
  [611] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pragma_directive, 2, .production_id = 4),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [633] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [635] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(36),
  [638] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(177),
  [641] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(232),
  [644] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(135),
  [647] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_style, 1),
  [649] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_style, 1),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_diagram, 3),
  [673] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_diagram, 3),
  [675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_diagram, 2),
  [677] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_diagram, 2),
  [679] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_decision_node_repeat1, 2),
  [681] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_decision_node_repeat1, 2), SHIFT_REPEAT(154),
  [684] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_decision_node_repeat1, 2),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [704] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_floating_note_repeat1, 2),
  [706] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_floating_note_repeat1, 2), SHIFT_REPEAT(161),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [731] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_activity_label, 1),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [747] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_spec, 2, .production_id = 15),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [757] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [825] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_plantuml_external_scanner_create(void);
void tree_sitter_plantuml_external_scanner_destroy(void *);
bool tree_sitter_plantuml_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_plantuml_external_scanner_serialize(void *, char *);
void tree_sitter_plantuml_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_plantuml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_plantuml_external_scanner_create,
      tree_sitter_plantuml_external_scanner_destroy,
      tree_sitter_plantuml_external_scanner_scan,
      tree_sitter_plantuml_external_scanner_serialize,
      tree_sitter_plantuml_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
