typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18EC;

s32 func_00164D10(u8 *p) {
    s32 m;
    s8 t;
    s32 s;
    u8 *q;
    f32 f0, f1, f2;
    if (p[0x1E4] == *(s32 *)(p + 0x468)) {
        t = *(s8 *)(p + 0x4B6) - 1;
        *(s8 *)(p + 0x4B6) = t;
        if (t != 0) {
            if (D_004D18EC == 0) {
                s32 a2 = p[0x1E6];
                m = 2 >> a2;
                s = *(s8 *)(p + 0x211);
                if (*(s8 *)(p + 0x1E7) != 0) m ^= 3;
                if (s == 0 || (s & m) == 0) {
                    q = *(u8 **)(p + 0x220);
                    f1 = *(f32 *)(p + 0x460);
                    if (q[0x1E6] == 0) f1 = -f1;
                    f1 += *(f32 *)(q + 0x34);
                    f2 = *(f32 *)(p + 0x34);
                    f0 = f2;
                    if (*(s32 *)(p + 0x46C) != 0) {
                        f0 = f1;
                        f1 = f2;
                    }
                    f1 = f0 - f1;
                    if (!(f1 <= 0.0f)) {
                        p[0x1E7] = ((*(s32 *)(p + 0x464) ^ ((s32)a2 * 3 << 10)) & 0x400) >> 10;
                        *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x464);
                        return 0;
                    }
                }
            }
        }
    }
    p[0x451]--;
    *(s16 *)(p + 0x4F0) = 0;
    return 1;
}
