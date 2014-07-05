#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#define KEY_LEFT_CTRL       0x80
#define KEY_LEFT_SHIFT      0x81
#define KEY_LEFT_ALT        0x82
#define KEY_LEFT_GUI        0x83
#define KEY_RIGHT_CTRL      0x84
#define KEY_RIGHT_SHIFT     0x85
#define KEY_RIGHT_ALT       0x86
#define KEY_RIGHT_GUI       0x87

#define KEY_UP_ARROW        0xDA
#define KEY_DOWN_ARROW      0xD9
#define KEY_LEFT_ARROW      0xD8
#define KEY_RIGHT_ARROW     0xD7
#define KEY_BACKSPACE       0xB2
#define KEY_TAB             0xB3
#define KEY_RETURN          0xB0
#define KEY_ESC             0xB1
#define KEY_INSERT          0xD1
#define KEY_DELETE          0xD4
#define KEY_PAGE_UP         0xD3
#define KEY_PAGE_DOWN       0xD6
#define KEY_HOME            0xD2
#define KEY_END             0xD5
#define KEY_CAPS_LOCK       0xC1
#define KEY_F1              0xC2
#define KEY_F2              0xC3
#define KEY_F3              0xC4
#define KEY_F4              0xC5
#define KEY_F5              0xC6
#define KEY_F6              0xC7
#define KEY_F7              0xC8
#define KEY_F8              0xC9
#define KEY_F9              0xCA
#define KEY_F10             0xCB
#define KEY_F11             0xCC
#define KEY_F12             0xCD

#define TRANSFER_PGM        0x80
#define TRANSFER_RELEASE    0x40
#define TRANSFER_ZERO       0x20

extern "C" {
    #include "HardwareSerial_cdcacm.h"
    extern void hid_send_report(const void *data, int len);
    extern void usb_initialize();
    extern void cdcacm_register(cdcacm_reset_cbfn reset, cdcacm_storedata_cbfn storeData);
}


extern void    USBresetRoutine(void);
extern boolean USBstoreDataRoutine(const byte *buffer, int length);

typedef struct
{
    uint8_t page;
    uint8_t modifiers;
    uint8_t reserved;
    uint8_t keys[6];
} KeyReport __attribute__((packed));

class KeyboardClass : public Print {
    private:
        KeyReport _keyReport;
        uint8_t _leds;
    public:
        void write(uint8_t k);
        void press(uint8_t k);
        void release(uint8_t k);

        void pressMod(uint8_t k);
        void releaseMod(uint8_t k);

        void writeRaw(uint8_t k);
        void pressRaw(uint8_t k);
        void releaseRaw(uint8_t k);

        void releaseAll();
        void begin();
        void end();

        void setLEDs(uint8_t);
        uint8_t getLEDs();
};

extern KeyboardClass Keyboard;

#endif // _KEYBOARD_H

#endif // defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
