@echo off
REM build_windows.bat - Windows Build Script
REM 074-Pingpong 乒乓球 - 双人对战版

echo ===========================================
echo  Zen-C Pingpong 2P Build Script
echo  074-Pingpong 乒乓球 - 双人对战版
echo ===========================================
echo.

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] zc编译器未找到!
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    echo.
    pause
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译
echo [编译] 正在编译游戏...
zc build -o build\pingpong2p.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo [错误] 编译失败!
    pause
    exit /b 1
)

echo [成功] 编译完成!
echo.
echo 运行游戏: build\pingpong2p.exe
echo.
pause
