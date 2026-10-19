typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0015F580(u8 *);

void residual_0015F7A0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    s16 w;
    s32 d;

    if (q[5] != 0 || q[0x1E4] != 10) {
        if (*(s32 *)(p + 0xD4) == 0)
            p[4] = 1;
        return;
    }
    w = *(s16 *)(p + 0x1E);
    if (w == 0)
        return;
    *(s16 *)(p + 0x1E) = w - 1;
    d = *(s32 *)(p + 0xD4);
    if (d >= 4)
        return;
    w = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = w;
    if (w != 0)
        return;
    *(s16 *)(p + 0x1C) = 8;
    func_0015F580(p);
}
