#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>
#include "player.h"

/* 
 * Perform raycasting for the maze.
 * 
 * renderer: The SDL renderer.
 * player: The player structure.
 */
void performRaycasting(SDL_Renderer *renderer, Player *player);

#endif /* RAYCASTING_H */

