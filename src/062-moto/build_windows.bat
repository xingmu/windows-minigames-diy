@echo off
chcp 65001 >nul
echo ========================================
echo   Zen-C 摩托车障碍躲避游戏 - Windows窗体版构建脚本
echo ========================================
echo.

REM 检查是否安装了Zen-C编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERROR] 未找到Zen-C编译器 (zc)
    echo.
    echo 请先安装Zen-C编译器:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C ^&^& mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo   将 build/zc 添加到系统PATH
    echo.
    echo 更多信息: https://zenc-lang.org/
    echo.
    pause
    exit /b 1
)

echo [OK] 找到Zen-C编译器 (zc)
echo.

set SOURCE_DIR=src
set BUILD_DIR=build
set OUTPUT_FILE=%BUILD_DIR%\moto_game.exe

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo [BUILD] 正在编译Windows窗体版摩托车游戏...
echo 源文件: %SOURCE_DIR%\main_window.zc
echo 输出文件: %OUTPUT_FILE%
echo.

REM 编译Zen-C源代码
zc build %SOURCE_DIR%\main_window.zc -o %OUTPUT_FILE%

if %errorlevel% neq 0 (
    echo [ERROR] 编译失败!
    pause
    exit /b 1
)

echo [OK] 编译成功!
echo.
echo 输出文件: %OUTPUT_FILE%
echo.
echo 运行方式:
echo 1. 双击 build\moto_game.exe
echo 2. 或直接运行 %OUTPUT_FILE%
echo.
echo 操作说明:
echo   A/左方向键: 向左移动
echo   D/右方向键: 向右移动
echo   空格键: 暂停/继续
echo   R键: 重新开始
echo   ESC: 退出游戏
echo.
echo 游戏特性:
echo   - 摩托车障碍躲避游戏
echo   - 三种障碍物: 路障、汽车、卡车
echo   - 金币收集系统
echo   - 速度递增系统
echo   - 分数和距离统计
echo.
pause
