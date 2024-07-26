#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

/**
 * struct Player - Represents a player in the game.
 * @x: The X-coordinate of the player.
 * @y: The Y-coordinate of the player.
 * @angle: The angle the player is facing (in radians).
 * @speed: The speed at which the player moves.
 */
typedef struct Player {
    float x;
    float y;
    float angle;
    float speed;
} Player;

/**
 * init_player - Initializes a player with default values.
 * @player: A pointer to the Player structure to initialize.
 */
void init_player(Player *player);

/**
 * move_forward - Moves the player forward based on their speed and direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void move_forward(Player *player, int **map);

/**
 * move_backward - Moves the player backward based on their speed and direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void move_backward(Player *player, int **map);

/**
 * strafe_left - Moves the player left relative to their direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void strafe_left(Player *player, int **map);

/**
 * strafe_right - Moves the player right relative to their direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void strafe_right(Player *player, int **map);

/**
 * rotate_left - Rotates the player left based on their rotation speed.
 * @player: A pointer to the Player structure to rotate.
 */
void rotate_left(Player *player);

/**
 * rotate_right - Rotates the player right based on their rotation speed.
 * @player: A pointer to the Player structure to rotate.
 */
void rotate_right(Player *player);

#endif /* PLAYER_H */

