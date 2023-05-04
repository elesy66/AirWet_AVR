/*
*******************************************************************************
** Name  : app.h
** Date  : 01.04.2023
** By    : I.Zaicev
** Notes :
*******************************************************************************
*/
#include "app.h"


/*
*******************************************************************************
**                        Variables
*******************************************************************************
*/
_system  sys_var;

uint16_t KlapanStatus = 0;
/*$PAGE$*/
/*
*******************************************************************************
** Description :
** Parameter   : none
** Return      : none
** Notes       :
*******************************************************************************
*/
ISR ( TIMER0_COMP_vect )
{
    TCNT0 = 0;
    sys_var.sys_tick++;
    if ( sys_var.sys_tick == 10 ) {
        sys_var.sys_tick = 0;
        sys_var.Fw_1_ms = 1;
    }
    sbi ( TIFR, OCF0 );
}
/*$PAGE$*/
/*
*******************************************************************************
** Description :
** Parameter   : none
** Return      : none
** Notes       :
*******************************************************************************
*/
ISR ( TIMER0_OVF_vect )
{
    _NOP();
}
/*$PAGE$*/
/*
*******************************************************************************
** Description :
** Parameter   : none
** Return      : none
** Notes       :
*******************************************************************************
*/
int main(void)
{
    ACSR  = 0x80;		// Analog Comparator Disable
	wdt_disable();
    // RES32 - ESP32 -> PE7
    DDRE  |= ( 1 << DDE7 );
    PORTE |= ( 1 << PORTE7 );
    // ERST - W5500  -> PB4
    DDRB  |= ( 1 << DDB4 );
    PORTB |= ( 1 << PORTB4 );
    
    RelayPump_Init ();
    PressureSensor_Init ();

    RelayKlapan_Init();
	GigroControl_Init ();

    TimerSys_Init();
    sei();
		
    while (1) 
    {
        _NOP();
        if ( sys_var.Fw_1_ms == 1 ) {
            sys_var.Fw_1_ms = 0;
			
        }
    }
}
/*$PAGE$*/
/*
*******************************************************************************
** Description :
** Parameter   : none
** Return      : none
** Notes       :
*******************************************************************************
*/
void TimerSys_Init ( void )
{
    TCCR0 = 0x02;  // F = Fclk/8
    OCR0  = 97;   // 100 usec
    TIMSK |= ( 1 << OCIE0 );
}