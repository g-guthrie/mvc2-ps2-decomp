typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[4]; s8 b4; u8 p5; s8 b6; } G62a;
extern G62a *D_004C2840;
extern s32 D_004C27FC;
extern s32 D_004C27E8;
extern f32 D_004BF404;
extern f32 D_00444314[];

void func_0014E2F0(void)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014DFD0(u8 *);
    extern void func_0014FDC0(u8 *);
    extern void func_0014F1D0(u8 *, s32, s32);
    extern void func_0014E7B0(u8 *, s32, f32);
    extern void func_0014E8E0(u8 *, s16, s32);
    extern void func_0014EA80(u8 *, s32);
    extern void func_0014EDD0(u8 *, s32);
    extern void func_0014F020(u8 *, s32, s32, f32);
    extern void func_0014F490(u8 *, s32, s32);
    extern void func_0014F740(u8 *, s32, s32);
    extern void func_0014F9F0(u8 *, s32, s32);
    extern void func_0014FCA0(u8 *, s32);
    extern void func_0014FED0(u8 *, s32, s32);
    extern void func_001500E0(u8 *, s32, s32);
    extern void func_0014EC30(u8 *, f32, f32, f32);
    extern void func_00150530(u8 *, s16, f32, f32, f32);
    extern void func_001508D0(u8 *, s16, s32, f32, f32, f32);
    extern void func_00150AE0(u8 *, s16, s32, f32, f32, f32);
    u8 *o;
    s32 b;

    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_0014DFD0;
        if (D_004C2840->b4 != 2) {
            *(s16 *)(o + 0xCC) = 0xF;
            *(s32 *)(o + 0x84) = D_004C27FC;
        } else {
            *(s16 *)(o + 0xCC) = 9;
            *(s32 *)(o + 0x84) = D_004C27E8;
        }
        *(s32 *)(o + 0xD0) = 0x421;
        *(s32 *)(o + 0xDC) = 1;
        *(s32 *)(o + 0x34) = 0;
        *(f32 *)(o + 0x38) = D_004BF404;
        *(u32 *)(o + 0x3C) = 0xC1500000;
        *(s16 *)(o + 0x1E) = 1;
        *(u32 *)(o + 0x74) = 0x3F800000;
        o[0x23] = D_004C2840->b6;
        b = D_004C2840->b4;
        if (b == 2) goto case2;
        if (b == 0) {
            func_0014FDC0(o);
        } else if (b == 1) {
            func_0014F1D0(o, 1, 0);
            func_0014F1D0(o, 1, 1);
        }
        func_0014E7B0(o, 1, D_00444314[0]);
        func_0014E8E0(o, 1, 0);
        func_0014E8E0(o, 1, 1);
        func_0014E8E0(o, 1, 2);
        func_0014EA80(o, 1);
        func_0014EDD0(o, 1);
        func_0014F020(o, 1, 0, -0.5400000214576721f);
        func_0014F020(o, 1, 1, -0.5400000214576721f);
        func_0014F490(o, 1, 0);
        func_0014F490(o, 1, 1);
        func_0014F740(o, 1, 0);
        func_0014F740(o, 1, 1);
        func_0014F9F0(o, 1, 0);
        func_0014F9F0(o, 1, 1);
        func_0014FCA0(o, 1);
        func_0014FED0(o, 1, 0);
        func_0014FED0(o, 1, 1);
        func_0014FED0(o, 1, 2);
        func_001500E0(o, 1, 0);
        func_001500E0(o, 1, 1);
        func_001500E0(o, 1, 2);
        func_001500E0(o, 1, 3);
        func_001500E0(o, 1, 4);
        func_001500E0(o, 1, 5);
        func_001500E0(o, 1, 6);
        func_001500E0(o, 1, 7);
        func_001500E0(o, 1, 8);
        func_001500E0(o, 1, 9);
        func_001500E0(o, 1, 10);
        return;
case2:
        if (b != 2) return;
        func_0014E7B0(o, 1, 0.5f + D_00444314[0]);
        func_0014EC30(o, -5.0f, 0.0f, 0.06999969482421875f);
        func_0014F020(o, 1, 0, -0.04000002145767212f);
        func_0014F020(o, 1, 1, -0.04000002145767212f);
        func_00150530(o, 1, -3.0999999046325684f, 0.0f, 0.10000000149011612f);
        func_001508D0(o, 1, 0, -2.5f, 0.0f, 0.10999999940395355f);
        func_001508D0(o, 1, 1, -2.5f, 0.0f, 0.10999999940395355f);
        func_001508D0(o, 1, 2, -2.5f, 0.0f, 0.10999999940395355f);
        func_001508D0(o, 1, 3, -2.5f, 0.0f, 0.10999999940395355f);
        func_00150AE0(o, 1, 0, -2.5f, 0.0f, 0.10999999940395355f);
        func_00150AE0(o, 1, 1, -2.5f, 0.0f, 0.10999999940395355f);
    }
}
