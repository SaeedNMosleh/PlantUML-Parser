Param(
  [Parameter(Mandatory=$true)][string]$Version,
  [Parameter(Mandatory=$true)][string]$OutDir
)

$ErrorActionPreference = 'Stop'

$tag = "v$Version"
$uri = "https://github.com/tree-sitter/tree-sitter/releases/download/$tag/tree-sitter-windows-x64.gz"

# Use proxy from environment if available
$proxy = $null
if ($env:HTTPS_PROXY) { $proxy = $env:HTTPS_PROXY }
elseif ($env:HTTP_PROXY) { $proxy = $env:HTTP_PROXY }
elseif ($env:https_proxy) { $proxy = $env:https_proxy }
elseif ($env:http_proxy) { $proxy = $env:http_proxy }

New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

$tmp = Join-Path $env:TEMP "tree-sitter-$Version-windows-x64.gz"

Write-Host "Downloading $uri"
if ($proxy) {
  Write-Host "Using proxy: $proxy"
  Invoke-WebRequest -Uri $uri -Proxy $proxy -TimeoutSec 60 -OutFile $tmp
} else {
  Invoke-WebRequest -Uri $uri -TimeoutSec 60 -OutFile $tmp
}

$exePath = Join-Path $OutDir 'tree-sitter.exe'

# Decompress .gz -> .exe
$inStream = [System.IO.File]::OpenRead($tmp)
try {
  $gzip = New-Object System.IO.Compression.GzipStream($inStream, [System.IO.Compression.CompressionMode]::Decompress)
  try {
    $outStream = [System.IO.File]::Create($exePath)
    try {
      $buffer = New-Object byte[] 8192
      while (($read = $gzip.Read($buffer, 0, $buffer.Length)) -gt 0) {
        $outStream.Write($buffer, 0, $read)
      }
    } finally {
      $outStream.Dispose()
    }
  } finally {
    $gzip.Dispose()
  }
} finally {
  $inStream.Dispose()
}

Write-Host "Wrote $exePath"

# Create a cmd shim for compatibility with npm's .bin expectations
$cmdPath = Join-Path $OutDir 'tree-sitter.cmd'
$cmd = "@echo off`r`n`"%~dp0tree-sitter.exe`" %*`r`n"
[System.IO.File]::WriteAllText($cmdPath, $cmd, [System.Text.Encoding]::ASCII)
Write-Host "Wrote $cmdPath"

# Smoke test
& $exePath --version | Out-Host
