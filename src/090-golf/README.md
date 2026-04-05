# Zen-C 高尔夫游戏 (090-Golf)

俯视角迷你高尔夫游戏，支持18洞完整球场。

## 🎮 游戏特性

- **18洞完整球场** - 每洞都有独特的Par值和名称
- **多种地形** - 球道、沙坑、水障碍、长草区
- **树木障碍** - 球道两侧的树木会阻挡球
- **风力系统** - 每洞随机风力影响球的轨迹
- **平滑摄像机** - 自动跟随球滚动
- **小地图** - 右侧显示球在球场中的位置

## 🕹️ 操作说明

- **瞄准**: 在球后方点击并拖拽，拖拽方向即击球方向
- **蓄力**: 拖拽距离越长，力度越大
- **击球**: 松开鼠标即可击球
- **下一洞**: 球进洞后点击进入下一洞
- **ESC**: 退出游戏

## 🎯 计分规则

- 每洞有标准杆 (Par) - 期望击球次数
- **小鸟球 (Birdie)**: 低于Par一杆
- **标准杆 (Par)**: 与Par相同
- **柏忌 (Bogey)**: 高于Par一杆
- 目标是用最少的杆数完成所有18洞

## 📁 项目结构

```
090-golf/
├── src/
│   ├── main_window.zc         # 游戏入口和渲染
│   ├── game_logic.zc          # 游戏核心逻辑
│   ├── platform_api.zc        # 平台API定义
│   ├── platform_api_windows.zc # Windows平台实现
│   └── game.zc                # 框架核心
├── docs/
│   └── design/
│       └── DESIGN.md          # 游戏设计文档
├── build/                     # 构建输出
├── Makefile
├── build_windows.bat
└── README.md
```

## 🔧 构建方法

### Windows

```bash
build_windows.bat
```

或使用 Make:

```bash
make
```

### Linux

```bash
make
```

## 🏌️ 球场设计

| 洞号 | 名称 | Par |
|------|------|-----|
| 1 | Short One | 3 |
| 2 | Fairway | 4 |
| 3 | Bunker Bay | 4 |
| 4 | Water Hole | 3 |
| 5 | Long Drive | 5 |
| 6 | Dogleg | 4 |
| 7 | Sand Trap | 3 |
| 8 | Tree Line | 4 |
| 9 | The Lake | 5 |
| 10 | Back Nine | 4 |
| 11 | Island Green | 3 |
| 12 | Narrow | 4 |
| 13 | Final Push | 5 |
| 14 | Cliff Edge | 4 |
| 15 | Quick Three | 3 |
| 16 | Home Stretch | 4 |
| 17 | Finale | 5 |
| 18 | Club House | 3 |

## 📄 许可证

MIT License

---

**由 ZenC开发者 AI 助手开发** 🧘
