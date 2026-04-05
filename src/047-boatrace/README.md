# 047-BoatRace - 赛船大赛 🚤

Zen-C 语言开发的赛船游戏，在规定时间内完成指定圈数获胜。

## 🎮 游戏介绍

经典赛船游戏，玩家控制船只穿越赛道，绕过障碍物和浮标，在3圈比赛中争取最佳成绩。

## 🎮 操作说明

| 按键 | 功能 |
|------|------|
| **↑** | 加速 |
| **←** | 左转 |
| **→** | 右转 |
| R | 重新开始（游戏结束后）|

## 📜 游戏规则

- 赛道包含4个检查点，必须按顺序通过
- 完成3圈比赛即可获胜
- 撞到浮标会减速
- 记录完成时间和最佳时间

## 🎨 游戏特色

- **漂移物理**：船只会产生漂移效果，转向更加真实
- **波浪效果**：船只后方产生动态波浪
- **速度线**：高速行驶时显示速度线
- **检查点系统**：4个检查点引导赛道方向
- **计时系统**：记录完成时间和最佳时间

## 🛠 技术特性

- 使用 Zen-C 语言开发
- 基于 003-framework 游戏框架
- 继承 Game 类实现
- Windows GUI 平台

## 📁 项目结构

```
047-boatrace/
├── src/
│   ├── main_window.zc       # 游戏入口
│   ├── game_logic.zc        # 游戏逻辑 (BoatRaceGame类)
│   ├── platform_api.zc     # 平台API
│   └── game.zc             # 框架核心
├── build/                   # 构建输出
├── Makefile                 # Linux/macOS构建
├── build_windows.bat       # Windows构建
├── README.md               # 本文件
├── SECURITY.md             # 安全策略
└── LICENSE                 # MIT 许可证
```

## 🚀 构建说明

### Windows

```bash
# 使用构建脚本
build_windows.bat

# 或使用 Makefile
make
```

### Linux/macOS

```bash
make
./build/boatrace_game
```

## 📦 依赖

- Zen-C 编译器 (zc)
- gcc 编译器（C后端）

安装 Zen-C 编译器:
```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

---

**由 ZenC开发者 AI 助手开发** 🤖  
**版本: 1.0.0 | 2026-04-06**
