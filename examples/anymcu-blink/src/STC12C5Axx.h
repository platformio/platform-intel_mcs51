#ifndef STC12C5Axx_H
#define STC12C5Axx_H

#include <compiler.h>

// 适用于 STC10Fxx / STC11Fxx / STC12C5Axx / STC12C52xx 系列的芯片
// Modified based on STC-ISP version by: ZnHoCn

                        //新一代 1T 8051系列 单片机内核特殊功能寄存器 C51 Core SFRs
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _ACC 0xE0
SFR(ACC, 0xE0);         //Accumulator                                                               0000,0000
#define _B 0xF0
SFR(B, 0xF0);           //B Register                                                                0000,0000
#define _PSW 0xD0
SFR(CCAP0H, 0xFA);      //PCA 模块 0 的捕捉/比较寄存器高 8 位。                                     0000,0000
SFR(PSW, 0xD0);         //Program Status Word   CY    AC    F0    RS1   RS0   OV    F1    P         0000,0000

SBIT(CY, _PSW, 7);
SBIT(AC, _PSW, 6);
SBIT(F0, _PSW, 5);
SBIT(RS1, _PSW, 4);
SBIT(RS0, _PSW, 3);
SBIT(OV, _PSW, 2);
SBIT(P, _PSW, 0);

#define _SP 0x81
SFR(SP, 0x81);          //Stack Pointer                                                                         0000,0111
#define _DPL 0x82
SFR(DPL, 0x82);         //Data Pointer Low Byte                                                                 0000,0000
#define _DPH 0x83
SFR(DPH, 0x83);         //Data Pointer High Byte                                                                0000,0000

                        //新一代 1T 8051系列 单片机系统管理特殊功能寄存器
                        //                      7       6       5       4       3       2       1       0       Reset Value
#define _PCON 0x87
SFR(PCON, 0x87);        //Power Control         SMOD    SMOD0   LVDF    POF     GF1     GF0     PD      IDL     0001,0000
                        //                      7       6       5       4       3       2       1       0       Reset Value
#define _AUXR 0x8E
SFR(AUXR, 0x8E);        //Auxiliary Register    T0x12   T1x12 UART_M0x6 BRTR    S2SMOD  BRTx12  EXTRAM  S1BRS   0000,0000

#define _AUXR1 0xA2
SFR(AUXR1, 0xA2);       //Auxiliary Register 1  -       PCA_P4  SPI_P4  S2_P4   GF2     ADRJ    -       DPS     0000,0000
/*
PCA_P4:
    0, 缺省PCA 在P1 口
    1，PCA/PWM 从P1 口切换到P4 口: ECI 从P1.2 切换到P4.1 口，
                                   PCA0/PWM0 从P1.3 切换到P4.2 口
                                   PCA1/PWM1 从P1.4 切换到P4.3 口
SPI_P4:
    0, 缺省SPI 在P1 口
    1，SPI 从P1 口切换到P4 口: SPICLK 从P1.7 切换到P4.3 口
                               MISO 从P1.6 切换到P4.2 口
                               MOSI 从P1.5 切换到P4.1 口
                               SS 从P1.4 切换到P4.0 口
S2_P4:
    0, 缺省UART2 在P1 口
    1，UART2 从P1 口切换到P4 口: TxD2 从P1.3 切换到P4.3 口
                                 RxD2 从P1.2 切换到P4.2 口
GF2: 通用标志位

ADRJ:
    0, 10 位A/D 转换结果的高8 位放在ADC_RES 寄存器, 低2 位放在ADC_RESL 寄存器
    1，10 位A/D 转换结果的最高2 位放在ADC_RES 寄存器的低2 位, 低8 位放在ADC_RESL 寄存器

DPS: 0, 使用缺省数据指针DPTR0
     1，使用另一个数据指针DPTR1
*/

