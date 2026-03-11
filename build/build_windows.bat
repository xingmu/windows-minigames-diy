@echo off
REM Windows构建脚本 for Zen-C Snake Game
REM 使用MinGW或MSVC编译器

setlocal enabledelayedexpansion

echo Zen-C贪吃蛇游戏 - Windows构建脚本
echo =================================

REM 检查编译器
where gcc >nul 2>nul
if %errorlevel% equ 0 (
    echo [INFO] 找到GCC编译器
    set COMPILER=gcc
    set CFLAGS=-Wall -Wextra -O2
) else (
    where cl >nul 2>nul
    if %errorlevel% equ 0 (
        echo [INFO] 找到MSVC编译器
        set COMPILER=cl
        set CFLAGS=/W4 /O2
    ) else (
        echo [ERROR] 未找到C编译器！
        echo 请安装MinGW或Visual Studio
        pause
        exit /b 1
    )
)

REM 创建构建目录
if not exist "build" mkdir build

REM 编译
echo [INFO] 编译游戏...
%COMPILER% %CFLAGS% src\snake_game.c -o build\snake_game.exe

if %errorlevel% neq 0 (
    echo [ERROR] 编译失败！
    pause
    exit /b 1
)

echo [SUCCESS] 编译成功！
echo.
echo 运行游戏: build\snake_game.exe
echo 清理构建: del build\snake_game.exe
echo.

REM 询问是否运行游戏
set /p RUN_GAME="是否立即运行游戏？(y/n): "
if /i "!RUN_GAME!"=="y" (
    echo [INFO] 启动游戏...
    build\snake_game.exe
)

pause