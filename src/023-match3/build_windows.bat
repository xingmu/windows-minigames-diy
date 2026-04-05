@echo off
REM Zen-C Match3 消消乐游戏 Windows 构建脚本

echo ==========================================
echo Zen-C Match3 消消乐游戏构建
echo ==========================================

REM 创建构建目录
if not exist build mkdir build

REM 检查 zc 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: zc 编译器未安装
    echo 请从 https://github.com/z-libs/Zen-C 安装
    exit /b 1
)

REM 编译 Zen-C 代码
echo 编译 Zen-C 代码...
zc build -o build\match3_game src\main_window.zc
if %errorlevel% neq 0 (
    echo 错误: Zen-C 编译失败
    exit /b 1
)

REM 编译 C 代码 (链接 Windows GUI 库)
echo 编译 Windows 可执行文件...
gcc -o build\match3.exe build\match3_game -lgdi32 -luser32 -lcomdlg32 -lcomctl32 -lshell32 -lole32 -luuid -mwindows
if %errorlevel% neq 0 (
    echo 错误: 链接失败
    exit /b 1
)

echo ==========================================
echo 构建成功!
echo 可执行文件: build\match3.exe
echo ==========================================
echo.
echo 运行游戏: build\match3.exe
echo.

pause
