typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C[];
extern f32 D_004F1FE8[];

void func_00285190(u8 *p)
{
    u8 *o;
    u32 t;
    s16 v;
    f32 a;
    f32 c;
    double k;
    extern void func_001266A0(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00178F20(u8 *, u8 *);

    o = *(u8 **)(p + 0x1DC);
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = p[6];
    p[6] = t + 1;
    *(s16 *)(p + 0x1C) = 0x12C;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_001266A0(p, 1, 1, 2);
    if (p[0x1E6] != 0) {
        a = D_004F1F4C[0];
    } else {
        a = D_004F1F4C[0] - 26.666666f;
    }
    *(f32 *)(p + 0x34) = a;
    k = 240.0;
    *(f32 *)(p + 0x38) = (f32)(k + (double)D_004F1FE8[0] - 360.0);
    func_001757E0(p, 0x16, 0xE);
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    if (p[0x1E6] != 0) {
        c = 0.104166664f;
    } else {
        c = -0.104166664f;
    }
    *(f32 *)(p + 0x5C) = c;
    *(s32 *)(p + 0x68) = 0;
    v = p[0x1E6] ^ 1;
    *(s16 *)(o + 0x140) = v;
    o[0x1E6] = v;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(f32 *)(o + 0x5C) = (f32)((double)*(f32 *)(p + 0x5C) / 2.0);
    *(s32 *)(o + 0x68) = 0;
    func_00178F20(p, o);
}
