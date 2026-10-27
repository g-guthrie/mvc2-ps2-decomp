typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00449280[];

void func_00191D40(u8 *p)
{
    u32 a2;
    s32 a1;
    u32 t;
    s32 v;
    extern void func_00191ED0(u8 *);
    extern void func_00185490(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_00188110(u8 *);
    extern void func_00175700(u8 *);
    extern void func_00191EF0(u8 *, s32);
    extern void func_00191F20(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001927D0(u8 *, s32, s32);
    extern void func_00191F50(u8 *);

    if (p[0x215] == 0) {
        func_00191ED0(p);
        return;
    }
    func_00185490(p);
    if (func_00184720(p) != 0) return;
    if (func_00185A90(p) != 0) return;
    if (func_00188110(p) != 0) return;
    p[0x250] = (*(u16 *)(p + 0x35E) & 0x3C00) >> 10;
    if (p[6] == 0) {
        func_00175700(p);
        if (p[0x250] == 0) return;
        t = p[6];
        p[6] = t + 1;
        func_00191EF0(p, p[0x250]);
        return;
    }
    func_00175700(p);
    a1 = p[0x250];
    if (a1 == 0) {
        p[6] = 0;
        func_00191F20(p, p[0x250]);
        func_001E3210(p, 0x2B);
        return;
    }
    if (p[0x22] != (u8)a1) {
        func_00191EF0(p, a1);
    }
    a2 = D_00449280[p[0x22]];
    if (p[0x1E6] != 0) {
        a2 = (u8)(32 - (s8)a2) & 0x1F;
    }
    switch (p[1]) {
    case 0x34:
        func_001927D0(p, 0x320, a2);
        v = 2;
        break;
    default:
        func_001927D0(p, 0x258, a2);
        v = 2;
        break;
    }
    p[0x20D] = v = 2;
    func_00191F50(p);
}
