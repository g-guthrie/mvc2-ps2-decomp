typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00187D70(u8 *p) {
    extern s32 func_00186CE0(u8 *, u8);
    u8 *q; u8 a;
    if ((*(u32 *)(p + 0x428) & 0x7000000) != 0) return 0;
    q = p + 0x368;
    if (p[0x36D] == 1) {
        q[5] = 0;
        if (q[4] == 0) { a = 10; } else { if (p[1] == 1) return 0; a = 11; }
        if (p[0x1E4] == a) goto zero;
        return (u8)func_00186CE0(p, a);
    }
    zero:
    return 0;
}
