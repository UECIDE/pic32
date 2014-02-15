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
const uint32_t port_to_tris_PGM[] = {
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


/*

0	S0	    RB0					                AN0     CN2
1	S1	    RB1				            	    AN1     CN3
2	S2	    RB2					                AN2     CN4
3	S3	    RB3					                AN3     CN5
4	S4	    RB4					                AN4     CN6

5	LED0	RF0
6	LED1	RF1

7	IO0	    RD1 	OC2	U4RX	SCK3
8	IO1	    RD2 	OC3	U1RX	SDI3	SDA3
9	IO2	    RD3 	OC4	U1TX	SDO3	SCL3
10	IO3	    RD0 	OC1                                 INT0
11	IO4	    RD10				        SCL1            INT3
12	IO5	    RD9 		U4RX	SS3	    SDA1            INT2
13	IO6	    RD8				                            INT1
14	IO7	    RF4 		U2TX	SDO4	SDA5            CN17
15	IO8	    RF5 		U2RX	SDI4	SCL5            CN18
16	IO9	    RB10					            AN10
17	IO10	RB9					                AN9
18	IO11	RB8 		U5RX	SS4		        AN8
19	IO12	RB14		U5TX	SCK4		    AN14
20	IO13	RB5					                AN5     CN7
21	IO14	RG9			        SS2                     CN11
22	IO15	RG8   			    SDO2	SCL4            CN10
23	IO16	RG7   			    SDI2	SDA4            CN9
24	IO17	RG6 			    SCK2                    CN8

25	DC0	    RD7
26	DC1 	RD6
27	DC2 	RD5
28	DC3 	RD4	    OC5
29	DC4 	RB13               					AN13
30	DC5 	RB15			            		AN15
31	DC6 	RB11					            AN11
32	DC7 	RB12					            AN12

33	DA0 	RE7
34	DA1 	RE6
35	DA2 	RE5
36	DA3 	RE4
37	DA4 	RE0
38	DA5 	RE1
39	DA6 	RE2
40	DA7 	RE3

*/


/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,

	_IOPORT_PF,
	_IOPORT_PF,

	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PF,
	_IOPORT_PF,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PG,
	_IOPORT_PG,
	_IOPORT_PG,
	_IOPORT_PG,

	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PD,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,
	_IOPORT_PB,

	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
	_IOPORT_PE,
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    _BV ( 0 ),
    _BV ( 1 ),
    _BV ( 2 ),
    _BV ( 3 ),
    _BV ( 4 ),

    _BV ( 0 ),
    _BV ( 1 ),

    _BV ( 1 ),
    _BV ( 2 ),
    _BV ( 3 ),
    _BV ( 0 ),
    _BV (10 ),
    _BV ( 9 ),
    _BV ( 8 ),
    _BV ( 4 ),
    _BV ( 5 ),
    _BV (10 ),
    _BV ( 9 ),
    _BV ( 8 ),
    _BV (14 ),
    _BV ( 5 ),
    _BV ( 9 ),
    _BV ( 8 ),
    _BV ( 7 ),
    _BV ( 6 ),

    _BV ( 7 ),
    _BV ( 6 ),
    _BV ( 5 ),
    _BV ( 4 ),
    _BV (13 ),
    _BV (15 ),
    _BV (11 ),
    _BV (12 ),

    _BV ( 7 ),
    _BV ( 6 ),
    _BV ( 5 ),
    _BV ( 4 ),
    _BV ( 0 ),
    _BV ( 1 ),
    _BV ( 2 ),
    _BV ( 3 ),
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,	
	NOT_ON_TIMER,	

	NOT_ON_TIMER,	
	NOT_ON_TIMER,	

	_TIMER_OC2,		
	_TIMER_OC3,		
	_TIMER_OC4,		
	_TIMER_OC1,		
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
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
	10,
	9,
	8,
	14,
	5,
};

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
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

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
