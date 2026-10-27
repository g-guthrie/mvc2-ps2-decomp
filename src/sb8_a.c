typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 *func_002FB340(u8 *p) {
    extern u8 *func_001E7FD0(u8 *);
    u8 *q;
    u8 *r;
    u8 v;
    v = (s32)(*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    q = p + 0x2B8;
    p[0x22] = v;
    if (v != 0) {
        u32 m;
        m = p[0x212];
        if (m == 0 && p[0x1B7] == 1) {
            if (q[0x16] != 0) return 0;
            if ((r = func_001E7FD0(p)) != 0) {
                p[0x20B] = 1;
                return r;
            }
        } else if (m == 1 && p[0x1B7] == 1) {
            if ((r = func_001E7FD0(p)) != 0) {
                p[0x20B] = 2;
                return r;
            }
        }
    }
    return 0;
}
