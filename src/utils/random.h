#ifndef RANDOM_H
#define RANDOM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <stdio.h>
#include <stdlib.h>
#include <debug.h>
typedef struct
{
	unsigned int seed;
}RandomGenerator;

typedef struct{
	int min;
	int max;
}Range;

unsigned int randomInt(RandomGenerator*, unsigned int min, unsigned int max);
unsigned int randomRange(RandomGenerator*, Range range);

#endif//RANDOM_H