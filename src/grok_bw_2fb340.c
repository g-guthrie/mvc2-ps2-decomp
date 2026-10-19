typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_001E7FD0(void);

s32 func_002FB340(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    s32 r;
    u8 *slot = p + 0x2B8;

    p[0x22] = (u8)x;
    if ((u8)x == 0)
        return 0;
    if (p[0x212] == 0) {
        if (p[0x1B7] == 1) {
            if (slot[0x16])
                return 0;
            r = func_001E7FD0();
            if (r) {
                p[0x20B] = 1;
                return r;
            }
        }
    } else if (p[0x212] == 1) {
        if (p[0x1B7] == 1) {
            r = func_001E7FD0();
            if (r) {
                p[0x20B] = 2;
                return r;
            }
        }
    }
    return 0;
}
