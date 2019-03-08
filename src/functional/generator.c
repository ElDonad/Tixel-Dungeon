#include "generator.h"
#include "../data/room.h"

#include "../utils/vector.h"
#include "../utils/rect.h"


uint8_t u8max(uint8_t a, uint8_t b){
	if (a >= b){
		return a;
	}
	return b;
}
uint8_t u8min(uint8_t a, uint8_t b){
	if (a <= b){
		return a;
	}
	return b;
}

void applyDepth(Depth* toApply);//complète le tableau de cases du niveau.

Straight* straightInDirection(Direction direction, Coord_u8 start, uint8_t length, Straight* straight){
	Straight* toReturn;
	if (start.x == 0 && start.y == 0){
		start.x = straight->x;
		start.y = straight->y;
	}
	if (straight == NULL){
		toReturn = malloc(sizeof(Straight));
		toReturn->x = start.x;
		toReturn->y = start.y;
	}
	else{
		toReturn = straight;
	}

	if (direction == LEFT){
		toReturn->orientation = HORIZONTAL;
		toReturn->length = -(int)(length);
		return toReturn;
	}
	else if (direction == RIGHT){
		toReturn->orientation = HORIZONTAL;
		toReturn->length = (int)(length);
		return toReturn;
	}
	else if (direction == UP){
		toReturn->orientation = VERTICAL;
		toReturn->length = -(int)(length);
		return toReturn;
	}
	else if (direction == DOWN){
		toReturn->orientation = VERTICAL;
		toReturn->length = (int)(length);
		return toReturn;
	}
}

Path* generateCorridor(Room* start, Room* end, RandomGenerator* generator){
	Coord_u8 startPoint;
	Coord_u8 endPoint;
	Direction initialDir;
	Orientation initialOrientation;

	Path* toReturn;
	toReturn = initializePath();

	if (fabs(start->size.x - end->size.y) > abs(start->size.y - end->size.y)){
		initialOrientation = HORIZONTAL;
		if (start->size.x > end->size.x){
			initialDir = LEFT;
			startPoint.x = start->size.x;
			startPoint.y = randomInt(generator, start->size.y, start->size.y + start->size.h);

			endPoint.x = end->size.x + end->size.w;
			endPoint.y = randomInt(generator, end->size.y, end->size.y + end->size.h);

		}
		else{
			initialDir = RIGHT;
			startPoint.x = start->size.x + start->size.w;
			startPoint.y = randomInt(generator, start->size.y, start->size.y + start->size.h);

			endPoint.x = end->size.x;
			endPoint.y = randomInt(generator, end->size.y, end->size.y + end->size.h);
		}
	}
	else{
		initialOrientation = VERTICAL;
		if (start->size.y > end->size.y){
			initialDir = UP;
			startPoint.y = start->size.y;
			startPoint.x = randomInt(generator, start->size.x, start->size.x + start->size.w);

			endPoint.y = end->size.y + end->size.h;
			endPoint.x = randomInt(generator, end->size.x, end->size.x + end->size.w);
		}
		else{
			initialDir = DOWN;
			startPoint.y = start->size.y + start->size.h;
			startPoint.x = randomInt(generator, start->size.x, start->size.x + start->size.w);

			endPoint.y = end->size.y;
			endPoint.x = randomInt(generator, end->size.x, end->size.x + end->size.w);
		}
	}
	dbg_sprintf(dbgout, "Corridor start point: %i, %i",startPoint.x, startPoint.y);
	dbg_sprintf(dbgout, "Corridor end point: %i %i",endPoint.x, endPoint.y);

	{//Début de la génération des chemins :
		Coord_u8 currentPos;
		Direction headingDir;
		uint8_t deltaDir;
		Direction priorityOrientation;

		currentPos = startPoint;
		headingDir = initialDir;

		if (initialDir == LEFT || initialDir == RIGHT){
			deltaDir = fabs(startPoint.x - endPoint.x);
			priorityOrientation = VERTICAL;
		}
		else if (initialDir == UP || initialDir == DOWN){
			deltaDir = fabs(startPoint.y - endPoint.y);
			priorityOrientation = HORIZONTAL;
		}
		vec_push_back(toReturn->straights,(void*) straightInDirection(initialDir,startPoint, randomInt(generator, 1, deltaDir / 3), NULL));
		currentPos = getEndStraight((Straight*)vec_getByPos(toReturn->straights, toReturn->straights->size - 1));

		while (currentPos.x != endPoint.x && currentPos.y != endPoint.y){
			uint8_t xDelta;
			uint8_t yDelta;
			int xOffset;
			int yOffset;

			xDelta = fabs(endPoint.x - currentPos.x);
			yDelta = fabs(endPoint.y - currentPos.y);
			xOffset = endPoint.x - currentPos.x;
			yOffset = endPoint.y - currentPos.y;

			if (yOffset != 0 && (priorityOrientation == VERTICAL || xOffset == 0)){
				Direction newDirection;
				if (yOffset < 0) newDirection = UP;
				else if (yOffset > 0) newDirection = DOWN;
				vec_push_back(toReturn->straights, (void*)straightInDirection(newDirection, currentPos, yDelta, NULL));
			}
			else if (xOffset != 0 && (priorityOrientation == HORIZONTAL || yOffset == 0)){
				Direction newDirection;
				if (xOffset < 0) newDirection = LEFT;
				else if (xOffset > 0) newDirection = RIGHT;
				vec_push_back(toReturn->straights, (void*)straightInDirection(newDirection, currentPos, xDelta, NULL));

			}
			currentPos = getEndStraight((Straight*)vec_getByPos(toReturn->straights, toReturn->straights->size - 1));
		}


	}

	return toReturn;

}

