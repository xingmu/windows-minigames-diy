# 013-Ludo - 飞行棋

![Zen-C](https://img.shields.io/badge/Zen-C-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20GUI-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

经典飞行棋游戏，使用 Zen-C 语言开发，Windows GUI 版本。

## 🎮 游戏说明

飞行棋（Ludo）是一种经典的四人飞行棋盘游戏。本游戏为双人版本：**玩家（红方）** 对阵 **电脑（蓝方）**。

## 📋 游戏规则

- **目标**: 最先将全部 4 枚棋子移动到终点（中心）的一方获胜
- **掷6规则**: 掷到 6 点可以继续投掷，连续 3 次掷到 6 则强制换手
- **出动规则**: 棋子在家中时，需要掷到 6 才能出动到起点
- **吃子规则**: 落在非安全格时可吃掉对方棋子，被吃的棋子返回对方基地
- **安全格**: 两个起点位置是安全格，在安全格不会被吃

## 🎯 操作说明

| 按键/操作 | 功能 |
|-----------|------|
| 空格键 | 掷骰子 |
| 鼠标左键 | 选择并移动棋子 |
| ESC | 退出游戏 |

## 🚀 快速开始

### 环境要求

- Zen-C 编译器 (`zc`)
- MinGW 或 GCC 编译器 (Windows)

### 安装 Zen-C 编译器

```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
# 将 build/zc 添加到系统 PATH
```

### 构建游戏

**Windows:**
```bash
# 方法一: 使用构建脚本
build_windows.bat

# 方法二: 使用 Makefile
make
```

### 运行游戏

```bash
# Windows
build\ludo.exe

# 或双击 build/ludo.exe
```

## 📁 项目结构

```
013-ludo/
├── src/
│   ├── main_window.zc           # 游戏主程序
│   ├── platform_api.zc           # 平台 API 接口
│   ├── platform_api_windows.zc  # Windows 平台实现
│   ├── game.zc                   # 游戏框架
│   └── ludo_logic.zc             # 飞行棋游戏逻辑
├── docs/
│   └── design/
│       └── DESIGN.md            # 游戏设计文档
├── build/                        # 构建输出
├── Makefile                      # Make 构建配置
├── build_windows.bat            # Windows 构建脚本
└── README.md                     # 本文件
```

## 🎨 游戏界面

- **红方（左侧）**: 玩家控制
- **蓝方（右侧）**: 电脑控制
- **中心**: 终点区域
- **骰子**: 右下角实时显示

## 🛠️ 开发

### 编译选项

```bash
# 清理构建
make clean

# 构建游戏
make
```

### 修改游戏参数

编辑 `src/ludo_logic.zc` 中的配置常量。

## 📜 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

## 👤 作者

**ZenC开发者 AI 助手**

---

*版本: 1.0.0 | 最后更新: 2026-04-06*
