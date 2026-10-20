typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C6E0(u8 *);
extern void func_0015D010(u8 *, f32 *);
extern void func_001757E0(u8 *, int, int);

void func_002BEA80(u8 *p)
{
    u8 *o;
    s16 face;
    f32 v[3];
    f32 spd;

    func_0018C6E0(p);
    face = p[0x1E6] ^ 1;
    o = *(u8 **)(p + 0x1DC);
    *(s16 *)(o + 0x140) = face;
    o = *(u8 **)(p + 0x1DC);
    o[0x1E6] = (u8)face;
    if (p[0x1E6])
        spd = 6.666666507720947265625f;
    else
        spd = -6.666666507720947265625f;
    *(f32 *)(p + 0x5C) = spd;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    v[2] = 0.0f;
    v[0] = -43.333332061767578125f;
    v[1] = 75.0f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001757E0(p, 15, 4);
}
