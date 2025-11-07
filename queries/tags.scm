; PlantUML symbol extraction queries

; Diagram definitions
(startuml_directive (identifier) @name) @definition.diagram

; Partition definitions
(partition
  name: [(identifier) (quoted_identifier)] @name) @definition.partition

; Activity node labels (for navigation)
(activity_node
  label: (activity_label (text_line) @name)) @definition.activity
