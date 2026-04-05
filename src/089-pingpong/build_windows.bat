@echo off
REM 089-Pingpong Windows Build Script
REM 乒乓球街机版

echo Building 089-Pingpong...

REM 检查 Zen-C 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: Zen-C compiler (zc) not found in PATH
    echo Please install Zen-C compiler first
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 编译所有源文件
echo Compiling main_window.zc...
zc -target windows -o build\main_window.c src\main_window.zc

echo Compiling game.zc...
zc -target windows -o build\game.c src\game.zc

echo Compiling game_logic.zc...
zc -target windows -o build\game_logic.c src\game_logic.zc

echo Compiling platform_api.zc...
zc -target windows -o build\platform_api.c src\platform_api.zc

echo Compiling platform_api_windows.zc...
zc -target windows -o build\platform_api_windows.c src\platform_api_windows.zc

REM 编译 C 文件并链接
echo Linking...
gcc -o build\pingpong_game.exe ^
    build\main_window.c ^
    build\game.c ^
    build\game_logic.c ^
    build\platform_api.c ^
    build\platform_api_windows.c ^
    -lwinmm -lgdi32 -luser32 -lm

if %errorlevel% equ 0 (
    echo.
    echo Build successful!
    echo Output: build\pingpong_game.exe
    echo.
    echo To run the game:
    echo   build\pingpong_game.exe
) else (
    echo.
    echo Build failed!
    exit /b 1
)
