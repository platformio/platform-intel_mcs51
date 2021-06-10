#ifndef N76E003_H
#define N76E003_H
#include <compiler.h>

// Suitable for use with all N76E003 series MCU.
// This header file was verified against the official Nuvoton BSP
// however it corrects a number of Nuvoton BSP inconsistencies. 
// After this file is included you don't have to include "reg51.h".
// Comments begining with /// indicate non 8051/8052 extensions.
// Comments beginning with //- indicate 8051 and //+ indicate 8052.
// Comments begining with //= indicate defacto standard aliases.
// X means undefined, U means unchanged, C means config dependent.

//SFR DEFINITION | NOTE | POR RESET VALUE  |  DESCRIPTION
#define _P0 0x80
  SFR(P0, _P0); //- 1111'1111                 Port 0
  SBIT( P0_0,  _P0, 0); //-
  SBIT( P00,   _P0, 0); //=
  SBIT( MOSI,  _P0, 0); ///
  SBIT( T1,    _P0, 0); ///
  SBIT( P0_1,  _P0, 1); //-
  SBIT( P01,   _P0, 1); //=
  SBIT( MISO,  _P0, 1); ///
  SBIT( P0_2,  _P0, 2); //-
  SBIT( P02,   _P0, 2); //=
  SBIT( RXD_1, _P0, 2); ///
  SBIT( P0_3,  _P0, 3); //-
  SBIT( P03,   _P0, 3); //=
  SBIT( P0_4,  _P0, 4); //-
  SBIT( P04,   _P0, 4); //=
  SBIT( P0_5,  _P0, 5); //-
  SBIT( P05,   _P0, 5); //=
  SBIT( T0,    _P0, 5); ///
  SBIT( P0_6,  _P0, 6); //-
  SBIT( P06,   _P0, 6); //=
  SBIT( P0_7,  _P0, 7); //-
  SBIT( P07,   _P0, 7); //=

#define _SP 0x81
  SFR(SP, _SP); //- 0000'0111                 Stack pointer

#define _DPL 0x82
  SFR(DPL, _DPL); //- 0000'0000               Data pointer low byte

#define _DPH 0x83
  SFR(DPH, _DPH); //- 0000'0000               Data pointer high byte

#define _RCTRIM0 0x84
  SFR(RCTRIM0, _RCTRIM0); /// 0000'0000       Internal RC trim value high byte

#define _RCTRIM1 0x85
  SFR(RCTRIM1, _RCTRIM1); /// 0000'0000       Internal RC trim value low byte

#define _RWK 0x86
  SFR(RWK, _RWK); /// 0000'0000               Self wake-up timer reload byte

#define _PCON 0x87
//SFR(PCON, _PCON); //- 0XXX'0000             Power Control (8051)
  SFR(PCON, _PCON); /// 0001'0000             Power Control (N76E003)
  #define IDL   0x01 //-
  #define PD    0x02 //-
  #define GF0   0x04 //-
  #define GF1   0x08 //-
  #define POF   0x10 ///
  #define SMOD0 0x40 ///
  #define SMOD  0x80 //-

#define _TCON 0x88
  SFR(TCON, _TCON); //- 0000'0000             Timer/Counter Control
  SBIT(IT0, _TCON, 0); //-
  SBIT(IE0, _TCON, 1); //-
  SBIT(IT1, _TCON, 2); //-
  SBIT(IE1, _TCON, 3); //-
  SBIT(TR0, _TCON, 4); //-
  SBIT(TF0, _TCON, 5); //-
  SBIT(TR1, _TCON, 6); //-
  SBIT(TF1, _TCON, 7); //-

#define _TMOD 0x89
  SFR(TMOD, _TMOD); //- 0000'0000             Timer/Counter Mode Control
  #define T0_M0   0x01 //-
  #define T0_M1   0x02 //-
  #define T0_CT   0x04 //-
  #define T0_GATE 0x08 //-
  #define T1_M0   0x10 //-
  #define T1_M1   0x20 //-
  #define T1_CT   0x40 //-
  #define T1_GATE 0x80 //-

#define _TL0 0x8A
  SFR(TL0, _TL0); //- 0000'0000               Timer/Counter 0 Low Byte

#define _TL1 0x8B
  SFR(TL1, _TL1); //- 0000'0000               Timer/Counter 1 Low Byte

#define _TH0 0x8C
  SFR(TH0, _TH0); //- 0000'0000               Timer/Counter 0 High Byte

#define _TH1 0x8D
  SFR(TH1, _TH1); //- 0000'0000               Timer/Counter 1 High Byte

#define _CKCON 0x8E
  SFR(CKCON, _CKCON); /// 0000'0000           Clock control
  #define CLOEN  0x02 ///
  #define T0M    0x08 ///
  #define T1M    0x10 ///
  #define PWMCKS 0x40 ///

#define _WKCON 0x8F
  SFR(WKCON, _WKCON); /// 0000'0000           Self wake-up timer control
  #define WKPS 0x07 ///
  #define WKTR 0x08 ///
  #define WKTF 0x10 ///

#define _P1 0x90
  SFR(P1, _P1); //- 1111'1111                 Port 1
  SBIT( P1_0,  _P1, 0); //-
  SBIT( P10,   _P1, 0); //=
//SBIT( T2,    _P1, 0); //+                   Software defined on N76E003
  SBIT( SPCLK, _P1, 0); ///
  SBIT( P1_1,  _P1, 1); //-
  SBIT( P11,   _P1, 1); //=
