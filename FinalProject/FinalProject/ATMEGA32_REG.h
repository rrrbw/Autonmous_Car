/*
* ATMEGA32_REG.h
*
* Created: 29/10/44 06:25:43 م
*  Author: lraya
*/


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/* DIO REGISTERS*/

/* DATA DIRCTION REGISTERS */
#define DDRA           (*(volatile u8*) 0x3A)
#define DDRB           (*(volatile u8*) 0x37)
#define DDRC           (*(volatile u8*) 0x34)
#define DDRD           (*(volatile u8*) 0x31)

/* OUTPUT REGISTERS */
#define PORTA          (*(volatile u8*) 0x3B)
#define PORTB          (*(volatile u8*) 0x38)
#define PORTC          (*(volatile u8*) 0x35)
#define PORTD          (*(volatile u8*) 0x32)

/* INPUT REGISTERS */
#define PINA           (*(volatile u8*) 0x39)
#define PINB           (*(volatile u8*) 0x36)
#define PINC           (*(volatile u8*) 0x33)
#define PIND           (*(volatile u8*) 0x30)

/* TIMER1 REGISTERS*/

// Timer/Counter1 Control Register A
#define TCCR1A             (*(volatile u8*) 0x4F)

// Timer/Counter1 Control Register B
#define TCCR1B             (*(volatile u8*) 0x4E)

// Timer/Counter1
#define TCNT1             (*(volatile u16*) 0x4C)

// Output Compare Register 1 A
#define OCR1A             (*(volatile u16*) 0x4A)

// Output Compare Register 1 B
#define OCR1B             (*(volatile u16*) 0x48)

// Input Capture Register 1
#define ICR1              (*(volatile u16*) 0x46)

#define TIFR              (*(volatile u16*) 0x58)

#endif /* ATMEGA32_REG_H_ */