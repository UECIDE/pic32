//************************************************************************
//	pic32_cdcacm.c
//
// this file implements a CDC/ACM transport on top of the usb driver module.
//
// This file originated from the cpustick.com skeleton project from
// http://www.cpustick.com/downloads.htm and was originally written
// by Rich Testardi; please preserve this reference and share bug
// fixes with rich@testardi.com.
//************************************************************************
//*	this code is best viewed with tabs set to 4 spaces
//************************************************************************
//*	Edit History
//************************************************************************
//*	Jun 23,	2011	<MLS> Got code from Rich, started on Serial support for Arduino/chipkit
//*	Jun 24,	2011	<MLS> USBSerial working completely
//*	Jul  2,	2011	<MLS/RT> Got the fast transmit buffering working (thanks Rich)
//*	Aug  2,	2011	<MKS/RT> added code to discard if not attached.
//************************************************************************


//#include "main.h"
#include	"HardwareSerial.h"
//*	make sure the cpu selected has a usb port
#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)


#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


#include	"HardwareSerial_cdcacm.h"
#include	"HardwareSerial_usb.h"

#define PACKET_SIZE	64

#ifndef CDCACM_MAN 
#define CDCACM_MAN "www.cpustick.com"
#endif

#ifndef CDCACM_PROD
#define CDCACM_PROD "stk500v2"
#endif

#ifndef CDCACM_SER
#define CDCACM_SER ""
#endif

// We have allocated 8 PIDs to you from A660 to A667 (hex).
// The PIDs must be used with VID 0403.
// We use A660; Cale Fallgatter uses A661; Jim Donelson uses A667;
// Avrbootloader group (this project) uses A662.
#ifndef CDCACM_VID
#define CDCACM_VID	0x0403
#endif

#ifndef CDCACM_PID
#define CDCACM_PID	0xA662
#endif

#ifndef CDCACM_RID
#define CDCACM_RID	0x0180
#endif

// Input types
#define IN_CONSTANT 0
#define IN_DATA     1

#define IN_ARRAY    0
#define IN_VARIABLE 2

#define IN_ABS      0
#define IN_REL      4

#define IN_NOWRAP   0
#define IN_WRAP     8

#define IN_LIN      0
#define IN_NONLIN   16

#define IN_PREF     0
#define IN_NOPREF   32

#define IN_NONULL   0
#define IN_NULL     64

#define IN_NONVOL   0
#define IN_VOL      128

// Usage pages
#define GENERIC_DESKTOP 0x01
#define PAGE_KEYBOARD   0x02
#define PAGE_KEYS       0x07
#define PAGE_BUTTONS    0x09

// Master usages
#define KEYBOARD        0x01
#define MOUSE           0x02

// Mouse Usages
#define POINTER         0x01
#define AXIS_X          0x30
#define AXIS_Y          0x31
#define AXIS_WHEEL      0x38

// Collections
#define COLL_PHYSICAL       0x00
#define COLL_APPLICATION    0x01
#define COLL_LOGICAL        0x02
#define COLL_REPORT         0x03
#define COLL_NAMEDARRAY     0x04
#define COLL_USAGESWITCH    0x05
#define COLL_USAGEMOD       0x06

// Commmands 
#define USAGE_PAGE(X)       0x05, (X)
#define USAGE(X)            0x09, (X)
#define COLLECTION(X)       0xA1, (X)
#define REPORT_ID(X)        0x85, (X)
#define USAGE_MINIMUM(X)    0x19, (X)
#define USAGE_MAXIMUM(X)    0x29, (X)
#define LOGICAL_MINIMUM(X)  0x15, (X)
#define LOGICAL_MAXIMUM(X)  0x25, (X)
#define REPORT_COUNT(X)     0x95, (X)
#define REPORT_SIZE(X)      0x75, (X)
#define CMD_INPUT(X)        0x81, (X)
#define CMD_OUTPUT(X)       0x91, (X)

#define END_COLLECTION      0xC0