//SBIT( T2EX,  _P1, 1); //+                   Software defined on N76E003
  SBIT( P1_2,  _P1, 2); //-
  SBIT( P12,   _P1, 2); //=
  SBIT( P1_3,  _P1, 3); //-
  SBIT( P13,   _P1, 3); //=
  SBIT( P1_4,  _P1, 4); //-
  SBIT( P14,   _P1, 4); //=
  SBIT( FB,    _P1, 4); ///
  SBIT( P1_5,  _P1, 5); //-
  SBIT( P15,   _P1, 5); //=
  SBIT( SS,    _P1, 5); ///
  SBIT( P1_6,  _P1, 6); //-
  SBIT( P16,   _P1, 6); //=
  SBIT( TXD_1, _P1, 6); ///
  SBIT( P1_7,  _P1, 7); //-
  SBIT( INT1,  _P1, 7); ///
  SBIT( P17,   _P1, 7); //=

#define _SFRS 0x91
  SFR(SFRS, _SFRS); /// TA 0000'0000          SFR page selection
  #define SFRPAGE 0x01 ///

#define _CAPCON0 0x92
  SFR(CAPCON0, _CAPCON0); /// 0000'0000       Input capture control 0
  #define CAPF0  0x01 ///
  #define CAPF1  0x02 ///
  #define CAPF2  0x04 ///
  #define CAPEN0 0x10 ///
  #define CAPEN1 0x20 ///
  #define CAPEN2 0x40 ///

#define _CAPCON1 0x93
  SFR(CAPCON1, _CAPCON1); /// 0000'0000       Input capture control 1
  #define CAP0LS 0x03 ///
  #define CAP1LS 0x0C ///
  #define CAP2LS 0x30 ///

#define _CAPCON2 0x94
  SFR(CAPCON2, _CAPCON2); /// 0000'0000       Input capture control 2
  #define ENF0 0x10 ///
  #define ENF1 0x20 ///
  #define ENF2 0x40 ///

#define _CKDIV 0x95
  SFR(CKDIV, _CKDIV); /// 0000'0000           Clock divider

#define _CKSWT 0x96
  SFR(CKSWT, _CKSWT); /// TA 0011'0000        Clock switch
  #define OSC    0x06 ///
  #define ECLKST 0x08 ///
  #define LIRCST 0x10 ///
  #define HIRCST 0x20 ///
  
#define _CKEN 0x97
  SFR(CKEN, _CKEN); /// TA 0011'0000          Clock enable
  #define CKSWTF 0x01 ///
  #define HIRCEN 0x20 ///
  #define EXTEN  0xC0 ///

#define _SCON 0x98
  SFR(SCON, _SCON); //- 0000'0000             Serial Port 0 Control
  SBIT( RI,  _SCON, 0); //-
  SBIT( TI,  _SCON, 1); //-
  SBIT( RB8, _SCON, 2); //-
  SBIT( TB8, _SCON, 3); //-
  SBIT( REN, _SCON, 4); //-
  SBIT( SM2, _SCON, 5); //-
  SBIT( SM1, _SCON, 6); //-
//SBIT( SM0, _SCON, 7); //-                   (8051)
  SBIT( SM0, _SCON, 7); /// Write             (N76E003)
  SBIT( FE,  _SCON, 7); /// Read

#define _SBUF 0x99
//SFR(SBUF, _SBUF); //- XXXX'XXXX             Serial Port 0 Data Buffer (8051)
  SFR(SBUF, _SBUF); /// 0000'0000             Serial Port 0 Data Buffer (N76E003)

#define _SBUF_1 0x9A
  SFR(SBUF_1, _SBUF_1); /// 0000'0000         Serial port 1 data buffer

#define _EIE 0x9B
  SFR(EIE, _EIE);  /// 0000'0000              Extensive interrupt enable
  #define EI2C 0x01 ///
  #define EPI  0x02 ///
  #define ECAP 0x04 ///
  #define EPWM 0x08 ///
  #define EWDT 0x10 ///
  #define EFB  0x20 ///
  #define ESPI 0x40 ///
  #define ET2  0x80 ///

#define _EIE1 0x9C
  SFR(EIE1, _EIE1); /// 0000'0000             Extensive interrupt enable 1
  #define EX_1 0x01 ///
  #define ET3  0x02 ///
  #define EWKT 0x04 ///

#define _CHPCON 0x9F
  SFR(CHPCON, _CHPCON); /// TA 0000'00C0      Chip control
  #define IAPEN 0x01 ///
  #define BS    0x02 ///
  #define IAPFF 0x40 ///
  #define SWRST 0x80 ///

#define _P2 0xA0
//SFR(P2, _P2); //- 1111'1111                 Port 2 (8051)
  SFR(P2, _P2); /// 0000'000X                 Port 2 (N76E003)
  SBIT( P2_0, _P2, 0); //-
  SBIT( P20,  _P2, 0); //=
  SBIT( RST,  _P2, 0); ///
//SBIT( P2_1, _P2, 1); //-                    Not available on N76E003
//SBIT( P2_2, _P2, 2); //-                    Not available on N76E003
//SBIT( P2_3, _P2, 3); //-                    Not available on N76E003
//SBIT( P2_4, _P2, 4); //-                    Not available on N76E003
//SBIT( P2_5, _P2, 5); //-                    Not available on N76E003
//SBIT( P2_6, _P2, 6); //-                    Not available on N76E003
//SBIT( P2_7, _P2, 7); //-                    Not available on N76E003

