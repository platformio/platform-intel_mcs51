#ifndef STC90C5xAD_H
#define STC90C5xAD_H

#include <compiler.h>

// 适用于 STC90C5xAD 系列的芯片
// Modified based on STC-ISP version by: ZnHoCn

/* The following is STC additional SFR */

/*
#define _AUXR 0x8e
SFR(AUXR, 0x8e);
#define _AUXR1 0xa2
SFR(AUXR1, 0xa2);
#define _IPH 0xb7
SFR(IPH, 0xb7);
*/

#define _P4 0xc0
SFR(P4, 0xc0);
SBIT(P46, _P4, 6);
SBIT(P45, _P4, 5);      //ISP下载需勾选"ALE脚用作P4.5口"
SBIT(P44, _P4, 4);
SBIT(P43, _P4, 3);
SBIT(P42, _P4, 2);
SBIT(P41, _P4, 1);
SBIT(P40, _P4, 0);

#define _XICON 0xe8
SFR(XICON, 0xe8);

#define _WDT_CONTR 0xe1
SFR(WDT_CONTR, 0xe1);

#define _ISP_DATA 0xe2
SFR(ISP_DATA, 0xe2);
#define _ISP_ADDRH 0xe3
SFR(ISP_ADDRH, 0xe3);
#define _ISP_ADDRL 0xe4
SFR(ISP_ADDRL, 0xe4);
#define _ISP_CMD 0xe5
SFR(ISP_CMD, 0xe5);
#define _ISP_TRIG 0xe6
SFR(ISP_TRIG, 0xe6);
#define _ISP_CONTR 0xe7
SFR(ISP_CONTR, 0xe7);

/* Above is STC additional SFR */

/*--------------------------------------------------------------------------
REG51F.H

Header file for 8xC31/51, 80C51Fx, 80C51Rx+
Copyright (c) 1988-1999 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.

Modification according to DataSheet from April 1999
 - SFR's AUXR and AUXR1 added for 80C51Rx+ derivatives
--------------------------------------------------------------------------*/

/*  BYTE Registers  */
#define _P0 0x80
SFR(P0, 0x80);
SBIT(P00, _P0, 0);
SBIT(P01, _P0, 1);
SBIT(P02, _P0, 2);
SBIT(P03, _P0, 3);
SBIT(P04, _P0, 4);
SBIT(P05, _P0, 5);
SBIT(P06, _P0, 6);
SBIT(P07, _P0, 7);
#define _P1 0x90
SFR(P1, 0x90);
SBIT(P10, _P1, 0);
SBIT(P11, _P1, 1);
SBIT(P12, _P1, 2);
SBIT(P13, _P1, 3);
SBIT(P14, _P1, 4);
SBIT(P15, _P1, 5);
SBIT(P16, _P1, 6);
SBIT(P17, _P1, 7);
#define _P2 0xA0
SFR(P2, 0xA0);
SBIT(P20, _P2, 0);
SBIT(P21, _P2, 1);
SBIT(P22, _P2, 2);
SBIT(P23, _P2, 3);
SBIT(P24, _P2, 4);
SBIT(P25, _P2, 5);
SBIT(P26, _P2, 6);
SBIT(P27, _P2, 7);
#define _P3 0xB0
SFR(P3, 0xB0);
SBIT(P30, _P3, 0);
SBIT(P31, _P3, 1);
SBIT(P32, _P3, 2);
SBIT(P33, _P3, 3);
SBIT(P34, _P3, 4);
SBIT(P35, _P3, 5);
SBIT(P36, _P3, 6);
SBIT(P37, _P3, 7);
#define _PSW 0xD0
SFR(PSW, 0xD0);
#define _ACC 0xE0
SFR(ACC, 0xE0);
#define _B 0xF0
SFR(B, 0xF0);
#define _SP 0x81
SFR(SP, 0x81);
#define _DPL 0x82
SFR(DPL, 0x82);
#define _DPH 0x83
SFR(DPH, 0x83);
#define _PCON 0x87
SFR(PCON, 0x87);
#define _TCON 0x88
SFR(TCON, 0x88);
#define _TMOD 0x89
SFR(TMOD, 0x89);
#define _TL0 0x8A
SFR(TL0, 0x8A);
#define _TL1 0x8B
SFR(TL1, 0x8B);
#define _TH0 0x8C
SFR(TH0, 0x8C);
#define _TH1 0x8D
SFR(TH1, 0x8D);
#define _IE 0xA8
SFR(IE, 0xA8);
#define _IP 0xB8
SFR(IP, 0xB8);
#define _SCON 0x98
SFR(SCON, 0x98);
#define _SBUF 0x99
SFR(SBUF, 0x99);

/*  80C51Fx/Rx Extensions  */
#define _AUXR 0x8E
SFR(AUXR, 0x8E);
#define _AUXR1 0xA2
SFR(AUXR1, 0xA2);
#define _SADDR 0xA9
SFR(SADDR, 0xA9);
#define _IPH 0xB7
SFR(IPH, 0xB7);
#define _SADEN 0xB9
SFR(SADEN, 0xB9);
#define _T2CON 0xC8
SFR(T2CON, 0xC8);
#define _T2MOD 0xC9
SFR(T2MOD, 0xC9);
#define _RCAP2L 0xCA
SFR(RCAP2L, 0xCA);
#define _RCAP2H 0xCB
SFR(RCAP2H, 0xCB);
#define _TL2 0xCC
SFR(TL2, 0xCC);
#define _TH2 0xCD
SFR(TH2, 0xCD);

