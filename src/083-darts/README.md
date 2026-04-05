# Zen-C Darts（飞镖）游戏

基于 Zen-C 和 003-framework 开发的飞镖游戏。

## 游戏规则

- 初始分数：301分
- 每轮3支飞镖
- 点击镖盘投掷飞镖
- 每次投掷后从总分中扣除相应分数
- 先将分数减至0者获胜
- 必须精确归零（过线则本轮得分不算）

## 计分规则

| 区域 | 分数 |
|------|------|
| 内牛眼（红心） | 50分 |
| 外牛眼（绿圈） | 25分 |
| 双倍环（外圈红绿交替） | 面值 × 2 |
| 三倍环（内圈红绿交替） | 面值 × 3 |
| 单倍区（黑白区域） | 面值（1-20） |

## 操作说明

- **鼠标移动**：瞄准
- **左键点击**：投掷飞镖
- **空格键**：开始游戏/下一轮
- **R 键**：重新开始
- **ESC**：退出游戏

## 编译

```bash
# 编译游戏
make all

# 运行游戏
make run

# Windows 编译
make windows
```

## 依赖

- zc 编译器 (Zen-C)
- gcc 编译器

## 安装 zc 编译器

```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
# 将 build/zc 添加到系统 PATH
```

## 项目结构

```
083-darts/
├── Makefile
├── README.md
├── LICENSE
├── .github/
│   └── workflows/
│       └── build.yml
└── src/
    ├── main_window.zc    - 主入口
    ├── game_logic.zc     - 游戏逻辑
    └── platform_api.zc  - 平台API
```
