typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004517C0[];

s32 func_002271E0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern s32 func_0022C5D0(u8 *);
    f32 v;
    f32 z;
    f32 d;

    if (func_00175700(p) < 0) {
        return func_0022C5D0(p);
    }
    z = 0.0f;
    v = (f32)*(s8 *)(p + 0x151);
    if (!(v <= z)) {
        p[0x151] = 0;
        d = D_004517C0[(s32)v];
        if (p[0x1E6] == 0) d = -d;
        *(f32 *)(p + 0x34) += d;
    } else {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x68) = z;
    }
}
