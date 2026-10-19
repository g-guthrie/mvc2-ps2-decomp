typedef unsigned char u8;
typedef float f32;

extern int func_0013C730(u8 *);

void residual_0013C5D0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    f32 f;

    if (q[4] >= 6)
        p[4] = 2;
    else if (func_0013C730(p))
        p[4] = 1;
    else {
        *(int *)(p + 0xD0) |= 0x800000;
        f = *(f32 *)(p + 0x74) - 0.05f;
        *(f32 *)(p + 0x74) = f;
        if (f <= 0.0f)
            *(f32 *)(p + 0x74) = 0.0f;
    }
}
