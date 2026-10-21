typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w1913_a.c "-O3 -sdatathreshold 0" */
typedef struct T41C { u8 pad[0x1C]; s32 w1C; u8 pad20[0x170 - 0x20]; } T41C;
typedef struct A41B { s32 w0; u32 w4; s32 w8; s32 wC; u16 h10; u16 h12; } A41B;
extern T41C D_005BF2F0[];
u8 *func_0041BBB0(A41B *a) {
    extern s32 func_003DD030(s32);
    u8 *base;
    u16 *p2;
    u16 *q;
    s32 idx;
    u16 v;
    s32 n;
    n = a->w0 - 1;
    base = (u8 *)(u32)func_003DD030(((T41C *)((u8 *)D_005BF2F0 + n * 0x170))->w1C);
    idx = a->h12;
    p2 = (u16 *)(u32)func_003DD030(a->w8);
    v = p2[idx * 2];
    if (v == 0xFFFF) {
        a->h12 = 0;
        a->h10 = 0;
        return 0;
    }
    q = (u16 *)(u32)func_003DD030(a->wC);
    a->h10 = idx;
    a->h12 = idx + 1;
    return base + q[v];
}

typedef struct S1 { f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30; s32 w34; u8 pad[0x100 - 0x38]; s32 w100; } S1;
typedef struct S2 { u8 pad0[4]; f32 f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30; s32 w34, w38, w3C, w40, w44, w48; } S2;
s32 func_003F1C10(u8 *a, s32 b, S2 *o) {
    extern S1 *func_003F1B10();
    extern void func_003F55B0(S2 *, s32, s32);
    extern s32 *func_003F1D10(u8 *, s32);
    extern s32 func_00118FA8(f32);
    S1 *s;
    s = func_003F1B10();
    func_003F55B0(o, 0, 0x4C);
    if (s->w34 != 0)
        o->w44 = *func_003F1D10(a, s->w100);
    else
        o->w44 = 0;
    o->f4 = s->f10;
    o->f8 = s->f14;
    o->fC = s->f18;
    o->f10 = s->f1C;
    o->f24 = s->f0;
    o->f28 = s->f4;
    o->f2C = s->f8;
    o->f30 = s->fC;
    o->f14 = s->f20;
    o->f18 = s->f24;
    o->f1C = s->f28;
    o->f20 = s->f2C;
    o->w34 = 0;
    o->w38 = 0;
    o->w3C = 0;
    o->w40 = 0;
    o->w48 = func_00118FA8(s->f30);
    return 1;
}

typedef struct P2B { u8 pad0[6]; u8 b6; u8 pad7[0x34 - 7]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; u8 pad70[0x1E6 - 0x70]; u8 b1E6; u8 pad1E7[0x20D - 0x1E7]; u8 b20D; u8 pad20E[0x430 - 0x20E]; f32 f430; } P2B;
typedef struct P20 { u8 pad0[0x34]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; } P20;
void func_0020CCE0(P20 *p, u8 *q) {
    extern int func_00175700(P20 *);
    extern void func_00328740();
    extern int func_001757E0(P20 *, int, int);
    extern void func_001266A0(P20 *, s32, s32);
    u8 *pb = (u8 *)p;
    u32 t;
    s8 c;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    pb[0x209] = 1;
    func_00175700(p);
    c = q[0xC] - 1;
    q[0xC] = c;
    if (c < 0) {
        if (*(s8 *)(pb + 0x211) & ((pb[0x1E6] ^ 1) + 1)) {
            t = pb[7];
            pb[7] = t + 1;
            pb[0x1E6] ^= 1;
            *(s16 *)(pb + 0x140) = pb[0x1E6];
            func_00328740(p);
            func_001266A0(p, 0, 0);
            if ((*(u8 **)(pb + 0x220))[1] == 0x1A)
                func_001266A0(p, 1, 1);
            q[0xA] = 1;
            func_001757E0(p, 0x14, 6);
        }
    }
}