#define _AUXR1 0xA2
  SFR(AUXR1, _AUXR1); /// 0000'0000           Auxiliary register 1
  #define UART0PX 0x04 ///
  #define GF2     0x08 ///
  #define HardF   0x20 ///
  #define RSTPINF 0x40 ///
  #define SWRF    0x80 ///

#define _BODCON0 0xA3
  SFR(BODCON0, _BODCON0); /// TA CCCC'XC0X    Brown-out detection control 0
  #define BOS   0x01 ///
  #define BORF  0x02 ///
  #define BORST 0x04 ///
  #define BOF   0x08 ///
  #define BOV   0x30 ///
  #define BODEN 0x80 ///

#define _IAPTRG 0xA4
  SFR(IAPTRG, _IAPTRG); /// TA 0000'0000      IAP trigger
  #define IAPGO 0x01 ///

#define _IAPUEN 0xA5
  SFR(IAPUEN, _IAPUEN); /// TA 0000'0000      IAP update enable
  #define APUEN 0x01 ///
  #define LDUEN 0x02 ///
  #define CFUEN 0x04 ///

#define _IAPAL 0xA6
  SFR(IAPAL, _IAPAL); /// 0000'0000           IAP address low byte

#define _IAPAH 0xA7
  SFR(IAPAH, _IAPAH); /// 0000'0000           IAP address high byte

#define _IE 0xA8
//SFR(IE, _IE); //- 0XX0'0000                 Interrupt Enable (8051)
//SFR(IE, _IE); //+ 0X00'0000                 Interrupt Enable (8052)
  SFR(IE, _IE); /// 0000'0000                 Interrupt Enable (N76E003)
  SBIT(EX0,  _IE, 0); //-
  SBIT(ET0,  _IE, 1); //-
  SBIT(EX1,  _IE, 2); //-
  SBIT(ET1,  _IE, 3); //-
  SBIT(ES,   _IE, 4); //-
  SBIT(EBOD, _IE, 5); ///                     (N76E003)
//SBIT(ET2,  _IE, 5); //-                     (8051)
  SBIT(EADC, _IE, 6); ///
  SBIT(EA,   _IE, 7); //-

#define _SADDR 0xA9
  SFR(SADDR, _SADDR); /// 0000'0000           Slave 0 address

#define _WDCON 0xAA
  SFR(WDCON, _WDCON); /// TA 0000'0111        Watchdog timer control
  #define WDPS  0x07 ///
  #define WDTRF 0x08 ///
  #define WIDPD 0x10 ///
  #define WDTF  0x20 ///
  #define WDCLR 0x40 ///
  #define WDTR  0x80 ///

#define _BODCON1 0xAB
  SFR(BODCON1, _BODCON1); /// TA 0000'0001    Brown-out detection control 1
  #define BODFLT 0x01 ///
  #define LPBOD  0x06 ///

#define _P3M1 0xAC
  SFR(P3M1, _P3M1); /// 0000'0001             P3 mode select 1
  #define P3M1_0 0x01 ///

#define _P3S 0xAC
  SFR(P3S, _P3S); /// Page1 0000'0000         P3 Schmitt trigger input
  #define P3S_0 0x01 ///

#define _P3M2 0xAD
  SFR(P3M2, _P3M2); /// 0000'0000             P3 mode select 2
  #define P3M2_0 0x01 ///

#define _P3SR 0xAD
  SFR(P3SR, _P3SR); /// Page1 0000'0000       P3 slew rate
  #define P3SR_0 0x01 ///

#define _IAPFD 0xAE
  SFR(IAPFD, _IAPFD); /// 0000'0000           IAP flash data

#define _IAPCN 0xAF
  SFR(IAPCN, _IAPCN); /// 0011'0000           IAP control
  #define FCTRL 0x0F ///
  #define FCEN  0x10 ///
  #define FOEN  0x20 ///
  #define IAPB  0xC0 ///

#define _P3 0xB0
//SFR(P3, _P3); //- 1111'1111                 Port 3 (8051)
  SFR(P3, _P3); /// 0000'0001                 Port 3 (N76E003)
  SBIT( P3_0, _P3, 0); //-
  SBIT( P30,  _P3, 0); //=
//SBIT( RXD,  _P3, 0); //-                    Software defined on N76E003
  SBIT( INT0, _P3, 0); ///
  SBIT( XIN,  _P3, 0); ///
//SBIT( P3_1, _P3, 1); //-                    Not available on N76E003
//SBIT( P31,  _P3, 1); //=                    Not available on N76E003
//SBIT( TXD,  _P3, 1); //-                    Software defined on N76E003
//SBIT( P3_2, _P3, 2); //=                    Not available on N76E003
//SBIT( P32,  _P3, 2); //=                    Not available on N76E003
//SBIT( INT0, _P3, 2); //-                    Mapped to P3.0 on N76E003
//SBIT( P3_3, _P3, 3); //-                    Not available on N76E003
//SBIT( P33,  _P3, 3); //-                    Not available on N76E003
//SBIT( INT1, _P3, 3); //-                    Mapped to P1.7 on N76E003
//SBIT( P3_4, _P3, 4); //-                    Not available on N76E003
//SBIT( P34,  _P3, 4); //-                    Not available on N76E003
//SBIT( T0,   _P3, 4); //-                    Mapped to P0.5 on N76E003
//SBIT( P3_5, _P3, 5); //-                    Not available on N76E003
//SBIT( P35,  _P3, 5); //-                    Not available on N76E003
//SBIT( T1,   _P3, 5); //-                    Mapped to P0.0 on N76E003
//SBIT( P3_6, _P3, 6); //-                    Not available on N76E003
//SBIT( P36,  _P3, 6); //-                    Not available on N76E003
//SBIT( WR,   _P3, 6); //-                    Not available on N76E003
//SBIT( P3_7, _P3, 7); //-                    Not available on N76E003
//SBIT( P37,  _P3, 7); //-                    Not available on N76E003
//SBIT( RD,   _P3, 7); //-                    Not available on N76E003

