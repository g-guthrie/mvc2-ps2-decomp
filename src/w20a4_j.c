typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 a[0x5B8]; } E;
extern E D_004F20B0[6];
extern u8 D_004B5430[4][6];
extern u8 *D_004C2840;
extern u8 D_004C27D0;

void func_00172520(void) {
    s32 i;
    u8 *d;
    for (i = 0; i < 6; i++) {
        u8 *x = D_004F20B0[i].a;
        x[0] = 1;
        x[0x13C] = 0;
        x[0x538] = i;
        x[0x540] = *((s8 *)D_004B5430 + i + (D_004C2840[0x2C] & 3) * 6);
        x[0x4DD] = 0;
        x[0x541] = 0;
        x[0x553] = i >> 1;
        x[0x570] = i;
    }
    d = D_004C2840;
    D_004C27D0 = *(s8 *)(d + 0x2C) & 7;
    d[0x85] = *(s8 *)(d + 0x2C) & 7;
}
