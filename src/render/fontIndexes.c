#include "fontIndexes.h"

uint8_t getCharSize(FontIndexes index, char character)
{
	uint8_t* selectedIndex;
	if (index == SmallFontIndex) selectedIndex = &smallFontTable;
	switch (character)
	{
		case '0': return *(selectedIndex + 0);
		case '1': return *(selectedIndex + 1);
		case '2': return *(selectedIndex + 2);
		case '3': return *(selectedIndex + 3);
		case '4': return *(selectedIndex + 4);
		case '5': return *(selectedIndex + 5);
		case '6': return *(selectedIndex + 6);
		case '7': return *(selectedIndex + 7);
		case '8': return *(selectedIndex + 8);
		case '9': return *(selectedIndex + 9);
		case ':': return *(selectedIndex + 10);
		case '0': return *(selectedIndex + 11);
		case '0': return *(selectedIndex + 12);
		case '0': return *(selectedIndex + 13);
		case '0': return *(selectedIndex + 14);
		case '0': return *(selectedIndex + 15);
	}
}