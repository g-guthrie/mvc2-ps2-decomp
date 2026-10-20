typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_00455C50[];

s32 func_002866F0(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (p[0x2C0] == 0) {
        if (func_00189310(p, D_00455C50, p + 0x398) == 0)
            return 0;
        if (p[0x20D] == 2 || q[5] || q[6] || *(s8 *)(q + 7))
            return 0;
        func_0018A990(p, p + 0x398);
        p[5] = 0;
        p[7] = 0;
        p[6] = 0;
        p[0x1FD] = 6;
        func_00186A60(p, 0x15);
        return 1;
    }
    if (func_00189310(p, D_00455C50, p + 0x398) == 0)
        return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0 && p[0x210] == 0)
            return 0;
        (*(s8 *)(p + 0x1E8))++;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    return 1;
}
