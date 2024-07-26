```markdown
# Maze Project

This project implements a 3D maze game using raycasting, SDL2, and a custom map parser. The game includes player movement, map parsing, texture rendering, and more, all following the Holberton coding style and documentation standards.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Tasks](#tasks)
- [Authors](#authors)

## Introduction

This project demonstrates the implementation of a basic 3D maze game using raycasting for rendering the maze walls. The player can navigate the maze using keyboard controls. The project includes functionalities for loading a map from a file, rendering the maze, and handling player movement and rotation.

## Features

- 3D maze rendering using raycasting
- Player movement and rotation
- Map parsing from a file
- Texture rendering for maze walls
- Keyboard controls for player navigation

## Dependencies

- SDL2
- GCC
- Make

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/malcolms-anatomy/maze_project.git
    cd maze_project
    ```

2. Install SDL2:
    ```bash
    sudo apt-get install libsdl2-dev
    ```

3. Compile the project:
    ```bash
    make
    ```

## Usage

To run the maze game, use the following command:
```bash
./maze_test <path_to_map_file>
```

For example:
```bash
./maze_test maps/map1.txt
```

## File Descriptions

- `src/main.c`: Entry point of the program, initializes SDL, loads the map, and handles the game loop.
- `src/raycasting.c`: Contains the raycasting algorithm and rendering logic.
- `src/player.c`: Handles player initialization and movement.
- `src/map_parser.c`: Parses the map file and loads the map into memory.
- `src/textures.c`: Manages textures used for rendering the maze walls.
- `include/maze.h`: Header file for the main game functions and structures.
- `include/player.h`: Header file for player-related functions and structures.
- `include/map_parser.h`: Header file for map parser functions.
- `include/raycasting.h`: Header file for raycasting functions.
- `include/textures.h`: Header file for texture functions.

## Tasks

### Task 1: Setting Up the Project Structure
- Created the initial project structure with necessary directories and files.

### Task 2: SDL Initialization
- Initialized SDL2 and created a window and renderer.

### Task 3: Implementing Raycasting
- Implemented the basic raycasting algorithm to render the 3D maze walls.

### Task 4: Player Movement and Rotation
- Implemented player movement (forward, backward, strafe left, strafe right) and rotation (left, right).

### Task 5: Map Parsing
- Created a map parser to load the maze layout from a file.

### Task 6: Texture Rendering
- Implemented texture rendering for maze walls using SDL2 textures.

### Task 7: Input Handling
- Added input handling for player movement and rotation using keyboard events.

### Task 8: Memory Management
- Implemented memory management for dynamic allocation and deallocation of map data.

## Authors

- Malcolm Iheremelam (malcolmihere@outlook.com)

```

This README.md file provides a comprehensive overview of the Maze Project, including its features, dependencies, installation steps, usage instructions, file descriptions, and the tasks completed so far.
