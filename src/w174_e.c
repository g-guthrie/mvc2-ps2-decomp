typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00257BC0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    f32 z = 0.0f;
    f32 v;
    if (*(s8 *)(p + 0x151) == 1) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > z) {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x60) = z;
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x6C) = z;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (p[0x1E6] != 0) v = 15.83333301544189f; else v = -15.83333301544189f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.625f; else v = 0.625f;
        *(f32 *)(p + 0x68) = v;
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}


void func_001A9940(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    f32 a, b, c, d;
    if (q[4] == 0 && q[0x169] == 0x12 && *(s8 *)(q + 0x151) != 0) return;
    p[7]++;
    p[0x13C] = 1;
    p[0] = 1;
    p[0x24] = 0;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140) ^ 1;
    if (*(s16 *)(q + 0x140) == 0) {
        a = -36.666664123535156f;
        *(f32 *)(p + 0x34) = a + *(f32 *)(q + 0x34);
        *(u32 *)(p + 0x5C) = 0x40555555;
    } else {
        a = -36.666664123535156f;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - a;
        *(u32 *)(p + 0x5C) = 0xC0555555;
    }
    b = 64.28571319580078f;
    *(f32 *)(p + 0x38) = b + *(f32 *)(q + 0x38);
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x17, 0x11);
}

typedef struct { f32 x, y, z; } V3;
extern f32 D_004B38E0[];
extern void func_0014FB00(void);

void func_0014F9F0(u8 *a, s16 b, s32 c) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014FB00;
        *(s32 *)(o + 0xD0) = 0x431;
        *(s16 *)(o + 0x1E) = b;
        o[0x23] = c;
        if (c != 0) {
            *(u32 *)(o + 0x34) = 0x411E8F5C;
        } else {
            *(u32 *)(o + 0x34) = 0x4128CCCD;
        }
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(V3 *)(o + 0x50) = *(V3 *)D_004B38E0;
        func_00150520(o, 1.0f, 0.37439998984336853f, 0.6825000047683716f);
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(u8 **)(o + 0x18) = a;
    }
}

s32 func_002330F0(u8 *p, u8 *q) {
    u8 *r;
    s32 d;
    s32 t;
    f32 x, ax, y;
    r = p + 0x2B8;
    if (p[1] != 0xB) return 0;
    if (r[0xE] != 0) return 0;
    if ((*(s8 *)(q + 0x1B0) & 6) == 0) return 0;
    t = *(s8 *)(r + 0x15);
    if (t == 0) return 0;
    d = 2;
    if ((s8)t > 0) {
        if ((*(u8 **)(q + 0x1D0))[2] & 0x20) return 0;
        d = 4;
    }
    x = *(f32 *)(p + 0x5C);
    ax = x < 0.0f ? -x : x;
    if (ax > 5.0f) {
        *(f32 *)(p + 0x5C) = x / (f32)d;
    } else {
        if (p[0x1E6] != 0) {
            y = 5.0f;
        } else {
            y = -5.0f;
        }
        *(f32 *)(p + 0x5C) = y;
        *(s32 *)(p + 0x68) = 0;
    }
    return 1;
}

void func_00276FE0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001BB8E0(u8 *, s32);
    f32 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
    }
    if (*(s8 *)(p + 0x151) == 3) {
        p[0x151] = 0;
        func_001BB8E0(p, 0);
    }
    if (*(s8 *)(p + 0x151) == 4) {
        p[6]++;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = p[0x1B7] ? 0xC : 8;
        if (p[0x1B7] != 0) {
            if (*(s16 *)(p + 0x140) != 0) v = 30.0f; else v = -30.0f;
            *(f32 *)(p + 0x5C) = v;
        } else {
            if (*(s16 *)(p + 0x140) != 0) v = 26.66666603088379f; else v = -26.66666603088379f;
            *(f32 *)(p + 0x5C) = v;
        }
        if (*(s16 *)(p + 0x140) != 0) v = -1.25f; else v = 1.25f;
        *(f32 *)(p + 0x68) = v;
        func_001BB8E0(p, 1);
    }
}

void func_002AD1F0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00183DF0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *v5c, *v60, *v68, *v6c;
    f32 z = 0.0f;
    v6c = (s32 *)(p + 0x6C);
    v68 = (s32 *)(p + 0x68);
    v60 = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v5c = (s32 *)(p + 0x5C);
    if (*(s32 *)(p + 0xD0) == 0) {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[6]++;
            *v5c = 0;
            *v60 = 0;
            *v68 = 0;
            *v6c = 0;
        }
        if (p[0x15B] != 0) {
            func_00183DF0(p, 3);
        }
    } else {
        if (*(f32 *)(p + 0x68) * *(f32 *)(p + 0x5C) > z) {
            p[6]++;
            func_001757E0(p, 2, 7);
        } else {
            func_00175700(p);
        }
    }
}

void func_001DD270(u8 *p) {
    extern u32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, u8);
    s32 t;
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)(((func_00174170() & 0x3F) - 0x20) << 4) / 256.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)(((func_00174170() & 0x3F) - 0x20) << 4) / 256.0f;
    *(s16 *)(p + 0x1C) = (func_00174170() & 0x1F) + 8;
    t = 6;
    if ((func_00174170() & 3) == 0) t = 7;
    func_001757E0(p, 0x17, t);
}

void func_0026CF90(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001B6750(u8 *, s32);
    u8 *r;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        r = p + 0x2B8;
        if (p[0x20D] == 2) {
            p[0x209] = 3;
        }
        p[0x151] = 0;
        r[2] = 0;
        r[3] = 0;
        p[0x152] = 1;
        func_00175700(p);
        func_001B6750(p, 1);
        func_001B6750(p, 3);
        func_001B6750(p, 4);
        func_001B6750(p, 5);
        func_001B6750(p, 6);
        func_001B6750(p, 7);
        if (p[0x20D] == 0) {
            func_001B6750(p, 8);
        }
        if (p[0x1B7] == 0) {
            *(s16 *)(p + 0x1C) = 0x26;
            *(u32 *)(p + 0x5C) = 0xC1C80000;
            *(u32 *)(p + 0x68) = 0x3FA00000;
        } else {
            *(s16 *)(p + 0x1C) = 0x32;
            *(u32 *)(p + 0x5C) = 0xC2055555;
            *(u32 *)(p + 0x68) = 0x3FBAAAAA;
        }
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
