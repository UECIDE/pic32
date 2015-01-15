/************************************************************************/
/*																		*/
/*	Board_Data.c --	DP32 Customization Data Declarations		        */
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with a CmodCK1 board using a	*/
/* PIC32 part in a 44-pin package.										*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	11/28/2011(GeneA): Created by splitting data out of Board_Defs.h	*/
/*  03/26/2013(KeithV): Modified for DP32 board                          */
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*					Data Tables									*/
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t	port_to_tris_PGM[] = {
	NOT_A_PORT,				//index value 0 is not used

#if defined(_PORTA)
	(uint32_t)&TRISA,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTB)
	(uint32_t)&TRISB,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTC)
	(uint32_t)&TRISC,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTD)
	(uint32_t)&TRISD,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTE)
	(uint32_t)&TRISE,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTF)
	(uint32_t)&TRISF,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTG)
	(uint32_t)&TRISG,
#else
	NOT_A_PORT,
#endif

	NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin. The default mapping is to assign pin numbers
** for every possible port bit in order from PORTA to PORTG.
*/
const uint8_t	digital_pin_to_port_PGM[] = {
    NOT_A_PORT, // 0 = GND
    NOT_A_PORT, // 1 = Vcc
    _IOPORT_PB, // 2 = RB0 (CE)
    _IOPORT_PB, // 3 = RB3 (CSN)
    _IOPORT_PB, // 4 = RB14 (SCK)
    _IOPORT_PB, // 5 = RB2 (MOSI)
    _IOPORT_PB, // 6 = RB1 (MISO)
    _IOPORT_PB, // 7 = RB7 (IRQ)
    _IOPORT_PB, // 8 = RB15 (SCK2)
    _IOPORT_PB, // 9 = RB4
    NOT_A_PORT, // 10 = MCLR
    _IOPORT_PA, // 11 = RA4
    _IOPORT_PB, // 12 = RB8 (SCL)
    _IOPORT_PB, // 13 = RB9 (SDA)
    _IOPORT_PA, // 14 = RA1
    _IOPORT_PA, // 15 = RA0
    _IOPORT_PB, // 16 = RB13 (LED)
    _IOPORT_PA, // 17 = RA3 (PROG)
    _IOPORT_PB, // 18 = RB5 (Pin 10 on proto)
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    NOT_A_PIN,  // 0 = GND
    NOT_A_PIN,  // 1 = Vcc
    _BV( 0),    // 2 = RB0 (CE)
    _BV( 3),    // 3 = RB3 (CSN)
    _BV(14),    // 4 = RB14 (SCK)
    _BV( 2),    // 5 = RB2 (MOSI)
    _BV( 1),    // 6 = RB1 (MISO)
    _BV( 7),    // 7 = RB7 (IRQ)
    _BV(15),    // 8 = RB15 (SCK2)
    _BV( 4),    // 9 = RB4
    NOT_A_PIN,  // 10 = MCLR
    _BV( 4),    // 11 = RA4
    _BV( 8),    // 12 = RB8 (SCL)
    _BV( 9),    // 13 = RB9 (SDA)
    _BV( 1),    // 14 = RA1
    _BV( 0),    // 15 = RA0
    _BV(13),    // 16 = RB13 (LED)
    _BV( 3),    // 17 = RA3 (PROG)
    _BV( 5),    // 18 = RB5 (Pin 10 on proto)
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t	digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
    NOT_ON_TIMER, 
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB0R),
    _PPS_OUT(_PPS_RPB3R),
    _PPS_OUT(_PPS_RPB14R),
    _PPS_OUT(_PPS_RPB2R),
    _PPS_OUT(_PPS_RPB1R),
    _PPS_OUT(_PPS_RPB7R),
    _PPS_OUT(_PPS_RPB15R),
    _PPS_OUT(_PPS_RPB4R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPA4R),
    _PPS_OUT(_PPS_RPB8R),
    _PPS_OUT(_PPS_RPB9R),
    _PPS_OUT(_PPS_RPA1R),
    _PPS_OUT(_PPS_RPA0R),
    _PPS_OUT(_PPS_RPB13R),
    _PPS_OUT(_PPS_RPA3R),
    _PPS_OUT(_PPS_RPB5R),
};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB0),
    _PPS_IN(_PPS_RPB3),
    _PPS_IN(_PPS_RPB14),
    _PPS_IN(_PPS_RPB2),
    _PPS_IN(_PPS_RPB1),
    _PPS_IN(_PPS_RPB7),
    _PPS_IN(_PPS_RPB15),
    _PPS_IN(_PPS_RPB4),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPA4),
    _PPS_IN(_PPS_RPB8),
    _PPS_IN(_PPS_RPB9),
    _PPS_IN(_PPS_RPA1),
    _PPS_IN(_PPS_RPA0),
    _PPS_IN(_PPS_RPB13),
    _PPS_IN(_PPS_RPA3),
    _PPS_IN(_PPS_RPB5),
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
//#if defined(_NOT_USED_)
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    _BOARD_AN2,
    _BOARD_AN5,
    _BOARD_AN10,
    _BOARD_AN4,
    _BOARD_AN3,
    NOT_ANALOG_PIN,
    _BOARD_AN9,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    _BOARD_AN1,
    _BOARD_AN0,
    _BOARD_AN11,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
};
//#endif

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
			//*	Arduino Pin		PIC32 Analog channel
	2,		//*	A0				11
	5,		//*	A1              10
	10,		//*	A2              9
	4,		//*	A3              0
	3,		//*	A4              1
	9,		//*	A5              2
	1,		//*	A6              3
	0,		//*	A7              4
	11,		//*	A8              5
};
//#endif

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    0,
	PIN_OC1,	        // A0, B3, B4, B15, B7  ; B15   RPB15R  = 5  	
	PIN_OC2,	        // A1, B5, B1, B11, B8  ; B8    RPB8R   = 5
	PIN_OC3,	        // A3, B14, B0, B10, B9 ; B9    RPB9R   = 5
	PIN_OC4,	        // A2, B6, A4, B13, B2  ; B2    RPB2R   = 5
	PIN_OC5,	        // A2, B6, A4, B13, B2	; B13   RPB13R  = 6
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// INT0 is not mappable;    RB7
	PIN_INT1,			// A3, B14, B0, B10, B9;    B9  INT1R = RPB9 = 4
	PIN_INT2,			// A2, B6, A4, B13, B2;     B2  INT2R = RPB2 = 4
	PIN_INT3,			// A1, B5, B1, B11, B8;     B8  INT3R = RPB8 = 4
	PIN_INT4			// A0, B3, B4, B15, B7;     B4  INT4R = RPB4 = 2
};

