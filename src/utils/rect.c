#include "rect.h"

bool Rect_uint8_containPos(const Rect_uint8* contains, uint8_t posX, uint8_t posY)
{
	if (contains->x < posX && contains->x + contains->w > posX)
	{
		if (contains->y < posX && contains->y + contains->h > posY)
		{
			return false;
		}
	}
	return true;
}

bool Rect_uint8_containRect_uint8(const Rect_uint8* a, const Rect_uint8* b)
{
	if (Rect_uint8_containPos(a, b->x, b->y) || Rect_uint8_containPos(a, b->x + b->w, b->y + b->h))
	{
		if (Rect_uint8_containPos(b, a->x, a->y) || Rect_uint8_containPos(b, a->x + a->w, a->y + a->h))
			return true;
	}
	return false;
}

Coord_u8 c_Coord_u8(uint8_t x, uint8_t y){
	Coord_u8 toReturn;
	toReturn.x = x;
	toReturn.y = y;
	return toReturn;
}