# Zen-C Surfing Game - 冲浪游戏 🏄

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 冲浪游戏。在海浪上保持平衡，收集星星和贝壳！

## 🎮 游戏特点

- **Zen-C 窗体版本**: 使用 Zen-C 源代码开发的原生 Windows 窗体游戏
- **物理平衡系统**: 真实的冲浪平衡模拟，体验海浪上的刺激
- **收集要素**: 在海浪上收集星星和贝壳获得高分
- **速度递增**: 随着分数增加，海浪速度越来越快
- **生命系统**: 3条生命，平衡失控会消耗生命
- **等级系统**: 每1000分提升一个等级

## 🎯 游戏玩法

- **← / A**: 向左倾斜
- **→ / D**: 向右倾斜
- **W / ↑**: 加速
- **S / ↓**: 减速
- **空格键 / P**: 暂停/继续
- **R**: 重新开始
- **ESC**: 退出游戏

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
cd windows-minigames-diy/src/043-surfing

# 使用构建脚本
build_windows.bat

# 运行游戏
surfing.exe
```

## 📁 项目结构

```
043-surfing/
├── src/                    # 源代码目录
│   ├── main_window.zc     # 主入口（窗口、事件处理、渲染）
│   ├── game_logic.zc      # 游戏逻辑模块
│   └── platform_api.zc    # 平台API封装
├── build/                  # 构建输出目录
├── build_windows.bat      # Windows 构建脚本
├── Makefile               # 构建配置
├── README.md              # 项目说明
└── LICENSE                # MIT 许可证
```

## 🎨 游戏截图

游戏界面包含:
- 渐变天空背景
- 飘动的云朵
- 动态波浪
- 冲浪者角色
- 星星和贝壳收集物
- 分数、生命、等级显示
- 平衡条显示

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
