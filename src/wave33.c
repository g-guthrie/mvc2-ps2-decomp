typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct A136D00 { u8 pad[0x1C]; s16 h; u8 pad2[0xC2]; s32 z; f32 f; } A136D00;

extern s8 D_004F1F47;
void func_00123250(void);
void func_001233B0(void);
void func_00123410(void);
void func_00123470(void) {
    switch (D_004F1F47) {
    case 0:
        func_00123250();
    case 1:
        func_001233B0();
        break;
    case 2:
        func_00123410();
        break;
    }
}

extern void (*D_0044B558[])(u8 *, u8 *);
void func_001A8980(u8 *a, u8 *b) {
    u32 c = b[0x1E4];
    u32 d;
    if (c != 21 || (d = b[0x1FD]) != 8) {
        a[4]++;
        a[0x13C] = 0;
    } else {
        D_0044B558[a[5]](a, b);
    }
}

s32 func_00185E40(u8 *);
s32 func_00185DD0(u8 *p) {
    if ((p[0x216] & 0x80) || *(s8 *)(p + 0x204) != 0 || p[0x425] != 0) return 0;
    if (p[0x1E4] == 19) return 1;
    return func_00185E40(p);
}

void func_00248E70(u8 *);
void func_00248DF0(u8 *p) {
    u32 a = p[0x212];
    if (a == 0 && (*(s8 *)(p + 0x1EA) & 0xF) != 0) {
        func_00248E70(p);
    } else if (a != 0 && (*(s8 *)(p + 0x1EA) & 0xF0) != 0) {
        func_00248E70(p);
    }
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
}

void func_003298B0(s32, s32, s32);
void func_001841E0(void);
typedef struct A328380 { u8 pad0[4]; u8 b; u8 pad1[0x17]; s16 h; } A328380;
void func_00328380(A328380 *p) {
    s16 v = p->h - 1;
    p->h = v;
    if (v < 0) {
        p->b++;
        p->h = 48;
        func_003298B0(-1, 32, 0);
    } else if (p->h == 40) {
        func_001841E0();
    }
}

typedef struct Q359670 { u8 p0[10]; s16 h; u8 c; } Q359670;
typedef struct P359670 { u8 p0[5]; u8 b; u8 p1[0x12]; u8 *q18; u8 p2[0x1C]; f32 f38; u8 p3[0x12C]; u8 c168; u8 c169; } P359670;
void func_001757E0(void *, u32, u32);
void func_003595B0(P359670 *, Q359670 *);
void func_00359670(P359670 *p, Q359670 *q) {
    u32 t = p->p0[5];
    u8 *r = p->q18;
    p->p0[5] = t + 1;
    q->h = 0;
    q->c = 0;
    p->f38 = *(f32 *)(r + 0x430);
    p->c169 = 23;
    p->c168 = 26;
    func_001757E0(p, p->c169, p->c168);
    func_003595B0(p, q);
}

typedef struct E64 { u8 b[64]; } E64;
extern E64 D_0061BEE0[];
extern u8 D_0061BE20[], D_0061C6E0[], D_0061C760[], D_0061BE60[], D_0061BEA0[];
void func_003DD360(f32 *, f32, f32, f32, f32);
void func_003DD440(void *);
void func_003DE160(void *, void *, void *);
void func_003DD2E0(s32 i, f32 far_plane, f32 near_plane, f32 fov, f32 aspect) {
    E64 *p = &D_0061BEE0[i];
    func_003DD360((f32 *)p, far_plane, near_plane, fov, aspect);
    func_003DD440(p);
    func_003DE160(D_0061BE20, D_0061C6E0, D_0061C760);
    func_003DE160(D_0061BE60, D_0061C6E0, D_0061BEA0);
}

