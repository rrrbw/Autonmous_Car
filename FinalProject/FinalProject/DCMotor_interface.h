/*
 * DCMotor_interface.h
 *
 * Created: 29/10/44 11:50:49 م
 *  Author: lraya
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

void DCM_Init();
void DCM_Start();
void DCM_MoveToLeft();
void DCM_MoveToRight();
void DCM_MoveToBack();
void DCM_Stop();

#endif /* DCMOTOR_INTERFACE_H_ */