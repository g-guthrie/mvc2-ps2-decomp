/* MW 3.0.3 -O4,p -sdatathreshold 8; exact with MWWARM@src/wrm1_j.c */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern s32 D_004C283C;
extern void func_0033AB50(u8 *);
extern V3 D_0045EB38;
extern f32 D_0045EB48[];
extern f32 D_0045EB4C[];
extern f32 D_0045EB50[];

extern V3 D_0045EC80[];
extern V3 D_0045ECA4[];
extern V3 D_0045ECA8[];

void func_0033B850(s32 a, s32 b)
{
    extern void func_0033B9D0();
    u8 *p;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)())(p + 0x10) = func_0033B9D0;
        *(s16 *)(p + 0xCC) = a * 2 + 4;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_0045EC80[a];
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)D_0045ECA4[a].x / 360.0) & mask);
        *(u32 *)(p + 0x48) = ((u32)(s32)(0.5 + k * (double)D_0045ECA8[a].x / 360.0) & mask);
        *(s32 *)(p + 0xD0) = 0x80D;
        p[0x20] = a;
        *(s32 *)(p + 0x14) = b;
    }
}
