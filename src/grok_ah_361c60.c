typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00361F90(u8 *);
extern void func_001E7F60(u8 *);

void residual_00361C60(u8 *p, u8 *q)
{
    s32 *z0;
    s32 *z1;
    u8 *r;
    z1 = (s32 *)(p + 0x6C);
    z0 = (s32 *)(p + 0x60);
    r = q + 0x2B8;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00361F90(p);
    if (q[0x169] != p[0xD1]) {
        p[4]++;
    } else if ((s8)p[0x1B3] != 0) {
        p[4]++;
    } else {
        func_001E7F60(p);
        if (r[9] != 0) {
            p[5]++;
            *z0 = 0;
            *z1 = 0;
            *(s16 *)(p + 0x1C) = (p[0x21] << 1) + 0x1E;
        }
    }
}