static const byte hid_report_descriptor[] = {

    //  Mouse
    USAGE_PAGE(GENERIC_DESKTOP),
    USAGE(MOUSE),
    COLLECTION(COLL_APPLICATION),
        USAGE(POINTER),
        COLLECTION(COLL_PHYSICAL),
            REPORT_ID(1),
            USAGE_PAGE(PAGE_BUTTONS),
            USAGE_MINIMUM(1),
            USAGE_MAXIMUM(3),
            LOGICAL_MINIMUM(0),
            LOGICAL_MAXIMUM(1),
            REPORT_COUNT(3),
            REPORT_SIZE(1),
            CMD_INPUT(2),
            REPORT_COUNT(1),
            REPORT_SIZE(5),
            CMD_INPUT(3),
            USAGE_PAGE(GENERIC_DESKTOP),
            USAGE(AXIS_X),
            USAGE(AXIS_Y),
            USAGE(AXIS_WHEEL),
            LOGICAL_MINIMUM(-127),
            LOGICAL_MAXIMUM(127),
            REPORT_SIZE(8),
            REPORT_COUNT(3),
            CMD_INPUT(6),
        END_COLLECTION,
    END_COLLECTION,

    //  Keyboard
    USAGE_PAGE(GENERIC_DESKTOP),
    USAGE(KEYBOARD),
    COLLECTION(COLL_APPLICATION),
        REPORT_ID(2),
        USAGE_PAGE(PAGE_KEYBOARD),

        USAGE_MINIMUM(0xE0),
        USAGE_MAXIMUM(0xE7),
        LOGICAL_MINIMUM(0),
        LOGICAL_MAXIMUM(1),
        REPORT_SIZE(1),

        REPORT_COUNT(8),
        CMD_INPUT(2),
        REPORT_COUNT(1),
        REPORT_SIZE(8),
        CMD_INPUT(3),

        // LED report components
        REPORT_COUNT(5),
        REPORT_SIZE(1),
        USAGE_PAGE(0x08),
        USAGE_MINIMUM(1),
        USAGE_MAXIMUM(5),
        CMD_OUTPUT(2),
        REPORT_COUNT(1),
        REPORT_SIZE(3),
        CMD_OUTPUT(1),
        // end LED report components

        REPORT_COUNT(6),
        REPORT_SIZE(8),
        LOGICAL_MINIMUM(0),
        LOGICAL_MAXIMUM(101),
        USAGE_PAGE(PAGE_KEYS),

        USAGE_MINIMUM(0),
        USAGE_MAXIMUM(101),
        CMD_INPUT(0),
    END_COLLECTION,

    0x06, 0x00, 0xFF,       // Usage Page = 0xFF00 (Vendor Defined Page 1)
    0x09, 0x01,             // Usage (Vendor Usage 1)
    0xA1, 0x01,             // Collection (Application)
    REPORT_ID(3),

    0x19, 0x00,             // Usage Minimum
    0x29, 0x40,             // Usage Maximum 64 input usages total (0x01 to 0x40)
    0x15, 0x00,             // Logical Minimum (data bytes in the report may have minimum value = 0x00)
    0x26, 0xFF, 0x00,       // Logical Maximum (data bytes in the report may have maximum value = 0x00FF = unsigned 255)
    0x75, 0x08,             // Report Size: 8-bit field size
    0x95, 0x40,             // Report Count: Make sixty-four 8-bit fields (the next time the parser hits an "Input", "Output", or "Feature" item)
    0x81, 0x00,             // Input (Data, Array, Abs): Instantiates input packet fields based on the above report size, count, logical min/max, and usage.

    0x19, 0x01,             // Usage Minimum
    0x29, 0x40,             // Usage Maximum 64 output usages total (0x01 to 0x40)
    0x91, 0x00,             // Output (Data, Array, Abs): Instantiates output packet fields.  Uses same report size and count as "Input" fields, since nothing new/different was specified to the parser since the "Input" item.

    0xC0,                   // End Collection


#if 0
    //  RAW HID
    USAGE_PAGE(0xC0), 0xFF,
    USAGE(0x00), 0xC0,
    COLLECTION(COLL_APPLICATION),
        REPORT_ID(3),
        REPORT_SIZE(8),
        LOGICAL_MINIMUM(0),
        LOGICAL_MAXIMUM(255),
        REPORT_COUNT(64),
        USAGE(1),
        CMD_INPUT(2),
        REPORT_COUNT(64),
        USAGE(2),
        CMD_OUTPUT(2),
    END_COLLECTION
#endif
};


