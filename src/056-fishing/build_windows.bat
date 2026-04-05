@echo off
REM build_windows.bat - Windows 构建脚本
REM 056-Fishing 捕鱼游戏
REM Zen-C 游戏框架 v1.0.0

echo ===========================================
echo  056-Fishing 捕鱼游戏
echo  Zen-C Windows 构建脚本
echo ===========================================
echo.

REM 检查 Zen-C 编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    pause
    exit /b 1
)

REM 创建构建目录
if not exist "build" mkdir build

REM 编译
echo 正在编译...
zc -O2 -o build/fishing.exe src/fishing_game.zc

if %errorlevel% equ 0 (
    echo.
    echo 构建成功!
    echo 输出: build/fishing.exe
    echo.
    echo 按任意键运行游戏...
    pause >nul
    build\fishing.exe
) else (
    echo.
    echo 构建失败!
    pause
)
