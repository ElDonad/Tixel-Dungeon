#include "generator.h"
#include "../data/depth.h"

bool generateLevel(Depth* toGenerate, int seed, uint8_t depth)
{
	unsigned int loop;
	RandomGenerator mainGenerator;

	toGenerate->id = depth;
	toGenerate->tiles = malloc(sizeof(uint8_t) * DEPTH_X * DEPTH_Y);
	for (loop = 0; loop != DEPTH_Y * DEPTH_X; ++loop)
	{
		*(toGenerate + loop) = 0;
	}

	//génération des salles
	{
		uint8_t maxRooms;
		bool chestRoomDone;
		bool itemRoomDone;
		unsigned int loop;
		unsigned int deltaFromCenter;//permet de placer les pièces dans un espace concentrique

		maxRooms = random(mainGenerator, 4, 6);
		chestRoomDone = false;
		itemRoomDone = false;
		deltaFromCenter = 5;

		for (loop = 0; loop != maxRooms; ++loop)
		{
			uint8_t placementIteration;//si à 255, impossible.
			bool placed = false;
			placementIteration = 0
			while (placed == false || placementIteration == 255)//tant que la pièce n'a pas trouvé un endroit où se placer...
			{
				Rect_uint8 newRoom;
				
				newRoom.dimX = random(mainGenerator, 2, 5);
				newRoom.dimY = random(mainGenerator, 2, 5);

				newRoom.posX = random(mainGenerator,min(DEPTH_X / 2 - deltaFromCenter, 0), max(DEPTH_X / 2 + deltaFromCenter), DEPTH_X);
				newRoom.posY = random(mainGenerator,min(DEPTH_Y / 2 - deltaFromCenter, 0), max(DEPTH_Y / 2 + deltaFromCenter), DEPTH_Y);


				if (canPlaceInRoom(toGenerate, newRoom))
				{
					Room* roomToAdd;
					roomToAdd = malloc(sizeof(Room));
					roomToAdd->room = newRoom;
					
					vec_push_back(toGenerate->depthData->rooms, )
				}

				placementIteration++;
			}
			if (placementIteration == 255) return false;

		}
	}
}

void initializeRandom(int seed)
{
	srandom(seed);
}