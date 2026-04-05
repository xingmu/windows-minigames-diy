@echo off
REM 024-racing Windows 构建脚本
echo Building 024-racing...

mkdir build 2>nul

zc -O2 -o build/024-racing.exe src/main_window.zc src/platform_api.zc src/platform_api_windows.zc src/game.zc

if exist build\024-racing.exe (
    echo Build successful: build\024-racing.exe
    echo.
    echo 运行游戏: build\024-racing.exe
) else (
    echo Build failed!
    exit /b 1
)
