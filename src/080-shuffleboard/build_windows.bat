@echo off
REM build_windows.bat - Windows 构建脚本 for Zen-C 沙狐球
echo Building Zen-C Shuffleboard...
echo.

REM 检查 Zen-C 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: Zen-C compiler 'zc' not found.
    echo Please install Zen-C compiler and add it to PATH.
    exit /b 1
)

REM 清理旧构建
if exist build\*.exe del /q build\*.exe 2>nul
if not exist build mkdir build

REM 编译
echo Compiling...
zc build src/main_window.zc -o build/shuffleboard.exe
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b 1
)

echo.
echo Build successful: build\shuffleboard.exe
echo Run: build\shuffleboard.exe
