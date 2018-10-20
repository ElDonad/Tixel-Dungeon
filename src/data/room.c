#include "room.h"

Room* initializeRoom(uint8_t dimX, uint8_t dimY, uint8_t posX, uint8_t posY)
{
	Room* toInitialize = malloc(sizeof(Room));
	toInitialize->roomX = dimX;
	toInitialize->roomY = dimY;
	toInitialize->posX = posX;
	toInitialize->posY = posY;
	toInitialize->accessNumber = 0;
}