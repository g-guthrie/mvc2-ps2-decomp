typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x362]; u16 h362; } P_d;

s32 func_00187BB0(u8 *p)
{
    extern s32 func_001882D0(u8 *);
    extern s32 func_0018AA50(u8 *, s32, u16 *, s32);
    u8 *q;
    u16 buf;
    s8 c;
    u32 t;
    p[0x36D] = 0;
    q = p + 0x368;
    t = p[0x1E4];
    if (t == 0x12 || t == 0x13) {
        if (func_001882D0(p) == 0) return 0;
    }
    if ((*(u8 **)(p + 0x220))[0x249] != 0) return 0;
    if (func_0018AA50(p, 0x300, &buf, 0) != 0) {
        *(u16 *)(q + 6) = *(u16 *)(p + 0x35E);
    } else if (q[0] == 0) {
        buf = *(u16 *)(p + 0x362);
        if ((buf &= 0xC00) == 0) return 0;
        if (buf != ((P_d *)p)->h362) return 0;
        q[0] = 1;
        *(u16 *)(q + 6) = buf;
        q[1] = 15;
        return 0;
    } else {
        c = q[1] - 1;
        q[1] = c;
        if (c < 0) {
            q[0] = 0;
            return 0;
        }
        buf = *(u16 *)(p + 0x362);
        if ((buf &= 0xC00) == 0) return 0;
        if (buf != ((P_d *)p)->h362) return 0;
        if (buf != *(u16 *)(q + 6)) return 0;
        if (p[0x20D] == 1) return 0;
    }
    q[0] = 0;
    q[5] = 1;
    q[4] = (*(u16 *)(q + 6) & 0x400) >> 10;
    return 1;
}
