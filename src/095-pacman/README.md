# Zen-C Pacman - 吃豆人游戏

经典吃豆人游戏的Zen-C实现，支持Windows/Linux/macOS跨平台运行。

## 游戏特性

- 🎮 经典玩法：控制吃豆人收集所有豆子
- 👻 四种幽灵：Blinky（红）、Pinky（粉）、Inky（青）、Clyde（橙）
- ⚡ 大力丸：吃掉后可以反吃幽灵
- 📊 分数系统：记录得分和游戏等级
- 🏠 迷宫设计：还原经典28x31迷宫
- 🎨 霓虹风格：现代视觉设计

## 控制说明

| 按键 | 功能 |
|------|------|
| W / ↑ | 向上移动 |
| S / ↓ | 向下移动 |
| A / ← | 向左移动 |
| D / → | 向右移动 |
| 空格 | 暂停/继续 |
| R | 重新开始（游戏结束后） |
| ESC | 退出游戏 |

## 构建方法

### 1. 安装 Zen-C 编译器

```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

### 2. 编译游戏

```bash
make all
```

### 3. 运行游戏

```bash
make run
```

## 项目结构

```
095-pacman/
├── Makefile           # 构建脚本
├── README.md          # 项目说明
├── LICENSE            # MIT许可证
├── .gitignore         # Git忽略文件
└── src/
    ├── main_window.zc # 主程序入口
    ├── game_logic.zc  # 游戏逻辑
    └── platform_api.zc # 跨平台API
```

## 游戏规则

1. 吃豆人在迷宫中移动，收集所有金色豆子
2. 避开幽灵，被抓到失去一条生命
3. 吃掉红色大力丸后，幽灵变蓝，可以反吃
4. 吃完所有豆子进入下一关
5. 初始有3条生命

## 幽灵AI

- **Blinky（红）**：直接追击吃豆人
- **Pinky（粉）**：包围战术，在吃豆人前方等待
- **Inky（青）**：协同攻击，配合Blinky
- **Clyde（橙）**：害羞型，距离远时追击，近时逃跑

## 技术实现

- 纯Zen-C语言编写
- 跨平台Windows/Linux/macOS支持
- 帧缓冲图形渲染
- 定时器驱动的游戏循环

## 许可证

MIT License

## 作者

Zen-C 开发团队

## 致谢

- Zen-C 语言：https://github.com/z-libs/Zen-C
