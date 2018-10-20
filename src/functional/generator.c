#include "generator.h"
#include "../data/depth.h"

void generateLevel(Depth* toGenerate, int seed, uint8_t depth)
{
	Depth* toGenerate;
	unsigned int loop;

	srandom(seed);
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

		maxRooms = randInt(4,6);
		chestRoomDone = false;
		itemRoomDone = false;

		for (loop = 0; loop != maxRooms; ++loop)
		{
			bool placed = false;
			while (placed == false)//tant que la pièce n'a pas trouvé un endroit où se placer...
			{
				uint8_t roomDimX;
				uint8_t roomDimY;
				uint8_t roomPosX; 
				

				vec_push_back(toGenerate->simplifiedLevel->rooms, initializeRoom(roomDimX, roomDimY));
			}

		}
	}
}