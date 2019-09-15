#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include <stdbool.h>
#include <stdint.h>

#define RED 4
#define GREEN 2

#define HEIGHT 50
uint16_t seed = 560;

void setColorAndBackground(int fore, int back);

uint16_t getRandomNumber(uint16_t min, uint16_t max);
uint16_t getRandomFromSeed(uint16_t* seed, uint16_t min, uint16_t max);


int main(){
    setColorAndBackground(0x0F, 0);
    
    //initialisation de la génération :
    printf("%zi", sizeof(uint16_t));

    while (true){
        
        system("pause");
    }


    return 0;
}

void setColorAndBackground(int fore, int back){
    WORD wColor = ((back & 0x0F) << 4) + (fore & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

uint16_t getRandomNumber(uint16_t min,  uint16_t max){
    seed = 36969*(seed&65535)+(seed>>16);
    return seed % (max-min) + min;
}

uint16_t getRandomFromSeed(uint16_t* altSeed, uint16_t min, uint16_t max){
    *altSeed = 36969*(*altSeed&65535)+(*altSeed>>16);
    return *altSeed % (max-min) + min;
}