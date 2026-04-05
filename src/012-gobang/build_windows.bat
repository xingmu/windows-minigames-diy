@echo off
REM build_windows.bat - Build Gobang game for Windows
REM Zen-C Windows GUI Game

echo ==========================================
echo  Gobang 五子棋游戏 - Windows 构建
echo ==========================================

REM 设置编译器路径
set ZCC=zcc.exe

REM 源文件目录
set SRC_DIR=src

REM 构建目录
set BUILD_DIR=build
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

REM 源文件
set SRC_FILES=%SRC_DIR%\main_window.zc %SRC_DIR%\game_logic.zc %SRC_DIR%\platform_api.zc

REM 输出文件
set OUTPUT=%BUILD_DIR%\gobang.exe

echo.
echo 正在编译...
echo.

REM 编译命令
%ZCC% -std=c11 -O2 -o %OUTPUT% %SRC_FILES%

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ==========================================
    echo  构建成功！
    echo  输出文件: %OUTPUT%
    echo ==========================================
    echo.
    echo 运行游戏请执行:
    echo   %OUTPUT%
    echo.
) else (
    echo.
    echo ==========================================
    echo  构建失败！
    echo ==========================================
    echo.
    echo 请确保:
    echo    1. Zen-C 编译器 (zcc.exe) 已安装
    echo    2. 源文件路径正确
    echo.
)

pause
