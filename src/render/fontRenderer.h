#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

#include <graphx.h>

#include "fontIndexes.h"
#include "../gfx/TDFONTS.h"
#include "../gfx/fonts.h"

typedef enum
{
    CenterAlignment,
    LeftAlignment
}Justification;

void drawString(char* string, FontIndexes fontIndex, uint24_t posX, uint8_t posY, uint24_t marginX, uint8_t coloumnCount, Justification justification);
