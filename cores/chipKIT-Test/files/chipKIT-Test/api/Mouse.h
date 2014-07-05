#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
#ifndef _MOUSE_H
#define _MOUSE_H

extern "C" {
    #include "HardwareSerial_cdcacm.h"
    extern void hid_send_report(const void *data, int len);
    extern void usb_initialize();
    extern void cdcacm_register(cdcacm_reset_cbfn reset, cdcacm_storedata_cbfn storeData);
}

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 4
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE)

extern void    USBresetRoutine(void);
extern boolean USBstoreDataRoutine(const byte *buffer, int length);

class MouseClass {
    private:
        uint8_t _buttons;
        void buttons(uint8_t b);
    public:
        void begin();
        void end();
        void click(uint8_t b = MOUSE_LEFT);
        void move(int8_t x, int8_t y, int8_t = 0);
        void press(uint8_t b = MOUSE_LEFT);
        void release(uint8_t b = MOUSE_LEFT);
        bool isPressed(uint8_t b = MOUSE_LEFT);

};

extern MouseClass Mouse;

#endif // _MOUSE_H

#endif // defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
