#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const http = require('http');

// PlantUML server configuration
const PLANTUML_SERVER = process.env.PLANTUML_SERVER || 'http://localhost:8080';
const TEST_CORPUS_DIR = path.join(__dirname, '../test/corpus');

// Colors for terminal output
const colors = {
  reset: '\x1b[0m',
  green: '\x1b[32m',
  red: '\x1b[31m',
  yellow: '\x1b[33m',
  blue: '\x1b[34m',
  bold: '\x1b[1m',
};

/**
 * Extract PlantUML test cases from a corpus file
 */
function extractTestCases(filePath, fileContent) {
  const testCases = [];
  const lines = fileContent.split('\n');
  let i = 0;

  while (i < lines.length) {
    // Find test case separator (===)
    if (lines[i].startsWith('===')) {
      i++;
      const testName = lines[i] ? lines[i].trim() : 'Unnamed Test';
      i++;

      // Skip the closing === line
      if (lines[i] && lines[i].startsWith('===')) {
        i++;
      }

      // Extract PlantUML code until --- separator
      const codeLines = [];
      while (i < lines.length && !lines[i].startsWith('---')) {
        codeLines.push(lines[i]);
        i++;
      }

      const code = codeLines.join('\n').trim();

      // Only add if it contains PlantUML code
      if (code.includes('@startuml')) {
        testCases.push({
          name: testName,
          code: code,
          file: path.relative(TEST_CORPUS_DIR, filePath),
        });
      }

      // Skip the expected output section
      while (i < lines.length && !lines[i].startsWith('===')) {
        i++;
      }
    } else {
      i++;
    }
  }

  return testCases;
}

/**
 * Read all test corpus files
 */
function readAllTestCases() {
  const allTestCases = [];

  function scanDirectory(dir) {
    const entries = fs.readdirSync(dir, { withFileTypes: true });

    for (const entry of entries) {
      const fullPath = path.join(dir, entry.name);

      if (entry.isDirectory()) {
        scanDirectory(fullPath);
      } else if (entry.isFile() && entry.name.endsWith('.txt')) {
        const content = fs.readFileSync(fullPath, 'utf-8');
        const testCases = extractTestCases(fullPath, content);
        allTestCases.push(...testCases);
      }
    }
  }

  scanDirectory(TEST_CORPUS_DIR);
  return allTestCases;
}

/**
 * Validate PlantUML code against server using txt endpoint
 */
async function validatePlantUML(code) {
  return new Promise((resolve, reject) => {
    // URL encode the PlantUML code
    const encodedCode = encodeURIComponent(code);
    const url = `${PLANTUML_SERVER}/plantuml/txt`;

    const postData = encodedCode;
    const urlObj = new URL(url);

    const options = {
      hostname: urlObj.hostname,
      port: urlObj.port || 8080,
      path: urlObj.pathname,
      method: 'POST',
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Content-Length': Buffer.byteLength(postData),
      },
    };

    const req = http.request(options, (res) => {
      let data = '';

      res.on('data', (chunk) => {
        data += chunk;
      });

      res.on('end', () => {
        resolve({
          statusCode: res.statusCode,
          body: data,
        });
      });
    });

    req.on('error', (error) => {
      reject(error);
    });

    req.write(postData);
    req.end();
  });
}

/**
 * Check if PlantUML server is ready
 */
async function waitForServer(maxAttempts = 30) {
  for (let i = 0; i < maxAttempts; i++) {
    try {
      const response = await new Promise((resolve, reject) => {
        const urlObj = new URL(PLANTUML_SERVER);
        const options = {
          hostname: urlObj.hostname,
          port: urlObj.port || 8080,
          path: '/',
          method: 'GET',
          timeout: 2000,
        };

        const req = http.request(options, (res) => {
          resolve({ statusCode: res.statusCode });
        });

        req.on('error', reject);
        req.on('timeout', () => {
          req.destroy();
          reject(new Error('Timeout'));
        });

        req.end();
      });

      if (response.statusCode === 200 || response.statusCode === 302) {
        console.log(`${colors.green}✓ PlantUML server is ready${colors.reset}`);
        return true;
      }
    } catch (error) {
      // Server not ready yet
    }

    if (i < maxAttempts - 1) {
      await new Promise(resolve => setTimeout(resolve, 1000));
    }
  }

  throw new Error('PlantUML server did not become ready in time');
}

/**
 * Check if response indicates a syntax error
 */
