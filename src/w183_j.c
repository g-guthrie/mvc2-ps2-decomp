typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00447050[];

static void func_00184AA0(u8 *a0) {
    if (a0[525] == 2) {
        if (a0[528] == 0) a0[531] = 1;
        else a0[531] = 2;
    } else {
        *(f32 *)(a0 + 56) = *(f32 *)(a0 + 1072);
        if (*(u16 *)(a0 + 852) & 0x1000) a0[525] = 1;
        else a0[525] = 0;
        if (a0[484] == 10 || a0[484] == 11) a0[531] = 3;
        else a0[531] = 0;
    }
}

s32 func_00184B30(u8 *p) {
    extern void func_00191210(u8 *);
    extern s32 func_00185E40(u8 *);
    extern void func_00185490(u8 *);
    extern s32 func_00186CE0(u8 *, u8);
    u16 m;
    u32 t;
    if (*(s8 *)(p + 0x203) != 0 || *(s8 *)(p + 0x207) != 0) return 0;
    func_00191210(p);
    t = p[0x20D];
    if (t == 2 || t == 3) return 0;
    if ((p[0x15A] & 0xE0) != 0) return 0;
    m = *(s16 *)(p + 0x35C) & D_00447050[p[1]];
    if (m == 0) return 0;
    if ((*(u16 *)(p + 0x35E) & 0x3C00) != 0x1800) return 0;
    if (func_00185E40(p) == 0) return 0;
    { u32 c = m; if (c & 0x100) p[0x212] = 0; else p[0x212] = 1; }
    func_00184AA0(p);
    func_00185490(p);
    func_00186CE0(p, 0x22);
    return 1;
}
