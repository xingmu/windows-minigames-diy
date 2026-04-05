# 085-Volleyball - 排球游戏 🏐

Zen-C 语言开发的排球游戏，一人对战电脑 AI。

## 游戏介绍

经典排球游戏，玩家控制左侧蓝色球员与电脑（红色）对战。先得 15 分者获胜。

## 操作说明

| 按键 | 功能 |
|------|------|
| A / ← | 球员左移 |
| D / → | 球员右移 |
| W / ↑ / 空格 | 跳跃 |
| ESC | 退出游戏 |
| R | 重新开始（游戏结束后）|

## 游戏规则

- 玩家（蓝色）在左侧，电脑（红色）在右侧
- 球在场地中反弹，球员可以击球
- 球落在对方场地，对方得分
- 先得 15 分获胜
- 每得一分后，由得分方发球

## 技术特性

- 使用 Zen-C 语言开发
- 基于 003-framework 游戏框架
- 继承 Game 类实现
- 物理引擎：重力、碰撞检测
- AI 对手：智能追踪和跳跃

## 项目结构

```
085-volleyball/
├── src/
│   ├── main_window.zc       # 游戏入口
│   ├── game_logic.zc        # 游戏逻辑 (VolleyballGame类)
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
./build/volleyball_game
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
