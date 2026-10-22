typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_00175670(void *p);
extern s8 func_00175700(void *p);
extern void func_001E3710(void *p, s32 n);
extern void func_003DF850(s32 a, s32 b);

void func_001BB4A0(u8 *p) {
    s16 v;
    func_00175670(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4] = 5;
        p[0x13C] = 0;
    } else {
        p[0x13C] = ((*(s16 *)(p + 0x1C) % 2) != 0) ? 1 : 0;
    }
}


typedef struct { u8 p0[0x5C]; f32 f5c; u32 w60; u8 p1[4]; u32 w68; u32 w6c; } Q;

void func_002AAC20(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        p[0x151] = 0;
        ((Q *)p)->f5c = (p[0x1E6] != 0) ? 5.0f : -5.0f;
        ((Q *)p)->w68 = 0;
        ((Q *)p)->w60 = 0x41092492;
        ((Q *)p)->w6c = 0xBF809249;
        func_001E3710(p, 0x15);
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
extern s32 func_001841C0(void *p);
extern void func_00199170(void *p);
extern void func_001266A0(void *p, s32 a, s32 b);
extern void func_0015D010(void *p, void *v);
extern void func_0018C6E0(void *p);
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990();
extern void func_00186A60(void *p, s32 a);
extern u8 D_00457CA0[];
extern s8 *D_004C2840;

void func_00205850(u8 *p) {
    if (p[6] == 0) {
        p[6]++;
        if ((D_004C2840[0x84] & 1) && func_001841C0(p) == 1) {
            func_001757E0(p, 0x13, 0);
            func_00199170(p);
        } else {
            func_001757E0(p, 0x13, 1);
        }
    } else {
        func_00175700(p);
    }
}

void func_00232A90(u8 *p) {
    u32 v[3];
    if (*(u16 *)(p + 0x20E) & 0x800) {
        *(s8 *)(p + 0x1E6) ^= 1;
        *(s16 *)(p + 0x140) ^= 1;
    }
    func_001266A0(p, 5, 5);
    p[0x1B4] = 10;
    p[6] = 0;
    v[0] = 0xC2A00000;
    v[1] = 0x43092492;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 2);
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x20]; f32 f5c, f60; u8 p2[4]; f32 f68, f6c; u8 p3[0x3C0]; f32 f430; } R;

void func_00202C00(R *p) {
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        ((u8 *)p)[6]++;
        func_001757E0(p, 1, 5);
    }
}

extern void func_001830D0();
extern void func_00194990(void *a, void *b);
extern s32 func_00194100(void *a);
extern void func_00178F20(void *a, void *b);
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003B2FC0();

void func_00219E00(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 2) {
        s32 n = p[7] + 1;
        p[7] = n;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x40555555;
        v[1] = 0x42CDB6DB;
        func_001830D0(p, v, 1, n);
    }
}

void func_002ECB30(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        s32 n = p[6] + 1;
        p[6] = n;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0x30;
        v[1] = 0x431E9249;
        v[0] = 0;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1, n);
    }
}

void func_00194300(u8 *a, u8 *b) {
    u8 *s1 = *(u8 **)(b + 0x1DC);
    if (*(s8 *)(s1 + 0x211) != 0) {
        a[0x21] |= 0x80;
        a[5] = 2;
        func_00194990(a, b);
    } else {
        u32 t = a[5];
        a[5] = t + 1;
        if (func_00194100(a) != 0) {
            func_00178F20(a, s1);
        } else {
            a[0x21] |= 0x80;
            a[5] = 2;
            func_00194990(a, b);
        }
    }
}

typedef struct O { u8 p0[0x430]; f32 f430; } O;
typedef struct T { u8 p0[5]; u8 b5; u8 p1[0x12]; O *o; s16 h1c; u8 p2[0x16]; f32 f34, f38; u8 p4[0x20]; f32 f5c, f60; u8 p5[4]; f32 f68, f6c; u8 p6[0xA8]; u32 w118; } T;

void func_003656B0(T *p) {
    if (p->h1c != 0) {
        s16 v = p->h1c - 1;
        p->h1c = v;
        if (v != 0) {
            return;
        }
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->o->f430) {
        p->b5++;
        p->f38 = p->o->f430;
        p->w118 = 0x3F800000;
    }
}

void func_003B2F10(u8 *a, s32 b, s32 c, s32 d, s32 e) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_003B2FC0;
        *(s16 *)(o + 0x26) = 0x3304;
        *(u32 *)(o + 0x18) = *(u32 *)(a + 0x18);
        o[1] = a[1];
        *(u8 **)(o + 0x14) = a;
        o[0x20] = b;
        o[0x21] = c;
        *(f32 *)(o + 0x5C) = (f32)d;
        *(s16 *)(o + 0x1E) = (u8)e;
    }
}

extern void func_0018F4C0(void *p);
extern void func_00184540(void *p);
extern void func_001843A0(void *p);
extern int func_00174470(const void *);
extern void func_00347190(void *p);
extern void func_001E7F60(void *p);
extern u8 D_004C1380[4];

void func_00177080(u8 *p) {
    u8 *o = *(u8 **)(p + 0x1CC);
    if (o == 0) {
        o = *(u8 **)(p + 0x220);
    }
    if (o[5] == 3) {
        func_0018F4C0(p);
    } else {
        s8 v = *(s8 *)(p + 0x24D) - 1;
        *(s8 *)(p + 0x24D) = v;
        if (v <= 0) {
            if (*(s16 *)(p + 0x434) == 0) {
                func_0018F4C0(p);
            } else if (p[0x20D] == 2) {
                func_00184540(p);
            } else {
                func_001843A0(p);
            }
        }
    }
}

