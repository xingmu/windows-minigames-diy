@echo off
REM 华容道 Klotski Game Windows Build Script
REM 使用Zen-C编译器构建

echo ===========================================
echo  Zen-C 华容道 Klotski Game Builder
echo ===========================================

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: zc compiler not found!
    echo Please install Zen-C compiler first.
    echo Visit: https://github.com/z-libs/Zen-C
    pause
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译
echo.
echo Compiling 华容道 Klotski...
zc build -o build\huarongdao.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo Build successful!
    echo Output: build\huarongdao.exe
    echo.
    echo To run the game:
    echo   build\huarongdao.exe
) else (
    echo.
    echo Build failed!
    pause
    exit /b 1
)

echo.
pause
