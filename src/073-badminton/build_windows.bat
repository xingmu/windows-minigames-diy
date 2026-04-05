@echo off
REM Zen-C Badminton Game Windows Build Script
REM 073-Badminton 羽毛球游戏

echo ===========================================
echo  Zen-C Badminton Game Builder
echo  羽毛球游戏 - Windows 构建脚本
echo ===========================================
echo.

REM 检查 zc 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo [错误] zc 编译器未找到!
    echo 请先安装 Zen-C 编译器:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C\build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo.
    echo 或将 zc 添加到系统 PATH 环境变量
    exit /b 1
)

echo [1/2] 创建构建目录...
if not exist "build" mkdir build

echo [2/2] 编译游戏...
zc build -o build\badminton_game.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo ===========================================
    echo  ✅ 编译成功!
    echo  运行游戏: build\badminton_game.exe
    echo ===========================================
) else (
    echo.
    echo ===========================================
    echo  ❌ 编译失败!
    echo ===========================================
    exit /b 1
)
