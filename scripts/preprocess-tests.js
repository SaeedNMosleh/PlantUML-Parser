#!/usr/bin/env node

/**
 * Test File Preprocessing Script
 *
 * This script preprocesses all PlantUML test corpus files to add
 * disambiguation markers before running tree-sitter tests.
 *
 * Usage:
 *   node scripts/preprocess-tests.js [--rule=rule1,rule2] [--restore] [--dry-run]
 *
 * Options:
 *   --rule=...    Only apply specific rules (comma-separated)
 *                 Available: start-stop, end-label, floating-note
 *   --restore     Restore original test files from backup
 *   --dry-run     Show what would be changed without modifying files
 *   --debug       Enable debug output
 */

const fs = require('fs');
const path = require('path');
const { PlantUMLPreprocessor } = require('../src/preprocessor');

// Parse command line arguments
const args = process.argv.slice(2);
const options = {
  rules: null,
  restore: false,
  dryRun: false,
  debug: false
};

for (const arg of args) {
  if (arg.startsWith('--rule=')) {
    options.rules = arg.substring(7).split(',');
  } else if (arg === '--restore') {
    options.restore = true;
  } else if (arg === '--dry-run') {
    options.dryRun = true;
  } else if (arg === '--debug') {
    options.debug = true;
  } else if (arg === '--help' || arg === '-h') {
    console.log(`
Test File Preprocessing Script

Usage:
  node scripts/preprocess-tests.js [options]

Options:
  --rule=rule1,rule2   Only apply specific rules (comma-separated)
                       Available: start-stop, end-label, floating-note
                       Default: all rules
  --restore            Restore original test files from backup
  --dry-run            Show what would be changed without modifying files
  --debug              Enable debug output
  --help, -h           Show this help message

Examples:
  # Apply all preprocessing rules
  node scripts/preprocess-tests.js

  # Only apply start-stop rule
  node scripts/preprocess-tests.js --rule=start-stop

  # Dry run to see changes
  node scripts/preprocess-tests.js --dry-run

  # Restore original files
  node scripts/preprocess-tests.js --restore
`);
    process.exit(0);
  }
}

const testDir = path.join(__dirname, '..', 'test', 'corpus', 'activity');
const backupDir = path.join(__dirname, '..', 'test', 'corpus-original', 'activity');

/**
 * Create backup of original test files
 */
function createBackup() {
  if (!fs.existsSync(backupDir)) {
    fs.mkdirSync(backupDir, { recursive: true });
  }

  const files = fs.readdirSync(testDir).filter(f => f.endsWith('.txt'));

  for (const file of files) {
    const sourcePath = path.join(testDir, file);
    const backupPath = path.join(backupDir, file);

    // Only backup if backup doesn't exist (don't overwrite backups)
    if (!fs.existsSync(backupPath)) {
      fs.copyFileSync(sourcePath, backupPath);
      console.log(`✓ Backed up ${file}`);
    }
  }

  console.log(`\nBackup created in: ${backupDir}\n`);
}

/**
 * Restore original test files from backup
 */
function restoreFromBackup() {
  if (!fs.existsSync(backupDir)) {
    console.error('Error: No backup directory found at:', backupDir);
    console.error('Cannot restore original files.');
    process.exit(1);
  }

  const files = fs.readdirSync(backupDir).filter(f => f.endsWith('.txt'));

  for (const file of files) {
    const backupPath = path.join(backupDir, file);
    const targetPath = path.join(testDir, file);

    fs.copyFileSync(backupPath, targetPath);
    console.log(`✓ Restored ${file}`);
  }

  console.log(`\nRestored ${files.length} files from backup\n`);
}

/**
 * Split test file into sections
 * Test files have format:
 *   ===========================
 *   Test Name
 *   ===========================
 *   INPUT_CODE
 *   ----------------------------
 *   EXPECTED_TREE
 *
 * We need to preprocess only the INPUT_CODE sections
 */
function splitTestFile(content) {
  const sections = [];
  const lines = content.split('\n');
  let currentSection = null;
  let sectionType = null;
  let lastSeparatorType = null; // Track what kind of separator we just saw

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];

    // Test separator (===)
    if (/^=+$/.test(line)) {
      if (currentSection) {
        sections.push({ type: sectionType, content: currentSection.join('\n') });
      }
      sections.push({ type: 'separator', content: line });
      currentSection = [];

      // After === separator, next section is either title (first ===) or input (second ===)
      if (lastSeparatorType === 'title-separator') {
        // We just saw the closing === for a title, so next is input code
        sectionType = 'input';
        lastSeparatorType = null;
      } else {
        // This is the opening === for a title
        sectionType = 'title';
        lastSeparatorType = 'title-separator';
      }
      continue;
    }

    // Expected tree separator (---)
    if (/^-+$/.test(line)) {
      if (currentSection) {
        sections.push({ type: sectionType, content: currentSection.join('\n') });
      }
      sections.push({ type: 'tree-separator', content: line });
      currentSection = [];
      sectionType = 'tree';
      lastSeparatorType = 'tree-separator';
      continue;
    }

    // Regular line
    if (currentSection === null) {
      currentSection = [];
      sectionType = 'input';
    }

    currentSection.push(line);
  }

  // Add final section
  if (currentSection && currentSection.length > 0) {
    sections.push({ type: sectionType, content: currentSection.join('\n') });
  }

  return sections;
}

