@echo off
REM build_windows.bat - Build 038-RacingPlus for Windows
REM Zen-C + 003-framework

echo Building 038-RacingPlus...
echo.

REM 设置路径
set ZCC=zcc
set SRC_DIR=src
set BUILD_DIR=build

REM 创建构建目录
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

REM 编译
echo Compiling...
%ZCC% -o %BUILD_DIR%\038-racingplus.exe %SRC_DIR%\main_window.zc %SRC_DIR%\platform_api.zc %SRC_DIR%\platform_api_windows.zc %SRC_DIR%\game.zc -lwinmm -lgdi32

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful!
    echo Output: %BUILD_DIR%\038-racingplus.exe
    echo.
    echo To run: %BUILD_DIR%\038-racingplus.exe
) else (
    echo.
    echo Build failed!
)

pause
