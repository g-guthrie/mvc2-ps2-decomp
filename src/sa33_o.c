typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004D18A0[];
u8 func_001884C0(u8 *p)
{
    extern s32 func_00186CE0(u8 *, s32);
    u8 *q;
    u8 *e;
    u8 *r;
    u32 x;
    s32 t;
    q = p + 0x370;
    if (p[0x375] != 2) {
        x = p[0x15A] & 0xE0;
        if ((s8)x >= 0) return 0;
        t = *(s8 *)(p + 0x1B2);
        if (t == 0) return 0;
        if (((s8)t & 1) != 0) return 0;
        if ((*(u16 *)(p + 0x35E) & 0x2000) == 0) return 0;
        e = *(u8 **)(p + 0x184) + (p[0x1B5] & 0x7F) * 28;
        if ((e[0x12] & 0x40) == 0) {
            if (e[9] < 0xB) return 0;
            if (((e[8] + 3) & 0x1F) > 5) return 0;
            r = *(u8 **)(p + 0x1C4);
            if (r[3] != 0) r = *(u8 **)(p + 0x220);
            if (r[0x20D] != 2) return 0;
        }
    }
    if (D_004D18A0[0] < 4) return 0;
    if (p[0x20D] == 2) return 0;
    x = p[0x15A] & 0xE0;
    if (x != 0) {
        if (x != 0x80) return 0;
        t = *(s8 *)(p + 0x1B2);
        if (t == 0 || ((s8)t & 1) != 0) return 0;
    }
    if ((*(u8 **)(p + 0x220))[0x249] != 0) return 0;
    q[5] = 0;
    return func_00186CE0(p, 0xD);
}
