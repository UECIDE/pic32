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
#define	NUM_DIGITAL_PINS	101
#define	NUM_ANALOG_PINS		16
#define NUM_OC_PINS			5
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		0

#define	NUM_SERIAL_PORTS	6
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define NUM_DSPI_PORTS		4
#define	NUM_DTWI_PORTS		5

/* Define I/O devices on the board.
*/
#define	NUM_LED				4
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

// no pin           0
#define PIN_G15        1
// Vdd              2
#define PIN_E5         3
#define PIN_E6         4
#define PIN_E7         5
#define PIN_C1         6
#define PIN_C2         7
#define PIN_C3         8
#define PIN_C4         9
#define PIN_G6         10
#define PIN_G7         11
#define PIN_G8         12
// MCLR             13
#define PIN_G9         14
// Vss              15
// Vdd              16
#define PIN_A0         17
#define PIN_E8         18
#define PIN_E9         19
#define PIN_B5         20
#define PIN_B4         21
#define PIN_B3         22
#define PIN_B2         23
#define PIN_B1         24
#define PIN_B0         25

#define PIN_B6         26
#define PIN_B7         27
#define PIN_A9         28
#define PIN_A10        29
// AVdd             30
// AVss             31
#define PIN_B8         32
#define PIN_B9         33
#define PIN_B10        34
#define PIN_B11        35
// Vss              36
// Vdd              37
#define PIN_A1         38
#define PIN_F13        39
#define PIN_F12        40
#define PIN_B12        41
#define PIN_B13        42
#define PIN_B14        43
#define PIN_B15        44
// Vss              45
// Vdd              46
#define PIN_D14        47
#define PIN_D15        48
#define PIN_F4         49
#define PIN_F5         50

#define PIN_F3         51
#define PIN_F2         52
#define PIN_F8         53
// Vbus             54
// Vusb3v3          55
#define PIN_G3         56
#define PIN_G2         57
#define PIN_A2         58
#define PIN_A3         59
#define PIN_A4         60
#define PIN_A5         61
// Vdd              62
#define PIN_C12        63
#define PIN_C15        64
// Vss              65
#define PIN_A14        66
#define PIN_A15        67
#define PIN_D8         68
#define PIN_D9         69
#define PIN_D10        70
#define PIN_D11        71
#define PIN_D0         72
#define PIN_C13        73
#define PIN_C4         74
// Vss              75

#define PIN_D1         76
#define PIN_D2         77
#define PIN_D3         78
#define PIN_D12        79
#define PIN_D13        80
#define PIN_D4         81
#define PIN_D5         82
#define PIN_D6         83
#define PIN_D7         84
// Vcap             85
// Vdd              86
#define PIN_F0         87
#define PIN_F1         88
#define PIN_G1         89
#define PIN_G0         90
#define PIN_A6         91
#define PIN_A7         92
#define PIN_E0         93
#define PIN_E1         94
#define PIN_G14        95
#define PIN_G12        96
#define PIN_G13        97
#define PIN_E2         98
#define PIN_E3         99
#define PIN_E4         100

#define PIN_OC1		72
#define	PIN_OC2		76
#define	PIN_OC3		77
#define	PIN_OC4		78
#define	PIN_OC5		81

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = 69;		// for SPI master operation, this
									// is actually RD4 (JP4 in RD4 pos)
const static uint8_t MOSI = 72;		// PIC32 SDO2
const static uint8_t MISO =  9;		// PIC32 SDI2
const static uint8_t SCK  = 70;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	69
#define	PIN_DSPI1_SS	14
#define PIN_DSPI2_SS    47
#define PIN_DSPI3_SS    40


/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		25
#define	A1		24
#define A2		23
#define A3		22
#define A4		21
#define A5		20
#define A6		26
#define A7      27
#define A8      32
#define A9      33
#define A10     34
#define A11     35
#define A12     41
#define A13     42
#define A14     43
#define A15     44

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
    (P) == 10 ? _BV( 8) : \
    (P) == 11 ? _BV( 9) : \
    (P) == 12 ? _BV(10) : \
    (P) == 14 ? _BV(11) : \
    (P) == 20 ? _BV( 7) : \
    (P) == 21 ? _BV( 6) : \
    (P) == 22 ? _BV( 5) : \
    (P) == 23 ? _BV( 4) : \
    (P) == 24 ? _BV( 3) : \
    (P) == 25 ? _BV( 2) : \
    (P) == 44 ? _BV(12) : \
    (P) == 47 ? _BV(20) : \
    (P) == 48 ? _BV(21) : \
    (P) == 49 ? _BV(17) : \
    (P) == 50 ? _BV(18) : \
    (P) == 73 ? _BV( 1) : \
    (P) == 74 ? _BV( 0) : \
    (P) == 80 ? _BV(19) : \
    (P) == 81 ? _BV(13) : \
    (P) == 82 ? _BV(14) : \
    (P) == 83 ? _BV(15) : \
    (P) == 84 ? _BV(16) : \
    NOT_CN_PIN )

