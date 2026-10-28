typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C283C[2];
extern V3 D_004B7970;
extern f32 D_004B7984[];

/* MW 3.0: ./try30.sh SRC "-O3 -Op -sdatathreshold 8"
   func_00333950 is the real function immediately before func_00333A00 in
   retail address order (verified exact at its own address). */
extern double func_00119058(f32);

typedef struct P {
    u8 pad0[0x1C];
    s16 h1c;
    u8 pad1[0x40 - 0x1E];
    u32 w40;
    u32 w44;
    u8 pad2[0x54 - 0x48];
    f32 f54;
    u8 pad3[0xD4 - 0x58];
    s32 wd4;
} P;

static s32 func_00333950(P *p) {
    p->h1c += 1;
    p->w44 += (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}

static s32 (*keep_00333950)(P *) = func_00333950;

void func_00333A00(void)
{
    extern u8 *func_003DA750();
    extern void func_00333590();
    extern void func_00332F70();
    extern void func_00333470();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00333590;
        *(s16 *)(o + 0xCC) = 1;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_004B7970;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B7984[0] / 360.0) & 0xFFFF;
        o[0x20] = 1;
        func_00332F70(o);
        func_00333470(o);
    }
}
