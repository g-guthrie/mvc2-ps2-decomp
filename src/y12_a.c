typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18EC[];
extern f32 D_00462550[];
extern f32 D_00462554[];
extern f32 D_00451998[];
typedef struct { u8 pad[0x2B8]; s32 s2B8; u8 pad2[0x3C]; s32 s2F8, s2FC, s300; } G2E;

void func_001C56D0(u8 *p) {
    extern s32 func_00174240();
    extern void func_00175670();
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0 || func_00174240() == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175670(p);
    }
}

void func_001F6530(u8 *p) {
    extern void func_001266A0();
    extern void func_0015D010();
    extern void func_0018C6E0();
    extern void func_001757E0();
    u32 v[4];
    u8 *q;
    if (*(u16 *)(p + 0x2B8) & 0x800) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] = *(s8 *)(p + 0x140);
        q = *(u8 **)(p + 0x1DC);
        *(s16 *)(q + 0x140) ^= 1;
        q[0x1E6] = *(s8 *)(q + 0x140);
    }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B4] = 10;
    p[7] = 0;
    p[6] = 0;
    func_001266A0(p, 5, 5);
    v[0] = 0xC3055555;
    v[1] = 0x435EDB6D;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 3);
}

void func_001AAEE0(u8 *p, u8 *q) {
    extern void func_00175700();
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    if (q[0x1E4] == 0x1D) {
        switch (q[0x1FD]) {
        case 5:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0xF;
            p[7] = 0;
            return;
        case 4:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0x11;
            p[7] = 0;
            return;
        default:
            return;
        }
    }
}

void func_003148B0(u8 *p) {
    extern void func_00175700();
    extern s32 func_00185980();
    extern void func_00185640();
    u8 *q;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u32 t;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        t = p[6];
        p[6] = t + 1;
    } else if (func_00185980(p) != 0) {
        q = *(u8 **)(p + 0x1C4);
        p[0x20B] = 2;
        p[0x20B] |= 0x40;
        p[0x20B] |= 0x80;
        p[7] = 0;
        p[6] = 0;
        *(u32 *)(q + 0x6C) = 0;
        *(u32 *)(q + 0x68) = 0;
        *(u32 *)(q + 0x60) = 0;
        *(u32 *)(q + 0x5C) = 0;
        func_00185640(p, q);
    }
}

s32 func_001646A0(u8 *p) {
    if (p[0x1E4] == *(s32 *)(p + 0x464)) {
        s8 v = *(s8 *)(p + 0x4B6) - 1;
        *(s8 *)(p + 0x4B6) = v;
        if (v != 0 && D_004D18EC[0] == 0) {
            s32 a = *(s8 *)(p + 0x211);
            if (a == 0 || (a & (2 >> p[0x1E6])) == 0) {
                u8 *o = *(u8 **)(p + 0x220);
                f32 t = *(f32 *)(p + 0x460);
                f32 m, d, x;
                if (o[0x1E6] == 0) t = -t;
                t += *(f32 *)(o + 0x34);
                m = *(f32 *)(p + 0x34);
                x = m;
                if (p[0x1E6] != 0) { x = t; t = m; }
                d = x - t;
                if (!(d <= 0.0f)) {
                    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x468);
                    return 0;
                }
            }
        }
    }
    p[0x451] -= 1;
    *(s16 *)(p + 0x4F0) = 0;
    return 1;
}

void func_001D4A60(u8 *a, u8 *b) {
    extern void func_00175700();
    extern void func_001D4B40();
    u32 t;
    u8 *c;
    a[0x24] = *(s8 *)(b + 0x24);
    *(s8 *)(a + 0x31) = -2;
    *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
    func_00175700(a);
    t = a[5];
    if (t == 0) {
        if (*(s8 *)(b + 0x151) != 0) {
            a[5] = t + 1;
            a[0x13C] = 1;
        }
        func_001D4B40(a, b);
        return;
    }
    func_001D4B40(a, b);
    if (b[5] == 1 && b[0x169] == 0xF && b[0x168] == 2) return;
    a[4] = 2;
    a[0x13C] = 0;
    c = *(u8 **)(b + 0x1DC);
    *(s16 *)(c + 0x140) ^= 1;
    c[0x1E6] ^= 1;
}

void func_003519E0(u8 *p) {
    extern s32 func_00417A40();
    u8 *o;
    u8 i;
    f32 d;
    o = *(u8 **)(*(u8 **)(p + 0x18) + 0x1DC);
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    i = func_00417A40() & 0xF;
    if (p[0x20] & 1) d = D_00462550[i * 2]; else d = -D_00462550[i * 2];
    *(f32 *)(p + 0x34) += d;
    if (p[0x20] & 2) d = D_00462554[i * 2]; else d = -D_00462554[i * 2];
    *(f32 *)(p + 0x38) += d;
}

void func_00228F50(u8 *p) {
    extern void func_00175700();
    extern s32 func_001864a0();
    extern void func_001757E0(u8 *, s32, u8);
    f32 *a, *b;
    u32 t;
    u8 k;
    f32 f;
    func_00175700(p);
    a = (f32 *)(p + 0x60);
    b = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        t = p[6];
        p[6] = t + 1;
        *a = 0;
        *b = 0;
        f = D_00451998[p[0x1B7]];
        if (*(s16 *)(p + 0x140) != 0) f = -f;
        *(f32 *)(p + 0x68) = f;
        k = 0x22;
        if (p[0x1B7] != 0) k = 0x31;
        func_001757E0(p, 0x15, k);
    }
}

void func_0027EB10(u8 *p) {
    extern void func_00175700();
    extern u32 func_00174170();
    extern void func_00381E40(u8 *, s32, u8);
    s16 h;
    s32 b;
    u8 a;
    func_00175700(p);
    h = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = h;
    if (h <= 0) {
        *(s16 *)(p + 0x1E) = func_00174170() & 4;
        b = (*(s8 *)(p + 0x22) + 1) & 1;
        *(s8 *)(p + 0x22) = b;
        if (b != 0) {
            s32 n;
            *(s16 *)(p + 0x1E) += 8;
            *(s16 *)(p + 0x1C) -= 1;
            a = p[0x21];
            n = a + 1;
            p[0x21] = n % 3;
        } else {
            a = func_00174170() % 3 + 0x80;
        }
        func_00381E40(p, 6, a);
        if (*(s16 *)(p + 0x1C) <= 0) {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

void func_002EE360(G2E *p) {
    extern s32 func_00174170();
    extern void func_002EE450();
    s32 v, n;
    if (p->s2B8 < 2) {
        if (p->s2B8 == 0) {
            p->s2B8 = p->s2B8 + 1;
            p->s300 = 0;
            p->s2F8 = 1;
            p->s2FC = 0;
        }
        v = p->s2F8 - 1;
        p->s2F8 = v;
        if (v < 0) {
            p->s2F8 = 1;
            if (p->s2FC > 1) {
                p->s2FC = 0;
                if ((func_00174170() & 0xF) == 0) {
                    p->s2B8 += 1;
                    p->s2F8 = 4;
                    p->s2FC = 0;
                }
            }
            func_002EE450(p, 0);
        }
    } else {
        v = p->s2F8 - 1;
        p->s2F8 = v;
        if (v < 0) {
            p->s2F8 = 1;
            n = 2;
            if (p->s2FC > 4) {
                p->s2B8 = 1;
                n = 0;
                p->s2F8 = 1;
                p->s2FC = 0;
            }
            func_002EE450(p, n);
        }
    }
}
