#include "stateManager.h"

StateManager* initializeStateManager()
{
	StateManager* toReturn = malloc(sizeof(StateManager));
	toReturn->states = initializeVector();
	toReturn->mustStop = false;
	toReturn->mustReinit = false;
	return toReturn;

}

void run(StateManager* toRun)
{
	uint8_t delta, currentState;
	State* toRunState;
	toRunState = (State*)vec_getByPos(toRun->states, toRun->defaultState);
	currentState = toRun->defaultState;
	toRunState->launch(NULL);
	delta = 0;
	while (toRun->mustStop == false)
	{
		if (toRun->mustReinit == true){
			dbg_sprintf(dbgout, "Reinitialization of the state ordered.", toRun->states->size);
			currentState = toRun->defaultState;
			toRunState = (State*)vec_getByPos(toRun->states, toRun->defaultState);
			toRun->mustReinit = false;
			toRunState->launch(NULL);
		}
		kb_Scan();
		toRunState->tick(delta, toRunState);
		delta = (delta >= 255) ?  0 : delta + 1;
		//if (toRun->defaultState != currentState) return;
	}
}

void switchState(StateManager* switchInto, StateType switchFrom, StateType switchTo, void* args)
{
	uint8_t loop;
	State* toSwitch;
	dbg_sprintf(dbgout, "Searching for the next state...");
	for (loop = 0; loop != switchInto->states->size; ++loop)
	{
		if (((State*)vec_getByPos(switchInto->states, loop))->type == switchTo)
		{
			dbg_sprintf(dbgout,"Found next state", loop);
			switchInto->defaultState = loop;
			switchInto->mustReinit = true;
		}
	}
}

State* findStateManager(StateManager* findInto, StateType toFind)
{
	State* found;
	uint8_t loop;
	for (loop = 0; loop != findInto->states->size; ++loop)
	{
		if (((State*)vec_getByPos(findInto->states, loop))->type == toFind)
			return (State*)vec_getByPos(findInto->states, loop);
	}
	return NULL;
}
