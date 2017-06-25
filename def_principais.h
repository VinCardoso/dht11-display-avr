#ifndef DEF_PRINCIPAIS_H_
#define DEF_PRINCIPAIS_H_

// Use for all programs
#define F_CPU 16000000UL	// CPU Clock
#include <avr/io.h>

// Use for delays
#include <util/delay.h>

// Use to save on memory
#include <avr/pgmspace.h>

// Use to interruptions
#include <avr/interrupt.h>

// Use for LCD
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

// General
#define set_bit(Y, bit_x) (Y|=(1<<bit_x))
#define clr_bit(Y, bit_x) (Y&=~(1<<bit_x))
#define tst_bit(Y, bit_x) (Y&(1<<bit_x))
#define cpl_bit(Y, bit_x) (Y^=(1<<bit_x))

#endif /* DEF_PRINCIPAIS_H_ */