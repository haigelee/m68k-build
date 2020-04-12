/*
 * File:    mcf5282_clock.h
 * Purpose: Register and bit definitions
 */

#ifndef __MCF5282_CLOCK_H__
#define __MCF5282_CLOCK_H__

/*********************************************************************
*
* Clock Module
*
*********************************************************************/

/* Read/Write access macros for general use */
#define MCF5282_CLOCK_SYNCR		(*(vuint16 *)(void *)(&__IPSBAR[0x120000]))
#define MCF5282_CLOCK_SYNSR		(*(vuint8  *)(void *)(&__IPSBAR[0x120002]))

/* Bit level definitions and macros */
#define MCF5282_CLOCK_SYNCR_LOLRE			(0x8000)
#define MCF5282_CLOCK_SYNCR_MFD(x)			(((x)&0x0007)<<12)
#define MCF5282_CLOCK_SYNCR_LOCRE			(0x0800)
#define MCF5282_CLOCK_SYNCR_RFD(x)			(((x)&0x0007)<<8)
#define MCF5282_CLOCK_SYNCR_LOCEN			(0x0080)
#define MCF5282_CLOCK_SYNCR_DISCLK			(0x0040)
#define MCF5282_CLOCK_SYNCR_FWKUP			(0x0020)
#define MCF5282_CLOCK_SYNCR_STPMD(x)		(((x)&0x0003)<<2)

#define MCF5282_CLOCK_SYNSR_PLLMODE			(0x80)
#define MCF5282_CLOCK_SYNSR_PLLSEL 			(0x40)
#define MCF5282_CLOCK_SYNSR_PLLREF 			(0x20)
#define MCF5282_CLOCK_SYNSR_LOCKS  			(0x10)
#define MCF5282_CLOCK_SYNSR_LOCK   			(0x08)
#define MCF5282_CLOCK_SYNSR_LOCS   			(0x04)

/********************************************************************/

#endif /* __MCF5282_CLOCK_H__ */
