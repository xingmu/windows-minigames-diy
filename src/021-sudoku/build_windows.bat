@echo off
REM Zen-C Sudoku Game Windows 构建脚本 (控制台模式)
REM 使用 Zen-C 编译器构建

echo ==========================================
echo Zen-C Sudoku Game 构建脚本
echo ==========================================

REM 检查 zc 编译器是否存在
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] 未找到 zc 编译器！
    echo.
    echo 请先安装 Zen-C 编译器：
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo   # 将 build\zc 添加到系统 PATH
    echo.
    echo 或从 releases 下载预编译版本：
    echo   https://github.com/z-libs/Zen-C/releases
    echo.
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 清理旧构建
if exist build\sudoku_game.exe del build\sudoku_game.exe

echo.
echo [1/2] 正在编译 Zen-C 代码...
zc build -o build\sudoku_game src\main_window.zc
if %errorlevel% neq 0 (
    echo [错误] 编译失败！
    pause
    exit /b 1
)

echo.
echo [2/2] 构建完成！
echo.
echo 运行游戏: build\sudoku_game.exe
echo.
echo ==========================================
echo 构建成功！按任意键退出...
echo ==========================================

REM 自动运行游戏
build\sudoku_game.exe

pause
