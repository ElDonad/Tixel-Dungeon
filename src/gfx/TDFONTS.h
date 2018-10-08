// Converted using ConvPNG
// This file contains all the graphics sources for easier inclusion in a project
#ifndef __TDFONTS__
#define __TDFONTS__
#include <stdint.h>

#include <stdbool.h>

#define TDFONTS_num 2

extern uint8_t *TDFONTS[2];
#define font ((gfx_sprite_t*)TDFONTS[0])
#define sizeof_fonts_pal 8
#define fonts_pal ((uint16_t*)TDFONTS[2])
bool TDFONTS_init(void);

#endif
