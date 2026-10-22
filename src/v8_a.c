typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


void func_003857A0(u8 *p) {
    extern void func_003859F0();
    extern void func_00175700();
    u8 *o = *(u8 **)(p + 0x18);
    if (o[5] != 0 || o[0x425] != 0) {
        func_003859F0(p);
        return;
    }
    if (*(s16 *)(*(u8 **)(p + 0x14) + 0x1C) == 0) {
        func_003859F0(p);
        return;
    }
    if (p[5] == 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v > 0) {
            return;
        }
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
        p[0x13C] = 1;
    }
    func_00175700(p);
}

void func_0021A6F0(u8 *p) {
    extern void func_0019B110();
    extern void func_00354460();
    extern void func_001E3210();
    extern void func_001757E0();
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[7] = 0;
    *(s16 *)(p + 0x1C) = 0x11;
    *(s16 *)(p + 0x1E) = 0;
    p[0x1B7] = 0;
    *(u32 *)(p + 0x5C) = 0xC1055555;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    func_0019B110(p, 5);
    func_00354460(p, 0);
    func_001E3210(p, 0x1F);
    func_001757E0(p, 0x16, 7);
}

s32 func_002B1B70(u8 *p) {
    extern s32 func_001E7FD0();
    s32 r = 0;
    if ((*(u16 *)(p + 0x20E) & 0xC00) != 0 && p[0x1B7] != 0 && p[0x20D] != 1) {
        r = func_001E7FD0(p);
        if (r != 0) {
            if (p[0x212] == 0) {
                if (p[0x20D] == 2) {
                    p[0x20B] = 2;
                } else {
                    p[0x20B] = 0;
                }
            } else {
                if (p[0x20D] == 2) {
                    r = 0;
                } else {
                    p[0x20B] = 1;
                }
            }
        }
    }
    return r;
}

void func_00244CC0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_00361070();
    u8 *q = p + 0x2B8;
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    {
        s8 f = p[0x151];
        if (f & 1) {
            p[0x151] = f & ~1;
            func_00361070(p, 0, 0);
        }
    }
    {
        s8 f = p[0x151];
        if (f & 2) {
            p[0x151] = f & ~2;
            q[8] = 1;
        }
    }
}

void func_0016CBD0(u8 *p) {
    extern void func_003DAA40();
    if (p[4] == 0) {
        p[4] = p[4] + 1;
        p[5] = 0;
        *(s16 *)(p + 0x1C) = 100;
    } else if (p[5] == 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v != 0) {
            f32 c = 0.000199999995f;
            *(f32 *)(p + 0x50) -= c;
            *(f32 *)(p + 0x54) -= c;
        } else {
            u32 t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = 0x1E0;
        }
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            func_003DAA40();
        }
    }
}

void func_001C9960(u8 *p) {
    extern void func_001754A0();
    u8 *o = *(u8 **)(p + 0x18);
    p[0x22] = 1;
    *(s16 *)(p + 0x1C) = 0x18;
    *(s16 *)(p + 0x1E) = 0x10;
    *(s8 *)(p + 0x31) = -8;
    *(u32 *)(p + 0x34) = 0xC2555555;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x5C) = 0x40555555;
    *(u32 *)(p + 0x68) = 0xBBD55555;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    {
        s16 v = *(s16 *)(o + 0x140);
        *(s16 *)(p + 0x140) = v;
        if (v != 0) {
            *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(o + 0x38);
    func_001754A0(p, 0x1B, 0x2B);
}

void func_00272D10(u8 *p) {
    extern void func_0018C6E0();
    extern void func_0015D010();
    extern void func_001757E0();
    extern void func_001B87E0();
    if (p[0x22] & 1) {
        s32 v;
        p[0x1E6] = *(s16 *)(p + 0x140) = p[0x1E6] ^ 1;
        v = p[0x1E6] ^ 1;
        (*(u8 **)(p + 0x1DC))[0x1E6] = *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = v;
    }
    func_0018C6E0(p);
    p[0x1B4] = 10;
    {
        V3 v;
        v.x = -60.0f;
        v.y = 188.571426f;
        v.z = 0.0f;
        func_0015D010(p, &v);
    }
    func_001757E0(p, 0xF, 1);
    func_001B87E0(p, 1);
}

void func_002D55B0(u8 *p) {
    extern void func_002D5590();
    extern void func_0015D010();
    extern void func_001757E0();
    extern u8 *func_0039C5B0();
    u8 *r;
    V3 v;
    func_002D5590(p);
    if (p[0x22] & 1) {
        *(s16 *)(p + 0x140) = *(s16 *)(p + 0x140) ^ 1;
        p[0x1E6] = *(s8 *)(p + 0x140);
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) ^ 1;
        (*(u8 **)(p + 0x1DC))[0x1E6] = *(s8 *)(*(u8 **)(p + 0x1DC) + 0x140);
    }
    v.x = -110.0f;
    v.y = 171.428558f;
    v.z = 0.0f;
    func_0015D010(p, &v);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 0);
    r = func_0039C5B0(p, 2);
    if (r != 0) {
        r[0x95] = 3;
    }
}

