#include "titleScreenState.h"

void drawSlidingBackground(gfx_sprite_t* sprite, uint8_t offset, uint8_t spriteRowNumber, bool isTransparent);

void onLaunch(void* args)
{
	gfx_Begin();
	gfx_SetPalette(titleScreenSprites_pal,sizeof_titleScreenSprites_pal, 0);
	gfx_SetDrawBuffer();
}

void onSwitch(StateType from, void* args)
{

}

void tick(uint8_t delta, State* args)
{

	uint8_t heightLoop, widthLoop;

	//gfx_FillScreen(1);
	drawSlidingBackground(arcs1, delta / 4, 10, false);
	drawSlidingBackground(arcs2, delta, 5, true);

	drawButtonWithText(20,20,100,40,NULL,false);
	gfx_SwapDraw();



	//tester les touches :
	kb_Scan();
	if (kb_Data[6] & kb_Enter)
	{
		gfx_End();
		args->stop();
	}

}

State* initializeTitleScreenState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void(*stop)())
{
	TitleScreenData* data;
	State* toReturn;
	data = malloc(sizeof(TitleScreenData));
	toReturn = malloc(sizeof(State));
	toReturn->launch = &onLaunch;
	toReturn->switchState = switchState;
	toReturn->switched = &onSwitch;
	toReturn->tick = &tick;
	toReturn->data = data;
	toReturn->stop = stop;
	return toReturn;
}

void drawSlidingBackground(gfx_sprite_t* sprite, uint8_t offset, uint8_t spriteColNumber, bool isTransparent)
{
	unsigned int loop, loop2;
	uint8_t spriteRows;
	uint8_t scaledOffset;

	scaledOffset = offset % sprite->height;
	spriteRows = 240 % sprite->height + 1;

	for (loop = 0; loop != spriteRows; ++loop)
	{
		for (loop2 = 0; loop2 != spriteColNumber; ++loop2)
		{
			if (isTransparent) gfx_TransparentSprite(sprite, sprite->width * loop, sprite->height * (loop2 - 1) + scaledOffset);
			else gfx_Sprite(sprite, sprite->width * loop, sprite->height * (loop2 - 1) + scaledOffset);
		}
	}

}
