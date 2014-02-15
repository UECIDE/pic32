#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Pulse Rifle FX Module"

#define _USB

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	31
#define	NUM_ANALOG_PINS		7
#define NUM_OC_PINS			5
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		0

#define	NUM_SERIAL_PORTS	3
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define NUM_DSPI_PORTS		1
#define	NUM_DTWI_PORTS		3

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				1
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
/*						Pin Declarations						*/
/* ------------------------------------------------------------ */

#define IO0         0
#define IO1         1
#define IO2         2
#define IO3         3
#define IO4         4
#define IO5         5

#define PIN_LED0    6
#define LED0        6
#define PIN_LED1    7
#define LED1        7

#define AUDIO       8

#define E0          9
#define E1          10
#define E2          11
#define E3          12
#define E4          13
#define E5          14
#define E6          15
#define E7          16
#define E8          17
#define E9          18

#define DC0         19
#define DC1         20

#define DA0         23
#define DA1         22
#define DA2         21
#define DA3         28
#define DA4         27
#define DA5         25
#define DA6         24
#define DA7         26

#define PROG        29

#define AMP         30

#define PIN_OC1		6
#define	PIN_OC2		8
#define	PIN_OC3		15
#define	PIN_OC4		16
#define	PIN_OC5		7

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = 12;		// for SPI master operation, this
									// is actually RD4 (JP4 in RD4 pos)
const static uint8_t MOSI = 11;		// PIC32 SDO2
const static uint8_t MISO = 10;		// PIC32 SDI2
const static uint8_t SCK  =  9;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	12
#define	PIN_DSPI1_SS	13

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		0
#define	A1		1
#define A2		2
#define A3		3
#define A4		4
#define A5		5
#define A6		9

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
    (P) == 0 ? _BV(2) : \
    (P) == 1 ? _BV(3) : \
    (P) == 2 ? _BV(4) : \
    (P) == 3 ? _BV(5) : \
    (P) == 4 ? _BV(6) : \
    (P) == 5 ? _BV(7) : \
    (P) == 7 ? _BV(13) : \
    (P) == 10 ? _BV(17) : \
    (P) == 11 ? _BV(18) : \
    (P) == 12 ? _BV(15) : \
    (P) == 13 ? _BV(14) : \
    (P) == 14 ? _BV(0) : \
    (P) == 17 ? _BV(10) : \
    (P) == 18 ? _BV(9) : \
    (P) == 29 ? _BV(1) : \
    NOT_CN_PIN )

#undef digitalPinToAnalog
#define	digitalPinToAnalog(P) ( \
    (P) == 0 ? 0 : \
    (P) == 1 ? 1 : \
    (P) == 2 ? 2 : \
    (P) == 3 ? 3 : \
    (P) == 4 ? 4 : \
    (P) == 5 ? 5 : \
    (P) == 9 ? 6 : \
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
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1
*/
#define	_SER0_BASE		_UART2_BASE_ADDRESS
#define	_SER0_IRQ		_UART2_ERR_IRQ
#define	_SER0_VECTOR	_UART_2_VECTOR
#define	_SER0_IPL_ISR	_UART2_IPL_ISR
#define	_SER0_IPL		_UART2_IPL_IPC
#define	_SER0_SPL		_UART2_SPL_IPC

#define	_SER1_BASE		_UART1_BASE_ADDRESS
#define	_SER1_IRQ		_UART1_ERR_IRQ
#define	_SER1_VECTOR	_UART_1_VECTOR
#define	_SER1_IPL_ISR	_UART1_IPL_ISR
#define	_SER1_IPL		_UART1_IPL_IPC
#define	_SER1_SPL		_UART1_SPL_IPC

#define	_SER2_BASE		_UART3_BASE_ADDRESS
#define	_SER2_IRQ		_UART3_ERR_IRQ
#define	_SER2_VECTOR	_UART_3_VECTOR
#define	_SER2_IPL_ISR	_UART3_IPL_ISR
#define	_SER2_IPL		_UART3_IPL_IPC
#define	_SER2_SPL		_UART3_SPL_IPC


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard SPI port uses SPI2.
*/
#define	_SPI_BASE		_SPI4_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI4_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI4_RX_IRQ
#define	_SPI_TX_IRQ		_SPI4_TX_IRQ
#define	_SPI_VECTOR		_SPI_4_VECTOR
#define _SPI_IPL_ISR	_SPI4_IPL_ISR
#define	_SPI_IPL		_SPI4_IPL_IPC
#define	_SPI_SPL		_SPI4_SPL_IPC

/* The Digilent DSPI library uses these ports.
*/
#define	_DSPI0_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI4_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI4_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI4_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_4_VECTOR
#define _DSPI0_IPL_ISR		_SPI4_IPL_ISR
#define	_DSPI0_IPL			_SPI4_IPL_IPC
#define	_DSPI0_SPL			_SPI4_SPL_IPC

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to pins
** A4/A5 on the analog connector. It is necessary to have jumpers
** JP6/JP8 set appropriately (RG2/RG3 position) to access the I2C
** signals.
*/
#define	_TWI_BASE		_I2C5_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C5_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C5_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C5_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_5_VECTOR
#define _TWI_IPL_ISR	_I2C5_IPL_ISR
#define _TWI_IPL		_I2C5_IPL_IPC
#define	_TWI_SPL		_I2C5_SPL_IPC

/* Declarations for Digilent DTWI library.
**		DTWI0 is on A4/A5 (see above comment).
**		DTWI1 is on digital pins 38 & 39.
*/
#define	_DTWI0_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C5_BUS_IRQ
#define	_DTWI0_SLV_IRQ	_I2C5_SLAVE_IRQ
#define	_DTWI0_MST_IRQ	_I2C5_MASTER_IRQ
#define	_DTWI0_VECTOR	_I2C_5_VECTOR
#define	_DTWI0_IPL_ISR	_I2C5_IPL_ISR
#define	_DTWI0_IPL		_I2C5_IPL_IPC
#define	_DTWI0_SPL		_I2C5_SPL_IPC

#define	_DTWI1_BASE		_I2C3_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C3_BUS_IRQ
#define	_DTWI1_SLV_IRQ	_I2C3_SLAVE_IRQ
#define	_DTWI1_MST_IRQ	_I2C3_MASTER_IRQ
#define	_DTWI1_VECTOR	_I2C_3_VECTOR
#define	_DTWI1_IPL_ISR	_I2C3_IPL_ISR
#define	_DTWI1_IPL		_I2C3_IPL_IPC
#define	_DTWI1_SPL		_I2C3_SPL_IPC

#define	_DTWI2_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ	_I2C4_BUS_IRQ
#define	_DTWI2_SLV_IRQ	_I2C4_SLAVE_IRQ
#define	_DTWI2_MST_IRQ	_I2C4_MASTER_IRQ
#define	_DTWI2_VECTOR	_I2C_4_VECTOR
#define	_DTWI2_IPL_ISR	_I2C4_IPL_ISR
#define	_DTWI2_IPL		_I2C4_IPL_IPC
#define	_DTWI1_SPL		_I2C3_SPL_IPC


/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */


#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