typedef struct S180 { u8 b[180]; } S180;
typedef struct S76 { u8 b[76]; } S76;
typedef struct R170B70 { u8 p0[4]; S76 *a4; u8 p1[12]; S180 *a14; u8 p2[4]; s32 **a1c; } R170B70;
typedef struct T16 { s32 w; s32 pad[3]; } T16;
extern T16 D_004D1820[];
void func_003DF850(s32, void *);
void func_00170B70(R170B70 *p, s32 i, s32 j) {
    s32 v = D_004D1820[j].w;
    S76 *d = p->a4;
    s32 *e = p->a1c[i];
    S180 *s = p->a14 + e[0x60];
    d += *(s32 *)(s->b + 0x10);
    *(s32 *)(d->b + 0x44) = v;
    func_003DF850(57, d);
}

typedef struct N19F3F0 { u8 p0; u8 b1; u8 p1[14]; void (*fn)(void); u8 p2[4]; u8 *o18; u8 p3[4]; u8 b20; u8 b21; u8 p4[4]; s16 h26; u8 p5[0x114]; u8 b13C; } N19F3F0;
N19F3F0 *func_003DA750(s32, s32, s32);
void func_0019F4F0(void);
void func_0019F3F0(u8 *p, u32 a, u32 b) {
    N19F3F0 *n = func_003DA750(0, 3, 1);
    if (n) {
        n->fn = func_0019F4F0;
        n->o18 = p;
        n->b1 = p[1];
        n->b20 = a;
        n->b21 = b;
        n->h26 = 0xB01;
        n->b13C = 0;
    }
}

typedef struct N3C12D0 { u8 p0; u8 b1; u8 p1[14]; void (*fn)(void); u8 *o14; u8 *o18; u8 p3[4]; u8 b20; u8 b21; u8 p4[4]; s16 h26; } N3C12D0;
void func_003C1350(void);
void func_003C12D0(u8 *p, u32 a, u32 b) {
    N3C12D0 *n = (N3C12D0 *)func_003DA750(0, 1, 1);
    if (n) {
        n->fn = func_003C1350;
        n->h26 = 0x3701;
        n->o18 = *(u8 **)(p + 24);
        n->o14 = p;
        n->b1 = p[1];
        n->b20 = a;
        n->b21 = b;
    }
}

typedef struct M3BCF30 { u8 p0[0x22]; u8 b22; u8 p1[0x11]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[0x6C]; struct M3BCF30 *o; u8 p4[0x6C]; s16 h140; } M3BCF30;
void func_003BCF30(M3BCF30 *p) {
    M3BCF30 *q = p->o;
    f32 v;
    p->f34 = q->f34;
    p->f38 = q->f38;
    v = p->f5c;
    if (v > 0.0f) p->h140 = 0;
    else p->h140 = 1;
    if (p->b22 != q->h140) {
        p->h140 ^= 1;
        v = -v;
    }
    p->f34 += v;
    p->f38 += p->f60;
}

void func_003A7C20(void);
void func_003A7BA0(u8 *p, u32 a, u32 b) {
    N3C12D0 *n = (N3C12D0 *)func_003DA750(0, 1, 1);
    if (n) {
        n->fn = func_003A7C20;
        n->h26 = 0x2E06;
        n->o18 = *(u8 **)(p + 24);
        n->b1 = p[1];
        n->o14 = p;
        n->b20 = a;
        n->b21 = b;
    }
}

extern u8 D_0045A8E0[];
s32 func_00189310(u8 *, u8 *, u8 *);
void func_0018A990(u8 *, u8 *);
void func_00186A60(u8 *, s32);
s32 func_002D94E0(u8 *p) {
    if (func_00189310(p, D_0045A8E0, p + 0x390) == 0) return 0;
    func_0018A990(p, p + 0x390);
    if (p[0x215] != 0) {
        *(s32 *)(p + 0x2C8) = 1;
        return 0;
    }
    p[0x1FD] = 3;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 21);
    return 1;
}

