typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003ACA80(u8 *p, s16 *q) {
    extern void func_001E7F60(u8 *);
    u8 *Y; u8 *s; u8 *t0; u8 d; u8 *X;
    f32 b, lo, hi, a;
    s32 c;
    X = *(u8 **)(p + 0x18);
    Y = *(u8 **)(p + 0x14);
    s = X + 0x88;
    if (X[0xBC] != 0) {
        t0 = *(u8 **)(p + 8);
        p[0x24] = *(s8 *)(Y + 0x24);
        *(f32 *)(p + 0x34) = *(f32 *)(t0 + 0x34) + (f32)*(s16 *)(t0 + 0x8C) - (f32)q[0];
        *(f32 *)(p + 0x38) = (f32)q[1] + (*(f32 *)(t0 + 0x38) - (f32)*(s16 *)(t0 + 0x8E));
        p[0x13C] = 0;
        d = p[0x22];
        a = *(f32 *)(p + 0x34);
        b = *(f32 *)(s + 0x10);
        lo = a;
        hi = b;
        if ((s8)d < 0) {
            lo = b;
            hi = a;
        }
        if (lo <= hi) {
            s32 e = d;
            a = *(f32 *)(p + 0x38);
            b = *(f32 *)(s + 0x14);
            lo = a;
            hi = b;
            if (e > 0x40 && e < 0xC0) {
                lo = b;
                hi = a;
            }
            if (lo <= hi) goto L;
        }
        c = 1;
        p[0x13C] = c;
        s[0xF] = *(s8 *)(s + 0xF) + 1;
        if (X[5] == 0 && *(s8 *)(s + 0xE) < 4) {
            X[5] = c;
            *(s16 *)(s + 8) = 0xA00;
            *(s16 *)(s + 8) = 0;
            *(f32 *)(X + 0x68) = 4.0f;
        }
    L:
        {
        s8 v = *(s8 *)(s + 0xE) - 1;
        s[0xE] = v;
        if (v <= 0 && X[5] < 2) {
            X[0x15A] = 0x80;
            func_001E7F60(X);
            if (s[0x32] == 0) {
                s[0x32] = 1;
                *(s8 *)(Y + 0x1B0) = -0x80;
            }
        }
        }
    }
}
