## 📜 License

This project is open-source andHere is a complete and customized `README.md` file based on your project's source code and structure[cite: 13, 14, 18, 20]. It highlights the specific features you have implemented, such as the custom UI and object-oriented design[cite: 13, 15, 19]. 

You can copy and paste this directly into your `README.md` file.

***
```markdown
# Tetris in C++ with Raylib

A classic Tetris clone built from scratch using C++ and the [Raylib](https://www.raylib.com/) game programming library. This project implements the core mechanics of the original arcade game using a clean, object-oriented approach.

## 🚀 Features

*   **Classic Mechanics:** Full Tetris gameplay including piece movement, rotation, and line clearing[cite: 13, 15].
*   **Dynamic Difficulty:** The game speed automatically increases as you clear lines and progress through levels[cite: 13].
*   **Pre-Game Countdown:** A 3-second countdown sequence before the game starts to get ready[cite: 13].
*   **Custom UI & Audio:** Features a customized Game Over screen with interactive "Replay" and "Exit" buttons, along with background music and sound effects[cite: 13].
*   **Object-Oriented Design:** Modular codebase separating logic into distinct classes for the Grid, Tetromino Blocks, Colors, and UI components[cite: 14, 16, 18, 20].

## 🎮 Controls

*   **Left Arrow:** Move piece left
*   **Right Arrow:** Move piece right
*   **Down Arrow:** Soft drop (accelerate piece falling)
*   **Up Arrow:** Rotate piece clockwise

## 🛠️ Prerequisites

To compile and run this game, you will need:
*   A C++ compiler supporting C++17 or later (like `clang++` or `g++`).
*   [Raylib](https://github.com/raysan5/raylib) installed on your system.

## ⚙️ Compilation & Running

This project separates source code (`src/`) from media assets (`assets/`). Navigate to the root directory of the project in your terminal to compile. 

**For macOS (using Homebrew Raylib installation):**
If you have installed Raylib via Homebrew, you can compile the game using `clang++` with the following command:

```bash
clang++ -std=c++17 src/*.cpp -o tetris -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

**For Linux:**
```bash
g++ -std=c++17 src/*.cpp -o tetris -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

Running the Game:
Once compiled, run the executable from the root directory so the game can properly load the files from the assets/ folder:

Bash
./tetris
📁 Repository Structure
Plaintext
Tetris/
├── src/                      # C++ Source and Header files
├── assets/                   # Audio, Images, and Fonts
├── .gitignore                # Ignored compiled binaries and system files
├── Makefile                  # Build instructions
└── README.md                 # Project documentation
👤 Author
Bilal (24L-0560)

FAST NUCES Lahore

📜 License
This project is open-source and available under the MIT License.
