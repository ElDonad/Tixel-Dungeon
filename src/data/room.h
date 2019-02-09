#ifndef ROOM_H
#define ROOM_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/rect.h"
#include "../utils/vector.h"


/* INFORMATION IMPORTANTE : 
	- le rect room contient les coordonées INTERIEURES de la pièce. Les murs ne sont pas pris en compte ! 

*/

typedef enum{
	UP,
	DOWN,
	RIGHT,
	LEFT
}Direction;

typedef enum{
	HORIZONTAL,
	VERTICAL
}Orientation;

typedef struct{
	Rect_uint8 size;
}Room;

typedef struct{
	vector* straights;
}Path;

Path* c_Path();

typedef struct{
	uint8_t x;
	uint8_t y;
	int length;
	Orientation orientation;
}Straight;

void checkRoom (Room check);
Coord_u8 getEndStraight(Straight*);

#endif//ROOM_H