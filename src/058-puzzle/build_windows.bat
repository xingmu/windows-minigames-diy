@echo off
REM Zen-C Slide Puzzle Windows构建脚本
REM 需要安装zc编译器和MinGW

echo Zen-C 滑动拼图游戏 - Windows构建脚本
echo ========================================

REM 检查zc编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: zc编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装zc编译器
    pause
    exit /b 1
)

REM 检查gcc编译器
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo 警告: gcc编译器未安装
    echo 建议安装MinGW或MSYS2
)

REM 显示编译器版本
echo.
echo 编译器信息:
zc --version

REM 创建构建目录
if not exist build mkdir build

REM 编译Zen-C代码
echo.
echo 正在编译Zen-C代码...
zc build -o build\puzzle_game.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo 编译成功!
    echo.
    echo 运行游戏:
    echo build\puzzle_game.exe
) else (
    echo 编译失败!
)

pause
