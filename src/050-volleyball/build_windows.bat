@echo off
REM build_windows.bat - Windows 构建脚本 for Volleyball
REM 使用 Zen-C 编译器构建游戏

echo ===========================================
echo  Volleyball - Zen-C Windows 构建脚本
echo ===========================================

REM 检查 Zen-C 编译器
where zc >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo 错误: 未找到 zc 编译器
    echo 请确保 Zen-C 编译器已安装并添加到 PATH
    echo.
    echo 安装方法:
    echo   git clone https://github.com/z-libs/Zen-C.git
    echo   cd Zen-C
    echo   mkdir build ^&^& cd build
    echo   cmake .. -DCMAKE_BUILD_TYPE=Release
    echo   cmake --build . --config Release
    echo   将 build\zc 添加到系统 PATH
    pause
    exit /b 1
)

echo 找到 Zen-C 编译器

REM 创建构建目录
if not exist "build" mkdir build

REM 编译
echo.
echo 编译源文件...
zc -target windows-gui -o build\volleyball.zcobj -c src\main_window.zc
if %ERRORLEVEL% NEQ 0 (
    echo 编译 main_window.zc 失败
    pause
    exit /b 1
)

zc -target windows-gui -o build\game.zcobj -c src\game.zc
if %ERRORLEVEL% NEQ 0 (
    echo 编译 game.zc 失败
    pause
    exit /b 1
)

zc -target windows-gui -o build\platform_api.zcobj -c src\platform_api.zc
if %ERRORLEVEL% NEQ 0 (
    echo 编译 platform_api.zc 失败
    pause
    exit /b 1
)

zc -target windows-gui -o build\platform_api_windows.zcobj -c src\platform_api_windows.zc
if %ERRORLEVEL% NEQ 0 (
    echo 编译 platform_api_windows.zc 失败
    pause
    exit /b 1
)

REM 链接
echo.
echo 链接生成可执行文件...
zc -target windows-gui -o build\volleyball.exe ^
    build\main_window.zcobj ^
    build\game.zcobj ^
    build\platform_api.zcobj ^
    build\platform_api_windows.zcobj

if %ERRORLEVEL% NEQ 0 (
    echo 链接失败
    pause
    exit /b 1
)

echo.
echo ===========================================
echo  构建成功!
echo  可执行文件: build\volleyball.exe
echo ===========================================
echo.
echo 按任意键运行游戏...
pause >nul

REM 运行游戏
build\volleyball.exe
