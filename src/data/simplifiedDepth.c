#include "simplifiedDepth.h"

SimplifiedDepth* initializeSimplifiedDepth()
{
	SimplifiedDepth* toInitialize = malloc(sizeof(SimplifiedDepth));
	toInitialize->rooms = initializeVector();
	toInitialize->items = initializeVector();
	toInitialize->corridors = initializeVector();
	return toInitialize;
}