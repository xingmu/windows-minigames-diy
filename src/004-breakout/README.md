# Breakout - 打砖块游戏 🧱

Zen-C 语言开发的经典打砖块游戏，基于 003-framework 框架。

## 游戏玩法

- 🎮 控制底部挡板反弹小球
- 🧱 击破顶部彩色砖块获得分数
- ⭐ 每击破一块砖块得 10 分
- ❤️ 有 3 条生命，球落底失去一条

## 操作说明

| 按键 | 功能 |
|------|------|
| ← → | 控制挡板左右移动 |
| 空格 | 开始游戏 / 发射球 |
| R | 重新开始（游戏结束后）|
| ESC | 退出游戏 |

## 游戏状态

- **Ready**: 等待开始，按空格发射球
- **Playing**: 游戏中
- **Lost**: 生命耗尽
- **Won**: 清除所有砖块

## 项目结构

```
004-breakout/
├── src/
│   ├── main_window.zc    # 主程序入口
│   ├── game_logic.zc     # 游戏逻辑
│   └── platform_api.zc    # 平台API封装
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

- **窗口大小**: 800 x 600 像素
- **帧率**: ~60 FPS
- **砖块**: 5 行 x 10 列，共 50 块
- **初始生命**: 3 条

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
