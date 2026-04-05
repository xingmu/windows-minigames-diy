# 091-Bowling 保龄球游戏

## 🎳 游戏简介

经典保龄球游戏，使用 Zen-C + 003-framework 构建。

## 🎮 游戏玩法

- **空格键**: 开始游戏/投球
- **方向键 ←/→**: 调整投球角度
- **方向键 ↑/↓**: 调整投球力度
- **R键**: 重新开始

## 📊 计分规则

- 每局10轮，每轮最多投2次
- 每击倒1个球瓶得1分
- Strike（全中）: 一球全倒 = 10分 + 后续两球奖励
- Spare（补中）: 两球全倒 = 10分 + 后续1球奖励
- 第10轮特殊规则：全中可追加投球

## 🏗️ 项目结构

```
091-bowling/
├── README.md
├── src/
│   ├── main_window.zc      # 入口点
│   ├── game_logic.zc       # 游戏逻辑
│   └── platform_api.zc     # 平台API
```

## 🛠️ 构建

```bash
cd src/091-bowling
# 使用 Zen-C 编译器构建
zc build src/main_window.zc -o build/bowling.exe
```

## 🎯 游戏特性

- 真实的保龄球物理模拟
- 精确的球瓶碰撞检测
- 标准保龄球计分系统
- 流畅的60fps游戏体验
