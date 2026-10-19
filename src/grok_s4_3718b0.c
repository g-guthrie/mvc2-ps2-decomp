typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00175700(u8 *);

void func_003718B0(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    unsigned bits = 0x3d75c28f;
    f32 f;
    if (o[6] != 2) {
        p[4]++;
        return;
    }
    if (*(f32 *)(p + 0x118) != 0.0f) {
        f = *(f32 *)(p + 0x118) - *(f32 *)&bits;
        *(f32 *)(p + 0x118) = f;
        if (f < 0.0f)
            *(f32 *)(p + 0x118) = 0.0f;
    }
    if (*(s8 *)(p + 0x153) < 0) {
        p[5]++;
        p[0x13c] = 0;
    } else {
        func_00175700(p);
    }
}
