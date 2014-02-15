#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Velox One"

#define _USB
#define CDCACM_MFG "Majenko Technologies"
#define CDCACM_PRD "Velox One"
#define CDCACM_DESC_SIZE 70

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	41
#define	NUM_ANALOG_PINS		5
#define NUM_OC_PINS			4
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		4

#define	NUM_SERIAL_PORTS	3
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define NUM_DSPI_PORTS		3
#define	NUM_DTWI_PORTS		4

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				5
#define	NUM_SWT				0
#define NUM_SERVO			0

/* Define the number of pins including extended i/o pins.
** These are pins that are not native to the microcontroller, such
** as implemented via an i/o expander or external A/D or D/A.
** This board doesn't have any.
*/
#define	NUM_DIGITAL_PINS_EXTENDED	NUM_DIGITAL_PINS
#define	NUM_ANALOG_PINS_EXTENDED	NUM_ANALOG_PINS

/* ------------------------------------------------------------ */
/*					Virtual Program Button						*/
/* ------------------------------------------------------------ */
//#define USE_VIRTUAL_PROGRAM_BUTTON      1
//#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISCbits.TRISC12
//#define VIRTUAL_PROGRAM_BUTTON          LATCbits.LATC12

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs.
*/
#define	LED0	5
#define	LED1	6

#define IO0 7
#define IO1 8
#define IO2 9
#define IO3 10
#define IO4 11
#define IO5 12
#define IO6 13
#define IO7 14
#define IO8 15
#define IO9 16
#define IO10 17
#define IO11 18
#define IO12 19
#define IO13 20
#define IO14 21
#define IO15 22
#define IO16 23
#define IO17 24

#define DC0 25
#define DC1 26
#define DC2 27
#define DC3 28
#define DC4 29
#define DC5 30
#define DC6 31
#define DC7 32

#define DA0 35
#define DA1 36
#define DA2 39
#define DA3 38
#define DA4 37
#define DA5 34 
#define DA6 33
#define DA7 40
/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* No buttons on this board.
*/

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define OC1		IO3
#define	OC2		IO0
#define	OC3		IO1
#define	OC4		IO1

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = IO14;		// for SPI master operation, this
									// is actually RD4 (JP4 in RD4 pos)
const static uint8_t MOSI = IO15;		// PIC32 SDO2
const static uint8_t MISO = IO16;		// PIC32 SDI2
const static uint8_t SCK  = IO17;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	IO14
#define	PIN_DSPI1_SS	IO5
#define	PIN_DSPI2_SS	IO11

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		IO9
#define	A1		IO10
#define A2		IO11
#define A3		IO12
#define A4		IO13

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* This section contains the definitions for pin mapping macros that
/* are being redefined for this board variant.
*/

#undef digitalPinToCN
#define digitalPinToCN(P) ( \
    (P) == 0 ? _BV( 2) : \
    (P) == 1 ? _BV( 3) : \
    (P) == 2 ? _BV( 4) : \
    (P) == 3 ? _BV( 5) : \
    (P) == 4 ? _BV( 6) : \
    (P) == 14 ? _BV(17) : \
    (P) == 15 ? _BV(18) : \
    (P) == 20 ? _BV( 7) : \
    (P) == 21 ? _BV(11) : \
    (P) == 22 ? _BV(10) : \
    (P) == 23 ? _BV( 9) : \
    (P) == 24 ? _BV( 8) : \
    NOT_CN_PIN )

#undef digitalPinToAnalog
#define	digitalPinToAnalog(P) ( \
    (P) == 16 ? 0 : \
    (P) == 17 ? 1 : \
    (P) == 18 ? 2 : \
    (P) == 19 ? 3 : \
    (P) == 20 ? 4 : \
    NOT_ANALOG_PIN )

#undef analogInPinToChannel
#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

/* ------------------------------------------------------------ */
/*					Data Declarations							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];
extern const uint8_t	analog_pin_to_channel_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			0	//board needs no special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*	Serial Port Declarations				*/
/* ------------------------------------------------------------ */

#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR		_UART_1_VECTOR
#define	_SER0_IPL_ISR		_UART1_IPL_ISR
#define	_SER0_IPL		_UART1_IPL_IPC
#define	_SER0_SPL		_UART1_SPL_IPC

#define	_SER1_BASE		_UART2_BASE_ADDRESS
#define	_SER1_IRQ		_UART2_ERR_IRQ
#define	_SER1_VECTOR		_UART_2_VECTOR
#define	_SER1_IPL_ISR		_UART2_IPL_ISR
#define	_SER1_IPL		_UART2_IPL_IPC
#define	_SER1_SPL		_UART2_SPL_IPC

#define	_SER2_BASE		_UART3_BASE_ADDRESS
#define	_SER2_IRQ		_UART3_ERR_IRQ
#define	_SER2_VECTOR		_UART_3_VECTOR
#define	_SER2_IPL_ISR		_UART3_IPL_ISR
#define	_SER2_IPL		_UART3_IPL_IPC
#define	_SER2_SPL		_UART3_SPL_IPC

#define	_SER3_BASE		_UART4_BASE_ADDRESS
#define	_SER3_IRQ		_UART4_ERR_IRQ
#define	_SER3_VECTOR		_UART_4_VECTOR
#define	_SER3_IPL_ISR		_UART4_IPL_ISR
#define	_SER3_IPL		_UART4_IPL_IPC
#define	_SER3_SPL		_UART4_SPL_IPC

