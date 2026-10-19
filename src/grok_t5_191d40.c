typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed int s32;

extern void func_00191ED0(u8 *);
extern void func_00185490(u8 *);
extern s32 func_00184720(u8 *);
extern s32 func_00185A90(u8 *);
extern s32 func_00188110(u8 *);
extern s8 func_00175700(u8 *);
extern void func_00191EF0(u8 *, s32);
extern void func_00191F20(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001927D0(u8 *, s32, s32);
extern void func_00191F50(u8 *);

extern u8 D_00459280[];

void func_00191D40(u8 *p)
{
    u8 a2;
    if (p[0x215] == 0) {
        func_00191ED0(p);
        return;
    }
    func_00185490(p);
    if (func_00184720(p) != 0) {
        return;
    }
    if (func_00185A90(p) != 0) {
        return;
    }
    if (func_00188110(p) != 0) {
        return;
    }
    p[0x250] = (*(u16 *)(p + 0x35e) & 0x3c00) >> 10;
    if (p[6] == 0) {
        func_00175700(p);
        if (p[0x250] == 0) {
            return;
        }
        p[6]++;
        func_00191EF0(p, p[0x250]);
        return;
    }
    func_00175700(p);
    if (p[0x250] == 0) {
        p[6] = 0;
        func_00191F20(p, p[0x250]);
        func_001E3210(p, 0x2b);
        return;
    }
    {
        u8 b = p[0x250];
        if (p[0x22] != (u8)b) {
            func_00191EF0(p, b);
        }
    }
    a2 = D_00459280[p[0x22]];
    if (p[0x1e6] != 0) {
        a2 = (32 - (s32)(s8)a2) & 0x1f;
    }
    if (p[1] == 52) {
        func_001927D0(p, 800, a2);
    } else {
        func_001927D0(p, 600, a2);
    }
    p[0x20d] = 2;
    func_00191F50(p);
}
