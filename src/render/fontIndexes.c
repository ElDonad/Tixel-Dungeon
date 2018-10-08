#include "fontIndexes.h"
Character smallFontTableau[] =
{
	{'0',0,0,0,14},
	{'1',1,14,0,10},
	{'2',2,24,0,14},
	{'3',3,38,0,14},
	{'4',4,52,0,14},
	{'5',5,68,0,14},
	{'6',6,82,0,14},
	{'7',7,96,0,14},
	{'8',8,110,0,14},
	{'9',9,124,0,14},
	{':',10,138,0,14}

};
//retourne la taille horizontale du character
uint8_t getCharSize(FontIndexes index, char character)
{
	Character* selectedIndex;
	unsigned int loop;
	int characterSelected;
	if (index == SmallFontIndex) selectedIndex = &smallFontTableau;
	else return 0;
	for(loop = 0; loop != SMALL_FONT_INDEX_SIZE; ++loop)
	{
		characterSelected = loop;
		if ((*(selectedIndex + characterSelected)).character == character)
			return (*(selectedIndex + characterSelected)).xLengh;
	}
}

Character* getChar(FontIndexes index, char character)
{
	unsigned int loop;
	unsigned int maxLoop;
	Character* charactersTable;

	if (index == SmallFontIndex)
	{
		maxLoop = SMALL_FONT_INDEX_SIZE;
		charactersTable = &smallFontTableau;
	}

	for (loop = 0; loop != maxLoop; ++loop)
	{
		// dbg_sprintf(dbgout, "%s\n",&character);
		// dbg_sprintf(dbgout, "Témoin : %s\n", &character);
		// dbg_sprintf(dbgout, "Original : %s\n", &(smallFontTableau[loop].character));
		//dbg_sprintf(dbgout, "à analyser : %p \n",((charactersTable + loop * sizeof(Character))).character));
		if ((*(charactersTable + loop)).character == character)
		{
			return (charactersTable + loop);
		}
	}


}

uint8_t getCharHeight(FontIndexes fontIndex)
{
	// if (fontIndex == SmallFontIndex) return SMALL_FONT_CHARACTER_HEIGHT;
	//
	// else return 0;
	return 20;
}
