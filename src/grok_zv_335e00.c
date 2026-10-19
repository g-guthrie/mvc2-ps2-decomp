typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003367F0(u8 *);
extern s32 func_00336690(u8 *);
extern s32 func_00336460(u8 *);
extern s32 func_00335390(u8 *);

void func_00335E00(u8 *p)
{
    s16 t;
    s32 v;
    f32 d;
    if (func_003367F0(p) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        return;
    }
    if (func_00336690(p) != 0 || func_00336460(p) != 0)
        return;
    t = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = t;
    d = *(f32 *)(p + 0x5C);
    if (*(s16 *)(p + 0x140) != 0)
        d = -d;
    *(f32 *)(p + 0x34) += d;
    *(s32 *)(p + 0x44) = (*(s16 *)(p + 0x140) != 0) ? 0 : 0x8000;
    t = *(s16 *)(p + 0x1E) % 8;
    *(s16 *)(p + 0x1E) = t;
    if (t == 0)
        p[0x20] ^= 1;
    v = -0x889;
    if (p[0x20] != 0)
        v = 0x889;
    *(s32 *)(p + 0x44) = *(s32 *)(p + 0x44) + v;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        if (func_00335390(p) != 0) {
            p[7] = 0;
            p[5] = 0;
            *(s32 *)(p + 0x48) = 0;
        }
    }
}