#undef digitalPinToAnalog
#define	digitalPinToAnalog(P) ( \
    (P) == 25 ? 0 : \
    (P) == 24 ? 1 : \
    (P) == 23 ? 2 : \
    (P) == 22 ? 3 : \
    (P) == 21 ? 4 : \
    (P) == 20 ? 5 : \
    (P) == 26 ? 6 : \
    (P) == 27 ? 7 : \
    (P) == 32 ? 8 : \
    (P) == 33 ? 9 : \
    (P) == 34 ? 10 : \
    (P) == 35 ? 11 : \
    (P) == 41 ? 12 : \
    (P) == 42 ? 13 : \
    (P) == 43 ? 14 : \
    (P) == 44 ? 15 : \
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
#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR	_UART_1_VECTOR
#define	_SER0_IPL_ISR	_UART1_IPL_ISR
#define	_SER0_IPL		_UART1_IPL_IPC
#define	_SER0_SPL		_UART1_SPL_IPC

#define	_SER1_BASE		_UART2_BASE_ADDRESS
#define	_SER1_IRQ		_UART2_ERR_IRQ
#define	_SER1_VECTOR	_UART_2_VECTOR
#define	_SER1_IPL_ISR	_UART2_IPL_ISR
#define	_SER1_IPL		_UART2_IPL_IPC
#define	_SER1_SPL		_UART2_SPL_IPC

#define	_SER2_BASE		_UART3_BASE_ADDRESS
#define	_SER2_IRQ		_UART3_ERR_IRQ
#define	_SER2_VECTOR	_UART_3_VECTOR
#define	_SER2_IPL_ISR	_UART3_IPL_ISR
#define	_SER2_IPL		_UART3_IPL_IPC
#define	_SER2_SPL		_UART3_SPL_IPC

#define	_SER3_BASE		_UART4_BASE_ADDRESS
#define	_SER3_IRQ		_UART4_ERR_IRQ
#define	_SER3_VECTOR	_UART_4_VECTOR
#define	_SER3_IPL_ISR	_UART4_IPL_ISR
#define	_SER3_IPL		_UART4_IPL_IPC
#define	_SER3_SPL		_UART4_SPL_IPC

#define	_SER4_BASE		_UART5_BASE_ADDRESS
#define	_SER4_IRQ		_UART5_ERR_IRQ
#define	_SER4_VECTOR	_UART_5_VECTOR
#define	_SER4_IPL_ISR	_UART5_IPL_ISR
#define	_SER4_IPL		_UART5_IPL_IPC
#define	_SER4_SPL		_UART5_SPL_IPC

#define	_SER5_BASE		_UART6_BASE_ADDRESS
#define	_SER5_IRQ		_UART6_ERR_IRQ
#define	_SER5_VECTOR	_UART_6_VECTOR
#define	_SER5_IPL_ISR	_UART6_IPL_ISR
#define	_SER5_IPL		_UART6_IPL_IPC
#define	_SER5_SPL		_UART6_SPL_IPC


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard SPI port uses SPI2.
*/
#define	_SPI_BASE		_SPI1_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI1_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI1_RX_IRQ
#define	_SPI_TX_IRQ		_SPI1_TX_IRQ
#define	_SPI_VECTOR		_SPI_1_VECTOR
#define _SPI_IPL_ISR	_SPI1_IPL_ISR
#define	_SPI_IPL		_SPI1_IPL_IPC
#define	_SPI_SPL		_SPI1_SPL_IPC

/* The Digilent DSPI library uses these ports.
*/
#define	_DSPI0_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI1_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI1_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI1_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_1_VECTOR
#define _DSPI0_IPL_ISR		_SPI1_IPL_ISR
#define	_DSPI0_IPL			_SPI1_IPL_IPC
#define	_DSPI0_SPL			_SPI1_SPL_IPC

