@echo off
chcp 65001 >nul
echo ========================================
echo   Zen-C 贪吃蛇游戏 - Windows窗体版构建脚本
echo ========================================
echo.

REM 检查是否安装了Zen-C编译器
where zc >nul 2>nul
if %errorlevel% neq 0 (
    echo ❌ 错误: 未找到Zen-C编译器 (zc)
    echo.
    echo 请先安装Zen-C编译器:
    echo.
    echo 方法1 - 从源码编译:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build && cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo   echo 将 build/zc 添加到系统PATH
    echo.
    echo 方法2 - 使用预编译版本:
    echo   访问 https://github.com/z-libs/Zen-C/releases
    echo   下载对应平台的预编译二进制文件
    echo.
    echo 更多信息: https://zenc-lang.org/
    echo.
    pause
    exit /b 1
)

echo ✅ 找到Zen-C编译器 (zc)
echo.

REM 设置源文件和输出文件
set SOURCE_DIR=src
set BUILD_DIR=build
set OUTPUT_FILE=%BUILD_DIR%\snake_game.exe

REM 创建构建目录
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo 🔨 正在编译Windows窗体版贪吃蛇游戏...
echo 源文件: %SOURCE_DIR%\main_window.zc
echo 输出文件: %OUTPUT_FILE%
echo.

REM 编译Zen-C源代码
REM Zen-C编译器会将.zc文件编译为C代码，然后调用gcc编译
zc build %SOURCE_DIR%\main_window.zc -o %OUTPUT_FILE%

if %errorlevel% neq 0 (
    echo ❌ 编译失败!
    echo 请检查错误信息
    echo.
    echo 提示: 确保所有源文件(.zc)都在正确位置
    pause
    exit /b 1
)

echo ✅ 编译成功!
echo.
echo 📁 输出文件: %OUTPUT_FILE%
echo 📏 文件大小: 
for %%F in (%OUTPUT_FILE%) do echo        %%~zF 字节
echo.

REM 创建运行脚本
echo 📝 创建运行脚本...
echo @echo off > %BUILD_DIR%\run_game.bat
echo echo 正在启动Zen-C贪吃蛇游戏... >> %BUILD_DIR%\run_game.bat
echo echo ======================================== >> %BUILD_DIR%\run_game.bat
echo start "" "%~dp0snake_game.exe" >> %BUILD_DIR%\run_game.bat

echo 🎮 游戏已准备就绪!
echo.
echo 运行方式:
echo 1. 双击 build\run_game.bat
echo 2. 或直接运行 %OUTPUT_FILE%
echo.
echo 🎯 游戏控制:
echo   方向键/WASD: 移动蛇
echo   空格键: 暂停/继续
echo   R键: 重新开始
echo   ESC键: 退出游戏
echo.
echo 🖼️ 游戏特性:
echo   - 美观的Windows窗体界面
echo   - 彩色图形显示
echo   - 分数和等级系统
echo   - 网格背景
echo   - 专业UI面板
echo.

REM 测试运行
echo 🧪 是否要测试运行游戏? (Y/N)
set /p TEST_RUN=
if /i "%TEST_RUN%"=="Y" (
    echo.
    echo 🚀 启动游戏...
    echo.
    start "" "%OUTPUT_FILE%"
    echo 游戏已启动!
)

echo.
echo ========================================
echo   构建完成! 按任意键退出...
echo ========================================
pause >nul
