/**
 * Jest Configuration for PlantUML Parser
 *
 * Tests the JavaScript normalizer and integration with the parser
 */

module.exports = {
  // Test environment
  testEnvironment: 'node',

  // Test match patterns
  testMatch: [
    '**/test/normalizer/**/*.test.js',
    '**/test/integration/**/*.test.js'
  ],

  // Coverage collection
  collectCoverageFrom: [
    'src/normalizer/**/*.js',
    '!src/normalizer/rules/**/*.js',
    'index.js'
  ],

  // Coverage thresholds
  coverageThreshold: {
    global: {
      branches: 40,
      functions: 30,
      lines: 40,
      statements: 40
    }
  },

  // Coverage directory
  coverageDirectory: 'coverage',

  // Coverage reporters
  coverageReporters: [
    'text',
    'text-summary',
    'html',
    'lcov'
  ],

  // Ignore patterns
  testPathIgnorePatterns: [
    '/node_modules/',
    '/build/',
    '/bindings/'
  ],

  // Module paths
  moduleDirectories: [
    'node_modules',
    'src'
  ],

  // Verbose output
  verbose: true,

  // Clear mocks automatically
  clearMocks: true,

  // Reset mocks automatically
  resetMocks: true,

  // Restore mocks automatically
  restoreMocks: true,

  // Test timeout (milliseconds)
  testTimeout: 10000
};
