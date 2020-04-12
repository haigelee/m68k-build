#ifndef HELLO_H_
#define HELLO_H_

// Some basic data types
typedef unsigned char       uint8;		//  8 bits
typedef unsigned short int  uint16;		// 16 bits

typedef volatile uint8      vuint8;		//  8 bits
typedef volatile uint16     vuint16;	// 16 bits

// IPSBAR is the Internal Peripheral System Base Address Register.
// It is set to 0x40000000 on reset so we use that value here.
// Normally you would define this address in your linker script or
// anywhere else that you define your memory map.
uint8 *__IPSBAR = (uint8 *)0x40000000;

// Define some useful macros
#include "mcf5282_clock.h"
#include "mcf5282_uart.h"
#include "mcf5282_gpio.h"

#endif /*HELLO_H_*/
