typedef unsigned char u8;
typedef unsigned short u16;

extern int func_001E7FD0(u8 *);

int func_00242D50(u8 *p)
{
    if (p[0x20D] == 1)
        return 0;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0)
        return 0;
    if (p[0x1B7] == 0)
        return 0;
    if (p[0x212] == 0) {
        if (p[0x20D] != 2) {
            if (func_001E7FD0(p))
                p[0x20B] = 0;
        } else {
            if (func_001E7FD0(p))
                p[0x20B] = 2;
        }
    } else {
        if (p[0x20D] == 2)
            return 0;
        if (func_001E7FD0(p))
            p[0x20B] = 1;
    }
    return 0;
}
