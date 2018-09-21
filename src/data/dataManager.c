#include "dataManager.h"

PlayerStruct* initializePlayerStruct(int live, PlayerType type)
{
	PlayerStruct* toInitialize = malloc(sizeof(PlayerStruct));
	toInitialize->inventory = initializeInventory(PLAYER_INVENTORY_SIZE);
	toInitialize->currentLevel = 1;
	toInitialize->live = live;
	toInitialize->type = type;
	return toInitialize;
}

Global* initializeGlobalStruct(PlayerType type, int livePlayer, uint8_t playerLevel, int maxLifePlayer, uint8_t currentLevel, int seed, vector* savedLevels)
{
	Global* toInitialize = malloc(sizeof(Global));
}
