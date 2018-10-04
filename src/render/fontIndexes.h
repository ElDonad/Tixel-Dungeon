#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/* Ce fichier regroupte toutes les fonctions utiles pour récupérer les informations à propos d'un character à dessiner.


*/
typedef struct
{
	char character;
	uint8_t index;
	uint8_t xOffset;
	uint8_t line;
	uint8_t xLengh;

}Character;

Character smallFontTable[] =
{
	{'0',0,0,0,20},
	{'1',1,20,0,10},
	{'2',2,30,0,14},
	{'3',3,44,0,14},
	{'4',4,58,0,14},
	{'5',5,72,0,14},
	{'6',6,86,0,14},
	{'7',7,100,0,14},
	{'8',8,114,0,14},
	{'9',9,128,0,14},

	{':',10,142,0,14}



};

#define SMALL_FONT_INDEX_SIZE 11

typedef enum
{
	SmallFontIndex
}FontIndexes;

Character* getChar(FontIndexes fontIndex, char character);
