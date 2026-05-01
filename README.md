## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page]((https://github.com/Muhammadbilal206/Tetris-in-C-/issues)) if you want to contribute.

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

***

**Tip for your GitHub repo:** You can also use the very first sentence ("A classic Tetris clone built using modern C++ and the Raylib game programming library.") for the short "About" sectionHere is a comprehensive and structured description you can use directly for your GitHub repository's `README.md` file. It covers the essentials: what the project is, its features, how to run it, and the controls.

***

# Tetris (C++ & Raylib)

A classic Tetris clone built from scratch using modern C++ and the [Raylib](https://www.raylib.com/) game programming library. This project serves as a fun recreation of the iconic arcade game while demonstrating game loop mechanics, grid-based collision detection, and state management in C++.

## 🚀 Features

*   **Classic Gameplay:** Full Tetris mechanics including piece rotation, line clearing, and game-over states.
*   **Dynamic Scoring:** Points awarded based on the number of lines cleared simultaneously.
*   **Next Piece Preview:** UI element showing the upcoming tetromino to help plan your moves.
*   **Clean Graphics:** Smooth, vibrant visual rendering handled by Raylib.
*   **Increasing Difficulty:** The game speeds up as your score increases.

## 🛠️ Tech Stack

*   **Language:** C++ (C++17 or later recommended)
*   **Graphics & Audio:** [Raylib](https://github.com/raysan5/raylib) (v4.5+)

## 🎮 Controls

*   **Left Arrow:** Move piece left
*   **Right Arrow:** Move piece right
*   **Up Arrow:** Rotate piece clockwise
*   **Down Arrow:** Soft drop (speed up piece falling)
*   **Spacebar:** Hard drop (instantly drop piece to the bottom) *(Optional, if implemented)*
*   **P:** Pause game *(Optional, if implemented)*

## ⚙️ Getting Started

### Prerequisites

To build and run this project, you will need:
*   A C++ compiler (GCC, Clang, or MSVC)
*   [Raylib](https://github.com/raysan5/raylib/wiki) installed on your system (or included via CMake/package manager)

### Compilation

*(Note: Update this section based on your specific build system. Here is a generic g++ example).*

If you have Raylib installed system-wide, you can compile the game using `g++`:
```bash
g++ main.cpp -o tetris -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
