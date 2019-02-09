#ifndef RECT_H
#define RECT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	uint8_t x;
	uint8_t y;
}Coord_u8;

Coord_u8 c_Coord_u8(uint8_t x, uint8_t y);

typedef struct
{
	uint8_t x;
	uint8_t y;
	uint8_t w;
	uint8_t h;
}Rect_uint8;

bool Rect_uint8_containPos(const Rect_uint8*, uint8_t posX, uint8_t posY);
bool Rect_uint8_containRect_uint8(const Rect_uint8*, const Rect_uint8*);

#endif//RECT_H