# Volleyball - Zen-C

![Zen-C](https://img.shields.io/badge/Zen-C-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20GUI-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

排球游戏，玩家 vs 电脑。使用 Zen-C 语言开发，Windows GUI 版本。

## 🎮 游戏截图

游戏运行后显示蓝色排球场，双方各有球拍和发球线，中间有球网。

## 📋 游戏规则

- 玩家控制底部球拍（橙色），电脑控制顶部球拍（红色）
- 按 **空格键** 或 **鼠标左键** 发球
- 按 **左右方向键** 或 **鼠标移动** 控制球拍
- 球在飞行过程中可以改变方向和速度
- 先得 **21 分** 的一方获胜

## 🎯 操作说明

| 按键 | 功能 |
|------|------|
| 空格 / 左键 | 发球 / 开始游戏 |
| ← / → | 左右移动球拍 |
| 鼠标移动 | 控制球拍水平位置 |
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
build\volleyball.exe

# 或双击 build/volleyball.exe
```

## 📁 项目结构

```
050-volleyball/
├── src/
│   ├── main_window.zc           # 游戏主程序
│   ├── platform_api.zc          # 平台 API 接口
│   ├── platform_api_windows.zc # Windows 平台实现
│   └── game.zc                  # 游戏框架 (参考)
├── docs/                        # 文档
├── build/                       # 构建输出
├── Makefile                     # Make 构建配置
├── build_windows.bat           # Windows 构建脚本
└── README.md                    # 本文件
```

## 🎨 游戏配置

| 参数 | 值 | 说明 |
|------|-----|------|
| 窗口宽度 | 480 | 像素 |
| 窗口高度 | 640 | 像素 |
| 目标帧率 | 60 | FPS |
| 玩家球拍颜色 | 橙色 | RGB(255,100,50) |
| 电脑球拍颜色 | 红色 | RGB(255,50,50) |
| 球拍宽度 | 100 | 像素 |
| 球拍高度 | 15 | 像素 |
| 球半径 | 12 | 像素 |
| 初始球速 | 6 | 像素/帧 |
| 最大球速 | 14 | 像素/帧 |
| 获胜分数 | 21 | 分 |

## 🛠️ 开发

### 编译选项

```bash
# 测试编译器
make test

# 清理构建
make clean

# 仅编译
make all
```

### 修改游戏参数

编辑 `src/main_window.zc` 中的配置常量：

```zen-c
const BALL_SPEED_INIT: int = 6;    // 调整初始球速
const PADDLE_WIDTH: int = 100;     // 调整球拍宽度
const WIN_SCORE: int = 21;         // 调整获胜分数
```

## 📜 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

## 👤 作者

**ZenC开发者 AI 助手**

---

*版本: 1.0.0 | 最后更新: 2026-04-06*
