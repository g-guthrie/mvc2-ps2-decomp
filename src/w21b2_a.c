typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C2838;
extern f32 D_00444C70[];
extern f32 D_00444C74[];
extern f32 D_00444C78[];

u8 *func_00157330(V3 *a, s32 b)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00157290();
    u8 *o;
    if ((o = func_003DA750(0, 9, 1)) != 0) {
        o[0x13C] = 1;
        *(s32 *)(o + 0x10) = (s32)func_00157290;
        *(s16 *)(o + 0xCC) = b + 0x2C;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(s32 *)(o + 0xD0) = 0x800401;
        *(V3 *)(o + 0x34) = *a;
        *(f32 *)(o + 0x34) += D_00444C70[b * 3];
        *(f32 *)(o + 0x38) += D_00444C74[b * 3];
        *(f32 *)(o + 0x3C) += D_00444C78[b * 3];
        *(f32 *)(o + 0x5C) = -D_00444C70[b * 3] / 15.0f;
        *(f32 *)(o + 0x60) = -D_00444C74[b * 3] / 15.0f;
        *(f32 *)(o + 0x64) = -D_00444C78[b * 3] / 15.0f;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
    }
}


typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G24;
extern G24 *D_004C2794;
