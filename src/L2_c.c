typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00312EC0(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_003131A0(u8 *, u8 *);
    extern void func_001DD8A0(u8 *, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_003C0BE0(u8 *, s32, s32);
    extern void func_00313120(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s8 f;
    s16 h;
    u32 t;
    func_00175700(p);
    f = p[0x151];
    if (f & 1) {
        p[0x151] = f & ~1;
        func_003131A0(p, q);
        func_001DD8A0(p, 2, 0);
    }
    f = p[0x151];
    if (f & 2) {
        p[0x151] = f & ~2;
        func_00175C00(p, 0);
        func_001DD8A0(p, 3, 0);
    }
    f = p[0x151];
    if (f & 0x10) {
        p[0x151] = f & ~0x10;
        func_003C0BE0(p, 0, 0);
        func_003C0BE0(p, 0, 1);
        func_003C0BE0(p, 0, 2);
        func_003C0BE0(p, 0, 3);
        func_003C0BE0(p, 0, 4);
        func_003C0BE0(p, 0, 5);
        func_003C0BE0(p, 0, 6);
        func_003C0BE0(p, 0, 7);
        func_003C0BE0(p, 0, 8);
        func_003C0BE0(p, 0, 9);
    }
    f = p[0x151];
    if (f & 8) {
        p[0x151] = f & ~8;
        q[9] = 0;
        q[10] = 0;
        func_001DD8A0(p, 6, 0);
    }
    if (*(s8 *)(p + 0x151) & 4) {
        func_00313120(p, q);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            t = p[6];
            p[6] = t + 1;
            func_00175C00(p, 0);
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 8));
        }
    }
}
