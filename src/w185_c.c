typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct O {
    u8 p0[0xC];
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 p1c[4];
    s32 f20;
    s32 f24;
    u8 p28[0x10];
    s32 (*f38)(s32, s32);
    s32 f3C;
} O;

s32 func_0040FC08(O *o, s32 m, s32 lim, s32 *out)
{
    extern void func_0040EFE0(void);
    extern void func_0040EFF8(void);
    s32 r;
    func_0040EFE0();
    if (m == 0) {
        r = (o->f20 - o->f14) + o->f24;
        if (o->f10 < r) r = o->f10;
        r = (r < lim) ? r : lim;
    } else if (m == 1) {
        r = (o->f20 - o->f18) + o->f24;
        if (o->f0C < r) r = o->f0C;
        r = (r < lim) ? r : lim;
    } else {
        r = 0;
        if (o->f38 != 0) o->f38(o->f3C, -3);
    }
    *out = r;
    func_0040EFF8();
    return r == lim;
}
