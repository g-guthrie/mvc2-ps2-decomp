typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00285310(u8 *p)
{
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    s16 v;
    s16 x;
    u32 t;
    f32 f;
    o = *(u8 **)(p + 0x1DC);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        *(f32 *)(o + 0x34) += *(f32 *)(o + 0x5C);
        *(f32 *)(o + 0x5C) += *(f32 *)(o + 0x68);
        *(f32 *)(o + 0x38) += *(f32 *)(o + 0x60);
        *(f32 *)(o + 0x60) += *(f32 *)(o + 0x6C);
    } else {
        t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 1;
        o[0x1B5] = 0x22;
        x = o[0x1E6] ^ 1;
        *(s16 *)(o + 0x140) = x;
        o[0x1E6] = x;
        func_001266A0(p, 0, 0);
        if (p[0x1E6] != 0) f = 6.666666507720947f; else f = -6.666666507720947f;
        *(f32 *)(p + 0x5C) = f;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 1, 10);
    }
}
