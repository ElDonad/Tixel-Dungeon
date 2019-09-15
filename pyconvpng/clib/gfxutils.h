/* L'objectif de cette bibliotèque est de charger en mémoire les sprites et palettes converties à partir 
   de l'utilitaire pyconvpng, particulièrement la fusion des subpalettes et la gestion des tilemaps.

*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <debug.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>


bool constructPalette(Palette* toConstruct, Subpalette** subPalettes, uint8_t subPalettesCount);
gfx_sprite_t* getSprite(Group* group, unsigned int sprite);