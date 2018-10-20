#ifndef SWITCH_STATES_STRUCTS_H
#define SWITCH_STATES_STRUCTS_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <debug.h>

/* Ce fichier doit contenir l'ensemble des structs nécessaires pour faire le passage entre un état à un autre. Il doit donc être inclus pr tous les états.



*/

typedef struct
{
	bool isNewRun;

}MainMenuToInGameStruct;

#endif