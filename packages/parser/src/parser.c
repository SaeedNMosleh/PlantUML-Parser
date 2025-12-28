#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 121
#define LARGE_STATE_COUNT 30
#define SYMBOL_COUNT 91
#define ALIAS_COUNT 0
#define TOKEN_COUNT 56
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 11
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 19

enum {
  sym_identifier = 1,
  sym_startuml_directive = 2,
  sym_enduml_directive = 3,
  anon_sym_start = 4,
  anon_sym_stop = 5,
  anon_sym_COLON = 6,
  anon_sym_SEMI = 7,
  sym_activity_label = 8,
  aux_sym_flow_arrow_token1 = 9,
  anon_sym_DASH_GT = 10,
  anon_sym_DASH_DASH_GT = 11,
  anon_sym_DASH_GT_GT = 12,
  anon_sym_DOT_GT = 13,
  anon_sym_LT_DASH = 14,
  anon_sym_LT_DASH_DASH = 15,
  anon_sym_LT_LT_DASH = 16,
  anon_sym_LT_DOT = 17,
  anon_sym_if = 18,
  anon_sym_then = 19,
  anon_sym_endif = 20,
  anon_sym_elseif = 21,
  anon_sym_else = 22,
  anon_sym_LPAREN = 23,
  aux_sym_condition_token1 = 24,
  anon_sym_RPAREN = 25,
  anon_sym_while = 26,
  anon_sym_is = 27,
  anon_sym_endwhile = 28,
  anon_sym_repeat = 29,
  anon_sym_partition = 30,
  anon_sym_LBRACE = 31,
  anon_sym_RBRACE = 32,
  anon_sym_PIPE = 33,
  sym_swimlane_name = 34,
  aux_sym_fork_node_token1 = 35,
  anon_sym_fork = 36,
  anon_sym_end = 37,
  aux_sym_split_node_token1 = 38,
  anon_sym_split = 39,
  anon_sym_title = 40,
  anon_sym_note = 41,
  anon_sym_left = 42,
  anon_sym_right = 43,
  anon_sym_top = 44,
  anon_sym_bottom = 45,
  aux_sym_note_line_token1 = 46,
  anon_sym_skinparam = 47,
  sym_detach = 48,
  sym_kill = 49,
  anon_sym_DQUOTE = 50,
  aux_sym_string_token1 = 51,
  anon_sym_POUND = 52,
  aux_sym_color_token1 = 53,
  sym_line_comment = 54,
  sym_block_comment = 55,
  sym_source_file = 56,
  sym__element = 57,
  sym_diagram = 58,
  sym__statement = 59,
  sym_activity_element = 60,
  sym_start_node = 61,
  sym_stop_node = 62,
  sym_activity_node = 63,
  sym_flow_arrow = 64,
  sym_arrow_type = 65,
  sym_decision_node = 66,
  sym_elseif_branch = 67,
  sym_else_branch = 68,
  sym_condition = 69,
  sym_branch_label = 70,
  sym_while_loop = 71,
  sym_repeat_loop = 72,
  sym_partition = 73,
  sym_swimlane = 74,
  sym_fork_node = 75,
  sym_join_node = 76,
  sym_split_node = 77,
  sym_split_join_node = 78,
  sym_title_directive = 79,
  sym_note_directive = 80,
  sym_note_position = 81,
  sym_note_line = 82,
  sym_skinparam_directive = 83,
  sym_string = 84,
  sym_color = 85,
  sym_text_content = 86,
  aux_sym_source_file_repeat1 = 87,
  aux_sym_diagram_repeat1 = 88,
  aux_sym_decision_node_repeat1 = 89,
  aux_sym_note_directive_repeat1 = 90,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_startuml_directive] = "startuml_directive",
  [sym_enduml_directive] = "enduml_directive",
  [anon_sym_start] = "start",
  [anon_sym_stop] = "stop",
  [anon_sym_COLON] = ":",
  [anon_sym_SEMI] = ";",
  [sym_activity_label] = "activity_label",
  [aux_sym_flow_arrow_token1] = "arrow_label",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_DASH_DASH_GT] = "-->",
  [anon_sym_DASH_GT_GT] = "->>",
  [anon_sym_DOT_GT] = ".>",
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_LT_DASH_DASH] = "<--",
  [anon_sym_LT_LT_DASH] = "<<-",
  [anon_sym_LT_DOT] = "<.",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_endif] = "endif",
  [anon_sym_elseif] = "elseif",
  [anon_sym_else] = "else",
  [anon_sym_LPAREN] = "(",
  [aux_sym_condition_token1] = "condition_token1",
  [anon_sym_RPAREN] = ")",
  [anon_sym_while] = "while",
  [anon_sym_is] = "is",
  [anon_sym_endwhile] = "endwhile",
  [anon_sym_repeat] = "repeat",
  [anon_sym_partition] = "partition",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_PIPE] = "|",
  [sym_swimlane_name] = "swimlane_name",
  [aux_sym_fork_node_token1] = "fork_node_token1",
  [anon_sym_fork] = "fork",
  [anon_sym_end] = "end",
  [aux_sym_split_node_token1] = "split_node_token1",
  [anon_sym_split] = "split",
  [anon_sym_title] = "title",
  [anon_sym_note] = "note",
  [anon_sym_left] = "left",
  [anon_sym_right] = "right",
  [anon_sym_top] = "top",
  [anon_sym_bottom] = "bottom",
  [aux_sym_note_line_token1] = "note_line_token1",
  [anon_sym_skinparam] = "skinparam",
  [sym_detach] = "detach",
  [sym_kill] = "kill",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_POUND] = "#",
  [aux_sym_color_token1] = "color_token1",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__element] = "_element",
  [sym_diagram] = "diagram",
  [sym__statement] = "_statement",
  [sym_activity_element] = "activity_element",
  [sym_start_node] = "start_node",
  [sym_stop_node] = "stop_node",
  [sym_activity_node] = "activity_node",
  [sym_flow_arrow] = "flow_arrow",
  [sym_arrow_type] = "arrow_type",
  [sym_decision_node] = "decision_node",
  [sym_elseif_branch] = "elseif_branch",
  [sym_else_branch] = "else_branch",
  [sym_condition] = "condition",
  [sym_branch_label] = "branch_label",
  [sym_while_loop] = "while_loop",
  [sym_repeat_loop] = "repeat_loop",
  [sym_partition] = "partition",
  [sym_swimlane] = "swimlane",
  [sym_fork_node] = "fork_node",
  [sym_join_node] = "join_node",
  [sym_split_node] = "split_node",
  [sym_split_join_node] = "split_join_node",
  [sym_title_directive] = "title_directive",
  [sym_note_directive] = "note_directive",
  [sym_note_position] = "note_position",
  [sym_note_line] = "note_line",
  [sym_skinparam_directive] = "skinparam_directive",
  [sym_string] = "string",
  [sym_color] = "color",
  [sym_text_content] = "text_content",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_diagram_repeat1] = "diagram_repeat1",
  [aux_sym_decision_node_repeat1] = "decision_node_repeat1",
  [aux_sym_note_directive_repeat1] = "note_directive_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_startuml_directive] = sym_startuml_directive,
  [sym_enduml_directive] = sym_enduml_directive,
  [anon_sym_start] = anon_sym_start,
  [anon_sym_stop] = anon_sym_stop,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_activity_label] = sym_activity_label,
  [aux_sym_flow_arrow_token1] = aux_sym_flow_arrow_token1,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_DASH_DASH_GT] = anon_sym_DASH_DASH_GT,
  [anon_sym_DASH_GT_GT] = anon_sym_DASH_GT_GT,
  [anon_sym_DOT_GT] = anon_sym_DOT_GT,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_LT_DASH_DASH] = anon_sym_LT_DASH_DASH,
  [anon_sym_LT_LT_DASH] = anon_sym_LT_LT_DASH,
  [anon_sym_LT_DOT] = anon_sym_LT_DOT,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_endif] = anon_sym_endif,
  [anon_sym_elseif] = anon_sym_elseif,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [aux_sym_condition_token1] = aux_sym_condition_token1,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_is] = anon_sym_is,
  [anon_sym_endwhile] = anon_sym_endwhile,
  [anon_sym_repeat] = anon_sym_repeat,
  [anon_sym_partition] = anon_sym_partition,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_swimlane_name] = sym_swimlane_name,
  [aux_sym_fork_node_token1] = aux_sym_fork_node_token1,
  [anon_sym_fork] = anon_sym_fork,
  [anon_sym_end] = anon_sym_end,
  [aux_sym_split_node_token1] = aux_sym_split_node_token1,
  [anon_sym_split] = anon_sym_split,
  [anon_sym_title] = anon_sym_title,
  [anon_sym_note] = anon_sym_note,
  [anon_sym_left] = anon_sym_left,
  [anon_sym_right] = anon_sym_right,
  [anon_sym_top] = anon_sym_top,
  [anon_sym_bottom] = anon_sym_bottom,
  [aux_sym_note_line_token1] = aux_sym_note_line_token1,
  [anon_sym_skinparam] = anon_sym_skinparam,
  [sym_detach] = sym_detach,
  [sym_kill] = sym_kill,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_color_token1] = aux_sym_color_token1,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__element] = sym__element,
  [sym_diagram] = sym_diagram,
  [sym__statement] = sym__statement,
  [sym_activity_element] = sym_activity_element,
  [sym_start_node] = sym_start_node,
  [sym_stop_node] = sym_stop_node,
  [sym_activity_node] = sym_activity_node,
  [sym_flow_arrow] = sym_flow_arrow,
  [sym_arrow_type] = sym_arrow_type,
  [sym_decision_node] = sym_decision_node,
  [sym_elseif_branch] = sym_elseif_branch,
  [sym_else_branch] = sym_else_branch,
  [sym_condition] = sym_condition,
  [sym_branch_label] = sym_branch_label,
  [sym_while_loop] = sym_while_loop,
  [sym_repeat_loop] = sym_repeat_loop,
  [sym_partition] = sym_partition,
  [sym_swimlane] = sym_swimlane,
  [sym_fork_node] = sym_fork_node,
  [sym_join_node] = sym_join_node,
  [sym_split_node] = sym_split_node,
  [sym_split_join_node] = sym_split_join_node,
  [sym_title_directive] = sym_title_directive,
  [sym_note_directive] = sym_note_directive,
  [sym_note_position] = sym_note_position,
  [sym_note_line] = sym_note_line,
  [sym_skinparam_directive] = sym_skinparam_directive,
  [sym_string] = sym_string,
  [sym_color] = sym_color,
  [sym_text_content] = sym_text_content,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_diagram_repeat1] = aux_sym_diagram_repeat1,
  [aux_sym_decision_node_repeat1] = aux_sym_decision_node_repeat1,
  [aux_sym_note_directive_repeat1] = aux_sym_note_directive_repeat1,
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
  [sym_activity_label] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_flow_arrow_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DOT] = {
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
  [aux_sym_condition_token1] = {
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_swimlane_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_fork_node_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_fork] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_split_node_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_split] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_title] = {
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
  [aux_sym_note_line_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_skinparam] = {
    .visible = true,
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
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_color_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
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
  [sym_flow_arrow] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_type] = {
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
  [sym_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_branch_label] = {
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
  [sym_partition] = {
    .visible = true,
    .named = true,
  },
  [sym_swimlane] = {
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
  [sym_split_node] = {
    .visible = true,
    .named = true,
  },
  [sym_split_join_node] = {
    .visible = true,
    .named = true,
  },
  [sym_title_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_note_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_note_position] = {
    .visible = true,
    .named = true,
  },
  [sym_note_line] = {
    .visible = true,
    .named = true,
  },
  [sym_skinparam_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_color] = {
    .visible = true,
    .named = true,
  },
  [sym_text_content] = {
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
  [aux_sym_note_directive_repeat1] = {
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
  field_name = 6,
  field_parameter = 7,
  field_position = 8,
  field_true_label = 9,
  field_type = 10,
  field_value = 11,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_color] = "color",
  [field_condition] = "condition",
  [field_content] = "content",
  [field_end_label] = "end_label",
  [field_label] = "label",
  [field_name] = "name",
  [field_parameter] = "parameter",
  [field_position] = "position",
  [field_true_label] = "true_label",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 2},
  [8] = {.index = 9, .length = 2},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 2},
  [11] = {.index = 15, .length = 2},
  [12] = {.index = 17, .length = 2},
  [13] = {.index = 19, .length = 2},
  [14] = {.index = 21, .length = 1},
  [15] = {.index = 22, .length = 1},
  [16] = {.index = 23, .length = 3},
  [17] = {.index = 26, .length = 3},
  [18] = {.index = 29, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 0},
  [1] =
    {field_name, 1},
  [2] =
    {field_content, 1},
  [3] =
    {field_label, 1},
    {field_type, 0},
  [5] =
    {field_label, 1},
  [6] =
    {field_condition, 1},
  [7] =
    {field_color, 2},
    {field_name, 1},
  [9] =
    {field_parameter, 1},
    {field_value, 2},
  [11] =
    {field_condition, 1},
    {field_end_label, 3},
  [13] =
    {field_content, 3},
    {field_position, 1},
  [15] =
    {field_condition, 1},
    {field_true_label, 3},
  [17] =
    {field_condition, 1},
    {field_label, 3},
  [19] =
    {field_condition, 1},
    {field_end_label, 4},
  [21] =
    {field_condition, 4},
  [22] =
    {field_position, 1},
  [23] =
    {field_condition, 1},
    {field_end_label, 5},
    {field_label, 3},
  [26] =
    {field_condition, 1},
    {field_end_label, 6},
    {field_label, 3},
  [29] =
    {field_condition, 4},
    {field_label, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
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
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
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
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(51);
      if (lookahead == '"') ADVANCE(119);
      if (lookahead == '#') ADVANCE(126);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '(') ADVANCE(75);
      if (lookahead == ')') ADVANCE(82);
      if (lookahead == '-') ADVANCE(15);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(57);
      if (lookahead == ';') ADVANCE(59);
      if (lookahead == '<') ADVANCE(13);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == 'e') ADVANCE(113);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 's') ADVANCE(115);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '|') ADVANCE(85);
      if (lookahead == '}') ADVANCE(84);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == 'e') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == ':') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4)
      if (lookahead == '\'') ADVANCE(64);
      if (lookahead == '/') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != ';') ADVANCE(65);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(126);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '(') ADVANCE(75);
      if (lookahead == '-') ADVANCE(15);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(56);
      if (lookahead == '<') ADVANCE(13);
      if (lookahead == '@') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(113);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 's') ADVANCE(115);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '|') ADVANCE(85);
      if (lookahead == '}') ADVANCE(84);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'f') ADVANCE(41);
      if (lookahead == 's') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 8:
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(127);
      END_STATE();
    case 9:
      if (lookahead == '\'') ADVANCE(10);
      END_STATE();
    case 10:
      if (lookahead == '\'') ADVANCE(16);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\'') ADVANCE(76);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(81);
      END_STATE();
    case 12:
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '/') ADVANCE(88);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(91);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(71);
      if (lookahead == '.') ADVANCE(74);
      if (lookahead == '<') ADVANCE(14);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(73);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '>') ADVANCE(67);
      END_STATE();
    case 16:
      if (lookahead == '/') ADVANCE(129);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 17:
      if (lookahead == '>') ADVANCE(70);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(68);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(29);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(48);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(38);
      if (lookahead == 's') ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == 'g') ADVANCE(21);
      END_STATE();
    case 28:
      if (lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 32:
      if (lookahead == 'k') ADVANCE(93);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(52);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 36:
      if (lookahead == 'm') ADVANCE(33);
      END_STATE();
    case 37:
      if (lookahead == 'm') ADVANCE(34);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 42:
      if (lookahead == 'p') ADVANCE(35);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(19);
      END_STATE();
    case 46:
      if (lookahead == 't') ADVANCE(98);
      END_STATE();
    case 47:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 48:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 49:
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 50:
      if (eof) ADVANCE(51);
      if (lookahead == '"') ADVANCE(119);
      if (lookahead == '#') ADVANCE(126);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '(') ADVANCE(75);
      if (lookahead == ')') ADVANCE(82);
      if (lookahead == '-') ADVANCE(15);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(56);
      if (lookahead == ';') ADVANCE(59);
      if (lookahead == '<') ADVANCE(13);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == 'e') ADVANCE(113);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 's') ADVANCE(115);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '|') ADVANCE(85);
      if (lookahead == '}') ADVANCE(84);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_startuml_directive);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(53);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_startuml_directive);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(54);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_startuml_directive);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_enduml_directive);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(66);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead == '\'') ADVANCE(64);
      if (lookahead == '/') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(65);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead == '\'') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(65);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead == '\'') ADVANCE(63);
      if (lookahead == '\n' ||
          lookahead == ';') ADVANCE(10);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '\n' ||
          lookahead == ';') ADVANCE(10);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead == ';') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_activity_label);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_flow_arrow_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      if (lookahead == '>') ADVANCE(69);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_DASH_GT_GT);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_DOT_GT);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      if (lookahead == '-') ADVANCE(72);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_LT_DASH_DASH);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LT_LT_DASH);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LT_DOT);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead == '\n') ADVANCE(81);
      if (lookahead == ')') ADVANCE(128);
      if (lookahead != 0) ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead == '\'') ADVANCE(76);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(81);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead == '\'') ADVANCE(79);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(81);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead == '\'') ADVANCE(80);
      if (lookahead == ')') ADVANCE(10);
      if (lookahead != 0) ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead == ')') ADVANCE(10);
      if (lookahead == '/') ADVANCE(81);
      if (lookahead != 0) ADVANCE(79);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_condition_token1);
      if (lookahead != 0 &&
          lookahead != ')') ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '|') ADVANCE(128);
      if (lookahead != 0) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '/') ADVANCE(88);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(91);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead == '\'') ADVANCE(89);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(91);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead == '\'') ADVANCE(90);
      if (lookahead == '|') ADVANCE(10);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead == '/') ADVANCE(91);
      if (lookahead == '|') ADVANCE(10);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_swimlane_name);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_fork_node_token1);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_fork);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_fork);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_end);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_end);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_split_node_token1);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_split);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_split);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(101);
      if (lookahead != 0) ADVANCE(100);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead != 0) ADVANCE(100);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == ':') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == 'e') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == '\'') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == 'd') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead == 'n') ADVANCE(106);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_note_line_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(118);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\n') ADVANCE(125);
      if (lookahead == '"') ADVANCE(128);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '"') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(122);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '"') ADVANCE(10);
      if (lookahead == '/') ADVANCE(125);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\'') ADVANCE(120);
      if (lookahead == '/') ADVANCE(124);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(123);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(125);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\'') ADVANCE(121);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_color_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_block_comment);
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
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'k') ADVANCE(5);
      if (lookahead == 'l') ADVANCE(6);
      if (lookahead == 'n') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(8);
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == 's') ADVANCE(10);
      if (lookahead == 't') ADVANCE(11);
      if (lookahead == 'w') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == 'l') ADVANCE(15);
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == 'f') ADVANCE(17);
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == 'k') ADVANCE(25);
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(27);
      if (lookahead == 'i') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(29);
      END_STATE();
    case 12:
      if (lookahead == 'h') ADVANCE(30);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 15:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 20:
      if (lookahead == 'f') ADVANCE(36);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 22:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 23:
      if (lookahead == 'p') ADVANCE(39);
      END_STATE();
    case 24:
      if (lookahead == 'g') ADVANCE(40);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(42);
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 29:
      if (lookahead == 'p') ADVANCE(46);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 31:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 34:
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'w') ADVANCE(52);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 40:
      if (lookahead == 'h') ADVANCE(58);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 43:
      if (lookahead == 'p') ADVANCE(61);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_top);
      END_STATE();
    case 47:
      if (lookahead == 'l') ADVANCE(64);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 49:
      if (lookahead == 'c') ADVANCE(66);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead == 'i') ADVANCE(67);
      END_STATE();
    case 51:
      if (lookahead == 'f') ADVANCE(68);
      END_STATE();
    case 52:
      if (lookahead == 'h') ADVANCE(69);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_kill);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_left);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_note);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 57:
      if (lookahead == 'a') ADVANCE(71);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 59:
      if (lookahead == 'p') ADVANCE(73);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(74);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_stop);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(77);
      END_STATE();
    case 66:
      if (lookahead == 'h') ADVANCE(78);
      END_STATE();
    case 67:
      if (lookahead == 'f') ADVANCE(79);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_endif);
      END_STATE();
    case 69:
      if (lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 70:
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 71:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_right);
      END_STATE();
    case 73:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_start);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_title);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_bottom);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_detach);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_elseif);
      END_STATE();
    case 80:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_repeat);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 85:
      if (lookahead == 'o') ADVANCE(88);
      END_STATE();
    case 86:
      if (lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_endwhile);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 89:
      if (lookahead == 'm') ADVANCE(91);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_partition);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_skinparam);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 5},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 5},
  [15] = {.lex_state = 5},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 5},
  [18] = {.lex_state = 5},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 5},
  [26] = {.lex_state = 5},
  [27] = {.lex_state = 5},
  [28] = {.lex_state = 5},
  [29] = {.lex_state = 5},
  [30] = {.lex_state = 5},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 5},
  [40] = {.lex_state = 5},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 5},
  [43] = {.lex_state = 5},
  [44] = {.lex_state = 5},
  [45] = {.lex_state = 5},
  [46] = {.lex_state = 5},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 5},
  [49] = {.lex_state = 5},
  [50] = {.lex_state = 5},
  [51] = {.lex_state = 5},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 5},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 5},
  [56] = {.lex_state = 5},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 5},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 5},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 5},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 5},
  [73] = {.lex_state = 7},
  [74] = {.lex_state = 7},
  [75] = {.lex_state = 7},
  [76] = {.lex_state = 7},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 7},
  [79] = {.lex_state = 7},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 3},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 6},
  [93] = {.lex_state = 3},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 7},
  [101] = {.lex_state = 7},
  [102] = {.lex_state = 123},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 7},
  [105] = {.lex_state = 7},
  [106] = {.lex_state = 11},
  [107] = {.lex_state = 7},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 11},
  [111] = {.lex_state = 12},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 8},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 7},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 7},
  [119] = {.lex_state = 7},
  [120] = {.lex_state = 7},
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
    [aux_sym_flow_arrow_token1] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_DASH_DASH_GT] = ACTIONS(1),
    [anon_sym_DASH_GT_GT] = ACTIONS(1),
    [anon_sym_DOT_GT] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
    [anon_sym_LT_DASH_DASH] = ACTIONS(1),
    [anon_sym_LT_LT_DASH] = ACTIONS(1),
    [anon_sym_LT_DOT] = ACTIONS(1),
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
    [anon_sym_partition] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [aux_sym_fork_node_token1] = ACTIONS(1),
    [anon_sym_fork] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [aux_sym_split_node_token1] = ACTIONS(1),
    [anon_sym_split] = ACTIONS(1),
    [anon_sym_title] = ACTIONS(1),
    [anon_sym_note] = ACTIONS(1),
    [anon_sym_left] = ACTIONS(1),
    [anon_sym_right] = ACTIONS(1),
    [anon_sym_top] = ACTIONS(1),
    [anon_sym_bottom] = ACTIONS(1),
    [anon_sym_skinparam] = ACTIONS(1),
    [sym_detach] = ACTIONS(1),
    [sym_kill] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(108),
    [sym__element] = STATE(80),
    [sym_diagram] = STATE(80),
    [aux_sym_source_file_repeat1] = STATE(80),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_startuml_directive] = ACTIONS(7),
    [sym_line_comment] = ACTIONS(9),
    [sym_block_comment] = ACTIONS(9),
  },
  [2] = {
    [sym__statement] = STATE(8),
    [sym_activity_element] = STATE(8),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_elseif_branch] = STATE(73),
    [sym_else_branch] = STATE(105),
    [sym_branch_label] = STATE(7),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(8),
    [aux_sym_decision_node_repeat1] = STATE(73),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(23),
    [anon_sym_elseif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_LPAREN] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__statement] = STATE(18),
    [sym_activity_element] = STATE(18),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(18),
    [sym_enduml_directive] = ACTIONS(57),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(57),
    [anon_sym_elseif] = ACTIONS(57),
    [anon_sym_else] = ACTIONS(59),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_is] = ACTIONS(61),
    [anon_sym_endwhile] = ACTIONS(63),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(57),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [4] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_elseif_branch] = STATE(74),
    [sym_else_branch] = STATE(104),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [aux_sym_decision_node_repeat1] = STATE(74),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(65),
    [anon_sym_elseif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [5] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [sym_enduml_directive] = ACTIONS(67),
    [anon_sym_start] = ACTIONS(69),
    [anon_sym_stop] = ACTIONS(72),
    [anon_sym_COLON] = ACTIONS(75),
    [anon_sym_DASH_GT] = ACTIONS(78),
    [anon_sym_DASH_DASH_GT] = ACTIONS(81),
    [anon_sym_DASH_GT_GT] = ACTIONS(81),
    [anon_sym_DOT_GT] = ACTIONS(81),
    [anon_sym_LT_DASH] = ACTIONS(78),
    [anon_sym_LT_DASH_DASH] = ACTIONS(81),
    [anon_sym_LT_LT_DASH] = ACTIONS(81),
    [anon_sym_LT_DOT] = ACTIONS(81),
    [anon_sym_if] = ACTIONS(84),
    [anon_sym_endif] = ACTIONS(67),
    [anon_sym_elseif] = ACTIONS(67),
    [anon_sym_else] = ACTIONS(87),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_endwhile] = ACTIONS(67),
    [anon_sym_repeat] = ACTIONS(92),
    [anon_sym_partition] = ACTIONS(95),
    [anon_sym_RBRACE] = ACTIONS(67),
    [anon_sym_PIPE] = ACTIONS(98),
    [aux_sym_fork_node_token1] = ACTIONS(101),
    [anon_sym_fork] = ACTIONS(104),
    [anon_sym_end] = ACTIONS(107),
    [aux_sym_split_node_token1] = ACTIONS(110),
    [anon_sym_split] = ACTIONS(113),
    [anon_sym_title] = ACTIONS(116),
    [anon_sym_note] = ACTIONS(119),
    [anon_sym_skinparam] = ACTIONS(122),
    [sym_detach] = ACTIONS(125),
    [sym_kill] = ACTIONS(125),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [6] = {
    [sym__statement] = STATE(17),
    [sym_activity_element] = STATE(17),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(17),
    [sym_enduml_directive] = ACTIONS(128),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(128),
    [anon_sym_elseif] = ACTIONS(128),
    [anon_sym_else] = ACTIONS(130),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_endwhile] = ACTIONS(132),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(128),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [7] = {
    [sym__statement] = STATE(4),
    [sym_activity_element] = STATE(4),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_elseif_branch] = STATE(76),
    [sym_else_branch] = STATE(100),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(4),
    [aux_sym_decision_node_repeat1] = STATE(76),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(134),
    [anon_sym_elseif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [8] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_elseif_branch] = STATE(75),
    [sym_else_branch] = STATE(120),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [aux_sym_decision_node_repeat1] = STATE(75),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(136),
    [anon_sym_elseif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [9] = {
    [sym__statement] = STATE(12),
    [sym_activity_element] = STATE(12),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_branch_label] = STATE(10),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(12),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(138),
    [anon_sym_elseif] = ACTIONS(138),
    [anon_sym_else] = ACTIONS(140),
    [anon_sym_LPAREN] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [10] = {
    [sym__statement] = STATE(11),
    [sym_activity_element] = STATE(11),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(11),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(142),
    [anon_sym_elseif] = ACTIONS(142),
    [anon_sym_else] = ACTIONS(144),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [11] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(146),
    [anon_sym_elseif] = ACTIONS(146),
    [anon_sym_else] = ACTIONS(148),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [12] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(150),
    [anon_sym_elseif] = ACTIONS(150),
    [anon_sym_else] = ACTIONS(152),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [13] = {
    [sym__statement] = STATE(19),
    [sym_activity_element] = STATE(19),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_branch_label] = STATE(20),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(19),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(154),
    [anon_sym_LPAREN] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [14] = {
    [sym__statement] = STATE(18),
    [sym_activity_element] = STATE(18),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(18),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_is] = ACTIONS(156),
    [anon_sym_endwhile] = ACTIONS(63),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [15] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(158),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [16] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(160),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [17] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_endwhile] = ACTIONS(164),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [18] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_endwhile] = ACTIONS(166),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [19] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(168),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [20] = {
    [sym__statement] = STATE(15),
    [sym_activity_element] = STATE(15),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(15),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_endif] = ACTIONS(170),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [21] = {
    [sym__statement] = STATE(16),
    [sym_activity_element] = STATE(16),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(16),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(172),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [22] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(174),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [23] = {
    [sym__statement] = STATE(22),
    [sym_activity_element] = STATE(22),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(22),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(176),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [24] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [sym_enduml_directive] = ACTIONS(178),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [25] = {
    [sym__statement] = STATE(17),
    [sym_activity_element] = STATE(17),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(17),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_endwhile] = ACTIONS(132),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(43),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [26] = {
    [sym__statement] = STATE(24),
    [sym_activity_element] = STATE(24),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(24),
    [sym_enduml_directive] = ACTIONS(180),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [27] = {
    [sym__statement] = STATE(29),
    [sym_activity_element] = STATE(29),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(29),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(182),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [28] = {
    [sym__statement] = STATE(29),
    [sym_activity_element] = STATE(29),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(29),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(33),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [29] = {
    [sym__statement] = STATE(5),
    [sym_activity_element] = STATE(5),
    [sym_start_node] = STATE(63),
    [sym_stop_node] = STATE(63),
    [sym_activity_node] = STATE(63),
    [sym_flow_arrow] = STATE(63),
    [sym_arrow_type] = STATE(38),
    [sym_decision_node] = STATE(63),
    [sym_while_loop] = STATE(63),
    [sym_repeat_loop] = STATE(63),
    [sym_partition] = STATE(63),
    [sym_swimlane] = STATE(63),
    [sym_fork_node] = STATE(63),
    [sym_join_node] = STATE(63),
    [sym_split_node] = STATE(63),
    [sym_split_join_node] = STATE(63),
    [sym_title_directive] = STATE(63),
    [sym_note_directive] = STATE(63),
    [sym_skinparam_directive] = STATE(63),
    [aux_sym_diagram_repeat1] = STATE(5),
    [anon_sym_start] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(13),
    [anon_sym_COLON] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(17),
    [anon_sym_DASH_DASH_GT] = ACTIONS(19),
    [anon_sym_DASH_GT_GT] = ACTIONS(19),
    [anon_sym_DOT_GT] = ACTIONS(19),
    [anon_sym_LT_DASH] = ACTIONS(17),
    [anon_sym_LT_DASH_DASH] = ACTIONS(19),
    [anon_sym_LT_LT_DASH] = ACTIONS(19),
    [anon_sym_LT_DOT] = ACTIONS(19),
    [anon_sym_if] = ACTIONS(21),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_repeat] = ACTIONS(184),
    [anon_sym_partition] = ACTIONS(35),
    [anon_sym_PIPE] = ACTIONS(37),
    [aux_sym_fork_node_token1] = ACTIONS(39),
    [anon_sym_fork] = ACTIONS(41),
    [anon_sym_end] = ACTIONS(162),
    [aux_sym_split_node_token1] = ACTIONS(45),
    [anon_sym_split] = ACTIONS(47),
    [anon_sym_title] = ACTIONS(49),
    [anon_sym_note] = ACTIONS(51),
    [anon_sym_skinparam] = ACTIONS(53),
    [sym_detach] = ACTIONS(55),
    [sym_kill] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(190), 1,
      anon_sym_LBRACE,
    ACTIONS(192), 1,
      anon_sym_POUND,
    STATE(39), 1,
      sym_color,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(188), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(186), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [50] = 5,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(50), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(196), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(194), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [97] = 5,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(71), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(200), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(198), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [144] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(204), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(202), 28,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
      anon_sym_POUND,
  [187] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(208), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(206), 28,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_then,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_is,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [230] = 5,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(69), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(212), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(210), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [277] = 5,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(58), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(216), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(214), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [324] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(220), 7,
      anon_sym_COLON,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(218), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      aux_sym_flow_arrow_token1,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [366] = 4,
    ACTIONS(226), 1,
      aux_sym_flow_arrow_token1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(224), 7,
      anon_sym_COLON,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(222), 25,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [410] = 4,
    ACTIONS(232), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(230), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(228), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [454] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(236), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(234), 27,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [496] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(240), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(238), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [537] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(244), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(242), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [578] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(248), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(246), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [619] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(252), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(250), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [660] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(256), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(254), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [701] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(260), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(258), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [742] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(264), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(262), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [783] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(268), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(266), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [824] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(272), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(270), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [865] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(276), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(274), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [906] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(280), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(278), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [947] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(284), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(282), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [988] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(288), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(286), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1029] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(292), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(290), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1070] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(296), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(294), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1111] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(300), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(298), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1152] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(304), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(302), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1193] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(308), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(306), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1234] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(312), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(310), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1275] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(316), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(314), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1316] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(320), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(318), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1357] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(324), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(322), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1398] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(328), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(326), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1439] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(332), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(330), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1480] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(336), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(334), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1521] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(340), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(338), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1562] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(344), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(342), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1603] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(348), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(346), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1644] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(352), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(350), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1685] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(356), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(354), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1726] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(360), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(358), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1767] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(364), 6,
      anon_sym_DASH_GT,
      anon_sym_LT_DASH,
      anon_sym_else,
      anon_sym_fork,
      anon_sym_end,
      anon_sym_split,
    ACTIONS(362), 26,
      sym_enduml_directive,
      anon_sym_start,
      anon_sym_stop,
      anon_sym_COLON,
      anon_sym_DASH_DASH_GT,
      anon_sym_DASH_GT_GT,
      anon_sym_DOT_GT,
      anon_sym_LT_DASH_DASH,
      anon_sym_LT_LT_DASH,
      anon_sym_LT_DOT,
      anon_sym_if,
      anon_sym_endif,
      anon_sym_elseif,
      anon_sym_while,
      anon_sym_endwhile,
      anon_sym_repeat,
      anon_sym_partition,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_fork_node_token1,
      aux_sym_split_node_token1,
      anon_sym_title,
      anon_sym_note,
      anon_sym_skinparam,
      sym_detach,
      sym_kill,
  [1808] = 6,
    ACTIONS(25), 1,
      anon_sym_elseif,
    ACTIONS(27), 1,
      anon_sym_else,
    ACTIONS(136), 1,
      anon_sym_endif,
    STATE(120), 1,
      sym_else_branch,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(78), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [1829] = 6,
    ACTIONS(25), 1,
      anon_sym_elseif,
    ACTIONS(27), 1,
      anon_sym_else,
    ACTIONS(366), 1,
      anon_sym_endif,
    STATE(115), 1,
      sym_else_branch,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(78), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [1850] = 6,
    ACTIONS(25), 1,
      anon_sym_elseif,
    ACTIONS(27), 1,
      anon_sym_else,
    ACTIONS(368), 1,
      anon_sym_endif,
    STATE(107), 1,
      sym_else_branch,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(78), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [1871] = 6,
    ACTIONS(25), 1,
      anon_sym_elseif,
    ACTIONS(27), 1,
      anon_sym_else,
    ACTIONS(65), 1,
      anon_sym_endif,
    STATE(104), 1,
      sym_else_branch,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(78), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [1892] = 4,
    ACTIONS(370), 1,
      ts_builtin_sym_end,
    ACTIONS(372), 1,
      sym_startuml_directive,
    ACTIONS(375), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(77), 3,
      sym__element,
      sym_diagram,
      aux_sym_source_file_repeat1,
  [1908] = 5,
    ACTIONS(378), 1,
      anon_sym_endif,
    ACTIONS(380), 1,
      anon_sym_elseif,
    ACTIONS(383), 1,
      anon_sym_else,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(78), 2,
      sym_elseif_branch,
      aux_sym_decision_node_repeat1,
  [1926] = 3,
    STATE(83), 1,
      sym_note_position,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(385), 4,
      anon_sym_left,
      anon_sym_right,
      anon_sym_top,
      anon_sym_bottom,
  [1940] = 4,
    ACTIONS(7), 1,
      sym_startuml_directive,
    ACTIONS(387), 1,
      ts_builtin_sym_end,
    ACTIONS(389), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(77), 3,
      sym__element,
      sym_diagram,
      aux_sym_source_file_repeat1,
  [1956] = 4,
    ACTIONS(391), 1,
      anon_sym_end,
    ACTIONS(393), 1,
      aux_sym_note_line_token1,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(82), 2,
      sym_note_line,
      aux_sym_note_directive_repeat1,
  [1971] = 4,
    ACTIONS(397), 1,
      anon_sym_end,
    ACTIONS(399), 1,
      aux_sym_note_line_token1,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(82), 2,
      sym_note_line,
      aux_sym_note_directive_repeat1,
  [1986] = 4,
    ACTIONS(393), 1,
      aux_sym_note_line_token1,
    ACTIONS(402), 1,
      anon_sym_COLON,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(81), 2,
      sym_note_line,
      aux_sym_note_directive_repeat1,
  [2001] = 3,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    STATE(119), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2012] = 3,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    STATE(101), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2023] = 3,
    ACTIONS(406), 1,
      aux_sym_note_line_token1,
    STATE(60), 1,
      sym_text_content,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2034] = 2,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(408), 2,
      anon_sym_COLON,
      aux_sym_note_line_token1,
  [2043] = 3,
    ACTIONS(406), 1,
      aux_sym_note_line_token1,
    STATE(45), 1,
      sym_text_content,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2054] = 1,
    ACTIONS(410), 4,
      ts_builtin_sym_end,
      sym_startuml_directive,
      sym_line_comment,
      sym_block_comment,
  [2061] = 1,
    ACTIONS(412), 4,
      ts_builtin_sym_end,
      sym_startuml_directive,
      sym_line_comment,
      sym_block_comment,
  [2068] = 3,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(25), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2079] = 3,
    ACTIONS(414), 1,
      anon_sym_fork,
    ACTIONS(416), 1,
      anon_sym_split,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2090] = 3,
    ACTIONS(406), 1,
      aux_sym_note_line_token1,
    STATE(59), 1,
      sym_text_content,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2101] = 2,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(418), 2,
      anon_sym_end,
      aux_sym_note_line_token1,
  [2110] = 3,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym_branch_label,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2121] = 3,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    STATE(3), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2132] = 3,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    STATE(14), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2143] = 3,
    ACTIONS(420), 1,
      anon_sym_DQUOTE,
    STATE(30), 1,
      sym_string,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2154] = 2,
    ACTIONS(422), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2162] = 2,
    ACTIONS(65), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2170] = 2,
    ACTIONS(424), 1,
      anon_sym_then,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2178] = 2,
    ACTIONS(426), 1,
      aux_sym_string_token1,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2186] = 2,
    ACTIONS(428), 1,
      anon_sym_PIPE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2194] = 2,
    ACTIONS(366), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2202] = 2,
    ACTIONS(136), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2210] = 2,
    ACTIONS(430), 1,
      aux_sym_condition_token1,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2218] = 2,
    ACTIONS(432), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2226] = 2,
    ACTIONS(434), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2234] = 2,
    ACTIONS(436), 1,
      sym_activity_label,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2242] = 2,
    ACTIONS(438), 1,
      aux_sym_condition_token1,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2250] = 2,
    ACTIONS(440), 1,
      sym_swimlane_name,
    ACTIONS(395), 2,
      sym_line_comment,
      sym_block_comment,
  [2258] = 2,
    ACTIONS(442), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2266] = 2,
    ACTIONS(444), 1,
      aux_sym_color_token1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2274] = 2,
    ACTIONS(446), 1,
      anon_sym_DQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2282] = 2,
    ACTIONS(448), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2290] = 2,
    ACTIONS(450), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2298] = 2,
    ACTIONS(452), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2306] = 2,
    ACTIONS(454), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2314] = 2,
    ACTIONS(456), 1,
      anon_sym_then,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [2322] = 2,
    ACTIONS(368), 1,
      anon_sym_endif,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(30)] = 0,
  [SMALL_STATE(31)] = 50,
  [SMALL_STATE(32)] = 97,
  [SMALL_STATE(33)] = 144,
  [SMALL_STATE(34)] = 187,
  [SMALL_STATE(35)] = 230,
  [SMALL_STATE(36)] = 277,
  [SMALL_STATE(37)] = 324,
  [SMALL_STATE(38)] = 366,
  [SMALL_STATE(39)] = 410,
  [SMALL_STATE(40)] = 454,
  [SMALL_STATE(41)] = 496,
  [SMALL_STATE(42)] = 537,
  [SMALL_STATE(43)] = 578,
  [SMALL_STATE(44)] = 619,
  [SMALL_STATE(45)] = 660,
  [SMALL_STATE(46)] = 701,
  [SMALL_STATE(47)] = 742,
  [SMALL_STATE(48)] = 783,
  [SMALL_STATE(49)] = 824,
  [SMALL_STATE(50)] = 865,
  [SMALL_STATE(51)] = 906,
  [SMALL_STATE(52)] = 947,
  [SMALL_STATE(53)] = 988,
  [SMALL_STATE(54)] = 1029,
  [SMALL_STATE(55)] = 1070,
  [SMALL_STATE(56)] = 1111,
  [SMALL_STATE(57)] = 1152,
  [SMALL_STATE(58)] = 1193,
  [SMALL_STATE(59)] = 1234,
  [SMALL_STATE(60)] = 1275,
  [SMALL_STATE(61)] = 1316,
  [SMALL_STATE(62)] = 1357,
  [SMALL_STATE(63)] = 1398,
  [SMALL_STATE(64)] = 1439,
  [SMALL_STATE(65)] = 1480,
  [SMALL_STATE(66)] = 1521,
  [SMALL_STATE(67)] = 1562,
  [SMALL_STATE(68)] = 1603,
  [SMALL_STATE(69)] = 1644,
  [SMALL_STATE(70)] = 1685,
  [SMALL_STATE(71)] = 1726,
  [SMALL_STATE(72)] = 1767,
  [SMALL_STATE(73)] = 1808,
  [SMALL_STATE(74)] = 1829,
  [SMALL_STATE(75)] = 1850,
  [SMALL_STATE(76)] = 1871,
  [SMALL_STATE(77)] = 1892,
  [SMALL_STATE(78)] = 1908,
  [SMALL_STATE(79)] = 1926,
  [SMALL_STATE(80)] = 1940,
  [SMALL_STATE(81)] = 1956,
  [SMALL_STATE(82)] = 1971,
  [SMALL_STATE(83)] = 1986,
  [SMALL_STATE(84)] = 2001,
  [SMALL_STATE(85)] = 2012,
  [SMALL_STATE(86)] = 2023,
  [SMALL_STATE(87)] = 2034,
  [SMALL_STATE(88)] = 2043,
  [SMALL_STATE(89)] = 2054,
  [SMALL_STATE(90)] = 2061,
  [SMALL_STATE(91)] = 2068,
  [SMALL_STATE(92)] = 2079,
  [SMALL_STATE(93)] = 2090,
  [SMALL_STATE(94)] = 2101,
  [SMALL_STATE(95)] = 2110,
  [SMALL_STATE(96)] = 2121,
  [SMALL_STATE(97)] = 2132,
  [SMALL_STATE(98)] = 2143,
  [SMALL_STATE(99)] = 2154,
  [SMALL_STATE(100)] = 2162,
  [SMALL_STATE(101)] = 2170,
  [SMALL_STATE(102)] = 2178,
  [SMALL_STATE(103)] = 2186,
  [SMALL_STATE(104)] = 2194,
  [SMALL_STATE(105)] = 2202,
  [SMALL_STATE(106)] = 2210,
  [SMALL_STATE(107)] = 2218,
  [SMALL_STATE(108)] = 2226,
  [SMALL_STATE(109)] = 2234,
  [SMALL_STATE(110)] = 2242,
  [SMALL_STATE(111)] = 2250,
  [SMALL_STATE(112)] = 2258,
  [SMALL_STATE(113)] = 2266,
  [SMALL_STATE(114)] = 2274,
  [SMALL_STATE(115)] = 2282,
  [SMALL_STATE(116)] = 2290,
  [SMALL_STATE(117)] = 2298,
  [SMALL_STATE(118)] = 2306,
  [SMALL_STATE(119)] = 2314,
  [SMALL_STATE(120)] = 2322,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repeat_loop, 5, .production_id = 14),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repeat_loop, 5, .production_id = 14),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(54),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(55),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(109),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(37),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(37),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(85),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(97),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(28),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(98),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(111),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(72),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(72),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(92),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(48),
  [113] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(48),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(88),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(79),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(116),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_diagram_repeat1, 2), SHIFT_REPEAT(63),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_repeat_loop, 7, .production_id = 18),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_repeat_loop, 7, .production_id = 18),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_branch, 3, .production_id = 6),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 3, .production_id = 6),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_branch, 4, .production_id = 12),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 4, .production_id = 12),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_branch, 5, .production_id = 12),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 5, .production_id = 12),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_branch, 4, .production_id = 6),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_branch, 4, .production_id = 6),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_branch, 1),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_branch, 3, .production_id = 5),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_branch, 2),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_branch, 2, .production_id = 5),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 2, .production_id = 2),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 2, .production_id = 2),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 6, .production_id = 12),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 6, .production_id = 12),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 4, .production_id = 6),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 4, .production_id = 6),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 3),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition, 3),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 3, .production_id = 6),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 3, .production_id = 6),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 5, .production_id = 12),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 5, .production_id = 12),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_type, 1),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_type, 1),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 1, .production_id = 1),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 1, .production_id = 1),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 3, .production_id = 7),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 3, .production_id = 7),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color, 2),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_color, 2),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 4, .production_id = 6),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 4, .production_id = 6),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 6, .production_id = 6),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 6, .production_id = 6),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_split_join_node, 2),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_split_join_node, 2),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_content, 1),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text_content, 1),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_directive, 2, .production_id = 3),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_directive, 2, .production_id = 3),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 8, .production_id = 11),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 8, .production_id = 11),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 5, .production_id = 6),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 5, .production_id = 6),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_split_node, 1),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_split_node, 1),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flow_arrow, 2, .production_id = 4),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_flow_arrow, 2, .production_id = 4),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 7, .production_id = 17),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 7, .production_id = 17),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_activity_node, 3, .production_id = 5),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_activity_node, 3, .production_id = 5),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 7, .production_id = 6),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 7, .production_id = 6),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 7, .production_id = 11),
  [288] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 7, .production_id = 11),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_node, 1),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_node, 1),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_node, 1),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stop_node, 1),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_swimlane, 3, .production_id = 2),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_swimlane, 3, .production_id = 2),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 6, .production_id = 7),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 6, .production_id = 7),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 6, .production_id = 16),
  [308] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 6, .production_id = 16),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note_directive, 4, .production_id = 10),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_directive, 4, .production_id = 10),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_skinparam_directive, 3, .production_id = 8),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_skinparam_directive, 3, .production_id = 8),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_join_node, 2),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_join_node, 2),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 5, .production_id = 11),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 5, .production_id = 11),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_activity_element, 1),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_activity_element, 1),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decision_node, 6, .production_id = 11),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decision_node, 6, .production_id = 11),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_branch_label, 3),
  [336] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_branch_label, 3),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note_directive, 5, .production_id = 15),
  [340] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_directive, 5, .production_id = 15),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 4, .production_id = 2),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 4, .production_id = 2),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 5, .production_id = 7),
  [348] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 5, .production_id = 7),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 4, .production_id = 9),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 4, .production_id = 9),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition, 5, .production_id = 2),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_partition, 5, .production_id = 2),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 5, .production_id = 13),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_loop, 5, .production_id = 13),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fork_node, 1),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fork_node, 1),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [375] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(77),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_decision_node_repeat1, 2),
  [380] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_decision_node_repeat1, 2), SHIFT_REPEAT(84),
  [383] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_decision_node_repeat1, 2),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [391] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [393] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [395] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [397] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_note_directive_repeat1, 2),
  [399] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_note_directive_repeat1, 2), SHIFT_REPEAT(94),
  [402] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [406] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [408] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_position, 1),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_diagram, 3),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_diagram, 2),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [418] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note_line, 1),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [430] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [434] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [436] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [438] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [440] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
