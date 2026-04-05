@echo off
REM Build script for 068-Fencing (Zen-C Windows)
echo ============================================
echo  Building 068-Fencing
echo ============================================

REM Check if Zen-C compiler is available
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: Zen-C compiler 'zc' not found in PATH
    echo Please install Zen-C SDK and add it to PATH
    exit /b 1
)

echo [1/3] Cleaning old build...
if exist build\*.exe del /q build\*.exe >nul 2>&1
if exist build\*.obj del /q build\*.obj >nul 2>&1
if not exist build mkdir build

echo [2/3] Compiling source files...
zc -O2 -o build\fencing.exe src\main_window.zc src\game_logic.zc src\game.zc src\platform_api.zc src\platform_api_windows.zc

if %errorlevel% neq 0 (
    echo Build failed!
    exit /b 1
)

echo [3/3] Build complete!
echo.
echo Executable: build\fencing.exe
echo.

if exist build\fencing.exe (
    echo Press any key to run...
    pause >nul
    build\fencing.exe
)

echo Done.
