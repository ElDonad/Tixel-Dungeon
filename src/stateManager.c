#include "stateManager.h"

StateManager* initializeStateManager()
{
	StateManager* toReturn = malloc(sizeof(StateManager));
	toReturn->states = initializeVector();
	toReturn->mustStop = false;
	return toReturn;

}

void run(StateManager* toRun)
{
	uint8_t delta, currentState;
	State* toRunState = (State*)vec_getByPos(toRun->states, toRun->defaultState);
	currentState = toRun->defaultState;
	toRunState->launch(NULL);
	delta = 0;
	while (toRun->mustStop == false)
	{
		kb_Scan();
		toRunState->tick(delta, toRunState);
		delta = (delta >= 255) ?  0 : delta + 1;
		if (toRun->defaultState != currentState) return;
	}
}

void switchState(StateManager* switchInto, StateType switchFrom, StateType switchTo, void* args)
{
	uint8_t loop;
	State* toSwitch;
	for (loop = 0; loop != switchInto->states->size; ++loop)
	{
		if (((State*)vec_getByPos(switchInto->states, loop))->type == switchTo)
		{
			switchInto->defaultState = loop;
		}
	}
}
