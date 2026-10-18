typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w189_d.c "-O3 -sdatathreshold 0" */
typedef struct W31 { s32 x[49]; } W31;
typedef struct V3 { f32 x, y, z; } V3;

#pragma padloop on
void func_001CDA70(u8 *a, u8 *b) {
    u32 t;
    s16 h;
    t = a[4];
    if (t == 0) {
        a[4] = t + 1;
        *(W31 *)(a + 0xEC) = *(W31 *)(b + 0xEC);
        a[0x13C] = 1;
        a[2] = b[2];
        a[1] = b[1];
        *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
        *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
        a[0x1B7] = b[0x1B7];
        a[0x1B8] = b[0x1B8];
        *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
        *(V3 *)(a + 0x50) = *(V3 *)(b + 0x50);
        *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
        a[0x13C] = 1;
        *(s8 *)(a + 0x24) = 7;
        *(s16 *)(a + 0x1C) = 8;
        *(V3 *)(a + 0x34) = *(V3 *)(b + 0x34);
    }
    h = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = h;
    if (h < 0) {
        t = a[4];
        a[4] = t + 1;
    }
}
