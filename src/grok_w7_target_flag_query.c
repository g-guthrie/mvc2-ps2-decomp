typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *func_001E7FD0(u8 *);

u8 *func_0030F260(u8 *p)
{
    unsigned int bits;
    u8 *target = 0;
    int selected;

    if (p[0x20D] != 0)
        goto done;
    bits = *(u16 *)(p + 0x20E) & 0x0C00;
    if (bits == 0)
        goto done;
    p[0x22] = bits >> 10;
    if (p[0x1B7] != 1)
        goto done;
    target = func_001E7FD0(p);
    if (target == 0)
        goto done;

    selected = 0;
    if (p[0x212] == 1)
        selected = 1;
    p[0x20B] = selected;
done:
    return target;
}
