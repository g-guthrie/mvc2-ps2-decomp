typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_0062BFD8;

s32 func_003DC2F0(u32 x, u8 *q) {
    extern void func_0010CA20();
    extern u32 *func_003DD030();
    extern void func_0010CA68();
    s32 r = -1;
    u32 n;
    u32 off;
    u32 *cnt;
    func_0010CA20();
    n = *(u32 *)(q + 4) - 1;
    off = D_0062BFD8 << 2;
    cnt = (u32 *)(off + (u32)q + 0x14);
    if (*cnt <= n) {
        u32 old;
        u32 *buf;
        u8 *b;
        u32 *c;
        r = 0;
        buf = func_003DD030(*(u32 *)(off + (u32)q + 0xC));
        *cnt += 1;
        b = (u8 *)off + (u32)q;
        old = *(u32 *)(b + 0x1C);
        *(u32 *)(b + 0x1C) = old + 1;
        buf[old] = x;
        c = (u32 *)(b + 0x1C);
        if (*c == *(u32 *)(q + 4))
            *c = 0;
    }
    func_0010CA68();
    return r;
}
