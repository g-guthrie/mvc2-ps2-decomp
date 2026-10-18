typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18EC;

s32 func_00164480(u8 *p) {
    s8 t;
    s8 m;
    u8 *q;
    f32 a, b, c;
    if (p[0x1E4] == *(s32 *)(p + 0x468)) {
        t = *(s8 *)(p + 0x4B6) - 1;
        *(s8 *)(p + 0x4B6) = t;
        if (t != 0 && D_004D18EC == 0) {
            m = *(s8 *)(p + 0x211);
            if (m == 0 || (m & (2 >> p[0x1E6])) == 0) {
                q = *(u8 **)(p + 0x220);
                a = *(f32 *)(p + 0x460);
                if (q[0x1E6] == 0) a = -a;
                a += *(f32 *)(q + 0x34);
                b = *(f32 *)(p + 0x34);
                c = b;
                if (p[0x1E6] != 0) { c = a; a = b; }
                a = c - a;
                if (a > 0.0f) {
                    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x46C);
                    p[0x1E7] = 0;
                    return 0;
                }
            }
        }
    }
    {
        u32 u = p[0x451];
        p[0x451] = u - 1;
        *(s16 *)(p + 0x4F0) = 0;
        return 1;
    }
}
