#include "random.h"

unsigned int random(RandomGenerator* gen, unsigned int min, unsigned int max)
{
	srand(gen->seed);
	return rand() % (gen->max - gen->min) + gen->min;
}