typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 func_0018A080(u8 *a, u8 *tab, s8 *st) {
    extern u8 func_0018A380(u8 *, u8 *, s8 *);
    extern u8 func_0018A460(u8 *, u8 *, s8 *);
    u16 *e;
    u32 t, k, h;
    s8 v = st[1] - 1;
    st[1] = v;
    if (v <= 0) {
        return *(u8 *)st = 0;
    }
    e = (u16 *)((((u8)st[2]) << 1) + (u32)tab);
    t = e[4];
    k = (*(u16 *)(a + 0x362) & 0x3F60) & t;
    k &= 0xFFFF;
    if (k != 0) {
        h = *(u16 *)(tab + 2);
        if ((h & 0x8000) == 0x8000) {
            if ((u16)k == t) return func_0018A380(a, tab, st);
            t = *(u8 *)st;
            *(u8 *)st = t + 1;
        } else {
            if ((h & 0x40) == 0x40) return func_0018A460(a, tab, st);
            return func_0018A380(a, tab, st);
        }
    }
    return 0;
}
