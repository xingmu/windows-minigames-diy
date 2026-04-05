# Shooting Gallery - 射击游戏

> Zen-C 开发的 60 秒限时射击游戏

## 🎯 游戏介绍

在 60 秒内尽可能多地击中目标，考验你的反应速度和准确性！

## 🕹️ 操作说明

- **鼠标移动** - 瞄准目标
- **左键点击** - 射击
- **ESC** - 退出游戏

## 🎨 目标类型

| 颜色 | 类型 | 分值 |
|------|------|------|
| 🔴 红色 | 立靶（静止） | 10 分 |
| 🔵 蓝色 | 移动靶 | 20 分 |
| 🟡 金色 | 加分靶（稀少） | 50 分 |

## 🛠️ 构建说明

### 前置要求

- Zen-C 编译器 `zc`

### Windows 构建

```bash
# 使用 bat 脚本
build_windows.bat

# 或使用 Makefile
make windows
```

### Linux/macOS 构建

```bash
make
```

### 运行游戏

```bash
make run
```

## 📁 项目结构

```
025-shooting/
├── src/
│   ├── platform_api.zc    # 平台 API 封装
│   ├── game_logic.zc      # 游戏核心逻辑
│   └── main_window.zc    # 主程序入口
├── build/                 # 构建输出
├── Makefile              # 构建配置
├── build_windows.bat     # Windows 构建脚本
└── README.md             # 本文件
```

## 📝 游戏特性

- 60 秒限时挑战
- 三种目标类型（立靶、移动靶、加分靶）
- 实时分数和命中率统计
- 准星跟随鼠标
- 目标超时自动消失
- 击中反馈效果

## 🧘 Zen-C 之道

> "简洁、优雅、高效。"

本游戏使用 Zen-C 语言开发，充分利用了其简洁优雅的语法特性。

---

**版本**: 1.0.0  
**作者**: ZenC 开发者 AI 助手 🤖
