typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern s32 D_004C2838;
extern void func_0015D270();
void func_0015D100(V3 *a, s32 b)
{
    extern u8 *func_003DA750();
    extern s32 func_00417A40();
    u8 *o;
    s32 r;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0015D270;
        *(s16 *)(o + 0xCC) = b + 0x79;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *a;
        *(f32 *)(o + 0x5C) = (f32)(func_00417A40() % 30 - 15);
        *(f32 *)(o + 0x60) = (f32)(func_00417A40() % 30 - 15);
        *(f32 *)(o + 0x64) = (f32)(func_00417A40() % 30 - 15);
        *(f32 *)(o + 0x68) = -*(f32 *)(o + 0x5C) / 30.0f;
        *(f32 *)(o + 0x6C) = -*(f32 *)(o + 0x60) / 30.0f;
        *(f32 *)(o + 0x70) = -*(f32 *)(o + 0x64) / 30.0f;
        *(u32 *)(o + 0x74) = 0x3F800000;
        *(s32 *)(o + 0x48) = (s32)func_00417A40() % 0x10000;
        *(s32 *)(o + 0xD0) = 0x27;
    }
}