/* ------------------------------------------------------------ */
/*		Include Files for Board Customization Functions			*/
/* ------------------------------------------------------------ */
#if	(OPT_BOARD_INIT != 0)
#include <plib.h>
#endif

/* ------------------------------------------------------------ */
/*				Board Customization Functions					*/
/* ------------------------------------------------------------ */
/*																*/
/* The following can be used to customize the behavior of some	*/
/* of the core API functions. These provide hooks that can be	*/
/* used to extend or replace the default behavior of the core	*/
/* functions. To use one of these functions, add the desired	*/
/* code to the function skeleton below and then set the value	*/
/* of the appropriate compile switch above to 1. This will		*/
/* cause the hook function to be compiled into the build and	*/
/* to cause the code to call the hook function to be compiled	*/
/* into the appropriate core function.							*/
/*																*/
/* ------------------------------------------------------------ */
/***	_board_init
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function is called from the core init() function.
**		This can be used to perform any board specific init
**		that needs to be done when the processor comes out of
**		reset and before the user sketch is run.
*/
#if	(OPT_BOARD_INIT != 0)

void _board_init(void) {

	//	Turn Secondary oscillator off as GPIO is needed
	OSCCONCLR	=	_OSCCON_SOSCEN_MASK;
	
}

#endif

/* ------------------------------------------------------------ */
/***	_board_pinMode
**
**	Parameters:
**		pin		- digital pin number to configure
**		mode	- mode to which the pin should be configured
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the pinMode
**		function. It can perform any special processing needed
**		when setting the pin mode. If this function returns zero,
**		control will pass through the normal pinMode code. If
**		it returns a non-zero value the normal pinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_pinMode(uint8_t pin, uint8_t mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_getPinMode
**
**	Parameters:
**		pin		- digital pin number
**		mode	- pointer to variable to receive mode value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the getPinMode
**		function. It can perform any special processing needed
**		when getting the pin mode. If this function returns zero,
**		control will pass through the normal getPinMode code. If
**		it returns a non-zero value the normal getPinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_getPinMode(uint8_t pin, uint8_t * mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalWrite
**
**	Parameters:
**		pin		- digital pin number
**		val		- value to write to the pin
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal digitalWrite code. If
**		it returns a non-zero value the normal digitalWrite code isn't
**		executed.
*/#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalWrite(uint8_t pin, uint8_t val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalRead
**
**	Parameters:
**		pin		- digital pin number
**		val		- pointer to variable to receive pin value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal digitalRead code. If
**		it returns a non-zero value the normal digitalRead code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalRead(uint8_t pin, uint8_t * val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogRead
**
**	Parameters:
**		pin		- analog channel number
**		val		- pointer to variable to receive analog value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal analogRead code. If
**		it returns a non-zero value the normal analogRead code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogRead(uint8_t pin, int * val) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogReference
**
**	Parameters:
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogReference
**		function. It can perform any special processing needed
**		to set the reference voltage. If this function returns zero,
**		control will pass through the normal analogReference code. If
**		it returns a non-zero value the normal analogReference code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogReference(uint8_t mode) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogWrite
**
**	Parameters:
**		pin		- pin number
**		val		- analog value to write
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal analogWrite code. If
**		it returns a non-zero value the normal analogWrite code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int	_board_analogWrite(uint8_t pin, int val) {

	return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif	// BOARD_DATA_C

/************************************************************************/
