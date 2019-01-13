#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/rect.h"


/* INFORMATION IMPORTANTE : 
	- le rect room contient les coordonées INTERIEURES de la pièce. Les murs ne sont pas pris en compte ! 

*/

typedef struct
{
	Rect_uint8 room;
	uint8_t accesNumber;
}Room;

Room* initializeRoom(roomX, roomY, roomPosX, roomPosY);