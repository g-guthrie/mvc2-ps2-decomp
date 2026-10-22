typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern double func_00119058(f32);

typedef struct P {
    u8 pad0[0x1C];
    s16 h1c;
    u8 pad1[0x48 - 0x1E];
    u32 w48;
    u8 pad2[0x64 - 0x4C];
    f32 f64;
    u8 pad3[0xD4 - 0x68];
    s32 wd4;
} P;

s32 func_00333EC0(P *p) {
    p->h1c += 1;
    p->w48 += (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(p->f64 * (f32)p->h1c) / 360.0));
    if (p->wd4 <= p->h1c) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}
