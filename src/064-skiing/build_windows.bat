@echo off
echo ==========================================
echo Zen-C Skiing Game - Windows Build
echo ==========================================

REM 创建build目录
if not exist build mkdir build

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: 未找到zc编译器
    echo 请确保Zen-C编译器已安装并添加到PATH
    exit /b 1
)

REM 编译游戏
echo 编译中...
zc build -o build\skiing.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo ✅ 编译成功!
    echo 游戏位置: build\skiing.exe
    echo.
    echo 运行游戏: build\skiing.exe
) else (
    echo.
    echo ❌ 编译失败
    exit /b 1
)
