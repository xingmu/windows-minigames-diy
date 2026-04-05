# Pachinko - 弹珠台游戏 🎱

Zen-C 语言开发的弹珠台游戏，基于 003-framework 框架。

## 游戏玩法

- 🎮 点击或按空格发射弹珠
- 🔼🔽 调整发射力度
- ⚪ 弹珠在钉子间弹跳下落
- 💰 落入底部不同颜色区域获得不同分数
- 🔄 使用左右翻转器将弹珠弹回

## 得分规则

| 颜色 | 分数 |
|------|------|
| 🟡 金色 | 500 分 |
| 🔴 橙红 | 200 分 |
| 🟠 橙色 | 100 分 |
| ⚪ 银色 | 50 分 |
| 🟤 棕色 | 10 分 |

## 操作说明

| 按键 | 功能 |
|------|------|
| 空格 | 发射弹珠 |
| ↑ | 增加发射力度 |
| ↓ | 减少发射力度 |
| ← | 激活左翻转器 |
| → | 激活右翻转器 |
| ESC | 退出游戏 |
| 鼠标点击 | 发射弹珠 |

## 项目结构

```
026-pachinko/
├── src/
│   ├── main_window.zc    # 主程序入口
│   ├── game_logic.zc     # 游戏逻辑
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

- **窗口大小**: 480 x 640 像素
- **帧率**: ~60 FPS
- **钉子**: 8 行 x 9 列，共 72 个
- **弹珠**: 5 个
- **得分区域**: 5 个（10-500分）

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
