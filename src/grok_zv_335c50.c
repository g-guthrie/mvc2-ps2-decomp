typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003367F0(u8 *);
extern s32 func_00336460(u8 *);
extern s32 func_00336690(u8 *);
extern s32 func_00335390(u8 *);

void func_00335C50(u8 *p)
{
    f32 z = 0.0f;
    f32 v;
    if (func_003367F0(p) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        return;
    }
    if (func_00336460(p) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        return;
    }
    v = *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0)
        v = -v;
    *(f32 *)(p + 0x5C) += v;
    v = *(f32 *)(p + 0x5C);
    if (*(s16 *)(p + 0x140) != 0)
        v = -v;
    *(f32 *)(p + 0x34) += v;
    if (*(f32 *)(p + 0x5C) <= z) {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x60) = z;
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x6C) = z;
        p[7] = 0;
        p[5] = 0;
    } else if (func_00336690(p) == 0 && func_00335390(p) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[7] = 0;
        p[5] = 0;
    }
}
