# Daenyum - Text-based RPG Combat

**Daenyum** is a retro-inspired, text-based RPG combat game written in C, designed to evoke the charm of 1980s console games. Featuring turn-based battles, character progression, multilingual support, and random events, Daenyum offers an immersive experience for players.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg) 

<br>

## Features 📋

- **Retro ASCII Banner**: Displays a stylized "DAENYUM, Text-based RPG Combat by PHForge" banner at startup.
- **Dynamic Characters**: Players and enemies are defined by a `Character` struct with attributes (name, HP, attack, defense, dodge, crit, luck).
- **Progression System**: Players gain experience (XP) to level up, with automatic stat improvements. Enemies scale with player level. Defeated players are revived with reset stats.
- **Turn-based Combat**: Engaging battles where players and enemies attack until one reaches 0 HP.
- **Randomized Damage**: Damage calculations incorporate randomness, influenced by defense, dodge, crit, and luck stats.
- **Interactive Menu**:
  - **Start Adventure**: Initiate a combat in a random environment (cave, dungeon, labyrinth, forest).
  - **View Stats**: Display player statistics.
  - **Settings**: Switch languages (English, French, Spanish, Brazilian Portuguese).
  - **Credits**: A heartfelt dedication to my wife and son for their support.
  - **Quit**: Exit the game gracefully.
- **Save/Load System**: Persist player profiles between sessions.
- **Varied Enemies**: Encounter different enemy types (e.g., Goblin, Troll) selected randomly.
- **Combat Environments**: Battle in atmospheric locations (cave, dungeon, labyrinth, forest).
- **Random Events**: Unexpected events like "Divine Intervention" (revives player), "Celestial Shock" (stat boost), or "Curse" (enemy debuff).
- **Flee Mechanism**: Option to flee combat, with success based on the luck stat.

<br>

## System Requirements ⚙️

The following components are required to build, run, or contribute to this project:

| Component          | Requirement                              | Notes                                      |
|--------------------|------------------------------------------|--------------------------------------------|
| Language | C                                      | Core language used for the project         |
| Compiler       | GCC                                      | Ensure GCC is installed (e.g., MinGW for Windows) |
| Libraries      | Standard C Libraries (stdio.h, stdlib.h, time.h, locale.h, windows.h) | Included with standard C installations      |
| IDE/Editor     | Code::Blocks or any C-compatible IDE/terminal | Other IDEs like VS Code or CLion can be used |
| Version Control | Git                                     | Required to clone the repository           |

> [!TIP]
> For optimal setup, install GCC via [MinGW](https://www.mingw-w64.org/) on Windows or use a package manager like `apt` or `brew` on Linux/macOS to install Git and GCC.

<br>

## Installation </>

1. **Clone the Repository**:
	```
	git clone https://github.com/PHForge/Daenyum_Text-basedRPG.git
	cd Daenyum_Text-basedRPG
	```

2. **Compile the Project**:
	- Windows: Use MinGW and run:
		```	
		gcc -o daenyum main.c character.c combat.c utils.c -finput-charset=UTF-8 -fexec-charset=UTF-8
		```
	- Linux/macOS: Ensure GCC is installed (`sudo apt install gcc` or `brew install gcc`) and run:
		```	
		gcc -o daenyum main.c character.c combat.c utils.c -finput-charset=UTF-8 -fexec-charset=UTF-8
		```

4. **Run the Game**:
	```
	./daenyum
	```

<br>

## Project Structure 🗂️

```bash
├── main.c           # Entry point of the game
├── character.c      # Character management and save/load logic
├── character.h	     # Header for character functions
├── combat.c         # Combat mechanics and random events
├── combat.h         # Header for combat functions
├── utils.c          # Utilities (banner, multilingual messages)
├── utils.h          # Header for utility functions
├── LICENSE          # MIT License
├── .gitignore       # Ignore compiled files
└── README.md        # This file
```

<br>

## License 🧾

This project is licensed under the **MIT License** - see the LICENSE file for details.

<br>

## Crédits ☕

> Developed by PHForge. 
> Feel free to reach out via [GitHub](https://github.com/PHForge) for feedback or collaboration ideas!

> Special thanks ❤️ to my wife and son for their patience and love.

<br>

## Example Output 💻

```bash

      ***** **
   ******  ***
 **    *  * ***
*     *  *   ***
     *  *     ***                                   **   ****      **   ****
    ** **      **    ****       ***    ***  ****     **    ***  *   **    ***  * *** **** ****
    ** **      **   * ***  *   * ***    **** **** *  **     ****    **     ****   *** **** ***  *
    ** **      **  *   ****   *   ***    **   ****   **      **     **      **     **  **** ****
    ** **      ** **    **   **    ***   **    **    **      **     **      **     **   **   **
    ** **      ** **    **   ********    **    **    **      **     **      **     **   **   **
    *  **      ** **    **   *******     **    **    **      **     **      **     **   **   **
       *       *  **    **   **          **    **    **      **     **      **     **   **   **
  *****       *   **    **   ****    *   **    **     *********      ******* **    **   **   **
 *   *********     ***** **   *******    ***   ***      **** ***      *****   **   ***  ***  ***
*       ****        ***   **   *****      ***   ***           ***                   ***  ***  ***
*                                                      *****   ***
 **                                                  ********  **
                                                    *      ****

                     Daenyum, Text-based RPG Combat by PHForge

=== Text-based RPG Combat ===

1. Start adventure
2. View stats
3. Settings
4. Credits
5. Quit
```