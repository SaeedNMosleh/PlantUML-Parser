# Corporate Proxy Setup for NPM (Zscaler)

## Current Working Configuration

Your npm is already configured correctly! Here's what's set:

```bash
https-proxy = "http://10.144.1.10:8080"
proxy = "http://10.144.1.10:8080"
registry = "https://registry.npmjs.org/"
strict-ssl = true
```

## Problem Identified

**Issue:** Post-install scripts (like `tree-sitter-cli`) make their own HTTPS requests and don't inherit npm's certificate settings.

**Root Cause:** When npm packages run post-install scripts, they use Node.js directly, which needs separate environment variable configuration.

## Complete Solution

### Option 1: Permanent System-Wide Fix (Recommended)

Run the setup script once:

```bash
setup-npm-proxy.bat
```

This sets:
1. NPM configuration (already done)
2. Windows environment variables for Node.js
3. Applies to all new terminal sessions

**Then restart your terminal!**

If you use VS Code, fully restart VS Code too so its integrated terminals inherit the new environment variables.

### Option 2: Per-Session Fix (Current Workaround)

For immediate use without restarting:

```bash
# Set for current session (CMD)
set NODE_EXTRA_CA_CERTS=C:\Users\najafi\Downloads\Zscaler Root CA.crt
set HTTPS_PROXY=http://10.144.1.10:8080
set HTTP_PROXY=http://10.144.1.10:8080

# Set for current session (PowerShell)
$env:NODE_EXTRA_CA_CERTS = "C:\Users\najafi\Downloads\Zscaler Root CA.crt"
$env:HTTPS_PROXY = "http://10.144.1.10:8080"
$env:HTTP_PROXY = "http://10.144.1.10:8080"
$env:NO_PROXY = "localhost,127.0.0.1"

# Then run npm install
npm install
```

### Option 3: Disable SSL Verification (Not Recommended)

Only use when absolutely necessary:

```bash
npm install --strict-ssl=false
```

**Security Warning:** This disables certificate validation entirely!

## What Works Now

✅ **npm install** - Works (no `--strict-ssl=false` needed)
✅ **npm registry access** - Works
✅ **Most packages** - Install successfully

⚠️ **tree-sitter-cli** - Downloads from GitHub (often blocked by Zscaler). The repo treats it as optional so installs can still succeed; grammar development commands may require a manual install.

## Solution for tree-sitter-cli

Manual installation (already done!):

1. Download: https://github.com/tree-sitter/tree-sitter/releases/download/v0.20.8/tree-sitter-windows-x64.gz
2. Extract to get `tree-sitter.exe`
3. Place in: `packages/parser/node_modules/.bin/tree-sitter.exe`

## Testing the Configuration

```bash
# Test npm registry connection
npm ping --loglevel verbose

# Best registry health check (often more reliable than ping behind proxies)
npm view lodash version

# Test package installation
npm install lodash

# Test with tree-sitter-cli (will still need manual download)
npm install tree-sitter-cli
```

## Files Created

- `setup-npm-proxy.bat` - One-time system configuration
- `packages/parser/setup-tree-sitter-manual.bat` - Manual tree-sitter setup

## Environment Variables Needed

For permanent fix, set these in Windows:

```
NODE_EXTRA_CA_CERTS=C:\Users\najafi\Downloads\Zscaler Root CA.crt
HTTPS_PROXY=http://10.144.1.10:8080
HTTP_PROXY=http://10.144.1.10:8080
```

## Verification

Check current settings:

```bash
# NPM config (workspace-safe)
npm --workspaces=false config get strict-ssl --location=user
npm --workspaces=false config get https-proxy --location=user
npm --workspaces=false config get proxy --location=user
npm --workspaces=false config get registry --location=user

# Environment variables (CMD)
echo %NODE_EXTRA_CA_CERTS%
echo %HTTPS_PROXY%

# Environment variables (PowerShell)
echo $env:NODE_EXTRA_CA_CERTS
echo $env:HTTPS_PROXY
```

### Important: Don't set `npm config cafile` to the Zscaler Root CA

It can break TLS validation for public endpoints with:

```text
UNABLE_TO_GET_ISSUER_CERT_LOCALLY
```

Use `NODE_EXTRA_CA_CERTS` (and optionally `NODE_OPTIONS=--use-system-ca`) instead.

## Alternative: Use pnpm or yarn

These package managers handle proxies differently and might work better with your corporate proxy:

```bash
npm install -g pnpm
pnpm install  # May handle certificates better
```

## Summary

**Current Status (Target):**

- ✅ npm registry access works with `strict-ssl=true`
- ✅ Node-based postinstall scripts trust Zscaler via `NODE_EXTRA_CA_CERTS`
- ✅ `npm ping` works (or at least fails fast with useful logs)
