@echo off
echo Building Shooting Gallery...

mkdir build 2>nul

zc build -o build/shooting.exe src/main_window.zc

if errorlevel 1 (
    echo Build failed!
    exit /b 1
)

echo Build successful!
echo Run: build\shooting.exe
