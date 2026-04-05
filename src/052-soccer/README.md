# 052-Soccer - 足球点球游戏

Zen-C 编写的足球点球游戏，使用鼠标瞄准射门。

## 游戏玩法

- 移动鼠标瞄准球门目标
- 点击左键射门
- 空格键进入下一轮（射门后）
- R键重新开始
- ESC退出游戏

## 游戏规则

- 5次射门机会
- 守门员会尝试扑救
- 进球得分

## 编译

### Windows

```bash
./build_windows.bat
```

或者双击 `build_windows.bat`

### Linux/macOS

```bash
make
```

## 项目结构

```
052-soccer/
├── src/
│   ├── main_window.zc    # 游戏主程序和渲染
│   ├── game_logic.zc     # 游戏逻辑（跨平台）
│   └── platform_api.zc   # 平台API抽象
├── Makefile
├── build_windows.bat
├── README.md
└── LICENSE
```

## 技术特性

- 使用 Zen-C 语言开发
- 基于 003-framework 框架
- 跨平台代码设计
- 纯2D图形渲染
- AI守门员系统

## 截图预览

游戏界面包含：
- 绿色草地场地
- 白色球门框
- 守门员（金色）
- 足球（黑白花纹）
- 瞄准准星
- 射门轨迹预测

## 许可证

MIT License
