// Blink example for all mcs51 boards with automatic LED pin
// Your boardname.json should pass the MCU names shown below

/*----------------------------------------------------------
   SELECT BOARD
----------------------------------------------------------*/
//Not needed for PlatformIO since the board definition file
//automatically activates macros by which we can identify it,
//like STM8S_NUCLEO_207K8 etc.

//#define n76e003
//#define stc15f104w
//#define stc15w408as

/*----------------------------------------------------------
   INCLUDE FILES BY BOARD NAME IN ALPHABETICAL ORDER
----------------------------------------------------------*/
#if defined(N76E003)
   #include "n76e003.h"
   #define ledPin P14
   #define INIT_PIN P1M1 &= 0xFE; P1M2 &= 0xFE;
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 4
#elif defined(STC15F104W)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15W104)
   #include "STC15.h"
   #define ledPin P33
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 3 pin 3
#elif defined(STC15W408AS)
   #include "STC15.h"
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(STC12C5A60S2)
   #include <stc12.h>
   #define ledPin P10
   #define INIT_PIN //Pin init not needed
   //print this out as an info during compilation
   #warning Connect LED to MCU port 1 pin 0
#elif defined(STC89C52RC)
   #include <stc89.h>
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
#else // GenericMCS51
   #include <mcs51reg.h>
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
