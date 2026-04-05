@echo off
REM Zen-C TetrisPlus Windows Build Script

echo Building TetrisPlus...
zc build -o build\tetrisplus_game.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo Build successful!
    echo Output: build\tetrisplus_game.exe
) else (
    echo Build failed!
)

pause
