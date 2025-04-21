# so_long 🎮
A 2D tile-based game built with MiniLibX
42 School Project | C Programming & Graphics Fundamentals

# 🌐 Overview
so_long is a minimalist 2D game where the player navigates a map to collect items and escape. Built from scratch in C using 42's MiniLibX graphics library, this project demonstrates:

Graphics rendering (sprites, animations)

Map parsing and validation

Event handling (keyboard inputs)

Pathfinding algorithms (flood fill to check map)

# 🎯 Features
Core Gameplay
Tile-based movement (WASD/arrow keys)

Collectible system (score tracking)

Dynamic rendering of sprites (player, walls, items, exits)

Win/lose conditions

Customizable maps via .ber files

Enemy patrol

Technical Highlights

Memory-efficient (zero leaks, Valgrind-approved)

Error handling for invalid maps

Pixel-perfect rendering with MiniLibX


# 🕹️ Usage

./so_long maps/map1.ber  

Controls

Move	W A S D
Quit	ESC or window X

# 🗺️ Map Format (.ber)
Maps are text files where:

1 = Wall

0 = Empty space

P = Player (exactly 1)

C = Collectible (≥1)

E = Exit (≥1)

G = Enemy (bonus)

# ✅ Compliance

42 Norminette: Strict coding style

No leaks: Verified with Valgrind

Error handling: Graceful exits