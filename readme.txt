 <h1>Text-Based RPG Game<h1>

## Overview
This project is a text-based RPG game built using C++. It features a player class, multiple enemy types, a combat system, and an inventory system. The game implements Object-Oriented Programming (OOP) concepts like inheritance and polymorphism to create different weapon and enemy types.

## Features
- **Player Class**: Tracks player health, level, experience, and equipped weapon.
- **Enemy Types**: Includes Goblin, Troll, and Orc, each with different health and attack characteristics.
- **Combat System**: Uses player and enemy speed attributes to determine attack order. Player can attack enemies using various weapons, and combat ends when either the player or enemy is defeated.
- **Inventory** (Upcoming): Placeholder for managing player’s weapons and healing items.

## Classes and Structure
### Player
- **Attributes**: Health, level, experience, speed, and equipped weapon.
- **Methods**: 
  - `attack()`: Deals weapon damage to the enemy.
  - `takedamage()`: Reduces player health based on enemy attack.
  - `collect_exp_from_kill()`: Gains experience after defeating an enemy and levels up if experience thresholds are met.

### Enemy
- **Types**: Goblin, Troll, and Orc with unique stats.
- **Methods**: 
  - `attack_e()`: Returns the enemy's attack damage.
  - `takedamage()`: Reduces enemy health when attacked by the player.

### Weapons
- **Types**: Sword, Axe, and Spear.
- **Methods**:
  - `attack()`: Returns the weapon’s damage.

### Inventory (Planned Feature)
An `inventory` class is planned to manage the player’s items (weapons, healing items).

## Combat System
The combat system is turn-based, with the player or enemy attacking first based on their speed. The combat loop continues until either the player or enemy is defeated.

## Installation and Compilation
### Requirements
- **Compiler**: GCC or any C++ compiler that supports C++11 or higher.

### Compiling the Code
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/your-repository.git
