/*
 * PlantUML Tree-sitter External Scanner
 *
 * MEMORY SAFETY REQUIREMENTS:
 * ==========================
 * This scanner MUST maintain strict memory safety to prevent system crashes.
 *
 * CRITICAL RULES:
 * 1. NEVER advance the lexer and then return false - this corrupts lexer state
 * 2. ALWAYS check for NULL before dereferencing pointers
 * 3. ALWAYS validate buffer bounds before array access
 * 4. ALWAYS check EOF before advancing lexer in loops
 * 5. NEVER assume tree-sitter will restore lexer state - YOU must manage it
 *
 * Tree-sitter Contract:
 * - When scan() returns true: tree-sitter keeps the advanced lexer position
 * - When scan() returns false: tree-sitter restores lexer to entry position
 * - Helper functions that advance lexer DO NOT automatically restore state
 * - Scanner owns the state returned by create() and must free it in destroy()
 *
 * Memory Ownership:
 * - create() allocates Scanner struct - MUST be freed in destroy()
 * - Tree-sitter owns the lexer, buffer, and valid_symbols - DO NOT free them
 * - serialize() writes to tree-sitter's buffer - respect TREE_SITTER_SERIALIZATION_BUFFER_SIZE
 */

#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// Maximum iterations for whitespace skipping (safety backstop to prevent infinite loops)
#define MAX_WHITESPACE_CHARS 10000

// Tree-sitter's serialization buffer size (usually 1024 bytes)
#define TREE_SITTER_SERIALIZATION_BUFFER_SIZE 1024

// Token types (MUST match order in grammar.js externals array)
enum TokenType {
  NOTE_CONTENT_LINE,  // Index 0: Content line inside floating notes
  ERROR_SENTINEL      // Index 1: Marker for error recovery
};

// Scanner state
// MEMORY: This struct is allocated by create(), owned by tree-sitter, freed by destroy()
typedef struct {
  bool in_floating_note;  // Track if we're inside a floating note block
} Scanner;

/*
 * Helper: Skip whitespace characters safely
 *
 * MEMORY SAFETY:
 * - Checks EOF before every advance to prevent reading beyond buffer
 * - Has maximum iteration limit to prevent infinite loops
 * - Only advances on commit (skip = false) to preserve state for lookahead
 *
 * @param lexer: Tree-sitter lexer (owned by tree-sitter, DO NOT free)
 * @param skip: If true, mark consumed chars as skipped (don't include in token)
 */
static void skip_whitespace(TSLexer *lexer, bool skip) {
  // SAFETY: Prevent infinite loops with maximum iteration count
  uint32_t iterations = 0;

  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    // SAFETY: Check EOF before advancing
    if (lexer->eof(lexer)) {
      break;
    }

    // SAFETY: Enforce maximum iterations to prevent infinite loops
    if (++iterations > MAX_WHITESPACE_CHARS) {
      // This should never happen with valid input, but prevents crashes
      break;
    }

    lexer->advance(lexer, skip);
  }
}

/*
 * Helper: Advance lexer (non-skipped)
 *
 * MEMORY SAFETY:
 * - Does NOT check EOF - caller must check before calling
 * - Use this only when you've verified lookahead is valid
 *
 * @param lexer: Tree-sitter lexer (owned by tree-sitter, DO NOT free)
 */
static inline void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

/*
 * Check if "end" keyword is at current position (non-destructive peek)
 *
 * MEMORY SAFETY:
 * - This function is SAFE because it does NOT advance the lexer at all
 * - Only examines lexer->lookahead which is always safe to read
 * - Cannot corrupt lexer state because it never modifies position
 *
 * NOTE: This only checks the CURRENT position's lookahead.
 * It cannot look multiple characters ahead without advancing,
 * which would corrupt state. Therefore, we only check for 'e' (start of "end")
 *
 * @param lexer: Tree-sitter lexer (owned by tree-sitter, DO NOT free)
 * @return: true if lookahead is 'e' (potential start of "end" keyword)
 */
static bool is_potential_end_keyword(TSLexer *lexer) {
  // SAFETY: Only reading lookahead, never advancing
  // This cannot corrupt lexer state
  return lexer->lookahead == 'e';
}

/*
 * Create scanner state
 *
 * MEMORY SAFETY:
 * - Allocates Scanner struct with calloc (zero-initialized)
 * - Returns NULL on allocation failure (caller must handle)
 * - Tree-sitter takes ownership and will call destroy() to free
 *
 * @return: Allocated Scanner or NULL on failure
 */
void *tree_sitter_plantuml_external_scanner_create() {
  // SAFETY: Use calloc to zero-initialize memory
  Scanner *scanner = (Scanner *)calloc(1, sizeof(Scanner));

  // SAFETY: Check allocation success
  if (scanner == NULL) {
    // Allocation failed - return NULL
    // Tree-sitter must handle NULL scanner gracefully
    return NULL;
  }

  // Initialize state (calloc already zeroed memory, but be explicit)
  scanner->in_floating_note = false;

  return scanner;
}

