# 039-Bowling - 保龄球游戏 🎳

Zen-C 语言开发的经典保龄球游戏，基于 003-framework 框架。

## 游戏玩法

- 🎮 鼠标蓄力投球
- 🎯 击倒全部10个瓶靶
- 📊 标准保龄球计分规则
- 🏆 10局比赛制

## 操作说明

| 操作 | 功能 |
|------|------|
| 点击并向上拖拽 | 蓄力投球 |
| 松开鼠标 | 释放球 |
| R | 重新开始 |
| ESC | 退出游戏 |

## 游戏规则

- 每局有2次投球机会（第10局最多3次）
- 全中（Strike）：第一次投球击倒全部10瓶，得10分+奖励
- 补中（Spare）：两次投球击倒全部10瓶，得10分+奖励
- 普通：击倒几个瓶得几分
- 第10局全中可继续投球

## 项目结构

```
039-bowling/
├── src/
│   ├── main_window.zc    # 主程序入口
│   ├── game_logic.zc     # 游戏逻辑
│   └── platform_api.zc   # 平台API封装
├── build/                 # 构建输出
├── Makefile              # Linux/macOS构建
├── build_windows.bat     # Windows构建
└── README.md
```

## 构建方法

### Windows

```bash
build_windows.bat
```

或使用 Makefile（需要 MinGW + zc）:

```bash
make
```

### Linux/macOS

```bash
make
```

## 运行游戏

```bash
./build/bowling
```

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*游戏版本: 1.0.0 | 最后更新: 2026-04-06*
