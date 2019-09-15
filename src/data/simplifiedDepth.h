#ifndef SIMPLIFIED_DEPTH_H
#define SIMPLIFIED_DEPTH_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/vector.h"
#include "../utils/random.h"
#include "item.h"

typedef struct
{
	vector *items;
	vector *rooms;
	vector *corridors;
	RandomGenerator* randGen;
	uint8_t depth;
}SimplifiedDepth;//Cette struct stocke toutes les données relative au niveau, sans stocker les tiles. Ce sont les données de sauvegarde.

SimplifiedDepth* initializeSimplifiedDepth();

#endif