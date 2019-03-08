#include "random.h"


unsigned int randomInt(RandomGenerator* gen, unsigned int min, unsigned int max)
{
	//srand(gen->seed);
	unsigned int seed = gen->seed;
	seed = 36969*(seed&65535)+(seed>>16);
	gen->seed = seed;
	return seed % (max - min) + min;
}

unsigned int randomRange(RandomGenerator* gen, Range range){
	return randomInt(gen, range.min, range.max);
}
