﻿/*
* DIO_program.c
*
* Created: 29/10/44 01:54:21 ص
*  Author: lraya
*/

#include <avr/io.h>

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"


/* MCAL */
#include "DIO_interface.h"

/**************************************************************************/

void DIO_SetPinDirection(u8 GroupId, u8 PinId, u8 PinMode)
{
	if((GroupId<=3)&&(PinId<=7)&&((PinMode==SET_PIN_OUTPUT)||(PinMode==SET_PIN_INPUT)))
	{
		switch (GroupId)
		{
			case DIO_GROUPA:
			if (PinMode == SET_PIN_OUTPUT)
			{
				SET_BIT(DDRA, PinId);
			}
			else
			{
				CLEAR_BIT(DDRA, PinId);
			}
			break;
			case DIO_GROUPB:
			if (PinMode == SET_PIN_OUTPUT)
			{
				SET_BIT(DDRB, PinId);
			}
			else
			{
				CLEAR_BIT(DDRB, PinId);
			}
			break;
			case DIO_GROUPC:
			if (PinMode == SET_PIN_OUTPUT)
			{
				SET_BIT(DDRC, PinId);
			}
			else
			{
				CLEAR_BIT(DDRC, PinId);
			}
			break;
			case DIO_GROUPD:
			if (PinMode == SET_PIN_OUTPUT)
			{
				SET_BIT(DDRD, PinId);
			}
			else
			{
				CLEAR_BIT(DDRD, PinId);
			}
			break;
		}

	}

	else
	{

		/* Do Nothing*/
	}
}

/**********************************************************************************/

void DIO_SetPinValue(u8 GroupId, u8 PinId, u8 PinValue)
{

	if((GroupId<=3)&&(PinId<=7)&&((PinValue==HIGH)||(PinValue==LOW)))
	{
		switch (GroupId)
		{
			case DIO_GROUPA:
			if (PinValue == HIGH)
			{
				SET_BIT(PORTA, PinId);
			}

			else
			{

				CLEAR_BIT(PORTA, PinId);
			}
			break;
			case DIO_GROUPB:
			if (PinValue == HIGH)
			{
				SET_BIT(PORTB, PinId);
			}

			else
			{

				CLEAR_BIT(PORTB, PinId);
			}
			break;
			case DIO_GROUPC:
			if (PinValue == HIGH)
			{
				SET_BIT(PORTC, PinId);
			}

			else
			{

				CLEAR_BIT(PORTC, PinId);
			}
			break;
			case DIO_GROUPD:
			if (PinValue == HIGH)
			{
				SET_BIT(PORTD, PinId);
			}

			else
			{

				CLEAR_BIT(PORTD, PinId);
			}
			break;
		}

	}


	else
	{

	}
}

void DIO_GetPinValue(u8 GroupId, u8 PinId, u8 *PinValue)
{
	switch (GroupId)
	{
		case DIO_GROUPA:
		*PinValue = CHECK_BIT(PINA, PinId);
		break;
		case DIO_GROUPB:
		*PinValue = CHECK_BIT(PINB, PinId);
		break;
		case DIO_GROUPC:
		*PinValue = CHECK_BIT(PINC, PinId);
		break;
		case DIO_GROUPD:
		*PinValue = CHECK_BIT(PIND, PinId);
		break;
	}
}


void DIO_TogglePinValue(u8 GroupId, u8 PinId)
{
	switch (GroupId)
	{
		case DIO_GROUPA:
		TOOGLE_BIT(PORTA, PinId);
		break;
		case DIO_GROUPB:
		TOOGLE_BIT(PORTB, PinId);
		break;
		case DIO_GROUPC:
		TOOGLE_BIT(PORTC, PinId);
		break;
		case DIO_GROUPD:
		TOOGLE_BIT(PORTD, PinId);
		break;
	}
}


void DIO_SetGroupDirection(u8 GroupId, u8 PinMode)
{
	u8 i;
	switch (GroupId)
	{

		case DIO_GROUPA:
		if (PinMode == SET_PIN_OUTPUT)
		{

			for (i = 0; i <= 7; i++)
			{
				SET_BIT(DDRA, i);
			}
		}

		else
		{

			for ( i = 0; i <= 7; i++)
			{
				CLEAR_BIT(DDRA, i);
			}
		}
		break;

		case DIO_GROUPB:
		if (PinMode == SET_PIN_OUTPUT)
		{

			for ( i = 0; i <= 7; i++)
			{
				SET_BIT(DDRB, i);
			}
		}

		else
		{

			for (i = 0; i <= 7; i++)
			{
				CLEAR_BIT(DDRB, i);
			}
		}
		break;
		case DIO_GROUPC:
		if (PinMode == SET_PIN_OUTPUT)
		{

			for (i = 0; i <= 7; i++)
			{
				SET_BIT(DDRC, i);
			}
		}

		else
		{

			for ( i = 0; i <= 7; i++)
			{
				CLEAR_BIT(DDRC, i);
			}
		}
		break;
		case DIO_GROUPD:
		if (PinMode == SET_PIN_OUTPUT)
		{

			for (i = 0; i <= 7; i++)
			{
				SET_BIT(DDRD, i);
			}
		}

		else
		{

			for (i = 0; i <= 7; i++)
			{
				CLEAR_BIT(DDRD, i);
			}
		}
		break;
	}
}


