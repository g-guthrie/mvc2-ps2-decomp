typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044AF20[];
void func_001A1860(u8 *a, u8 *b) {
    extern void func_00175910();
    extern void func_001757E0();
    u8 *c;
    u8 *q;
    s32 i;
    s32 n;
    s32 v;
    c = b + 0x2B8;
    n = *(s16 *)(a + 0x1E);
    i = 1;
    if (n > 1) do {
        q = *(u8 **)(a + 0xC);
        if (*(s8 *)(q + 0x13C) == 0) break;
        func_00175910(a, 0x17, (u8)(D_0044AF20[a[0x23]] + 0x10), a[0x22]);
        i++;
        a = q;
    } while (i < n);
    v = 0x13;
    if (c[5] > 0) v++;
    func_001757E0(a, 0x17, (u8)v);
}

void func_00251CA0(u8 *p) {
    extern void func_00175700();
    extern void func_00367F90();
    extern void func_001AD170();
    s32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00367F90(p, 1, *(s16 *)(p + 0x1E) & 3);
        func_001AD170(p, 6, *(s16 *)(p + 0x1E) & 3);
        func_001AD170(p, 0xF, *(s16 *)(p + 0x1E) & 3);
        *(s16 *)(p + 0x1E) += 1;
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if ((s16)t == 0) {
            t = p[6];
            p[6] = t + 1;
        }
    }
}

void func_0021BE10(u8 *p) {
    extern void func_0015D010();
    extern void func_001266A0();
    u32 v[4];
    s32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if ((s16)t < 0) {
        p[0x152] = 1;
        v[0] = 0x41D55555;
        v[1] = 0x42892492;
        func_0015D010(p, v);
        p[0x1B4] = 10;
        func_001266A0(p, 1, 1);
    }
}

void func_00285490(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *a3, *t0, *t1, *t2;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x5C);
    t1 = (f32 *)(p + 0x68);
    t0 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t2 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        *(u32 *)t1 = 0;
        *(u32 *)t2 = 0;
        func_001757E0(p, 0x16, 0xF);
    }
}

void func_002FF690(u8 *p) {
    extern void func_001266A0();
    extern void func_001757E0();
    extern void func_002FFB00();
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    extern void func_001D91E0();
    u32 v[4];
    func_001266A0(p, 5, 5);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 1);
    func_002FFB00(p, (u8 *)((s32)p + 0x2B8));
    v[0] = 0xC2AA0000;
    v[1] = 0x4331DB6D;
    v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
    *(s16 *)(p + 0x1C) = 0x3C;
    *(u32 *)(p + 0x60) = 0x3F892492;
    *(u32 *)(p + 0x6C) = 0;
    func_001D91E0(p, 3, 0);
    func_001D91E0(p, 3, 1);
}


extern s16 D_00446C20[];
void func_0018F1A0(u8 a, u8 b, f32 *out) {
    extern f32 func_00417500();
    extern f32 func_00417440();
    s16 ang;
    f32 f;
    f = D_00446C20[b];
    ang = ((0x28 - a) & 0x1F) << 11;
    out[0] = 1.6666666269302368f * (f * func_00417500(ang) / 150.0f);
    out[1] = 2.142857074737549f * (f * func_00417440(ang) / 125.0f);
}

void func_002AB1F0(u8 *p) {
    extern void func_0015D010();
    extern void func_001266A0();
    extern void func_001757E0();
    u32 v[4];
    s16 t;
    t = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    *(*(u8 **)(p + 0x1DC) + 0x1E6) = t;
    if (p[0x22] & 1) {
        t = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = t;
        p[0x1E6] = t;
        t = p[0x1E6] ^ 1;
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
        *(*(u8 **)(p + 0x1DC) + 0x1E6) = t;
    }
    v[0] = 0x42055555;
    v[1] = 0x43430000;
    v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_001757E0(p, 0xF, 0);
}

