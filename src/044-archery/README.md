# Archery - 射箭游戏 🏹

一款基于 Zen-C 和 003-framework 开发的射箭游戏。

## 🎮 游戏特色

- **鼠标瞄准** - 弓的方向跟随鼠标移动
- **蓄力射击** - 按住鼠标左键蓄力，松开射击
- **抛物线轨迹** - 箭矢受重力影响，飞行轨迹自然
- **风力系统** - 每回合风力不同，影响箭矢飞行
- **环形靶心** - 金心50分、蓝圈30分、白圈10分
- **连击奖励** - 连续命中获得额外分数加成
- **5回合挑战** - 每回合10支箭，共50支箭

## 📐 控制说明

| 操作 | 说明 |
|------|------|
| 鼠标移动 | 瞄准方向 |
| 按住左键 | 蓄力（Power条显示） |
| 松开左键 | 发射箭矢 |
| ESC | 退出游戏 |

## 🎯 计分规则

- **Bullseye (金心)** - 50分
- **Inner Ring (蓝圈)** - 30分  
- **Outer Ring (白圈)** - 10分
- **连击奖励** - 连击数 × 5 额外加分

## 🛠 构建说明

### Windows 构建

```batch
build_windows.bat
```

或使用 Makefile：

```bash
make windows
```

### Linux/macOS 构建

```bash
make
```

### 运行游戏

```bash
./build/archery
```

## 📁 项目结构

```
044-archery/
├── src/
│   ├── platform_api.zc        # 统一平台接口
│   ├── platform_api_windows.zc # Windows 平台实现
│   ├── game.zc                # 游戏框架核心
│   ├── game_logic.zc          # 游戏逻辑
│   └── main_window.zc         # 主程序入口
├── docs/
│   └── design/DESIGN.md       # 设计文档
├── build/                     # 构建输出
├── Makefile                   # 构建配置
├── build_windows.bat          # Windows 构建脚本
└── README.md                  # 本文件
```

## 🧘 Zen-C 之道

> "简洁是终极优雅。"

本游戏使用 Zen-C 语言开发，遵循简洁优雅的编程理念。

---

**由 ZenC开发者 AI 助手创建** 🤖  
*版本: 1.0.0 | 2026-04-06*
