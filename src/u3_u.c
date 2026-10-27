typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *func_003F6E70(u8 *, s32, s32 *, s32 *, s32 *, s32 *, s32 *);

s32 func_003F71E0(u8 *a, s32 n, s16 *out, s8 *p3, s8 *p4, s8 *p5, s8 *p6, s32 *p7, s32 *p8, s32 *p9, s32 *p10) {
    struct { s32 l0, l1, l2, l3; } L;
    u8 *r;
    s32 d;
    if (n < 8) {
        *out = 0;
        return -1;
    }
    r = func_003F6E70(a, n, &L.l0, &L.l1, &L.l2, &L.l3, p10);
    if (r == 0) return -1;
    d = r - a;
    *out = d;
    if ((s16)d <= 0) return -1;
    *p7 = L.l0;
    *p6 = ((u8 *)&L.l1)[0];
    *p4 = ((u8 *)&L.l2)[0];
    *p8 = L.l3;
    *p3 = -1;
    *p5 = (*p6 * *p4) / 8;
    *p9 = 1;
    return 0;
}
