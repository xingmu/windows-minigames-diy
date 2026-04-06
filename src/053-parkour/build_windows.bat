@echo off
echo ===========================================
echo  Building Parkour - Zen-C
echo ===========================================

REM 创建 build 目录
if not exist build mkdir build

REM 编译
echo Compiling...
zc -O2 -o build\053-parkour.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Output: build\053-parkour.exe
echo.
echo To run the game:
echo   build\053-parkour.exe
echo.
pause
