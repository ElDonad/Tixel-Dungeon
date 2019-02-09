#ifndef STATE_H
#define STATE_H


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
	SPLASH_SCREEN_STATE,
	MAIN_MENU_STATE,
	INGAME_STATE,
	INVENTORY_STATE,
	PAUSE_STATE
}StateType;

struct State;

struct State
{
	StateType type;
	void (*launch)(void* args);//de type StateSpecificLaunchStruct. Cette fonction ne présente d'arguments que pour la forme. Elle ne doit être appelée qu'une fois par le stateManager, pour le state par défaut.
	void (*switchState)(StateType switchFrom, StateType switchTo, void* args);//Fonction membre de stateManager
	void (*switched)(StateType switchFrom, void* args);//Lancement du state par un switch.
	void* data;//une struct spécifique à chaque state, qui doit être convertie en connaissance de cause...
	void (*tick)(uint8_t delta, struct State* args);//delta est une variable qui boucle. Utile pour les animations.
	void (*stop)();
};

typedef struct State State;

//State* initializeState(StateType type, void (*launch)(void* args), void (*switchState)(StateType switchFrom, StateType switchTo, void* args), void (*switched)(StateType switchFrom, void* args), void (*tick)(uint8_t delta, State* args), void* data);

#endif
