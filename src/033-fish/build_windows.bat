@echo off
REM build_windows.bat - Windows 构建脚本 for 033-FishGame

echo ===========================================
echo   捕鱼达人 FishGame 构建脚本
echo ===========================================

REM 创建 build 目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zc -o build/fishgame.exe src/platform_api.zc src/platform_api_windows.zc src/game_logic.zc src/fish_render.zc src/main_window.zc

if %errorlevel% neq 0 (
    echo 编译失败!
    pause
    exit /b 1
)

echo 编译成功!
echo.
echo 运行游戏: build\fishgame.exe
echo.
pause
