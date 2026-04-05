@echo off
REM build_windows.bat - Build 2048 game for Windows
REM 
REM This script builds the 2048 game using Zen-C compiler on Windows.
REM
REM Usage:
REM   build_windows.bat [options]
REM
REM Options:
REM   debug    - Build with debug symbols
REM   clean    - Clean build directory before building

echo ===========================================
echo  Zen-C 2048 Game - Windows Build Script
echo ===========================================
echo.

REM 检查 zc 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] zc compiler not found!
    echo Please install Zen-C compiler and add it to PATH
    echo Download from: https://github.com/z-libs/Zen-C
    exit /b 1
)

echo [OK] zc compiler found

REM 设置输出目录
set OUTPUT_DIR=build
set TARGET=game2048

REM 创建输出目录
if not exist "%OUTPUT_DIR%" mkdir "%OUTPUT_DIR%"

REM 检查源码文件
if not exist "src\main_window.zc" (
    echo [ERROR] src\main_window.zc not found!
    exit /b 1
)

echo.
echo Building 2048 game...
echo Source: src\main_window.zc
echo Output: %OUTPUT_DIR%\%TARGET%.exe
echo.

REM 编译
zc build -o %OUTPUT_DIR%\%TARGET%.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Build failed!
    exit /b 1
)

echo.
echo ===========================================
echo  Build successful!
echo  Output: %OUTPUT_DIR%\%TARGET%.exe
echo ===========================================
echo.
echo To run the game, execute:
echo   %OUTPUT_DIR%\%TARGET%.exe
echo.

REM 可选：自动运行
set /p RUN="Would you like to run the game now? (Y/N) "
if /i "%RUN%"=="Y" goto run
goto end

:run
echo Starting game...
%OUTPUT_DIR%\%TARGET%.exe

:end
exit /b 0
