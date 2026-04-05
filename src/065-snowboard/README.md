# 065-Snowboard - Zen-C 单板滑雪游戏

![Zen-C](https://img.shields.io/badge/Zen--C-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-green)
![Framework](https://img.shields.io/badge/Framework-003--framework-yellow)

## 🎿 游戏简介

一款纯 Zen-C 语言开发的单板滑雪游戏。玩家控制滑雪者在雪道上躲避障碍物（树木、石头、旗帜），尽可能滑得更远获得高分。

## 🎮 游戏特色

- **纯 Zen-C 开发**：无外部依赖，使用 Windows GUI
- **流畅帧率**：60 FPS 游戏主循环
- **渐进难度**：速度随游戏时间逐渐加快
- **丰富障碍物**：树木、石头、旗帜三种类型
- **粒子效果**：飘雪动画增强沉浸感
- **物理倾斜**：滑雪者左右移动时身体倾斜

## 🕹️ 操作说明

| 按键 | 功能 |
|------|------|
| ← / A | 向左移动 |
| → / D | 向右移动 |
| 鼠标点击 | 开始/重新开始 |
| ESC | 退出游戏 |

## 📁 项目结构

```
065-snowboard/
├── src/
│   ├── main_window.zc          # 游戏主程序
│   ├── platform_api.zc         # 平台 API 接口
│   └── platform_api_windows.zc # Windows 平台实现
├── build/                      # 构建输出
├── docs/
│   └── design/DESIGN.md        # 游戏设计文档
├── Makefile                    # 构建配置
└── README.md                   # 本文件
```

## 🔧 构建方法

### 前置依赖

- zc 编译器 (Zen-C 编译器)
- gcc 编译器 (MinGW)

### 安装 zc 编译器

```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
# 将 build/zc 添加到系统 PATH
```

### 编译游戏

```bash
make all
```

### 运行游戏

```bash
make run
```

## 📐 游戏设计

### 画面规格

- 窗口尺寸：480 x 640 像素
- 帧率：60 FPS
- 雪道宽度：360 像素

### 障碍物类型

| 类型 | 尺寸 | 碰撞框 |
|------|------|--------|
| 树木 | 28 x 36 | 全尺寸 |
| 石头 | 30 x 20 | 全尺寸 |
| 旗帜 | 6 x 40 | 全尺寸 |

### 物理参数

- 初始速度：280 像素/秒
- 最大速度：600 像素/秒
- 侧向速度：280 像素/秒
- 侧向摩擦：600 像素/秒²

## 📄 许可证

MIT License - 查看 [LICENSE](../../LICENSE) 文件了解详情。

---

**由 ZenC开发者 AI 助手开发** 🤖  
*游戏版本: 1.0.0 | 创建日期: 2026-04-06*
