/* MW 3.0 -O3 -Op -fp off -sdatathreshold 8; exact with MWWARM_30@src/model_y_wave_callback_00345650.c (nearest preceding double-arith fn func_00345650) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { s32 w[0x31]; } CP157;
typedef struct { f32 x, y, z; } V157;
extern u8 *D_004C2954;
extern f32 D_004F1F4C[];

void func_0034FBB0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    f64 k;
    f32 g;

    p[0x13C] = 1;
    *(CP157 *)(p + 0xEC) = *(CP157 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[0x2] = (*(u8 **)(p + 0x18))[0x2];
    p[0x1] = (*(u8 **)(p + 0x18))[0x1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V157 *)(p + 0x50) = *(V157 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    D_004C2954[3] = 1;
    p[0x24] = 0xB;
    if (*(s16 *)(p + 0x140) != 0) {
        k = -426.66666412353516;
    } else {
        k = 426.66666412353516;
    }
    g = D_004F1F4C[0];
    *(f32 *)(p + 0x34) = (f32)((f64)g + k);
    *(f32 *)(p + 0x38) = 411.4285583496094f + *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = (*(s16 *)(p + 0x140) != 0) ? 10.0f : -10.0f;
    *(u32 *)(p + 0x60) = 0xBF892492;
    p[0x14C] = 0x40;
    p[0x14D] = 0x10;
    p[0x14E] = 0x60;
    p[0x14F] = 0x60;
    *(s16 *)(p + 0x1C) = p[0x1B7] ? 0x40 : 0x20;
    func_001757E0(p, 0x17, 0);
}
