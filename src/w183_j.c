typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00447050[];

/* Provisional: func_00185490 requires the actor argument. */
s32 func_00184B30(u8 *p) {
    extern void func_00191210();
    extern s32 func_00185E40(u8 *);
    extern void func_00184AA0(u8 *);
    extern void func_00185490();
    extern void func_00186CE0(u8 *, s32);
    u16 m;
    u32 t;
    if (*(s8 *)(p + 0x203) != 0 || *(s8 *)(p + 0x207) != 0) return 0;
    func_00191210();
    t = p[0x20D];
    if (t == 2 || t == 3) return 0;
    if ((p[0x15A] & 0xE0) != 0) return 0;
    m = *(s16 *)(p + 0x35C) & D_00447050[p[1]];
    if (m == 0) return 0;
    if ((*(u16 *)(p + 0x35E) & 0x3C00) != 0x1800) return 0;
    if (func_00185E40(p) == 0) return 0;
    { u32 c = m; if (c & 0x100) p[0x212] = 0; else p[0x212] = 1; }
    func_00184AA0(p);
    func_00185490();
    func_00186CE0(p, 0x22);
    return 1;
}
