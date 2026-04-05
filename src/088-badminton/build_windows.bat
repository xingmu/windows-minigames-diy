@echo off
REM Zen-C Badminton Game Build Script for Windows
REM 088-Badminton 羽毛球游戏

echo ===========================================
echo   Zen-C Badminton Game Builder
echo   088-Badminton 羽毛球游戏
echo ===========================================
echo.

REM Check if zc compiler exists
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] zc compiler not found!
    echo.
    echo Please install Zen-C compiler:
    echo   1. Download from https://github.com/z-libs/Zen-C
    echo   2. Add to PATH environment variable
    echo.
    pause
    exit /b 1
)

echo [INFO] zc compiler found
echo.

REM Create build directory if not exists
if not exist "build" mkdir build

REM Build the game
echo [BUILD] Compiling badminton game...
zc build -o build\badminton_game.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Build failed!
    pause
    exit /b 1
)

echo.
echo [SUCCESS] Build completed!
echo.
echo Output: build\badminton_game.exe
echo.
echo To run the game:
echo   .\build\badminton_game.exe
echo.

pause
