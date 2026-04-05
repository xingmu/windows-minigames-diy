@echo off
REM Zen-C Sudoku Game Windows 构建脚本 (窗口模式，无控制台)
REM 使用 Zen-C 编译器构建

echo ==========================================
echo Zen-C Sudoku Game 构建脚本 (窗口模式)
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
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 清理旧构建
if exist build\sudoku_game_window.exe del build\sudoku_game_window.exe

echo.
echo [1/2] 正在编译 Zen-C 代码 (窗口模式)...
REM 窗口模式编译（不显示控制台）
zc build -o build\sudoku_game_window -window src\main_window.zc
if %errorlevel% neq 0 (
    echo [错误] 编译失败！
    pause
    exit /b 1
)

echo.
echo [2/2] 构建完成！
echo.
echo 游戏文件: build\sudoku_game_window.exe
echo.
echo ==========================================
echo 构建成功！
echo ==========================================

REM 直接运行
start build\sudoku_game_window.exe
