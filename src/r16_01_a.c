/* func_001E5870: wait for the 0x8000000C status register to change, then
   for func_001E5700 to report idle. Busy-wait nop runs are the original
   inline-asm timing delays (as in func_0012DA40 / func_00418B10).
   MW 3.0, -O3,p -sdatathreshold 0, with the global optimizer off (like
   src/rb24_c.c): this leaves the loop-test block in source order. */
#pragma global_optimizer off
#include "queue_request_api.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004CC150[];

int func_001E5870(const void *request, unsigned int n) {
    extern s32 func_00423990(u32, s32);
    extern s32 func_001E5700(void);
    extern void func_00418B10();
    extern void func_0011D8F8(u8 *, s32, s32);
    s32 t, k, r;
    t = func_00423990(0x8000000C, 1);
    if ((r = func_001E5710(request, n)) < 0) return r;
    k = 0xF0;
    while (func_00423990(0x8000000C, 1) == t) {
        __asm__("nop;nop;nop;nop;nop;nop");
        func_00418B10();
        if (--k < 0) {
            func_0011D8F8(D_004CC150 + n * 512, 0, 0x200);
            return -1;
        }
    }
    while (func_001E5700() > 0) {
        __asm__("nop;nop;nop;nop;nop;nop");
        func_00418B10();
    }
    return 0;
}
