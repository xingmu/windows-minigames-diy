# 042-Skiing 滑雪游戏

基于 Zen-C + 003-framework 开发的滑雪游戏。

## 游戏玩法

- **← →** 方向键控制滑雪者左右移动
- **空格** 开始游戏
- **R** 重新开始
- **ESC** 退出游戏

## 游戏目标

躲避障碍物（树木、石头、雪人），尽可能滑得更远获得更高分数。

## 项目结构

```
042-skiing/
├── src/
│   ├── main_window.zc     # 游戏主程序入口
│   ├── game_logic.zc      # 游戏逻辑
│   └── platform_api.zc    # 平台API封装
├── Makefile               # 构建配置
└── README.md              # 本文件
```

## 构建说明

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

### 构建命令

```bash
# 编译游戏
make all

# 运行游戏
make run

# Windows构建
make windows

# 清理
make clean
```

## 游戏特性

- 流畅的左右移动控制
- 三种随机障碍物：树木、石头、雪人
- 渐进式加速系统
- 滑雪痕迹视觉效果
- 分数和速度显示

## 许可证

MIT License
