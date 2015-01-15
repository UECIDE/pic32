/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Majenko Technologies SDZL"

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	44
#define	NUM_ANALOG_PINS		15
#define NUM_OC_PINS			6
#define	NUM_IC_PINS			5
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	2   
#define	NUM_SPI_PORTS		1   
#define	NUM_I2C_PORTS		1   

#define NUM_DSPI_PORTS		1
#define	NUM_DTWI_PORTS		1

/* Define I/O devices on the board.
*/
#define	NUM_LED				1
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
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISCbits.TRISC12
#define VIRTUAL_PROGRAM_BUTTON          LATCbits.LATC12

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs.
*/
#define	PIN_LED1	23

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* Define buttons on this board.
*/
#define	PIN_BTN1	13

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

#define PIN_OC1		3
#define	PIN_OC2		5
#define	PIN_OC3		6
#define	PIN_OC4		9
#define	PIN_OC5		10
#define	PIN_OC6		11

#define PIN_IC1		2      
#define PIN_IC2		7      
#define PIN_IC3		8      
#define PIN_IC4		10
#define PIN_IC5		35

//#define	PIN_TCK1	not connected
#define	PIN_TCK2	34      
#define	PIN_TCK3	35      
#define	PIN_TCK4	36      
#define	PIN_TCK5	38

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	3   // uno32 is on 38
#define	PIN_INT1	2
#define PIN_INT2	7
#define	PIN_INT3	8
#define	PIN_INT4	59  // used by MRF and is not on uno32 pin 35.

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = 27;		// for SPI master operation, shared with pin 10
const static uint8_t MOSI = 26;		// PIC32 SDO2
const static uint8_t MISO = 25;		// PIC32 SDI2
const static uint8_t SCK  = 24;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	27      // SS2; 
#define	PIN_DSPI1_SS	7       // SS1; 

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		43      // AN45
#define	A1		42      // AN49
#define A2		41      // AN21
#define A3		40      // AN10
#define A4		39      // AN13
#define A5		38      // AN12
#define A6		37      // AN3
#define A7		36      // AN2
#define A8		35      // AN4
#define A9		34      // AN1
#define A10		33      // AN48
#define A11		32      // AN0
#define A12		31      // AN8
#define A13		30      // AN7
#define A14		29      // AN7

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0		0
#define	PIN_CN1		1
#define	PIN_CN2		2      
#define	PIN_CN3		3      
#define	PIN_CN4		4
#define	PIN_CN5		5
#define	PIN_CN6		6
#define	PIN_CN7		7
#define	PIN_CN8		8
#define	PIN_CN9		9
#define	PIN_CN10	10
#define	PIN_CN11	11
#define	PIN_CN12	12
#define	PIN_CN13	13
#define	PIN_CN14	14      
#define	PIN_CN15	15
#define	PIN_CN16	16
#define	PIN_CN17	17      
#define	PIN_CN18	18      
#define	PIN_CN19	19
#define	PIN_CN20	20
#define	PIN_CN21	21
#define	PIN_CN22	22
#define	PIN_CN23	23      
#define	PIN_CN24	24
#define	PIN_CN25	25
#define	PIN_CN26	26      
#define	PIN_CN27	27      
#define	PIN_CN28	28      
#define	PIN_CN29	29      
#define	PIN_CN30	30
#define	PIN_CN31	31
#define	PIN_CN32	32
#define	PIN_CN33	33
#define	PIN_CN34	34      
#define	PIN_CN35	35
#define	PIN_CN36	36
#define	PIN_CN37	37      
#define	PIN_CN38	38      
#define	PIN_CN39	39
#define	PIN_CN40	40
#define	PIN_CN41	41

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* This section contains the definitions for pin mapping macros that
/* are being redefined for this board variant.
*/

// NUM_ANALOG_PINS == 14, the first analog pin as represented as a digital pin is also 14
// if the analog pin is less than 14, then you can put in the analog number 
// if the pin is greater than 14, it must be a digital pin number.

#undef digitalPinToAnalog
//#define	digitalPinToAnalog(P) (digital_pin_to_analog_PGM[P])
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])


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

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

extern const uint8_t	analog_pin_to_channel_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];

extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];

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
#define	_SER0_BASE      _UART2_BASE_ADDRESS
#define	_SER0_IRQ       _UART2_FAULT_VECTOR
#define	_SER0_VECTOR    _UART2_FAULT_VECTOR
#define	_SER0_IPL_ISR   _UART2_IPL_ISR
#define	_SER0_IPL       _UART2_IPL_IPC
#define	_SER0_SPL       _UART2_SPL_IPC
#define _SER0_TX_OUT    PPS_OUT_U2TX     // (RPF8R = 0b0010)   RF8 -> U4TX   
#define _SER0_TX_PIN    35               // REBIRDY2/RPF8/SCL3/RF8   
#define _SER0_RX_IN     PPS_IN_U2RX      // (U4RXR = 0b1011)    RPF2 -> U4RX
#define _SER0_RX_PIN    34               // EBIRDY3/RPF2/SDA3/RF2 

