/*
* TIMER1_program.c
*
* Created: 02/11/44 03:50:41 م
*  Author: lraya
*/
#include <xc.h>

// Library
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLOCK.h"

// MCAL
#include "TIMER1_interface.h"

void TIMER1_ON(void){
	// ON The timer in 64 prescaler
	SET_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
}
void TIMER1_OFF(void){
	
    TCCR1B = 0x00;	
	
}
u32 TIMER1_value(void){
	
	return TCNT1;
}
void Rest_TIMER1(void){
	
	TCNT1 = 0x00;
}