#ifndef _DHT_h
#define _DHT_h

#define F_CPU 16000000UL

#define DHT_PORT_OUT PORTD
#define DHT_PORT_IN PIND
#define DHT_PIN PD6

#define SET_BIT(byte, bit) ((byte) |= (1UL << (bit)))

#define CLEAR_BIT(byte,bit) ((byte) &= ~(1UL << (bit)))

#define IS_SET(byte,bit) (((byte) & (1UL << (bit))) >> (bit))

#include <stdint.h>

void initDHT(void);

uint8_t fetchData(uint8_t* arr);

#endif