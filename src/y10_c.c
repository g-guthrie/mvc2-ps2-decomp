typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_002FB860(f32 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    u8 *q = (u8 *)p;
    f32 *a1, *a2;
    func_00175700((u8 *)p);
    a1 = &p[0x18];
    a2 = &p[0x1B];
    p[0xE] += p[0x18];
    p[0x18] += p[0x1B];
    {
        s16 v = *(s16 *)(q + 0x1C);
        *(s16 *)(q + 0x1C) = v - 1;
        if (v == 0) {
            u32 t = q[6];
            u32 pp;
            q[6] = t + 1;
            *(u32 *)a1 = 0;
            *(u32 *)a2 = 0;
            pp = *(u16 *)(q + 0x35E);
            if (pp & 0x2000) {
                q[0x168] = 2;
            } else if (pp & 0x1000) {
                q[0x168] = 3;
            } else {
                q[0x168] = 1;
            }
            func_001757E0(q, 0xF, q[0x168]);
        }
    }
}

typedef struct { f32 x, y, z, w; } V4d;
void func_00183C40(u8 *p) {
    extern int func_00175700(u8 *);
    u32 u, w;
    u8 *q;
    s8 v = *(s8 *)(p + 0x150);
    u = v & 0xFF;
    if (v < 0) {
        q = *(u8 **)(p + 0x164);
        func_00175700(p);
        w = u & 0xFF;
        if (w != *(s8 *)(p + 0x150)) {
            if ((w & 0x40) == 0) {
                if ((u & 0xF) == 0) {
                    return;
                }
                {
                    u8 k = u & 0xF;
                    q -= (k - 1) * 20;
                }
            } else {
                q += (u8)((w & 0x3F) << 2);
            }
            *(u8 **)(p + 0x164) = q;
            *(V4d *)(p + 0x150) = *(V4d *)q;
            *(f32 *)(p + 0x160) = *(f32 *)(q + 0x10);
            *(s8 *)(p + 0x152) = *(s8 *)(p + 0x152) + 1;
            func_00175700(p);
        }
    }
}

extern u8 D_00458A90[];
extern u8 D_00458A80[];
s32 func_002ABEA0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *tab;
    if (*(s8 *)(p + 0x539) != 0 && p[0x20D] == 2) {
        tab = D_00458A90;
    } else {
        tab = D_00458A80;
    }
    if (func_00189310(p, tab, p + 0x3A0) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return 0;
        }
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] != 2) {
        p[0x1FD] = 1;
    } else {
        p[0x1FD] = 0xC;
    }
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_00457CB0[];
s32 func_00295340(u8 *p) {
    extern s32 func_00189310();
    extern s32 func_0018AA10();
    extern void func_0018A990();
    extern void func_0011D8F8();
    extern void func_00186A60();
    s16 buf;
    if (func_00189310(p, D_00457CB0, p + 0x3A8) == 0) {
        return 0;
    }
    if (func_0018AA10(p, 0x300, &buf) == 0) {
        if (func_0018AA10(p, 0x60, &buf) == 0) {
            return 0;
        }
    }
    func_0018A990(p, p + 0x3A8);
    func_0011D8F8(p + 0x3A0, 0, 8);
    func_0011D8F8(p + 0x3C8, 0, 8);
    func_0011D8F8(p + 0x3E0, 0, 8);
    p[0x1FD] = 6;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

s32 func_001650A0(u8 *p, s32 b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern s32 func_0016A3F0();
    extern void func_00186CE0();
    extern s32 func_00165180();
    s32 a;
    u32 t;
    if (func_0016B240(p, 0) == 0) {
        return 0;
    }
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 3);
    if (func_0016A3F0(p) != 0) {
        return 0;
    }
    a = *(s8 *)(p + 0x211);
    if (a != 0 && (a & (1 << p[0x1E6])) != 0) {
        return 0;
    }
    t = p[0x451];
    p[0x451] = t + 1;
    *(f32 *)(p + 0x460) = *(f32 *)(p + 0x4C8);
    *(f32 *)(p + 0x464) = *(f32 *)(p + 0x34);
    *(s32 *)(p + 0x468) = 0xB;
    *(s32 *)(p + 0x46C) = 0;
    func_00186CE0(p, 0xB);
    return func_00165180(p, b);
}

