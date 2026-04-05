@echo off
REM Space Invaders Windows Build Script
REM 使用 Zen-C 编译器构建游戏

echo ===========================================
echo  Space Invaders 构建脚本
echo ===========================================
echo.

REM 检查 zc 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 参考: https://github.com/z-libs/Zen-C
    pause
    exit /b 1
)

REM 创建 build 目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zc build -o build\spaceinvaders.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo 构建成功!
    echo 输出: build\spaceinvaders.exe
    echo.
) else (
    echo.
    echo 构建失败!
    pause
    exit /b 1
)

pause
