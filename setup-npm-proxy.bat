@echo off
REM Permanent NPM and Node.js proxy/SSL configuration for Zscaler
REM Run this script once to configure npm for corporate proxy

setlocal

REM NOTE:
REM Do NOT set `npm config cafile` to the Zscaler root CA.
REM npm treats `cafile` as the full CA bundle, which can break TLS validation
REM for public endpoints (e.g. registry.npmjs.org) with errors like:
REM   UNABLE_TO_GET_ISSUER_CERT_LOCALLY
REM Instead, keep npm using Node/system CAs and add Zscaler via NODE_EXTRA_CA_CERTS.

echo Configuring NPM for Zscaler proxy...

REM NPM Configuration
REM Use --workspaces=false to avoid ENOWORKSPACES in monorepos
REM Use --location=user so it applies to all repos on this laptop
npm --workspaces=false config delete cafile --location=user >nul 2>&1
npm --workspaces=false config set strict-ssl true --location=user
npm --workspaces=false config set https-proxy "http://10.144.1.10:8080" --location=user
npm --workspaces=false config set proxy "http://10.144.1.10:8080" --location=user
npm --workspaces=false config set registry "https://registry.npmjs.org/" --location=user

echo.
echo Setting Windows environment variables for Node.js...

REM Set environment variables for Node.js (used by post-install scripts)
setx NODE_EXTRA_CA_CERTS "C:\Users\najafi\Downloads\Zscaler Root CA.crt"
setx HTTPS_PROXY "http://10.144.1.10:8080"
setx HTTP_PROXY "http://10.144.1.10:8080"

REM Some tools only read lowercase variants
setx https_proxy "http://10.144.1.10:8080"
setx http_proxy "http://10.144.1.10:8080"

REM Avoid proxying local traffic
setx NO_PROXY "localhost,127.0.0.1"
setx no_proxy "localhost,127.0.0.1"

REM Optional: make Node trust the Windows cert store too (Node v22+)
REM If you already use NODE_OPTIONS, append manually instead of overwriting.
setx NODE_OPTIONS "--use-system-ca"

echo.
echo Configuration complete!
echo.
echo NPM settings:
npm --workspaces=false config list --location=user | findstr /C:"strict-ssl" /C:"proxy" /C:"registry" /C:"cafile"
echo.
echo Environment variables (will apply to new terminals):
echo   NODE_EXTRA_CA_CERTS=C:\Users\najafi\Downloads\Zscaler Root CA.crt
echo   HTTPS_PROXY=http://10.144.1.10:8080
echo   HTTP_PROXY=http://10.144.1.10:8080
echo   NO_PROXY=localhost,127.0.0.1
echo   NODE_OPTIONS=--use-system-ca
echo.
echo IMPORTANT: Close and reopen your terminal for environment variables to take effect.
echo If you use VS Code, fully restart VS Code so its integrated terminals inherit the new env vars.
echo.
echo Test the configuration with:
echo   npm ping
echo.
pause

endlocal
