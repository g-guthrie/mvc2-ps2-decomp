typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 *func_001E7FD0(void);

s32 residual_002BE550(u8 *p)
{
    u8 dir;
    u8 a1;
    u8 *hit;

    dir = (u8)((*(u16 *)(p + 0x20E) & 0xC00) >> 10);
    p[0x22] = dir;
    if (dir == 0)
        return 0;
    a1 = p[0x212];
    if (a1 == 0) {
        if (p[0x1B7] == 1) {
            p[0x22] ^= 3;
            hit = func_001E7FD0();
            if (hit) {
                p[0x20B] = 5;
                return (s32)hit;
            }
            return 0;
        }
    }
    if (a1 != 1)
        return 0;
    if (p[0x1B7] != 1)
        return 0;
    hit = func_001E7FD0();
    if (hit) {
        p[0x20B] = 0;
        return (s32)hit;
    }
    return 0;
}
