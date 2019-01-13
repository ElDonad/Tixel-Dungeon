#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

typedef struct
{
	unsigned int seed;
}RandomGenerator;

unsigned int random(RandomGenerator*, unsigned int min, unsigned int max);