function checkForErrors(response) {
  const body = response.body;

  // Check for common error indicators in PlantUML output
  if (response.statusCode !== 200) {
    return {
      hasError: true,
      message: `HTTP ${response.statusCode}: Server error`,
    };
  }

  // PlantUML txt endpoint returns error messages in the output
  const errorPatterns = [
    /Syntax Error/i,
    /cannot parse/i,
    /Unexpected token/i,
    /Unknown.*command/i,
    /Error line \d+/i,
  ];

  for (const pattern of errorPatterns) {
    if (pattern.test(body)) {
      // Extract error message
      const lines = body.split('\n').filter(line => line.trim());
      return {
        hasError: true,
        message: lines.slice(0, 5).join('\n'), // First 5 lines of error
      };
    }
  }

  // If response is too short, it might be an error
  if (body.trim().length < 10) {
    return {
      hasError: true,
      message: 'Empty or invalid response from PlantUML server',
    };
  }

  return { hasError: false };
}

/**
 * Main validation function
 */
async function main() {
  console.log(`${colors.bold}PlantUML Test Corpus Validation${colors.reset}\n`);
  console.log(`Server: ${PLANTUML_SERVER}`);
  console.log(`Test Corpus: ${TEST_CORPUS_DIR}\n`);

  // Wait for PlantUML server to be ready
  console.log('Waiting for PlantUML server...');
  try {
    await waitForServer();
  } catch (error) {
    console.error(`${colors.red}✗ Failed to connect to PlantUML server${colors.reset}`);
    console.error(`  Make sure the server is running at ${PLANTUML_SERVER}`);
    process.exit(1);
  }

  // Read all test cases
  console.log('\nReading test cases...');
  const testCases = readAllTestCases();
  console.log(`Found ${testCases.length} test cases\n`);

  if (testCases.length === 0) {
    console.log(`${colors.yellow}Warning: No test cases found${colors.reset}`);
    process.exit(0);
  }

  // Validate each test case
  console.log(`${colors.bold}Validating test cases...${colors.reset}\n`);

  const results = {
    valid: [],
    invalid: [],
    errors: [],
  };

  for (let i = 0; i < testCases.length; i++) {
    const testCase = testCases[i];
    const progress = `[${i + 1}/${testCases.length}]`;

    process.stdout.write(`${progress} ${testCase.name} (${testCase.file})... `);

    try {
      const response = await validatePlantUML(testCase.code);
      const errorCheck = checkForErrors(response);

      if (errorCheck.hasError) {
        console.log(`${colors.red}✗ INVALID${colors.reset}`);
        results.invalid.push({
          ...testCase,
          error: errorCheck.message,
        });
      } else {
        console.log(`${colors.green}✓ Valid${colors.reset}`);
        results.valid.push(testCase);
      }
    } catch (error) {
      console.log(`${colors.red}✗ ERROR${colors.reset}`);
      results.errors.push({
        ...testCase,
        error: error.message,
      });
    }

    // Small delay to avoid overwhelming the server
    await new Promise(resolve => setTimeout(resolve, 100));
  }

  // Print summary
  console.log('\n' + '='.repeat(70));
  console.log(`${colors.bold}Validation Summary${colors.reset}\n`);
  console.log(`${colors.green}Valid:${colors.reset}   ${results.valid.length}/${testCases.length} (${(results.valid.length / testCases.length * 100).toFixed(1)}%)`);
  console.log(`${colors.red}Invalid:${colors.reset} ${results.invalid.length}/${testCases.length}`);
  console.log(`${colors.red}Errors:${colors.reset}  ${results.errors.length}/${testCases.length}`);

  // Print details of invalid test cases
  if (results.invalid.length > 0) {
    console.log('\n' + '='.repeat(70));
    console.log(`${colors.bold}${colors.red}Invalid Test Cases:${colors.reset}\n`);

    for (const test of results.invalid) {
      console.log(`${colors.bold}${test.name}${colors.reset} (${test.file})`);
      console.log(`${colors.yellow}Error:${colors.reset}`);
      console.log(test.error.split('\n').map(line => '  ' + line).join('\n'));
      console.log('');
    }
  }

  // Print details of errors
  if (results.errors.length > 0) {
    console.log('\n' + '='.repeat(70));
    console.log(`${colors.bold}${colors.red}Validation Errors:${colors.reset}\n`);

    for (const test of results.errors) {
      console.log(`${colors.bold}${test.name}${colors.reset} (${test.file})`);
      console.log(`${colors.yellow}Error:${colors.reset} ${test.error}`);
      console.log('');
    }
  }

  // Exit with appropriate code
  if (results.invalid.length > 0 || results.errors.length > 0) {
    console.log(`${colors.red}${colors.bold}Validation FAILED${colors.reset}`);
    process.exit(1);
  } else {
    console.log(`${colors.green}${colors.bold}All test cases are valid PlantUML!${colors.reset}`);
    process.exit(0);
  }
}

// Run the validation
main().catch((error) => {
  console.error(`${colors.red}Unexpected error:${colors.reset}`, error);
  process.exit(1);
});