static const byte cdcacm_device_descriptor[] = {
	18,					// length
	0x01,				// device descriptor
	0x01, 0x01,			// 1.1
	0x02, 0x00, 0x00,	// class (cdc), subclass, protocol
	PACKET_SIZE,		// packet size
	CDCACM_VID%0x100, CDCACM_VID/0x100, CDCACM_PID%0x100, CDCACM_PID/0x100,
	CDCACM_RID%0x100, CDCACM_RID/0x100,
	0x01,				// manufacturer (string)
	0x02,				// product (string)
	0x03,				// sn (string)
	0x01				// num configurations
};

static const byte cdcacm_configuration_descriptor[] = {
	9,			// length
	0x02,		// configuration descriptor
	92, 0,		// total length
	0x03,		// num interfaces
	0x01,		// configuration value
	0x00,		// configuration (string)
	0x80,		// attributes
	250,		// 500 mA                           9

	9,			// length
	0x04,		// interface descriptor
	0x00,		// interface number
	0x00,		// alternate
	0x01,		// num endpoints
	0x02,		// interface class (comm)
	0x02,		// subclass (acm)
	0x00,		// protocol (none)
	0x00,		// interface (string)               18

	5,			// length
	0x24,		// header functional descriptor
	0x00,
	0x10, 0x01,                         //          23

	4,			// length
	0x24,		// abstract control model descriptor
	0x02,
	0x00,                               //          27

	5,			// length
	0x24,		// union functional descriptor
	0x06,
	0x00,		// comm
	0x01,		// data                             32

	5,			// length
	0x24,		// call management functional descriptor
	0x01,
	0x00,
	0x01,                       //                  37

	7,			// length
	0x05,		// endpoint descriptor
	0x81,		// endpoint IN address
	0x03,		// attributes: interrupt
	0x10, 0x00,	// packet size
	64  ,		// interval (ms)                44
	
	9,			// length
	0x04,		// interface descriptor
	0x01,		// interface number
	0x00,		// alternate
	0x02,		// num endpoints
	0x0a,		// interface class (data)
	0x00,		// subclass
	0x00,		// protocol
	0x00,		// interface (string)                   53

	7,			// length
	0x05,		// endpoint descriptor
	0x02,		// endpoint OUT address
	0x02,		// attributes: bulk
	0x40, 0x00,		// packet size
	0x00,		// interval (ms)                    60

	7,			// length
	0x05,		// endpoint descriptor
	0x83,		// endpoint OUT address
	0x02,		// attributes: bulk
	0x40, 0x00,	// packet size
	0x00,		// interval (ms)                    67

    // HID
	9,			// length
	0x04,		// interface descriptor
	0x02,		// interface number
	0x00,		// alternate
	0x01,		// num endpoints    ///// 1
	0x03,		// interface class (comm)
	0x02,		// subclass (acm)
	0x00,		// protocol (none)
	0x00,		// interface (string)               76

    // HID device descriptor
    9,          // length
    33,         // descriptor type
    1, 1,        // Version
    0,          // country code
    1,          // Num descriptors
    34,         // Descriptor type: report
    sizeof(hid_report_descriptor),        // length
    0,              //                          85
#if 1
    7,          // length
    0x05,       // endpoint descriptor
    0x84,       // endpoint OUT address
    0x03,       // attributes: interrupt
    0x40, 0x00, // packet size
    0x01,       // interval (ms)            92
#endif
};