bool generateLevel(Depth* toGenerate, int seed, uint8_t depth)
{
	//initialization
	Range roomRange;
	uint8_t roomNumber;
	vector* rooms;
	vector* corridors;
	uint8_t* tilesArray;
	uint8_t deltaFromCenter;
	RandomGenerator mainGenerator;

	int loop;


	dbg_sprintf(dbgout,"Debut de la generation... seed : %i\n", seed);

	mainGenerator.seed = seed;

	roomRange = getDepthRoomCountRange(depth);
	rooms = toGenerate->data->rooms;
	corridors = toGenerate->data->corridors;
	tilesArray = toGenerate->tiles;
	deltaFromCenter = 3;
	roomNumber = randomRange(&mainGenerator, roomRange);

	for(loop=0; loop != DEPTH_X * DEPTH_Y; ++loop){
		tilesArray[loop] = 0;
	}

	for(loop = 0; loop != roomNumber; ++loop){
		bool placed;
		int placeIt;

		dbg_sprintf(dbgout, "Nombre de pièces : %i", loop);
		placed = false;
		for (placeIt = 0; placeIt != 1500; ++placeIt){
			Room *newRoom;
			bool collide;
			newRoom = malloc(sizeof(Room));
			newRoom->size.h = randomInt(&mainGenerator, 3,6);
			newRoom->size.w = randomInt(&mainGenerator, 3,6);
			newRoom->size.x = randomInt(&mainGenerator, u8max(0, DEPTH_X / 2 - deltaFromCenter), u8min(DEPTH_X - newRoom->size.w - 2, DEPTH_X / 2 + deltaFromCenter));
			newRoom->size.y = randomInt(&mainGenerator, u8max(0, DEPTH_Y / 2 - deltaFromCenter), u8min(DEPTH_X - newRoom->size.h - 2, DEPTH_Y / 2 + deltaFromCenter));

			dbg_sprintf(dbgout, "new room to place : %i %i %i %i", newRoom->size.x, newRoom->size.y, newRoom->size.w, newRoom->size.h);
			collide = roomCollide(newRoom, toGenerate);
			if (collide == false){
				dbg_sprintf(dbgout, "room placed\n");
				placed = true;
				vec_push_back(rooms, newRoom);
				if (rooms->size > 1){
					Path* newRegularCorridor;
					newRegularCorridor = generateCorridor((Room*)vec_getByPos(rooms, rooms->size - 2), (Room*) vec_getByPos(rooms, rooms->size - 1), &mainGenerator);
					vec_push_back(corridors, newRegularCorridor);
				}
				break;
			}

		}
		if (placed == false){
			dbg_sprintf(dbgerr, "Limite d'essais dépassé lors de la création d'une pièce\n");
			return false;
		}

	}
	toGenerate->data->depth = depth;
	applyDepth(toGenerate);
	return true;



}

void applyDepth(Depth* depth){

}

void initializeRandom(int seed)
{
	srandom(seed);
}
