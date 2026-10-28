typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
extern GA *D_004C2794;
typedef struct { u8 pad[0x1C]; s32 f1c; } GB;
extern GB *D_004C2840;

void func_00353C80(u8 *p) {
    extern void func_00353F90(u8 *, u8 *);
    extern void func_00354000(u8 *, u8 *);
    extern s32 func_00174470(u8 *);
    extern void func_003540B0(u8 *, u8 *);
    extern void func_003543E0(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *d, *s, *q;
    u32 t;

    p[0x13C] = 0;
    q = *(u8 **)(p + 0x8C);
    s = q + 0x88;
    d = p + 0x88;
    if (q[4] != 1 || (*(u8 **)(p + 8))[4] >= 3) {
        p[4] = 2;
        return;
    }
    *(s8 *)d = *(s8 *)s;
    if (*(u16 *)(s + 8) >= p[0x20]) {
        *(u16 *)(d + 0xC) = 0;
        *(u16 *)(d + 0xA) = 0;
    } else {
        *(u16 *)(d + 0xA) = *(u16 *)(s + 0xA);
        *(u16 *)(d + 0xC) = *(u16 *)(s + 0xC);
    }
    func_00353F90(p, *(u8 **)(p + 8));
    func_00354000(p, d);
    if ((*(u8 **)(p + 8))[0x20] == 0) {
        s32 v = 0x68;
        if (D_004C2840->f1c & 1) v = 0x69;
        *(u8 **)(p + 0x1D4) = (u8 *)((s32)*(u8 **)(p + 0x17C) + v * 16);
    }
    t = p[0x20];
    p[0x20] = t + 1;
    if (func_00174470(p) == 0) {
        p[4] = 2;
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[0x1B3] = 0;
        d[2] = 0;
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        s32 n, c;
        p[0x1B2] = 0;
        d[2] = 0;
        func_003540B0(p, d);
        func_003543E0(p);
        if (*(u16 *)(s + 8) <= (c = p[0x20])) {
            n = c - 1;
            if ((s8)n > 0) *(u16 *)(s + 8) = n;
            else *(u16 *)(s + 8) = 1;
            *(u16 *)(s + 0xA) = *(u16 *)(d + 0xA);
            *(u16 *)(s + 0xC) = *(u16 *)(d + 0xC);
            s[0xE] = 8;
        }
    } else {
        p[0x1B0] = 0x42;
        if (d[1] == 0 && d[2] == 0) p[0x1B0] = 0;
        p[0x1B5] = (*(u8 **)(p + 0x18))[0x1B5];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001E7F60(p);
    }
}
