#include "random.h"

unsigned int randomInt(RandomGenerator* gen, unsigned int min, unsigned int max)
{
	srand(gen->seed);
	return rand() % (max - min) + min;
}

unsigned int randomRange(RandomGenerator* gen, Range range){
	return randomInt(gen, range.min, range.max);
}