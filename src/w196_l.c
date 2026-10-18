typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0018A460(u8 *a, u8 *b, u8 *c, s32 d)
{
    extern s32 func_0018A6C0(u8 *);
    extern s32 func_0018A7A0(u8 *);
    extern s32 func_0018A580(u8 *);
    u32 f;
    f = *(u16 *)(b + 2);
    if ((f & 0x4000) == 0) {
        if ((f & 0x20) != 0) {
            if ((a[0x15A] & 0xE0) != 0) return 0;
        }
        if ((f & 0x800) != 0) {
            if (func_0018A6C0(a) == 0) return 0;
        } else if ((f & 0x100) != 0) {
            if (func_0018A7A0(a) == 0) return 0;
        } else {
            if (func_0018A580(a) == 0) return 0;
        }
    }
    if ((f & 0x2000) != 0) {
        if (a[0x20D] != 2) return 0;
    }
    if ((f & 0x1000) != 0) {
        if (a[0x20D] == 2) return 0;
    }
    c[0] = 0;
    *(s16 *)(c + 6) = d;
    return 1;
}
