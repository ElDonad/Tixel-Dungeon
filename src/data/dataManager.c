#include "dataManager.h"

PlayerStruct* initializePlayerStruct(int live, PlayerType type, uint8_t playerLevel, int maxLifePlayer)
{
	PlayerStruct* toInitialize = malloc(sizeof(PlayerStruct));
	toInitialize->inventory = initializeInventory(PLAYER_INVENTORY_SIZE);
	toInitialize->currentLevel = playerLevel;
	toInitialize->live = live;
	toInitialize->maxLife = maxLifePlayer;
	toInitialize->type = type;
	return toInitialize;
}

Global* initializeGlobalStruct(PlayerType type, int livePlayer, uint8_t playerLevel, int maxLifePlayer, uint8_t currentLevel, int seed, vector* savedLevels)
{
	PlayerStruct* playerStruct;
	Global* toInitialize;

	toInitialize = malloc(sizeof(Global));
	playerStruct = 	initializePlayerStruct(livePlayer, type, playerLevel, maxLifePlayer);
	toInitialize->player = playerStruct;
	toInitialize->currentDepth = currentLevel;
	toInitialize->seed = seed;

	if (savedLevels != NULL) toInitialize->saveLevels = savedLevels;
	else toInitialize->saveLevels = initializeVector();

}
