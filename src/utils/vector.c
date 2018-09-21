#include "vector.h"

vectorItem* initializeVectorItem(vectorItem* previous, vectorItem* next, void* current)
{
	vectorItem* toInitialize = malloc(sizeof(vectorItem));
	toInitialize->previous = previous;
	toInitialize->next = next;
	toInitialize->current = current;
	return toInitialize;
}

void destroy(vector* toDestroy)
{
	vectorItem* itemToFree = toDestroy->first;
	while (itemToFree->next != NULL)
	{
		free(itemToFree->current);
	}
	free(toDestroy);
}

vectorItem* getItemById(vector* toBeGot, unsigned int pos)
{
	if (toBeGot->size - 1 < pos)
	{
		dbg_sprintf(dbgerr,"SIGSEGV ERROR\n");
		exit(-1);
		return NULL;
	}
	else
	{
		int loop;
		vectorItem* toReturn = toBeGot->first;
		for (loop = 0; loop < pos; loop++)
		{
			toReturn = toReturn->next;
		}
		return toReturn;
	}
}

vector* initializeVector()
{
	vector* toInitialize = malloc(sizeof(vector));
	toInitialize->size = 0;
	toInitialize->first = NULL;
	toInitialize->last = NULL;
	return toInitialize;
}

void* vec_push_back(vector* toBePushed, void* toPush)
{
	if (toBePushed->last == NULL && toBePushed->first == NULL)//si le vector est vide
	{
		vectorItem* toAdd = initializeVectorItem(NULL,NULL,toPush);
		dbg_sprintf(dbgout,"empty vector\n");
		toBePushed->first = toAdd;
		toBePushed->last = toAdd;
		toBePushed->size += 1;
		return toPush;
	}
	else
	{
		vectorItem* toAdd = initializeVectorItem(toBePushed->last, NULL, toPush);
		toBePushed->last->next = toAdd;
		toAdd->previous = toBePushed->last;
		toBePushed->last = toAdd;
		toBePushed->size += 1;
		return toPush;
	}
}

void* vec_getLast(vector* toBeGot)
{
	if (toBeGot->last != NULL)
	{return toBeGot->last->current;}
	else
		{return NULL;}
}

void* vec_getFirst(vector* toBeGot)
{
	if (toBeGot->first != NULL)
	{return toBeGot->first->current;}
	else
		{return NULL;}
}

void vec_pop_back(vector* toBePoped)
{
	vectorItem* toFree = toBePoped->last;
	if (toBePoped->last != NULL)//si pas vide
	{
		if (toFree == toBePoped->first)// si il n'y a qu'un item
		{
			toBePoped->first = NULL;
			toBePoped->last = NULL;
		}
		else//si deux items ou plus...
		{
			toBePoped->last = toFree->previous;
		}
		toBePoped->size -= 1;
		free(toFree);
	}
}

void* vec_getByPos(vector* toBeGot, unsigned int pos)
{
	return getItemById(toBeGot, pos)->current;
}

void* vec_push_front(vector* toBePushed, void* toPush)
{
	if (toBePushed->first == NULL)//si vector vide
	{
		vectorItem* toAdd = initializeVectorItem(NULL, NULL, toPush);
		toBePushed->first = toAdd;
		toBePushed->last = toAdd;
		toBePushed->size += 1;
		return toPush;
	}
	else//si au moins un item (donc déjà dans vector->first et vector->last)
	{
		vectorItem* toAdd = initializeVectorItem(NULL,toBePushed->first, toPush);
		toBePushed->first->previous = toAdd;
		toAdd->next = toBePushed->first;
		toBePushed->first = toAdd;
		toBePushed->size += 1;
		return toPush;
	}
}

void vec_pop_front(vector* toBePoped)
{
	if (toBePoped->first != NULL)
	{
		vectorItem* toFree = toBePoped->first;
		if (toBePoped->last = toFree)//si seulement 1 item : vider le tableau
		{
			toBePoped->last = NULL;
			toBePoped->first = NULL;
			free(toFree);
		}
		else
		{
			toBePoped->first = toFree->next;
			free(toFree);
		}
		toBePoped->size -= 1;
	}
}

void* vec_insert(vector* toBeInserted, void* toInsert, unsigned int pos)
{
	vectorItem* toInsertBefore;
	vectorItem* toBeInsertedBefore = getItemById(toBeInserted, pos);
	toInsertBefore = initializeVectorItem(NULL,NULL,toInsert);
	if (toBeInsertedBefore != NULL)//si pas d'erreur (cas du tableau vide géré après)
	{
		toInsertBefore->previous = toBeInsertedBefore->previous;
		toInsertBefore->next = toBeInsertedBefore;
		if (toInsertBefore->previous != NULL)
		{
			toInsertBefore->previous->next = toInsertBefore;
		}
		if (toInsertBefore->next != NULL)
		{
			toInsertBefore->next->previous = toInsertBefore;
		}

		if (toBeInserted->size == pos)//pas de -1 car on a pas encore incrémenté le compteur pour cet item
		{
			dbg_sprintf(dbgout, "taille correspondante\n");
			toBeInserted->last = toInsertBefore;
		}
		if (pos == 0)
		{
			toBeInserted->first = toInsertBefore;
		}
		toBeInserted->size += 1;
		return toInsert;
	}
	dbg_sprintf(dbgerr, "failed to insert object : bad initialization\n");
	return NULL;

}

void vec_delete(vector* toBeDeleted, unsigned int pos)
{
	vectorItem* toDelete = getItemById(toBeDeleted,pos);
	if (toDelete != NULL)
	{

		if (toDelete->previous != NULL && toDelete->next != NULL)//ssi ni le premier ni le dernier
		{
			toDelete->previous->next = toDelete->next;
			toDelete->next->previous = toDelete->previous;
		}
		if (toDelete->next == NULL)//si le dernier
		{
			toDelete->previous->next = NULL;
			toBeDeleted->last = toDelete->previous;
		}
		if (toDelete->previous == NULL)//si le premier
		{
			toDelete->next->previous = NULL;
			toBeDeleted->first = toDelete->next;
		}
		free(toDelete);
		toBeDeleted->size -= 1;
	}
	else
	{
		dbg_sprintf(dbgerr, "failed to delete object : bad initialization\n");
	}
}
