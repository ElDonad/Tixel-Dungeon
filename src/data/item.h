#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    WEAPON,//distance (bow and cie)
    SWORD,//close combat
    ARMOR,
    WAND,
    CONSOMMABLE



}ItemType;

typedef enum
{
    DAGGER,
    RANGER_BOW,
    WAND_OF_DEFLAGRATION
}ItemId;

typedef struct
{
    ItemId id;
    bool isCursed;
    uint8_t level;
    ItemType type;
    uint8_t maximumStackValue;
}Item;

#endif
