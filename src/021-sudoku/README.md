# Zen-C Sudoku Game 🧩

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 数独游戏。

## 🎮 游戏特点

- **9x9 标准数独**: 完整的数独游戏体验
- **鼠标选择**: 点击单元格快速选择
- **数字键填入**: 使用数字键1-9填入数字
- **即时反馈**: 错误数字红色高亮显示
- **提示功能**: 不会做时可以使用提示
- **计时系统**: 记录游戏时长
- **多难度**: 支持简单、中等、困难、专家四种难度

## 🎯 游戏规则

1. 9x9 网格被分为 9 个 3x3 小宫格
2. 每行、每列、每个 3x3 小宫格都必须包含数字 1-9
3. 题目中的数字是固定的（蓝色），不能修改
4. 玩家填入的数字可以修改
5. 填满所有空格且无冲突即获胜

## 🎮 操作说明

| 操作 | 按键/动作 |
|------|----------|
| 选择单元格 | 鼠标左键点击 |
| 填入数字 | 数字键 1-9 |
| 清除数字 | 0 或 Backspace |
| 移动选择 | 方向键 ↑↓←→ |
| 使用提示 | H 键 |
| 新游戏 | N 键 |
| 检查错误 | C 键 |
| 退出游戏 | ESC |

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
```

### 构建和运行

```bash
# 克隆仓库
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy/src/021-sudoku

# 使用构建脚本
build_windows.bat

# 运行游戏
sudoku_game.exe
```

## 📁 项目结构

```
021-sudoku/
├── src/                    # 源代码目录
│   ├── main_window.zc     # 主入口（窗口、事件处理）
│   ├── game_logic.zc      # 游戏逻辑模块
│   └── platform_api.zc    # 平台API封装
├── build/                 # 构建输出目录
├── build_windows.bat     # Windows 构建脚本
├── Makefile              # 构建配置
├── README.md             # 项目说明
├── SECURITY.md           # 安全策略
├── LICENSE               # MIT 许可证
└── .gitignore           # Git 忽略文件
```

## 🧮 技术实现

- **数独生成器**: 使用回溯算法生成有效数独题目
- **回溯求解**: 自动生成唯一解
- **难度控制**: 根据挖空数量调整难度
- **错误检测**: 实时检测冲突并高亮显示

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
