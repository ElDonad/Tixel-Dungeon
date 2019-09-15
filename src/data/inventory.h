#ifndef INVENTORY_H
#define INVENTORY_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/vector.h"
#include "item.h"

typedef struct
{
    Item item;
    uint8_t count;


}InventoryItem;

typedef struct
{
    vector* items;//type : InventoryItem;
    uint8_t maxSize;
    uint8_t* shortcutItems;//les items placés dans les quick slots. 
}Inventory;

uint8_t itemCount(Inventory*, ItemId itemId);//return 0 if no item, item count otherwise
bool deleteItem(Inventory*, ItemId itemToDelete, uint8_t count);//Delete <count> items of id <itemToDelete> in the inventory. If count = 0, delete the entire itemStack.
bool addItem(Inventory*, Item toAdd, uint8_t count);
Item getItemByInvId(Inventory*, uint8_t id);
Item getItem(Inventory*, ItemType type);//retourne la référence exacte de l'item à partir de son type.

Inventory* initializeInventory(uint8_t maxSize);
void destroyInventory(Inventory*);

#endif
