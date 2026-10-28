typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0027BA50(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 10;
        *(s16 *)(p + 0x1E) = 0;
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x38);
        *(s32 *)(p + 0x118) = 0;
        func_001757E0(p, 0x13, 3);
    }
}

s32 func_002A46D0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern s32 func_001843A0(u8 *);
    extern s32 func_001E7FD0(u8 *);
    extern s32 func_00185640(u8 *, s32);
    s32 o;
    if (func_00175700(p) < 0) {
        return func_001843A0(p);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        if ((o = func_001E7FD0(p)) != 0) {
            p[6] = 0;
            p[0x20B] = 0xC3;
            return func_00185640(p, o);
        }
    }
}

void func_001D1A60(u8 *p, u8 *q) {
    extern void func_001D1AF0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001D1AE0(u8 *);
    if (p[1] == q[1] && *(s32 *)(p + 0xD0) == q[0x169] && *(s32 *)(p + 0xD4) == q[0x168]) {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        func_001D1AF0(p);
        func_00175700(p);
        *(s8 *)(p + 0x13C) = *(s8 *)(p + 0x13C) ^ 1;
    } else {
        func_001D1AE0(p);
    }
}

typedef struct { f32 value[3]; } PoseVector;
typedef struct { PoseVector values[3]; } PoseRow;
extern PoseRow data_f32v3x3_004B1730[12];
/* Provisional: row selector and interpolation helper linkage need proof. */
void func_0013DF10(u8 *p) {
    extern void func_0013DB00(u8 *, s32, s32);
    s16 v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v + 1;
    if (v != 8) {
        func_0013DB00(p, 8, 1);
        return;
    }
    {
        u32 t = p[5];
        p[5] = t + 1;
    }
    *(PoseVector *)(p + 0x34) = data_f32v3x3_004B1730[p[0x20] + p[0x23] * 6].values[2];
}

void func_002C9660(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x161) != 0) {
        q[4] = 1;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
    }
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 2;
        p[0x13C] = 0;
        p[0x209] = 1;
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_00323330(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3710(p, 0x2C);
        func_00183d50(p);
        func_001757E0(p, 0x12, 2);
    }
}

void func_001B78B0(u8 *p) {
    extern void func_00175670(u8 *);
    extern void func_001E3210(u8 *, s32);
    u8 *q = *(u8 **)(p + 0x18);
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[4];
        p[4] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(u32 *)(p + 0x60) = 0x41092492;
        func_001E3210(p, 0x1E);
    }
}

s32 func_00167550(u8 *p, u8 *q) {
    extern s32 func_0016B250(u8 *, s32);
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(u8 *, u8 *, s32);
    u16 v;
    if (func_0016B250(p, 2) == 0) {
        return 0;
    }
    if (func_0016B360(p, q) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    func_0016B0C0(p, q, 1);
    v = ((*(s16 *)(p + 0x4C8) * 256) & 0x3C00) | 0x20;
    if (v & 0xC00) {
        v = v ^ (p[0x1E6] * 3 << 10);
    }
    *(u16 *)(p + 0x4F0) = v;
    return 0;
}

typedef struct { f32 f[5]; } A5_0014C100;
extern A5_0014C100 D_004440B0;
extern A5_0014C100 D_004440D0;
void func_0014C100(u8 *p) {
    extern void func_0014C0E0(f32);
    A5_0014C100 a = D_004440B0;
    A5_0014C100 b = D_004440D0;
    u32 i = p[5];
    f32 lim = a.f[i];
    s32 d = *(s8 *)(p + 4);
    {f32 t = b.f[i];
    *(f32 *)(p + 0x34) += t * (f32)d;}
    if (d < 0) {
        if (*(f32 *)(p + 0x34) <= lim) {
            func_0014C0E0(lim);
        }
    } else if (d > 0) {
        if (!(*(f32 *)(p + 0x34) < lim)) {
            func_0014C0E0(lim);
        }
    }
}

void func_0025DE00(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s16 *)(p + 0x1C) == 0) {
        f32 a;
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            a = 0.3125f;
        } else {
            a = -0.3125f;
        }
        *(f32 *)(p + 0x68) += a;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        func_001757E0(p, 2, 3);
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
}

void func_00239A90(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00126400(void);
    func_00175700(p);
    if (p[0x15B] != 0) {
        u8 *q;
        u32 v;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x15B] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        v = p[0x1E6];
        q[0x1E6] = v;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        *(s16 *)(q + 0x140) = *(s16 *)(q + 0x140) ^ 1;
        {
            u32 w = q[0x1E6];
            q[0x1E6] = w ^ 1;
        }
        func_00126400();
        *(u32 *)(p + 0x5C) = 0x40D55555;
        *(u32 *)(p + 0x68) = 0xBE555555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        *(u32 *)(p + 0x60) = 0x412B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

typedef struct { f32 x, y, z; } V3_003AD3A0;
void func_003AD3A0(u8 *a, u8 *s, u8 *r) {
    extern void func_0018FDB0(u8 *);
    extern void func_00158C70(V3_003AD3A0 *, s32);
    u8 *q;
    if (*(u16 *)(r + 0x12) != 0) {
        u8 c;
        *(u16 *)(r + 0x12) = 0;
        c = 0;
        if (*(u16 *)r < 10) {
            u16 w = *(u16 *)(r + 0x14);
            c = 1;
            if ((w & 0xC00) != 0) {
                *(u16 *)(r + 0x14) = w ^ 0xC00;
            }
        }
        r[0x11] = c;
        *(u8 **)(*(u8 **)(s + 0x1DC) + 0x1C8) = s;
        (*(u8 **)(s + 0x1DC))[0x1B5] = 0x38;
        func_0018FDB0(s);
        q = *(u8 **)(s + 0x1DC);
        if (*(s16 *)(q + 0x434) != 0) {
            V3_003AD3A0 v;
            v = *(V3_003AD3A0 *)(q + 0x34);
            v.y = *(f32 *)(*(u8 **)(s + 0x1DC) + 0x430);
            func_00158C70(&v, (*(u8 **)(s + 0x1DC))[2]);
            a[5] = 3;
            s[6] = 0xB;
        }
    }
}

void func_0026C800(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *a, *c, *b, *d;
    func_00175700(p);
    a = (s32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    b = (s32 *)(p + 0x68);
    c = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (s32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) > *(f32 *)(p + 0x38)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 2, 3);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a = 0;
        *c = 0;
        *b = 0;
        *d = 0;
    }
}

void func_00231190(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_001549B0(u8 *, u32 *);
    extern void func_00190D50(u8 *, u8 *);
    extern void func_001E3B70(u8 *, u32);
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
    } else if (*(s8 *)(p + 0x150) != 0) {
        u32 v[4];
        u8 *r = *(u8 **)(q + 4);
        u32 t;
        *(u8 **)(r + 0x1C8) = p;
        p[0x1B5] = *(s8 *)(p + 0x150) + 0x4C;
        r[0x1B5] = *(s8 *)(p + 0x150) + 0x4C;
        p[0x150] = 0;
        func_0018FDB0(p);
        v[0] = 0xC2A00000;
        v[1] = 0x43092492;
        func_001549B0(p, v);
        func_00190D50(*(u8 **)(q + 4), p);
        t = p[0x15B];
        if (t != 0) {
            func_001E3B70(*(u8 **)(p + 0x1DC), (u8)((u8)t - 1));
            p[0x15B] = 0;
        }
    }
}
