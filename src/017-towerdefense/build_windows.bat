@echo off
REM Tower Defense Zen-C Game - Windows Build Script
REM 使用 zc 编译器构建 Zen-C 项目

echo ===========================================
echo  Tower Defense - Zen-C Build Script
echo ===========================================

REM 检查 zc 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] zc 编译器未找到!
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    echo.
    echo 安装方法:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo.
    pause
    exit /b 1
)

echo [1/3] 检查编译器版本...
zc --version
echo.

REM 创建 build 目录
echo [2/3] 创建构建目录...
if not exist "build" mkdir build
echo.

REM 编译
echo [3/3] 编译游戏...
echo.

zc build -o build\towerdefense.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo.
    echo [错误] 编译失败!
    pause
    exit /b 1
)

echo.
echo ===========================================
echo  编译成功!
echo  可执行文件: build\towerdefense.exe
echo ===========================================
echo.
echo 运行游戏请执行: build\towerdefense.exe
echo.

pause