#define _P0M1 0xB1
  SFR(P0M1, _P0M1); /// 1111'1111             P0 mode select 1
  #define P0M1_0 0x01 ///
  #define P0M1_1 0x02 ///
  #define P0M1_2 0x04 ///
  #define P0M1_3 0x08 ///
  #define P0M1_4 0x10 ///
  #define P0M1_5 0x20 ///
  #define P0M1_6 0x40 ///
  #define P0M1_7 0x80 ///

#define _P0S 0xB1
  SFR(P0S, _P0S); /// Page1 0000'0000         P0 Schmitt trigger input
  #define P0S1_0 0x01 ///
  #define P0S1_1 0x02 ///
  #define P0S1_2 0x04 ///
  #define P0S1_3 0x08 ///
  #define P0S1_4 0x10 ///
  #define P0S1_5 0x20 ///
  #define P0S1_6 0x40 ///
  #define P0S1_7 0x80 ///

#define _P0M2 0xB2
  SFR(P0M2, _P0M2); /// 0000'0000             P0 mode select 2
  #define P0M2_0 0x01 ///
  #define P0M2_1 0x02 ///
  #define P0M2_2 0x04 ///
  #define P0M2_3 0x08 ///
  #define P0M2_4 0x10 ///
  #define P0M2_5 0x20 ///
  #define P0M2_6 0x40 ///
  #define P0M2_7 0x80 ///

#define _P0SR 0xB2
  SFR(P0SR, _P0SR); /// Page1 0000'0000       P0 slew rate
  #define P0SR1_0 0x01 ///
  #define P0SR1_1 0x02 ///
  #define P0SR1_2 0x04 ///
  #define P0SR1_3 0x08 ///
  #define P0SR1_4 0x10 ///
  #define P0SR1_5 0x20 ///
  #define P0SR1_6 0x40 ///
  #define P0SR1_7 0x80 ///

#define _P1M1 0xB3
  SFR(P1M1, _P1M1); /// 1111'1111             P1 mode select 1
  #define P1M1_0 0x01 ///
  #define P1M1_1 0x02 ///
  #define P1M1_2 0x04 ///
  #define P1M1_3 0x08 ///
  #define P1M1_4 0x10 ///
  #define P1M1_5 0x20 ///
  #define P1M1_6 0x40 ///
  #define P1M1_7 0x80 ///

#define _P1S 0xB3
  SFR(P1S, _P1S);	/// Page1 0000'0000       P1 Schmitt trigger input
  #define P1S1_0 0x01 ///
  #define P1S1_1 0x02 ///
  #define P1S1_2 0x04 ///
  #define P1S1_3 0x08 ///
  #define P1S1_4 0x10 ///
  #define P1S1_5 0x20 ///
  #define P1S1_6 0x40 ///
  #define P1S1_7 0x80 ///
  
#define _P1M2 0xB4
  SFR(P1M2, _P1M2); /// 0000'0000             P1 mode select 2
  #define P1M2_0 0x01 ///
  #define P1M2_1 0x02 ///
  #define P1M2_2 0x04 ///
  #define P1M2_3 0x08 ///
  #define P1M2_4 0x10 ///
  #define P1M2_5 0x20 ///
  #define P1M2_6 0x40 ///
  #define P1M2_7 0x80 ///
  
#define _P1SR 0xB4
  SFR(P1SR, _P1SR); /// Page1 0000'0000       P1 slew rate
  #define P1SR1_0 0x01 ///
  #define P1SR1_1 0x02 ///
  #define P1SR1_2 0x04 ///
  #define P1SR1_3 0x08 ///
  #define P1SR1_4 0x10 ///
  #define P1SR1_5 0x20 ///
  #define P1SR1_6 0x40 ///
  #define P1SR1_7 0x80 ///
  
#define _P2S 0xB5
  SFR(P2S, _P2S); /// 0000'0000               P20 setting and Timer 0/1 output enable
  #define P2S_0 0x01 ///
  #define T0OE  0x04 ///
  #define T1OE  0x08 ///
  #define P20UP 0x80 ///

#define _IPH 0xB7
  SFR(IPH, _IPH); /// 0000'0000               Interrupt priority high
  #define PX0H  0x01 ///
  #define PT0H  0x02 ///
  #define PX1H  0x04 ///
  #define PT1H  0x08 ///
  #define PSH   0x10 ///
  #define PBODH 0x20 ///
  #define PADCH 0x40 ///

#define _PWMINTC 0xB7
  SFR(PWMINTC, _PWMINTC); ///Page1 0000'0000  PWM interrupt control
  #define INTSEL0 0x01 ///
  #define INTSEL1 0x02 ///
  #define INTSEL2 0x04 ///
  #define INTTYP0 0x10 ///
  #define INTTYP1 0x20 ///

