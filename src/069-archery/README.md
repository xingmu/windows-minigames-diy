# 069-Archery 射箭游戏

Zen-C 语言开发的射箭游戏，使用 003-framework 框架。

## 游戏特性

- 🎯 **鼠标瞄准** - 使用鼠标控制弓箭方向
- 🏹 **真实物理** - 弓箭受重力和风力影响
- 🎨 **精美画面** - GDI双缓冲渲染
- 🎮 **简单操作** - 点击射箭，空格下一轮

## 游戏规则

1. 使用鼠标瞄准弓箭方向
2. 点击左键射出弓箭
3. 弓箭受重力和风力影响
4. 击中目标环获得不同分数：
   - 靶心（金色）: 100分
   - 中环（红色）: 50分
   - 外环（白色）: 20分
5. 距离越远分数越高
6. 每回合5支弓箭，共3回合

## 操作说明

| 按键 | 功能 |
|------|------|
| 鼠标移动 | 调整瞄准方向 |
| 鼠标左键 | 射箭 |
| 空格键 | 下一回合 |
| R 键 | 重新开始 |
| ESC 键 | 退出游戏 |

## 编译方法

### Windows

```bash
# 方法1: 使用批处理脚本
build_windows.bat

# 方法2: 使用 Makefile (需要 make)
make

# 方法3: 手动编译
zc build -o build/archery_game.exe src/main_window.zc
```

### Linux/macOS

```bash
make
./build/archery_game
```

## 目录结构

```
069-archery/
├── src/
│   ├── main_window.zc      # 主程序入口
│   ├── game_logic.zc       # 游戏逻辑
│   └── platform_api.zc     # 平台API封装
├── build_windows.bat       # Windows构建脚本
├── Makefile                # Make构建文件
├── README.md               # 本文件
└── LICENSE                 # MIT许可证
```

## 技术实现

- **语言**: Zen-C
- **图形**: Windows GDI (双缓冲)
- **架构**: 事件驱动游戏循环
- **框架**: 基于 003-framework

## 开发背景

本游戏是 Windows Mini Games DIY 项目的一部分，使用 Zen-C 语言开发，旨在展示如何使用简洁优雅的代码创建有趣的游戏。

## 许可证

MIT License - 详见 LICENSE 文件
