/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
 * Description:
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <debug.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data/dataManager.h"
#include "stateManager.h"

#include "states/titleScreenState.h"
#include "states/inGameState.h"
/* Put your function prototypes here */
void switchStateMain(StateType switchFrom, StateType switchTo, void* data);
void stop();
/* Put all your globals here */
StateManager* stateManager;

void main(void) {


    State* titleScreenState;
    State* inGameState;
	stateManager = initializeStateManager();
	dbg_sprintf(dbgout, "avant initialisation titleScreenState");
    titleScreenState = initializeTitleScreenState(switchStateMain, stop);
    vec_push_back(stateManager->states, titleScreenState);
    stateManager->defaultState = 0;
	dbg_sprintf(dbgout, "titleScreenState initialise");

	inGameState = initializeInGameState(switchStateMain, stop);
	vec_push_back(stateManager->states, inGameState);


	run(stateManager);

}

/* Put other functions here*/
void switchStateMain(StateType switchFrom, StateType switchTo, void* data)
{
	switchState(stateManager, switchFrom, switchTo, data);
}

void stop()
{
  stateManager->mustStop = true;
}
