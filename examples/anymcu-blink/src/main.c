// Blink example for all mcs51 boards with automatic LED pin
// Your boardname.json should pass the MCU names shown below
// Include files by board name listed in alphabetical order:
#if defined(N76E003)
   #include "n76e003.h"
   #define ledPin P14
   #define INIT_PIN P1M1 &= 0xFE; P1M2 &= 0xFE;
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 4
#elif defined(STC15F10XW)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15F20XA)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15F2KXXS2)
   #include "STC15.h"
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(STC15W10X)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15W20XS)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15W40XAS)
   #include "STC15.h"
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(STC12C5AXXS2)
   #include <stc12.h>
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(STC89C5XRX)
   #include <stc89.h>
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(AT89S51)
   #include <at89x51.h>
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(AT89S52)
   #include <at89x52.h>
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(Generic8052)
   #include "Generic8052.h"
   #define ledPin P1_0
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#else // Assume Generic8051
   #include "Generic8051.h"
   #define ledPin P1_0
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#endif
#include "delay.h"
/*-----------------------------------------------------------------------------
   MAIN ROUTINE
-----------------------------------------------------------------------------*/
void main(void)
{
    INIT_PIN // Macro if needed to initialize output pin
    while (1)
    {
        ledPin = 0x00;   // LED on
        delay_c_ds(250); // Software delay 2500ms
        ledPin = 0xff;   // LED off
        delay_s_ds(250); // Software delay 2500ms

        // int n;
        // ledPin = 0;                  // LED on
        // for (n = 0; n < 50000; n++); // waste some cycles
        // ledPin = 1;                  // LED off
        // for (n = 0; n < 50000; n++); // waste some cycles
    }
}
/*-----------------------------------------------------------------------------
   END OF MODULE
-----------------------------------------------------------------------------*/
