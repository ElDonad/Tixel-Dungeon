#include "rect.h"

bool Rect_uint8_containPos(const Rect_uint8* contains, uint8_t posX, uint8_t posY)
{
	if (contains->posX < posX && contains->posX + contains->sizeX > posX)
	{
		if (contains->posY < posX && contains->posY + contains->sizeY > posY)
		{
			return false;
		}
	}
	return true;
}

bool Rect_uint8_containRect_uint8(const Rect_uint8* a, const Rect_uint8* b)
{
	if (Rect_uint8_containPos(a, b->posX, b->posY) || Rect_uint8_containPos(a, b->posX + b->sizeX, b->posY + b->sizeY))
	{
		if (Rect_uint8_containPos(b, a->posX, a->posY) || Rect_uint8_containPos(b, a->posX + a->sizeX, a->posY + a->sizeY))
			return true;
	}
	return false;
}