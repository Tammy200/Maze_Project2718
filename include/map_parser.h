#ifndef MAP_PARSER_H
#define MAP_PARSER_H

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
int load_map(const char *filename, int ***map, int *width, int *height);

/* 
 * Free the memory allocated for the map.
 * 
 * map: The map array.
 * height: The height of the map.
 */
void free_map(int **map, int height);

#endif /* MAP_PARSER_H */

