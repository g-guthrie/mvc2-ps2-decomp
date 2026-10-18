typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD0;

void func_0019EB80(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_0019F3A0(u8 *, u8 *);
    u8 *o, *w;
    f32 d;
    f32 z, lim;
    o = *(u8 **)(p + 0x18);
    w = o + 0x2B8;
    lim = 102.85713958740234f + D_004F1FD0;
    if (lim < *(f32 *)(p + 0x38)) {
        p[4]++;
        return;
    }
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = *(f32 *)(p + 0x34) - *(f32 *)(o + 0x34);
    if (d < z) d = -d;
    if (!(d < 80.0f)) {
        w[0x11] = 1;
    }
    p[0x24] = 0;
    func_00175700(p);
    func_0019F3A0(p, q);
}
