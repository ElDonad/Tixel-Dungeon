#include "gfxutils.h"

bool constructPalette(Palette* toConstruct, Subpalette** subPalettes, uint8_t subPalettesCount){
	uint8_t loop;
	uint8_t colorsCount;
	uint8_t *orderUsed;

	colorsCount = 0;
	orderUsed = malloc(sizeof(uint8_t) * subPalettesCount);

	for (loop = 0; loop != subPalettesCount; loop++){
		uint8_t loopOrder;

		for (loopOrder = 0; loopOrder != loop + 1; ++loopOrder){
			if (subPalettes[loop]->order == orderUsed[loopOrder]){
				return false; //ordre déjà utilisé
			}
			colorsCount += subPalettes[loop]->size;
		}
		toConstruct->palette = malloc(sizeof(uint16_t) * colorsCount);
		{
			uint8_t subpalloop;
			for (subpalloop = 0; subpalloop != subPalettesCount; ++subpalloop){
				uint8_t colorloop;
				for (colorloop = 0; colorloop != subPalettes[subpalloop]->size; ++colorloop){
					toConstruct->palette[subPalettes[subpalloop]->offset + colorloop] = subPalettes[subpalloop]->subpalette[colorloop];
				}

			}
		}


	}

	free(orderUsed);
	return true;
}

gfx_sprite_t* getSprite(unsigned int sprite){
	
}