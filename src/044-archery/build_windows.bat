@echo off
echo Building Archery Game...

mkdir build 2>nul

zc build -o build/archery.exe src/main_window.zc

if errorlevel 1 (
    echo Build failed!
    exit /b 1
)

echo Build successful!
echo Run: build\archery.exe
