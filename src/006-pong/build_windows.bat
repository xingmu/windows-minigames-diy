@echo off
REM build_windows.bat - Windows构建脚本
REM 006-Pong 乒乓球游戏

echo ===========================================
echo  Zen-C Pong Game 构建脚本
echo ===========================================

REM 检查zc编译器
where zc >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo 错误: 未找到zc编译器
    echo 请先安装Zen-C编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    pause
    exit /b 1
)

echo 找到zc编译器，准备编译...

REM 创建build目录
if not exist "build" mkdir build

REM 编译
echo.
echo 编译中...
zc build -o build\pong_game.exe src\main_window.zc

if %ERRORLEVEL% EQU 0 (
    echo.
    echo 编译成功!
    echo 输出: build\pong_game.exe
    echo.
    echo 是否运行游戏? (Y/N)
    set /p choice=
    if /i "%choice%"=="Y" (
        build\pong_game.exe
    )
) else (
    echo.
    echo 编译失败!
    pause
)

pause
