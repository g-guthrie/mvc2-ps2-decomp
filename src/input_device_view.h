#ifndef MVC2_INPUT_DEVICE_VIEW_H
#define MVC2_INPUT_DEVICE_VIEW_H

typedef struct InputDeviceView {
    unsigned char state;
    unsigned char pad01[0x39];
    signed short axis_3a;
    unsigned char pad3c[0x4c];
} InputDeviceView;

typedef char InputDeviceView_size_check[(sizeof(InputDeviceView) == 0x88) ? 1 : -1];

#endif
