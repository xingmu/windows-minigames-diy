# 084-Basketball 🏀

Zen-C 篮球投篮练习游戏

## 📦 游戏简介

一款简洁的篮球投篮练习游戏，使用 Zen-C 语言和 003-framework 框架开发。

## 🎮 游戏玩法

- **↑/↓ 方向键**: 调整投篮角度
- **←/→ 方向键**: 调整投篮力量
- **空格键**: 投篮
- **R 键**: 重置球位
- **ESC**: 退出

## 🎯 游戏目标

- 将篮球投入篮筐得分
- 每次进球得 2 分
- 尽量提高命中率和总得分

## 🏗️ 项目结构

```
084-basketball/
├── src/
│   ├── platform_api.zc         # 平台接口定义
│   ├── platform_api_windows.zc # Windows 平台实现
│   ├── game.zc                # 游戏核心类
│   └── main_window.zc         # 篮球游戏主程序
├── build/                      # 构建输出
├── build_windows.bat          # Windows 构建脚本
└── README.md                   # 本文件
```

## 🔧 构建说明

### Windows 构建

```bash
build_windows.bat
```

或使用 Makefile:

```bash
make
```

## 📋 系统要求

- Windows 操作系统
- Zen-C 编译器 (zc)

## 🧘 Zen-C 之道

> "简洁是终极优雅。"

本游戏遵循 Zen-C 的设计哲学，代码简洁、优雅、高效。

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*游戏版本: 1.0.0 | 发布: 2026-04-06*