#define _IP 0xB8
//SFR(IP, _IP); //- XXX0'0000                 Interrupt priority (8051)
//SFR(IP, _IP); //+ XX00'0000                 Interrupt priority (8052)
  SFR(IP, _IP); /// 0000'0000                 Interrupt priority (N76E003)
  SBIT(PX0,  _IP, 0); //-
  SBIT(PT0,  _IP, 1); //-
  SBIT(PX1,  _IP, 2); //-
  SBIT(PT1,  _IP, 3); //-
  SBIT(PS,   _IP, 4); //-
  SBIT(PBOD, _IP, 5); ///                     (N76E003)
//SBIT(PT2,  _IP, 5); //-                     (8051)
  SBIT(PADC, _IP, 6); ///

#define _SADEN 0xB9
  SFR(SADEN, _SADEN); /// 0000'0000           Slave 0 address mask

#define _SADEN_1 0xBA
  SFR(SADEN_1, _SADEN_1); /// 0000'0000       Slave 1 address mask

#define _SADDR_1 0xBB
  SFR(SADDR_1, _SADDR_1); /// 0000'0000       Slave 1 address

#define _I2DAT 0xBC
  SFR(I2DAT, _I2DAT); /// 0000'0000           I2C data

#define _I2STAT 0xBD
  SFR(I2STAT, _I2STAT); /// 1111'1000         I2C status
  #define I2STAT 0xF8 ///

#define _I2CLK 0xBE
  SFR(I2CLK, _I2CLK); /// 0000'1001           I2C clock

#define _I2TOC 0xBF
  SFR(I2TOC, _I2TOC); /// 0000'0000           I2C time-out counter
  #define I2TOF   0x01 ///
  #define DIV     0x02 ///
  #define I2TOCEN 0x04 ///

#define _I2CON 0xC0
  SFR(I2CON,  _I2CON); /// 0000'0000           I2C control
  SBIT( I2CPX, _I2CON, 0); ///
  SBIT( AA,    _I2CON, 2); ///
  SBIT( SI,    _I2CON, 3); ///
  SBIT( STO,   _I2CON, 4); ///
  SBIT( STA,   _I2CON, 5); ///
  SBIT( I2CEN, _I2CON, 6); ///

#define _I2ADDR 0xC1
  SFR(I2ADDR, _I2ADDR); /// 0000'0000         I2C own slave address
  #define GC     0x01 ///
  #define I2ADDR 0xFE ///

#define _ADCRL 0xC2
  SFR(ADCRL, _ADCRL); /// 0000'0000           ADC result low byte

#define _ADCRH 0xC3
  SFR(ADCRH, _ADCRH); /// 0000'0000           ADC result high byte

#define _T3CON 0xC4
  SFR(T3CON, _T3CON); /// 0000'0000           Timer 3 control
  #define T3PS    0x07 ///
  #define TR3     0x80 ///
  #define TF3     0x10 ///
  #define BRCK    0x20 ///
  #define SMOD0_1 0x40 ///
  #define SMOD_1  0x80 ///

#define _PWM4H 0xC4
  SFR(PWM4H, _PWM4H); /// Page1 0000'0000     PWM4 duty high byte

#define _RL3 0xC5 /// 0000'0000               Timer 3 reload low byte
  SFR(RL3, _RL3); ///

#define _PWM5H 0xC5
  SFR(PWM5H, _PWM5H); /// Page1 0000'0000     PWM5 duty high byte

#define _RH3 0xC6
  SFR(RH3, _RH3); /// 0000'0000               Timer 3 reload high byte

#define _PIOCON1 0xC6
  SFR(PIOCON1, _PIOCON1); /// Page1 0000'0000 PWM I/O switch 1
  #define PIO11 0x02 ///
  #define PIO12 0x04 ///
  #define PIO13 0x08 ///
  #define PIO15 0x20 ///

#define _TA 0xC7
  SFR(TA, _TA); /// 0000'0000                 Timed access protection

#define _T2CON 0xC8
  SFR(T2CON, _T2CON); //+ 0000'0000           Timer/Counter 2 Control
  SBIT( CM_RL2, _T2CON, 0); //+
//SBIT( CP_RL2, _T2CON, 0); //+               (8051)
//SBIT( C_T2,   _T2CON, 1); //+               (8051)
  SBIT( TR2,    _T2CON, 2); //+
//SBIT( EXEN2,  _T2CON, 3); //+               (8051)
//SBIT( TCLK,   _T2CON, 4); //+               (8051)
//SBIT( RCLK,   _T2CON, 5); //+               (8051)
//SBIT( EXF2,   _T2CON, 6); //+               (8051)
  SBIT(TF2,     _T2CON, 7); //+

#define _T2MOD 0xC9
  SFR(T2MOD,  _T2MOD); /// 0000'0000          Timer 2 mode
  #define LDTS  0x03 ///
  #define CMPCR 0x04 ///
  #define CAPCR 0x08 ///
  #define T2DIV 0x70 ///
  #define LDEN  0x80 ///

#define _RCMP2L 0xCA
  SFR(RCMP2L, _RCMP2L); /// 0000'0000         Timer 2 compare low byte (N76E003)

//#define _RCAP2L 0xCA
//SFR(RCAP2L, _RCAP2L); //+ 0000'0000         T/C 2 Capture Reg. Low byte (8052)

#define _RCMP2H 0xCB
  SFR(RCMP2H, _RCMP2H); /// 0000'0000         Timer 2 compare high byte (N76E003)

//#define _RCAP2H 0xCB
//SFR(RCAP2H, _RCAP2H); //+ 0000'0000         T/C 2 Capture Reg. High byte (8052)

