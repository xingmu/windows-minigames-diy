@echo off
REM Zen-C Pacman Windows 构建脚本

echo ==========================================
echo Zen-C Pacman 构建系统 (Windows)
echo ==========================================

REM 检查zc编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误: zc编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zc build -o build\pacman_game.exe src\main_window.zc

if %errorlevel% neq 0 (
    echo 编译失败!
    exit /b 1
)

echo 编译成功!
echo 运行: build\pacman_game.exe
echo ==========================================