/* Serial port 1 uses UART1; this goes to pins 39&40
*/
#define	_SER1_BASE		_UART1_BASE_ADDRESS
#define	_SER1_IRQ		_UART1_FAULT_VECTOR
#define	_SER1_VECTOR	_UART1_FAULT_VECTOR
#define	_SER1_IPL_ISR	_UART1_IPL_ISR
#define	_SER1_IPL		_UART1_IPL_IPC
#define	_SER1_SPL		_UART1_SPL_IPC
#define _SER1_TX_OUT    PPS_OUT_U1TX     // (RPF8R = 0b0010)   RF8 -> U4TX   
#define _SER1_TX_PIN    40                // REBIRDY2/RPF8/SCL3/RF8   
#define _SER1_RX_IN     PPS_IN_U1RX      // (U4RXR = 0b1011)    RPF2 -> U4RX
#define _SER1_RX_PIN    39                // EBIRDY3/RPF2/SDA3/RF2 


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard SPI port uses SPI2.
*/
#define	_SPI_BASE		_SPI2_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI2_FAULT_VECTOR
#define	_SPI_RX_IRQ		_SPI2_RX_VECTOR
#define	_SPI_TX_IRQ		_SPI2_TX_VECTOR
#define	_SPI_VECTOR		_SPI2_FAULT_VECTOR
#define _SPI_IPL_ISR	_SPI2_IPL_ISR
#define	_SPI_IPL		_SPI2_IPL_IPC
#define	_SPI_SPL		_SPI2_SPL_IPC

/* SPI pin declarations
*/
#define _SPI_MISO_IN	PPS_IN_SDI2
#define	_SPI_MISO_PIN	MISO
#define _SPI_MOSI_OUT	PPS_OUT_SDO2
#define	_SPI_MOSI_PIN	MOSI


/* The Digilent DSPI library uses these ports.
*/

// same as the default SPI port
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_FAULT_VECTOR
#define	_DSPI0_RX_IRQ		_SPI2_RX_VECTOR
#define	_DSPI0_TX_IRQ		_SPI2_TX_VECTOR
#define	_DSPI0_VECTOR		_SPI2_FAULT_VECTOR
#define _DSPI0_IPL_ISR		_SPI2_IPL_ISR
#define	_DSPI0_IPL			_SPI2_IPL_IPC
#define	_DSPI0_SPL			_SPI2_SPL_IPC

#define _DSPI0_MISO_IN		PPS_IN_SDI2
#define _DSPI0_MISO_PIN		MISO		    // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI0_MOSI_PIN		MOSI		    // RA4  SDO1    RPA4R = SDO1 = 3

#if 0
// 2nd SPI
#define	_DSPI1_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI1_FAULT_VECTOR
#define	_DSPI1_RX_IRQ		_SPI1_RX_VECTOR
#define	_DSPI1_TX_IRQ		_SPI1_TX_VECTOR
#define	_DSPI1_VECTOR		_SPI1_FAULT_VECTOR
#define _DSPI1_IPL_ISR		_SPI1_IPL_ISR
#define	_DSPI1_IPL			_SPI1_IPL_IPC
#define	_DSPI1_SPL			_SPI1_SPL_IPC

#define _DSPI1_MISO_IN		PPS_IN_SDI1
#define _DSPI1_MISO_PIN		36		        // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI1_MOSI_OUT		PPS_OUT_SDO1
#define _DSPI1_MOSI_PIN		35		        // RA4  SDO1    RPA4R = SDO1 = 3

// SD Card
#define	_DSPI2_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI3_FAULT_VECTOR
#define	_DSPI2_RX_IRQ		_SPI3_RX_VECTOR
#define	_DSPI2_TX_IRQ		_SPI3_TX_VECTOR
#define	_DSPI2_VECTOR		_SPI3_FAULT_VECTOR
#define _DSPI2_IPL_ISR		_SPI3_IPL_ISR
#define	_DSPI2_IPL			_SPI3_IPL_IPC
#define	_DSPI2_SPL			_SPI3_SPL_IPC

#define _DSPI2_MISO_IN		PPS_IN_SDI3
#define _DSPI2_MISO_PIN		53		    // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI2_MOSI_OUT		PPS_OUT_SDO3
#define _DSPI2_MOSI_PIN		54		    // RA4  SDO1    RPA4R = SDO1 = 3

// this is the MRF24
#define	_DSPI3_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI4_FAULT_VECTOR
#define	_DSPI3_RX_IRQ		_SPI4_RX_VECTOR
#define	_DSPI3_TX_IRQ		_SPI4_TX_VECTOR
#define	_DSPI3_VECTOR		_SPI4_FAULT_VECTOR
#define _DSPI3_IPL_ISR		_SPI4_IPL_ISR
#define	_DSPI3_IPL			_SPI4_IPL_IPC
#define	_DSPI3_SPL			_SPI4_SPL_IPC

#define _DSPI3_MISO_IN		PPS_IN_SDI2
#define _DSPI3_MISO_PIN		57		    // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI3_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI3_MOSI_PIN		58		    // RA4  SDO1    RPA4R = SDO1 = 3
#endif

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to pins
** A4/A5 pins 18/19 on the analog connector. It is necessary to have jumpers
** JP6/JP8 set appropriately (RG2/RG3 position) to access the I2C
** signals.  
*/
#define	_TWI_BASE		_I2C4_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C4_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C4_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C4_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_4_VECTOR
#define _TWI_IPL_ISR	_I2C4_IPL_ISR
#define _TWI_IPL		_I2C4_IPL_IPC
#define	_TWI_SPL		_I2C4_SPL_IPC

/* Declarations for Digilent DTWI library.
**		DTWI0 is SDA2/SCL2 on A4/A5 pins 18/19 (see above comment).
*/
#define	_DTWI0_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C4_BUS_IRQ
#define	_DTWI0_SLV_IRQ	_I2C4_SLAVE_IRQ
#define	_DTWI0_MST_IRQ	_I2C4_MASTER_IRQ
#define	_DTWI0_VECTOR	_I2C_4_VECTOR
#define	_DTWI0_IPL_ISR	_I2C4_IPL_ISR
#define	_DTWI0_IPL		_I2C4_IPL_IPC
#define	_DTWI0_SPL		_I2C4_SPL_IPC

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*  On MZ parts, ports are defined                              */
/* ------------------------------------------------------------ */

#undef  _PORTA
#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG

/* ------------------------------------------------------------ */

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
