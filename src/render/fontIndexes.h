#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

uint8_t smallFontTable[] = 
{
	20,//0
	10,//1
	14,//2
	14,//3
	14,//4
	14,//5
	14,//6
	14,//7
	14,//8
	14,//9
	10//:

};

typedef enum 
{
	SmallFontIndex
}FontIndexes;

uint8_t getCharSize(FontIndexes fontIndex, char character);