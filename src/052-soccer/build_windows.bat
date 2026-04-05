@echo off
REM build_windows.bat - Windows平台编译脚本
REM 足球点球游戏 Zen-C

echo ==========================================
echo  Zen-C 足球点球游戏 - Windows编译
echo ==========================================

REM 检查zenc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请确保 Zen-C 编译器已安装并添加到 PATH
    echo 下载地址: https://github.com/zenc-lang/zenc
    pause
    exit /b 1
)

echo 找到 zc 编译器

REM 创建输出目录
if not exist "bin" mkdir bin

REM 编译
echo.
echo 正在编译...
zc -o bin\soccer.exe src\main_window.zc src\game_logic.zc src\platform_api.zc

if %errorlevel% neq 0 (
    echo.
    echo 编译失败！
    pause
    exit /b 1
)

echo.
echo ==========================================
echo 编译成功！
echo 输出: bin\soccer.exe
echo ==========================================
echo.
echo 运行游戏请输入: bin\soccer.exe
echo.
pause
