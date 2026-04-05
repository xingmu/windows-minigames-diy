# 064-Skiing（滑雪）- 障碍躲避游戏 🎿

Zen-C 语言开发的滑雪障碍躲避游戏，基于 003-framework 框架。

## 游戏玩法

- 🎿 控制滑雪者左右移动躲避障碍
- 🎄 障碍物包括：树木、岩石、雪堆
- ⭐ 躲避成功获得分数，每秒+10分
- 🏆 撞到障碍物游戏结束
- ❄️ 速度逐渐加快，挑战更高分数

## 操作说明

| 按键 | 功能 |
|------|------|
| ← → 或 A/D | 控制滑雪者左右移动 |
| 空格 | 开始游戏 / 重新开始 |
| ESC | 退出游戏 |

## 游戏状态

- **Ready**: 等待开始，按空格开始
- **Playing**: 滑雪中，躲避障碍
- **GameOver**: 撞到障碍物

## 项目结构

```
064-skiing/
├── src/
│   ├── platform_api.zc           # 平台API（从003-framework复制）
│   ├── platform_api_windows.zc  # Windows平台实现
│   └── main_window.zc           # 游戏主程序
├── build/                        # 构建输出
├── Makefile                      # Linux/macOS构建
├── build_windows.bat             # Windows构建
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

- **窗口大小**: 480 x 720 像素
- **帧率**: 60 FPS
- **障碍物类型**: 3种（树木、岩石、雪堆）
- **初始速度**: 5 像素/帧
- **速度增量**: 每10秒 +0.5

## 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🤖
