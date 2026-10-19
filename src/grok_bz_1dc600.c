typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00175670(u8 *);
extern s8 *D_004C2840;

void func_001DC600(u8 *p, u8 *q)
{
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s8 *g = D_004C2840;
        s8 a = *(s8 *)(p + 0x22);
        p[0x13C] = (u8)((g[0x1C] + a) & 1);
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430))
        p[4]++;
}
