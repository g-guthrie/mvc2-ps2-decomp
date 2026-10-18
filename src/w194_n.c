typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A0[];
extern u8 *D_004C2840;

s32 func_003D92F0(u8 *p) {
    u8 *g = D_004D18A0;
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);

    if (D_004D18A0[0] >= 6) {
        u8 *c = D_004C2840;
        s32 v;
        s32 idx;
        if ((s8)c[0x8C] != 0) goto fail;
        if ((s8)c[0x58] != 0) goto fail;
        v = (s8)g[0x3E];
        if (v < 0) return 0;
        idx = p[2];
        if (v != idx) return 0;
        if (g[3] != 0) return 0;
        if ((s8)g[0x34 + (u8)idx] != 1) return 0;
        if ((*(u32 *)(*(u8 **)(p + 0x220) + 0x428) & 0x7000000) != 0) return 0;
        if (p[0x33A] != 0) {
            p[0x33A] = p[0x33A] - 1;
            goto fail;
        }
        if ((*(u16 *)(p + 0x354) & 0x8000) == 0) return 0;
        g[1] = 1;
        g[0x3F] = 1;
        p[0x20C] = *(s8 *)(p + 0x20C) | (s8)0x80;
    }
    func_00185490(p);
    func_00175C00(p, 1);
    func_001266A0(p, 0, 0);
    return 1;
fail:
    p[0x201] = 3;
    p[0x1B1] = 0;
    return 0;
}
