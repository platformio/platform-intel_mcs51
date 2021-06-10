#ifndef STC15W4K_H
#define STC15W4K_H
#include <compiler.h>

// Suitable for use with STC15W4K series MCU with enhanced PWM.
// This header file was verified against the official STC ISP Tool.
// After this file is included you don't have to include "reg51.h"

/////////////////////////////////////////////////
// Note regarding STC15W4K32S4 series of chips:
// All IO ports related to PWM are high after power-on and
// need to be set to quasi-two-way or strong push-pull modes:
// P0.6/P0.7/P1.6/P1.7/P2.1/P2.2/P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
/////////////////////////////////////////////////

// Special Function Register    //Reset Value    Description
#define _ACC 0xE0
SFR(ACC, 0xE0);         //0000,0000 Accumulator
#define _B 0xF0
SFR(B, 0xF0);           //0000,0000 B Register
#define _PSW 0xD0
SFR(PSW, 0xD0);         //0000,0000 Program status word
SBIT(CY, _PSW, 7);
SBIT(AC, _PSW, 6);
SBIT(F0, _PSW, 5);
SBIT(RS1, _PSW, 4);
SBIT(RS0, _PSW, 3);
SBIT(OV, _PSW, 2);
SBIT(F1, _PSW, 1);
SBIT(P, _PSW, 0);
#define _SP 0x81
SFR(SP, 0x81);          //0000,0111 Stack Pointer
#define _DPL 0x82
SFR(DPL, 0x82);         //0000,0000 Data Pointer Low Byte
#define _DPH 0x83
SFR(DPH, 0x83);         //0000,0000 Data Pointer High Byte

