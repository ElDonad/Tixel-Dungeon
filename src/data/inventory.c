#include "inventory.h"

Inventory* initializeInventory(uint8_t maxSize)
{
    Inventory* toInitialize = malloc(sizeof(Inventory));
    toInitialize->maxSize = maxSize;
    toInitialize->items = initializeVector();
    return toInitialize;
}

void destroyInventory(Inventory* toDestroy)
{
    freeVector(toDestroy->items);
    free(toDestroy);
}

InventoryItem* getInvItem(Inventory* inv, ItemId item)//Privée, utilisé par les fonctions de ce fichier seulement
{
    int loop = 0;
    for (; loop != inv->items->size; ++loop)
    {
        if (item == ((InventoryItem*)vec_getByPos(inv->items, loop))->item.id)
        {
            return (InventoryItem*)vec_getByPos(inv->items, loop);
        }
    }
    return NULL;
}

void mergeStack(InventoryItem* item, uint8_t count)
{
    if (item->count + count >= item->item.maximumStackValue)
    {
        item->count = item->item.maximumStackValue;
    }
    else
    {
        item->count += count;
    }
}

Item getItem(Inventory* inv, ItemId id)
{
    Item toReturn;
    InventoryItem* item = getInvItem(inv, id);
    if (item != NULL) return item->item;
    else return toReturn;



}

uint8_t itemCount(Inventory* inv, ItemId itemId)
{
    return getInvItem(inv, itemId)->count;
}

Item getItemByInvId(Inventory* inv, uint8_t id)
{
    return ((InventoryItem*)vec_getByPos(inv->items, id))->item;
}

//En cas de nécessité de connaître plus précisément les raisons de l'échec de l'ajout de l'item, des appels à d'autres fonctions utilitaires devront être effectuées, ou des analyses spécifiques faites. Ceci n'entre pas dans le champ de responsabilité de cette fonction.
bool addItem(Inventory* inv, Item toAdd, uint8_t count)
{
    //1. Vérifier si ce type d'item est déjà présent :
    uint8_t loop;
    InventoryItem* newToAdd;
    InventoryItem* toAddIn = getInvItem(inv, toAdd.id);
    if (toAddIn != NULL)
    {
        mergeStack(toAddIn, count);
        return true;
    }

    //2. vérifier si il reste de la place disponible dans le tableau :
    if (inv->items->size >= inv->maxSize) return false;

    //3. Sinon, ajouter un InventoryItem.
    newToAdd = malloc(sizeof(InventoryItem));
    newToAdd->item = toAdd;
    newToAdd->count = (count <= toAdd.maximumStackValue) ? count : toAdd.maximumStackValue;
    return true;
    

}
