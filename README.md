# Rugby - 橄榄球游戏

🏉 077-Rugby - 使用 Zen-C + 003-framework 构建的橄榄球游戏

## 游戏介绍

一款激动人心的橄榄球达阵游戏！玩家控制绿色球员，带球突破防守，争取在对方端区达阵得分。

## 游戏规则

- **目标**: 带球进入屏幕顶端的达阵区域(TRY ZONE)得分
- **得分**: 每次达阵得 5 分
- **时间**: 2分钟比赛时间
- **对手**: 红色防守球员会追捕持球者
- **传球**: 按空格键传球给最近的队友

## 控制说明

| 按键 | 功能 |
|------|------|
| ↑ ↓ ← → | 移动球员 |
| 空格键 | 传球给最近的队友 |
| R | 重新开始游戏 |

## 游戏特色

- 🏉 真实的橄榄球场地和达阵区
- 👥 队友AI会自动跑位
- 🤺 防守球员AI会追捕持球者
- ✨ 达阵特效和得分动画
- ⏱️ 限时比赛模式

## 运行方法

### Windows
```bash
./build/run.bat
```
或双击 `build/run.bat`

### Linux
```bash
make run
```

### 使用 Zen-C 编译器
```bash
zenc src/main_window.zc -o build/rugby
./build/rugby
```

## 项目结构

```
077-rugby/
├── src/
│   ├── main_window.zc      # 游戏入口
│   ├── game.zc             # 游戏框架核心
│   ├── game_logic.zc      # 橄榄球游戏逻辑
│   ├── platform_api.zc    # 平台API接口
│   └── platform_api_windows.zc  # Windows实现
├── build/                  # 编译输出
├── docs/                   # 文档
├── LICENSE
└── README.md
```

## 技术特性

- **框架**: Zen-C Game Framework v1.0.0
- **语言**: Zen-C (简洁、高效的系统编程语言)
- **渲染**: 帧缓冲直接绘制，高性能
- **AI**: 简单的追逐和跑位AI

## 截图预览

游戏中包含：
- 绿色草坪橄榄球场
- 黄色达阵区
- H形球门柱
- 动态球员和球
- 实时分数和时间显示

## 开发信息

- **游戏编号**: 077
- **类型**: 体育运动游戏
- **难度**: 中等
- **作者**: Zen-C Developer

## 许可

MIT License - 详见 LICENSE 文件

---

**Zen-C - 简洁是终极优雅。** 🧘