//static const byte cdcacm_string_descriptor[] = {
//	4,			// length
//	0x03,		// string descriptor
//	0x09, 0x04,	// english (usa)
//
//	34,			// length
//	0x03,		// string descriptor
//	'w', 0, 'w', 0, 'w', 0, '.', 0, 'c', 0, 'p', 0, 'u', 0, 's', 0, 't', 0, 'i', 0, 'c', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0,
//
//	18,			// length
//	0x03,		// string descriptor
//	'S', 0, 't', 0, 'k', 0, '5', 0, '0', 0, '0', 0, 'v', 0, '2', 0,
//};

static byte *cdcacm_string_descriptor;

boolean gCdcacm_active;


//*	cbfn	=	Call Back FuNction (first letter 'g' means this variable is a global)
static	cdcacm_reset_cbfn		gReset_cbfn;
static	cdcacm_storedata_cbfn	gStoredata_cbfn;

static byte			gTXbuffer[PACKET_SIZE];	// packet from host

//#define NRX	16
#define NRX	4		//*	save on RAM, does not seem to slow it down any

// N.B. -1 forces short packets
static byte			gRXbuffer[NRX][PACKET_SIZE-1]; // packets to host
static int			gRX_length[NRX];
static volatile byte			gRX_in;
static volatile byte			gRX_out;

boolean      gConnected = false;

void setStrings(char *man, char *prod, char *ser) {
    int i;
    int pos = 0;
    if (cdcacm_string_descriptor) {
        free(cdcacm_string_descriptor);
    }
    int totlen = 4;
    totlen += strlen(man) * 2 + 2;
    totlen += strlen(prod) * 2 + 2;
    totlen += strlen(ser) * 2 + 2;

    cdcacm_string_descriptor = malloc(totlen);

    // Header
    cdcacm_string_descriptor[pos++] = 0x04;
    cdcacm_string_descriptor[pos++] = 0x03;
    cdcacm_string_descriptor[pos++] = 0x09;
    cdcacm_string_descriptor[pos++] = 0x04;

    // Manufacturer
    
    cdcacm_string_descriptor[pos++] = strlen(man)*2 + 2;
    cdcacm_string_descriptor[pos++] = 0x03;
    for (i = 0; i < strlen(man); i++) {
        cdcacm_string_descriptor[pos++] = man[i];
        cdcacm_string_descriptor[pos++] = 0;
    }

    // Product
    cdcacm_string_descriptor[pos++] = strlen(prod)*2 + 2;
    cdcacm_string_descriptor[pos++] = 0x03;
    for (i = 0; i < strlen(prod); i++) {
        cdcacm_string_descriptor[pos++] = prod[i];
        cdcacm_string_descriptor[pos++] = 0;
    }

    // Serial number
    cdcacm_string_descriptor[pos++] = strlen(ser)*2 + 2;
    cdcacm_string_descriptor[pos++] = 0x03;
    for (i = 0; i < strlen(ser); i++) {
        cdcacm_string_descriptor[pos++] = ser[i];
        cdcacm_string_descriptor[pos++] = 0;
    }

	usb_string_descriptor(cdcacm_string_descriptor, totlen);
}

//*******************************************************************************
static	int	SPLX(int level)
{
	int csr;
	int oldlevel;

	// get the sr
	csr	=	_CP0_GET_STATUS();

	oldlevel	=	(csr >> 10) & 7;
	if (level <= 0)
	{
		// we're going down
		level	=	-level;
	}
	else
	{
		// we're going up
		level	=	MAX(level, oldlevel);
	}
	assert(level >= 0 && level <= 7);
	csr	=	(csr & 0xffffe3ff) | (level << 10);

	// update the sr
	_CP0_SET_STATUS(csr);

	assert(oldlevel >= 0 && oldlevel <= 7);
	return -oldlevel;
}


