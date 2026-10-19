typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern void func_00174910(u8 *, s16);
extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_00358C50(u8 *p)
{
    f32 one = 1.0f;
    f32 zero = 0.0f;
    f32 cur = *(f32 *)(p + 0x8C);
    one = cur - one;
    *(f32 *)(p + 0x8C) = one;
    if (one < zero) {
        *(u32 *)(p + 0x8C) = 0x40000000;
        p[0x23]++;
        p[0x23] &= 7;
        p[0x22] = (u8)(*(s8 *)(p + 0x20) + *(s8 *)(p + 0x23));
    }
    one = 1.0f;
    zero = 0.0f;
    cur = *(f32 *)(p + 0x88);
    one = cur - one;
    *(f32 *)(p + 0x88) = one;
    if (one == zero) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        func_00174910(p, *(s16 *)(p + 0x1E));
        func_00175700(p);
        if (p[0x21] == 0)
            func_001E7F60(p);
    }
}
