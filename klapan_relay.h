/*
*******************************************************************************
** Name  : klapan_relay.h
** Date  : 01.04.2023
** By    : I.Zaicev
** Notes :
*******************************************************************************
*/
#ifndef KLAPAN_RELAY_H_
#define KLAPAN_RELAY_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <compat/ina90.h>
#include <avr/pgmspace.h>
#include <math.h>			// sqrt sin cos
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <avr/sfr_defs.h>

#include "conf.h"

/*
*******************************************************************************
**                        Definitions
*******************************************************************************
*/
// KL1 -> PD7
#define KL_1_ON()      { sbi ( PORTD, PORTD7 ); }
#define KL_1_OFF()     { cbi ( PORTD, PORTD7 ); }
// KL2 -> PD6
#define KL_2_ON()      { sbi ( PORTD, PORTD6 ); }
#define KL_2_OFF()     { cbi ( PORTD, PORTD6 ); }
// KL3 -> PD5
#define KL_3_ON()      { sbi ( PORTD, PORTD5 ); }
#define KL_3_OFF()     { cbi ( PORTD, PORTD5 ); }
// KL4 -> PD4
#define KL_4_ON()      { sbi ( PORTD, PORTD4 ); }
#define KL_4_OFF()     { cbi ( PORTD, PORTD4 ); }
// KL5 -> PD3
#define KL_5_ON()      { sbi ( PORTD, PORTD3 ); }
#define KL_5_OFF()     { cbi ( PORTD, PORTD3 ); }
// KL6 -> PD2
#define KL_6_ON()      { sbi ( PORTD, PORTD2 ); }
#define KL_6_OFF()     { cbi ( PORTD, PORTD2 ); }
// KL7 -> PB7
#define KL_7_ON()      { sbi ( PORTB, PORTB7 ); }
#define KL_7_OFF()     { cbi ( PORTB, PORTB7 ); }
// KL8 -> PB6
#define KL_8_ON()      { sbi ( PORTB, PORTB6 ); }
#define KL_8_OFF()     { cbi ( PORTB, PORTB6 ); }
// KL9 -> PB5
#define KL_9_ON()      { sbi ( PORTB, PORTB5 ); }
#define KL_9_OFF()     { cbi ( PORTB, PORTB5 ); }
// KL_H -> PC1
#define KL_H_ON()      { sbi ( PORTC, PORTC1 ); }
#define KL_H_OFF()     { cbi ( PORTC, PORTC1 ); }
// KL_L -> PC3
#define KL_L_ON()      { sbi ( PORTC, PORTC3 ); }
#define KL_L_OFF()     { cbi ( PORTC, PORTC3 ); }

/*
*******************************************************************************
**                        Constants
*******************************************************************************
*/

/*
*******************************************************************************
**                        Typedefs
*******************************************************************************
*/

/*
*******************************************************************************
**                        Variables
*******************************************************************************
*/

/*
*******************************************************************************
**                        Function Prototipes
*******************************************************************************
*/
void RelayKlapan_Init ( void );
uint16_t RelayKlapan_ReadStatus ( void );

#endif