// I/O Port Special Function Register
#define _P0 0x80
SFR(P0, 0x80);          //1111,1111 Port 0
SBIT(P00, _P0, 0);
SBIT(P01, _P0, 1);
SBIT(P02, _P0, 2);
SBIT(P03, _P0, 3);
SBIT(P04, _P0, 4);
SBIT(P05, _P0, 5);
SBIT(P06, _P0, 6);
SBIT(P07, _P0, 7);
SBIT(P0_0, _P0, 0);
SBIT(P0_1, _P0, 1);
SBIT(P0_2, _P0, 2);
SBIT(P0_3, _P0, 3);
SBIT(P0_4, _P0, 4);
SBIT(P0_5, _P0, 5);
SBIT(P0_6, _P0, 6);
SBIT(P0_7, _P0, 7);
#define _P1 0x90
SFR(P1, 0x90);          //1111,1111 Port 1
SBIT(P10, _P1, 0);
SBIT(P11, _P1, 1);
SBIT(P12, _P1, 2);
SBIT(P13, _P1, 3);
SBIT(P14, _P1, 4);
SBIT(P15, _P1, 5);
SBIT(P16, _P1, 6);
SBIT(P17, _P1, 7);
SBIT(P1_0, _P1, 0);
SBIT(P1_1, _P1, 1);
SBIT(P1_2, _P1, 2);
SBIT(P1_3, _P1, 3);
SBIT(P1_4, _P1, 4);
SBIT(P1_5, _P1, 5);
SBIT(P1_6, _P1, 6);
SBIT(P1_7, _P1, 7);
#define _P2 0xA0
SFR(P2, 0xA0);          //1111,1111 Port 2
SBIT(P20, _P2, 0);
SBIT(P21, _P2, 1);
SBIT(P22, _P2, 2);
SBIT(P23, _P2, 3);
SBIT(P24, _P2, 4);
SBIT(P25, _P2, 5);
SBIT(P26, _P2, 6);
SBIT(P27, _P2, 7);
SBIT(P2_0, _P2, 0);
SBIT(P2_1, _P2, 1);
SBIT(P2_2, _P2, 2);
SBIT(P2_3, _P2, 3);
SBIT(P2_4, _P2, 4);
SBIT(P2_5, _P2, 5);
SBIT(P2_6, _P2, 6);
SBIT(P2_7, _P2, 7);
#define _P3 0xB0
SFR(P3, 0xB0);          //1111,1111 Port 3
SBIT(P30, _P3, 0);
SBIT(P31, _P3, 1);
SBIT(P32, _P3, 2);
SBIT(P33, _P3, 3);
SBIT(P34, _P3, 4);
SBIT(P35, _P3, 5);
SBIT(P36, _P3, 6);
SBIT(P37, _P3, 7);
SBIT(P3_0, _P3, 0);
SBIT(P3_1, _P3, 1);
SBIT(P3_2, _P3, 2);
SBIT(P3_3, _P3, 3);
SBIT(P3_4, _P3, 4);
SBIT(P3_5, _P3, 5);
SBIT(P3_6, _P3, 6);
SBIT(P3_7, _P3, 7);
#define _P4 0xC0
SFR(P4, 0xC0);          //1111,1111 Port 4
SBIT(P40, _P4, 0);
SBIT(P41, _P4, 1);
SBIT(P42, _P4, 2);
SBIT(P43, _P4, 3);
SBIT(P44, _P4, 4);
SBIT(P45, _P4, 5);
SBIT(P46, _P4, 6);
SBIT(P47, _P4, 7);
SBIT(P4_0, _P4, 0);
SBIT(P4_1, _P4, 1);
SBIT(P4_2, _P4, 2);
SBIT(P4_3, _P4, 3);
SBIT(P4_4, _P4, 4);
SBIT(P4_5, _P4, 5);
SBIT(P4_6, _P4, 6);
SBIT(P4_7, _P4, 7);
#define _P5 0xC8
SFR(P5, 0xC8);          //xxxx,1111 Port 5
SBIT(P50, _P5, 0);
SBIT(P51, _P5, 1);
SBIT(P52, _P5, 2);
SBIT(P53, _P5, 3);
SBIT(P54, _P5, 4);
SBIT(P55, _P5, 5);
SBIT(P56, _P5, 6);
SBIT(P57, _P5, 7);
SBIT(P5_0, _P5, 0);
SBIT(P5_1, _P5, 1);
SBIT(P5_2, _P5, 2);
SBIT(P5_3, _P5, 3);
SBIT(P5_4, _P5, 4);
SBIT(P5_5, _P5, 5);
SBIT(P5_6, _P5, 6);
SBIT(P5_7, _P5, 7);
#define _P6 0xE8
SFR(P6, 0xE8);          //0000,0000 Port 6
SBIT(P60, _P6, 0);
SBIT(P61, _P6, 1);
SBIT(P62, _P6, 2);
SBIT(P63, _P6, 3);
SBIT(P64, _P6, 4);
SBIT(P65, _P6, 5);
SBIT(P66, _P6, 6);
SBIT(P67, _P6, 7);
SBIT(P6_0, _P6, 0);
SBIT(P6_1, _P6, 1);
SBIT(P6_2, _P6, 2);
SBIT(P6_3, _P6, 3);
SBIT(P6_4, _P6, 4);
SBIT(P6_5, _P6, 5);
SBIT(P6_6, _P6, 6);
SBIT(P6_7, _P6, 7);
#define _P7 0xF8
SFR(P7, 0xF8);          //0000,0000 Port 7
SBIT(P70, _P7, 0);
SBIT(P71, _P7, 1);
SBIT(P72, _P7, 2);
SBIT(P73, _P7, 3);
SBIT(P74, _P7, 4);
SBIT(P75, _P7, 5);
SBIT(P76, _P7, 6);
SBIT(P77, _P7, 7);
SBIT(P70, _P7, 0);
SBIT(P7_1, _P7, 1);
SBIT(P7_2, _P7, 2);
SBIT(P7_3, _P7, 3);
SBIT(P7_4, _P7, 4);
SBIT(P7_5, _P7, 5);
SBIT(P7_6, _P7, 6);
SBIT(P7_7, _P7, 7);
#define _P0M0 0x94
SFR(P0M0, 0x94);        //0000,0000 Port 0 Mode Register 0
#define _P0M1 0x93
SFR(P0M1, 0x93);        //0000,0000 Port 0 Mode Register 1
#define _P1M0 0x92
SFR(P1M0, 0x92);        //0000,0000 Port 1 Mode Register 0
#define _P1M1 0x91
SFR(P1M1, 0x91);        //0000,0000 Port 1 Mode Register 1
#define _P2M0 0x96
SFR(P2M0, 0x96);        //0000,0000 Port 2 Mode Register 0
#define _P2M1 0x95
SFR(P2M1, 0x95);        //0000,0000 Port 2 Mode Register 1
#define _P3M0 0xB2
SFR(P3M0, 0xB2);        //0000,0000 Port 3 Mode Register 0
#define _P3M1 0xB1
SFR(P3M1, 0xB1);        //0000,0000 Port 3 Mode Register 1
#define _P4M0 0xB4
SFR(P4M0, 0xB4);        //0000,0000 Port 4 Mode Register 0
#define _P4M1 0xB3
SFR(P4M1, 0xB3);        //0000,0000 Port 4 Mode Register 1
#define _P5M0 0xCA
SFR(P5M0, 0xCA);        //0000,0000 Port 5 Mode Register 0
#define _P5M1 0xC9
SFR(P5M1, 0xC9);        //0000,0000 Port 5 Mode Register 1
#define _P6M0 0xCC
SFR(P6M0, 0xCC);        //0000,0000 Port 6 Mode Register 0
#define _P6M1 0xCB
SFR(P6M1, 0xCB);        //0000,0000 Port 6 Mode Register 1
#define _P7M0 0xE2
SFR(P7M0, 0xE2);        //0000,0000 Port 7 Mode Register 0
#define _P7M1 0xE1
SFR(P7M1, 0xE1);        //0000,0000 Port 7 Mode Register 1

