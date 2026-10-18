typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0 (older): ./try30.sh src/w188_g.c "-O3 -Op -sdatathreshold 0" */

typedef struct { f32 x, y, z; } V3_001B2240;
typedef struct { s32 w[0x31]; } S_001B2240;
void func_001B2240(u8 *a) {
    u8 *b;
    f32 c;
    f32 d;
    extern void func_001754A0(u8 *, s32, s32);
    a[4]++;
    b = *(u8 **)(a + 0x18);
    *(S_001B2240 *)(a + 0xEC) = *(S_001B2240 *)(b + 0xEC);
    a[0x13C] = 1;
    a[2] = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
    *(V3_001B2240 *)(a + 0x50) = *(V3_001B2240 *)(b + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    a[0x13C] = 1;
    a[0x24] = 0xE;
    *(s16 *)(a + 0x140) = *(s16 *)(*(u8 **)(a + 0x18) + 0x140);
    *(f32 *)(a + 0x34) = *(f32 *)(*(u8 **)(a + 0x18) + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(*(u8 **)(a + 0x18) + 0x38);
    *(f32 *)(a + 0x3C) = *(f32 *)(*(u8 **)(a + 0x18) + 0x3C);
    if (*(s16 *)(a + 0x140) != 0) c = -53.33333206176758f;
    else c = 53.33333206176758f;
    *(f32 *)(a + 0x34) += c;
    d = 34.2857131958f;
    *(f32 *)(a + 0x38) += d;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x6C) = 0;
    func_001754A0(a, 0x1B, 0xE);
}
