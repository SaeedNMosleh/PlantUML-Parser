; PlantUML syntax highlighting queries

; Directives
["@startuml" "@enduml"] @keyword.directive

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
  "join"
  "partition"
  "detach"
  "is"
  "of"
] @keyword

; Directives
[
  "title"
  "note"
  "skinparam"
] @keyword.directive

; Note positions
[
  "left"
  "right"
  "top"
  "bottom"
] @keyword.modifier

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
(note_content (text_line) @string)

; Quoted identifiers
(quoted_identifier) @string.special

; Colors
(color) @constant

; Numbers
(number) @number

; Strings
(string) @string

; Title content
(title_directive content: (text_line) @markup.heading)
