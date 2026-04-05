@echo off
REM build_windows.bat - Windows Build Script for 082-Billiards
REM Zen-C 9-Ball Pool 台球游戏

echo ==========================================
echo Zen-C 9-Ball Pool 台球游戏构建
echo ==========================================

setlocal

REM 设置项目路径
set PROJECT=082-billiards
set GAME_NAME=9ball
set SRC_DIR=src
set BUILD_DIR=build

REM 创建构建目录
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM 查找 Zen-C 编译器
where zc >nul 2>&1
if %errorlevel% neq 0 (
    echo [警告] 未找到 Zen-C 编译器 (zc)
    echo 这是一个模板项目，需要 Zen-C 编译器来构建
    echo 请访问 https://github.com/your-repo/zenc 获取编译器
    goto :end
)

REM 编译
echo 正在编译...
zc -o "%BUILD_DIR%\%GAME_NAME%.exe" "%SRC_DIR%\*.zc"

if %errorlevel% neq 0 (
    echo [错误] 编译失败!
    goto :end
)

echo.
echo ==========================================
echo 构建成功!
echo 输出: %BUILD_DIR%\%GAME_NAME%.exe
echo ==========================================
echo.
echo 运行游戏: 双击 %BUILD_DIR%\%GAME_NAME%.exe
echo.

:end
endlocal
pause
