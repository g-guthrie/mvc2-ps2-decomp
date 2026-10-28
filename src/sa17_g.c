typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C2808[2];
extern V3 D_004B3418;
extern s32 D_004C283C[2];
extern s32 D_004C2808[2];
extern V3 D_004B3418;
extern f32 D_004B3428[];
extern f32 D_004B342C[];
extern f32 D_004B3430[];

extern V3 D_004B8168;
extern f32 D_004B817C[];
extern f32 D_004B3428[];
extern f32 D_004B342C[];
extern f32 D_004B3430[];


static void func_00339770(u8 *p) {
    switch (p[4]) {
    case 0: {
        double degrees = *(short *)(p+0x1c);
        *(int *)(p+0x40) = (int)((unsigned int)(int)(0.5 + 65536.0 * degrees / 360.0) & 0xFFFFu);
        *(short *)(p+0x1c) += 0x3;
        if (*(short *)(p+0x1c) >= 360) *(short *)(p+0x1c) %= 360;
        break;
    }
    }
}

void func_00339820(void)
{
    extern u8 *func_003DA750();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00339770;
        *(s16 *)(o + 0xCC) = 0x11;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B8168;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B817C[0] / 360.0) & 0xFFFF;
    }
}

void func_001458C0(s32 a)
{
    extern u8 *func_003DA750();
    extern void func_00145A90();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        *(s32 *)(o + 0x18) = a;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00145A90;
        *(s16 *)(o + 0xCC) = 9;
        *(s32 *)(o + 0x84) = D_004C2808[0];
        *(V3 *)(o + 0x34) = D_004B3418;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + k * (double)D_004B3428[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B342C[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + k * (double)D_004B3430[0] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0xC1F;
        *(u32 *)(o + 0x50) = 0x3F19999A;
        *(u32 *)(o + 0x54) = 0x3F19999A;
        *(u32 *)(o + 0x58) = 0x3F19999A;
        *(f32 *)(o + 0x5C) = D_004B3428[0];
        *(s32 *)(*(u8 **)(o + 0x18) + 0xD8) = 1;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
    }
}

