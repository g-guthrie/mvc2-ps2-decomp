typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00450E90[];

s32 func_00215E40(u8 *p)
{
    extern s32 func_0018AA50();
    extern s32 func_0018A580();
    extern void func_00186A60();
    u16 loc;
    u8 a;
    if (p[0x2B8] != 0) return 0;
    if (func_0018AA50(p, 0x140, &loc, 1) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (*(s8 *)(p + 0x539) != 0) {
        loc = *(u16 *)(p + 0x20E);
        if (p[0x1E6] != 0) {
            if ((loc & 0xC00) != 0) {
                loc = loc ^ 0xC00;
            }
        }
    } else {
        loc = *(u16 *)(p + 0x354);
    }
    loc = (loc & 0x3C00) >> 10;
    if (loc == 0) {
        loc = 2 - p[0x1E6];
    }
    if (p[0x20D] == 2) {
        loc += 0x10;
    }
    a = D_00450E90[loc];
    if (a == 0) return 0;
    if (p[0x20D] != 2) {
        if ((loc & (1 << p[0x1E6])) != 0) return 0;
    }
    p[0x22] = a - 1;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1B7] = 1;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}