//************************************************************************
// this function waits for space to be available in the transport
// buffers and then prints the specified line to the CDCACM transport
// console.
//************************************************************************
void	cdcacm_print(const byte *buffer, int length)
{
    int availableBuffers;
    int buffersNeeded;
    int m;
    int previousInterrutLevel;
		
	// ASSERT(length);

	if (! gCdcacm_attached || !gConnected || (length <= 0))
	{
		return;
	}

	// figure out how many buffers we need
	buffersNeeded	=	(length + sizeof(gRXbuffer[0]) - 1) / sizeof(gRXbuffer[0]) + 1;

	previousInterrutLevel	=	SPLX(7);

	// forever...
	m	=	0;
	for (;;)
	{
		// compute the number of available buffers
		availableBuffers	=	(gRX_out + NRX-gRX_in) % NRX;
		if (! availableBuffers)
		{
			availableBuffers	=	NRX;
		}

		// if we have as many as we need...
		if (availableBuffers >= buffersNeeded)
		{
			// we're ready to go
			break;
		}
#ifdef _USE_USB_IRQ_
		SPLX(previousInterrutLevel);

		delay(1);
		if (m++ > 1000)
		{
			return;
		}
		previousInterrutLevel	=	SPLX(7);
#else
		usb_isr();
#endif
	}

	// while there is more data to send...
	do
	{
		// append to next gRX_in(s)
		m	=	MIN(length, sizeof(gRXbuffer[gRX_in])-gRX_length[gRX_in]);

		assert(gRX_length[gRX_in]+m <= sizeof(gRXbuffer[gRX_in]));
		memcpy(gRXbuffer[gRX_in]+gRX_length[gRX_in], buffer, m);

		gRX_length[gRX_in]	+=	m;

		buffer	+=	m;
		length	-=	m;

		// if this is the first buffer of the transfer or if the transfer will need more buffers...
		if (availableBuffers == NRX || length)
		{
			// advance to the next buffer
			assert(length ? gRX_length[gRX_in] == sizeof(gRXbuffer[gRX_in]) : true);
			gRX_in	=	(gRX_in+1)%NRX;
			assert(gRX_in != gRX_out);
			assert(! gRX_length[gRX_in]);
		}
	} while (length);

	// if this is the first buffer of the transfer...
	if (availableBuffers == NRX)
	{
		// start the rx ball rolling
		assert(gRX_out != gRX_in);
		assert(gRX_length[gRX_out] > 0 && gRX_length[gRX_out] < PACKET_SIZE);
		usb_device_enqueue(bulk_in_ep, 1, gRXbuffer[gRX_out], gRX_length[gRX_out]);
	}

	SPLX(previousInterrutLevel);
}


/* Mandatory class specific requests. */
#define CDCRQ_SEND_ENCAPSULATED_COMMAND 0x0
#define CDCRQ_GET_ENCAPSULATED_RESPONSE 0x1

/* Optional class specific requests. Windows usbser.sys depends on these. */
#define CDCRQ_SET_LINE_CODING			0x20
#define CDCRQ_GET_LINE_CODING			0x21
#define CDCRQ_SET_CONTROL_LINE_STATE	0x22
#define CDCRQ_SEND_BREAK				0x23

#define FILL_LINE_CODING(bps, stops, parity, data_bits) \
	(bps) & 0xff, ((bps)>>8) & 0xff, ((bps)>>16) & 0xff, ((bps)>>24) & 0xff, (uint8)(stops), (uint8)(parity), (uint8)(data_bits)

static uint8 line_coding[7] =
{
	FILL_LINE_CODING(115200, 0, 0, 8) /* Default is 115200 BPS and 8N1 format. */
};

extern void hid_push(uint8_t *data, int len);
extern uint8_t hid_call_feature(uint8_t f, uint8_t rw, uint8_t *d, uint8_t l);
extern void keyboard_set_leds(uint8_t);

#define HID_OUTPUT 2
#define HID_SET_FEATURE 3

#define HID_READ 0
#define HID_WRITE 1