/*
 * Destroy scanner state
 *
 * MEMORY SAFETY:
 * - Frees Scanner allocated by create()
 * - NULL check before free (defensive, free(NULL) is safe but be explicit)
 * - DO NOT call free() twice on same pointer (double-free crash)
 * - After this call, pointer is invalid - tree-sitter must not use it again
 *
 * @param payload: Scanner pointer from create() (may be NULL if create failed)
 */
void tree_sitter_plantuml_external_scanner_destroy(void *payload) {
  // SAFETY: Check for NULL before freeing
  // While free(NULL) is safe per C standard, explicit check is clearer
  if (payload == NULL) {
    return;
  }

  Scanner *scanner = (Scanner *)payload;

  // SAFETY: Free allocated memory
  // After this, scanner pointer is INVALID - must not be used
  free(scanner);
}

/*
 * Serialize scanner state for backtracking
 *
 * MEMORY SAFETY:
 * - Buffer is owned by tree-sitter (DO NOT free it)
 * - Buffer size is TREE_SITTER_SERIALIZATION_BUFFER_SIZE (usually 1024 bytes)
 * - MUST validate buffer is large enough before writing
 * - Returns number of bytes written (must be <= buffer size)
 *
 * Tree-sitter uses this to save parser state for backtracking.
 * If parsing fails, it can restore to this saved state.
 *
 * @param payload: Scanner pointer (may be NULL)
 * @param buffer: Tree-sitter's buffer to write state (owned by tree-sitter, DO NOT free)
 * @return: Number of bytes written to buffer (0 on error)
 */
unsigned tree_sitter_plantuml_external_scanner_serialize(
    void *payload,
    char *buffer
) {
  // SAFETY: Validate inputs before dereferencing
  if (payload == NULL) {
    // Cannot serialize NULL scanner - return 0 bytes
    return 0;
  }

  if (buffer == NULL) {
    // Cannot write to NULL buffer - return 0 bytes
    return 0;
  }

  Scanner *scanner = (Scanner *)payload;

  // SAFETY: Validate buffer has space for our data
  // We need 1 byte for in_floating_note flag
  const unsigned bytes_needed = 1;

  // SAFETY: Compile-time assertion that our serialization fits in tree-sitter's buffer
  // Note: We use a macro check instead of _Static_assert for MSVC compatibility
  #if defined(_MSC_VER)
    // MSVC: Use static_assert (available in C11/C++11 mode)
    static_assert(1 <= 1024, "Serialization size exceeds tree-sitter buffer size");
  #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    // C11 and later: Use _Static_assert
    _Static_assert(1 <= 1024, "Serialization size exceeds tree-sitter buffer size");
  #else
    // Older compilers: Use compile-time array size trick
    // If assertion fails, this creates a negative array size -> compile error
    typedef char assert_serialization_fits[(1 <= 1024) ? 1 : -1];
  #endif

  // Write state to buffer
  // SAFETY: We validated buffer is non-NULL and large enough
  buffer[0] = scanner->in_floating_note ? 1 : 0;

  return bytes_needed;
}

/*
 * Deserialize scanner state from buffer
 *
 * MEMORY SAFETY:
 * - Buffer is owned by tree-sitter (DO NOT free it)
 * - MUST validate length before accessing buffer
 * - MUST validate buffer is non-NULL before accessing
 * - Always reset state first (defensive programming)
 *
 * Tree-sitter calls this to restore parser state when backtracking.
 *
 * @param payload: Scanner pointer (may be NULL)
 * @param buffer: Tree-sitter's buffer containing saved state (owned by tree-sitter, DO NOT free)
 * @param length: Number of bytes in buffer
 */
void tree_sitter_plantuml_external_scanner_deserialize(
    void *payload,
    const char *buffer,
    unsigned length
) {
  // SAFETY: Validate scanner pointer
  if (payload == NULL) {
    // Cannot deserialize to NULL scanner
    return;
  }

  Scanner *scanner = (Scanner *)payload;

  // SAFETY: Always reset state first (defensive programming)
  // This ensures consistent state even if deserialization fails
  scanner->in_floating_note = false;

  // SAFETY: Validate buffer and length before accessing
  const unsigned bytes_needed = 1;

  if (buffer == NULL) {
    // NULL buffer - keep default state
    return;
  }

  if (length < bytes_needed) {
    // Buffer too small - keep default state
    return;
  }

  // SAFETY: We validated buffer is non-NULL and has enough bytes
  // Restore state from buffer
  scanner->in_floating_note = (buffer[0] != 0);
}

