# 094-Minesweeper - 扫雷游戏 💣

Zen-C 语言开发的经典扫雷游戏，基于 003-framework 框架。

## 游戏玩法

- 🖱️ **左键点击** 揭开格子
- 🚩 **右键点击** 标记/取消标记地雷
- 💣 揭开地雷 = 游戏结束
- 🏆 揭开所有安全格子 = 胜利
- ⏱️ 计时器记录游戏时间
- 💣 剩余地雷数量显示

## 操作说明

| 按键/操作 | 功能 |
|------|------|
| 左键点击 | 揭开格子 |
| 右键点击 | 标记/取消标记地雷 |
| R | 重新开始 |
| ESC | 退出游戏 |

## 游戏规则

- 9x9 网格，共 10 个地雷
- 数字表示周围8个格子中的地雷数量
- 数字 1 = 蓝色, 2 = 绿色, 3 = 红色, 4 = 紫色...
- 未揭开的格子显示为灰色方块
- 标记地雷的格子显示 🚩

## 项目结构

```
094-minesweeper/
├── src/
│   ├── main_window.zc    # 主程序入口
│   ├── game_logic.zc     # 扫雷核心逻辑
│   └── platform_api.zc   # 平台API封装
├── build/                  # 构建输出
├── Makefile              # Linux/macOS构建
├── build_windows.bat     # Windows构建
└── README.md
```

## 构建方法

### Windows

```bash
build_windows.bat
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

- **窗口大小**: 400 x 500 像素
- **网格**: 9 x 9
- **地雷数**: 10
- **每个格子**: ~40 x 40 像素

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