#define _WAKE_CLKO 0x8F
SFR(WAKE_CLKO, 0x8F);   //附加的 SFR WAK1_CLKO
/*
      7            6          5          4          3       2       1      0         Reset Value
   PCAWAKEUP  RXD_PIN_IE  T1_PIN_IE  T0_PIN_IE  LVD_WAKE    _    T1CLKO  T0CLKO      0000,0000B

b7 - PCAWAKEUP : PCA 中断可唤醒 powerdown。
b6 - RXD_PIN_IE : 当 P3.0(RXD) 下降沿置位 RI 时可唤醒 powerdown(必须打开相应中断)。
b5 - T1_PIN_IE : 当 T1 脚下降沿置位 T1 中断标志时可唤醒 powerdown(必须打开相应中断)。
b4 - T0_PIN_IE : 当 T0 脚下降沿置位 T0 中断标志时可唤醒 powerdown(必须打开相应中断)。
b3 - LVD_WAKE : 当 CMPIN 脚低电平置位 LVD 中断标志时可唤醒 powerdown(必须打开相应中断)。
b2 -
b1 - T1CLKO : 允许 T1CKO(P3.5) 脚输出 T1 溢出脉冲，Fck1, 1/2 T1 溢出率
b0 - T0CLKO : 允许 T0CKO(P3.4) 脚输出 T0 溢出脉冲，Fck0, 1/2 T1 溢出率
*/

#define _CLK_DIV 0x97
SFR(CLK_DIV, 0x97);     //Clock Divder          -     -      -       -     -  CLKS2 CLKS1 CLKS0     xxxx,x000

#define _BUS_SPEED 0xA1
SFR(BUS_SPEED, 0xA1);   //Stretch register      -     -    ALES1   ALES0   -  RWS2  RWS1  RWS0      xx10,x011
/*
ALES1 and ALES0:
00 : The P0 address setup time and hold time to ALE negative edge is one clock cycle
01 : The P0 address setup time and hold time to ALE negative edge is two clock cycles.
10 : The P0 address setup time and hold time to ALE negative edge is three clock cycles. (default)
11 : The P0 address setup time and hold time to ALE negative edge is four clock cycles.

RWS2,RWS1,RWS0:
  000 : The MOVX read/write pulse is 1 clock cycle.
  001 : The MOVX read/write pulse is 2 clock cycles.
  010 : The MOVX read/write pulse is 3 clock cycles.
  011 : The MOVX read/write pulse is 4 clock cycles. (default)
  100 : The MOVX read/write pulse is 5 clock cycles.
  101 : The MOVX read/write pulse is 6 clock cycles.
  110 : The MOVX read/write pulse is 7 clock cycles.
  111 : The MOVX read/write pulse is 8 clock cycles.
*/

                        //新一代 1T 8051系列 单片机中断特殊功能寄存器
                        //有的中断控制、中断标志位散布在其它特殊功能寄存器中，这些位在位地址中定义
                        //其中有的位无位寻址能力，请参阅 新一代 1T 8051系列 单片机中文指南
                        //                      7     6     5    4     3    2    1    0             Reset Value
#define _IE 0xA8
SFR(IE, 0xA8);          //中断控制寄存器        EA   ELVD  EADC  ES   ET1  EX1  ET0  EX0            0x00,0000

SBIT(EA, _IE, 7);
SBIT(ELVD, _IE, 6);     //低压监测中断允许位
SBIT(EADC, _IE, 5);     //ADC 中断允许位
SBIT(ES, _IE, 4);
SBIT(ET1, _IE, 3);
SBIT(EX1, _IE, 2);
SBIT(ET0, _IE, 1);
SBIT(EX0, _IE, 0);

#define _IE2 0xAF
SFR(IE2, 0xAF);         //Auxiliary Interrupt   -     -     -     -     -     -     ESPI  ES2       0000,0000B

                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _IP 0xB8
SFR(IP, 0xB8);          //中断优先级低位        PPCA  PLVD  PADC  PS    PT1   PX1   PT0   PX0       0000,0000

SBIT(PPCA, _IP, 7);     //PCA 模块中断优先级
SBIT(PLVD, _IP, 6);     //低压监测中断优先级
SBIT(PADC, _IP, 5);     //ADC 中断优先级
SBIT(PS, _IP, 4);
SBIT(PT1, _IP, 3);
SBIT(PX1, _IP, 2);
SBIT(PT0, _IP, 1);
SBIT(PX0, _IP, 0);

                        //                      7      6      5     4     3     2     1     0       Reset Value
