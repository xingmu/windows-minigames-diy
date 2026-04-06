# 053-Parkour - Zen-C 跑酷游戏

经典横版跑酷游戏，使用 Zen-C 和 003-framework 开发。

## 游戏特性

- **自动跑酷**: 世界自动滚动，角色持续奔跑
- **平台跳跃**: 踩着悬浮平台获得更高分数
- **二段跳**: 支持空中二段跳，灵活躲避障碍
- **收集金币**: 收集金币获得额外分数
- **障碍物**: 小心躲避地面的尖刺障碍
- **速度递增**: 游戏时间越长，速度越快

## 操作说明

| 按键 | 功能 |
|------|------|
| 空格/↑ | 跳跃 / 二段跳 |
| ESC | 退出游戏 |

## 游戏目标

1. 跑酷 10000 米到达终点获得胜利
2. 收集金币获得分数奖励
3. 避免撞到障碍物
4. 速度会逐渐加快，挑战极限！

## 计分规则

- 金币: 每枚 +50 分
- 距离: 每 100 米自动累计

## 项目结构

```
053-parkour/
├── src/
│   ├── main_window.zc         # 游戏主程序
│   ├── platform_api.zc        # 平台 API 定义
│   ├── platform_api_windows.zc # Windows 实现
│   └── game.zc               # 框架核心
├── docs/
│   └── design/
│       └── DESIGN.md          # 游戏设计文档
├── Makefile
├── build_windows.bat
└── README.md
```

## 构建说明

### Windows

```bash
# 使用批处理脚本
build_windows.bat

# 或使用 Makefile
make
```

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

## 开发

基于 003-framework 框架开发，继承统一窗口管理、绘图接口和游戏循环。

## 许可证

MIT License
