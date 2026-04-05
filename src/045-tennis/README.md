# 045-Tennis - 网球游戏

Zen-C 网球游戏，玩家 vs 电脑，鼠标挥拍控制。

## 🎮 游戏介绍

一款模拟网球运动的休闲游戏，玩家与电脑对战，体验网球运动的乐趣。

### 游戏特性

- **玩家 vs 电脑** - 与智能AI对战
- **鼠标挥拍** - 点击鼠标发球和挥拍
- **真实物理** - 球的抛物线运动和碰撞
- **网球计分** - 遵循网球规则（0, 15, 30, 40, Game）

## 🕹️ 操作说明

| 操作 | 功能 |
|------|------|
| 鼠标左键点击(下方区域) | 发球 |
| 鼠标左键按下+拖动 | 挥拍击球 |
| R键 | 重新开始游戏 |

## 📐 游戏规则

- 每局先赢6局且领先2局获胜
- 每分采用网球计分：0 → 15 → 30 → 40 → Game
- 击中球拍的位置会影响球的反弹角度
- 挥拍速度影响球的力度

## 🛠️ 构建说明

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

### Windows 构建

```bash
# 使用构建脚本
build_windows.bat

# 或使用 Makefile
make
```

### Linux/macOS 构建

```bash
make
./build/tennis_game
```

## 📁 项目结构

```
045-tennis/
├── src/
│   ├── platform_api.zc         # 平台接口定义
│   ├── platform_api_windows.zc # Windows平台实现
│   ├── game.zc                 # 游戏框架
│   ├── game_logic.zc           # 网球游戏逻辑
│   └── main_window.zc          # 入口点
├── docs/
│   └── design/DESIGN.md        # 设计文档
├── build/                      # 构建输出
├── Makefile                    # 构建配置
├── build_windows.bat           # Windows构建
└── README.md                   # 本文件
```

## 🎯 游戏界面

- **上方** - 电脑区域
- **中间** - 球网分隔
- **下方** - 玩家区域
- **底部** - 分数显示

---

**由 ZenC开发者 AI 助手自主管理** 🤖
