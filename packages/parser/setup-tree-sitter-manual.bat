@echo off
REM Manual tree-sitter-cli setup script
REM After downloading tree-sitter-windows-x64.gz from GitHub:
REM 1. Extract it to get tree-sitter.exe
REM 2. Place tree-sitter.exe in the same folder as this script
REM 3. Run this script

echo Setting up tree-sitter-cli manually...

REM Create directory structure
mkdir node_modules\tree-sitter-cli 2>nul
mkdir node_modules\.bin 2>nul

REM Copy the binary
if exist tree-sitter.exe (
    echo Copying tree-sitter.exe...
    copy tree-sitter.exe node_modules\tree-sitter-cli\tree-sitter.exe
    copy tree-sitter.exe node_modules\.bin\tree-sitter.exe
    echo.
    echo Success! Testing...
    node_modules\.bin\tree-sitter.exe --version
    echo.
    echo Now you can run: npm test
) else (
    echo ERROR: tree-sitter.exe not found!
    echo.
    echo Please:
    echo 1. Download from: https://github.com/tree-sitter/tree-sitter/releases/download/v0.20.8/tree-sitter-windows-x64.gz
    echo 2. Extract to get tree-sitter.exe
    echo 3. Place it in: packages\parser\
    echo 4. Run this script again
)

pause
