#ifndef MVC2_INPUT_DEVICE_VIEW_H
#define MVC2_INPUT_DEVICE_VIEW_H

typedef struct InputDeviceVector {
    signed short x, y, length, angle;
    float radians;
} InputDeviceVector;

typedef struct InputDeviceView {
    unsigned char state;
    unsigned char flags;
    unsigned short mode;
    unsigned char pad04[4];
    unsigned int buttons;
    unsigned char pad0c[0x20];
    InputDeviceVector first;
    InputDeviceVector second;
    unsigned char pad44[0x44];
} InputDeviceView;

typedef char InputDeviceVector_size_check[(sizeof(InputDeviceVector) == 12) ? 1 : -1];
typedef char InputDeviceView_size_check[(sizeof(InputDeviceView) == 0x88) ? 1 : -1];

#endif
