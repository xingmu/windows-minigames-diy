@echo off
REM build_windows.bat - Windows build script for Rugby

echo ===========================================
echo  Rugby - Zen-C 橄榄球游戏 编译脚本
echo ===========================================
echo.

REM 创建构建目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zenc src/main_window.zc src/game.zc src/game_logic.zc src/platform_api.zc src/platform_api_windows.zc -o build/rugby

if %errorlevel% equ 0 (
    echo.
    echo 编译成功！
    echo 输出: build/rugby.exe
    echo.
) else (
    echo.
    echo 编译失败！
    exit /b 1
)
