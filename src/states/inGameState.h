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

typedef struct
{
	Global* gameStruct;
	bool isInitialized;
	int loadedLevel;
}InGameData;



State* initializeInGameState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void (*stop)());
