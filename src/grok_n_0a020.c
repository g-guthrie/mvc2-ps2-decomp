typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_0020A020(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    p[6]++;
    *(f32 *)(p + 0x5C) = p[0x1E6] ? -(50.0f / 3.0f) : (50.0f / 3.0f);
    *(f32 *)(p + 0x68) = p[0x1E6] ? 0.3125f : -0.3125f;
}
