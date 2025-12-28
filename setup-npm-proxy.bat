@echo off
REM Permanent NPM and Node.js proxy/SSL configuration for Zscaler
REM Run this script once to configure npm for corporate proxy

echo Configuring NPM for Zscaler proxy...

REM NPM Configuration
npm config set cafile "C:\Users\najafi\Downloads\Zscaler Root CA.crt"
npm config set strict-ssl true
npm config set https-proxy "http://10.144.1.10:8080"
npm config set proxy "http://10.144.1.10:8080"
npm config set registry "https://registry.npmjs.org/"

echo.
echo Setting Windows environment variables for Node.js...

REM Set environment variables for Node.js (used by post-install scripts)
setx NODE_EXTRA_CA_CERTS "C:\Users\najafi\Downloads\Zscaler Root CA.crt"
setx HTTPS_PROXY "http://10.144.1.10:8080"
setx HTTP_PROXY "http://10.144.1.10:8080"

echo.
echo Configuration complete!
echo.
echo NPM settings:
npm config list | findstr /C:"cafile" /C:"strict-ssl" /C:"proxy" /C:"registry"
echo.
echo Environment variables (will apply to new terminals):
echo   NODE_EXTRA_CA_CERTS=C:\Users\najafi\Downloads\Zscaler Root CA.crt
echo   HTTPS_PROXY=http://10.144.1.10:8080
echo   HTTP_PROXY=http://10.144.1.10:8080
echo.
echo IMPORTANT: Close and reopen your terminal for environment variables to take effect.
echo.
echo Test the configuration with:
echo   npm ping
echo.
pause
