#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	uint8_t roomSizeX; 
	uint8_t roomSizeY;
	uint8_t roomPosX;
	uint8_t roomPosY;
	uint8_t accesNumber;
}Room;

Room* initializeRoom(roomX, roomY, roomPosX, roomPosY);