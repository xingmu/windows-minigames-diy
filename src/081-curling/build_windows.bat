@echo off
REM Zen-C Curling Game Windows Build Script

echo Building Curling...

mkdir build 2>nul

zc build -o build\curling.exe src\main_window.zc

if %ERRORLEVEL% == 0 (
    echo Build successful!
    echo Output: build\curling.exe
) else (
    echo Build failed!
)

pause
