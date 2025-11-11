; PlantUML syntax highlighting queries

; Directives - using node types instead of literal strings
(startuml_directive) @keyword.directive
(enduml_directive) @keyword.directive

; Keywords
[
  "start"
  "stop"
  "end"
  "if"
  "then"
  "else"
  "elseif"
  "endif"
  "while"
  "endwhile"
  "repeat"
  "fork"
  "again"
  "split"
  "partition"
  "is"
  "of"
] @keyword

; Special statements
(detach_statement) @keyword

; Directives
[
  "title"
  "note"
  "skinparam"
] @keyword.directive

; Note positions - these are matched as string literals in the grammar
; They appear as identifiers in the AST, so we don't highlight them separately

; Operators and punctuation
[":" ";" "->" "-->" "|"] @operator

; Delimiters
["(" ")" "{" "}"] @punctuation.bracket

; Comments
(line_comment) @comment
(block_comment) @comment

; Identifiers
(identifier) @variable

; Labels and text
(activity_label (text_line) @string)
(arrow_label) @string
(condition_expression) @string.special
(swimlane_name) @string
(note_content_line) @string

; Quoted identifiers
(quoted_identifier) @string.special

; Colors
(color) @constant

; Title content
(title_directive content: (text_line) @markup.heading)
