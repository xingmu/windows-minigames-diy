@echo off
echo ======================================
echo  Snowboard - Zen-C Build (Windows)
echo ======================================

REM 检查 zc 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [错误] 未找到 zc 编译器
    echo 请先安装 Zen-C 编译器:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build

REM 编译
echo [编译] zc build -o build/snowboard src/main_window.zc
zc build -o build/snowboard src/main_window.zc

if %errorlevel% equ 0 (
    echo [成功] 编译完成！
    echo 运行 build\snowboard.exe 启动游戏
) else (
    echo [失败] 编译出错
)

pause
