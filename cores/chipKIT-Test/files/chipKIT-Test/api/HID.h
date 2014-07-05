#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
#ifndef _HID_H
#define _HID_H

extern "C" {
    #include "HardwareSerial_cdcacm.h"
    extern void hid_send_report(const void *data, int len);
    extern void usb_initialize();
    extern void cdcacm_register(cdcacm_reset_cbfn reset, cdcacm_storedata_cbfn storeData);
}

extern void    USBresetRoutine(void);
extern boolean USBstoreDataRoutine(const byte *buffer, int length);

typedef int (*hidFeature)(uint8_t, uint8_t *, int);

#define HID_READ 0
#define HID_WRITE 1

class HIDClass : public Stream {
    private:
        hidFeature _featureCallbacks[256];

    public:
        void write(uint8_t k);
        void write(uint8_t *k, int n);
        void begin();
        void end();
        int available();
        int read();
        int peek();
        void flush();
        void attachFeature(uint8_t feature, hidFeature cb);
        void detatchFeature(uint8_t feature);
        uint8_t callFeature(uint8_t feature, uint8_t rw, uint8_t *buffer, uint8_t len);
};

extern HIDClass HID;

#endif // _HID_H

#endif // defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
