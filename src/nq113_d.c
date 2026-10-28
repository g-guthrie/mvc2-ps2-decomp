typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0: ./try30.sh src/nq113_d.c "-O4,p -Op -sdatathreshold 0" */

extern u8 *D_004D18B8[];
extern u8 *D_004D18C4[];
extern s8 D_004D18D6[];
extern s8 D_004D18D7[];
extern f32 D_004F1FDC[];
extern s32 D_004C283C __attribute__((section(".sdata")));

void func_00340E70(u8 *p) {
    extern s32 func_003D90A0(s32);
    extern void func_00340B20(s32);
    u8 *a;
    u8 *b;
    s32 i;
    a = D_004D18B8[0];
    b = D_004D18C4[0];
    if (D_004D18D6[0] != 3 && D_004D18D7[0] != 3) return;
    if (func_003D90A0(1) == 0) return;
    if (a[0x249] != 0) {
        if (!(*(f32 *)(a + 0x34) <= 50.0f + D_004F1FDC[0])) return;
        if (*(f32 *)(a + 0x34) < D_004F1FDC[0] - 50.0f) return;
        p[4]++;
        *(s16 *)(p + 0x1C) = 100;
        *(s16 *)(p + 0xCC) = 8;
        *(s32 *)(p + 0x84) = D_004C283C;
        i = 0;
        do {
            func_00340B20(i);
            i++;
        } while (i < 9);
    } else {
    if (!(*(f32 *)(b + 0x34) <= 50.0f + D_004F1FDC[0])) return;
    if (*(f32 *)(b + 0x34) < D_004F1FDC[0] - 50.0f) return;
    p[4]++;
    *(s16 *)(p + 0x1C) = 100;
    *(s16 *)(p + 0xCC) = 8;
    *(s32 *)(p + 0x84) = D_004C283C;
    i = 0;
    do {
        func_00340B20(i);
        i++;
    } while (i < 9);
    }
}
