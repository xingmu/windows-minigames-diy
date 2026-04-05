@echo off
echo ==========================================
echo Zen-C Squash 壁球游戏 - Windows构建
echo ==========================================

REM 检查zc编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器
    echo 参考: https://github.com/z-libs/Zen-C
    exit /b 1
)

REM 创建build目录
if not exist build mkdir build

REM 编译
echo 正在编译...
zc build -o build/squash.exe src/main_window.zc

if %errorlevel% equ 0 (
    echo 编译成功!
    echo 输出: build\squash.exe
    echo.
    echo 运行游戏: build\squash.exe
) else (
    echo 编译失败!
    exit /b 1
)

echo ==========================================
