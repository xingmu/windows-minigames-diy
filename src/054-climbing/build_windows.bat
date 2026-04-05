@echo off
REM Climbing Zen-C Windows Build Script
REM 使用 zc 编译器构建游戏

echo Building Climbing...

REM 检查 zc 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: zc 编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 编译
echo Compiling...
zc build -o build\climbing.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo 编译失败!
    pause
    exit /b 1
)

echo.
echo 编译成功!
echo 运行: build\climbing.exe
echo.
pause
