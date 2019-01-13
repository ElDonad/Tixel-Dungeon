#include "depth.h"

Depth* initializeDepth()
{
	Depth* toInitialize = malloc(sizeof(Depth));
	toInitialize->depthData = initializeSimplifiedDepth();
	return toInitialize;
}

bool canPlaceRoom(const Depth* toPlaceIn, Rect_uint8 roomPosition)
{
	int loop;
	vector* roomList = &toPlaceIn->depthData->rooms;
	Rect_uint8 depth;
	depth.posX = 0;
	depth.posY = 0;
	depth.sizeX = DEPTH_X;
	depth.sizeY = DEPTH_Y;

	if (toPlaceIn->posX + toPlaceIn->sizeX > depth.sizeX || toPlaceIn->posY + toPlaceIn->sizeY > depth.sizeY) return false;//si la pièce dépasse du niveau.

	for (loop = 0; loop != roomList->size; ++loop)
	{
		Room* check = (Room*) vec_getByPos(roomList, loop);
		
		if (Rect_uint8_containRect_uint8(&(check->room), &roomPosition)) return false;
	}

	return true;
}
