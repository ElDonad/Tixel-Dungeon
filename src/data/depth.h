#ifndef DEPTH_H
#define DEPTH_H


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
#include "room.h"

#define DEPTH_X 50
#define DEPTH_Y 50

typedef enum
{
	NOTHING=0,
	WALL,
	FLOOR,
	CLOSED_DOOR,
	OPENED_DOOR

}TilesType;

typedef struct
{
	uint8_t* tiles;
	SimplifiedDepth* data;
}Depth;

Depth* initializeDepth();
bool roomCollide(Room*, Depth*);
void test(Depth* test);
bool corridorCollide(Path* cor1, Depth* depth);

#endif