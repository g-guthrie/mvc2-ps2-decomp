typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003B9580(u8 *p)
{
    extern void func_003BA140(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    u8 *o;
    u8 *t;
    f32 k;
    f32 d;

    o = *(u8 **)(p + 0x18);
    t = p + 0xD0;
    func_003BA140(p);
    p[0x24] = 0xB;
    k = 53.33333206176758f;
    *(f32 *)(t + 8) = *(f32 *)(o + 0x430);
    *(s16 *)(p + 0x1E) = p[0x21] + 1;
    if (o[0x1E6] != 0) k = -k;
    *(f32 *)(p + 0x34) -= k;
    *(f32 *)(p + 0x38) += 240.0f;
    func_001757E0(p, 0x17, p[0x21] + 0xC);
    if (o[0x1B7] == 0) {
        k = 160.0f;
        if (o[0x1E6] == 0) k = -k;
        *(f32 *)(t + 4) = *(f32 *)(o + 0x34) + k;
    } else {
        *(f32 *)(t + 4) = *(f32 *)(*(u8 **)(o + 0x220) + 0x34);
    }
    *(s32 *)(p + 0x6C) = 0;
    *(s32 *)(p + 0x68) = 0;
    d = 64.0f;
    *(f32 *)((s32)p + 0x5C) = (*(f32 *)(t + 4) - *(f32 *)(p + 0x34)) / d;
    *(f32 *)((s32)p + 0x60) = (*(f32 *)(t + 8) - *(f32 *)(p + 0x38)) / d;
    *(f32 *)(p + 0x34) += 16.0f * (*(f32 *)(p + 0x5C) * (f32)(u32)p[0x21]);
    *(f32 *)(p + 0x38) += 16.0f * (*(f32 *)(p + 0x60) * (f32)(u32)p[0x21]);
}
