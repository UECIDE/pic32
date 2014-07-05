
#include <WProgram.h>

#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

#include "HardwareSerial.h"

HIDClass HID;

ring_buffer     hid_rx_buffer = { { 0 }, 0, 0 };

extern "C" {

    uint8_t hid_call_feature(uint8_t feature, uint8_t rw, uint8_t *data, uint8_t len) {
        return HID.callFeature(feature, rw, data, len);
    }

    void hid_debug(uint32_t v) {
        char tmp[100];
        sprintf(tmp, "Debug: 0x%08X", v);
        Serial.println(tmp);
    }

    void hid_push(uint8_t *data, int len) {
        uint32_t x;
        int pos = 0;
        while (len > 0) {
            int     bufIndex;
            uint8_t ch;

            ch = data[pos];
            pos++;
            len--;

            bufIndex    = (hid_rx_buffer.head + 1) % RX_BUFFER_SIZE;
       
            if (bufIndex != hid_rx_buffer.tail) {
                hid_rx_buffer.buffer[hid_rx_buffer.head] = ch;
                hid_rx_buffer.head = bufIndex;
            }

        }
    }

}

void HIDClass::begin() {
    usb_initialize();
    cdcacm_register(USBresetRoutine, USBstoreDataRoutine);
    for (int i = 0; i < 256; i++) {
        _featureCallbacks[i] = NULL;
    }
}

void HIDClass::write(uint8_t k) {
    uint8_t data[2];
    data[0] = 3;
    data[1] = k;
    hid_send_report(data, 2);
}

void HIDClass::write(uint8_t *k, int n) {
    uint8_t data[64];
    data[0] = 3;
    while (n > 0) {
        int tx = (n > 63 ? 63 : n);
        memcpy(data + 1, k, tx);
        n -= tx;
        k += tx;
        hid_send_report(data, tx + 1);
    }
}

void HIDClass::end() {
}

int HIDClass::available(void) {
    return (RX_BUFFER_SIZE + hid_rx_buffer.head - hid_rx_buffer.tail) % RX_BUFFER_SIZE;
}

int HIDClass::read(void) {
    unsigned char theChar;

    // if the head isn't ahead of the tail, we don't have any characters
    if (hid_rx_buffer.head == hid_rx_buffer.tail) {
        return -1;
    } else {
        theChar         = hid_rx_buffer.buffer[hid_rx_buffer.tail];
        hid_rx_buffer.tail  = (hid_rx_buffer.tail + 1) % RX_BUFFER_SIZE;
        return (theChar);
    }
}

int HIDClass::peek() {
    if (hid_rx_buffer.head == hid_rx_buffer.tail) {
        return -1;
    } else {
        return hid_rx_buffer.buffer[hid_rx_buffer.tail];
    }
}

void HIDClass::flush() {
}

void HIDClass::attachFeature(uint8_t feature, hidFeature cb) {
    _featureCallbacks[feature] = cb;
}

void HIDClass::detatchFeature(uint8_t feature) {
    _featureCallbacks[feature] = NULL;
}


uint8_t HIDClass::callFeature(uint8_t feature, uint8_t rw, uint8_t *buffer, uint8_t len) {
    if (_featureCallbacks[feature] == NULL) {
        return 0;
    }
    return _featureCallbacks[feature](rw, buffer, len);
}

#endif // defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

