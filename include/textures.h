#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL.h>

/* 
 * Load textures from files.
 * 
 * renderer: The SDL renderer.
 * 
 * Returns: 0 on success, -1 on failure.
 */
int load_textures(SDL_Renderer *renderer);

/* 
 * Draw a wall with texture.
 * 
 * renderer: The SDL renderer.
 * x: X position on the screen.
 * drawStart: Start Y position for drawing.
 * drawEnd: End Y position for drawing.
 * textureIndex: Index of the texture to use.
 * wallX: X position of the wall texture.
 */
void draw_wall(SDL_Renderer *renderer, int x, int drawStart, int drawEnd, int textureIndex, float wallX);

#endif /* TEXTURES_H */

