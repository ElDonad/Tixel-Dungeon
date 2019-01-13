#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simplifiedDepth.h"
#include "room.h"

#include "../utils/rect.h"
#include "../utils/random.h"

#define DEPTH_X 50
#define DEPTH_Y 50

typedef enum
{
	WALL=1,
	FLOOR,
	CLOSED_DOOR,
	OPENED_DOOR

}TilesType;

typedef struct
{
	uint8_t id;
	uint8_t* tiles;
	SimplifiedDepth* depthData;
}Depth;

bool canPlaceRoom(const Depth* toPlaceIn,Rect_uint8);// /!\ : exceptionnellement, n'initialise pas les données du level, dans un soucis d'optimisation.
