typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_001BC4C0(u8 *p, u8 *q)
{
    extern void func_001BC650(u8 *, u8 *);
    extern void func_00175670(u8 *);
    u32 *s0, *s1, *s2, *s3;
    s3 = (u32 *)(p + 0x6C);
    s2 = (u32 *)(p + 0x68);
    s1 = (u32 *)(p + 0x60);
    s0 = (u32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    *(u32 *)(p + 0x48) += (u32)(s32)(0.5 + 65536.0 * (double)(-*(s32 *)(p + 0xD4)) / 360.0) & 0xFFFF;
    if (p[1] != q[1]) {
        func_001BC650(p, q);
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[4] = 2;
            p[0x13C] = 0;
            *s0 = 0;
            *s1 = 0;
            *s2 = 0;
            *s3 = 0;
        } else {
            func_00175670(p);
        }
    }
}