void func_002B1400(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 *v1, *a3, *t0, *t1;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    t1 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *v1 = 0;
        *a3 = 0;
        *t0 = 0;
        *t1 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x15, 0xA);
        func_00183d50(p);
    }
}

void func_00291540(u8 *p) {
    extern void func_00175700();
    extern void func_00294B20();
    extern void func_001830D0();
    extern u8 D_00456FF0[];
    u8 *q;
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q = p + 0x2B8;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        q[0xB] = 2;
        q[0xA] = 0xFF;
        func_00294B20(p, D_00456FF0);
        v.x = -13.333333f;
        v.y = 105.0f;
        v.z = 0.0f;
        func_001830D0(p, &v, 1);
    }
}

typedef struct {
    u8 p0[0x34];
    f32 f34, f38;
    u8 p3c[0x20];
    f32 f5c, f60;
    u8 p64[4];
    f32 f68, f6c;
    u8 p70[0x3C0];
    f32 f430;
} S_00224BB0;
static void func_00224BB0(S_00224BB0 *p) {
    f32 *v1, *a1, *a2, *a3;
    p->f34 += p->f5c;
    v1 = &p->f5c;
    a2 = &p->f68;
    a1 = &p->f60;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    a3 = &p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *v1 = 0; *a1 = 0; *a2 = 0; *a3 = 0;
    }
}

void func_00224D60(u8 *p) {
    extern void func_00175700();
    extern void func_00175C00();
    extern void func_001830D0();
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    func_00224BB0((S_00224BB0 *)p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_00175C00(p, 0);
        if (p[0x20D] == 2) {
            v.x = 0.0f;
            v.y = 270.0f;
        } else {
            v.x = 10.0f;
            v.y = 267.857147f;
        }
        v.z = 0.0f;
        func_001830D0(p, &v, 1);
    }
}

void func_00265630(u8 *p) {
    extern s32 func_00184720();
    extern void func_00175700();
    extern void func_001757E0();
    f32 *s0, *s1;
    if ((*(u16 *)(p + 0x35E) & 0x360) == 0 || func_00184720(p) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        s0 = (f32 *)(p + 0x5C);
        s1 = (f32 *)(p + 0x68);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_00175700(p);
        p[0x209] = 2;
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v <= 0) {
                u32 t = p[6];
                p[6] = t + 1;
                *s0 = 0;
                *(f32 *)(p + 0x60) = 0;
                *s1 = 0;
                *(f32 *)(p + 0x6C) = 0;
                func_001757E0(p, 0x15, 0xD);
            }
        }
    }
}

void func_00282EA0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    f32 *s0, *s1, *s2, *s3;
    s3 = (f32 *)(p + 0x6C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    s0 = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 2, 2);
    }
}

void func_0031C7E0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            f32 f = 1.6666666f * (f32) * (s8 *)(p + 0x150);
            if (p[0x1E6] == 0) {
                f = -f;
            }
            *(f32 *)(p + 0x34) += f;
        }
        break;
    }
}