#define _IPH 0xB7
SFR(IPH, 0xB7);         //中断优先级高位        PPCAH  PLVDH  PADCH  PSH  PT1H  PX1H  PT0H  PX0H    0000,0000
#define _IP2 0xB5
SFR(IP2, 0xB5);         //                      -      -      -     -     -     -   PSPI   PS2      xxxx,xx00
#define _IPH2 0xB6
SFR(IPH2, 0xB6);        //                      -      -      -     -     -     -   PSPIH  PS2H     xxxx,xx00

                        //新一代 1T 8051系列 单片机I/O 口特殊功能寄存器
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _P0 0x80
SFR(P0, 0x80);          //8 bitPort0            P0.7  P0.6  P0.5  P0.4  P0.3  P0.2  P0.1  P0.0      1111,1111
SBIT(P00, _P0, 0);
SBIT(P01, _P0, 1);
SBIT(P02, _P0, 2);
SBIT(P03, _P0, 3);
SBIT(P04, _P0, 4);
SBIT(P05, _P0, 5);
SBIT(P06, _P0, 6);
SBIT(P07, _P0, 7);
#define _P0M0 0x94
SFR(P0M0, 0x94);        //                                                                          0000,0000
#define _P0M1 0x93
SFR(P0M1, 0x93);        //                                                                          0000,0000
#define _P1 0x90
SFR(P1, 0x90);          //8 bitPort1            P1.7  P1.6  P1.5  P1.4  P1.3  P1.2  P1.1  P1.0      1111,1111
SBIT(P10, _P1, 0);
SBIT(P11, _P1, 1);
SBIT(P12, _P1, 2);
SBIT(P13, _P1, 3);
SBIT(P14, _P1, 4);
SBIT(P15, _P1, 5);
SBIT(P16, _P1, 6);
SBIT(P17, _P1, 7);
#define _P1M0 0x92
SFR(P1M0, 0x92);        //                                                                          0000,0000
#define _P1M1 0x91
SFR(P1M1, 0x91);        //                                                                          0000,0000
#define _P1ASF 0x9D
SFR(P1ASF, 0x9D);       //P1 analog special function
#define _P2 0xA0
SFR(P2, 0xA0);          //8 bitPort2            P2.7  P2.6  P2.5  P2.4  P2.3  P2.2  P2.1  P2.0      1111,1111
SBIT(P20, _P2, 0);
SBIT(P21, _P2, 1);
SBIT(P22, _P2, 2);
SBIT(P23, _P2, 3);
SBIT(P24, _P2, 4);
SBIT(P25, _P2, 5);
SBIT(P26, _P2, 6);
SBIT(P27, _P2, 7);
#define _P2M0 0x96
SFR(P2M0, 0x96);        //                                                                          0000,0000
#define _P2M1 0x95
SFR(P2M1, 0x95);        //                                                                          0000,0000
#define _P3 0xB0
SFR(P3, 0xB0);          //8 bitPort3            P3.7  P3.6  P3.5  P3.4  P3.3  P3.2  P3.1  P3.0      1111,1111
SBIT(P30, _P3, 0);
SBIT(P31, _P3, 1);
SBIT(P32, _P3, 2);
SBIT(P33, _P3, 3);
SBIT(P34, _P3, 4);
SBIT(P35, _P3, 5);
SBIT(P36, _P3, 6);
SBIT(P37, _P3, 7);
#define _P3M0 0xB2
SFR(P3M0, 0xB2);        //                                                                          0000,0000
#define _P3M1 0xB1
SFR(P3M1, 0xB1);        //                                                                          0000,0000
#define _P4 0xC0
SFR(P4, 0xC0);          //8 bitPort4            P4.7  P4.6  P4.5  P4.4  P4.3  P4.2  P4.1  P4.0      1111,1111
SBIT(P40, _P4, 0);
SBIT(P41, _P4, 1);
SBIT(P42, _P4, 2);
SBIT(P43, _P4, 3);
SBIT(P44, _P4, 4);
SBIT(P45, _P4, 5);
SBIT(P46, _P4, 6);
SBIT(P47, _P4, 7);
#define _P4M0 0xB4
SFR(P4M0, 0xB4);        //                                                                          0000,0000
#define _P4M1 0xB3
SFR(P4M1, 0xB3);        //                                                                          0000,0000
                        //                      7     6        5       4    3 2     1     0         Reset Value
