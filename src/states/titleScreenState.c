#include "titleScreenState.h"

void drawSlidingBackground(gfx_sprite_t* sprite, uint8_t offset, uint8_t spriteRowNumber, bool isTransparent);

void onLaunchTTS(void* args)
{
	gfx_Begin();
	gfx_SetPalette(titleScreenSprites_pal,sizeof_titleScreenSprites_pal, 0);
	gfx_SetDrawBuffer();
	dbg_sprintf(dbgout, "Title screen state initialized");
}

void onSwitchTTS(StateType from, void* args)
{

}

void tickTTS(uint8_t delta, State* self)
{

	TitleScreenData* data = (TitleScreenData*) self->data;
	uint8_t heightLoop, widthLoop;
	char truc[] = "0121:23";

	//gfx_FillScreen(1);
	drawSlidingBackground(arcs1, delta / 4, 10, false);
	drawSlidingBackground(arcs2, delta, 5, true);

	drawButtonWithText(20,20,100,40,NULL,false);
	drawString(truc, SmallFontIndex, 24,24,80,2,LeftAlignment);
	gfx_SwapDraw();



	//tester les touches :
	if (kb_Data[6] & kb_Clear)
	{
		gfx_End();
		self->stop();
	}
	if (kb_Data[6] & kb_Enter)//Passer en mode ingame
	{
		MainMenuToInGameStruct* machin;
		dbg_sprintf(dbgout, "Lancement du nouvel état...");
		machin = malloc(sizeof(MainMenuToInGameStruct));
		machin->isNewRun = true;
		self->switchState(MAIN_MENU_STATE, INGAME_STATE, machin);
		//dbg_sprintf(dbgout, "new rand : %i", randomInt(&data->gen, 1,50));

	}

}

State* initializeTitleScreenState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void(*stop)())
{
	TitleScreenData* data;
	State* toReturn;
	data = malloc(sizeof(TitleScreenData));
	data->gen.seed = 2567871;
	toReturn = malloc(sizeof(State));
	toReturn->type = MAIN_MENU_STATE;
	toReturn->launch = &onLaunchTTS;
	toReturn->switchState = switchState;
	toReturn->switched = &onSwitchTTS;
	toReturn->tick = &tickTTS;
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
