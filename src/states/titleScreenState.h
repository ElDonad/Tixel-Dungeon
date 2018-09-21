#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <keypadc.h>

#include "../state.h"

#include "../gfx/titleScreenSprites.h"
#include "../render/button.h"

typedef enum
{
	MAIN_MENU,
	PERSONNAGE_SELECTION_MENU
}Menu;

typedef struct
{

	Menu menuIn;
	uint8_t currentButton;//Utilisé pour savoir où l'utilisateur souhaite cliquer.
}TitleScreenData;

//Dans les fonctions suivantes, currentState désigne la struct State qui contient ces fonctions.
void onLaunch(void* args);//args : State* currentState
void onSwitch(StateType switchFrom, void* args);//args : State* currentState
void tick(uint8_t delta, State* args);//args : State* currentState

State* initializeTitleScreenState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void (*stop)());