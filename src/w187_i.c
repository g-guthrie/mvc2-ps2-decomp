typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003F6510(s32, s32 *, s32 *, s32 *, s32 *);

s32 func_003F6908(s32 a0, s32 a1, s16 *a2, s8 *a3, s8 *t0, s8 *t1, s8 *t2, s32 *t3, s32 *p9, s32 *p10) {
    s32 l0;
    s32 l4;
    s32 l8;
    s32 lC;
    s32 v;
    s32 d;
    if (a1 < 0x1000) {
        *a2 = 0;
        return -1;
    }
    v = func_003F6510(a0, &l0, &l4, &l8, &lC);
    if (v == 0) return -1;
    d = v - a0;
    *a2 = d;
    if ((d << 16) <= 0) return -1;
    *t3 = l0;
    *t2 = (u8)l4;
    *t0 = (u8)l8;
    *p9 = lC;
    *a3 = -1;
    *t1 = (*t2 * *t0) / 8;
    *p10 = 1;
    return 0;
}
