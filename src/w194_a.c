#include "runtime_decode_descriptor.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_00404438(RuntimeDecodeDescriptor *p, const void *a1, s32 a2, short *a3, short *t0) {
    if (p->state == 0) {
        p->input = a1; p->count = a2; p->mode = 2; p->output = a3; p->output2 = t0;
        return 1;
    }
    return 0;
}
