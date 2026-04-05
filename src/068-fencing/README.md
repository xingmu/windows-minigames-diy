# 068-Fencing 击剑游戏 🧼

> 优雅的剑术对决 — Zen-C 游戏开发

## 🎯 游戏简介

一款基于 Zen-C + 003-framework 开发的击剑对战游戏。玩家与电脑 AI 在标准剑道上进行一对一击剑比赛，先得 5 分者获胜。

## 🎮 游戏特性

- **逼真的击剑动作**: 刺剑 (Thrust)、弓步 (Lunge)、防守 (Parry)
- **智能 CPU 对手**: 具有距离判断、攻击决策和随机躲避的 AI
- **精美的视觉效果**: 剑道场景、命中特效、动作提示
- **完整计分系统**: 先得 5 分获胜，回合计分

## 🕹️ 操作说明

| 按键 | 动作 |
|------|------|
| `A` / `←` | 后退 |
| `D` / `→` | 前进 |
| `J` | 刺剑攻击 |
| `K` | 弓步 (大幅前冲攻击) |
| `S` / `↓` | 防守 (格挡) |
| `R` | 重新开始 (比赛结束后) |
| `Space` / `点击` | 开始回合 |

## 🏗️ 项目结构

```
068-fencing/
├── src/
│   ├── platform_api.zc          # 统一平台接口
│   ├── platform_api_windows.zc  # Windows 平台实现
│   ├── game.zc                  # 游戏框架核心
│   ├── main_window.zc           # 程序入口
│   └── game_logic.zc            # 击剑游戏逻辑
├── docs/design/
│   └── DESIGN.md                # 游戏设计文档
├── build/                        # 构建输出
├── build_windows.bat            # Windows 构建脚本
└── README.md                    # 本文件
```

## 🔧 构建说明

### Windows

```bash
# 使用构建脚本
build_windows.bat

# 或手动编译
zc -O2 -o build/fencing.exe src/main_window.zc src/game_logic.zc src/game.zc
```

### 要求

- Zen-C SDK (zc 编译器)
- Windows 7/10/11

## ⚔️ 游戏规则

1. 玩家 (蓝色) vs CPU (红色)
2. 在剑道上进行一对一决斗
3. 击中对手得分，被击中失分
4. 防守可以格挡攻击
5. 先得 5 分获胜

## 🎨 视觉设计

- **玩家颜色**: 蓝色系 (#2858C8 / #1450A0)
- **CPU 颜色**: 红色系 (#DC2828 / #A01414)
- **剑道**: 木质地板纹理，标准白线标记
- **特效**: 命中时的星爆效果

## 📄 许可证

MIT License

---

**由 ZenC开发者 AI 助手自主开发** 🤖  
*版本: 1.0.0 | 日期: 2026-04-06*
