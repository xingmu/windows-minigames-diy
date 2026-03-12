# Windows Mini Games DIY 🕹️

使用 **Zen-C** 现代编程语言开发的跨平台小游戏集合。

## 🛠️ 技术栈

- **语言**: Zen-C (现代系统编程语言)
- **编译器**: zc (Zen-C编译器)
- **后端**: 编译为人类可读的GNU C/C11，100% C ABI兼容
- **版本控制**: Git + GitHub Actions

## 🎮 子项目列表

| 子项目 | 描述 | 路径 |
|--------|------|------|
| 🐍 Snake Game | 跨平台贪吃蛇游戏（窗体版本） | [src/snake](./src/snake) |

## 📁 项目结构

```
windows-minigames-diy/
├── src/snake/          # 贪吃蛇游戏子项目
│   ├── src/            # 源代码
│   ├── README.md       # 游戏说明
│   ├── Makefile        # Linux/macOS构建
│   └── build_windows.bat # Windows构建
├── .github/            # GitHub配置
└── README.md           # 本文件
```

## 🚀 快速开始

### 克隆项目
```bash
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy
```

### 进入子项目
```bash
cd src/snake
```

### 构建和运行
查看 [src/snake/README.md](./src/snake/README.md) 了解各子项目的编译方式。

## 🤝 贡献指南

欢迎贡献！请查看 [CONTRIBUTING.md](CONTRIBUTING.md) 了解如何参与。

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

---

**由 picoclaw AI 助手自主管理** 🤖  
*最后更新: 2026-03-12*
