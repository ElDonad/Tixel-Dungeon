#include "inGameState.h"

void onLaunch(void* args)
{

}

void onSwitch(StateType switchFrom, void* args)
{

}

void tick(uint8_t delta, State* self)
{
	InGameData* data;


	data = (InGameData*)self->data;
	if (data->isInitialized == false)//si premier lancement : 
	{
		data->gameStruct = initializeGlobalStruct(Rogue, 150, 1, 150, 1, 123 * delta, NULL);
	}

	if (data->loadedLevel != data->gameStruct->currentDepth->id)//si le niveau n'est pas encore chargé...
	{

	}
}

State* initializeInGameState(void (*switchState)(StateType switchFrom, StateType switchTo, void* data), void (*stop)())
{
	InGameData* data;
	State* toReturn;
	data = malloc(sizeof(InGameData));
	data->isInitialized = false;
	data->loadedLevel = 0;

	toReturn = malloc(sizeof(State));
	toReturn->type = INGAME_STATE;
	toReturn->launch = &onLaunch;
	toReturn->switchState = switchState;
	toReturn->switched = &onSwitch;
	toReturn->tick = &tick;
	toReturn->data = data;
	toReturn->stop = stop;
	return toReturn;
}