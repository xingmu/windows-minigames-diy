@echo off
REM build_windows.bat - Zen-C BreakoutPlus Windows 构建脚本

echo ========================================
echo Zen-C BreakoutPlus 构建脚本
echo ========================================

REM 检查 Zen-C 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    pause
    exit /b 1
)

REM 创建构建目录
if not exist "build" mkdir build

REM 编译
echo 正在编译...
zc src\main_window.zc -o build\breakoutplus.exe -O2

if %errorlevel% equ 0 (
    echo.
    echo ========================================
    echo 构建成功!
    echo 可执行文件: build\breakoutplus.exe
    echo ========================================
) else (
    echo.
    echo ========================================
    echo 构建失败!
    echo ========================================
)

pause
