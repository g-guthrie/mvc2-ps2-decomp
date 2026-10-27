/* Provisional: callback-table return types and actor selector bounds remain unresolved. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 *func_001E7FD0(u8 *);
u8 *func_002BE550(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20e) & 0xc00) >> 10;
    u8 *r;
    u32 a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1b7] == 1) {
            p[0x22] ^= 3;
            r = func_001E7FD0(p);
            if (r) { p[0x20b] = 5; return r; }
        } else if (a == 1 && p[0x1b7] == 1) {
            r = func_001E7FD0(p);
            if (r) { p[0x20b] = 0; return r; }
        }
    }
    return 0;
}