#define	_DSPI1_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_2_VECTOR
#define _DSPI1_IPL_ISR		_SPI2_IPL_ISR
#define	_DSPI1_IPL			_SPI2_IPL_IPC
#define	_DSPI1_SPL			_SPI2_SPL_IPC

#define	_DSPI2_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI3_ERR_IRQ
#define	_DSPI2_RX_IRQ		_SPI3_RX_IRQ
#define	_DSPI2_TX_IRQ		_SPI3_TX_IRQ
#define	_DSPI2_VECTOR		_SPI_3_VECTOR
#define _DSPI2_IPL_ISR		_SPI3_IPL_ISR
#define	_DSPI2_IPL			_SPI3_IPL_IPC
#define	_DSPI2_SPL			_SPI3_SPL_IPC

#define	_DSPI3_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI4_ERR_IRQ
#define	_DSPI3_RX_IRQ		_SPI4_RX_IRQ
#define	_DSPI3_TX_IRQ		_SPI4_TX_IRQ
#define	_DSPI3_VECTOR		_SPI_4_VECTOR
#define _DSPI3_IPL_ISR		_SPI4_IPL_ISR
#define	_DSPI3_IPL			_SPI4_IPL_IPC
#define	_DSPI3_SPL			_SPI4_SPL_IPC

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to pins
** A4/A5 on the analog connector. It is necessary to have jumpers
** JP6/JP8 set appropriately (RG2/RG3 position) to access the I2C
** signals.
*/
#define	_TWI_BASE		_I2C1_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C1_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C1_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_1_VECTOR
#define _TWI_IPL_ISR	_I2C1_IPL_ISR
#define _TWI_IPL		_I2C1_IPL_IPC
#define	_TWI_SPL		_I2C1_SPL_IPC

/* Declarations for Digilent DTWI library.
**		DTWI0 is on A4/A5 (see above comment).
**		DTWI1 is on digital pins 38 & 39.
*/
#define	_DTWI0_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C1_BUS_IRQ
#define	_DTWI0_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_DTWI0_MST_IRQ	_I2C1_MASTER_IRQ
#define	_DTWI0_VECTOR	_I2C_1_VECTOR
#define	_DTWI0_IPL_ISR	_I2C1_IPL_ISR
#define	_DTWI0_IPL		_I2C1_IPL_IPC
#define	_DTWI0_SPL		_I2C1_SPL_IPC

#define	_DTWI1_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI1_SLV_IRQ	_I2C2_SLAVE_IRQ
#define	_DTWI1_MST_IRQ	_I2C2_MASTER_IRQ
#define	_DTWI1_VECTOR	_I2C_2_VECTOR
#define	_DTWI1_IPL_ISR	_I2C2_IPL_ISR
#define	_DTWI1_IPL		_I2C2_IPL_IPC
#define	_DTWI1_SPL		_I2C2_SPL_IPC

#define	_DTWI2_BASE		_I2C3_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ	_I2C3_BUS_IRQ
#define	_DTWI2_SLV_IRQ	_I2C3_SLAVE_IRQ
#define	_DTWI2_MST_IRQ	_I2C3_MASTER_IRQ
#define	_DTWI2_VECTOR	_I2C_3_VECTOR
#define	_DTWI2_IPL_ISR	_I2C3_IPL_ISR
#define	_DTWI2_IPL		_I2C3_IPL_IPC
#define	_DTWI1_SPL		_I2C3_SPL_IPC

#define	_DTWI3_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI3_BUS_IRQ	_I2C4_BUS_IRQ
#define	_DTWI3_SLV_IRQ	_I2C4_SLAVE_IRQ
#define	_DTWI3_MST_IRQ	_I2C4_MASTER_IRQ
#define	_DTWI3_VECTOR	_I2C_4_VECTOR
#define	_DTWI3_IPL_ISR	_I2C4_IPL_ISR
#define	_DTWI3_IPL		_I2C4_IPL_IPC
#define	_DTWI3_SPL		_I2C4_SPL_IPC

#define	_DTWI4_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI4_BUS_IRQ	_I2C5_BUS_IRQ
#define	_DTWI4_SLV_IRQ	_I2C5_SLAVE_IRQ
#define	_DTWI4_MST_IRQ	_I2C5_MASTER_IRQ
#define	_DTWI4_VECTOR	_I2C_5_VECTOR
#define	_DTWI4_IPL_ISR	_I2C5_IPL_ISR
#define	_DTWI4_IPL		_I2C5_IPL_IPC
#define	_DTWI4_SPL		_I2C5_SPL_IPC


/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */


#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
