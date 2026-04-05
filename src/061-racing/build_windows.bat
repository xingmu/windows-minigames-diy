@echo off
REM build_windows.bat - Zen-C 俯视角赛车游戏 Windows 编译脚本

echo ==========================================
echo Zen-C Racing Game - Windows Build
echo ==========================================

REM 设置 Zen-C 编译器路径
set ZENC_HOME=..\003-framework
set ZENC_SRC=src
set OUTPUT=061-racing.exe

echo.
echo 编译游戏源文件...
echo.

REM 编译主程序 (需要 Zen-C 编译器)
REM 注意: 此脚本需要 Zen-C 编译器支持
REM 实际编译命令取决于 Zen-C 编译器的具体用法

echo 源文件:
echo   - src/main_window.zc
echo   - src/game_logic.zc
echo   - src/platform_api.zc
echo.

echo 检查 Zen-C 编译器...
where zenc >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo [警告] 未找到 zenc 命令，请确保 Zen-C 编译器已安装并配置到 PATH
    echo.
    echo 编译步骤:
    echo   1. 安装 Zen-C 编译器
    echo   2. 确保 'zenc' 命令可用
    echo   3. 运行: zenc build
    echo.
    echo 或手动编译:
    echo   zenc src/main_window.zc -o %OUTPUT%
    echo.
) else (
    echo [OK] Zen-C 编译器已找到
    echo.
    echo 开始编译...
    zenc build
    if %ERRORLEVEL% equ 0 (
        echo.
        echo ==========================================
        echo 编译成功!
        echo 输出文件: %OUTPUT%
        echo 运行游戏: .\%OUTPUT%
        echo ==========================================
    ) else (
        echo.
        echo [错误] 编译失败!
        echo ==========================================
        exit /b 1
    )
)

echo.
pause
