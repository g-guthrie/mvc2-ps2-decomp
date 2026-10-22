typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00184CA0(u8 *p) {
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_00181D90(u8 *);
    u8 a7;
    u8 lim;
    u8 s1;
    s32 t;
    s32 h;
    s32 v;
    a7 = p[0x1ED];
    lim = (*(u32 *)(p + 0x428) & 0x8000100) ? 2 : 1;
    if (!((a7 & 0x7F) < lim)) return 0;
    if (*(s8 *)(p + 0x539) != 0) {
        t = *(s8 *)(p + 0x4BA);
        if (!(t & 2)) return 0;
        p[0x4BA] = t & ~2;
    } else {
        if (!(a7 & -128)) {
            if (!(*(u16 *)(p + 0x354) & 0x2000)) {
                p[0x1ED] = a7 | 0x80;
            }
            return 0;
        }
        h = *(u16 *)(p + 0x35E);
        if (!(h & 0x2000)) return 0;
        p[0x1E7] = (h & 0xC00) ? (h & 0x400) >> 10 : -1;
    }
    t = *(s8 *)(p + 0x1E7);
    if (t == 0) {
        p[0x168] = 1;
    } else if (t == 1) {
        p[0x168] = 2;
    } else {
        p[0x168] = 0;
    }
    if (p[1] == 5) p[0x168] += 6;
    s1 = 1;
    do {
        func_00175910(p, 1, p[0x168], s1);
        s1++;
    } while (*(s8 *)(p + 0x151) & 0xF);
    t = *(s8 *)(p + 0x1ED);
    p[0x1ED] = (t + 1) & 0x7F;
    p[0x1EA] = 0x11;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x210] != 0) {
        p[0x210] = 0;
        func_00181D90(p);
        p[0x210] = 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        return 1;
    }
    func_00181D90(p);
    return 1;
}
