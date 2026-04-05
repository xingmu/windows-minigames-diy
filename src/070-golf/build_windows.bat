@echo off
REM Zen-C 高尔夫游戏 Windows 构建脚本

echo Building Golf Game for Windows...

mkdir build >nul 2>&1

REM 使用 Zen-C 编译器构建
zc build -o build/golf.exe src/main_window.zc

if %errorlevel% equ 0 (
    echo Build successful!
    echo Executable: build\golf.exe
) else (
    echo Build failed!
)

pause
