#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

struct vectorItem;

struct vectorItem
{
	struct vectorItem* previous;
	struct vectorItem* next;
	void* current;
};

typedef struct vectorItem vectorItem;

typedef struct
{
	vectorItem* first;
	vectorItem* last;
	unsigned int size;
}vector;

vector* initializeVector();
void destroy(vector*);

void* vec_push_back(vector* toBePushed, void* toPush);//done
void vec_pop_back(vector* toBePoped);//done

void* vec_push_front(vector* toBePushed, void* toPush);//done
void vec_pop_front(vector* toBePoped);//done

void* vec_insert(vector* toBeInserted, void* toInsert, unsigned int pos);//done
void vec_delete(vector* toBeDeleted, unsigned int pos);//done
void* vec_getByPos(vector* toBeGot, unsigned int pos);//done

void* vec_getFirst(vector* toBeGot);//done
void* vec_getLast(vector* toBeGot);//done



#endif
