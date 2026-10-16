# Tetris in C++ (Raylib)

A classic Tetris game built from scratch in **C++14** using the lightweight and fast **Raylib** library. Designed with clean Object-Oriented Programming (OOP) principles, featuring responsive controls, line-clearing mechanics, progressive difficulty, custom artwork, and sound effects.

---

## Features

* **Classic Tetrominoes**: Implements all 7 standard tetromino shapes (I, J, L, O, S, T, Z) with rotation mechanics and grid-boundary collision detection.
* **Responsive Controls**: Smooth horizontal movements, rotation handling, and soft-drop mechanics with spawn protection to prevent accidental drops.
* **Scoring & Level Progression**: Real-time score tracking, line counter, and dynamic speed scaling that increases challenge as you clear more lines.
* **Audio & Visual Polish**: Includes custom Japanese-style typography (`SamuraiBlast.ttf`), custom background graphics, sound effects for drops/game-over, and an in-engine interactive Game Over / Replay screen.
* **Modular OOP Architecture**: Separated concerns across grid state management (`Gridformation`), block rotation/positioning (`Blocks`, `Block`, `Position`), color palettes (`Color`), and game loop logic (`main.cpp`).

---

## Controls

| Key | Action |
| :--- | :--- |
| `Left Arrow` | Move tetromino left |
| `Right Arrow` | Move tetromino right |
| `Up Arrow` | Rotate tetromino clockwise |
| `Down Arrow` | Soft drop (fast fall) |
| `Mouse Left Click` | Select **Replay** or **Exit** on Game Over screen |
| `Esc` | Quit game |

---

## Project Structure

```
Tetris/
├── assets/
│   ├── SamuraiBlast.ttf    # Custom retro font
│   ├── Tetrisback.png      # 600x700 background graphic
│   ├── Gameover.WAV        # Game over sound effect
│   └── butound.WAV         # UI button click sound
├── src/
│   ├── main.cpp            # Game loop, input handling, and state machine
│   ├── Gridformation.h/.cpp# 10x20 grid matrix, collision detection & row clearing
│   ├── Blocks.h/.cpp       # Tetromino definitions, rotation & movement
│   ├── Block.h/.cpp        # Individual cell rendering & offset logic
│   ├── Color.h/.cpp        # RGB color palette definitions
│   └── position.h/.cpp     # 2D integer coordinate helper
├── .vscode/                # VS Code build and debug configurations
├── Makefile                # Cross-platform Makefile (macOS, Windows, Linux)
└── README.md
```

---

## Getting Started

### Prerequisites

* A C++ compiler supporting **C++14** or newer (`clang++`, `g++`, or MSVC).
* **Raylib** (v4.5 or newer).
* `make` build tool.

#### Installing Raylib:

* **macOS** (via Homebrew):
  ```bash
  brew install raylib
  ```
* **Linux (Debian/Ubuntu)**:
  ```bash
  sudo apt install libraylib-dev
  ```
* **Windows**:
  Install via [w64devkit with Raylib](https://www.raylib.com/) or vcpkg.

---

### Building and Running

#### 1. From Terminal (macOS / Linux)

Clone the repository and run:

```bash
# Clean previous builds and compile
make clean && make

# Launch the game
./main
```

#### 2. From Visual Studio Code

1. Open the project folder in VS Code.
2. Press `Ctrl + Shift + B` (or `Cmd + Shift + B` on macOS) to build.
3. Press `F5` to run and debug.

---

## License

This project is open-source and available under the [MIT License](LICENSE.txt).
