typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 f0[4]; s8 f4; u8 f5; s8 f6; } G67;
extern G67 *D_004C2840;
extern s32 D_004C27FC, D_004C27E8;
extern f32 D_004442D0[], D_004442E0[], D_004442F0[], D_00444310[];

void func_0014DA90(void) {
    extern u8 *func_003DA750();
    extern void func_0014DFD0();
    extern void func_0014E2F0();
    extern void func_0014E7B0(u8 *o, s32 t, f32 y);
    extern void func_0014E8E0(u8 *a, s32 b, s32 c);
    extern void func_0014EA80(u8 *a, s32 b);
    extern void func_0014EDD0(u8 *a, s32 b);
    extern void func_0014EC30(u8 *o, f32 x, f32 y, f32 z);
    extern void func_0014F020(u8 *p, s32 a1, s32 a2, f32 f);
    extern void func_0014F1D0();
    extern void func_0014F490();
    extern void func_0014F740();
    extern void func_0014F9F0();
    extern void func_0014FCA0();
    extern void func_0014FDC0();
    extern void func_0014FED0();
    extern void func_001500E0();
    extern void func_00150530(u8 *a, s32 b, f32 x, f32 y, f32 z);
    extern void func_001508D0(u8 *a, s32 b, s32 c, f32 x, f32 y, f32 z);
    extern void func_00150AE0(u8 *a, s32 b, s32 c, f32 x, f32 y, f32 z);
    s32 i;
    u8 *o;
    for (i = 0; i < 3; i++) {
        D_004442D0[i] = (D_004C2840->f4 != 2) ? D_004442E0[i] : D_004442F0[i];
    }
    i = 0;
    do {
        if ((o = func_003DA750(0, 0xD, 1)) == 0) return;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0014DFD0;
        if (D_004C2840->f4 != 2) {
            *(s16 *)(o + 0xCC) = 0xF;
            *(s32 *)(o + 0x84) = D_004C27FC;
        } else {
            *(s16 *)(o + 0xCC) = 9;
            *(s32 *)(o + 0x84) = D_004C27E8;
        }
        *(s32 *)(o + 0xD0) = 0x421;
        *(s32 *)(o + 0x34) = 0;
        *(f32 *)(o + 0x38) = D_004442D0[i];
        *(f32 *)(o + 0x3C) = -13.0f;
        *(s16 *)(o + 0x1E) = i;
        *(f32 *)(o + 0x74) = 1.0f;
        o[0x23] = D_004C2840->f6;
        if (D_004C2840->f4 != 2) {
            func_0014E7B0(o, i, D_00444310[i]);
            func_0014E8E0(o, i, 0);
            func_0014E8E0(o, i, 1);
            func_0014E8E0(o, i, 2);
            func_0014EA80(o, i);
            func_0014EDD0(o, i);
            func_0014F020(o, i, 0, -0.5400000214576721f);
            func_0014F020(o, i, 1, -0.5400000214576721f);
            if (D_004C2840->f4 == 0) {
                func_0014FDC0(o, i);
            } else if (D_004C2840->f4 == 1) {
                func_0014F1D0(o, i, 0);
                func_0014F1D0(o, i, 1);
            }
            func_0014F490(o, i, 0);
            func_0014F490(o, i, 1);
            func_0014F740(o, i, 0);
            func_0014F740(o, i, 1);
            func_0014F9F0(o, i, 0);
            func_0014F9F0(o, i, 1);
            func_0014FCA0(o, i);
            func_0014FED0(o, i, 0);
            func_0014FED0(o, i, 1);
            func_0014FED0(o, i, 2);
            func_001500E0(o, i, 0);
            func_001500E0(o, i, 1);
            func_001500E0(o, i, 2);
            func_001500E0(o, i, 3);
            func_001500E0(o, i, 4);
            func_001500E0(o, i, 5);
            func_001500E0(o, i, 6);
            func_001500E0(o, i, 7);
            func_001500E0(o, i, 8);
            func_001500E0(o, i, 9);
            func_001500E0(o, i, 10);
        } else if (D_004C2840->f4 == 2) {
            func_0014E7B0(o, i, 0.5f + D_00444310[i]);
            func_0014EC30(o, -5.0f, 0.0f, 0.06999969482421875f);
            func_0014F020(o, i, 0, -0.04000002145767212f);
            func_0014F020(o, i, 1, -0.04000002145767212f);
            func_00150530(o, i, -3.0999999046325684f, 0.0f, 0.10000000149011612f);
            func_001508D0(o, i, 0, -2.5f, 0.0f, 0.10999999940395355f);
            func_001508D0(o, i, 1, -2.5f, 0.0f, 0.10999999940395355f);
            func_001508D0(o, i, 2, -2.5f, 0.0f, 0.10999999940395355f);
            func_001508D0(o, i, 3, -2.5f, 0.0f, 0.10999999940395355f);
            func_00150AE0(o, i, 0, -2.5f, 0.0f, 0.10999999940395355f);
            func_00150AE0(o, i, 1, -2.5f, 0.0f, 0.10999999940395355f);
        }
        i++;
    } while (i < 3);
    func_0014E2F0();
}
