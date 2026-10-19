typedef unsigned char u8;
typedef float f32;

extern int func_0013C730(u8 *);

void residual_0013C5D0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    if (q[4] >= 6)
        p[4] = 2;
    else if (func_0013C730(p))
        p[4] = 1;
    else {
        *(unsigned *)(p + 0xD0) |= 0x800000u;
        {
            f32 z = 0.0f;
            f32 f = *(f32 *)(p + 0x74) - 0.05f;
            if (f <= z)
                f = z;
            *(f32 *)(p + 0x74) = f;
        }
    }
}
