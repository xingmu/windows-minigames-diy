# 075-Cricket - 板球游戏

Zen-C 板球游戏，玩家击球对战电脑，体验板球运动的乐趣。

## 🎮 游戏介绍

一款模拟板球运动的休闲游戏，玩家作为击球手与电脑投球手对战，体验精准挥杆的快乐。

### 游戏特性

- **玩家 vs 电脑** - 与智能AI投球手对战
- **鼠标挥杆** - 点击鼠标挥杆击球
- **真实物理** - 球的弹跳和飞行轨迹
- **跑位得分** - 根据击球质量和时机获得分数

## 🕹️ 操作说明

| 操作 | 功能 |
|------|------|
| 鼠标左键点击 | 挥杆击球 |
| 移动鼠标 | 调整挥杆时机 |
| R键 | 重新开始游戏 |

## 📐 游戏规则

- 投球手投出6个球为一轮(over)
- 击中球获得跑位分数(1-6分)
- 未击中球得0分
- 三次未击中出局(out)
- 获得最高分获胜

## 🛠️ 构建说明

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

### Windows 构建

```bash
build_windows.bat
```

### Linux/macOS 构建

```bash
make
./build/cricket_game
```

## 📁 项目结构

```
075-cricket/
├── src/
│   ├── platform_api.zc          # 平台接口定义
│   ├── platform_api_windows.zc  # Windows平台实现
│   ├── game.zc                  # 游戏框架
│   ├── game_logic.zc           # 板球游戏逻辑
│   └── main_window.zc          # 入口点
├── docs/
│   └── design/DESIGN.md        # 设计文档
├── build/                      # 构建输出
├── Makefile                    # 构建配置
├── build_windows.bat           # Windows构建
└── README.md                   # 本文件
```

## 🎯 游戏界面

- **上方** - 投球手区域
- **中间** - 球场
- **下方** - 击球手区域
- **左侧** - 分数和出局数显示

---

**由 ZenC开发者 AI 助手自主管理** 🤖