// System management special function register
#define _PCON 0x87
SFR(PCON, 0x87);        //0001,0000 Power Control Register
#define _AUXR 0x8E
SFR(AUXR, 0x8E);        //0000,0000 Auxiliary Register
#define _AUXR1 0xA2
SFR(AUXR1, 0xA2);       //0000,0000 Auxiliary Register 1
#define _P_SW1 0xA2
SFR(P_SW1, 0xA2);       //0000,0000 Peripheral Port Switching Register 1
#define _CLK_DIV 0x97
SFR(CLK_DIV, 0x97);     //xxxx,x000 Clock Division Control Register
#define _BUS_SPEED 0xA1
SFR(BUS_SPEED, 0xA1);   //xx10,x011 Bus Speed Control Register
#define _P1ASF 0x9D
SFR(P1ASF, 0x9D);       //0000,0000 Port 1 Analog Function Configuration Register
#define _P_SW2 0xBA
SFR(P_SW2, 0xBA);       //0xxx,x000 Peripheral Port Switching Register
#define _IRC_CLKO 0xBB
SFR(IRC_CLKO, 0xBB);    //0000,0000 Internal Oscillator Clock Output Control Register

// Interrupt special function register
#define _IE 0xA8
SFR(IE, 0xA8);          //0000,0000 Interrupt Control Register
SBIT(EA, _IE, 7);
SBIT(ELVD, _IE, 6);
SBIT(EADC, _IE, 5);
SBIT(ES, _IE, 4);
SBIT(ET1, _IE, 3);
SBIT(EX1, _IE, 2);
SBIT(ET0, _IE, 1);
SBIT(EX0, _IE, 0);
#define _IP 0xB8
SFR(IP, 0xB8);          //0000,0000 Interrupt Priority Register
SBIT(PPCA, _IP, 7);
SBIT(PLVD, _IP, 6);
SBIT(PADC, _IP, 5);
SBIT(PS, _IP, 4);
SBIT(PT1, _IP, 3);
SBIT(PX1, _IP, 2);
SBIT(PT0, _IP, 1);
SBIT(PX0, _IP, 0);
#define _IE2 0xAF
SFR(IE2, 0xAF);         //0000,0000 Interrupt Control Register 2
#define _IP2 0xB5
SFR(IP2, 0xB5);         //xxxx,xx00 Interrupt Priority Register 2
#define _INT_CLKO 0x8F
SFR(INT_CLKO, 0x8F);    //0000,0000 External Interrupt and Clock Output Control Register

