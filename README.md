# Windows Mini Games DIY 🕹️

使用 **Zen-C** 现代编程语言开发的 Windows 小游戏集合。

## ⚠️ 不支持贡献

本项目**不接受外部贡献**，所有代码由项目维护者自行开发。

如有问题或建议，请通过 GitHub Issues 反馈，但请注意不保证会被处理。

## 🛠️ 技术栈

- **语言**: Zen-C (现代系统编程语言)
- **编译器**: zc (Zen-C编译器)
- **后端**: 编译为人类可读的GNU C/C11，100% C ABI兼容
- **版本控制**: Git + GitHub Actions
- **目标平台**: Windows 10/11 (仅限)

## 🎮 子项目列表

| 子项目 | 描述 | 路径 |
|--------|------|------|
| 🐍 Snake Game | Windows 贪吃蛇游戏（窗体版本） | [src/001-snake](./src/001-snake) |
| 💣 Minesweeper | Windows 扫雷游戏（经典玩法） | [src/002-minesweeper](./src/002-minesweeper) |

## 📁 项目结构

```
windows-minigames-diy/
├── src/
│   ├── 001-snake/              # 贪吃蛇游戏子项目
│   │   ├── src/                # 源代码
│   │   ├── README.md           # 游戏说明
│   │   └── build_windows.bat   # Windows构建
│   └── 002-minesweeper/        # 扫雷游戏子项目
│       ├── src/                # 源代码（.zc）
│       ├── docs/               # 设计文档
│       ├── Makefile            # 构建脚本
│       └── build_windows.bat   # Windows构建
├── .github/                    # GitHub配置
└── README.md                   # 本文件
```

## 🚀 快速开始

### 克隆项目
```bash
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy
```

### 进入子项目
```bash
cd src/001-snake      # 贪吃蛇
cd src/002-minesweeper # 扫雷
```

### 构建和运行
- 贪吃蛇：查看 [src/001-snake/README.md](./src/001-snake/README.md)
- 扫雷：查看 src/002-minesweeper/Makefile

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-05*
