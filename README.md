# 🚀 2D Space Shooter Game

A simple 2D space shooter game developed using **C++** and **SFML (Simple and Fast Multimedia Library)**.

---

## 🎮 Game Overview

This game is a classic 2D space shooter where the player controls a spaceship to shoot down incoming enemies, collect power-ups, and survive as long as possible. The game includes a start menu, enemy spawning mechanics, shooting with cooldowns, power-ups, and a scoring system with high score tracking.

---

## 📂 File Structure

### `main.cpp`
- Initializes the game engine.
- Contains the **main loop** with nested loops for:
  - Start menu
  - Game logic
  - Restart menu
- Manages transitions between game states (start, play, game over, restart).
- Calls functions to reset game state and clear vectors on restart.

### `Game.h` / `Game.cpp`
- `Game.h` contains the structure and declarations of all game attributes.
- `Game.cpp` implements the full game logic:
  - Backend: `update()` methods
  - Rendering: `render()` methods
  - Initialization and window creation (`initWindow()`)

---

## 🔧 Key Features & Mechanics

### 🎮 Controls
- **Arrow Keys / WASD**: Move the player
- **Spacebar**: Fire bullets
- **Mouse**: Menu navigation
- **Escape**: Exit game

### 💣 Enemy Management
- Enemies spawn at the top and move downward.
- Special enemies with more health appear occasionally.

### 🔫 Firing System
- Bullets move upward and collide with enemies.
- Cooldown system prevents spamming.

### ⚡ Power-ups
- Randomly falling boosts that reduce firing cooldown when collected.

### 🧠 Game Logic
- Collision detection using `getGlobalBounds()`
- Game Over when player dies
- High score saved and displayed

---

## 🖼️ SFML Functions Used

Some important SFML functions used include:
- `sf::RenderWindow::draw()`, `clear()`, `display()`
- `sf::Keyboard::isKeyPressed()`, `sf::Mouse::getPosition()`
- `sf::RenderWindow::mapPixelToCoords()`, `pollEvent()`, `close()`
- `sf::Shape::getGlobalBounds()`
- `sf::Text` and `sf::Font` for UI
- `sf::SoundBuffer` and `sf::Sound` for audio

---

## 🔚 Ending the Game

- When the player dies, a **Game Over** screen is shown.
- If the player beats the high score, it is saved.
- The player can **restart** or **exit** from the menu.

---

## 🏁 Conclusion

This project demonstrates the development of a complete 2D space shooter game using C++ and SFML. It includes key game development concepts such as:
- Real-time input handling
- Rendering and animation
- Collision detection
- State management
- Audio and UI integration

---

## ✅ Requirements

- C++ Compiler (e.g., g++)
- SFML Library

To build the game:
```bash
g++ main.cpp Game.cpp -o space_shooter -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
