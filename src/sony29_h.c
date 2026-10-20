#include "sony_deci2_call.h"


int func_00104F08(int a0, void *a1, unsigned short a2) {
    struct {
        int f0; void *f4; unsigned int f8;
    } buf;

    buf.f4 = a1;
    buf.f8 = a2 & 0xFFFF;
    buf.f0 = a0;
    return func_00104210(-5, &buf);
}

int func_00104F40(int a0, void *a1, unsigned short a2) {
    struct {
        int f0; void *f4; unsigned int f8;
    } buf;

    buf.f4 = a1;
    buf.f8 = a2 & 0xFFFF;
    buf.f0 = a0;
    return func_00104210(-6, &buf);
}
