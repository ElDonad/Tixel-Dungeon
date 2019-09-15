#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H


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
#include "depth.h"

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
    int life;
    int maxLife;
    PlayerType type;
	uint8_t posX, posY;

}PlayerStruct;

typedef struct
{
	uint8_t currentDepth;
	PlayerStruct* player;
	uint8_t* loadedDepthTiles;
	Depth* loadedDepth;
    vector* saveLevels;//contains : SaveLevelStruct
    int seed;//utilisée pour toutes les opérations de randomisation.


}Global;

Global* initializeGlobalStruct(PlayerType type,
							   int livePlayer,
							   uint8_t playerLevel,
							   int maxLifePlayer,
							   uint8_t currentLevel,
							   int seed,
							   vector* savedLevels);//nullable

#endif
