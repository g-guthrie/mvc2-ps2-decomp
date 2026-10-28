typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern u16 *D_004C2984;

void residual_00369440(u8 *o) {
    extern void func_0036A8A0(u8 *);
    extern s32 func_0036A5F0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s = *(u8 **)(o + 0x18);
    u32 t;
    f32 k;
    if (*D_004C2984 != *(u16 *)(s + 0x168)) {
        func_0036A8A0(o);
        return;
    }
    if (func_0036A5F0(o)) {
        func_0036A8A0(o);
    } else if (*(s8 *)(s + 0x151) != 0) {
        t = o[5];
        o[5] = t + 1;
        o[0x13C] = 1;
        o[0x24] = 0xC;
        o[0x31] = 1 - *(s8 *)(o + 2) * 4;
        o[0x14C] = 0x20;
        o[0x14D] = 0xC0;
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x42;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(u32 *)(o + 0x1D8) = 0;
        {u32 a = o[2] * 2; a += (u32)D_004C2794; a += 0x7C; ++*(s16 *)a;}
        if (*(s16 *)(o + 0x140) != 0) {
            k = 226.66665649414062f;
        } else {
            k = -226.66665649414062f;
        }
        *(f32 *)(o + 0x34) = *(f32 *)(s + 0x34) + k;
        *(f32 *)(o + 0x38) = *(f32 *)(s + 0x430);
        *(s16 *)(o + 0x1C) = 0;
        func_001757E0(o, 0x17, 0x18);
    }
}