#define _P4SW 0xBB
SFR(P4SW, 0xBB);        //Port-4 switch         - LVD_P4.6 ALE_P4.5 NA_P4.4 - -     -     -         x000,xxxx

#define _P5 0xC8
SFR(P5, 0xC8);          //8 bitPort5            -     -     -     -    P5.3  P5.2  P5.1  P5.0       xxxx,1111
SBIT(P50, _P5, 0);
SBIT(P51, _P5, 1);
SBIT(P52, _P5, 2);
SBIT(P53, _P5, 3);
#define _P5M0 0xCA
SFR(P5M0, 0xCA);        //                                                                          0000,0000
#define _P5M1 0xC9
SFR(P5M1, 0xC9);        //                                                                          0000,0000

                        //新一代 1T 8051系列 单片机定时器特殊功能寄存器
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _TCON 0x88
SFR(TCON, 0x88);        //T0/T1 Control         TF1   TR1   TF0   TR0   IE1   IT1   IE0   IT0       0000,0000

SBIT(TF1, _TCON, 7);
SBIT(TR1, _TCON, 6);
SBIT(TF0, _TCON, 5);
SBIT(TR0, _TCON, 4);
SBIT(IE1, _TCON, 3);
SBIT(IT1, _TCON, 2);
SBIT(IE0, _TCON, 1);
SBIT(IT0, _TCON, 0);

#define _TMOD 0x89
SFR(TMOD, 0x89);        //T0/T1 Modes           GATE1 C/T1  M1_1  M1_0  GATE0 C/T0  M0_1  M0_0      0000,0000
#define _TL0 0x8A
SFR(TL0, 0x8A);         //T0 Low Byte                                                               0000,0000
#define _TH0 0x8C
SFR(TH0, 0x8C);         //T0 High Byte                                                              0000,0000
#define _TL1 0x8B
SFR(TL1, 0x8B);         //T1 Low Byte                                                               0000,0000
#define _TH1 0x8D
SFR(TH1, 0x8D);         //T1 High Byte                                                              0000,0000

                        //新一代 1T 8051系列 单片机串行口特殊功能寄存器
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _SCON 0x98
SFR(SCON, 0x98);        //Serial Control      SM0/FE SM1   SM2   REN   TB8   RB8    TI    RI        0000,0000

SBIT(SM0, _SCON, 7);    //SM0/FE
SBIT(SM1, _SCON, 6);
SBIT(SM2, _SCON, 5);
SBIT(REN, _SCON, 4);
SBIT(TB8, _SCON, 3);
SBIT(RB8, _SCON, 2);
SBIT(TI, _SCON, 1);
SBIT(RI, _SCON, 0);

#define _SBUF 0x99
SFR(SBUF, 0x99);        //Serial Data Buffer                                                        xxxx,xxxx
#define _SADEN 0xB9
SFR(SADEN, 0xB9);       //Slave Address Mask                                                        0000,0000
#define _SADDR 0xA9
SFR(SADDR, 0xA9);       //Slave Address                                                             0000,0000

                        //                      7      6      5      4      3      2     1     0    Reset Value
#define _S2CON 0x9A
SFR(S2CON, 0x9A);       //S2 Control          S2SM0  S2SM1  S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI  00000000B
#define _S2BUF 0x9B
SFR(S2BUF, 0x9B);       //S2 Serial Buffer                                                          xxxx,xxxx
#define _BRT 0x9C
SFR(BRT, 0x9C);         //S2 Baud-Rate Timer                                                        0000,0000

                        //新一代 1T 8051系列 单片机看门狗定时器特殊功能寄存器