// Timer Special Function Register
#define _TCON 0x88
SFR(TCON, 0x88);        //0000,0000 T0/T1 Control Register
SBIT(TF1, _TCON, 7);
SBIT(TR1, _TCON, 6);
SBIT(TF0, _TCON, 5);
SBIT(TR0, _TCON, 4);
SBIT(IE1, _TCON, 3);
SBIT(IT1, _TCON, 2);
SBIT(IE0, _TCON, 1);
SBIT(IT0, _TCON, 0);
#define _TMOD 0x89
SFR(TMOD, 0x89);        //0000,0000 T0/T1 Mode Register
#define _TL0 0x8A
SFR(TL0, 0x8A);         //0000,0000 T0 Low Byte
#define _TL1 0x8B
SFR(TL1, 0x8B);         //0000,0000 T1 Low Byte
#define _TH0 0x8C
SFR(TH0, 0x8C);         //0000,0000 T0 High Byte
#define _TH1 0x8D
SFR(TH1, 0x8D);         //0000,0000 T1 High Byte
#define _T4T3M 0xD1
SFR(T4T3M, 0xD1);       //0000,0000 T3/T4 Mode Register
#define _T3T4M 0xD1
SFR(T3T4M, 0xD1);       //0000,0000 T3/T4 Mode Register
#define _T4H 0xD2
SFR(T4H, 0xD2);         //0000,0000 T4 High Byte
#define _T4L 0xD3
SFR(T4L, 0xD3);         //0000,0000 T4 Low Byte
#define _T3H 0xD4
SFR(T3H, 0xD4);         //0000,0000 T3 High Byte
#define _T3L 0xD5
SFR(T3L, 0xD5);         //0000,0000 T3 Low Byte
#define _T2H 0xD6
SFR(T2H, 0xD6);         //0000,0000 T2 High Byte
#define _T2L 0xD7
SFR(T2L, 0xD7);         //0000,0000 T2 Low Byte
#define _WKTCL 0xAA
SFR(WKTCL, 0xAA);       //0000,0000 Power Down Wakeup Timer Low Byte
#define _WKTCH 0xAB
SFR(WKTCH, 0xAB);       //0000,0000 Power Down Wakeup Timer High Byte
#define _WDT_CONTR 0xC1
SFR(WDT_CONTR, 0xC1);   //0000,0000 Watchdog Control Register

// Serial port special function register
#define _SCON 0x98
SFR(SCON, 0x98);        //0000,0000 Serial Port 1 Control Register
SBIT(SM0, _SCON, 7);
SBIT(SM1, _SCON, 6);
SBIT(SM2, _SCON, 5);
SBIT(REN, _SCON, 4);
SBIT(TB8, _SCON, 3);
SBIT(RB8, _SCON, 2);
SBIT(TI, _SCON, 1);
SBIT(RI, _SCON, 0);
#define _SBUF 0x99
SFR(SBUF, 0x99);        //xxxx,xxxx Serial Port 1 Data Register
#define _S2CON 0x9A
SFR(S2CON, 0x9A);       //0000,0000 Serial Port 2 Control Register
#define _S2BUF 0x9B
SFR(S2BUF, 0x9B);       //xxxx,xxxx Serial Port 2 Data Register
#define _S3CON 0xAC
SFR(S3CON, 0xAC);       //0000,0000 Serial Port 3 Control Register
#define _S3BUF 0xAD
SFR(S3BUF, 0xAD);       //xxxx,xxxx Serial Port 3 Data Register
#define _S4CON 0x84
SFR(S4CON, 0x84);       //0000,0000 Serial Port 4 Control Register
#define _S4BUF 0x85
SFR(S4BUF, 0x85);       //xxxx,xxxx Serial Port 4 Data Register
#define _SADDR 0xA9
SFR(SADDR, 0xA9);       //0000,0000 Slave Address Register
#define _SADEN 0xB9
SFR(SADEN, 0xB9);       //0000,0000 Slave Address Mask Register

// ADC Special Function Register
#define _ADC_CONTR 0xBC
SFR(ADC_CONTR, 0xBC);   //0000,0000 A/D Conversion Control Register
#define _ADC_RES 0xBD
SFR(ADC_RES, 0xBD);     //0000,0000 A/D Conversion Result High 8 Bits
#define _ADC_RESL 0xBE
SFR(ADC_RESL, 0xBE);    //0000,0000 A/D Conversion Result Low 2 Bits

// SPI Special Function Register
#define _SPSTAT 0xCD
SFR(SPSTAT, 0xCD);      //00xx,xxxx SPI Status Register
#define _SPCTL 0xCE
SFR(SPCTL, 0xCE);       //0000,0100 SPI Control Register
#define _SPDAT 0xCF
SFR(SPDAT, 0xCF);       //0000,0000 SPI Data Register

