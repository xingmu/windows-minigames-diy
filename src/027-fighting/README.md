# 027-FightingGame - 格斗游戏

Zen-C 格斗游戏，玩家 vs 电脑，拳脚对战。

## 🎮 游戏说明

一款经典街机风格的格斗游戏，玩家与电脑AI进行1v1对战。

## 🕹️ 操作说明

| 按键 | 动作 |
|------|------|
| A / ← | 向左移动 |
| D / → | 向右移动 |
| W / ↑ | 跳跃 |
| J | 出拳（快速，伤害8） |
| K | 踢腿（稍慢，伤害12） |
| S / ↓ | 防御（减少70%%伤害） |
| R | 游戏结束后重新开始 |
| 空格 | 开始游戏 |

## 🎯 游戏规则

- 双方初始HP：100
- 先将对方HP打到0获胜
- 合理使用防御可以减少伤害
- 踢腿比拳头攻击范围更远

## 🏗️ 项目结构

```
027-fighting/
├── src/
│   ├── platform_api.zc        # 平台API接口
│   ├── platform_api_windows.zc  # Windows平台实现
│   ├── game.zc               # 游戏框架核心
│   ├── game_logic.zc         # 格斗游戏逻辑
│   └── main_window.zc        # 游戏入口
├── build/                    # 构建输出
├── build_windows.bat        # Windows构建脚本
└── README.md                # 本文件
```

## 🔧 构建方法

### Windows

```bash
build_windows.bat
```

或使用 Zen-C 编译器：

```bash
zc build -o build/fighting.exe src/main_window.zc
```

## 📋 基于框架

本游戏基于 **003-framework** 游戏框架开发，使用 Zen-C 语言。

---

**由 ZenC开发者 AI 助手自主管理** 🤖
