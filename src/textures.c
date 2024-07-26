#include "textures.h"
#include <SDL2/SDL_image.h>

#define TEXTURE_COUNT 5
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

static SDL_Texture *textures[TEXTURE_COUNT];

/* 
 * Load textures from files.
 * 
 * renderer: The SDL renderer.
 * 
 * Returns: 0 on success, -1 on failure.
 */
int load_textures(SDL_Renderer *renderer) {
    const char *filenames[TEXTURE_COUNT] = {
        "texture1.png",
        "texture2.png",
        "texture3.png",
        "texture4.png",
        "texture5.png"
    };

    for (int i = 0; i < TEXTURE_COUNT; i++) {
        SDL_Surface *surface = IMG_Load(filenames[i]);
        if (!surface) {
            fprintf(stderr, "Failed to load texture %s: %s\n", filenames[i], IMG_GetError());
            return -1;
        }

        textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!textures[i]) {
            fprintf(stderr, "Failed to create texture from %s: %s\n", filenames[i], SDL_GetError());
            return -1;
        }
    }

    return 0;
}

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
void draw_wall(SDL_Renderer *renderer, int x, int drawStart, int drawEnd, int textureIndex, float wallX) {
    SDL_Rect srcRect = { wallX * TEXTURE_WIDTH, 0, 1, TEXTURE_HEIGHT };
    SDL_Rect dstRect = { x, drawStart, 1, drawEnd - drawStart };

    SDL_RenderCopy(renderer, textures[textureIndex], &srcRect, &dstRect);
}

