// Converted using ConvPNG
#include <stdint.h>
#include "TDFONTS.h"

#include <fileioc.h>
uint8_t *TDFONTS[2] = {
 (uint8_t*)0,
 (uint8_t*)2922,
};

bool TDFONTS_init(void) {
    unsigned int data, i;
    ti_var_t appvar;

    ti_CloseAll();

    appvar = ti_Open("TDFONTS", "r");
    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)TDFONTS[0];
    for (i = 0; i < TDFONTS_num; i++) {
        TDFONTS[i] += data;
    }

    ti_CloseAll();

    return (bool)appvar;
}
