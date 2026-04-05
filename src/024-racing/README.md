# 024-Racing 俯视角赛车游戏

## 🎮 游戏简介

Zen-C + 003-framework 开发的俯视角赛车游戏，操作简单直观。

## 🕹️ 操作说明

| 按键 | 功能 |
|------|------|
| ↑ | 加速 |
| ← | 左转 |
| → | 右转 |
| ESC | 退出游戏 |

## 🚗 游戏特性

- **真实物理**：赛车具有惯性、摩擦力和速度限制
- **赛道系统**：矩形赛道，带检查点和圈数计算
- **速度显示**：实时速度表，off-track 警告
- **计时系统**：比赛计时器

## 🏗️ 项目结构

```
024-racing/
├── src/
│   ├── main_window.zc           # 游戏主逻辑
│   ├── platform_api.zc         # 平台API定义
│   ├── platform_api_windows.zc # Windows平台实现
│   └── game.zc                  # 游戏框架核心
├── build/                        # 构建输出
├── Makefile                      # Linux/macOS 构建
├── build_windows.bat            # Windows 构建
├── docs/design/DESIGN.md        # 设计文档
└── README.md                     # 本文件
```

## 🔧 构建方法

### Windows

```bash
build_windows.bat
```

### Linux/macOS

```bash
make
```

### 直接运行

```bash
./build/024-racing.exe
```

## 📐 游戏设计

- **视角**：俯视角 (Top-Down)
- **分辨率**：800 x 600
- **帧率**：60 FPS
- **赛道**：矩形环形赛道

### 物理模型

- 速度范围：-MAX/2 ~ MAX
- 转向效率与速度成正比
- 赛道内摩擦力：0.98
- 草地摩擦力：0.92 (减速效果)

## 📝 开发信息

- **版本**：1.0.0
- **框架**：Zen-C 003-framework v1.0.0
- **平台**：Windows (Linux/macOS 待适配)

---

**Zen-C 游戏系列 | 024-Racing** 🧘
