# 088-Badminton - 羽毛球游戏 🏸

Zen-C 语言开发的羽毛球游戏，一人对战 AI。

## 游戏介绍

经典羽毛球游戏，玩家控制左侧球拍与 AI 对战。先得 11 分者获胜。

## 操作说明

| 按键 | 功能 |
|------|------|
| W | 球拍上移 |
| S | 球拍下移 |
| A | 球拍左移 |
| D | 球拍右移 |
| 空格 | 发球 |
| ESC | 退出游戏 |
| R | 重新开始（游戏结束后）|

## 游戏规则

- 玩家球拍在左侧，AI 球拍在右侧
- 羽毛球在场地中飞行，受重力影响
- 球拍击中羽毛球会产生反弹
- 球落在边界外对方得分
- 先得 11 分获胜
- AI 有反应延迟和失误设定，不会完美跟踪

## 技术特性

- 使用 Zen-C 语言开发
- 基于 003-framework 游戏框架
- 继承 Game 类实现
- 真实的物理模拟（重力、空气阻力）
- Windows GUI 平台

## 项目结构

```
088-badminton/
├── src/
│   ├── main_window.zc       # 游戏入口
│   ├── game_logic.zc       # 游戏逻辑 (BadmintonGame类)
│   ├── platform_api.zc     # 平台API
│   ├── platform_api_windows.zc  # Windows实现
│   └── game.zc             # 框架核心
├── docs/
│   └── design/
│       └── DESIGN.md       # 游戏设计文档
├── build/                  # 构建输出
├── Makefile               # Linux/macOS构建
├── build_windows.bat      # Windows构建
└── README.md              # 本文件
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
make run
```

## 依赖

- Zen-C 编译器 (zc)
- Windows 10/11 或 Linux/macOS

## 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*游戏版本: 1.0.0 | 最后更新: 2026-04-06*
