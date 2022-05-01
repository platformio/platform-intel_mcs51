#ifndef Generic8051_H
#define Generic8051_H
#include <compiler.h>

// Includes extra compatibility enhancements over original 8051.h
// Suitable for use with the original basic 8051 series MCU.
// This header file was verified against the MCS-51 manual.
// After this file is included you don't have to include "reg51.h".
// Comments beginning with //- indicate 8051.
// Comments begining with //= indicate defacto standard aliases.
// X means undefined, U means unchanged, C means config dependent.

//SFR DECLARATION   NOTE   POR RESET VALUE   DESCRIPTION
#define _P0 0x80
  SFR(P0, _P0); //- 1111'1111                 Port 0
  SBIT( P0_0,  _P0, 0); //-
  SBIT( P00,   _P0, 0); //=
  SBIT( P0_1,  _P0, 1); //-
  SBIT( P01,   _P0, 1); //=
  SBIT( P0_2,  _P0, 2); //-
  SBIT( P02,   _P0, 2); //=
  SBIT( P0_3,  _P0, 3); //-
  SBIT( P03,   _P0, 3); //=
  SBIT( P0_4,  _P0, 4); //-
  SBIT( P04,   _P0, 4); //=
  SBIT( P0_5,  _P0, 5); //-
  SBIT( P05,   _P0, 5); //=
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

#define _PCON 0x87
  SFR(PCON, _PCON); //- 0XXX'0000             Power Control
  #define IDL   0x01 //-
  #define PD    0x02 //-
  #define GF0   0x04 //-
  #define GF1   0x08 //-
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

#define _P1 0x90
  SFR(P1, _P1); //- 1111'1111                 Port 1
  SBIT( P1_0,  _P1, 0); //-
  SBIT( P10,   _P1, 0); //=
  SBIT( P1_1,  _P1, 1); //-
  SBIT( P11,   _P1, 1); //=
  SBIT( P1_2,  _P1, 2); //-
  SBIT( P12,   _P1, 2); //=
  SBIT( P1_3,  _P1, 3); //-
  SBIT( P13,   _P1, 3); //=
  SBIT( P1_4,  _P1, 4); //-
  SBIT( P14,   _P1, 4); //=
  SBIT( P1_5,  _P1, 5); //-
  SBIT( P15,   _P1, 5); //=
  SBIT( P1_6,  _P1, 6); //-
  SBIT( P16,   _P1, 6); //=
  SBIT( P1_7,  _P1, 7); //-
  SBIT( P17,   _P1, 7); //=

#define _SCON 0x98
  SFR(SCON, _SCON); //- 0000'0000             Serial Port 0 Control
  SBIT( RI,  _SCON, 0); //-
  SBIT( TI,  _SCON, 1); //-
  SBIT( RB8, _SCON, 2); //-
  SBIT( TB8, _SCON, 3); //-
  SBIT( REN, _SCON, 4); //-
  SBIT( SM2, _SCON, 5); //-
  SBIT( SM1, _SCON, 6); //-
  SBIT( SM0, _SCON, 7); //-

#define _SBUF 0x99
  SFR(SBUF, _SBUF); //- XXXX'XXXX             Serial Port 0 Data Buffer

#define _P2 0xA0
  SFR(P2, _P2); //- 1111'1111                 Port 2
  SBIT( P2_0, _P2, 0); //-
  SBIT( P20,  _P2, 0); //=
  SBIT( P2_1, _P2, 1); //-
  SBIT( P2_2, _P2, 2); //-
  SBIT( P2_3, _P2, 3); //-
  SBIT( P2_4, _P2, 4); //-
  SBIT( P2_5, _P2, 5); //-
  SBIT( P2_6, _P2, 6); //-
  SBIT( P2_7, _P2, 7); //-

#define _IE 0xA8
  SFR(IE, _IE); //- 0XX0'0000                 Interrupt Enable (8051)
  SBIT(EX0,  _IE, 0); //-
  SBIT(ET0,  _IE, 1); //-
  SBIT(EX1,  _IE, 2); //-
  SBIT(ET1,  _IE, 3); //-
  SBIT(ES,   _IE, 4); //-
  SBIT(ET2,  _IE, 5); //-
  SBIT(EA,   _IE, 7); //-

#define _P3 0xB0
  SFR(P3, _P3); //- 1111'1111                 Port 3
  SBIT( P3_0, _P3, 0); //-
  SBIT( P30,  _P3, 0); //=
  SBIT( RXD,  _P3, 0); //-
  SBIT( P3_1, _P3, 1); //-
  SBIT( P31,  _P3, 1); //=
  SBIT( TXD,  _P3, 1); //-
  SBIT( P3_2, _P3, 2); //=
  SBIT( P32,  _P3, 2); //=
  SBIT( INT0, _P3, 2); //-
  SBIT( P3_3, _P3, 3); //-
  SBIT( P33,  _P3, 3); //-
  SBIT( INT1, _P3, 3); //-
  SBIT( P3_4, _P3, 4); //-
  SBIT( P34,  _P3, 4); //-
  SBIT( T0,   _P3, 4); //-
  SBIT( P3_5, _P3, 5); //-
  SBIT( P35,  _P3, 5); //-
  SBIT( T1,   _P3, 5); //-
  SBIT( P3_6, _P3, 6); //-
  SBIT( P36,  _P3, 6); //-
  SBIT( WR,   _P3, 6); //-
  SBIT( P3_7, _P3, 7); //-
  SBIT( P37,  _P3, 7); //-
  SBIT( RD,   _P3, 7); //-

#define _IP 0xB8
  SFR(IP, _IP); //- XXX0'0000                 Interrupt priority (8051)
  SBIT(PX0,  _IP, 0); //-
  SBIT(PT0,  _IP, 1); //-
  SBIT(PX1,  _IP, 2); //-
  SBIT(PT1,  _IP, 3); //-
  SBIT(PS,   _IP, 4); //-
  SBIT(PT2,  _IP, 5); //-

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

//Reset vector absolute address declaration
  #define RST_VECTOR 0x00 //- 0x00 Reset Vector
//Interrupt numbers: Address = ( Number * 8 ) + 3
  #define EX0_VECTOR  0  //- 0x03 External Interrupt 0
  #define ET0_VECTOR  1  //- 0x0B Timer 0
  #define EX1_VECTOR  2  //- 0x13 External Interrupt 1
  #define ET1_VECTOR  3  //- 0x1B Timer 1
  #define ES_VECTOR   4  //- 0x23 Serial Port 0

#endif