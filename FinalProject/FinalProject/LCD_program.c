/*
 * LCD_program.c
 *
 * Created: 30/10/44 12:36:31 ص
 *  Author: lraya
 */ 

#include <xc.h>

/* Library */
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"


void LCD_Init(void)
{
	// Set Pins Directions For LCD
	DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN, SET_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN, SET_PIN_OUTPUT);

	_delay_ms(35);
	// set Rs pin = 0 (write command)
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	// set Rw pin = 0 (write)
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
	LCD_writeHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	// Function Set command 2*16 LCD , 4 Bit Mode
	LCD_sendCmnd(0b00101000);
	_delay_us(45);

	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_sendCmnd(0b00001111);
	_delay_us(45);

	// Clear Display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);


	LCD_sendCmnd(0b00000110);
}


void LCD_sendCmnd(u8 Cmnd)
{
	// set Rs pin = 0 (write command)
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);

	// set Rw pin = 0 (write)
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);

	// Write The Most 4 bits Of command on Data Pins
	LCD_writeHalfPort(Cmnd>>4);

	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);

	// Write The Least 4 bits Of command on Data Pins
	LCD_writeHalfPort(Cmnd);

	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}


void LCD_sendChar(u8 data)
{
	// set Rs pin = 1 (write data)
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	// set Rw pin = 0 (write)
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);

	// Write The Most 4 bits Of Data on Data Pins
	LCD_writeHalfPort(data>>4);

	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);

	// Write The Least 4 bits Of Data on Data Pins
	LCD_writeHalfPort(data);

	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void LCD_writeString(const u8* String){
	u8 stringLength = 0;
	while(String[stringLength] != '\0')
	{
		LCD_sendChar(String[stringLength] );
		stringLength++;
	}
}

void LCD_clear(void)
{
	// Clear Display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
}

void LCD_writeHalfPort(u8 value)
{
	if(1 == CHECK_BIT(value,0))
	{
		DIO_SetPinValue(LCD_D4_PORT, LCD_D4_PIN, HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_D4_PORT, LCD_D4_PIN, LOW);
	}
	if(1 == CHECK_BIT(value,1))
	{
		DIO_SetPinValue(LCD_D5_PORT, LCD_D5_PIN, HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_D5_PORT, LCD_D5_PIN, LOW);
	}
	if(1 == CHECK_BIT(value,2))
	{
		DIO_SetPinValue(LCD_D6_PORT, LCD_D6_PIN, HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,LOW);
	}
	if(1 == CHECK_BIT(value,3))
	{
		DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,LOW);
	}
}

void LCD_SetPos(u8 LineNo, u8 Pos){
	
	switch(LineNo){
		case 1:
		LCD_sendCmnd((0x80 | (Pos & 0x0F)));
		break;
		case 2:
		LCD_sendCmnd((0xC0 | (Pos & 0x0F)));
		break;
	}
}