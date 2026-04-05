# Zen-C Basketball Game 🏀

A basketball shooting game built with Zen-C language using the 003-framework.

## Game Features

- **Mouse Shooting**: Click and drag to aim and set power, release to shoot
- **Realistic Physics**: Ball gravity, bouncing, and rim collision
- **Combo System**: consecutive baskets increase your score multiplier
- **Score Tracking**: Track your score, balls remaining, and best combo

## Controls

| Action | Input |
|--------|-------|
| Aim & Shoot | Click and drag from ball position, release to shoot |
| Restart | Press `R` key |
| Exit | Press `Escape` key |

## How to Play

1. Position your mouse near the basketball
2. Click and hold the left mouse button
3. Drag backwards to set the angle and power
   - The trajectory preview shows where the ball will go
   - The power bar indicates shot strength
4. Release to shoot the ball
5. Try to make consecutive baskets to build your combo!

## Scoring

- Each basket: **2 points + combo bonus**
- Combo increases with consecutive successful shots
- You have **10 balls** per game

## Building

### Prerequisites

- Zen-C compiler (zc)
- GCC compiler (for C backend)

### Build Instructions

```bash
# Clone and build
cd src/051-basketball
make all

# Or build and run
make run
```

### Install Zen-C Compiler

```bash
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
# Add build/zc to your PATH
```

## Project Structure

```
051-basketball/
├── src/
│   ├── main.zc           # Main entry point, rendering, events
│   ├── game_logic.zc    # Game logic (physics, scoring, collision)
│   └── platform_api.zc  # Platform API abstraction
├── Makefile
├── README.md
└── LICENSE
```

## Screenshots

The game features:
- Wooden court floor with court lines
- Basketball with realistic orange color and black lines
- Red rim with white backboard and net
- Trajectory preview while aiming
- Power bar indicator
- Score, combo, and balls remaining display

## License

MIT License - See LICENSE file for details.
