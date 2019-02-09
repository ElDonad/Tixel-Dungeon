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
		dbg_sprintf(dbgout, "begin initialisation");
		data->gameStruct = initializeGlobalStruct(Rogue, 150, 1, 150, 1, 123 * delta, NULL);
		dbg_sprintf(dbgout, "global struct initialized");
		//TODO : remettre ça à sa place, avant l'initialisation de tout. Si nécessaire.
		data->gameStruct->loadedDepth = initializeDepth();
		data->gameStruct->loadedDepth->data->depth = 0;
		data->gameStruct->currentDepth = 1;
		data->isInitialized = true;
		dbg_sprintf(dbgout, "end of dead loop");
	}

	if (data->gameStruct->currentDepth != data->gameStruct->loadedDepth->data->depth)//si le niveau n'est pas encore chargé...
	{
		dbg_sprintf(dbgout, "before level generation...");
		generateLevel(data->gameStruct->loadedDepth, 27, data->gameStruct->currentDepth);
		dbg_sprintf(dbgout, "Generation done");
	}
	else{
		dbg_sprintf(dbgout, "bug de condition...");
	}
}

State* initializeInGameState(void (*switchState)(StateType switchFrom, StateType switchTo, void* dataInutile), void (*stop)())
{
	InGameData* data;
	State* toReturn;
	data = malloc(sizeof(InGameData));
	data->isInitialized = false;
/*	data->gameStruct->loadedDepth = malloc(sizeof(Depth));
	data->gameStruct->loadedDepth->data->depth = 0;
	data->gameStruct->currentDepth = 1;*/

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