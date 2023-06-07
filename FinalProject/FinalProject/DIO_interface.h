/*
 * DIO_interface.h
 *
 * Created: 29/10/44 01:39:01 ص
 *  Author: lraya
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
/************* MACROS**************/
#define DIO_GROUPA      0
#define DIO_GROUPB      1
#define DIO_GROUPC      2
#define DIO_GROUPD      3

/*********** pi DIRECTION***********/

#define SET_PIN_INPUT  0
#define SET_PIN_OUTPUT  1

/**************** Pin Macros**************/

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

/*********************** MACROS FOR PINSTATE****************/

#define LOW  0
#define HIGH 1

/************************************ APIS PROTO TYPES************************************/

void DIO_SetPinDirection(u8 GroupId,u8 PinId,u8 PinMode);
void DIO_SetPinValue(u8 GroupId,u8 PinId,u8 PinValue);
void DIO_GetPinValue(u8 GroupId,u8 PinId,u8* PinValue);
void DIO_TogglePinValue(u8 GroupId,u8 PinId);
void DIO_SetGroupDirection(u8 GroupId,u8 PinMode);

#endif /* DIO_INTERFACE_H_ */