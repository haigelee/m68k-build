/*
 * File:    mcf5282_uart.h
 * Purpose: Register and bit definitions
 */

#ifndef __MCF5282_UART_H__
#define __MCF5282_UART_H__

/*********************************************************************
*
* Universal Asychronous Receiver/Transmitter (UART) Module
*
*********************************************************************/

/* Read/Write access macros for general use */
#define MCF5282_UART0_UMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0200]))
#define MCF5282_UART0_USR		(*(vuint8  *)(void *)(&__IPSBAR[0x0204]))
#define MCF5282_UART0_UCSR		(*(vuint8  *)(void *)(&__IPSBAR[0x0204]))
#define MCF5282_UART0_UCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0208]))
#define MCF5282_UART0_URB		(*(vuint8  *)(void *)(&__IPSBAR[0x020C]))
#define MCF5282_UART0_UTB		(*(vuint8  *)(void *)(&__IPSBAR[0x020C]))
#define MCF5282_UART0_UIPCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0210]))
#define MCF5282_UART0_UACR		(*(vuint8  *)(void *)(&__IPSBAR[0x0210]))
#define MCF5282_UART0_UISR		(*(vuint8  *)(void *)(&__IPSBAR[0x0214]))
#define MCF5282_UART0_UIMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0214]))
#define MCF5282_UART0_UBG1		(*(vuint8  *)(void *)(&__IPSBAR[0x0218]))
#define MCF5282_UART0_UBG2		(*(vuint8  *)(void *)(&__IPSBAR[0x021C]))
#define MCF5282_UART0_UIP		(*(vuint8  *)(void *)(&__IPSBAR[0x0234]))
#define MCF5282_UART0_UOP1		(*(vuint8  *)(void *)(&__IPSBAR[0x0238]))
#define MCF5282_UART0_UOP0		(*(vuint8  *)(void *)(&__IPSBAR[0x023C]))

#define MCF5282_UART1_UMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0240]))
#define MCF5282_UART1_USR		(*(vuint8  *)(void *)(&__IPSBAR[0x0244]))
#define MCF5282_UART1_UCSR		(*(vuint8  *)(void *)(&__IPSBAR[0x0244]))
#define MCF5282_UART1_UCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0248]))
#define MCF5282_UART1_URB		(*(vuint8  *)(void *)(&__IPSBAR[0x024C]))
#define MCF5282_UART1_UTB		(*(vuint8  *)(void *)(&__IPSBAR[0x024C]))
#define MCF5282_UART1_UIPCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0250]))
#define MCF5282_UART1_UACR		(*(vuint8  *)(void *)(&__IPSBAR[0x0250]))
#define MCF5282_UART1_UISR		(*(vuint8  *)(void *)(&__IPSBAR[0x0254]))
#define MCF5282_UART1_UIMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0254]))
#define MCF5282_UART1_UBG1		(*(vuint8  *)(void *)(&__IPSBAR[0x0258]))
#define MCF5282_UART1_UBG2		(*(vuint8  *)(void *)(&__IPSBAR[0x025C]))
#define MCF5282_UART1_UIP		(*(vuint8  *)(void *)(&__IPSBAR[0x0274]))
#define MCF5282_UART1_UOP1		(*(vuint8  *)(void *)(&__IPSBAR[0x0278]))
#define MCF5282_UART1_UOP0		(*(vuint8  *)(void *)(&__IPSBAR[0x027C]))

#define MCF5282_UART2_UMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0280]))
#define MCF5282_UART2_USR		(*(vuint8  *)(void *)(&__IPSBAR[0x0284]))
#define MCF5282_UART2_UCSR		(*(vuint8  *)(void *)(&__IPSBAR[0x0284]))
#define MCF5282_UART2_UCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0288]))
#define MCF5282_UART2_URB		(*(vuint8  *)(void *)(&__IPSBAR[0x028C]))
#define MCF5282_UART2_UTB		(*(vuint8  *)(void *)(&__IPSBAR[0x028C]))
#define MCF5282_UART2_UIPCR		(*(vuint8  *)(void *)(&__IPSBAR[0x0290]))
#define MCF5282_UART2_UACR		(*(vuint8  *)(void *)(&__IPSBAR[0x0290]))
#define MCF5282_UART2_UISR		(*(vuint8  *)(void *)(&__IPSBAR[0x0294]))
#define MCF5282_UART2_UIMR		(*(vuint8  *)(void *)(&__IPSBAR[0x0294]))
#define MCF5282_UART2_UBG1		(*(vuint8  *)(void *)(&__IPSBAR[0x0298]))
#define MCF5282_UART2_UBG2		(*(vuint8  *)(void *)(&__IPSBAR[0x029C]))
#define MCF5282_UART2_UIP		(*(vuint8  *)(void *)(&__IPSBAR[0x02B4]))
#define MCF5282_UART2_UOP1		(*(vuint8  *)(void *)(&__IPSBAR[0x02B8]))
#define MCF5282_UART2_UOP0		(*(vuint8  *)(void *)(&__IPSBAR[0x02BC]))