#define _TL2 0xCC
  SFR(TL2,    _TL2); //+ 0000'0000            Timer/Counter 2 Low Byte

#define _PWM4L 0xCC
  SFR(PWM4L,  _PWM4L); /// Page1 0000'0000    PWM4 duty low byte

#define _TH2 0xCD
  SFR(TH2,    _TH2); //+ 0000'0000            Timer/Counter 2 High Byte

#define _PWM5L 0xCD
  SFR(PWM5L, _PWM5L); ///Page1 0000'0000      PWM5 duty low byte

#define _ADCMPL 0xCE
  SFR(ADCMPL, _ADCMPL); /// 0000'0000         ADC compare low byte

#define _ADCMPH 0xCF
  SFR(ADCMPH, _ADCMPH); /// 0000'0000         ADC compare high byte

#define _PSW 0xD0 //- 0000'0000               Program status word
  SFR(PSW,   _PSW); //-
  SBIT( P,   _PSW, 0); //-
  SBIT( F1,  _PSW, 1); //-
  SBIT( OV,  _PSW, 2); //-
  SBIT( RS0, _PSW, 3); //-
  SBIT( RS1, _PSW, 4); //-
  SBIT( F0,  _PSW, 5); //-
  SBIT( AC,  _PSW, 6); //-
  SBIT( CY,  _PSW, 7); //-

#define _PWMPH 0xD1
  SFR(PWMPH, _PWMPH); /// 0000'0000           PWM period high byte

#define _PWM0H 0xD2
  SFR(PWM0H, _PWM0H); /// 0000'0000           PWM0 duty high byte

#define _PWM1H 0xD3
  SFR(PWM1H, _PWM1H); /// 0000'0000           PWM1 duty high byte

#define _PWM2H 0xD4
  SFR(PWM2H, _PWM2H); /// 0000'0000           PWM2 duty high byte

#define _PWM3H 0xD5
  SFR(PWM3H, _PWM3H); /// 0000'0000           PWM3 duty high byte

#define _PNP 0xD6
  SFR(PNP, _PNP); /// 0000'0000               PWM negative polarity
  #define PNP0 0x01 ///
  #define PNP1 0x02 ///
  #define PNP2 0x04 ///
  #define PNP3 0x08 ///
  #define PNP4 0x10 ///
  #define PNP5 0x20 ///

#define _FBD 0xD7
  SFR(FBD, _FBD); /// 0000'0000               Brake data
  #define FBD0   0x01 ///
  #define FBD1   0x02 ///
  #define FBD2   0x04 ///
  #define FBD3   0x08 ///
  #define FBD4   0x10 ///
  #define FBD5   0x20 ///
  #define FBINLS 0x40 ///
  #define FBF    0x80 ///

#define _PWMCON0 0xD8
  SFR(PWMCON0, _PWMCON0); /// 0000'0000       PWM control 0
  SBIT( CLRPWM, _PWMCON0, 4); ///
  SBIT( PWMF,   _PWMCON0, 5); ///
  SBIT( LOAD,   _PWMCON0, 6); ///
  SBIT( PWMRUN, _PWMCON0, 7); ///

#define _PWMPL 0xD9
  SFR(PWMPL, _PWMPL); /// 0000'0000           PWM period low byte

#define _PWM0L 0xDA
  SFR(PWM0L, _PWM0L); /// 0000'0000           PWM0 duty low byte

#define _PWM1L 0xDB
  SFR(PWM1L, _PWM1L); /// 0000'0000           PWM1 duty low byte

#define _PWM2L 0xDC
  SFR(PWM2L, _PWM2L); /// 0000'0000           PWM2 duty low byte

#define _PWM3L 0xDD
  SFR(PWM3L, _PWM3L); /// 0000'0000           PWM3 duty low byte

#define _PIOCON0 0xDE
  SFR(PIOCON0, _PIOCON0); /// 0000'0000       PWM I/O switch 0
  #define PIO00 0x01 ///
  #define PIO01 0x02 ///
  #define PIO02 0x04 ///
  #define PIO03 0x08 ///
  #define PIO04 0x10 ///
  #define PIO05 0x20 ///

#define _PWMCON1 0xDF
  SFR(PWMCON1, _PWMCON1); /// 0000'0000       PWM control 1
  #define PWMDIV 0x07 ///
  #define FBINEN 0x08 ///
  #define PWMTYP 0x10 ///
  #define GP     0x20 ///
  #define PWMMOD 0xC0 ///

#define _ACC 0xE0
  SFR(ACC, _ACC); //- 0000'0000               Accumulator
  SBIT( ACC_0, _ACC, 0); //-
  SBIT( ACC_1, _ACC, 1); //-
  SBIT( ACC_2, _ACC, 2); //-
  SBIT( ACC_3, _ACC, 3); //-
  SBIT( ACC_4, _ACC, 4); //-
  SBIT( ACC_5, _ACC, 5); //-
  SBIT( ACC_6, _ACC, 6); //-
  SBIT( ACC_7, _ACC, 7); //-

#define _ADCCON1 0xE1
  SFR(ADCCON1, _ADCCON1); /// 0000'0000       ADC control 1
  #define ADCEN   0x01 ///
  #define ADCEX   0x02 ///
  #define ETGTYP  0x0C ///
  #define STADCPX 0x40 ///

#define _ADCCON2 0xE2
  SFR(ADCCON2, _ADCCON2); /// 0000'0000       ADC control 2
  #define ADCDLY_8 0x01 ///
  #define ADCMPO   0x10 ///
  #define ADCMPEN  0x20 ///
  #define ADCMPOP  0x40 ///
  #define ADFBEN   0x80 ///

