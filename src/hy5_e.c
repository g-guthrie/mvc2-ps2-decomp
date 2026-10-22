typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FE0[];

void func_002DADC0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700();
    s16 v;
    s32 b;
    f32 f, o, k;
    u32 t;
    p[0x209] = 2;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        f = *(f32 *)(p + 0x430);
        if (!(*(f32 *)(p + 0x38) <= f - 34.28571319580078f)) {
            goto rest;
        }
        *(f32 *)(p + 0x38) = f;
        p[0x20D] = 0;
    }
    p[6] = 4;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x15, 0x14);
    return;
rest:
    b = *(s8 *)(p + 0x1B2);
    if (b != 0) {
        if (((s8)b & 0x11) != 0) {
            t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0x20;
            *(s32 *)(p + 0x2C0) = 0x10;
            k = 1.6666666269302368f;
            if (*(s16 *)(p + 0x140) != 0) {
                k = -k;
            }
            *(f32 *)(p + 0x5C) = k;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x60) = 0x41AB6DB6;
            *(u32 *)(p + 0x6C) = 0xBF892492;
            func_001757E0(p, 0x16, 0xB);
            return;
        }
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x5C) / 24.0f;
        *(f32 *)(p + 0x6C) = -*(f32 *)(p + 0x60) / 24.0f;
    }
    o = *(f32 *)(p + 0x38);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x38) <= D_004F1FE0[0])) {
        *(f32 *)(p + 0x38) = o;
    }
    func_00175700(p);
}
