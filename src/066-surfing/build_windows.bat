@echo off
REM Zen-C Surfing Game Windows Build Script

echo Building Surfing Game...

REM 检查 zc 编译器
where zc >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo ERROR: zc compiler not found. Please install Zen-C compiler.
    exit /b 1
)

REM 创建 build 目录
if not exist build mkdir build

REM 编译
echo Compiling...
zc build -o build/surfing.exe src/main_window.zc

if %ERRORLEVEL% equ 0 (
    echo Build successful!
    echo Output: build/surfing.exe
) else (
    echo Build failed!
    exit /b 1
)
