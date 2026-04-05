@echo off
REM Zen-C 纸牌接龙游戏 Windows 构建脚本

echo ============================================
echo Zen-C Solitaire Windows Build Script
echo ============================================
echo.

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 下载地址: https://github.com/z-libs/Zen-C
    echo.
    echo 安装步骤:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo   # 将 build\zc 添加到系统PATH
    echo.
    pause
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译游戏
echo 正在编译游戏...
zc build -o build\solitaire.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo.
    echo ============================================
    echo 编译成功！
    echo 启动游戏...
    echo ============================================
    build\solitaire.exe
) else (
    echo.
    echo ============================================
    echo 编译失败！
    echo ============================================
    pause
    exit /b 1
)
