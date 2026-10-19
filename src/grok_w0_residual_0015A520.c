typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

void residual_0015A520(u8 *p)
{
    u32 t = *(u32 *)(p + 0xD4);
    s16 w;

    if (t != 0) {
        *(u32 *)(p + 0xD4) = t - 1;
        return;
    }
    w = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = w;
    if (w != 0)
        return;
    p[0x13C] = 1;
    p[4]++;
    *(s16 *)(p + 0x1C) = 4;
}