//************************************************************************
// this function implements the CDCACM usb setup control transfer.
//************************************************************************
static int	cdcacm_control_transfer(struct setup *setup, byte *buffer, int length)
{
#if SODEBUG
	if ((setup->requesttype & 0x60) != (SETUP_TYPE_CLASS<<5))
	{
		return 0;
	}
	if ((setup->requesttype & 0x1f) != (SETUP_RECIP_INTERFACE<<0))
	{
		return 0;
	}
	if (setup->index != 0 /*comm*/)
	{
		return 0;
	}
#endif
	switch(setup->request)
	{
        case 9: // Incoming HID report
			assert(! (setup->requesttype & 0x80));
            if ((setup->value >> 8) == HID_OUTPUT) {
                assert(length <= 64);
                if ((setup->value & 0xFF) == 0) {
                    hid_push(buffer+1, length-1);
                    length = 0;
                } else if ((setup->value & 0xFF) == 2) { // Keyboard report
                    keyboard_set_leds(buffer[1]);
                    // Keyboard LEDs are in buffer[1].
                    length = 0;
                } else {
                    length = 0;
                }
            } else if ((setup->value >> 8) == HID_SET_FEATURE) {
                length = hid_call_feature(setup->value & 0xFF, HID_WRITE, buffer, length);
            } else {
                length = 0;
            }
            break;
		case CDCRQ_SEND_ENCAPSULATED_COMMAND:
			assert(! (setup->requesttype & 0x80));
            length = hid_call_feature(setup->value & 0xFF, HID_READ, buffer, length);
            length = 0;
			break;
		case CDCRQ_GET_ENCAPSULATED_RESPONSE:
			assert(setup->requesttype & 0x80);
			assert(length <= 64);
            length = hid_call_feature(setup->value & 0xFF, HID_READ, buffer, length);
			break;
		case CDCRQ_SET_LINE_CODING:
			assert(! (setup->requesttype & 0x80));
			assert(length == sizeof(line_coding));
			memcpy(line_coding, buffer, sizeof(line_coding));
			length	=	0;
			break;
		case CDCRQ_GET_LINE_CODING:
			assert(setup->requesttype & 0x80);
			assert(length == sizeof(line_coding));
			memcpy(buffer, line_coding, sizeof(line_coding));
			break;
		case CDCRQ_SET_CONTROL_LINE_STATE:
			assert(! (setup->requesttype & 0x80));
            gConnected = setup->value > 0;
			length	=	0;
			break;
		case CDCRQ_SEND_BREAK:
			length	=	0;
			break;
		default:
			assert(0);
			length	=	0;
			break;
	}
	
	return length;
}


static boolean gWaiting;

//************************************************************************
// this function acknowledges receipt of an CDCACM command from upper
// level code.
//************************************************************************
void	cdcacm_command_ack(void)
{
	int x;

	x	=	SPLX(7);

	if (gWaiting)
	{
		// start the tx ball rolling
		usb_device_enqueue(bulk_out_ep, 0, gTXbuffer, sizeof(gTXbuffer));
		gWaiting	=	false;
	}

	SPLX(x);
}

//************************************************************************
// this function implements the CDCACM usb bulk transfer.
//************************************************************************
static int	cdcacm_bulk_transfer(boolean in, byte *buffer, int length)
{
	if (! in)
	{
		gCdcacm_active	=	true;
		
		// accumulate commands
		if (gStoredata_cbfn(buffer, length))
		{
			// keep the tx ball rolling
			usb_device_enqueue(bulk_out_ep, 0, gTXbuffer, sizeof(gTXbuffer));
		}
		else
		{
			// drop the ball
			gWaiting	=	true;
		}
	}
	else
	{
		gRX_length[gRX_out]	=	0;
		gRX_out	=	(gRX_out+1)%NRX;

		// if there is more data to transfer...
		if (gRX_length[gRX_out] > 0)
		{
			if (gRX_in == gRX_out)
			{
				gRX_in	=	(gRX_in+1)%NRX;
				assert(gRX_in != gRX_out);
				assert(gRX_length[gRX_in] == 0);
			}

			// keep the rx ball rolling
			assert(gRX_out != gRX_in);
			assert(gRX_length[gRX_out] > 0 && gRX_length[gRX_out] < PACKET_SIZE);
			usb_device_enqueue(bulk_in_ep, 1, gRXbuffer[gRX_out], gRX_length[gRX_out]);
		}
	}

	return 0;
}

