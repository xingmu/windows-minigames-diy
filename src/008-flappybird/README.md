# FlappyBird - Zen-C

![Zen-C](https://img.shields.io/badge/Zen-C-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20GUI-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

经典 FlappyBird 游戏，使用 Zen-C 语言开发，Windows GUI 版本。

## 🎮 游戏截图

游戏运行后显示浅蓝色天空，黄色小鸟从左向右飞行，绿色管道从右向左移动。

## 📋 游戏规则

- 小鸟受重力影响自动下落
- 按 **空格键** 或 **上箭头** 让小鸟向上飞
- 穿越管道间隙得 **+1 分**
- 撞到管道或边界则游戏结束
- 撞到地面或天花板游戏结束

## 🎯 操作说明

| 按键 | 功能 |
|------|------|
| 空格 / 上箭头 | 向上飞 |
| ESC | 退出游戏 |
| 鼠标左键 | 向上飞 (备用) |

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
build\flappybird.exe

# 或双击 build/flappybird.exe
```

## 📁 项目结构

```
008-flappybird/
├── src/
│   ├── main_window.zc           # 游戏主程序
│   ├── platform_api.zc           # 平台 API 接口
│   ├── platform_api_windows.zc  # Windows 平台实现
│   └── game.zc                  # 游戏框架 (参考)
├── docs/
│   └── design/
│       └── DESIGN.md            # 游戏设计文档
├── build/                       # 构建输出
├── Makefile                     # Make 构建配置
├── build_windows.bat           # Windows 构建脚本
└── README.md                    # 本文件
```

## 🎨 游戏配置

| 参数 | 值 | 说明 |
|------|-----|------|
| 窗口宽度 | 400 | 像素 |
| 窗口高度 | 600 | 像素 |
| 目标帧率 | 60 | FPS |
| 小鸟半径 | 15 | 像素 |
| 管道宽度 | 60 | 像素 |
| 管道间隙 | 150 | 像素 |
| 重力 | 800 | 像素/秒² |
| 跳跃速度 | -350 | 像素/秒 |
| 管道速度 | 180 | 像素/秒 |

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
const GRAVITY: int = 800;        // 调整重力
const JUMP_VELOCITY: int = -350; // 调整跳跃力度
const PIPE_GAP: int = 150;       // 调整管道间隙难度
```

## 📜 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

## 👤 作者

**ZenC开发者 AI 助手**

---

*版本: 1.0.0 | 最后更新: 2026-04-06*
