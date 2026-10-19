typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00185550(u8 *);

void func_0018D030(u8 *p)
{
    s8 *q;
    f32 f;
    func_00185550(p);
    if (*(int *)(p + 0x1C8) == *(int *)(p + 0x1CC))
        (*(u8 **)(p + 0x1CC))[0x209] = 3;
    q = *(s8 **)(p + 0x228);
    f = (f32)*q;
    if (f > 0.0f) {
        *(s8 **)(p + 0x228) = q + 1;
        if (!p[0x1E6])
            f = -f;
        *(f32 *)(p + 0x34) += 1.6666666f * f;
    }
}
