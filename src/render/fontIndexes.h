#ifndef FONT_INDEX_H
#define FONT_INDEX_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <debug.h>


/* Ce fichier regroupte toutes les fonctions utiles pour récupérer les informations à propos d'un character à dessiner.


*/

typedef struct
{
	char character;
	uint8_t index;//index dans la table des chars
	uint8_t xOffset;//offset depuis la gauche du fichier.
	uint8_t line;//Ligne dans le fichier. 0 par défaut
	uint8_t xLengh;//longueur du caractère.

}Character;

#define SMALL_FONT_INDEX_SIZE 11
#define SMALL_FONT_CHARACTER_HEIGHT 20

typedef enum
{
	SmallFontIndex
}FontIndexes;

Character* getChar(FontIndexes fontIndex, char character);
uint8_t getCharHeight(FontIndexes fontIndex);

#endif
