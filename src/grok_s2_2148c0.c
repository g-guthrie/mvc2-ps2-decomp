typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 *func_001E7FD0(u8 *);

u8 *func_002148C0(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    u8 *r;
    unsigned int a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 2; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 5; return r; }
        }
    }
    return 0;
}

u8 *func_002478C0(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    u8 *r;
    unsigned int a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 0; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 1; return r; }
        }
    }
    return 0;
}
