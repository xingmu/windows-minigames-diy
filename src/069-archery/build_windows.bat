@echo off
REM Zen-C Archery Game Build Script for Windows
REM 需要先安装 Zen-C 编译器

echo ========================================
echo Zen-C Archery 射箭游戏 - Windows 构建
echo ========================================

REM 检查 zc 编译器是否安装
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo [错误] 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    echo ========================================
    pause
    exit /b 1
)

echo [1/3] 创建 build 目录...
if not exist build mkdir build

echo [2/3] 编译 Zen-C 代码...
zc build -o build\archery_game.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo [错误] 编译失败！
    echo ========================================
    pause
    exit /b 1
)

echo [3/3] 构建完成！
echo ========================================
echo 游戏已编译到: build\archery_game.exe
echo 双击运行或输入: build\archery_game.exe
echo ========================================
pause