void func_002313B0(u8 *p) {
    extern void func_001266A0();
    extern void func_001757E0();
    u8 *q;
    u32 t;
    s32 n = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = n - 1;
    if (n == 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x24;
        q[0x20D] = 2;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        p[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        if (*(s16 *)(p + 0x140) != 0) {
            *(u32 *)(p + 0x5C) = 0xC1555555;
            *(u32 *)(p + 0x68) = 0;
        } else {
            *(u32 *)(p + 0x5C) = 0x41555555;
            *(u32 *)(p + 0x68) = 0;
        }
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_001757E0(p, 0x16, 7);
    }
}

void func_00348A80(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_001E7F60();
    u8 *c = q + 0x2B8;
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0 || *(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        u32 t;
        c[0x1A] = 0;
        t = p[5];
        p[5] = t + 1;
        p[0x169] = 0x15;
        p[0x168] = 0xE;
        func_001757E0(p, p[0x169], p[0x168]);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700();
    func_001E7F60(p);
}

s32 func_00232840(u8 *p) {
    extern s32 func_001E7FD0();
    s32 t, r;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) return 0;
    t = p[0x20D];
    if (t == 1) return 0;
    if (p[0x1B7] == 0) return 0;
    if (p[0x212] != 0) {
        if (t == 2) return 0;
        if ((r = func_001E7FD0(p)) != 0) {
            p[0x20B] = 1;
            return r;
        }
    } else if (t == 2) {
        if ((r = func_001E7FD0(p)) != 0) {
            p[0x20B] = 2;
            return r;
        }
    } else {
        if ((r = func_001E7FD0(p)) != 0) {
            p[0x20B] = 0;
            return r;
        }
    }
    return 0;
}

s32 func_002E80A0(u8 *p) {
    extern s32 func_001E7FD0();
    u8 *c = p + 0x2B8;
    s32 r;
    if (*(s8 *)(p + 0x2C1) != 0) return 0;
    if (*(s8 *)(c + 0xC) != 0) return 0;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) return 0;
    if (p[0x1B7] == 0) return 0;
    if (p[0x212] == 0) {
        if (p[0x20D] != 2) {
            if ((r = func_001E7FD0(p)) != 0) {
                p[0x20B] = 0;
                return r;
            }
        } else {
            if ((r = func_001E7FD0(p)) != 0) {
                p[0x20B] = 1;
                return r;
            }
        }
    } else {
        if ((r = func_001E7FD0(p)) != 0) {
            p[0x20B] = 2;
            return r;
        }
    }
    return 0;
}

void func_002F9B20(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001D8AB0();
    extern void func_00183210();
    extern void func_00175C00();
    extern void func_00131AB0();
    extern void func_002F8E40();
    u32 v[4];
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        t = p[7];
        p[7] = t + 1;
        func_001D8AB0(p, 2, 0);
        v[0] = 0x413AAAAA;
        v[1] = 0x43092492;
        func_00183210(p, v, 3);
        func_00175C00(p, 0);
        q[0x16] = 1;
        q[0xD] = 3;
        *(s16 *)(q + 0xE) = 0x1A4;
        q[0x14] = 0;
        q[0x15] = 0;
        func_00131AB0(p, (u8 *)((s32)q + 0xE), 6);
        p[0x214] = 0;
        *(s16 *)(p + 0x3FE) = 0;
        *(s16 *)(p + 0x3FA) = 0;
        p[0x402] = 0;
    }
    func_002F8E40(p);
}