/**
 * Join test file sections back together
 */
function joinTestFile(sections) {
  return sections.map(s => s.content).join('\n');
}

/**
 * Preprocess a single test file
 */
function preprocessTestFile(filePath, preprocessor) {
  const content = fs.readFileSync(filePath, 'utf8');
  const sections = splitTestFile(content);

  let modified = false;
  const stats = {
    inputSections: 0,
    modifiedSections: 0,
    startStopReplacements: 0,
    endLabelAnnotations: 0,
    floatingNoteMarkers: 0
  };

  // Preprocess only INPUT sections
  for (let i = 0; i < sections.length; i++) {
    const section = sections[i];

    if (section.type === 'input') {
      stats.inputSections++;

      // Skip if not PlantUML code (check for @startuml)
      if (!section.content.includes('@startuml')) {
        continue;
      }

      const result = preprocessor.preprocess(section.content);

      if (result.processed !== section.content) {
        sections[i].content = result.processed;
        modified = true;
        stats.modifiedSections++;
        stats.startStopReplacements += result.stats.startStopReplacements;
        stats.endLabelAnnotations += result.stats.endLabelAnnotations;
        stats.floatingNoteMarkers += result.stats.floatingNoteMarkers;
      }
    }
  }

  const processedContent = joinTestFile(sections);

  return {
    modified,
    content: processedContent,
    stats
  };
}

/**
 * Main execution
 */
function main() {
  console.log('PlantUML Test Preprocessing\n');

  // Restore mode
  if (options.restore) {
    console.log('Restoring original test files from backup...\n');
    restoreFromBackup();
    return;
  }

  // Create backup first time
  createBackup();

  // Create preprocessor with specified rules
  const preprocessor = new PlantUMLPreprocessor({
    enabledRules: options.rules || ['start-stop', 'end-label', 'floating-note'],
    debug: options.debug
  });

  console.log('Enabled rules:', preprocessor.enabledRules.join(', '));
  console.log('');

  // Find all test files
  const testFiles = fs.readdirSync(testDir).filter(f => f.endsWith('.txt'));

  const totalStats = {
    filesProcessed: 0,
    filesModified: 0,
    inputSections: 0,
    modifiedSections: 0,
    startStopReplacements: 0,
    endLabelAnnotations: 0,
    floatingNoteMarkers: 0
  };

  // Process each file
  for (const file of testFiles) {
    const filePath = path.join(testDir, file);
    const result = preprocessTestFile(filePath, preprocessor);

    totalStats.filesProcessed++;
    totalStats.inputSections += result.stats.inputSections;
    totalStats.modifiedSections += result.stats.modifiedSections;
    totalStats.startStopReplacements += result.stats.startStopReplacements;
    totalStats.endLabelAnnotations += result.stats.endLabelAnnotations;
    totalStats.floatingNoteMarkers += result.stats.floatingNoteMarkers;

    if (result.modified) {
      totalStats.filesModified++;

      if (options.dryRun) {
        console.log(`[DRY RUN] Would modify: ${file}`);
        console.log(`  Start/Stop: ${result.stats.startStopReplacements}`);
        console.log(`  End Labels: ${result.stats.endLabelAnnotations}`);
        console.log(`  Note Markers: ${result.stats.floatingNoteMarkers}`);
      } else {
        fs.writeFileSync(filePath, result.content);
        console.log(`✓ Processed: ${file}`);
        console.log(`  Start/Stop: ${result.stats.startStopReplacements}`);
        console.log(`  End Labels: ${result.stats.endLabelAnnotations}`);
        console.log(`  Note Markers: ${result.stats.floatingNoteMarkers}`);
      }
    } else {
      console.log(`- Unchanged: ${file}`);
    }
  }

  // Summary
  console.log('\n' + '='.repeat(50));
  console.log('PREPROCESSING SUMMARY');
  console.log('='.repeat(50));
  console.log(`Files processed:       ${totalStats.filesProcessed}`);
  console.log(`Files modified:        ${totalStats.filesModified}`);
  console.log(`Input sections:        ${totalStats.inputSections}`);
  console.log(`Modified sections:     ${totalStats.modifiedSections}`);
  console.log(`Start/Stop replaced:   ${totalStats.startStopReplacements}`);
  console.log(`End labels annotated:  ${totalStats.endLabelAnnotations}`);
  console.log(`Note markers added:    ${totalStats.floatingNoteMarkers}`);

  if (options.dryRun) {
    console.log('\n[DRY RUN] No files were actually modified.');
  } else {
    console.log('\nPreprocessing complete!');
    console.log('Run "npm test" to verify tests pass.');
  }
}

// Run if executed directly
if (require.main === module) {
  try {
    main();
  } catch (error) {
    console.error('Error:', error.message);
    if (options.debug) {
      console.error(error.stack);
    }
    process.exit(1);
  }
}

module.exports = { preprocessTestFile, splitTestFile, joinTestFile };