#define _ADCDLY 0xE3
  SFR(ADCDLY, _ADCDLY); /// 0000'0000         ADC trigger delay

#define _C0L 0xE4
  SFR(C0L, _C0L); /// 0000'0000               Input capture 0 low byte

#define _C0H 0xE5
  SFR(C0H, _C0H); /// 0000'0000               Input capture 0 high byte

#define _C1L 0xE6
  SFR(C1L, _C1L); /// 0000'0000               Input capture 1 low byte

#define _C1H 0xE7
  SFR(C1H, _C1H); /// 0000'0000               Input capture 1 high byte

#define _ADCCON0 0xE8
  SFR(ADCCON0, _ADCCON0); /// 0000'0000       ADC control 0
  SBIT( ADCHS0,  _ADCCON0, 0); ///
  SBIT( ADCHS1,  _ADCCON0, 1); ///
  SBIT( ADCHS2,  _ADCCON0, 2); ///
  SBIT( ADCHS3,  _ADCCON0, 3); ///
  SBIT( ETGSEL0, _ADCCON0, 4); ///
  SBIT( ETGSEL1, _ADCCON0, 5); ///
  SBIT( ADCS,    _ADCCON0, 6); ///
  SBIT( ADCF,    _ADCCON0, 7); ///

#define _PICON 0xE9
SFR(PICON, _PICON); /// 0000'0000             Pin interrupt control
  #define PIPS  0x03 ///
  #define PITO  0x04 ///
  #define PIT1  0x08 ///
  #define PIT2  0x10 ///
  #define PIT3  0x20 ///
  #define PIT45 0x40 ///
  #define PIT67 0x80 ///

#define _PINEN 0xEA
SFR(PINEN, _PINEN); /// 0000'0000             Pin interrupt low level/falling edge enable
  #define PINEN0 0x01 ///
  #define PINEN1 0x02 ///
  #define PINEN2 0x04 ///
  #define PINEN3 0x08 ///
  #define PINEN4 0x10 ///
  #define PINEN5 0x20 ///
  #define PIN3N6 0x40 ///
  #define PINEN7 0x80 ///

#define _PIPEN 0xEB
SFR(PIPEN, _PIPEN); /// 0000'0000             Pin interrupt high level/rising edge enable
  #define PIPEN0 0x01 ///
  #define PIPEN1 0x02 ///
  #define PIPEN2 0x04 ///
  #define PIPEN3 0x08 ///
  #define PIPEN4 0x10 ///
  #define PIPEN5 0x20 ///
  #define PIP3N6 0x40 ///
  #define PIPEN7 0x80 ///

#define _PIF 0xEC
  SFR(PIF, _PIF); /// 0000'0000               Pin interrupt flag
  #define PIF0 0x01 ///
  #define PIF1 0x02 ///
  #define PIF2 0x04 ///
  #define PIF3 0x08 ///
  #define PIF4 0x10 ///
  #define PIF5 0x20 ///
  #define PIF6 0x40 ///
  #define PIF7 0x80 ///

#define _C2L 0xED
  SFR(C2L, _C2L); /// 0000'0000               Input capture 2 low byte

#define _C2H 0xEE
  SFR(C2H, _C2H); /// 0000'0000               Input capture 2 high byte

#define _EIP 0xEF
  SFR(EIP, _EIP); /// 0000'0000               Extensive interrupt priority
  #define PI2C 0x01 ///
  #define PPI  0x02 ///
  #define PCAP 0x04 ///
  #define PPWM 0x08 ///
  #define PWDT 0x10 ///
  #define PFB  0x20 ///
  #define PSPI 0x40 ///
  #define PT2  0x80 ///

#define _B 0xF0
  SFR(B, _B); //- 0000'0000                   B register
  SBIT( B_0, _B, 0); //-
  SBIT( B_1, _B, 1); //-
  SBIT( B_2, _B, 2); //-
  SBIT( B_3, _B, 3); //-
  SBIT( B_4, _B, 4); //-
  SBIT( B_5, _B, 5); //-
  SBIT( B_6, _B, 6); //-
  SBIT( B_7, _B, 7); //-

#define _CAPCON3 0xF1
  SFR(CAPCON3, _CAPCON3); /// 0000'0000       Input capture control 3
  #define CAP00 0x01 ///
  #define CAP01 0x02 ///
  #define CAP02 0x04 ///
  #define CAP03 0x08 ///
  #define CAP10 0x10 ///
  #define CAP11 0x20 ///
  #define CAP12 0x40 ///
  #define CAP13 0x80 ///

#define _CAPCON4 0xF2
  SFR(CAPCON4, _CAPCON4); /// 0000'0000       Input capture control 4
  #define CAP20 0x01 ///
  #define CAP21 0x02 ///
  #define CAP22 0x04 ///
  #define CAP23 0x08 ///

#define _SPCR 0xF3
  SFR(SPCR, _SPCR); /// 0000'0000             SPI control
  #define SPR0  0x01 ///
  #define SPR1  0x02 ///
  #define CPHA  0x04 ///
  #define CPOL  0x08 ///
  #define MSTR  0x10 ///
  #define LSBFE 0x20 ///
  #define SPIEN 0x40 ///
  #define SSOE  0x80 ///

#define _SPCR2 0xF3
  SFR(SPCR2, _SPCR2); ///Page1 0000'0000      SPI control 2
  #define SPIS0 0x01 ///
  #define SPIS1 0x02 ///

