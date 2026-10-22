typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003210D0(u8 *p)
{
    extern s32 func_001E7FD0();
    s32 r;
    s32 t;
    if (p[0x214] != 0) {
        return 0;
    }
    t = p[0x20D];
    if (t == 1) {
        return 0;
    }
    if (p[0x1B7] == 0) {
        return 0;
    }
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) {
        return 0;
    }
    if (p[0x212] != 0) {
        if (t == 2) {
            return 0;
        }
        r = func_001E7FD0();
        if (r != 0) {
            p[0x20B] = 1;
        }
    } else if (t == 2) {
        r = func_001E7FD0();
        if (r != 0) {
            p[0x20B] = 2;
        }
    } else {
        r = func_001E7FD0();
        if (r != 0) {
            p[0x20B] = 0;
        }
    }
    return r;
}
