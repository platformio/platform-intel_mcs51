#include "delay.h"

#define MAIN_Fosc 22118400L //Define the clock
//#define MAIN_Fosc 12000000L   //Define the clock
//#define MAIN_Fosc 11059200L   //Define the clock
//#define MAIN_Fosc 5529600L    //Define the clock
//#define MAIN_Fosc 24000000L   //Define the clock

void delay_ms(unsigned char ms)
{
    unsigned int i;
    do
    {
        i = MAIN_Fosc / 13000;
        while (--i); //14T per loop
    } while (--ms);
}
