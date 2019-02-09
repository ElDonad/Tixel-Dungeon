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
	vector* states;//type : State*
	uint8_t defaultState;
	bool mustStop;
	bool mustReinit;
}StateManager;

StateManager* initializeStateManager();
State* findStateManager(StateManager* findInto, StateType toFind);
void switchState(StateManager* sitchInto, StateType switchFrom, StateType switchTo, void* args);
void run(StateManager* toRun);
