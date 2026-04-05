@echo off
REM FlappyBird Zen-C Windows 构建脚本
REM 需要 zc 编译器和 MinGW

echo FlappyBird - Zen-C Windows 构建脚本
echo ========================================

REM 检查 zc 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: zc 编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装 zc 编译器
    echo.
    echo 安装步骤:
    echo 1. git clone https://github.com/z-libs/Zen-C.git
    echo 2. cd Zen-C
    echo 3. mkdir build ^&^& cd build
    echo 4. cmake .. -DCMAKE_BUILD_TYPE=Release
    echo 5. cmake --build . --config Release
    echo 6. 将 build\zc 添加到系统 PATH
    pause
    exit /b 1
)

REM 检查 gcc 编译器
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo 警告: gcc 编译器未安装
    echo 建议安装 MinGW 或 MSYS2
    echo.
    echo 安装 MinGW:
    echo 1. 下载 https://sourceforge.net/projects/mingw/
    echo 2. 安装并添加 gcc 到 PATH
    pause
)

REM 显示编译器版本
echo.
echo 编译器信息:
zc --version
if %errorlevel% equ 0 (
    echo zc 编译器: 已安装
) else (
    echo zc 编译器: 未正确安装
)

REM 创建构建目录
if not exist build mkdir build

REM 编译 Zen-C 代码
echo.
echo 正在编译 FlappyBird...
zc build -o build\flappybird.exe src\main_window.zc

if %errorlevel% equ 0 (
    echo 编译成功!
    echo.
    echo 运行游戏:
    echo build\flappybird.exe
    echo.
    echo 或者直接运行:
    echo flappybird.exe
) else (
    echo 编译失败!
    echo 请检查错误信息
)

pause
