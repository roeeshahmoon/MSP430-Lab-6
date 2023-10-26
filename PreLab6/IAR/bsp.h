#ifndef _BSP_H
#define _BSP_H

#include <msp430g2553.h>

// ----------------------------------------------

// MSP430G2553 MCU-specific defines
#if defined (__MSP430G2553__)

#define RAM_ADDRESS       0x0200
#define FLASH_ADDRESS     0xC000
#define STACK_ADDRESS     0x03FF

// ADC10 abstraction
#define ADC_VECTOR        ADC10_VECTOR
#define ADC_MEM           &ADC10MEM
#define ADC_CONTROL0      &ADC10CTL0
#define ADC_CONTROL1      &ADC10CTL1

#define ADC_AE            &ADC10AE0
#define ADC_IE            ADC10IE
#define ADC_SC            ADC10SC
#define ADC_ON            ADC10ON
#define ADC_SHT           ADC10SHT_0       //if we need to change here it's easy _x
#define ADC_DIV           ADC10DIV_0       
#define ADC_SSEL           ADC10SSEL_0  //ADC10OSC 5 MHZ
#define ADC_SHP           0
#define ADC_INCH          INCH_3
#define ADC_INCH2         0
#define ADC_INT_ENABLED   0

#define ADC_MAX_VALUE     0x3FF   //0-1023
#define ADC_CH            0x08
#define ADC_PORT_SEL      0
#define ADC_DELTA         278  //need to be 292 calc is (3.5 / 2^10 - 1)

// ----------------------------------------------

// general defines that work on both MCUs

#define debounceVal       250

// LCD abstraction
#define LCDArrPort        &P2OUT
#define LCDArrPortSel     &P2SEL
#define LCDArrPortDir     &P2DIR
#define LCDControl        &P1OUT
#define LCDControlSel     &P1SEL
#define LCDControlDir     &P1DIR
#define LCD_E             0x20
#define LCD_RS            0x40
#define LCD_RW            0x80

// LCD cmds
#define LCD_CursorResetL1   0x02 // cursor gets set to the beginning of the first line
#define LCD_CursorResetL2 0xC0 // cursor gets set to the beginning of the second line
#define LCD_Clear         0x01 // clears all chars from the screen
#define LCD_CursorOFF     0x0C // hides cursor from screen
#define LCD_CursorON      0x0F // shows cursor on screen
#define LCD_CursorRight   0x14 // moves cursor one step right
#define LCD_CursorLeft    0x10 // moves cursor one step left

// Pushbuttons abstraction
#define PBsArrPort        &P1IN
#define PBsArrIntPend     &P1IFG
#define PBsArrIntEn       &P1IE
#define PBsArrIntEdgeSel  &P1IES
#define PBsArrPortSel     &P1SEL
#define PBsArrPortDir     &P1DIR
#define PB0               0x01
#define PB1               0x02
#define PB2               0x04

#define PBs               (PB0+PB1+PB2)

//-------------------------------------------

#endif