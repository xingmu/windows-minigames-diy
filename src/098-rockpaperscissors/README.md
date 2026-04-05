# Rock Paper Scissors - Zen-C Game ✊✋✌️

A classic Rock-Paper-Scissors game developed with **Zen-C modern systems programming language**.

## 🎮 Game Features

- **Zen-C Windows Version**: Native Windows GUI game developed entirely in Zen-C source code
- **Modern Features**: Type safety, pattern matching, enums, and more
- **High Performance**: Compiles to human-readable GNU C/C11, 100% C ABI compatible
- **Complete Game**: Full game logic, scoring system, animation effects
- **Beautiful Interface**: Colorful graphics with professional UI design

## 🚀 Quick Start

### Prerequisites

- **Zen-C Compiler**: Requires `zc` compiler
- **C Compiler**: MinGW or MSVC (Windows)
- **OS**: Windows 10/11

### Install Zen-C Compiler

```bash
# Clone Zen-C repository
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# Build and install
make install
# May require administrator privileges
```

### Build and Run

```bash
# Clone repository
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy/src/098-rockpaperscissors

# Use build script
build_windows.bat

# Run game
rockpaperscissors.exe
```

## 📁 Project Structure

```
098-rockpaperscissors/
├── src/                    # Source code directory
│   ├── main_window.zc     # Main entry (window, events)
│   ├── game_logic.zc      # Game logic module
│   └── platform_api.zc    # Platform API wrapper
├── build/                  # Build output directory
├── build_windows.bat      # Windows build script
├── Makefile               # Build configuration
├── README.md              # Project documentation
├── LICENSE                # MIT License
└── .gitignore             # Git ignore file
```

## 🎯 How to Play

1. **Select** your choice: Rock (✊), Paper (✋), or Scissors (✌️)
2. **Watch** as the CPU makes its selection
3. **See** the result:
   - Rock beats Scissors
   - Scissors beats Paper
   - Paper beats Rock
4. **Score** points for each win
5. Click **"再来一局"** (Play Again) to continue

## 📜 Game Rules

| Your Choice | Beats | Loses To |
|-------------|-------|----------|
| Rock ✊     | Scissors ✌️ | Paper ✋ |
| Paper ✋    | Rock ✊ | Scissors ✌️ |
| Scissors ✌️ | Paper ✋ | Rock ✊ |

## 🔧 Build Instructions

### Windows Build

```bash
# Using build script
build_windows.bat

# Or using Makefile
make
```

### Manual Build

```bash
# Compile Zen-C code
zc build -o build/rockpaperscissors.exe src/main_window.zc
```

## 📄 License

This project is licensed under the MIT License - see [LICENSE](../../LICENSE) file for details.

---

**Maintained by ZenC Developer AI Assistant** 🤖  
*Game Version: 1.0.0 | Last Updated: 2026-04-06*
