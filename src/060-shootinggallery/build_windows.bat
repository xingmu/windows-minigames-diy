@echo off
REM build_windows.bat - Windows 构建脚本 for 射击训练游戏
REM Shooting Gallery - 移动靶射击训练游戏

echo ========================================
echo  Zen-C Shooting Gallery 构建脚本
echo ========================================

REM 设置 Zen-C 编译器路径
set ZC_PATH=C:\ZenC\bin
set PATH=%ZC_PATH%;%PATH%

REM 清理旧的构建文件
if exist build\*.o del /q build\*.o
if exist build\shootinggallery.exe del /q build\shootinggallery.exe

REM 编译源文件
echo 编译源文件...

REM 编译 platform_api.zc
echo  - 编译 platform_api.zc...
zcc -c src\platform_api.zc -o build\platform_api.o
if errorlevel 1 goto error

REM 编译 platform_api_windows.zc
echo  - 编译 platform_api_windows.zc...
zcc -c src\platform_api_windows.zc -o build\platform_api_windows.o
if errorlevel 1 goto error

REM 编译 game.zc
echo  - 编译 game.zc...
zcc -c src\game.zc -o build\game.o
if errorlevel 1 goto error

REM 编译 main_window.zc
echo  - 编译 main_window.zc...
zcc -c src\main_window.zc -o build\main_window.o
if errorlevel 1 goto error

REM 链接
echo 链接生成可执行文件...
zcc -o build\shootinggallery.exe build\main_window.o build\game.o build\platform_api_windows.o build\platform_api.o
if errorlevel 1 goto error

echo ========================================
echo  构建成功!
echo  可执行文件: build\shootinggallery.exe
echo ========================================
goto end

:error
echo ========================================
echo  构建失败!
echo ========================================
exit /b 1

:end