#define MCF5282_UART_UMR(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x0200+(x*0x40)]))
#define MCF5282_UART_USR(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x0204+(x*0x40)]))
#define MCF5282_UART_UCSR(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0204+(x*0x40)]))
#define MCF5282_UART_UCR(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x0208+(x*0x40)]))
#define MCF5282_UART_URB(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x020C+(x*0x40)]))
#define MCF5282_UART_UTB(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x020C+(x*0x40)]))
#define MCF5282_UART_UIPCR(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0210+(x*0x40)]))
#define MCF5282_UART_UACR(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0210+(x*0x40)]))
#define MCF5282_UART_UISR(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0214+(x*0x40)]))
#define MCF5282_UART_UIMR(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0214+(x*0x40)]))
#define MCF5282_UART_UBG1(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0218+(x*0x40)]))
#define MCF5282_UART_UBG2(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x021C+(x*0x40)]))
#define MCF5282_UART_UIP(x)		(*(vuint8  *)(void *)(&__IPSBAR[0x0234+(x*0x40)]))
#define MCF5282_UART_UOP1(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x0238+(x*0x40)]))
#define MCF5282_UART_UOP0(x)	(*(vuint8  *)(void *)(&__IPSBAR[0x023C+(x*0x40)]))

/* Bit level definitions and macros */
#define MCF5282_UART_UMR1_RXRTS				(0x80)
#define MCF5282_UART_UMR1_RXIRQ				(0x40)
#define MCF5282_UART_UMR1_ERR				(0x20)
#define MCF5282_UART_UMR1_PM_MULTI_ADDR		(0x1C)
#define MCF5282_UART_UMR1_PM_MULTI_DATA		(0x18)
#define MCF5282_UART_UMR1_PM_NONE			(0x10)
#define MCF5282_UART_UMR1_PM_FORCE_HI		(0x0C)
#define MCF5282_UART_UMR1_PM_FORCE_LO		(0x08)
#define MCF5282_UART_UMR1_PM_ODD			(0x04)
#define MCF5282_UART_UMR1_PM_EVEN			(0x00)
#define MCF5282_UART_UMR1_BC_5				(0x00)
#define MCF5282_UART_UMR1_BC_6				(0x01)
#define MCF5282_UART_UMR1_BC_7				(0x02)
#define MCF5282_UART_UMR1_BC_8				(0x03)

#define MCF5282_UART_UMR2_CM_NORMAL	  		(0x00)
#define MCF5282_UART_UMR2_CM_ECHO	  		(0x40)
#define MCF5282_UART_UMR2_CM_LOCAL_LOOP		(0x80)
#define MCF5282_UART_UMR2_CM_REMOTE_LOOP	(0xC0)
#define MCF5282_UART_UMR2_TXRTS		 		(0x20)
#define MCF5282_UART_UMR2_TXCTS		 		(0x10)
#define MCF5282_UART_UMR2_STOP_BITS_1 		(0x07)
#define MCF5282_UART_UMR2_STOP_BITS_15		(0x08)
#define MCF5282_UART_UMR2_STOP_BITS_2 		(0x0F)
#define MCF5282_UART_UMR2_STOP_BITS(a)		((a)&0x0f)

#define MCF5282_UART_USR_RB					(0x80)
#define MCF5282_UART_USR_FE					(0x40)
#define MCF5282_UART_USR_PE					(0x20)
#define MCF5282_UART_USR_OE					(0x10)
#define MCF5282_UART_USR_TXEMP				(0x08)
#define MCF5282_UART_USR_TXRDY				(0x04)
#define MCF5282_UART_USR_FFULL				(0x02)
#define MCF5282_UART_USR_RXRDY				(0x01)

#define MCF5282_UART_UCSR_RCS_SYS_CLK		(0xD0)
#define MCF5282_UART_UCSR_RCS_DTIN16		(0xE0)
#define MCF5282_UART_UCSR_RCS_DTIN			(0xF0)
#define MCF5282_UART_UCSR_TCS_SYS_CLK		(0x0D)
#define MCF5282_UART_UCSR_TCS_DTIN16		(0x0E)
#define MCF5282_UART_UCSR_TCS_DTIN			(0x0F)

#define MCF5282_UART_UCR_NONE				(0x00)
#define MCF5282_UART_UCR_STOP_BREAK			(0x70)
#define MCF5282_UART_UCR_START_BREAK		(0x60)
#define MCF5282_UART_UCR_RESET_BKCHGINT		(0x50)
#define MCF5282_UART_UCR_RESET_ERROR		(0x40)
#define MCF5282_UART_UCR_RESET_TX			(0x30)
#define MCF5282_UART_UCR_RESET_RX			(0x20)
#define MCF5282_UART_UCR_RESET_MR			(0x10)
#define MCF5282_UART_UCR_TX_DISABLED		(0x08)
#define MCF5282_UART_UCR_TX_ENABLED			(0x04)
#define MCF5282_UART_UCR_RX_DISABLED		(0x02)
#define MCF5282_UART_UCR_RX_ENABLED			(0x01)

#define MCF5282_UART_UIPCR_COS				(0x10)
#define MCF5282_UART_UIPCR_CTS				(0x01)

#define MCF5282_UART_UACR_IEC				(0x01)

#define MCF5282_UART_UISR_COS				(0x80)
#define MCF5282_UART_UISR_ABC				(0x40)
#define MCF5282_UART_UISR_RXFIFO			(0x20)
#define MCF5282_UART_UISR_TXFIFO			(0x10)
#define MCF5282_UART_UISR_RXFTO				(0x08)
#define MCF5282_UART_UISR_DB				(0x04)
#define MCF5282_UART_UISR_RXRDY				(0x02)
#define MCF5282_UART_UISR_TXRDY				(0x01)

#define MCF5282_UART_UIMR_COS				(0x80)
#define MCF5282_UART_UIMR_DB				(0x04)
#define MCF5282_UART_UIMR_FFULL				(0x02)
#define MCF5282_UART_UIMR_TXRDY				(0x01)

#define MCF5282_UART_UIP_CTS				(0x01)

#define MCF5282_UART_UOP_RTS				(0x01)

/********************************************************************/

#endif /* __MCF5282_UART_H__ */
