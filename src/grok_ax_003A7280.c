typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_001745B0(u8 *, u8 *);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_003A7280(u8 *p, u8 *q)
{
    {
        int ok = func_001745B0(p, q);
        if (!ok)
            p[0x13C] = 0;
        else
            p[0x13C] = 1;
    }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        p[4]++;
    } else if (*(s8 *)(p + 0x1B3)) {
        p[4]++;
    } else {
        func_001E7F60(p);
        if (*(s8 *)(p + 0x1B2))
            p[4]++;
    }
}
