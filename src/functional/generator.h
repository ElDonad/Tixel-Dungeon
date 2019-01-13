#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Level;
bool generateLevel(Depth* toGenerate, int seed, uint8_t depth);

void initializeRandom(int seed);