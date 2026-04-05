@echo off
REM Zen-C Cricket Game Build Script for Windows
REM 075-Cricket 板球游戏

echo ===========================================
echo   Zen-C Cricket Game Build
echo   板球游戏构建脚本
echo ===========================================
echo.

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    pause
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译
echo [编译] 编译板球游戏...
zc build -o build\cricket_game.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo [成功] 编译完成！
    echo 输出文件: build\cricket_game.exe
) else (
    echo [失败] 编译失败
)

echo.
pause
