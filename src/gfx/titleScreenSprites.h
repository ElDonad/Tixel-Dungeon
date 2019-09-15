// convpng v7.1
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __titleScreenSprites__
#define __titleScreenSprites__
#include <stdint.h>

#define titleScreenSprites_transparent_color_index 0

#define arcs2_width 64
#define arcs2_height 64
#define arcs2_size 4098
extern uint8_t arcs2_data[4098];
#define arcs2 ((gfx_sprite_t*)arcs2_data)
#define arcs1_width 32
#define arcs1_height 32
#define arcs1_size 1026
extern uint8_t arcs1_data[1026];
#define arcs1 ((gfx_sprite_t*)arcs1_data)
#define sizeof_titleScreenSprites_pal 24
extern uint16_t titleScreenSprites_pal[12];

#endif
