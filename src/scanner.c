#include <tree_sitter/parser.h>
#include <string.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * PlantUML Tree-sitter Scanner
 *
 * This scanner handles context-sensitive tokens that cannot be parsed
 * by the grammar alone. It works in conjunction with the semantic preprocessor
 * which adds disambiguation markers to guide token recognition.
 */

enum TokenType {
  // Markers from preprocessor
  START_MARKER,       // «START»
  STOP_MARKER,        // «STOP»
  LABEL_MARKER,       // «LABEL»
  CONTENT_START,      // «CONTENT_START»
  CONTENT_END,        // «CONTENT_END»
  ARROW_LABEL_MARKER, // «ARROW_LABEL»
  ACTIVITY_MARKER,    // «ACTIVITY»
  CONDITION_MARKER,   // «CONDITION»
  LOOP_LABEL_MARKER,  // «LOOP_LABEL»

  // Multiline content
  NOTE_CONTENT_LINE,  // Content lines within note blocks

  // Error recovery
  ERROR_SENTINEL
};

// Scanner state structure
typedef struct {
  bool in_note_block;
  bool in_content_block;
  int bracket_depth;
  int paren_depth;
} Scanner;

// Helper function to advance the lexer
static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

// Helper function to skip whitespace
static void skip_whitespace(TSLexer *lexer) {
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    advance(lexer);
  }
}

// Helper function to match a string
static bool match_string(TSLexer *lexer, const char *str) {
  const char *p = str;
  while (*p) {
    if (lexer->lookahead != *p) {
      return false;
    }
    advance(lexer);
    p++;
  }
  return true;
}

// Helper function to peek ahead for a string without advancing
static bool peek_string(TSLexer *lexer, const char *str, int offset) {
  // Note: This is a simplified peek - full implementation would need proper lookahead
  return false; // Simplified for now
}

// Helper function to check for a marker
static bool check_marker(TSLexer *lexer, const char *marker) {
  // Markers use « and » which are multi-byte UTF-8 characters
  // « is 0xC2 0xAB
  // » is 0xC2 0xBB

  if (lexer->lookahead == 0xAB) { // Check for «
    TSLexer *saved = lexer;
    advance(lexer);

    // Try to match the marker content
    const char *p = marker;
    while (*p) {
      if (lexer->lookahead != *p) {
        return false;
      }
      advance(lexer);
      p++;
    }

    // Check for closing »
    if (lexer->lookahead == 0xBB) {
      advance(lexer);
      return true;
    }
  }

  return false;
}

// Helper to read until end of line
static void read_line(TSLexer *lexer) {
  while (lexer->lookahead && lexer->lookahead != '\n') {
    advance(lexer);
  }
}

// Main scanner function
void *tree_sitter_plantuml_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->in_note_block = false;
  scanner->in_content_block = false;
  scanner->bracket_depth = 0;
  scanner->paren_depth = 0;
  return scanner;
}

void tree_sitter_plantuml_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  free(scanner);
}

unsigned tree_sitter_plantuml_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  buffer[0] = scanner->in_note_block;
  buffer[1] = scanner->in_content_block;
  buffer[2] = scanner->bracket_depth;
  buffer[3] = scanner->paren_depth;
  return 4;
}

void tree_sitter_plantuml_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  if (length >= 4) {
    scanner->in_note_block = buffer[0];
    scanner->in_content_block = buffer[1];
    scanner->bracket_depth = buffer[2];
    scanner->paren_depth = buffer[3];
  }
}

bool tree_sitter_plantuml_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // Skip leading whitespace
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    lexer->advance(lexer, true);
  }

  // Check for UTF-8 marker start (« character)
  // « in UTF-8 is 0xC2 0xAB (194 171)
  // » in UTF-8 is 0xC2 0xBB (194 187)

  // First check if we see the start of a UTF-8 sequence for «
  if (lexer->lookahead == 194) { // 0xC2
    lexer->mark_end(lexer);
    advance(lexer);

    if (lexer->lookahead == 171) { // 0xAB - This is «
      advance(lexer);

      // Now we're past the «, check what marker follows

      // START marker
      if (valid_symbols[START_MARKER] && match_string(lexer, "START")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) { // 0xBB - This is »
            advance(lexer);
            lexer->result_symbol = START_MARKER;
            return true;
          }
        }
      }

      // Reset and try STOP marker
      if (valid_symbols[STOP_MARKER] && match_string(lexer, "STOP")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) { // 0xBB - This is »
            advance(lexer);
            lexer->result_symbol = STOP_MARKER;
            return true;
          }
        }
      }

      // LABEL marker
      if (valid_symbols[LABEL_MARKER] && match_string(lexer, "LABEL")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            lexer->result_symbol = LABEL_MARKER;
            return true;
          }
        }
      }

      // LOOP_LABEL marker
      if (valid_symbols[LOOP_LABEL_MARKER] && match_string(lexer, "LOOP_LABEL")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            lexer->result_symbol = LOOP_LABEL_MARKER;
            return true;
          }
        }
      }

      // CONTENT_START marker
      if (valid_symbols[CONTENT_START] && match_string(lexer, "CONTENT_START")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            scanner->in_content_block = true;
            lexer->result_symbol = CONTENT_START;
            return true;
          }
        }
      }

      // CONTENT_END marker
      if (valid_symbols[CONTENT_END] && match_string(lexer, "CONTENT_END")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            scanner->in_content_block = false;
            lexer->result_symbol = CONTENT_END;
            return true;
          }
        }
      }

      // ACTIVITY marker
      if (valid_symbols[ACTIVITY_MARKER] && match_string(lexer, "ACTIVITY")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            lexer->result_symbol = ACTIVITY_MARKER;
            return true;
          }
        }
      }

      // ARROW_LABEL marker
      if (valid_symbols[ARROW_LABEL_MARKER] && match_string(lexer, "ARROW_LABEL")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            lexer->result_symbol = ARROW_LABEL_MARKER;
            return true;
          }
        }
      }

      // CONDITION marker
      if (valid_symbols[CONDITION_MARKER] && match_string(lexer, "CONDITION")) {
        if (lexer->lookahead == 194) {
          advance(lexer);
          if (lexer->lookahead == 187) {
            advance(lexer);
            lexer->result_symbol = CONDITION_MARKER;
            return true;
          }
        }
      }
    }
  }

  // Handle note content lines when in a content block
  if (scanner->in_content_block && valid_symbols[NOTE_CONTENT_LINE]) {
    // Check if we're about to see CONTENT_END marker
    if (lexer->lookahead == 194) { // Might be start of «CONTENT_END»
      // Don't consume it, let the CONTENT_END handler above deal with it
      return false;
    }

    // Otherwise, consume the line as note content
    lexer->mark_end(lexer);

    while (lexer->lookahead && lexer->lookahead != '\n') {
      // Also check for CONTENT_END marker while reading
      if (lexer->lookahead == 194) {
        // Might be the start of a marker, stop here
        break;
      }
      advance(lexer);
    }

    if (lexer->lookahead != 194) { // If we didn't stop for a potential marker
      lexer->mark_end(lexer);
      lexer->result_symbol = NOTE_CONTENT_LINE;
      return true;
    }
  }

  // Error recovery
  if (valid_symbols[ERROR_SENTINEL]) {
    if (lexer->lookahead == 0) { // EOF
      lexer->result_symbol = ERROR_SENTINEL;
      return true;
    }
  }

  return false;
}