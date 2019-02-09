#include "fontRenderer.h"

void drawString(char* string, FontIndexes fontIndex, uint24_t posX, uint8_t posY, uint24_t marginX,uint8_t coloumnCount, Justification justification)
{
    uint8_t currentRow;
    unsigned int currentColoumn;
    uint8_t characterHeight;

    unsigned int loop;

    TDFONTS_init();
    currentRow = 0;
    currentColoumn = 0;
    characterHeight = getCharHeight(fontIndex);

    if (justification == LeftAlignment)//Faster
    {
        for (loop = 0; loop != strlen(string); ++loop)
        {
            Character* currentChar;

            currentChar = getChar(fontIndex, *(string + loop));
            //dbg_sprintf(dbgout,"%i",currentChar->xLengh);
            if (currentColoumn + currentChar->xLengh > marginX)//si fin de ligne
            {
                currentRow++;
                currentColoumn = 0;
            }
            if (currentRow + 1 > coloumnCount)
            {
                return;
            }
            //dbg_sprintf(dbgout, "caractere affiché : %c\n", currentChar->character);
            //dbg_sprintf(dbgout,"colonne compte : %i\n",currentColoumn);

            gfx_SetClipRegion(posX + currentColoumn, posY + currentRow * characterHeight, posX + currentColoumn + currentChar->xLengh,  posY + (currentRow + 1) * characterHeight);
            gfx_TransparentSprite(font, posX + currentColoumn - currentChar->xOffset, posY + (currentRow - currentChar->line) * characterHeight);
            currentColoumn += currentChar->xLengh;
        }
    }
    gfx_SetClipRegion(0,0,320,240);
}
