# Zen-C Tetris Game 🧱

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 俄罗斯方块游戏。

## 🎮 游戏特点

- **经典玩法**: 完整实现俄罗斯方块，7种方块 (I, O, T, S, Z, J, L)
- **流畅操作**: 方向键移动/旋转，空格硬降
- **现代特性**: 使用 Zen-C 类型安全、模式匹配等现代语言特性
- **美观界面**: 彩色方块、游戏区域网格、分数面板
- **完整计分**: 消除1行100分，2行300分，3行500分，4行800分

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
cd windows-minigames-diy/src/005-tetris

# 使用构建脚本
build_windows.bat

# 运行游戏
tetris_game.exe
```

## 🎯 操作说明

| 按键 | 功能 |
|------|------|
| ← → | 左右移动方块 |
| ↑ | 旋转方块 |
| ↓ | 加速下落（软降） |
| 空格 | 硬降（直接落到底部） |
| ESC | 退出游戏 |

## 📊 计分规则

| 消除行数 | 得分 |
|---------|------|
| 1 行 | 100 分 |
| 2 行 | 300 分 |
| 3 行 | 500 分 |
| 4 行 | 800 分 |

## 📁 项目结构

```
005-tetris/
├── src/
│   ├── main_window.zc              # 主程序（游戏逻辑）
│   ├── platform_api.zc             # 平台API（从003-framework复制）
│   ├── platform_api_windows.zc     # Windows平台实现
│   └── game.zc                     # 游戏框架（从003-framework复制）
├── build/                          # 构建输出目录
├── build_windows.bat              # Windows构建脚本
├── Makefile                       # 构建配置
├── README.md                      # 项目说明
├── LICENSE                       # MIT许可证
└── .gitignore                    # Git忽略文件
```

## 🏗️ 技术架构

- **框架**: 003-framework
- **基类**: Game（提供窗口管理、事件循环、画布接口）
- **游戏逻辑**: TetrisGame 类，继承 Game
- **棋盘**: 10x20 格子
- **方块系统**: 7种标准俄罗斯方块，每种4个旋转状态
- **碰撞检测**: 边界 + 棋盘已有方块
- **行消除**: 从下往上检测，触发计分

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-05*
