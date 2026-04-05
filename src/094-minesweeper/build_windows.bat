@echo off
echo ===========================================
echo Zen-C Minesweeper Windows 构建脚本
echo ===========================================

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请确保 Zen-C 编译器已安装并在 PATH 中
    exit /b 1
)

REM 创建build目录
if not exist "build" mkdir build

REM 编译
echo 正在编译...
zc build -o build/minesweeper.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo ✅ 编译成功!
    echo 可执行文件: build\minesweeper.exe
    echo.
    echo 运行游戏: build\minesweeper.exe
) else (
    echo.
    echo ❌ 编译失败!
    exit /b 1
)

echo ===========================================
