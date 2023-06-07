/*
 * LCD_config.h
 *
 * Created: 30/10/44 12:33:10 ص
 *  Author: lraya
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* Macros For Rs configuration */
#define LCD_RS_PORT         DIO_GROUPB
#define LCD_RS_PIN          PIN1

/* Macros For Rw configuration */
#define LCD_RW_PORT         DIO_GROUPB
#define LCD_RW_PIN          PIN2

/* Macros For En configuration */
#define LCD_EN_PORT         DIO_GROUPB
#define LCD_EN_PIN          PIN3

/* 4 Bit Mode Pins Configurtion */
#define LCD_D4_PORT         DIO_GROUPA
#define LCD_D4_PIN          PIN4

#define LCD_D5_PORT         DIO_GROUPA
#define LCD_D5_PIN          PIN5

#define LCD_D6_PORT         DIO_GROUPA
#define LCD_D6_PIN          PIN6

#define LCD_D7_PORT         DIO_GROUPA
#define LCD_D7_PIN          PIN7
#endif /* LCD_CONFIG_H_ */