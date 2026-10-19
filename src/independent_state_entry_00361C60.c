typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern void func_00361F90(u8 *);
extern void func_001E7F60(u8 *);

void func_00361C60(u8 *p, u8 *q)
{
    f32 *vy = (f32 *)(p + 0x60);
    f32 *ay = (f32 *)(p + 0x6C);
    u8 *c = q + 0x2B8;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00361F90(p);
    if (q[0x169] != p[0xD1])
        p[4]++;
    else if (((s8 *)p)[0x1B3])
        p[4]++;
    else {
        func_001E7F60(p);
        if (c[9]) {
            p[5]++;
            *vy = 0;
            *ay = 0;
            *(s16 *)(p + 0x1C) = (p[0x21] << 1) + 30;
        }
    }
}
