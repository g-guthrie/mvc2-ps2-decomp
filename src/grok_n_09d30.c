typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);

void residual_00209D30(u8 *p)
{
    func_00175700(p);
    p[6]++;
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = p[0x1E6] ? (47.5f / 3.0f) : -(47.5f / 3.0f);
    *(f32 *)(p + 0x68) = p[0x1E6] ? -0.3125f : 0.3125f;
    *(s16 *)(p + 0x1C) = 0xE;
    func_001E3210(p, 6);
}
