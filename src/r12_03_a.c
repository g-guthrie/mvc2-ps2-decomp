/* func_0014D7A0: MW 3.0.3 -O3 -Op -sdatathreshold 8 (also exact on 3.0) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3D5;

extern V3D5 D_00444290[];
extern u32 D_004442C0[];
extern s32 D_004C27FC;
extern s32 D_004C27E8;

#pragma push
#pragma opt_dead_assignments off
void func_0014D7A0(void)
{
    u8 *o;
    s32 i;
    f32 k;
    u32 a;
    s32 g;

    i = 0;
    do {
        extern u8 *func_003DA750(s32 a0, s32 a1, s32 a2);
        extern void func_0014D910(void);
        extern void func_0014D9E0(u8 *o, u32 a1, s32 a2, s32 a3, f32 f);
        s32 t0;

        if ((o = func_003DA750(0, 0xD, 1)) == 0) {
            return;
        }
        *(u8 *)(o + 0x13C) = 1;
        *(u32 *)(o + 0x10) = (u32)func_0014D910;
        *(u16 *)(o + 0xCC) = 0xB;
        t0 = D_004C27FC;
        *(s32 *)(o + 0x84) = t0;
        *(u32 *)(o + 0xD0) = 0x800021;
        *(V3D5 *)(o + 0x34) = D_00444290[i];
        *(u8 *)(o + 0x20) = i;
        func_0014D9E0(o, D_004C27FC, 9, 0, -0.009999999776482582f);
        func_0014D9E0(o, D_004C27FC, 10, 0, -0.009999999776482582f);
        if (i != 2) {
            g = D_004C27FC;
            k = 0.009999999776482582f;
            func_0014D9E0(o, g, D_004442C0[i], 1, k);
        } else {
            k = 0.009999999776482582f;
            g = D_004C27E8;
            a = D_004442C0[i];
            func_0014D9E0(o, g, a, 1, k);
        }
        i++;
    } while (i < 4);
}
#pragma pop
