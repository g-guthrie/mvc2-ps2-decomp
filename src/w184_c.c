typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_00496A50[];


f32 func_00417500(u32 a)
{
    switch (a & 0xC000) {
    case 0:
        return D_00496A50[0x4000 - (a & 0xFFFF)];
    case 0x4000:
        return -D_00496A50[a & 0x3FFF];
    case 0x8000:
        return -D_00496A50[0xC000 - (a & 0xFFFF)];
    case 0xC000:
        return D_00496A50[a & 0x3FFF];
    }
    return 0.0f;
}

s32 func_0035AB80(u8 *p)
{
    extern s32 func_001E8310(u8 *, u8 *, s16, s16);
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u32 v;
    s0 = *(u8 **)(p + 0x18);
    s1 = *(u8 **)(p + 0x1D4);
    s2 = *(u8 **)(s0 + 0x1D4);
    if (func_001E8310(p, s0, (s32)s1[0xC], (s32)s2[4]) != 0) {
        return 1;
    }
    if (func_001E8310(p, s0, (s32)s1[0xC], (s32)s2[6]) != 0) {
        return 1;
    }
    if (func_001E8310(p, s0, (s32)s1[0xC], (s32)s2[8]) != 0) {
        return 1;
    }
    v = *(u16 *)(s2 + 0xA);
    if (v != 0) {
        if (func_001E8310(p, s0, (s32)s1[0xC], (s32)(v & 0xFF)) != 0) {
            return 1;
        }
    }
    return 0;
}
