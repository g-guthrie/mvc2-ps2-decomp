typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 D_004D18A0;
extern u8 D_004F20B0[];
extern void func_0018AD80(u8 *);

void func_001E8530(void)
{
    s32 i;
    u8 *p;
    u8 *q;
    s8 f;
    if ((u8)D_004D18A0 < 4)
        return;
    p = D_004F20B0;
    for (i = 0; i < 6; i++, p += 0x5B8) {
        if (p[0] == 0)
            continue;
        f = p[0x1B3];
        if (f == 0)
            continue;
        q = *(u8 **)(p + 0x1C8);
        if ((s8)q[0x1B0] & 0x20) {
            p[0x1B3] = (u8)(f | 0x40);
            continue;
        }
        p[0x1B6] = q[0x1B5];
        *(u8 **)(p + 0x1CC) = D_004F20B0 + q[0x1B8] * 0x5B8;
        p[0x1BA] = (*(u8 **)(p + 0x1CC))[0x1E6];
        p[0x1B9] = p[0x1E6];
        func_0018AD80(p);
    }
}
