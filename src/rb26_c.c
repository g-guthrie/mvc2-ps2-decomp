#include "queue_request_api.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004CC150[];

s32 func_001E5710(const void *request, u32 n)
{
    u32 a=(u32)request;
    extern void *func_0011D8F8(void *, s32, u32);
    extern s32 func_00423480(u32, s32, s32, s32, s32, s32, s32);
    extern s32 func_00423750(s32);
    u8 *q;
    u8 *p;
    u8 *src;
    u8 *d;
    u8 *e;
    s32 i;
    s32 r;

    if (n >= 8) return -1;
    src = (u8 *)(a + *(s32 *)(a + 0x18));
    e = D_004CC150 + n * 512;
    q = (u8 *)a;
    p = (u8 *)a;
    d = e;
    func_0011D8F8(e, 0, 0x200);
    for (i = 0; i < 0x80 && (u32)i < (*(u32 *)(p + 0x1C) >> 4); i++) {
        d[0] = 1;
        d[1] = src[4];
        d[2] = src[0xE];
        d[3] = src[3];
        while (src[3] != 0) {
            src += 0x10;
        }
        src += 0x10;
        d += 4;
    }
    r = func_00423480(n, (s32)(u32)(q + *(s32 *)p), *(s32 *)(p + 4), (s32)(u32)(q + *(s32 *)(p + 8)), *(s32 *)(p + 0xC), (s32)(u32)(q + *(s32 *)(p + 0x10)), *(s32 *)(p + 0x14));
    if (r < 0) {
        func_0011D8F8(e, 0, 0x200);
        return r;
    }
    return func_00423750(1);
}
