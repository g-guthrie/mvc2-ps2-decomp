#ifndef RUNTIME_DECODE_DESCRIPTOR_H
#define RUNTIME_DECODE_DESCRIPTOR_H

typedef struct RuntimeDecodeDescriptor {
    int active, slot, reserved, state, result, mode;
    const void *input;
    int count;
    short *output;
    short *output2;
    short state1[2], state2[2];
    short rate1, rate2, state3, step, finish, tail;
} RuntimeDecodeDescriptor;

#endif