void func_0019E3F0(u8 *p) {
    extern u8 *func_003DA750();
    extern void func_001757E0();
    extern void func_0019DFD0();
    u8 *q = *(u8 **)(p + 0x18);
    u8 *o;
    p[5] = 0;
    p[0x13C] = 0;
    if (p[0x21] == 0) {
        *(s16 *)(p + 0x140) = 0;
        if (q[2] == 0) p[0x168] = 0x23;
        else p[0x168] = 0x24;
        func_001757E0(p, 0x17, p[0x168]);
        if ((o = func_003DA750(p, 3, 2)) != 0) {
            *(void **)(o + 0x10) = (void *)func_0019DFD0;
            *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(o + 0x14) = p;
            o[0x20] = 5;
            o[0x21] = 1;
            *(s16 *)(o + 0x26) = 0xB00;
            o[0x13C] = 0;
        }
    } else {
        if (q[2] == 0) p[0x168] = 0x25;
        else p[0x168] = 0x26;
        func_001757E0(p, 0x17, p[0x168]);
    }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
void func_0039EC60(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_0039EF70();
    extern void func_0039E4E0();
    extern void func_001E7F60();
    u32 t;
    s32 v;
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        if (p[5] == 0) {
            if (func_00175700(p) < 0) {
                t = p[5];
                p[5] = t + 1;
                func_001757E0(p, 0x16, 0xB);
                return;
            }
        } else {
            if (func_00175700(p) < 0) {
                func_0039EF70(p);
                return;
            }
            v = *(s8 *)(p + 0x151);
            if (v & 1) {
                p[0x151] = v ^ 1;
                func_0039E4E0(p, 0);
            }
            func_001E7F60(p);
        }
    }
}

extern s32 D_0044FE00[];
extern u8 D_004D18A6;
void func_001FFC90(u8 *p) {
    extern void func_00175700();
    extern void func_00176160();
    extern void func_001757E0();
    s32 v;
    u32 t;
    p[0x405] = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x2CA] = 6;
    func_00175700(p);
    if (p[0x15B] != 0) {
        func_00176160(p, 2, *(s8 *)(p + 0x150) + D_0044FE00[p[0x25]], 1);
    }
    v = *(s16 *)(p + 0x1C);
    if (v != 0) {
        *(s16 *)(p + 0x1C) = v - 1;
    } else {
        p[0x404] = 0;
        p[0x405] = 0;
        if ((D_004D18A6 & (1 << p[2])) == 0) {
            *(s16 *)(p + 0x1C) = 0x46;
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x16, 0x1B);
        }
    }
}

void func_0021B110(u8 *p) {
    extern void func_00175700();
    extern void func_00183210();
    extern void func_00131AB0();
    u32 v[4];
    s32 t;
    u32 u;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = *(s8 *)(p + 0x151);
        p[0x151] = t ^ 1;
        v[0] = 0x41200000;
        v[1] = 0x4311B6DB;
        func_00183210(p, v, 1);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u = p[6];
        p[6] = u + 1;
        t = *(s8 *)(p + 0x151);
        p[0x151] = t ^ 1;
        p[0x214] = 1;
        *(s16 *)(p + 0x3FE) = 0x1E0;
        func_00131AB0(p, (u8 *)((s32)p + 0x3FE), 2);
    }
}

void func_00322E20(u8 *p) {
    extern void func_001863F0();
    extern s8 func_00175700();
    extern void func_003266E0();
    extern void func_003CD6B0();
    s32 t;
    f32 k;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) {
        func_003266E0(p);
        return;
    }
    t = *(s8 *)(p + 0x151);
    if (t != 0) {
        func_003CD6B0(p, (s8)t - 1);
        p[0x151] = 0;
    }
    if (p[0x15B] != 0) {
        k = -6.666666507720947f;
        if (*(s16 *)(p + 0x140) != 0) k = -k;
        *(f32 *)(p + 0x34) += k;
    }
}

void func_00316800(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_00316940();
    u8 *s0;
    f32 *s1, *s2;
    u32 t, u;
    s0 = *(u8 **)(p + 0x1DC);
    p[0x152] = 1;
    func_00175700(p);
    s1 = (f32 *)(p + 0x60);
    s2 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) = *(f32 *)(s0 + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00316940(p, q);
    t = q[0x17];
    q[0x17] = t - 1;
    if (t == 0) {
        u = p[6];
        p[6] = u + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)s1 = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)s2 = 0;
        *(u32 *)(p + 0x60) = 0x41892492;
        *(f32 *)(p + 0x34) = *(f32 *)(s0 + 0x34);
        *(f32 *)(p + 0x38) -= 34.2857131958f;
    }
}

void func_002B0BD0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 *v1, *a3, *t0, *t1;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t1 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        *(u32 *)v1 = 0;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        *(u32 *)t1 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x16, 5);
        func_00183d50(p);
    }
}
