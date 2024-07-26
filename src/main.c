#include <SDL2/SDL.h>
#include "player.h"
#include "maze.h"
#include "map_parser.h"
#include "textures.h"
#include "raycasting.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* 
 * Handle input from the user.
 * 
 * e: The SDL event to process.
 * quit: Pointer to the quit flag.
 * player: The player structure.
 * map: The map array.
 */
void handle_input(SDL_Event *e, int *quit, Player *player, int **map) {
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) {
            *quit = 1;
        } else if (e->type == SDL_KEYDOWN) {
            switch (e->key.keysym.sym) {
                case SDLK_w:
                    move_forward(player, map);
                    break;
                case SDLK_s:
                    move_backward(player, map);
                    break;
                case SDLK_a:
                    strafe_left(player, map);
                    break;
                case SDLK_d:
                    strafe_right(player, map);
                    break;
                case SDLK_LEFT:
                    rotate_left(player);
                    break;
                case SDLK_RIGHT:
                    rotate_right(player);
                    break;
                default:
                    break;
            }
        }
    }
}

/* 
 * Main function for the program.
 * 
 * argc: Argument count.
 * argv: Argument vector.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <mapfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event e;
    int quit = 0;
    Player player;
    int **map;
    int map_width, map_height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if (load_map(argv[1], &map, &map_width, &map_height) != 0) {
        fprintf(stderr, "Failed to load map\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    init_player(&player);

    while (!quit) {
        handle_input(&e, &quit, &player, map);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        performRaycasting(renderer, &player);
        draw_map(renderer, &player, map, map_width, map_height, 1);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    free_map(map, map_height);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

