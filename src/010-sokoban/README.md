# Zen-C Sokoban Game 🧊

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 推箱子游戏。

## 🎮 游戏特点

- **经典玩法**: 还原经典推箱子游戏体验
- **三关递进**: 3个精心设计的关卡，难度逐步提升
- **步数记录**: 记录每关步数，挑战最优解
- **美观界面**: 彩色图形界面，专业 UI 设计
- **流畅操控**: 方向键控制，响应迅速

## 🚀 快速开始

### 前提条件

- **Zen-C 编译器**: 需要安装 `zc` 编译器
- **C 编译器**: MinGW 或 MSVC (Windows)
- **操作系统**: Windows 10/11

### 安装 Zen-C 编译器

```bash
# 克隆 Zen-C 仓库
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# 编译并安装
make install
# 可能需要管理员权限
```

### 构建和运行

```bash
# 克隆仓库
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy/src/010-sokoban

# 使用构建脚本
build_windows.bat

# 运行游戏
sokoban_game.exe
```

## 🎯 游戏操作

| 操作 | 功能 |
|------|------|
| ← ↑ → ↓ | 移动玩家 |
| R | 重置当前关卡 |
| N | 下一关（仅在当前关卡完成后）|
| ESC | 退出游戏 |

## 🎨 游戏元素

| 元素 | 颜色 | 描述 |
|------|------|------|
| 玩家 | 蓝色 | 控制它推动箱子 |
| 箱子 | 棕色 | 推到绿色目标点 |
| 目标点 | 绿色 | 箱子放这里就完成 |
| 墙壁 | 深灰色 | 不可通过 |

## 📁 项目结构

```
010-sokoban/
├── src/
│   ├── main_window.zc      # 主程序入口
│   ├── sokoban_logic.zc    # 游戏核心逻辑
│   ├── game.zc             # 框架核心类
│   └── platform_api.zc     # 平台API封装
├── docs/
│   └── design/DESIGN.md    # 游戏设计文档
├── build/                   # 构建输出目录
├── Makefile               # 构建配置
├── build_windows.bat      # Windows 构建脚本
└── README.md              # 本文件
```

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