typedef struct P1F { u8 pad0[0x34]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; } P1F;
void func_001F1410(P1F *p) {
    extern s32 func_00175700(P1F *);
    extern int func_001757E0(P1F *, int, int);
    extern void func_001266A0(P1F *, s32, s32);
    u8 *pb = (u8 *)p;
    s8 *q;
    u8 *o;
    u32 t;
    s8 d;
    pb[0x1FE] = 1;
    q = (s8 *)(pb + 0x2B8);
    pb[0x201] = 2;
    pb[0x209] = 2;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if ((s8)func_00175700(p) < 0) {
        t = pb[7];
        pb[7] = t + 1;
        func_001757E0(p, 0xF, 0x21);
        return;
    }
    if (*(s8 *)(pb + 0x151) != 0) {
        pb[0x151] = 0;
        func_001266A0(p, 0, 0);
        o = *(u8 **)(pb + 0x1DC);
        *(u8 **)(o + 0x1C8) = pb;
        o[0x20A] = 2;
        o[0x1B5] = *(s8 *)(pb + 0x1B7) + 0x25;
        pb[0x1B5] = *(s8 *)(pb + 0x1B7) + 0x25;
        d = q[2];
        pb[0x219] = d / 2 + 0x20;
    }
}

typedef struct V3 { f32 x, y, z; } V3;
typedef struct P27 { u8 pad0[0x1C]; s16 h1C; u8 pad1E[0x34 - 0x1E]; f32 f34, f38, f3C; u8 pad40[0x5C - 0x40]; f32 f5C, f60, f64, f68, f6C; } P27;
void func_00272190(P27 *p) {
    extern int func_00175700(P27 *);
    extern int func_001757E0(P27 *, int, int);
    extern void func_001830D0(P27 *, f32 *, int);
    u8 *pb = (u8 *)p;
    f32 *s0, *s1, *s2, *s3;
    V3 v;
    f32 *vp;
    s16 h;
    u32 t;
    pb[0x40C] = 2;
    pb[0x33C] = 5;
    pb[0x405] = (pb[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    s0 = &p->f5C;
    s2 = &p->f68;
    s1 = &p->f60;
    s3 = &p->f6C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    h = p->h1C - 1;
    p->h1C = h;
    if (h == 0) {
        pb[0x404] = 0;
        pb[0x405] = 0;
        t = pb[7];
        pb[7] = t + 1;
        func_001757E0(p, 0x16, 1);
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        vp = &v.x;
        *(V3 *)vp = *(V3 *)&p->f34;
        *(u32 *)&v.x = 0xC2555555;
        *(u32 *)&v.y = 0x434DB6DB;
        func_001830D0(p, vp, 1);
    }
}

typedef struct P29 { u8 pad0[0x1C]; s16 h1C; u8 pad1E[0x34 - 0x1E]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; } P29;
void func_00298B10(P29 *p) {
    extern int func_00175700(P29 *);
    extern int func_001266A0(P29 *, int, int);
    extern int func_001757E0(P29 *, int, int);
    extern void func_001843A0(P29 *);
    extern u8 *func_001E7FD0(P29 *);
    extern void func_0015D010(P29 *, f32 *);
    extern void func_00185770(P29 *, u8 *);
    u8 *pb = (u8 *)p;
    u8 *o;
    f32 v[4];
    s16 h;
    u32 t;
    pb[0x40C] = 2;
    pb[0x33C] = 5;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    h = 0;
    if ((*(s8 *)(pb + 0x211) & (1 << (pb[0x1E6] ^ 1))) != 0 || (h = p->h1C - 1, p->h1C = h, h <= 0)) {
        pb[0x40D] = 0;
        pb[0x40C] = 0;
        pb[0x33B] = 0;
        pb[0x33C] = 0;
        func_001843A0(p);
        return;
    }
    if ((o = func_001E7FD0(p)) != 0) {
        t = pb[6];
        pb[6] = t + 1;
        func_001266A0(p, 5, 5);
        func_001757E0(p, 0xF, 2);
        *(u32 *)&v[0] = 0xC2A6AAAA;
        *(u32 *)&v[1] = 0x431E9249;
        func_0015D010(p, v);
        p->h1C = 0x10;
        pb[0x20B] = 0xC2;
        func_00185770(p, o);
    }
}

