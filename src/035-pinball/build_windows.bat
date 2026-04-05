@echo off
REM build_windows.bat - Zen-C Pinball Windows 构建脚本

echo ==========================================
echo Zen-C Pinball 弹球机游戏 - Windows 构建
echo ==========================================

set SRC_DIR=src
set BUILD_DIR=build
set OUT_NAME=pinball

REM 创建构建目录
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM 编译主程序
echo.
echo 正在编译...
zc build "%SRC_DIR%\main_window.zc" -o "%BUILD_DIR%\%OUT_NAME%.exe" -I"%SRC_DIR%"

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo 编译失败!
    pause
    exit /b 1
)

echo.
echo ==========================================
echo 构建成功!
echo 输出: %BUILD_DIR%\%OUT_NAME%.exe
echo ==========================================

if "%1"=="" (
    echo.
    echo 按任意键运行...
    pause >nul
    "%BUILD_DIR%\%OUT_NAME%.exe"
)

pause
