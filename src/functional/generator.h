#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <debug.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/depth.h"
#include "../data/depthData.h"

struct Level;
//N'initialise pas un niveau, génère simplement le layout de la salle. La seed et le depth doivent correspondre, ils seront sauvegardés dans le Depth.
bool generateLevel(Depth* toGenerate, int seed, uint8_t depth);

void initializeRandom(int seed);
#endif
