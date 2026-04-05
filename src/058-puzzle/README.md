# Slide Puzzle - Zen-C Windows Mini Games DIY

A classic 3x3 sliding puzzle game (8-puzzle) built with Zen-C language using the 003-framework.

## Game Features

- **3x3 Grid**: Classic 8-puzzle gameplay on a 3x3 grid
- **Smooth Controls**: Arrow keys or WASD to slide tiles
- **Move Counter**: Track your moves as you solve the puzzle
- **Timer**: Track your solving time
- **Rank System**: Get rated based on your performance
- **Win Detection**: Celebrate when you arrange 1-8 in order!
- **Click Support**: Click on tiles next to empty space to move them
- **Restart**: Press R to shuffle and restart

## Controls

| Key | Action |
|-----|--------|
| ← | Slide tile right (move empty left) |
| ↑ | Slide tile down (move empty up) |
| → | Slide tile left (move empty right) |
| ↓ | Slide tile up (move empty down) |
| W/A/S/D | Alternative movement keys |
| R | Restart (shuffle puzzle) |
| ESC | Exit game |
| Click | Click adjacent tile to move it |

## Ranking System

| Moves | Rank |
|-------|------|
| < 20 | 大师 (Master) |
| 20-29 | 高手 (Expert) |
| 30-49 | 熟练 (Skilled) |
| 50-79 | 入门 (Beginner) |
| 80+ | 新手 (Novice) |

## Building

### Prerequisites

- Zen-C compiler (zc)
- GCC compiler (for C backend)
- Windows OS (for Windows build)

### Build on Linux/macOS

```bash
cd src/058-puzzle
make
```

### Build on Windows

```batch
cd src\058-puzzle
build_windows.bat
```

Or use the Makefile with WSL:

```bash
make windows
```

## Project Structure

```
058-puzzle/
├── src/
│   ├── main_window.zc   # Main game window, inherits from Game class
│   ├── game_logic.zc    # Game logic (board, movement, win detection)
│   └── platform_api.zc  # Platform API (imported from framework)
├── docs/
│   └── design/          # Design documents
├── README.md
├── Makefile
└── build_windows.bat
```

## Architecture

### Game Class

The game inherits from the framework's `Game` class and implements:
- `onInit()` - Initialize and shuffle puzzle
- `onUpdate(dt)` - Update game logic (input-driven)
- `onRender(canvas)` - Render puzzle board and UI
- `onKeyDown(key)` - Handle arrow key and WASD input
- `onMouseDown(x, y, button)` - Handle mouse click to move tiles

### Game Logic (game_logic.zc)

- `Board` - 3x3 grid storing values 1-8 and 0 (empty)
- `GameData` - Contains board, moves, win state, timer
- `shuffle_game()` - Generate solvable random puzzle
- `try_move(x, y)` - Try to move tile at (x, y) if adjacent to empty
- `check_solved()` - Check if puzzle is in winning order

### Puzzle Rules

The goal is to arrange the numbered tiles in order (1-8) with the empty space in the bottom-right corner:

```
1  2  3
4  5  6
7  8  _
```

## License

Same as the parent project.

## Part of Windows Mini Games DIY

This game is part of the [windows-minigames-diy](https://github.com/xingmu/windows-minigames-diy) collection of classic games built with Zen-C.
