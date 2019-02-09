#include "depth.h"

Depth* initializeDepth()
{
	Depth* toInitialize = malloc(sizeof(Depth));
	toInitialize->data = initializeSimplifiedDepth();
	return toInitialize;
}

bool roomCollide(Room* rm1, Depth* depth){
	int loop;
	Rect_uint8 *rect1 = &rm1->size;
	for (loop = 0; loop != depth->data->rooms->size; loop++){
		Rect_uint8* rect2 = (Rect_uint8*)vec_getByPos(depth->data->rooms, loop);
		if (rect1->x + rect1->w + 1 >= rect2->x - 1 &&
			rect1->x - 1 <= rect2->x + rect2->w + 1 &&
			rect1->y + rect1->h + 1 >= rect2->y - 1 &&
			rect1->y - 1 <= rect2->y + rect2->h + 1){
			return true;
		}
	}
	return false;
}

void test(Depth* test){
	return;
}