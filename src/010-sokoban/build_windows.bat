@echo off
REM build_windows.bat - Windows 构建脚本 for Sokoban
REM 使用 Zen-C 编译器构建游戏

echo ===========================================
echo Zen-C Sokoban Game Build Script
echo ===========================================

REM 检查 zc 编译器
where zc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo 错误: 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    pause
    exit /b 1
)

REM 创建构建目录
if not exist "build" mkdir build

REM 编译 Zen-C 代码
echo.
echo 正在编译 Zen-C 代码...
zc compile -target x86_64-pc-windows-gnu -o build/sokoban_game.z.c src\main_window.zc src\sokoban_logic.zc src\game.zc src\platform_api.zc

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo 错误: Zen-C 编译失败
    pause
    exit /b 1
)

REM 编译 C 代码
echo.
echo 正在编译 C 代码...
gcc -Wall -Wextra -O2 build\sokoban_game.z.c -o build\sokoban_game.exe -lwin32 -lgdi32 -luser32 -lkernel32

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo 错误: C 编译失败
    pause
    exit /b 1
)

echo.
echo ===========================================
echo 构建成功!
echo 可执行文件: build\sokoban_game.exe
echo ===========================================
echo.
echo 按任意键运行游戏...
pause >nul

REM 运行游戏
build\sokoban_game.exe
