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
	vector items;
	vector rooms;
	RandomGenerator randGen;
}SimplifiedDepth;

SimplifiedDepth* initializeSimplifiedDepth();