#define _WDT_CONTR 0xC1
SFR(WDT_CONTR, 0xC1);   //Watch-Dog-Timer Control register
                        //                      7     6     5      4       3      2   1   0         Reset Value
                        //                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0        xx00,0000

                        //新一代 1T 8051系列 单片机PCA/PWM 特殊功能寄存器
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _CCON 0xD8
SFR(CCON, 0xD8);        //PCA 控制寄存器。      CF    CR    -     -     -     -     CCF1  CCF0      00xx,xx00

SBIT(CF, _CCON, 7);     //PCA计数器溢出标志,由硬件或软件置位,必须由软件清0。
SBIT(CR, _CCON, 6);     //1:允许 PCA 计数器计数, 必须由软件清0。

SBIT(CCF1, _CCON, 1);   //PCA 模块1 中断标志, 由硬件置位, 必须由软件清0。
SBIT(CCF0, _CCON, 0);   //PCA 模块0 中断标志, 由硬件置位, 必须由软件清0。

#define _CMOD 0xD9
SFR(CMOD, 0xD9);        //PCA 工作模式寄存器。  CIDL  -     -     -     CPS2  CPS1  CPS0  ECF       0xxx,x000
/*
CIDL: idle 状态时 PCA 计数器是否继续计数, 0: 继续计数, 1: 停止计数。

CPS2: PCA 计数器脉冲源选择位 2。
CPS1: PCA 计数器脉冲源选择位 1。
CPS0: PCA 计数器脉冲源选择位 0。
   CPS2   CPS1   CPS0
    0      0      0    系统时钟频率 fosc/12。
    0      0      1    系统时钟频率 fosc/2。
    0      1      0    Timer0 溢出。
    0      1      1    由 ECI/P3.4 脚输入的外部时钟，最大 fosc/2。
    1      0      0    系统时钟频率，  Fosc/1
    1      0      1    系统时钟频率/4，Fosc/4
    1      1      0    系统时钟频率/6，Fosc/6
    1      1      1    系统时钟频率/8，Fosc/8

ECF: PCA计数器溢出中断允许位, 1--允许 CF(CCON.7) 产生中断。
*/

#define _CL 0xE9
SFR(CL, 0xE9);          //PCA 计数器低位                                                            0000,0000
#define _CH 0xF9
SFR(CH, 0xF9);          //PCA 计数器高位                                                            0000,0000

                        //                      7     6      5      4     3     2     1     0       Reset Value
#define _CCAPM0 0xDA
SFR(CCAPM0, 0xDA);      //PCA 模块0 PWM 寄存器  -   ECOM0  CAPP0  CAPN0  MAT0  TOG0  PWM0  ECCF0    x000,0000
#define _CCAPM1 0xDB
SFR(CCAPM1, 0xDB);      //PCA 模块1 PWM 寄存器  -   ECOM1  CAPP1  CAPN1  MAT1  TOG1  PWM1  ECCF1    x000,0000

//ECOMn, 1:允许比较功能。
//CAPPn, 1:允许上升沿触发捕捉功能。
//CAPNn, 1:允许下降沿触发捕捉功能。
//MATn, 1:当匹配情况发生时, 允许 CCON 中的 CCFn 置位。
//TOGn, 1:当匹配情况发生时, CEXn 将翻转。
//PWMn, 1:将 CEXn 设置为 PWM 输出。
//ECCFn, 1:允许 CCON 中的 CCFn 触发中断。

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   未启用任何功能。
//  x      1      0     0     0     0     x   0x21   16位CEXn上升沿触发捕捉功能。
//  x      0      1     0     0     0     x   0x11   16位CEXn下降沿触发捕捉功能。
//  x      1      1     0     0     0     x   0x31   16位CEXn边沿(上、下沿)触发捕捉功能。
//  1      0      0     1     0     0     x   0x49   16位软件定时器。
//  1      0      0     1     1     0     x   0x4d   16位高速脉冲输出。
//  1      0      0     0     0     1     0   0x42   8位 PWM。

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   无此操作
//  1      0      0     0     0     1     0   0x42   普通8位PWM, 无中断
//  1      1      0     0     0     1     1   0x63   PWM输出由低变高可产生中断
//  1      0      1     0     0     1     1   0x53   PWM输出由高变低可产生中断
//  1      1      1     0     0     1     1   0x73   PWM输出由低变高或由高变低都可产生中断