#define _SPSR 0xF4
  SFR(SPSR, _SPSR); /// 0000'0000             SPI status
  #define TXBUF   0x04 ///
  #define DISMODF 0x08 ///
  #define MODF    0x10 ///
  #define SPIOVF  0x20 ///
  #define WCOL    0x40 ///
  #define SPIF    0x80 ///

#define _SPDR 0xF5
  SFR(SPDR, _SPDR); /// 0000'0000             SPI data

#define _AINDIDS 0xF6
  SFR(AINDIDS, _AINDIDS); /// 0000'0000       ADC channel digital input disable
  #define P17DIDS 0x01 ///
  #define P30DIDS 0x02 ///
  #define P07DIDS 0x04 ///
  #define P06DIDS 0x08 ///
  #define P05DIDS 0x10 ///
  #define P04DIDS 0x20 ///
  #define P03DIDS 0x40 ///
  #define P11DIDS 0x80 ///

#define _EIPH 0xF7
  SFR(EIPH, _EIPH); /// 0000'0000             Extensive interrupt priority high
  #define PI2CH 0x01 ///
  #define PPIH  0x02 ///
  #define PCAPH 0x04 ///
  #define PPWMH 0x08 ///
  #define PWDTH 0x10 ///
  #define PFBH  0x20 ///
  #define PSPIH 0x40 ///
  #define PT2H  0x80 ///

#define _SCON_1 0xF8
  SFR(SCON_1, _SCON_1); /// 0000'0000         Serial port 1 control
  SBIT( RI_1,  _SCON_1, 0); ///
  SBIT( TI_1,  _SCON_1, 1); ///
  SBIT( RB8_1, _SCON_1, 2); ///
  SBIT( TB8_1, _SCON_1, 3); ///
  SBIT( REN_1, _SCON_1, 4); ///
  SBIT( SM2_1, _SCON_1, 5); ///
  SBIT( SM1_1, _SCON_1, 6); ///
  SBIT( SM0_1, _SCON_1, 7); /// Write
  SBIT( FE_1,  _SCON_1, 7); /// Read

#define _PDTEN 0xF9
  SFR(PDTEN, _PDTEN); /// TA 0000'0000        PWM dead time enable
  #define PDT01N   0x01 ///
  #define PDT23N   0x02 ///
  #define PDT45N   0x04 ///
  #define PDTCNT_8 0x10 ///

#define _PDTCNT 0xFA
  SFR(PDTCNT, _PDTCNT); /// TA 0000'0000      PWM dead-time counter

#define _PMEN 0xFB
  SFR(PMEN, _PMEN); /// 0000'0000             PWM mask enable
  #define PMEN0 0x01 ///
  #define PMEN1 0x02 ///
  #define PMEN2 0x04 ///
  #define PMEN3 0x08 ///
  #define PMEN4 0x10 ///
  #define PMEN5 0x20 ///

#define _PMD 0xFC
  SFR(PMD, _PMD); /// 0000'0000               PWM mask data
  #define PMD0 0x01 ///
  #define PMD1 0x02 ///
  #define PMD2 0x04 ///
  #define PMD3 0x08 ///
  #define PMD4 0x10 ///
  #define PMD5 0x20 ///

#define _PORDIS 0xFD
  SFR(PORDIS, _PORDIS); /// TA 0000'0000      POR disable

#define _EIP1 0xFE
  SFR(EIP1, _EIP1); /// 0000'0000             Extensive interrupt priority 1
  #define PS_1 0x01 ///
  #define PT3  0x02 ///
  #define PWKT 0x04 ///

#define _EIPH1 0xFF
  SFR(EIPH1, _EIPH1); /// 0000'0000           Extensive interrupt priority high 1
  #define PSH_1 0x01 ///
  #define PT3H  0x02 ///
  #define PWKTH 0x04 ///

//Reset vector absolute address declaration
#define RST_VECTOR 0x00 //- 0x00 Reset Vector
//Interrupt numbers: Address = ( Number * 8 ) + 3
//Vectors are named after their corresponding interrupt
//enable register bit, so that we don't have to make up
//names and can be consisten across different 8051 MCUs
#define EX0_VECTOR  0  //- 0x03 External Interrupt 0
#define ET0_VECTOR  1  //- 0x0B Timer 0
#define EX1_VECTOR  2  //- 0x13 External Interrupt 1
#define ET1_VECTOR  3  //- 0x1B Timer 1
#define ES_VECTOR   4  //- 0x23 Serial Port 0
#define ET2_VECTOR  5  //+ 0x2B Timer 2
#define EI2C_VECTOR 6  /// 0x33 I2C
#define EP1_VECTOR  7  /// 0x3B Pin Interrupt
#define EBOD_VECTOR 8  /// 0x43 Brown-out
#define ESPI_VECTOR 9  /// 0x4B SPI
#define EWDT_VECTOR 10 /// 0x53 Watchdog timer
#define EADC_VECTOR 11 /// 0x5B ADC
#define ECAP_VECTOR 12 /// 0x63 Input Capture
#define EPWM_VECTOR 13 /// 0x6B PWM
#define EFB_VECTOR  14 /// 0x73 Fault Brake Event
#define ES1_VECTOR  15 /// 0x7B Serial Port 1
#define ET3_VECTOR  16 /// 0x83 Timer 3
#define EWKT_VECTOR 17 /// 0x8B Self Wake-up Timer

#endif