; PlantUML syntax highlighting queries

; Directives - using node types instead of literal strings
(startuml_directive) @keyword.directive
(enduml_directive) @keyword.directive

; Node-based keywords
(start_node) @keyword
(stop_node) @keyword
(detach) @keyword
(kill) @keyword

; Keywords (anonymous tokens)
[
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
  "split"
  "partition"
  "is"
] @keyword

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
(activity_label) @string
(arrow_label) @string
(condition) @string.special
(swimlane_name) @string
(note_line) @string
(text_content) @string

; Quoted identifiers
(string) @string.special

; Colors
(color) @constant

; Title content
(title_directive content: (text_content) @markup.heading)
