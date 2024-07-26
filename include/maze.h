#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include "player.h"

/* Function declarations for maze functionality */

/**
 * handle_input - Handles user input and updates the player and map accordingly.
 * @e: The SDL event structure.
 * @quit: Pointer to the quit flag.
 * @player: A pointer to the Player structure.
 * @map: The game map.
 */
void handle_input(SDL_Event *e, int *quit, Player *player, int **map);

/**
 * draw_map - Draws the map and player's view.
 * @renderer: The SDL renderer.
 * @player: A pointer to the Player structure.
 * @map: The game map.
 * @map_width: The width of the map.
 * @map_height: The height of the map.
 * @show_map: Flag to enable or disable map drawing.
 */
void draw_map(SDL_Renderer *renderer, Player *player, int **map, int map_width, int map_height, int show_map);

/**
 * load_map - Loads the map from a file.
 * @filename: The file name of the map.
 * @map: Pointer to the map.
 * @map_width: Pointer to the width of the map.
 * @map_height: Pointer to the height of the map.
 */
void load_map(const char *filename, int ***map, int *map_width, int *map_height);

/**
 * free_map - Frees the memory allocated for the map.
 * @map: The game map.
 * @map_height: The height of the map.
 */
void free_map(int **map, int map_height);

/**
 * init_player - Initializes the player.
 * @player: Pointer to the Player structure.
 */
void init_player(Player *player);

/**
 * move_forward - Moves the player forward.
 * @player: Pointer to the Player structure.
 * @map: The game map.
 */
void move_forward(Player *player, int **map);

/**
 * move_backward - Moves the player backward.
 * @player: Pointer to the Player structure.
 * @map: The game map.
 */
void move_backward(Player *player, int **map);

/**
 * strafe_left - Moves the player to the left.
 * @player: Pointer to the Player structure.
 * @map: The game map.
 */
void strafe_left(Player *player, int **map);

/**
 * strafe_right - Moves the player to the right.
 * @player: Pointer to the Player structure.
 * @map: The game map.
 */
void strafe_right(Player *player, int **map);

/**
 * rotate_left - Rotates the player to the left.
 * @player: Pointer to the Player structure.
 */
void rotate_left(Player *player);

/**
 * rotate_right - Rotates the player to the right.
 * @player: Pointer to the Player structure.
 */
void rotate_right(Player *player);

#endif /* MAZE_H */

