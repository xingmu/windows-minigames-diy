# 038-RacingPlus 俯视角赛车游戏增强版

## 🎮 游戏简介

Zen-C + 003-framework 开发的俯视角赛车游戏增强版，**更多赛道，更高难度！**

## 🕹️ 操作说明

| 按键 | 功能 |
|------|------|
| ↑ | 加速 |
| ← | 左转 |
| → | 右转 |
| SPACE | 刹车 |
| ESC | 返回菜单/退出 |
| ENTER | 开始比赛 |

## 🚗 游戏特性

### 多赛道系统
- **5条风格各异的赛道**，难度递增
- 椭圆赛道、技术赛道、8字赛道、卡丁车道、高速赛道

### 难度系统
- **Easy** - 宽赛道，无障碍物
- **Normal** - 中等赛道，少量障碍
- **Hard** - 窄赛道，多障碍，有时间限制
- **Extreme** - 最窄赛道，大量障碍，严格时间限制

### 物理系统
- **真实惯性**：赛车具有质量感和惯性
- **速度相关转向**：高速时转向效率降低
- **地形摩擦**：赛道内外摩擦系数不同
- **障碍物碰撞**：撞到障碍物会反弹

### 视觉效果
- 轮胎痕迹
- 尘土粒子效果
- 速度线效果
- 速度表动态颜色

### 竞赛系统
- 圈数计时
- 最佳圈速记录
- 时间限制挑战
- 检查点通过提示

## 🏗️ 项目结构

```
038-racingplus/
├── src/
│   ├── main_window.zc           # 游戏主逻辑
│   ├── platform_api.zc         # 平台API定义
│   ├── platform_api_windows.zc # Windows平台实现
│   └── game.zc                  # 游戏框架核心
├── build/                        # 构建输出
├── Makefile                      # Linux/macOS 构建
├── build_windows.bat            # Windows 构建
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
./build/038-racingplus.exe
```

## 🏁 赛道介绍

| 赛道名称 | 类型 | 难度 | 圈数 | 时间限制 |
|---------|------|------|------|---------|
| Sunset Oval | 椭圆 | Easy | 3 | 无 |
| Technical Twist | 技术 | Normal | 3 | 无 |
| Figure-8 Fury | 8字 | Hard | 3 | 2分钟 |
| Karting Chaos | 卡丁车 | Hard | 4 | 2.5分钟 |
| Speedway Extreme | 高速 | Extreme | 5 | 3分钟 |

## 📐 游戏设计

- **视角**：俯视角 (Top-Down)
- **分辨率**：900 x 700
- **帧率**：60 FPS

### 物理模型

- 最大速度：10
- 加速：4
- 转向：5 (与速度相关)
- 赛道摩擦：0.97
- 赛道外摩擦：0.88

## 📝 开发信息

- **版本**：1.0.0
- **框架**：Zen-C 003-framework v1.0.0
- **基于**：024-Racing 俯视角赛车游戏

---

**Zen-C 游戏系列 | 038-RacingPlus** 🧘
