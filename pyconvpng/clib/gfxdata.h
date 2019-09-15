#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct{
	uint16_t* subpalette;
	uint8_t size;
	uint8_t order;//définit l'ordre dans la palette finale. Insérer plusieurs sous-palettes avec le même ordre provoquera une erreur. 
	uint8_t offset;//où commence la subpalette dans le tableau
}Subpalette;

typedef struct{
	uint16_t* palette;
	uint24_t size;

	Subpalette** subpalettes;
	Subpalette** currentlyUsedSubPalettes;
	uint8_t subpaletteCount;

}Palette;

typedef struct{
	Subpalette* allowedSubPalette;//la liste des palettes pour lesquelles ce sprite est valide
	uint8_t* data;
	uint8_t height;
	uint8_t width;
}Sprite;

typedef struct{
	Palette* palettes;
	Sprite* sprites;
}Group;


