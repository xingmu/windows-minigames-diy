# Zen-C Minesweeper Game 💣

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 扫雷游戏。

## 🎮 游戏特点

- **经典玩法**: 还原 Windows 经典扫雷游戏体验
- **三个难度**: 初级 (9×9/10雷)、中级 (16×16/40雷)、高级 (30×16/99雷)
- **首次安全**: 第一次点击必定安全，踩雷自动迁移
- **自动扩展**: 无雷区域自动展开，连锁反应
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
cd windows-minigames-diy/src/002-minesweeper

# 使用 Makefile 构建
make

# 或使用 Windows 构建脚本
build_windows.bat

# 运行游戏
minesweeper.exe
```

## 🎯 游戏操作

| 操作 | 功能 |
|------|------|
| 左键点击 | 揭开格子 |
| 右键点击 | 标记/取消标记地雷 |
| 中键点击 | 数字地毯（已标记数匹配时自动展开） |
| F2 | 重新开始 |

## 📁 项目结构

```
002-minesweeper/
├── src/                    # Zen-C 源代码
│   ├── main_window.zc     # 主窗口与界面
│   ├── game_logic.zc      # 游戏核心逻辑
│   └── platform_api.zc    # 平台 API 封装
├── docs/                   # 设计文档
│   ├── design/DESIGN.md   # 详细设计文档
│   └── filemanager/       # 文件管理设计
├── build/                  # 构建输出目录
├── Makefile               # 构建配置
├── build_windows.bat      # Windows 构建脚本
└── README.md              # 本文件
```

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-05*
