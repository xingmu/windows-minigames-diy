@echo off
REM 斗地主游戏 Windows 构建脚本
echo Zen-C 斗地主游戏 - Windows构建
echo ============================

REM 检查zc编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: zc编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zc build -o build\doudizhu_game.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo 编译成功!
    echo 运行: build\doudizhu_game.exe
) else (
    echo 编译失败!
)

pause
