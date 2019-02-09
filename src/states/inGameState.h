#ifndef IN_GAME_STATE_H
#define IN_GAME_STATE_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../state.h"
#include "switchStateStructs.h"

#include "../data/dataManager.h"
#include "../functional/generator.h"

typedef struct
{
	Global* gameStruct;
	bool isInitialized;
}InGameData;

typedef struct{//à continuer
	PlayerType playerType;

}InGameSwitchData;

State* initializeInGameState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void (*stop)());
#endif