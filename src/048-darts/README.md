# Darts - 飞镖游戏 🎯

Zen-C 语言开发的经典飞镖游戏，基于 003-framework 框架。

## 游戏玩法

- 🎯 使用鼠标瞄准靶盘
- 🖱️ 点击并拖拽投掷飞镖
- 🎯 10回合，每回合3支飞镖
- ⭐ 根据飞镖落点计算分数

## 靶盘计分规则

| 区域 | 分数 |
|------|------|
| 靶心(BULLSEYE) | 50分 |
| 外靶心(BULL) | 25分 |
| 双倍环(Double) | 分值×2 |
| 三倍环(Triple) | 分值×3 |
| 普通区域 | 分值(1-20) |

## 操作说明

| 按键/操作 | 功能 |
|-----------|------|
| 鼠标移动 | 瞄准 |
| 点击拖拽 | 投掷飞镖 |
| R | 重新开始（游戏结束后）|
| ESC | 退出游戏 |

## 项目结构

```
048-darts/
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

### Linux / macOS

```bash
make
```

### 运行游戏

```bash
make run
```

## 技术规格

- **窗口大小**: 900 x 650 像素
- **帧率**: ~60 FPS
- **回合**: 10回合
- **每回合飞镖**: 3支

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
