/*
* HC_SR03_program.c
*
* Created: 30/10/44 12:45:06 ص
*  Author: lraya
*/

#include <avr/io.h>

// Libaray
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLOCK.h"

// MCAL
#include "DIO_interface.h"

// HAL
#include "HC_SR04_interface.h"
#include "TIMER1_interface.h"

void HS_SR04_Init(){
	// Pin Trigal
	DIO_SetPinDirection(DIO_GROUPA, PIN0, SET_PIN_OUTPUT);
	// Pin Echo
	DIO_SetPinDirection(DIO_GROUPA, PIN1, SET_PIN_INPUT);
	
}

u32 Calculate_Distance(){
	
	// Send pulse width to trigal pin
	DIO_SetPinValue(DIO_GROUPA, PIN0, HIGH);
	_delay_us(10);
	DIO_SetPinValue(DIO_GROUPA, PIN0, LOW);
	
	u32 distance_cm = 0;
	
	// Reset Timer1
	Rest_TIMER1();
	
	// Wait for echo pin to go high
	while (!(DIO_GROUPA & (1 << PIN1))){}
	// Start Timer1
	TIMER1_ON();

	// Wait for echo pin to go low
	while (DIO_GROUPA & (1 << PIN1)){}
	
	// Stop Timer1
	TIMER1_OFF();
	
	// Calculate the distance in cm
	distance_cm = ((34*TIMER1_value()) / 375);
	
	return distance_cm;
	
}