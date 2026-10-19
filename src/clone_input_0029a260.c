/* Dispatch ignores the selected target pointer returned by this input gate. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_001E7FD0(u8 *);

u8 *func_0029A260(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    u8 *r;
    u32 a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 1; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 0; return r; }
        }
    }
    return 0;
}
