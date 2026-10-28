typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;



typedef struct { f32 x, y, z; } V3;
extern V3 D_0045F9E0[];
extern f32 D_0045FA04[];
extern u8 D_004C2A40[8];
extern u8 D_004C2A41;
extern u8 D_004C2A42[2];
extern u8 D_004C2A43[2];
extern s32 D_004C283C;

/* Real address-order predecessor (0x0033FCE0, soft-float), verbatim from src/w178_f.c. */
static void func_0033FCE0(u8 *p) {
    switch (p[0x20]) {
    case 0:
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * (double)(D_004C2A42[0] * 3 * 2) / 360.0));
        break;
    case 1:
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * (double)((D_004C2A42[0] + (D_004C2A43[0] % 12) * 60) / 2) / 360.0));
        break;
    }
}

void func_0033FE10(s32 a)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_0010FC98(u8 *);
    extern void func_003D7220(u8 *);
    extern void func_0033FCE0();
    u8 *o;

    if ((o = func_003DA750(0, 6, 0)) != 0) {
        if (func_0010FC98(D_004C2A40) == 0) {
            D_004C2A43[0] = 0;
            D_004C2A42[0] = 0;
            D_004C2A41 = 0;
        }
        func_003D7220(D_004C2A40);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033FCE0;
        *(s16 *)(o + 0xCC) = a + 9;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_0045F9E0[a];
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)((u8 *)D_0045FA04 + a * 12) / 360.0) & 0xFFFF;
        o[0x20] = a;
    }
}
