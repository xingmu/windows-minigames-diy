@echo off
REM Zen-C Blackjack Windows Build Script
REM 使用 Zen-C 编译器构建游戏

echo ============================================
echo  Zen-C Blackjack 构建脚本 (Windows)
echo ============================================

REM 检查 zc 编译器
where zc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [错误] 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器并将其添加到 PATH
    echo 下载地址: https://github.com/z-libs/Zen-C
    echo.
    pause
    exit /b 1
)

REM 检查 gcc 编译器
where gcc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [错误] 未找到 gcc 编译器
    echo 请安装 MinGW 或其他 GCC 工具链
    echo.
    pause
    exit /b 1
)

echo [OK] 编译器检查通过

REM 创建 build 目录
if not exist "build" mkdir build

REM 编译
echo.
echo 正在编译...
zc build -o build\blackjack.exe src\main_window.zc

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [错误] 编译失败!
    pause
    exit /b 1
)

echo.
echo ============================================
echo  编译成功!
echo  可执行文件: build\blackjack.exe
echo ============================================
echo.
echo 是否运行游戏? (Y/N)
set /p choice=
if /i "%choice%"=="Y" goto run
if /i "%choice%"=="y" goto run
exit /b 0

:run
echo.
echo 启动游戏...
build\blackjack.exe

pause
exit /b 0
