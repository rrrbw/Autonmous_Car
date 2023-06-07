/*
* main.c
*
* Created: 5/19/2023 6:25:00 PM
*  Author: lraya
*/

#include <xc.h>

// Library
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLOCK.h"

// HAL
#include "DCMotor_interface.h"
#include "HC_SR04_interface.h"
#include "LCD_interface.h"
#include "ServoMotor_interface.h"

// MCAL
#include "DIO_interface.h"


int main(void)
{
	u32 Dist = 0, Right_Dist = 0, Left_Dist = 0;
	LCD_Init();
	DCM_Init();
	ServoMotor_Init();
	HS_SR04_Init();
	
	LCD_SetPos(1, 2);
	LCD_writeString("Made by Rayan");
	LCD_SetPos(2, 3);
	LCD_writeString("Made in KSA");
	_delay_ms(3000);
	
	LCD_clear();
	LCD_SetPos(1, 2);
	LCD_writeString("Start The Car:");
	ServoSetAngle(90);
	_delay_ms(1000);
	
	while(1){
		
		// by default move to forworde
		LCD_SetPos(2, 4);
		LCD_writeString("Forworde");
		DCM_Start();
		
		Dist = Calculate_Distance();
		_delay_ms(1000);
		
		if (Dist <= 30){
			DCM_Stop();
			LCD_clear();
			LCD_SetPos(2, 4);
			LCD_writeString("Stop");
			_delay_ms(500);
			
			ServoSetAngle(0);
			_delay_ms(100);
			
			Left_Dist = Calculate_Distance();
			_delay_ms(1000);
			
			ServoSetAngle(180);
			_delay_ms(200);
			
			Right_Dist = Calculate_Distance();
			_delay_ms(1000);
			
			ServoSetAngle(90);
			_delay_ms(100);
			
			if (Left_Dist > Right_Dist){
				DCM_MoveToBack();
				_delay_ms(500);
				LCD_clear();
				LCD_SetPos(2, 3);
				LCD_writeString("Move To Back");
				
				DCM_MoveToLeft();
				_delay_ms(500);
				LCD_clear();
				DCM_Stop();
				LCD_SetPos(1, 3);
				LCD_writeString("Move To Left");
				
				_delay_ms(1000);
				LCD_clear();
			}
			
			else {
				DCM_MoveToBack();
				_delay_ms(500);
				LCD_clear();
				LCD_SetPos(2, 3);
				LCD_writeString("Move To Back");
				
				DCM_MoveToRight();
				_delay_ms(500);
				LCD_clear();
				DCM_Stop();
				LCD_SetPos(1, 3);
				LCD_writeString("Move To Right");
				
				_delay_ms(1000);
				LCD_clear();
			}
			
		}
		
	}
	
	return 0;
}