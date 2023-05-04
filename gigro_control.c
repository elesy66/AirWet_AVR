/*
*******************************************************************************
** Name  : gigro_control.c
** Date  : 02.04.2023
** By    : I.Zaicev
** Notes :
*******************************************************************************
*/
#include "gigro_control.h"

/*
*******************************************************************************
**                        Variables
*******************************************************************************
*/

/*$PAGE$*/
/*
*******************************************************************************
** Description : 
** Parameter   : none
** Return      : none
** Notes       : KL1 -> PD7, KL2 -> PD6, KL3-> PD5, KL4-> PD4,
**               KL5 -> PD3, KL6 -> PD2, KL7-> PB7, KL8-> PB6,
**               KL9 -> PB5, KL_H -> PC1, KL_L->  PC3,
*******************************************************************************
*/
void GigroControl_Init ( void )
{
	PORTF &= ~( 1 << PORTF6 );
	DDRF  |= ( 1 << DDRF6 );
	
	PORTF &= ~( ( 1 << PORTF5 ) | ( 1 << PORTF4 ) | ( 1 << PORTF3 ) | ( 1 << PORTF2 ) ) ;
	DDRF  &= ~( ( 1 << DDRF5 ) | ( 1 << DDRF4 ) | ( 1 << DDRF3 ) | ( 1 << DDRF2 ) );
	
	PORTA &= ~( ( 1 << PORTA5 ) | ( 1 << PORTA4 ) | ( 1 << PORTA3 ) | ( 1 << PORTA2 ) ) ;
	DDRA  &= ~( ( 1 << DDRA3 ) | ( 1 << DDRA2 ) | ( 1 << DDRA1 ) | ( 1 << DDRA0 ) );
}
/*$PAGE$*/
/*
*******************************************************************************
** Description :
** Parameter   : none
** Return      : none
** Notes       : 
**               
*******************************************************************************
*/
uint8_t GigroControl_ReadStatus ( void )
{
	uint8_t RetVal = 0;
	
	if ( bit_is_set ( PINA, PINA3 ) ) {
		sbi ( RetVal, 0 );
	} else {
		cbi ( RetVal, 0 );
	}
	if ( bit_is_set ( PINA, PINA2 ) ) {
		sbi ( RetVal, 1 );
	} else {
		cbi ( RetVal, 1 );
	}
	if ( bit_is_set ( PINA, PINA1 ) ) {
		sbi ( RetVal, 2 );
	} else {
		cbi ( RetVal, 2 );
	}
	if ( bit_is_set ( PINA, PINA0 ) ) {
		sbi ( RetVal, 3 );
	} else {
		cbi ( RetVal, 3 );
	}
	if ( bit_is_set ( PINF, PINF5 ) ) {
		sbi ( RetVal, 4 );
	} else {
		cbi ( RetVal, 4 );
	}
	if ( bit_is_set ( PINF, PINF4 ) ) {
		sbi ( RetVal, 5 );
	} else {
		cbi ( RetVal, 5 );
	}
	if ( bit_is_set ( PINF, PINF3 ) ) {
		sbi ( RetVal, 6 );
	} else {
		cbi ( RetVal, 6 );
	}
	if ( bit_is_set ( PINF, PINF2 ) ) {
		sbi ( RetVal, 7 );
	} else {
		cbi ( RetVal, 7 );
	}
	
	return RetVal;
}
