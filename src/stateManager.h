#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <keypadc.h>

#include "state.h"
#include "utils/vector.h"


typedef struct
{
	vector* states;
	uint8_t defaultState;
	bool mustStop;
}StateManager;

StateManager* initializeStateManager();
void switchState(StateManager* sitchInto, StateType switchFrom, StateType switchTo, void* args);
void run(StateManager* toRun);
