#include "hello.h"

// This is defined by the linker script...
extern const int __interrupt_vector[];

// System clock speed in MHz
#define SYSTEM_CLOCK 64

// Console output on CONSOLE_UART at CONSOLE_BAUD
#define CONSOLE_UART 0
#define CONSOLE_BAUD 115200


/********************************************************************/
void 
mcf5282_pll_init(void)
{
	// Multiply 8Mhz reference crystal by 8 to achieve system clock of 64Mhz
	MCF5282_CLOCK_SYNCR = MCF5282_CLOCK_SYNCR_MFD(2);
	
	while (!(MCF5282_CLOCK_SYNSR & MCF5282_CLOCK_SYNSR_LOCK)) 
	{
		// This line will ensure that the compiler will not optimise away
		// this empty loop, while generating no additional code.
		__asm__ volatile ("");
	}
}

/********************************************************************/
void
mcf5282_uart_init(void)
{
	uint16 divisor;
	
	// Set Port UA to initialize URXD0/URXD1 UTXD0/UTXD1 
	MCF5282_GPIO_PUAPAR = 0x0F;

	// Reset the console UART
	// Mask interrupts, reset the device, and disable Rx and Tx
	MCF5282_UART_UIMR(CONSOLE_UART) = 0;
	MCF5282_UART_UCR(CONSOLE_UART) = MCF5282_UART_UCR_RESET_RX;
	MCF5282_UART_UCR(CONSOLE_UART) = MCF5282_UART_UCR_RESET_TX;
	MCF5282_UART_UCR(CONSOLE_UART) = MCF5282_UART_UCR_RESET_ERROR;
	MCF5282_UART_UCR(CONSOLE_UART) = MCF5282_UART_UCR_RESET_BKCHGINT;
	MCF5282_UART_UCR(CONSOLE_UART) = ( MCF5282_UART_UCR_RESET_MR |
									   MCF5282_UART_UCR_TX_DISABLED |
									   MCF5282_UART_UCR_RX_DISABLED );

	// Set serial parameters to 8, N, 1, no flow control
	MCF5282_UART_UMR(CONSOLE_UART) = ( MCF5282_UART_UMR1_PM_NONE |
									   MCF5282_UART_UMR1_BC_8 );
	MCF5282_UART_UMR(CONSOLE_UART) = ( MCF5282_UART_UMR2_CM_NORMAL |
									   MCF5282_UART_UMR2_STOP_BITS_1 );

	// Calculate the baud rate divider:
	// divider = (f_sys/2) / (32 * baudrate)
	divisor = (uint16)((SYSTEM_CLOCK * 1000000)/(CONSOLE_BAUD * 32));
   
	MCF5282_UART_UBG1(CONSOLE_UART) = (divisor >> 8) & 0xff;
	MCF5282_UART_UBG2(CONSOLE_UART) = divisor & 0xff;
	MCF5282_UART_UCSR(CONSOLE_UART) = ( MCF5282_UART_UCSR_RCS_SYS_CLK |
										MCF5282_UART_UCSR_TCS_SYS_CLK );

	// Enable tx and rx
	MCF5282_UART_UCR(CONSOLE_UART) = ( MCF5282_UART_UCR_RX_ENABLED |
									   MCF5282_UART_UCR_TX_ENABLED );
}

// Transmit a byte. The for loop is a bit heavy handed
// but it works well enough and has the advantage of
// simplicity.
void outbyte(char ch)
{
	int i;
	
	/* UART transmitter */
	for (i = 0; i < 10000; i++)
	{
		if (MCF5282_UART_USR(CONSOLE_UART) & MCF5282_UART_USR_TXRDY)
			break;
	}

	MCF5282_UART_UTB(CONSOLE_UART) = ch;
}

// This is a replacement for the C library's write() function
int write( char *ptr, int len )
{
	while (len--)
	{
		if (*ptr == '\n')
			outbyte('\r');
			
		outbyte(*ptr++);
	}
	
	return 0;
}

// This is defined in cf-crt1.c with weak linkage so this version
// will replace it. We just set the vector base register, make sure
// the system clock is running at the speed we expect and initialise
// the UART we will use for console output.
void hardware_init_hook(void)
{
	// Set the VBR. Copied from default hardware_init_hook()
	__asm__ __volatile__ ("movec.l %0,%/vbr" :: "r" (__interrupt_vector));

	// Set the system clock
	mcf5282_pll_init();
	
	// Initialise the UART that will be used for console output
	mcf5282_uart_init();
}


int main (void)
{
	while (1)
		write( "Hello World!\r\n", 14 );
}

                         
