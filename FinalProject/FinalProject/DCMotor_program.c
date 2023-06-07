/*
* DCMotor_program.c
*
* Created: 29/10/44 11:52:54 م
*  Author: lraya
*/

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "DCMotor_interface.h"
#include "DCMotor_config.h"

void DCM_Init(void){
	DIO_SetPinDirection (DCM_A1, DCM_A1_PIN, SET_PIN_OUTPUT  );
	DIO_SetPinDirection (DCM_A2, DCM_A2_PIN, SET_PIN_OUTPUT  );

	DIO_SetPinDirection (DCM_A3, DCM_A3_PIN, SET_PIN_OUTPUT  );
	DIO_SetPinDirection (DCM_A4, DCM_A4_PIN, SET_PIN_OUTPUT  );
}

void DCM_Start(void){

	// by default move to forworde
	DIO_SetPinValue (DCM_A1, DCM_A1_PIN, HIGH  );
	DIO_SetPinValue (DCM_A2, DCM_A2_PIN, LOW   );
	DIO_SetPinValue (DCM_A3, DCM_A3_PIN, HIGH  );
	DIO_SetPinValue (DCM_A4, DCM_A4_PIN, LOW   );
}

void DCM_MoveToLeft(void){

	// move to left
	DIO_SetPinValue (DCM_A1, DCM_A1_PIN, HIGH  );
	DIO_SetPinValue (DCM_A2, DCM_A2_PIN, LOW   );
	DIO_SetPinValue (DCM_A3, DCM_A3_PIN, LOW   );
	DIO_SetPinValue (DCM_A4, DCM_A4_PIN, HIGH  );
	
}

void DCM_MoveToRight(void){
	
	// ON THE MOTOR:
	//DIO_SetPinValue (DCM_EN1, DCM_EN1_PIN, HIGH);
	//DIO_SetPinValue (DCM_EN2, DCM_EN2_PIN, HIGH);
	
	// move to right
	DIO_SetPinValue (DCM_A1, DCM_A1_PIN, LOW   );
	DIO_SetPinValue (DCM_A2, DCM_A2_PIN, HIGH  );
	DIO_SetPinValue (DCM_A3, DCM_A3_PIN, HIGH  );
	DIO_SetPinValue (DCM_A4, DCM_A4_PIN, LOW   );
	
}

void DCM_MoveToBack(){
	// move to back
	DIO_SetPinValue (DCM_A1, DCM_A1_PIN, LOW   );
	DIO_SetPinValue (DCM_A2, DCM_A2_PIN, HIGH  );
	DIO_SetPinValue (DCM_A3, DCM_A3_PIN, LOW   );
	DIO_SetPinValue (DCM_A4, DCM_A4_PIN, HIGH  );
}

void DCM_Stop(){
	// move to back
	DIO_SetPinValue (DCM_A1, DCM_A1_PIN, LOW   );
	DIO_SetPinValue (DCM_A2, DCM_A2_PIN, LOW   );
	DIO_SetPinValue (DCM_A3, DCM_A3_PIN, LOW   );
	DIO_SetPinValue (DCM_A4, DCM_A4_PIN, LOW   );
}