// IAP/ISP Special Function Register
#define _IAP_DATA 0xC2
SFR(IAP_DATA, 0xC2);    //0000,0000 EEPROM data register
#define _IAP_ADDRH 0xC3
SFR(IAP_ADDRH, 0xC3);   //0000,0000 EEPROM address high byte
#define _IAP_ADDRL 0xC4
SFR(IAP_ADDRL, 0xC4);   //0000,0000 EEPROM address low byte
#define _IAP_CMD 0xC5
SFR(IAP_CMD, 0xC5);     //xxxx,xx00 EEPROM Command Register
#define _IAP_TRIG 0xC6
SFR(IAP_TRIG, 0xC6);    //0000,0000 EEPRPM Command Trigger
#define _IAP_CONTR 0xC7
SFR(IAP_CONTR, 0xC7);   //0000,x000 EEPROM Control Register

// PCA/PWM Special Function Register
#define _CCON 0xD8
SFR(CCON, 0xD8);        //00xx,xx00 PCA Control Register
SBIT(CF, _CCON, 7);
SBIT(CR, _CCON, 6);
SBIT(CCF2, _CCON, 2);
SBIT(CCF1, _CCON, 1);
SBIT(CCF0, _CCON, 0);
#define _CMOD 0xD9
SFR(CMOD, 0xD9);        //0xxx,x000 PCA Working Mode Register
#define _CL 0xE9
SFR(CL, 0xE9);          //0000,0000 PCA Counter Low Byte
#define _CH 0xF9
SFR(CH, 0xF9);          //0000,0000 PCA Counter High Byte
#define _CCAPM0 0xDA
SFR(CCAPM0, 0xDA);      //0000,0000 PCA Module 0 PWM Register
#define _CCAPM1 0xDB
SFR(CCAPM1, 0xDB);      //0000,0000 PCA Module 1 PWM Register
#define _CCAPM2 0xDC
SFR(CCAPM2, 0xDC);      //0000,0000 PCA Module 2 PWM Register
#define _CCAP0L 0xEA
SFR(CCAP0L, 0xEA);      //0000,0000 PCA Module 0 Capture/Compare Register Low Byte
#define _CCAP1L 0xEB
SFR(CCAP1L, 0xEB);      //0000,0000 PCA Module 1 Capture/Compare Register Low Byte
#define _CCAP2L 0xEC
SFR(CCAP2L, 0xEC);      //0000,0000 PCA Module 2 Capture/Compare Register Low Byte
#define _PCA_PWM0 0xF2
SFR(PCA_PWM0, 0xF2);    //xxxx,xx00 PCA Module 0 PWM Register
#define _PCA_PWM1 0xF3
SFR(PCA_PWM1, 0xF3);    //xxxx,xx00 PCA Module 1 PWM Register
#define _PCA_PWM2 0xF4
SFR(PCA_PWM2, 0xF4);    //xxxx,xx00 PCA Module 2 PWM Register
#define _CCAP0H 0xFA
SFR(CCAP0H, 0xFA);      //0000,0000 PCA Module 0 Capture/Compare Register High Byte
#define _CCAP1H 0xFB
SFR(CCAP1H, 0xFB);      //0000,0000 PCA Module 1 Capture/Compare Register High Byte
#define _CCAP2H 0xFC
SFR(CCAP2H, 0xFC);      //0000,0000 PCA Module 2 Capture/Compare Register High Byte

// Comparator Special Function Register
#define _CMPCR1 0xE6
SFR(CMPCR1, 0xE6);      //0000,0000 Comparator Control Register 1
#define _CMPCR2 0xE7
SFR(CMPCR2, 0xE7);      //0000,0000 Comparator Control Register 2

// Enhanced PWM waveform generator special function register
#define _PWMCFG 0xF1
SFR(PWMCFG, 0xF1);      //x000,0000 PWM Special Function Register
#define _PWMCR 0xF5
SFR(PWMCR, 0xF5);       //0000,0000 PWM Control Register
#define _PWMIF 0xF6
SFR(PWMIF, 0xF6);       //x000,0000 Interrupt Flag Register
#define _PWMFDCR 0xF7
SFR(PWMFDCR, 0xF7);     //xx00,0000 PWM External Exception Detection Control Register

// The following special function registers are in the extended RAM area.
// You need to set bit7 of P_SW2 to 1 to read and write them normally.
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff50)
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff54)

#endif
