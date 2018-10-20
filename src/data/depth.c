#include "depth.h"

Depth* initializeDepth()
{
	Depth* toInitialize = malloc(sizeof(Depth));
	toInitialize->depthData = initializeSimplifiedDepth();
	return toInitialize;
}

bool canPlaceRoom(Depth* toPlaceIn, uint8_t roomSizeX, uint8_t roomSizeY, uint8_t roomPosX, uint8_t roomPosY)
{
	int loop;
	vector* roomList = &toPlaceIn->depthData->rooms;

	for (loop = 0; loop != roomList->size; ++loop)
	{
		Room* check = (Room*) vec_getByPos(roomList, loop);

		/*Algorithme :
			- On vérifie que le point du haut gauche de la pièce n'est pas dans la pièce à tester
			- On vérifie que le point du bas droite de la pièce n'est pas dans la pièce à tester
			- On vérifie que le point du haut gauche de la pièce à tester n'est pas dans la pièce
			- On vérifie que le point du bas droite de la pièce à tester n'est pas dans la pièce

		*/
		if ()
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
