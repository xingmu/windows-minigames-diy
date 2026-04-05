# 073-Badminton - 羽毛球游戏 🏸

Zen-C 语言开发的羽毛球游戏，一人对战电脑。

## 游戏介绍

经典羽毛球游戏，玩家控制左侧球拍与电脑对战。先得 11 分者获胜。

## 操作说明

| 按键 | 功能 |
|------|------|
| W | 球拍上移 |
| S | 球拍下移 |
| 空格 | 发球 |
| ESC | 退出游戏 |
| R | 重新开始（游戏结束后）|

## 游戏规则

- 玩家球拍在左侧（蓝色），电脑球拍在右侧（红色）
- 中间有球网分隔
- 羽毛球有重力和空气阻力模拟
- 球落在哪边，哪边失分
- 先得 11 分获胜
- 电脑 AI 有延迟和失误设定，不会完美跟踪

## 技术特性

- 使用 Zen-C 语言开发
- 基于 003-framework 游戏框架
- 继承 Game 类实现
- Windows GUI 平台
- 羽毛球物理模拟（重力、阻力、弹性）

## 项目结构

```
073-badminton/
├── src/
│   ├── main_window.zc       # 游戏入口
│   ├── game_logic.zc        # 游戏逻辑 (BadmintonGame类)
│   ├── platform_api.zc      # 平台API
│   ├── platform_api_windows.zc  # Windows实现
│   └── game.zc             # 框架核心
├── build/                  # 构建输出
├── Makefile                # Linux/macOS构建
├── build_windows.bat       # Windows构建
└── README.md               # 本文件
```

## 构建说明

### Windows

```bash
# 使用构建脚本
build_windows.bat

# 或使用 Makefile
make
```

### Linux/macOS

```bash
make
./build/badminton_game
```

## 依赖

- Zen-C 编译器 (zc)
- gcc 编译器（C后端）

安装 Zen-C 编译器:
```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

---

**由 ZenC开发者 AI 助手开发** 🤖
**版本: 1.0.0 | 2026-04-06**