/*
 * Main scanning function
 *
 * MEMORY SAFETY CRITICAL:
 * - If you advance the lexer and return false, YOU CORRUPT THE LEXER STATE
 * - Tree-sitter restores lexer position when you return false, but only to the
 *   position when scan() was CALLED, not to before helper functions advanced it
 * - NEVER call helper functions that advance and then return false
 * - ALWAYS commit to consuming what you've advanced before returning true
 *
 * Token Recognition Strategy:
 * - We recognize NOTE_CONTENT_LINE tokens for floating note content
 * - We do NOT try to peek ahead for "end note" - that corrupts state
 * - Instead, we consume lines one at a time
 * - The grammar's repeat() naturally stops when it hits "end" keyword
 * - Tree-sitter's GLR parser handles the ambiguity correctly
 *
 * @param payload: Scanner pointer (may be NULL)
 * @param lexer: Tree-sitter lexer (owned by tree-sitter, DO NOT free)
 * @param valid_symbols: Array of bools indicating which tokens are valid
 * @return: true if token was recognized, false otherwise
 */
bool tree_sitter_plantuml_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
  // SAFETY: Validate scanner pointer
  if (payload == NULL) {
    // Cannot scan with NULL scanner - reject
    return false;
  }

  Scanner *scanner = (Scanner *)payload;

  // SAFETY: Validate valid_symbols array is non-NULL
  if (valid_symbols == NULL) {
    // Cannot check valid tokens with NULL array - reject
    return false;
  }

  // SAFETY: Validate lexer pointer
  if (lexer == NULL) {
    // Cannot scan with NULL lexer - reject
    return false;
  }

  // Error recovery: During error recovery, tree-sitter sets ERROR_SENTINEL
  // SAFETY: Check array bounds - ERROR_SENTINEL is index 1
  // We assume valid_symbols has at least 2 elements (indices 0 and 1)
  // This is guaranteed by our grammar.js externals array
  if (valid_symbols[ERROR_SENTINEL]) {
    // During error recovery, clear our state to prevent cascading failures
    // SAFETY: scanner is validated non-NULL above
    scanner->in_floating_note = false;
    return false;
  }

  // Handle NOTE_CONTENT_LINE token
  // SAFETY: Check array bounds - NOTE_CONTENT_LINE is index 0
  if (valid_symbols[NOTE_CONTENT_LINE]) {
    // CRITICAL: We must check BEFORE skipping whitespace
    // If we skip whitespace and then return false, we corrupt lexer state!

    // First, check if at EOF or empty line WITHOUT advancing
    // SAFETY: eof() and lookahead are always safe to check
    if (lexer->eof(lexer)) {
      // EOF - not a content line
      // SAFETY: We haven't advanced lexer, so returning false is safe
      return false;
    }

    // Check for empty line (just newline)
    if (lexer->lookahead == '\n') {
      // Empty line - not a content line
      // SAFETY: We haven't advanced lexer, so returning false is safe
      return false;
    }

    // Check if we're at "end note" - only check for 'e' at start of line
    // followed by 'n', 'd', ' ', 'n', 'o', 't', 'e'
    if (lexer->lookahead == 'e') {
      // Might be "end note" - don't consume it, let grammar handle it
      // SAFETY: We haven't advanced lexer, so returning false is safe
      return false;
    }

    // Check if line starts with ':' - this indicates an inline note or label, not content
    // SAFETY: Only reading lookahead, never advancing
    if (lexer->lookahead == ':') {
      // This is likely a note_line (note left: content) not a floating_note content
      // SAFETY: We haven't advanced lexer, so returning false is safe
      return false;
    }

    // Check if line starts with '<' - this indicates a preprocessor marker, not content
    // SAFETY: Only reading lookahead, never advancing
    if (lexer->lookahead == '<') {
      // This is a preprocessor marker (<NOTE_CONTENT_BEGIN> or <NOTE_CONTENT_END>)
      // Let the grammar handle it
      // SAFETY: We haven't advanced lexer, so returning false is safe
      return false;
    }

    // Check for whitespace-only lines
    // We need to peek ahead to see if there's content after whitespace
    // But we CAN'T advance to check! So we'll consume whitespace as part of the content
    // The grammar can handle leading whitespace in note content

    // Consume line content until newline or EOF
    // SAFETY: EOF check prevents reading beyond buffer
    uint32_t iterations = 0;
    while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
      // SAFETY: Prevent infinite loops
      if (++iterations > MAX_WHITESPACE_CHARS * 10) {
        // Line is too long - something is wrong
        // Return true with what we have to avoid infinite loop
        break;
      }

      // SAFETY: We checked EOF and lookahead before advancing
      advance(lexer);
    }

    // Mark end of token (before newline)
    // SAFETY: lexer is validated non-NULL above
    lexer->mark_end(lexer);

    // Optionally consume the newline (include in token but not in content)
    // SAFETY: Check before advancing
    if (!lexer->eof(lexer) && lexer->lookahead == '\n') {
      advance(lexer);
    }

    // Successfully recognized NOTE_CONTENT_LINE token
    // SAFETY: We advanced the lexer and are returning true - this commits the advance
    lexer->result_symbol = NOTE_CONTENT_LINE;
    return true;
  }

  // No valid tokens recognized
  // SAFETY: We never advanced lexer in this path, so returning false is safe
  return false;
}
