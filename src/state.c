#include "state.h"

/*State* initializeState(StateType type, void (*launch)(void* args), void (*switchState)(StateType switchTo, void* args), void (*switched)(StateType switchFrom, void* args), void (*tick)(uint8_t delta, State* args), void* data)
{
	State* toInitialize = malloc(sizeof(State));
	toInitialize->type = type;
	toInitialize->launch = launch;
	toInitialize->switchTo = switchTo;
	toInitialize->switched = switched;
	toInitialize->tick = tick;
	toInitialize->data = data;

	return toInitialize;
	
}*/