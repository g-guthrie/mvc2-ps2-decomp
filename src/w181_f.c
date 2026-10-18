typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_003053D0(u8 *p)
{
    extern void func_00308AB0(u8 *, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00307760(u8 *, u8 *);
    u8 *q;
    s32 a2;
    s16 t;
    s8 c;
    q = p + 0x2B8;
    *(s16 *)(p + 0x3F8) = 2;
    a2 = *(s8 *)(p + 0x2C8);
    if (a2 != 0) {
        if (*(u16 *)(p + 0x168) == *(u16 *)(q + 0x12)) {
            q[0x10] = a2 - 1;
            c = *(s8 *)(p + 0x151);
            if (c != 0) {
                func_00308AB0(p, (u8)(((c << 24) >> 24) - 1));
                p[0x151] = 0;
            }
        } else {
            q[0x10] = 0;
        }
    }
    if (p[0x215] != 0 && p[5] == 0)
        goto doA;
    if (p[0x215] != 0 && p[5] == 1)
        return;
    if (q[8] != 0) {
        q[8] = 0;
        func_00175C00(p, 0);
    }
    return;
doA:
    t = *(s16 *)q - 1;
    *(s16 *)q = t;
    if (t == 0) {
        if (p[0x1E4] == 0x15) {
            *(s16 *)q = 1;
            return;
        }
        func_00307760(p, q);
    }
}