#define	_SER4_BASE		_UART5_BASE_ADDRESS
#define	_SER4_IRQ		_UART5_ERR_IRQ
#define	_SER4_VECTOR		_UART_5_VECTOR
#define	_SER4_IPL_ISR		_UART5_IPL_ISR
#define	_SER4_IPL		_UART5_IPL_IPC
#define	_SER4_SPL		_UART5_SPL_IPC

#define	_SER5_BASE		_UART6_BASE_ADDRESS
#define	_SER5_IRQ		_UART6_ERR_IRQ
#define	_SER5_VECTOR		_UART_6_VECTOR
#define	_SER5_IPL_ISR		_UART6_IPL_ISR
#define	_SER5_IPL		_UART6_IPL_IPC
#define	_SER5_SPL		_UART6_SPL_IPC


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard SPI port uses SPI2.
*/
#define	_SPI_BASE		_SPI2_BASE_ADDRESS
#define _SPI_ERR_IRQ		_SPI2_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI2_RX_IRQ
#define	_SPI_TX_IRQ		_SPI2_TX_IRQ
#define	_SPI_VECTOR		_SPI_2_VECTOR
#define _SPI_IPL_ISR		_SPI2_IPL_ISR
#define	_SPI_IPL		_SPI2_IPL_IPC
#define	_SPI_SPL		_SPI2_SPL_IPC

/* The Digilent DSPI library uses these ports.
*/
#define	_DSPI0_BASE		_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_2_VECTOR
#define _DSPI0_IPL_ISR		_SPI2_IPL_ISR
#define	_DSPI0_IPL		_SPI2_IPL_IPC
#define	_DSPI0_SPL		_SPI2_SPL_IPC

#define	_DSPI1_BASE		_SPI3_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI3_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI3_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI3_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_3_VECTOR
#define _DSPI1_IPL_ISR		_SPI3_IPL_ISR
#define	_DSPI1_IPL		_SPI3_IPL_IPC
#define	_DSPI1_SPL		_SPI3_SPL_IPC

#define	_DSPI2_BASE		_SPI4_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI4_ERR_IRQ
#define	_DSPI2_RX_IRQ		_SPI4_RX_IRQ
#define	_DSPI2_TX_IRQ		_SPI4_TX_IRQ
#define	_DSPI2_VECTOR		_SPI_4_VECTOR
#define _DSPI2_IPL_ISR		_SPI4_IPL_ISR
#define	_DSPI2_IPL		_SPI4_IPL_IPC
#define	_DSPI2_SPL		_SPI4_SPL_IPC

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to pins
** A4/A5 on the analog connector. It is necessary to have jumpers
** JP6/JP8 set appropriately (RG2/RG3 position) to access the I2C
** signals.
*/
#define	_TWI_BASE		_I2C1_BASE_ADDRESS
#define	_TWI_BUS_IRQ		_I2C1_BUS_IRQ
#define	_TWI_SLV_IRQ		_I2C1_SLAVE_IRQ
#define	_TWI_MST_IRQ		_I2C1_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_1_VECTOR
#define _TWI_IPL_ISR		_I2C1_IPL_ISR
#define _TWI_IPL		_I2C1_IPL_IPC
#define	_TWI_SPL		_I2C1_SPL_IPC

/* Declarations for Digilent DTWI library.
**		DTWI0 is on A4/A5 (see above comment).
**		DTWI1 is on digital pins 38 & 39.
*/
#define	_DTWI0_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ		_I2C1_BUS_IRQ
#define	_DTWI0_SLV_IRQ		_I2C1_SLAVE_IRQ
#define	_DTWI0_MST_IRQ		_I2C1_MASTER_IRQ
#define	_DTWI0_VECTOR		_I2C_1_VECTOR
#define	_DTWI0_IPL_ISR		_I2C1_IPL_ISR
#define	_DTWI0_IPL		_I2C1_IPL_IPC
#define	_DTWI0_SPL		_I2C1_SPL_IPC

#define	_DTWI1_BASE		_I2C3_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ		_I2C3_BUS_IRQ
#define	_DTWI1_SLV_IRQ		_I2C3_SLAVE_IRQ
#define	_DTWI1_MST_IRQ		_I2C3_MASTER_IRQ
#define	_DTWI1_VECTOR		_I2C_3_VECTOR
#define	_DTWI1_IPL_ISR		_I2C3_IPL_ISR
#define	_DTWI1_IPL		_I2C3_IPL_IPC
#define	_DTWI1_SPL		_I2C3_SPL_IPC

#define	_DTWI2_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ		_I2C4_BUS_IRQ
#define	_DTWI2_SLV_IRQ		_I2C4_SLAVE_IRQ
#define	_DTWI2_MST_IRQ		_I2C4_MASTER_IRQ
#define	_DTWI2_VECTOR		_I2C_4_VECTOR
#define	_DTWI2_IPL_ISR		_I2C4_IPL_ISR
#define	_DTWI2_IPL		_I2C4_IPL_IPC
#define	_DTWI2_SPL		_I2C4_SPL_IPC

#define	_DTWI3_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI3_BUS_IRQ		_I2C5_BUS_IRQ
#define	_DTWI3_SLV_IRQ		_I2C5_SLAVE_IRQ
#define	_DTWI3_MST_IRQ		_I2C5_MASTER_IRQ
#define	_DTWI3_VECTOR		_I2C_5_VECTOR
#define	_DTWI3_IPL_ISR		_I2C5_IPL_ISR
#define	_DTWI3_IPL		_I2C5_IPL_IPC
#define	_DTWI3_SPL		_I2C5_SPL_IPC


/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */


#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