extern s8 D_00446D40[];
typedef struct G18E970 { u8 p0[0x1CC]; struct G18E970 *w1cc; u8 *w1d0; u8 p1[0x47]; u8 b21b; u8 p2[4]; struct G18E970 *w220; u8 p3[0x1F]; s8 b243; } G18E970;
u8 func_0018E970(G18E970 *p) {
    s8 n = p->b243;
    if ((p->w1d0[0x12] & 4) == 0) {
        G18E970 *t = p->w1cc;
        if (t == 0) t = p->w220;
        n = n + D_00446D40[(p->b21b - t->b21b + 7) & 0xF];
        if (n < 0) n = 0;
        if (n > 15) n = 15;
    }
    return n;
}

extern s32 D_0062BFD4, D_0062BFD8, D_0062BFDC, D_0062BFE0, D_0062BFE4;
extern s32 D_0062BFE8[];
s32 func_003DD030(s32);
void func_003DD0D0(void) {
    switch (D_0062BFD4) {
    case 0:
    case 2:
    case 1:
        D_0062BFDC = func_003DD030(D_0062BFE8[D_0062BFD8]);
        D_0062BFE4 = D_0062BFDC;
        D_0062BFE0 = D_0062BFDC + 0x80000;
        break;
    }
}

typedef struct F22BDF0 { u8 p0[6]; u8 b6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; } F22BDF0;
s32 func_00175700(void *);
void func_0022BDF0(F22BDF0 *p) {
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f60 < 0.0f) {
        p->b6++;
        func_001757E0(p, 15, 8);
    }
}

typedef struct W2 { f32 a, b; } W2;
void func_001843A0(void *);
void func_00175C00(void *, s32);
void func_00183920(void *, f32 *);
void func_00355BE0(void *, s32);
void func_00225500(u8 *p) {
    f32 w[3];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        *(s8 *)(p + 0x150) = 0;
        func_00175C00(p, 0);
        w[0] = 73.33332824707031f;
        w[1] = 102.85713958740234f;
        func_00183920(p, w);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_00355BE0(p, 5);
    }
}

void func_001B9400(void *);
void func_00272810(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_001757E0(p, 20, 4);
    } else if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_001B9400(p);
    }
}

typedef struct H13C660 { u8 p0[4]; u8 b4; u8 p1[0x13]; u8 *o18; u8 p2[0x58]; f32 f74; u8 p3[0x58]; u32 wd0; } H13C660;
s32 func_0013C730(void *, void *);
void func_0013C660(H13C660 *p) {
    f32 f;
    u8 *q = p->o18;
    if (q[4] >= 6) {
        p->b4 = 2;
    } else if (func_0013C730(p, q) == 0) {
        p->b4 = 0;
    } else {
        p->f74 += 0.05f;
        f = p->f74;
        if (f >= 1.0f) {
            p->wd0 &= 0xFF7FFFFF;
            p->f74 = 1.0f;
        }
    }
}

void func_001830D0(void *, f32 *, s32);
void func_0020DE60(u8 *p) {
    f32 w[3];
    u32 v = 2;
    p[0x40C] = v;
    p[0x33C] = 5;
    if (p[0x269] == 6) {
        v = 2;
    } else {
        v = 0;
    }
    p[0x405] = v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        w[0] = -30.0f;
        w[1] = 175.71427917480469f;
        func_001830D0(p, w, 1);
    }
}

typedef struct B1C30A0 { u8 b0; u8 p0[3]; u8 b4; u8 p1[2]; u8 b7; u8 p2[0x1C]; s8 b24; u8 p3[0xF]; f32 f34; u8 p4[0x108]; s16 h140; } B1C30A0;
void func_001C30A0(B1C30A0 *p, u8 *q) {
    p->b24 = ((B1C30A0 *)q)->b24;
    if (q[0x1E4] != 22) {
        func_001757E0(p, 25, 5);
        p->b7 = 4;
    } else {
        if (*(s8 *)(q + 0x151) != 0) {
            u32 t = p->b4;
            p->b4 = t + 1;
            *(u8 *)((u8 *)p + 0x13C) = 0;
            p->b0 = 0;
        }
        func_00175700(p);
        if (*(s8 *)((u8 *)p + 0x151) != 0) {
            p->h140 = ((B1C30A0 *)q)->h140;
            p->f34 = ((B1C30A0 *)q)->f34;
        }
    }
}