void func_003470A0(u8 *p) {
    if (func_00174470(p) == 0) {
        func_00347190(p);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x169] = 0x17;
        p[0x168] = 2;
        func_001757E0(p, p[0x169], p[0x168]);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        func_001E7F60(p);
        func_00175700(p);
    }
}

void func_00225310(R *p) {
    f32 *q = &p->f60;
    f32 *r = &p->f6c;
    s8 v;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *(u32 *)q = 0;
        *(u32 *)r = 0;
    }
    v = func_00175700(p);
    if (v < 0) {
        func_00184540(p);
    }
}

void func_0023D800(u8 *p, u8 *context) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001266A0(p, 7, 7);
        v[0] = 0;
        v[1] = 0x43340000;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_00245380(R *p) {
    f32 *q;
    f32 *r;
    func_00175700(p);
    q = &p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    r = &p->f6c;
    if (!(p->f430 < p->f38)) {
        u32 t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        p->f38 = p->f430;
        *(u32 *)q = 0;
        *(u32 *)r = 0;
        func_001757E0(p, 2, 2);
    }
}

extern void func_00174A40(void *p, s32 n);
extern s32 func_00174240(void *p);
extern void func_0014EEC0(void *p, s32 n);
extern void func_0014EE80();
extern u32 D_004C27FC;
extern u32 D_004C2838;
extern s32 func_00417A40(void);
extern void func_00157470();
extern s8 D_004F7F50[];
extern s8 D_004F7F51[];
extern s8 D_004F7FC6[];
extern u32 D_00464450[];
typedef struct { s32 a, b; } E8;
extern E8 D_004F4420[];
typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7858;

void func_0016EDA0(s32 idx, s32 val) {
    if (D_004F7F50[0] == 0 && D_004C2840[0x4C] == 2 && (D_004F7F51[0] & (1 << idx)) == 0) {
        return;
    }
    if (D_004F4420[idx].a != 0 && D_004F4420[idx].b < val) {
        return;
    }
    if ((D_004F7FC6[0] & (1 << idx)) != 0) {
        D_004F4420[idx].a = -1;
        D_004F4420[idx].b = val;
    }
}

void func_003812D0(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    if (o[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        s16 h;
        func_00174A40(p, 0x708);
        h = *(s16 *)(p + 0x1C);
        if (h != 0) {
            *(s16 *)(p + 0x1C) = h - 1;
        } else if (func_00174240(p) == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            return;
        }
        *(u32 *)(p + 0x48) = D_00464450[p[0x22]];
        func_001E7F60(p);
    }
}

void func_0014EDD0(u8 *a, s32 b) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014EE80;
        *(s16 *)(o + 0xCC) = 0x2F;
        *(u32 *)(o + 0x84) = D_004C27FC;
        *(u32 *)(o + 0xD0) = 0x21;
        *(u32 *)(o + 0x34) = 0x40FA3D71;
        *(u32 *)(o + 0x38) = 0x3EAE147B;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(s16 *)(o + 0x1E) = b;
        *(u8 **)(o + 0x18) = a;
        func_0014EEC0(o, b);
    }
}

void func_002D4FB0(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        *(s8 *)(p + 0x151) ^= 1;
        v[0] = 0xC23AAAAA;
        v[1] = 0x434DB6DB;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_00317D30(R *p) {
    s8 r;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    r = func_00175700(p);
    if (r <= 0) {
        s32 n = 2;
        u32 t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        *(u32 *)&p->f68 = 0x3F200000;
        if (*(s16 *)((u8 *)p + 0x140) != 0) {
            p->f68 = -p->f68;
        }
        func_001757E0(p, n, n);
    }
}

void func_0032F7E0(u8 *p) {
    s16 h = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = h;
    if (h >= 0x3C) {
        u32 t = p[4];
        s32 r;
        p[4] = t + 1;
        p[0x13C] = 1;
        *(V3 *)(p + 0x34) = D_004B7858;
        r = func_00417A40();
        *(f32 *)(p + 0x34) += (f32)(r % 50000 - 10000);
        *(u32 *)(p + 0x80) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x78) = 0x3F800000;
    }
}

void func_00157540(V3 *a) {
    u8 *o = func_003DA750(0, 9, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00157470;
        *(s16 *)(o + 0xCC) = 0x2A;
        *(u32 *)(o + 0x84) = D_004C2838;
        *(u32 *)(o + 0xD0) = 0x800411;
        *(V3 *)(o + 0x34) = *a;
        *(u32 *)(o + 0x5C) = 0x3ECCCCCD;
        *(u32 *)(o + 0x68) = 0xBD23D70A;
        *(u32 *)(o + 0x50) = 0x3F000000;
        *(u32 *)(o + 0x54) = 0x3F000000;
        *(u32 *)(o + 0x58) = 0x3F000000;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
    }
}

void func_0016D460(void) {
    volatile u32 a = 0x4B189680;
    volatile u32 b = 0x4B189680;
    u32 pa = (u32)&a;
    u32 pb = (u32)&b;
    func_003DF850(15, 0);
    func_003DF850(0x10, *(u32 *)pa);
    func_003DF850(0x11, *(u32 *)pb);
}
