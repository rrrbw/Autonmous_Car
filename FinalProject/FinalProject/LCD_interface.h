/*
 * LCD_interface.h
 *
 * Created: 30/10/44 12:36:06 ص
 *  Author: lraya
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Init               (void);
void LCD_sendCmnd        (u8 Cmnd);
void LCD_sendChar        (u8 data);
void LCD_writeHalfPort  (u8 value);
void LCD_writeString  (const u8* String);
void LCD_SetPos(u8 LineNo, u8 Pos);
void LCD_clear              (void);

#endif /* LCD_INTERFACE_H_ */