void func_001AB210(u8 *p, u8 *o) {
    extern int func_00174470(const void *);
    extern void func_001757E0();
    extern void func_001AB2E0(u8 *, u8 *);
    extern f32 D_004F1FC8;
    extern f32 D_004F1FCC;
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    *(s16 *)(p + 0x1C) = 0x1E;
    *(s16 *)(p + 0x140) = *(s16 *)(o + 0x140);
    if (func_00174470(p) == 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) = 80.0f + D_004F1FCC;
            *(u32 *)(p + 0x5C) = 0xC0FD5555;
        } else {
            *(f32 *)(p + 0x34) = D_004F1FC8 - 80.0f;
            *(u32 *)(p + 0x5C) = 0x40FD5555;
        }
    }
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
    func_001757E0(p, 0x17, 0xD);
    func_001AB2E0(p, o);
}

void func_001C19A0(u8 *p, u8 *o) {
    extern void func_001C1B40();
    extern void func_001C1AE0();
    extern void func_001C1CA0();
    extern void func_001754A0();
    extern void func_001E3210();
    extern void func_001E3270(u8 *, s32, f32);
    extern void func_001C1A80();
    extern u8 D_0044C900[];
    u8 *s0 = o + 0x2B8;
    if (o[0x378] == 0) {
        func_001C1B40(p, o);
        return;
    }
    if (*(s8 *)(o + 0x379) != 0) {
        func_001C1AE0(p, o);
    } else {
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
        func_001C1CA0(p, o, D_0044C900);
        func_001754A0(p, 0x1B, 7);
        s0[2] = 2;
        *(s16 *)(p + 0xD6) = 0x78;
        func_001E3210(o, 0x27);
        func_001E3270(o, 0x27, 0.4f);
        func_001C1A80(p, o);
    }
}

void func_001A02B0(u8 *p, u8 *o) {
    extern void func_001A0390();
    extern void func_001A0880();
    extern void func_001A0620();
    extern void func_001A0540();
    extern u16 D_004D18DC;
    extern u8 D_004D18DB;
    u8 *t0 = o + 0x2B8;
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        if (o[0x1FD] != 3) {
            p[4] = 2;
            func_001A0390(p, o);
        } else {
            s8 v = t0[7];
            if (v == 2 || v == -1) {
                p[4] = 2;
                func_001A0390(p, o);
            } else {
                *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
                p[0x31] = 8;
                func_001A0880();
                func_001A0620(p, o);
                func_001A0540(p, o);
            }
        }
    }
}

void func_001821D0(u8 *p) {
    extern s16 D_004484B4[][3][2];
    if (p[0x210] != 0) {
        s8 v = p[0x1EC];
        if (v < 7) {
            p[0x1EC] = v + 1;
        } else {
            u16 h = *(u16 *)(p + 0x35E);
            if ((h & 0xC00) != 0) {
                f32 d = 1.6666666f * (f32)D_004484B4[p[1]][*(s8 *)(p + 0x1E7)][(h & 0x400) >> 10] / 256.0f;
                if (p[0x1E6] != 0) {
                    *(f32 *)(p + 0x5C) -= d;
                } else {
                    *(f32 *)(p + 0x5C) += d;
                }
            }
        }
    }
}

s32 func_002022F0(u8 *p) {
    extern s32 func_001E7FD0();
    s32 r;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) {
        return 0;
    }
    if (p[0x20D] == 1) {
        return 0;
    }
    if (p[0x1B7] == 0) {
        return 0;
    }
    if (p[0x212] != 0) {
        if (p[0x20D] == 2) {
            return 0;
        }
        r = func_001E7FD0(p);
        if (r != 0) {
            p[0x20B] = 3;
            return r;
        }
    } else if (p[0x20D] == 2) {
        r = func_001E7FD0(p);
        if (r != 0) {
            p[0x20B] = 2;
            return r;
        }
    } else {
        r = func_001E7FD0(p);
        if (r != 0) {
            p[0x20B] = 0;
            return r;
        }
    }
    return 0;
}
