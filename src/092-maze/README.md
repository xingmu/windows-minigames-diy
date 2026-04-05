# Maze - 迷宫游戏 🧩

Zen-C 语言开发的经典迷宫游戏，基于 003-framework 框架。

## 游戏玩法

- 🧭 从蓝色起点（右上角）移动到绿色出口（右下角）
- 🎯 使用方向键或WASD控制玩家（红色圆点）
- 🔄 按R键重新开始新迷宫
- ⭐ 步数越少分数越高

## 操作说明

| 按键 | 功能 |
|------|------|
| ↑ ↓ ← → | 方向键控制移动 |
| W A S D | 方向键控制移动 |
| R | 重新开始（生成新迷宫）|
| ESC | 退出游戏 |

## 游戏规则

- **起点**: 迷宫左上角（蓝色方块）
- **终点**: 迷宫右下角（绿色方块）
- **墙壁**: 棕色墙壁不可穿过
- **胜利**: 到达绿色出口
- **计分**: 1000 - 步数 × 5，最低100分

## 项目结构

```
092-maze/
├── src/
│   ├── main_window.zc     # 主程序入口
│   ├── game_logic.zc      # 游戏逻辑（迷宫生成等）
│   └── platform_api.zc    # 平台API封装
├── build/                 # 构建输出
├── Makefile               # Linux/macOS构建
├── build_windows.bat      # Windows构建
└── README.md
```

## 构建方法

### Windows

```bash
build_windows.bat
```

或使用 Makefile（需要 MinGW + zc）:

```bash
make
```

### Linux / macOS

```bash
make
```

### 运行游戏

```bash
make run
```

## 技术规格

- **窗口大小**: 600 x 440 像素
- **迷宫大小**: 15 x 11 单元格
- **单元格大小**: 40 x 40 像素
- **帧率**: ~60 FPS
- **迷宫生成**: 递归回溯算法

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
