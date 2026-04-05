# Zen-C MinesweeperPlus (扫雷增强版) 💣

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 扫雷增强版游戏。

## 🎮 游戏特点

- **经典玩法**: 还原 Windows 经典扫雷游戏体验
- **三个难度**: 初级 (9×9/10雷)、中级 (16×16/40雷)、高级 (30×16/99雷)
- **首次安全**: 第一次点击必定安全，踩雷自动迁移
- **连锁翻开**: 无雷区域自动展开，连锁反应
- **旗帜标记**: 右键标记/取消地雷位置
- **数字地毯**: 中键智能展开（已标记数匹配时自动展开）
- **计时计雷**: 实时显示用时和剩余雷数
- **战绩记录**: 记录各难度最佳成绩

## 🚀 快速开始

### 前提条件

- **Zen-C 编译器**: 需要安装 `zc` 编译器
- **C 编译器**: MinGW 或 MSVC (Windows)
- **操作系统**: Windows 10/11

### 安装 Zen-C 编译器

```bash
# 克隆 Zen-C 仓库
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# 编译并安装
make install
# 可能需要管理员权限
```

### 构建和运行

```bash
# 克隆仓库
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy/src/034-minesweeperplus

# 使用 Makefile 构建
make

# 或使用 Windows 构建脚本
build_windows.bat

# 运行游戏
minesweeperplus.exe
```

## 🎯 游戏操作

| 操作 | 功能 |
|------|------|
| 左键点击 | 揭开格子 |
| 右键点击 | 标记/取消标记地雷 |
| 中键点击 | 数字地毯（已标记数匹配时自动展开） |
| F2 | 重新开始 |
| 1/2/3 | 选择难度（初级/中级/高级） |

## 📐 难度设置

| 难度 | 行列 | 地雷数 |
|------|------|--------|
| 初级 | 9×9 | 10 |
| 中级 | 16×16 | 40 |
| 高级 | 30×16 | 99 |

## 📁 项目结构

```
034-minesweeperplus/
├── src/
│   ├── platform_api.zc      # 平台 API 封装
│   ├── game.zc               # 游戏框架核心
│   ├── main_window.zc        # 主窗口与界面
│   └── game_logic.zc         # 游戏核心逻辑
├── docs/
│   └── design/DESIGN.md      # 游戏设计文档
├── build/                     # 构建输出
├── Makefile                   # 构建配置
├── build_windows.bat          # Windows 构建脚本
└── README.md                  # 本文件
```

## 🧘 Zen-C 之道

> "完美的代码不是加无可加，而是减无可减。"

本项目遵循 Zen-C 简洁优雅的设计哲学，追求代码的优美与高效。

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
