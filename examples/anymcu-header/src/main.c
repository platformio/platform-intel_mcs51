// Automatic header selection example for all mcs51 boards
// Your boardname.json should pass the MCU names shown below
// Include files by board name listed in alphabetical order:
#if defined(N76E003)
   #include "n76e003.h"
#elif defined(STC15F10XW)
   #include "STC15.h"
#elif defined(STC15F20XA)
   #include "STC15.h"
#elif defined(STC15F2KXXS2)
   #include "STC15.h"
#elif defined(STC15W10X)
   #include "STC15.h"
#elif defined(STC15W20XS)
   #include "STC15.h"
#elif defined(STC15W40XAS)
   #include "STC15.h"
#elif defined(STC12C5AXXS2)
   #include <stc12.h>
#elif defined(STC89C5XRX)
   #include <stc89.h>
#elif defined(AT89S51)
   #include <at89x51.h>
#elif defined(AT89S52)
   #include <at89x52.h>
#elif defined(Generic8052)
   #include "Generic8052.h"
#else // Assume Generic8051
   #include "Generic8051.h"
#endif

void main()
{
    /* code */
    // return 0;
}
