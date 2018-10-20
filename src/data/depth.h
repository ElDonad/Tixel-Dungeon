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

bool canPlaceRoom(Depth* toPlaceIn, uint8_t roomSizeX, uint8_t roomSizeY, uint8_t roomPosX, uint8_t roomPosY);// /!\ : exceptionnellement, n'initialise pas les données du level, dans un soucis d'optimisation.
