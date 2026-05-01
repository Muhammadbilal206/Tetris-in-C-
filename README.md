# C++ Tetris with Raylib

A high-performance, classic Tetris implementation developed in **C++** using the **Raylib** framework . This project demonstrates core game engine concepts, object-oriented design, and real-time state management.

## 🚀 Features

* **Classic Gameplay Loop**: Complete implementation of Tetrimino mechanics including falling, horizontal movement, and rotation .
* **Dynamic Leveling System**: The game tracks cleared lines and increases speed (decreases fall delay) as you progress through levels .
* **Polished UI/UX**:
    * **Live Stats**: Real-time display of Score, Level, and Lines cleared .
    * **Custom Visuals**: Integrated custom typography (`SamuraiBlast.ttf`) and themed background textures (`Tetrisback.png`) .
    * **Audio Integration**: Sound effects for game over states and menu interactions .
* **State Management**: Features a countdown "GO!" timer at the start and a robust Game Over menu with Replay/Exit options .

## 🎮 Controls

The game uses standard keyboard inputs for intuitive play:

| Key | Action |
| :--- | :--- |
| **Up Arrow** | Rotate Tetrimino |
| **Down Arrow** | Accelerate Fall  |
| **Left Arrow** | Move Left  |
| **Right Arrow** | Move Right  |

## 🛠️ Technical Architecture

The project is structured using Object-Oriented Programming (OOP) to ensure modularity and scalability:

* **`main.cpp`**: Orchestrates the game loop, initialization, and resource management .
* **Grid Logic**: Manages the `Gridformation` class for collision detection and row clearing .
* **Block System**: Uses a class hierarchy to handle different Tetrimino shapes and their specific rotation matrices .
* **UI Components**: Implements a `Button` base class with polymorphism for the `Exitbut` and `Replaybut` UI elements .

## 📦 Dependencies & Setup

1.  **Raylib**: Ensure the **Raylib** library is installed and linked in your C++ environment .
2.  **Asset Loading**: The executable expects the following files in the same directory:
    * `SamuraiBlast.ttf` 
    * `Tetrisback.png` 
    * `butound.WAV` 
    * `Gameover.WAV` 
3.  **Compilation**: Link against `raylib`, `GL`, `m`, `pthread`, `dl`, and `rt`.

---

**Developed by Bilal**
