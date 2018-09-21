#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/vector.h"
#include "inventory.h"

#define PLAYER_INVENTORY_SIZE 24

typedef enum 
{
	Rogue,
	Mage
}PlayerType;

typedef struct
{
    int currentLevel;
    Inventory* inventory;
    int live;
    PlayerType type;

}PlayerStruct;

typedef struct
{
    int currentDepth;
    PlayerStruct* player;
    //Level* currentLevel;
    vector* saveLevels;//contains : SaveLevelStruct
    int seed;//utilisée pour toutes les opérations de randomisation.


}Global;

PlayerStruct* initializePlayerStruct(int live, PlayerType type);
Global* initializeGlobalStruct(PlayerType type,
							 int livePlayer,
							  uint8_t playerLevel,
							   int maxLifePlayer,
							   uint8_t currentLevel,
							    int seed,
							     vector* savedLevels);//nullable
