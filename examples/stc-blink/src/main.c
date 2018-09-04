#include <reg51.h>     // old header from SDCC
//#include "STC15Fxx.h"  // Official header from STC-ISP
#include <stdint.h>
#include <stdio.h>
#include "delay.h"

// P1 is Chip Pin #P1.0 for STC15W408AS Development board LED Pin
#define ledPin P1

// P33 is Chip Pin #P3.3 for STC15W204S Development board LED Pin
//#define ledPin P33

void main()
{
    while (1)
    {
        ledPin = 0x00;  // LED on
        delay_ms(1000);
        ledPin = 0xff;  // LED off
        delay_ms(1000);

        // int n;
        // ledPin = 0;  // LED on
        // for (n = 0; n < 10000; n++); // waste some cycles
        // ledPin = 1;  // LED off
        // for (n = 0; n < 10000; n++); // waste some cycles
    }
}
