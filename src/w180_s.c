typedef struct StreamGroup StreamGroup;
#include "runtime_stream_query.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00401A48(u8 *p, s32 *a, s32 *b) {
    s32 r1;
    s32 arg;
    s32 r2; s32 r5;
    s32 r3;
    s32 r4;
    s8 t;
    u8 raw;
    extern s32 func_003FFF78(void *);
    extern s32 func_003FFEC8(s32);
    extern s32 func_003FF190(s32);
    extern s32 func_00402298(u8 *, s32);
    extern s32 func_003FFFF0(StreamGroup *);
    raw = p[1];
    if ((u32)raw - 3 < 2) {
        r1 = func_003FFF78(*(void **)(p + 4));
        arg = *(s32 *)(p + 4);
        *b = r1;
        r2 = func_003FFEC8(arg);
        r3 = func_003FF190(*(s32 *)(p + 0xC));
        r4 = func_00402298(p, 0);
        *a = r2 - (r3 + r4) + *(s32 *)(p + 0xA4);
    } else if ((s8)raw == 5) {
        r1 = func_003FFFF0(*(StreamGroup **)(p + 4));
        arg = *(s32 *)(p + 4);
        *a = r1;
        r1 = func_003FFF78((void *)arg);
        arg = *(s32 *)(p + 4);
        *b = r1;
        r5 = func_003FFFA8((void *)arg);
        *a = *a * (16 / r5);
        *a += *(s32 *)(p + 0xA4);
    } else {
        *a = 0;
        *b = 1;
    }
    *a += *(s32 *)(p + 0x88);
}
