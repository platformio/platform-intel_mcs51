#include "delay.h"

#define MAIN_Fosc 16000000L   //Define the clock
//#define MAIN_Fosc 11059200L   //Define the clock

void delay_c_ms(unsigned char ms) //Software delay in mili-sec
{                                 //Calibrated for STC on SDCC
    unsigned int i;
    do
    {
        i = MAIN_Fosc / 13000;
        while (--i); // 14T per loop
    } while (--ms);
}

void delay_c_ds(unsigned char ds) //Software delay in deci-sec
{                                 //Calibrated for STC on SDCC
    unsigned int i;
    do
    {
        i = MAIN_Fosc / 1300;
        while (--i); // 14T per loop
    } while (--ds);
}

void delay_s_ms(unsigned char ms) //Software delay in mili-sec
{                           //Calibrated for Nuvoton N76E003
	ms;						//Must declare delay variable
	__asm
			MOV R2,dpl		//Variable ms was passed via dpl
	00001$: MOV R1,#0x08	//8 x 12.5ms produces 1ms total
	00002$:	MOV R0,#0xFA	//FA is 12.5ms (or C7 is 100us)
	00003$: DJNZ R0,00003$
			DJNZ R1,00002$
			DJNZ R2,00001$
	__endasm;
}

void delay_s_ds(unsigned char ds) //Software delay in deci-sec
{                           //Calibrated for Nuvoton N76E003
	ds;						//Must declare delay variable
	__asm
			MOV R2,dpl		//Variable ds was passed via dpl
	00001$: MOV R1,#0x50	//80 x 12.5ms produces 1ds total
	00002$:	MOV R0,#0xFA	//FA is 12.5ms (or C7 is 100us)
	00003$: DJNZ R0,00003$
			DJNZ R1,00002$
			DJNZ R2,00001$
	__endasm;
}
