const path = require("path");
const root = path.join(__dirname, "..", "..");

// Try to load the compiled binding
let binding;
try {
  // Try Release build first
  binding = require("../../build/Release/tree_sitter_plantuml_binding.node");
} catch (error1) {
  try {
    // Fallback to Debug build
    binding = require("../../build/Debug/tree_sitter_plantuml_binding.node");
  } catch (error2) {
    // Last resort: use node-gyp-build
    try {
      binding = require("node-gyp-build")(root);
    } catch (error3) {
      throw new Error("Failed to load tree-sitter-plantuml binding. Run `npm run build` first.");
    }
  }
}

// Export the binding and its properties
module.exports = binding;

// Also export language directly if available
if (binding && binding.language) {
  module.exports.language = binding.language;
}

// Export node type info if available
try {
  module.exports.nodeTypeInfo = require("../../src/node-types.json");
} catch (_) {}
