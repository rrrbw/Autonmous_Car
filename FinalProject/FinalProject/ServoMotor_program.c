/*
* ServoMotor_program.c
*
* Created: 30/10/44 12:20:48 ص
*  Author: lraya
*/

#include <avr/io.h>

// Library
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLOCK.h"

// MACL
#include "DIO_interface.h"

// HAL
#include "ServoMotor_interface.h"

void ServoMotor_Init(void){
	
	DIO_SetPinDirection(DIO_GROUPD, PIN6, SET_PIN_OUTPUT);
	DIO_SetPinValue(DIO_GROUPD, PIN6, LOW);
}

void ServoSetAngle(u8 angle){
	
	switch (angle){
		
		case 0:
		DIO_SetPinValue(DIO_GROUPD, PIN6, HIGH);
		_delay_us(1000);
		DIO_SetPinValue(DIO_GROUPD, PIN6, LOW);
		break;
		
		case 90:
		DIO_SetPinValue(DIO_GROUPD, PIN6, HIGH);
		_delay_us(1500);
		DIO_SetPinValue(DIO_GROUPD, PIN6, LOW);
		break;
		
		case 180:
		DIO_SetPinValue(DIO_GROUPD, PIN6, HIGH);
		_delay_us(2000);
		DIO_SetPinValue(DIO_GROUPD, PIN6, LOW);
		break;
	}
	
}


/*
void ServoSetAngle(u8 angle){
u16 pulseWidth = 0;

// Calculate pulse width in microseconds based on the desired angle
pulseWidth = (angle * 10) / 18 + 500;

// Generate the PWM signal
DIO_SetPinValue(DIO_GROUPD, PIN7, HIGH); // ON SERVO motor
_delay_us(pulseWidth); // Wait for the pulse width duration
DIO_SetPinValue(DIO_GROUPD, PIN7, LOW); // OFF SERVO motor
_delay_us(20000 - pulseWidth); // Wait for the remaining period (20ms - pulse width)

}*/