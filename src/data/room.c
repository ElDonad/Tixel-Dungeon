#include "room.h"

void checkRoom(Room tocheck){
	return;
}

Coord_u8 getEndStraight(Straight* toGet){
	Coord_u8 toReturn;
	toReturn.x = toGet->x;
	toReturn.y = toGet->y;
	if (toGet->orientation == HORIZONTAL){
		toReturn.x += toGet->length;
		return toReturn;
	}
	else{
		toReturn.y += toGet->length;
		return toReturn;
	}
}

Path* c_Path(){
	Path* toReturn;
	toReturn = malloc(sizeof(Path));
	toReturn->straights = initializeVector();
	return toReturn;
}