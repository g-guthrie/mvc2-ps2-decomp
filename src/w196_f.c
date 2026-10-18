typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00223000(u8 *p)
{
    extern u32 func_00174170();
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_0019C1C0(u8 *, s32);
    u8 *q;
    s8 v;
    u32 t;
    s32 w;
    p[0x2BA] = 0;
    q = p + 0x2B8;
    if (p[0x2B8] != 0) {
        if (q[1] == 0) q[0] = 0;
    }
    v = *(s8 *)(q + 4) - 1;
    *(s8 *)(q + 4) = v;
    if (v <= 0) {
        q[4] = 4;
        t = q[5] + 1;
        q[5] = t;
        if ((u8)t > 6) {
            q[5] = 0;
            t = func_00174170();
            t = t % 0x30;
            q[4] = *(s8 *)(q + 4) + (s8)(t + 0x10);
        }
        func_00176160(p, 0, q[5] + p[0x25] * 7 + 0x18, 1);
    }
    if (p[0x169] == 0 && (p[0x168] == 2 || p[0x168] == 3)) {
        w = *(s8 *)(p + 0x151);
        if (w != 0) {
            func_0019C1C0(p, (u8)((s8)w - 1));
            p[0x151] = 0;
        }
    }
}
