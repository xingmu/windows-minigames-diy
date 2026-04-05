@echo off
REM Zen-C Golf Game Windows Build Script

echo Building Golf...

mkdir build 2>nul

REM 使用 Zen-C 编译器编译
zc -O2 -o build\golf.exe src\main_window.zc src\game_logic.zc src\platform_api.zc src\platform_api_windows.zc src\game.zc

if errorlevel 1 (
    echo Build failed!
    exit /b 1
)

echo Build successful! Output: build\golf.exe
