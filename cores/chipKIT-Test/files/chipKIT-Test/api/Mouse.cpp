
#include <WProgram.h>

#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

MouseClass Mouse;

void MouseClass::begin() {
    _buttons = 0;
    usb_initialize();
    cdcacm_register(USBresetRoutine, USBstoreDataRoutine);
}

void MouseClass::click(uint8_t b) {
    _buttons = b;
    move(0, 0, 0);
    _buttons = 0;
    move(0, 0, 0);
}

void MouseClass::move(int8_t x, int8_t y, int8_t wheel) {
    uint8_t report[5];
    report[0] = 1;
    report[1] = _buttons;
    report[2] = x;
    report[3] = y;
    report[4] = wheel;
    hid_send_report(report, 5);
}

void MouseClass::buttons(uint8_t b) {
    if (b != _buttons) {
        _buttons = b;
        move(0, 0, 0);
    }
}

void MouseClass::press(uint8_t b) {
    buttons(_buttons | b);
}

void MouseClass::release(uint8_t b) {
    buttons(_buttons & ~b);
}

bool MouseClass::isPressed(uint8_t b) {
    return ((_buttons & b) > 0);
}

void MouseClass::end() {
}

#endif // defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

