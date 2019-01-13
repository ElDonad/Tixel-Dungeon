#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	uint8_t posX;
	uint8_t posY;
	uint8_t sizeX;
	uint8_t sizeY;
}Rect_uint8;

bool Rect_uint8_containPos(const Rect_uint8*, uint8_t posX, uint8_t posY);
bool Rect_uint8_containRect_uint8(const Rect_uint8*, const Rect_uint8*);