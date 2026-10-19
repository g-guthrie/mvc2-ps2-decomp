typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_001E7FD0(void);

void residual_0029A260(u8 *p)
{
    int m = (int)(*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    p[0x22] = m;
    m = (u8)p[0x22];
    if (m == 0)
        return;
    if (p[0x212] == 0) {
        if (p[0x1B7] == 1) {
            if (func_001E7FD0()) {
                p[0x20B] = 1;
                return;
            }
            return;
        }
    }
    if (p[0x212] != 1)
        return;
    if (p[0x1B7] != 1)
        return;
    if (func_001E7FD0())
        p[0x20B] = 0;
}
