typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;

#define PAR (*(u8 **)(o + 0x18))

void residual_0037B9E0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern u16 func_00417620(f32);
    extern f32 func_00417500(u16);
    extern f32 func_00417440(u16);
    extern void func_001E3210(u8 *, s32);
    extern void func_0037BBF0(u8 *);
    f32 k, r;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    func_001757E0(o, 0x17, 0xA);
    o[0x24] = 0;
    *(V3 *)(o + 0x34) = *(V3 *)(PAR + 0x34);
    if (*(s16 *)(o + 0x140) != 0) k = 26.0f; else k = -26.0f;
    *(f32 *)(o + 0x34) += k;
    *(f32 *)(o + 0x38) += 90.0f;
    if (*(s16 *)(o + 0x140) != 0)
        r = 20.0f * func_00417500(func_00417620(3.0f));
    else
        r = -20.0f * func_00417500(func_00417620(3.0f));
    *(f32 *)(o + 0x5C) = r;
    *(f32 *)(o + 0x60) = 20.0f * func_00417440(func_00417620(3.0f));
    *(s16 *)(o + 0x1C) = 100;
    *(s16 *)(o + 0x1E) = PAR[0x1B7] ? 7 : 4;
    o[4] = 1;
    func_001E3210(o, 0x21);
    func_0037BBF0(o);
}
