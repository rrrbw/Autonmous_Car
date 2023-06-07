/*
 * BIT_MATH.h
 *
 * Created: 29/10/44 01:37:11 ص
 *  Author: lraya
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)        REG|=(1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)      REG&=~(1<<BIT_NUM)
#define TOOGLE_BIT(REG,BIT_NUM)     REG^=(1<<BIT_NUM)
#define CHECK_BIT(REG,BIT_NUM)      ((REG>>BIT_NUM)&1)


#endif /* BIT_MATH_H_ */