# Zen-C 摩托车障碍躲避游戏

一个使用 Zen-C 语言开发的 Windows 窗体障碍躲避游戏。

## 游戏说明

驾驶摩托车在公路上躲避障碍物，尽可能行驶更远的距离并收集金币获得更高分数。

## 操作说明

- `A` / `左方向键`: 向左移动
- `D` / `右方向键`: 向右移动
- `空格键`: 暂停/继续游戏
- `R键`: 游戏结束后重新开始
- `ESC`: 退出游戏

## 游戏特性

- 三种障碍物：路障、汽车、卡车
- 金币收集系统（+20分）
- 速度递增系统（每500米加速一次）
- 躲避障碍物得分（+5分）
- 美观的彩色图形界面
- 分数、距离、速度等级显示

## 编译说明

### Windows 环境

1. 确保已安装 Zen-C 编译器 (`zc`)
2. 双击运行 `build_windows_window.bat`
3. 或在命令行执行：

```bash
zc build src\main_window.zc -o build\moto_game.exe
```

### Linux/macOS 环境

Zen-C 编译器支持跨平台编译，请参考 [Zen-C 官方文档](https://zenc-lang.org/)。

## 项目结构

```
src/
  game_logic.zc      # 游戏逻辑（纯Zen-C，跨平台）
  main_window.zc     # 窗体主程序（Zen-C + 平台API）
  platform_api.zc    # 跨平台API封装
build_windows_window.bat  # Windows构建脚本
README.md            # 本说明文件
```

## 技术细节

- 游戏区域: 400x600 像素
- 道路宽度: 300 像素
- 车道数: 3
- 帧率: ~60 FPS
- 初始障碍物生成间隔: 800ms

## 许可证

MIT License

## 作者

Zen-C 开发团队