//************************************************************************
// this function is called by the usb driver when the USB device
// is reset.
//************************************************************************
static void	cdcacm_reset(void)
{
	int i;

	for (i=0; i < NRX; i++)
	{
		gRX_length[i]	=	0;
	}

	// prepare for rx
	usb_device_enqueue(bulk_in_ep, -1, NULL, 0);
	usb_device_enqueue(int_ep, -1, NULL, 0);
	
	// start the tx ball rolling
	usb_device_enqueue(bulk_out_ep, 0, gTXbuffer, sizeof(gTXbuffer));
	
	assert(gReset_cbfn);
	gReset_cbfn();
    static uint8_t dummyData[9];
    dummyData[0] = 2;
    usb_device_enqueue(hid_ep, 1, dummyData, 9);
}

//************************************************************************
static int __attribute__((unused)) check(const byte *descriptor, int length)
{
	int i;
	int j;

	i	=	0;
	j	=	0;
	while (i < length)
	{
		i += descriptor[i];
		j++;
	}
	assert(i == length);
	return j;
}

//************************************************************************
// this function is called by upper level code to register callback
// functions.
//************************************************************************
void	cdcacm_register(cdcacm_reset_cbfn reset, cdcacm_storedata_cbfn storeData)
{
	int i;

	for (i = 0; i < NRX; i++)
	{
		gRX_length[i]	=	0;
	}

	gReset_cbfn		=	reset;
	gStoredata_cbfn	=	storeData;

	usb_register(cdcacm_reset, cdcacm_control_transfer, cdcacm_bulk_transfer);

	assert(check(cdcacm_device_descriptor, sizeof(cdcacm_device_descriptor)) == 1);
	usb_device_descriptor(cdcacm_device_descriptor, sizeof(cdcacm_device_descriptor));

	assert(check(cdcacm_configuration_descriptor, sizeof(cdcacm_configuration_descriptor)) == 10);
	usb_configuration_descriptor(cdcacm_configuration_descriptor, sizeof(cdcacm_configuration_descriptor));

    usb_hid_report_descriptor(hid_report_descriptor, sizeof(hid_report_descriptor));

	assert(check(cdcacm_string_descriptor, sizeof(cdcacm_string_descriptor)) == 3);
    setStrings(CDCACM_MAN, CDCACM_PROD, CDCACM_SER);
//	usb_string_descriptor(cdcacm_string_descriptor, sizeof(cdcacm_string_descriptor));
}

/*
From: FTDI Support
To: 'Rich Testardi at Home' 
Sent: Monday, March 24, 2008 4:46 AM
Subject: RE: Custom PID?

Hello,

We only give out the PIDs in blocks.

We have allocated 8 PIDs to you from A660 to A667 (hex).

The PIDs must be used with VID 0403.

To reprogram the EEPROM use MPROG.

The help appendix of this utility will show you how to edit the driver for
your new identity.

http://www.ftdichip.com/Resources/Utilities/MProg3.0_Setup.exe

NOTE 1: Editing the driver for your new identity will invalidate any current
driver certification.

NOTE 2: It will be necessary for you to maintain your own edited driver
release for distribution to your customers.

Regards,
 
Gordon Lunn
Support Engineer

FTDI Ltd
373 Scotland Street
Glasgow
Scotland
UK
G5 8QB

Tel:	 +44 (0) 141 429 2777
Fax:    +44 (0) 141 429 2758
Skype: ftdi.support2
Web:   www.ftdichip.com

-----Original Message-----
From: Rich Testardi at Home [mailto:rich@testardi.com] 
Sent: 24 March 2008 06:45
To: Support1
Subject: Custom PID?

Hi,

I was wondering if I could get a custom PID to use with your VID?
(I just need one, not a block of 8, if that matters...  I just want
to be able to control the version of the driver for my hardware
independent of the version of the driver for two other FTDI chips
I already have connected to my development PC!)

Name: Rich Testardi
Company: Incipient, Inc.
Country: USA
E-Mail address: rich@testardi.com

Thank you!

-- Rich
*/

#endif	//	defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