/* PCA SFR
#define _CCON 0xD8
SFR(CCON, 0xD8);
#define _CMOD 0xD9
SFR(CMOD, 0xD9);
#define _CCAPM0 0xDA
SFR(CCAPM0, 0xDA);
#define _CCAPM1 0xDB
SFR(CCAPM1, 0xDB);
#define _CCAPM2 0xDC
SFR(CCAPM2, 0xDC);
#define _CCAPM3 0xDD
SFR(CCAPM3, 0xDD);
#define _CCAPM4 0xDE
SFR(CCAPM4, 0xDE);
#define _CL 0xE9
SFR(CL, 0xE9);
#define _CCAP0L 0xEA
SFR(CCAP0L, 0xEA);
#define _CCAP1L 0xEB
SFR(CCAP1L, 0xEB);
#define _CCAP2L 0xEC
SFR(CCAP2L, 0xEC);
#define _CCAP3L 0xED
SFR(CCAP3L, 0xED);
#define _CCAP4L 0xEE
SFR(CCAP4L, 0xEE);
#define _CH 0xF9
SFR(CH, 0xF9);
#define _CCAP0H 0xFA
SFR(CCAP0H, 0xFA);
#define _CCAP1H 0xFB
SFR(CCAP1H, 0xFB);
#define _CCAP2H 0xFC
SFR(CCAP2H, 0xFC);
#define _CCAP3H 0xFD
SFR(CCAP3H, 0xFD);
#define _CCAP4H 0xFE
SFR(CCAP4H, 0xFE);
*/

/*  BIT Registers  */
/*  PSW   */
SBIT(CY, _PSW, 7);
SBIT(AC, _PSW, 6);
SBIT(F0, _PSW, 5);
SBIT(RS1, _PSW, 4);
SBIT(RS0, _PSW, 3);
SBIT(OV, _PSW, 2);
SBIT(P, _PSW, 0);

/*  TCON  */
SBIT(TF1, _TCON, 7);
SBIT(TR1, _TCON, 6);
SBIT(TF0, _TCON, 5);
SBIT(TR0, _TCON, 4);
SBIT(IE1, _TCON, 3);
SBIT(IT1, _TCON, 2);
SBIT(IE0, _TCON, 1);
SBIT(IT0, _TCON, 0);

/*  IE   */
SBIT(EA, _IE, 7);
SBIT(EC, _IE, 6);
SBIT(ET2, _IE, 5);
SBIT(ES, _IE, 4);
SBIT(ET1, _IE, 3);
SBIT(EX1, _IE, 2);
SBIT(ET0, _IE, 1);
SBIT(EX0, _IE, 0);

/*  IP   */
//SBIT(PPC, _IP, 6);
SBIT(PT2, _IP, 5);
SBIT(PS, _IP, 4);
SBIT(PT1, _IP, 3);
SBIT(PX1, _IP, 2);
SBIT(PT0, _IP, 1);
SBIT(PX0, _IP, 0);

/*  P3  */
SBIT(RD, _P3, 7);
SBIT(WR, _P3, 6);
SBIT(T1, _P3, 5);
SBIT(T0, _P3, 4);
SBIT(INT1, _P3, 3);
SBIT(INT0, _P3, 2);
SBIT(TXD, _P3, 1);
SBIT(RXD, _P3, 0);

/*  SCON  */
SBIT(SM0, _SCON, 7);    // alternatively "FE"
SBIT(FE, _SCON, 7);
SBIT(SM1, _SCON, 6);
SBIT(SM2, _SCON, 5);
SBIT(REN, _SCON, 4);
SBIT(TB8, _SCON, 3);
SBIT(RB8, _SCON, 2);
SBIT(TI, _SCON, 1);
SBIT(RI, _SCON, 0);

/*  P1  */
/* PCA
SBIT(CEX4, _P1, 7);
SBIT(CEX3, _P1, 6);
SBIT(CEX2, _P1, 5);
SBIT(CEX1, _P1, 4);
SBIT(CEX0, _P1, 3);
SBIT(ECI, _P1, 2);
*/

SBIT(T2EX, _P1, 1);
SBIT(T2, _P1, 0);

/*  T2CON  */
SBIT(TF2, _T2CON, 7);
SBIT(EXF2, _T2CON, 6);
SBIT(RCLK, _T2CON, 5);
SBIT(TCLK, _T2CON, 4);
SBIT(EXEN2, _T2CON, 3);
SBIT(TR2, _T2CON, 2);
SBIT(C_T2, _T2CON, 1);
SBIT(CP_RL2, _T2CON, 0);

/*  CCON  */
/*  PCA
SBIT(CF, _CCON, 7);
SBIT(CR, _CCON, 6);

SBIT(CCF4, _CCON, 4);
SBIT(CCF3, _CCON, 3);
SBIT(CCF2, _CCON, 2);
SBIT(CCF1, _CCON, 1);
SBIT(CCF0, _CCON, 0);
*/

#endif
