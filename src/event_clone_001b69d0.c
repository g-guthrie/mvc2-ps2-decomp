typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#pragma padloop on
void func_001B69D0(u8 *p)
{
    extern s32 func_00175670(u8 *);
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_001B6F10(u8 *);
    extern void func_001B6F30(u8 *);
    switch (p[4]) {
    case 0: {
        u8 *q;
        s32 n;
        u32 *d;
        u32 *r;
        u32 t;
        t = p[4]; p[4] = t + 1;
        q = *(u8 **)(p + 0x18);
        d = (u32 *)(p + 0xEC); r = (u32 *)(q + 0xEC); n = 49;
        for (; n > 0; --n) *d++ = *r++;
        p[0x13C] = 1;
        p[2] = (*(u8 **)(p + 0x18))[2];
        p[1] = (*(u8 **)(p + 0x18))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
        p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
        p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
        p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
        p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        p[0x13C] = 1;
        func_001754A0(p, 0x1B, 4);
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
        p[0x24] = 0;
        break;
    }
    case 1: {
        u8 *q = *(u8 **)(p + 0x14);
        if (q[0x2B9] != 0 || q[0x1E4] != 0x15 || q[5] != 0)
            func_001B6F10(p);
        break;
    }
    case 2: {
        func_001B6F30(p);
        break;
    }
    }
}
