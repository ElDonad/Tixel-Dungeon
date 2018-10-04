#include "fontIndexes.h"

//retourne la taille horizontale du character
uint8_t getCharSize(FontIndexes index, char character)
{
	Character* selectedIndex;
	unsigned int loop;
	int characterSelected;
	if (index == SmallFontIndex) selectedIndex = &smallFontTable;
	else return 0;
	for(loop = 0; loop != SMALL_FONT_INDEX_SIZE; ++loop)
	{
		characterSelected = loop * sizeof(Character);
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
		charactersTable = &smallFontTable;
	}	
	//rajouter ici éventuellement les autres tables

	for (loop = 0; loop != maxLoop; ++loop)
	{
		if ((*(charactersTable + loop * sizeof(Character))).character == character) return (charactersTable + loop * sizeof(Character));
	}


}
