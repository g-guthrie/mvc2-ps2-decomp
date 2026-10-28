typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 *func_00242D50(u8 *p)
{
    extern u8 *func_001E7FD0(u8 *);
    u8 *r;
    if (p[0x20D] == 1) return 0;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) return 0;
    if (p[0x1B7] == 0) return 0;
    if (p[0x212] == 0) {
        if (p[0x20D] != 2) {
            r = func_001E7FD0(p);
            if (r != 0) p[0x20B] = 0;
        } else {
            r = func_001E7FD0(p);
            if (r != 0) p[0x20B] = 2;
        }
    } else {
        if (p[0x20D] == 2) return 0;
        r = func_001E7FD0(p);
        if (r != 0) p[0x20B] = 1;
    }
    return r;
}
