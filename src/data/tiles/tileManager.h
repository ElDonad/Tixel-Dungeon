#ifndef TILE_MANAGER_H
#define TILE_MANAGER_H
/* Ce fichier s'occupe de fournir un tableau de textures à un niveau nouvellement chargé, ainsi que de fournir
   la liste des variantes des blocs d'un type de niveau.

*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <debug.h>
#include <graphx.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_WALL 0
#define TILE_CUT_GRASS 1
#define TILE_GRASS 2
#define TILE_BURNT_GRASS 3
#define TILE_DOWNSTAIRS 4
#define TILE_UPSTAIRS 5
#define TILE_DOOR_OPEN 6
#define TILE_DOOR_CLOSED 7
#define TILE_DOOR_LOCKED 8
#define TILE_FLOOR 9
#define TILE_TRAP 10

typedef uint8_t Tile;

void loadTexturesForLevel(uint8_t level);
void drawTileAtCoordinate(Tile toDraw, int x, int y);


#endif
