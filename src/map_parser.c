#include "map_parser.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * Load the map from a file.
 * 
 * filename: The name of the map file.
 * map: Pointer to the map array.
 * width: Pointer to the width of the map.
 * height: Pointer to the height of the map.
 * 
 * Returns: 0 on success, -1 on failure.
 */
int load_map(const char *filename, int ***map, int *width, int *height) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return -1;
    }

    fscanf(file, "%d %d", width, height);

    *map = malloc(*height * sizeof(int *));
    for (int i = 0; i < *height; i++) {
        (*map)[i] = malloc(*width * sizeof(int));
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &(*map)[i][j]);
        }
    }

    fclose(file);
    return 0;
}

/* 
 * Free the memory allocated for the map.
 * 
 * map: The map array.
 * height: The height of the map.
 */
void free_map(int **map, int height) {
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

