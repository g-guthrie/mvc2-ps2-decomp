typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00446C40[];

void func_0018CA30(u8 *p, u32 idx) {
    u8 *o;
    f32 a;
    f32 k;
    f32 lim;
    o = *(u8 **)(p + 0x1CC);
    if (o == 0) o = *(u8 **)(p + 0x220);
    k = 1.6666666269302368f;
    a = k * (f32)D_00446C40[idx & 0xFF] / 256.0f;
    *(u32 *)(p + 0x68) = 0x3FFD5555;
    if (p[0x1BA] != 0) {
        a = -a;
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    if ((a < 0.0f && *(f32 *)(o + 0x5C) < 1.6666666269302368f) ||
        (a > 0.0f && *(f32 *)(o + 0x5C) > -1.6666666269302368f)) {
        a += *(f32 *)(o + 0x5C);
    }
    lim = (a > 0.0f) ? 31.666666030883789f : -31.666666030883789f;
    if (a > 0.0f) {
        if (!(a <= lim)) a = lim;
    } else {
        if (a < lim) a = lim;
    }
    *(f32 *)(p + 0x22C) = a;
}
