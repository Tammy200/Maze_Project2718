#include "player.h"
#include <math.h>

/**
 * init_player - Initializes a player with default values.
 * @player: A pointer to the Player structure to initialize.
 */
void init_player(Player *player) {
    player->x = 5.0f;    // Default starting X position
    player->y = 5.0f;    // Default starting Y position
    player->angle = 0.0f; // Default angle (facing right)
    player->speed = 0.1f; // Default speed
}

/**
 * move_forward - Moves the player forward based on their speed and direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void move_forward(Player *player, int **map) {
    player->x += player->speed * cos(player->angle);
    player->y += player->speed * sin(player->angle);
    // Collision detection and map boundaries should be handled here
}

/**
 * move_backward - Moves the player backward based on their speed and direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void move_backward(Player *player, int **map) {
    player->x -= player->speed * cos(player->angle);
    player->y -= player->speed * sin(player->angle);
    // Collision detection and map boundaries should be handled here
}

/**
 * strafe_left - Moves the player left relative to their direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void strafe_left(Player *player, int **map) {
    player->x -= player->speed * cos(player->angle + M_PI / 2);
    player->y -= player->speed * sin(player->angle + M_PI / 2);
    // Collision detection and map boundaries should be handled here
}

/**
 * strafe_right - Moves the player right relative to their direction.
 * @player: A pointer to the Player structure to move.
 * @map: The game map.
 */
void strafe_right(Player *player, int **map) {
    player->x += player->speed * cos(player->angle - M_PI / 2);
    player->y += player->speed * sin(player->angle - M_PI / 2);
    // Collision detection and map boundaries should be handled here
}

/**
 * rotate_left - Rotates the player left based on their rotation speed.
 * @player: A pointer to the Player structure to rotate.
 */
void rotate_left(Player *player) {
    player->angle -= 0.1f; // Rotate left by 0.1 radians
}

/**
 * rotate_right - Rotates the player right based on their rotation speed.
 * @player: A pointer to the Player structure to rotate.
 */
void rotate_right(Player *player) {
    player->angle += 0.1f; // Rotate right by 0.1 radians
}

