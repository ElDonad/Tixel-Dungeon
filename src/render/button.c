#include "button.h"

void drawButtonFrame(uint24_t posX, uint8_t posY, uint8_t sizeX, uint8_t sizeY, bool hovered);

void drawButtonWithText(uint24_t posX, uint8_t posY, uint8_t sizeX, uint8_t sizeY, char* text, bool hovered)
{
	drawButtonFrame(posX, posY, sizeX, sizeY, hovered);
}

#define NORMAL_COLOR 1
#define BRIGHT_COLOR 2
#define DARK_COLOR   3

void drawButtonFrame(uint24_t posX, uint8_t posY, uint8_t sizeX, uint8_t sizeY, bool hovered)
{
	if (hovered == false)//normal button
	{
		gfx_SetColor(NORMAL_COLOR);
		gfx_FillRectangle_NoClip(posX, posY,sizeX, sizeY);//Couleur de fond

		gfx_SetColor(BRIGHT_COLOR);
		gfx_FillRectangle_NoClip(posX, posY,sizeX - 2, 2);//barre horizontale
		gfx_FillRectangle_NoClip(posX, posY,2, sizeY - 2);

		gfx_SetColor(DARK_COLOR);
		gfx_FillRectangle_NoClip(posX + 2, posY + sizeY - 2, sizeX - 2, 2);
		gfx_FillRectangle_NoClip(posX + sizeX - 2, posY + 2, 2, sizeY - 2);

	}
}