#define _CCAP0L 0xEA
SFR(CCAP0L, 0xEA);      //PCA 模块 0 的捕捉/比较寄存器低 8 位。                                     0000,0000
#define _CCAP0H 0xFA
SFR(CCAP0H, 0xFA);      //PCA 模块 0 的捕捉/比较寄存器高 8 位。                                     0000,0000
#define _CCAP1L 0xEB
SFR(CCAP1L, 0xEB);      //PCA 模块 1 的捕捉/比较寄存器低 8 位。                                     0000,0000
#define _CCAP1H 0xFB
SFR(CCAP1H, 0xFB);      //PCA 模块 1 的捕捉/比较寄存器高 8 位。                                     0000,0000

                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _PCA_PWM0 0xF2
SFR(PCA_PWM0, 0xF2);    //PCA 模块0 PWM 寄存器。-     -     -     -     -     -   EPC0H EPC0L       xxxx,xx00
#define _PCA_PWM1 0xF3
SFR(PCA_PWM1, 0xF3);    //PCA 模块1 PWM 寄存器。-     -     -     -     -     -   EPC1H EPC1L       xxxx,xx00
                        //PCA_PWMn:             7     6     5     4     3     2     1     0
                        //                      -     -     -     -     -     -   EPCnH EPCnL
                        //B7-B2: 保留
                        //B1(EPCnH): 在 PWM 模式下，与 CCAPnH 组成 9 位数。
                        //B0(EPCnL): 在 PWM 模式下，与 CCAPnL 组成 9 位数。

                        //新一代 1T 8051系列 单片机 ADC 特殊功能寄存器
                        //                      7           6       5       4           3           2       1       0       Reset Value
#define _ADC_CONTR 0xBC
SFR(ADC_CONTR, 0xBC);   //A/D 转换控制寄存器    ADC_POWER   SPEED1  SPEED0  ADC_FLAG    ADC_START   CHS2    CHS1    CHS0    0000,0000
#define _ADC_RES 0xBD
SFR(ADC_RES, 0xBD);     //A/D 转换结果高8位     ADCV.9      ADCV.8  ADCV.7  ADCV.6      ADCV.5      ADCV.4  ADCV.3  ADCV.2  0000,0000
#define _ADC_RESL 0xBE
SFR(ADC_RESL, 0xBE);    //A/D 转换结果低2位     -           -       -       -           -           -       ADCV.1  ADCV.0  0000,0000

                        //新一代 1T 8051系列 单片机 SPI 特殊功能寄存器
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _SPCTL 0xCE
SFR(SPCTL, 0xCE);       //SPI Control Register  SSIG  SPEN  DORD  MSTR  CPOL  CPHA  SPR1  SPR0      0000,0100
#define _SPSTAT 0xCD
SFR(SPSTAT, 0xCD);      //SPI Status Register   SPIF  WCOL  -     -     -     -     -     -         00xx,xxxx
#define _SPDAT 0xCF
SFR(SPDAT, 0xCF);       //SPI Data Register                                                         0000,0000

                        //新一代 1T 8051系列 单片机 IAP/ISP 特殊功能寄存器
#define _IAP_DATA 0xC2
SFR(IAP_DATA, 0xC2);
#define _IAP_ADDRH 0xC3
SFR(IAP_ADDRH, 0xC3);
#define _IAP_ADDRL 0xC4
SFR(IAP_ADDRL, 0xC4);
                        //                      7     6     5     4     3     2     1     0         Reset Value
#define _IAP_CMD 0xC5
SFR(IAP_CMD, 0xC5);     //IAP Mode Table        0     -     -     -     -     -     MS1   MS0       0xxx,xx00
#define _IAP_TRIG 0xC6
SFR(IAP_TRIG, 0xC6);
#define _IAP_CONTR 0xC7
SFR(IAP_CONTR, 0xC7);   //IAP Control Register  IAPEN SWBS SWRST CFAIL  -     WT2   WT1   WT0       0000,x000

#endif

