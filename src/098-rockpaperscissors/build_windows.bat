@echo off
REM Zen-C Rock-Paper-Scissors Game Windows Build Script
REM Requires zc compiler and MinGW

echo Zen-C Rock-Paper-Scissors Game - Windows Build Script
echo ====================================================

REM Check zc compiler
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: zc compiler not installed
    echo Please install from https://github.com/z-libs/Zen-C
    echo.
    echo Installation steps:
    echo 1. git clone https://github.com/z-libs/Zen-C.git
    echo 2. cd Zen-C
    echo 3. make install
    pause
    exit /b 1
)

REM Check gcc compiler
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo Warning: gcc compiler not installed
    echo Recommend installing MinGW or MSYS2
    echo.
    echo Install MinGW:
    echo 1. Download https://sourceforge.net/projects/mingw/
    echo 2. Install and add gcc to PATH
    pause
)

REM Show compiler version
echo.
echo Compiler info:
zc --version
if %errorlevel% equ 0 (
    echo zc compiler: installed
) else (
    echo zc compiler: not properly installed
)

REM Create build directory
if not exist build mkdir build

REM Compile Zen-C code
echo.
echo Compiling Zen-C code...
zc build -o build\rockpaperscissors.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo Build successful!
    echo.
    echo Run game:
    echo build\rockpaperscissors.exe
    echo.
    echo Or run directly:
    echo rockpaperscissors.exe
) else (
    echo Build failed!
    echo Please check error messages
)

pause
