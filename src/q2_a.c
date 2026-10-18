typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004C1AD0[2])(u8 *, s32);

void func_00358F30(u8 *p, s32 n)
{
    extern void func_0035AE70(u8 *, s32);
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = q + 0x2B8;
    q[0x2C8] = p[0x20];
    if (p[0x20] != q[0x2C6]) {
        p[0x20] = q[0x2C6];
        p[0x21] = r[0xF];
        func_0035AE70(p, n);
    }
    p[0x13C] = ((s8 *)*(u8 **)(p + 0x18))[0x13C];
    D_004C1AD0[p[0x20]](p, n);
}

typedef struct { u8 pad0[0x194]; s32 f194; u8 pad1[0x570 - 0x198]; u8 f570; u8 pad2[0x5B8 - 0x571]; } E16F;
extern E16F D_004F20B0[];
extern s32 *D_004C9FC0[];
extern u8 *D_004C2840;
extern s32 D_004C28BC;
extern s32 D_004CB1F0[];

void func_0016F720(void)
{
    extern void func_0011D740(s32, s32, s32);
    s32 i = 0;
    s32 off = 0;
    do {
        E16F *e = (E16F *)((u8 *)D_004F20B0 + off);
        s32 j;
        s32 o;
        e->f194 = (s32)D_004C9FC0[e->f570];
        j = i;
        if (*(s32 *)(D_004C2840 + 0x98) == D_004C28BC + 0x3F0000) j = i + 6;
        o = D_004CB1F0[j];
        if (o != 0) func_0011D740(e->f194, o, 0xF000);
        i++;
        off += 0x5B8;
    } while (i < 6);
}

void func_00362B00(u8 *p, u8 *q)
{
    extern s8 func_00175700();
    extern void func_00362C20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 f = 0;
    if (func_00175700() < 0) {
        f32 d = *(f32 *)(p + 0x34) - *(f32 *)(q + 0x34);
        f32 z = 0.0f;
        if (d < z) f = 1;
        if (*(s16 *)(p + 0x140) == f) {
            p[6] = 6;
            func_00362C20(p, q);
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x140) = f;
            func_001757E0(p, 0x17, 0xE);
        }
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7890;
extern f32 D_004B7A50[];
extern f32 D_004B7A54[];
extern f32 D_004B7A58[];
extern s32 D_004C283C;

typedef struct {
    u8 p0[0x10]; u32 f10; u32 f14; u8 p1[0x34 - 0x18]; V3 f34; s32 f40; s32 f44; s32 f48; u8 p2[0x84 - 0x4C]; s32 f84;
    u8 p3[0xC8 - 0x88]; u8 *fC8; s16 fCC; u8 p4[2]; s32 fD0; u8 p5[0xDC - 0xD4]; s32 fDC; u8 p6[0x13C - 0xE0]; u8 f13C;
} O331;


typedef struct {
    u8 p0[6]; u8 f6; u8 p1[0x34 - 7]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x20B - 0x70]; u8 f20b; u8 p5[0x430 - 0x20C]; f32 f430;
} P2B2;

void func_002B2050(P2B2 *p)
{
    extern void func_00175700();
    extern void func_00185490();
    extern void func_001757E0(P2B2 *, s32, s32);
    f32 z = 0.0f;
    func_00175700();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f60 < z) {
        if (p->f430 > p->f38) {
            u32 t = p->f6;
            p->f6 = t + 1;
            p->f38 = p->f430;
            if (p->f20b == 0) {
                func_00185490(p);
                func_001757E0(p, 0xF, 2);
            } else {
                func_001757E0(p, 0xF, 4);
            }
        }
    }
}


typedef struct {
    u8 p0[6]; u8 f6; u8 f7; u8 p1[0x34 - 8]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x151 - 0x70]; s8 f151; u8 p5[0x2B8 - 0x152]; s16 f2b8[8]; u8 p6[0x430 - 0x2C8]; f32 f430;
} P22E7;

void func_0022E700(P22E7 *p)
{
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0(P22E7 *, s32, s32);
    s16 *q = p->f2b8;
    if (p->f151 < 0) {
        func_00175700();
        return;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 > p->f430) {
        func_00175700();
        return;
    }
    p->f34 = q[4];
    p->f38 = p->f430;
    func_00183d50();
    {
        u32 t = p->f7;
        p->f7 = t + 1;
    }
    func_001757E0(p, 0x12, 4);
}

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G3B33;
extern G3B33 *D_004C2794;

void func_003B3370(u8 *p, u8 *a)
{
    extern void func_00175700();
    extern void func_001E7F60(u8 *);
    extern void func_003B2F10(u8 *, s32, u8, s32, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = a + 0x2B8;
    func_00175700();
    func_001E7F60(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[0x1B5] = 0x34;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    {
        u32 e = p[0x1E];
        func_003B2F10(p, 1, p[0x21], -0xAA, e);
    }
    {
        u32 t = p[0x21];
        p[0x21] = t + 1;
    }
    {
        u32 t = p[0x21];
        p[0x21] = t & 7;
    }
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) & 3;
    if (q[6] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 0xE);
    }
}



typedef struct { f32 x, y, z; } V3b;
extern V3b D_004425C0[];
extern V3b D_00442710[];
extern s32 D_004C2804;

void func_001464D0(u8 *p)
{
    u32 t = p[4];
    s16 v;
    if (t == 0) {
        p[4] = t + 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 6;
        *(s16 *)(p + 0x1E) = 0;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        *(s16 *)(p + 0x1C) = 6;
        *(s16 *)(p + 0x1E) = (*(s16 *)(p + 0x1E) + 1) % 6;
    }
    *(s16 *)(p + 0xCC) = *(s16 *)(p + 0x1E) + 0x11;
    *(s32 *)(p + 0x84) = D_004C2804;
    *(V3b *)(p + 0x34) = D_004425C0[*(s8 *)(D_004C2840 + 0x4C)];
    *(u32 *)(p + 0x3C) = 0xC15028F6;
    *(V3b *)(p + 0x50) = D_00442710[*(s8 *)(D_004C2840 + 0x4C)];
}

typedef struct {
    u8 p0[6]; u8 f6; u8 p00[0x1C - 7]; s16 f1c; u8 p01[0x34 - 0x1E]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x151 - 0x70]; s8 f151; u8 p5[0x1B7 - 0x152]; u8 f1b7; u8 p6[0x430 - 0x1B8]; f32 f430;
} P2252;

void func_00225210(P2252 *p)
{
    extern void func_00175700();
    extern void func_001757E0(P2252 *, s32, s32);
    extern void func_00357690(P2252 *, s32);
    u32 *q, *r;
    s16 v = p->f1c - 1;
    p->f1c = v;
    if (v <= 0) {
        u32 t = p->f6;
        p->f6 = t + 1;
        func_001757E0(p, 0x15, (u8)((p->f1b7 ^ 1) + 0xC));
        return;
    }
    func_00175700();
    q = (u32 *)&p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    r = (u32 *)&p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *q = 0;
        *r = 0;
    }
    if (p->f151 != 0) {
        p->f151 = 0;
        func_00357690(p, (u8)((p->f1b7 ^ 1) + 2));
    }
}

typedef struct {
    u8 p0[4]; u8 f4; u8 p00[0x24 - 5]; s8 f24; u8 p01[0x34 - 0x25]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x1B2 - 0x70]; s8 f1b2; s8 f1b3;
} P3999;
extern u8 *D_004C29FC;
extern u8 *D_004C29F8;

void func_00399A50(P3999 *p)
{
    extern s32 func_00174240(P3999 *);
    extern void func_00399BA0(P3999 *);
    extern void func_001757E0(P3999 *, s32, s32);
    extern void func_00399B50(P3999 *);
    extern void func_00175700();
    extern void func_001E7F60(P3999 *);
    u8 *g;
    p->f24 = 0;
    g = D_004C29FC;
    if (*g != 0) {
        u32 v = *g;
        v = v - 1;
        *g = v;
        if ((u8)v != 0) goto L;
    }
    if (func_00174240(p) == 0) {
        func_00399BA0(p);
        return;
    }
L:
    if (p->f1b2 != 0 || p->f1b3 != 0) {
        u32 t = p->f4;
        p->f4 = t + 1;
        *D_004C29F8 = 0;
        func_001757E0(p, 0x17, 1);
        func_00399B50(p);
        return;
    }
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001E7F60(p);
}

typedef struct { f32 x, y; } F2;
extern F2 D_004B5A90[];
extern F2 D_004B5A94[];
extern F2 D_004B5AE0[];
extern F2 D_004B5AE4[];
typedef struct {
    u8 p0[4]; u8 f4; u8 f5; u8 p1[0x34 - 6]; f32 f34; f32 f38; u8 p2[0x140 - 0x3C]; s16 f140; u8 p3[0x151 - 0x142]; s8 f151;
    u8 p4[0x161 - 0x152]; s8 f161;
} P1C9C;
typedef struct { u8 p0[4]; u8 f4; u8 f5; u8 p1[0x34 - 6]; f32 f34; f32 f38; u8 p2[0x140 - 0x3C]; s16 f140; u8 p3[0x161 - 0x142]; s8 f161; } Q1C9C;
typedef struct { u8 p0[4]; u8 f4; u8 p1[0x14 - 5]; Q1C9C *f14; u8 p2[0x34 - 0x18]; f32 f34; f32 f38; u8 p3[0x140 - 0x3C]; s16 f140; u8 p4[0x151 - 0x142]; s8 f151; } R1C9C;

void func_001C9CD0(R1C9C *p)
{
    extern void func_00175670();
    Q1C9C *q = p->f14;
    s16 v;
    if (q->f4 < 2) {
        if (q->f5 == 0) {
            if (p->f151 != 0) {
                p->f34 = D_004B5A90[q->f161].x;
                p->f38 = D_004B5A94[q->f161].x;
            } else {
                p->f34 = D_004B5AE0[q->f161].x;
                p->f38 = D_004B5AE4[q->f161].x;
            }
            v = q->f140;
            p->f140 = v;
            if (v != 0) p->f34 = -p->f34;
            p->f34 += q->f34;
            p->f38 += q->f38;
            func_00175670();
            return;
        }
    }
    p->f4 = 2;
}

typedef struct {
    u8 p00[0x34]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x151 - 0x70]; s8 f151; u8 p5[0x160 - 0x152]; s8 f160; u8 p6[0x1DC - 0x161]; u8 *f1dc; u8 p7[0x430 - 0x1E0]; f32 f430;
} P2858;

void func_00285ED0(P2858 *p)
{
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_001843A0();
    u32 *d, *c, *b, *a;
    a = (u32 *)&p->f6c;
    b = (u32 *)&p->f68;
    c = (u32 *)&p->f60;
    d = (u32 *)&p->f5c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (p->f151 != 0) {
        u8 *q;
        p->f151 = 0;
        q = p->f1dc;
        *(P2858 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x21;
    }
    if (p->f38 <= p->f430) {
        *d = 0;
        *c = 0;
        *b = 0;
        *a = 0;
        if (p->f160 == 0) func_001843A0(p);
    }
}

typedef struct {
    u8 p0[2]; u8 f2; u8 p01[2]; u8 f5; u8 f6; u8 p02[0x34 - 7]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x1B2 - 0x70]; u8 f1b2; u8 p5[2]; u8 f1b5; u8 p6[0x1C0 - 0x1B6]; u16 f1c0; u8 p7[0x1D8 - 0x1C2]; s32 f1d8; u8 p8[0x20D - 0x1DC]; u8 f20d; u8 p9[0x213 - 0x20E]; u8 f213;
} P2E1C;

void func_002E1CF0(P2E1C *p)
{
    extern void func_001861B0();
    extern void func_0018C4B0(P2E1C *, s32);
    extern void func_001757E0(P2E1C *, s32, s32);
    extern void func_001E3710(P2E1C *, s32);
    extern void func_00183D90(P2E1C *);
    extern void func_001863F0(P2E1C *);
    extern s8 func_00175700();
    extern void func_001843A0(P2E1C *);
    if (p->f6 == 0) {
        u32 t;
        func_001861B0();
        t = p->f6;
        p->f6 = t + 1;
        p->f1b5 = 0x41;
        p->f1b2 = p->f1c0 = 0;
        p->f1d8 = 0;
        D_004C2794->f7c[p->f2]++;
        p->f20d = 0;
        func_0018C4B0(p, 5);
        func_001757E0(p, 0x14, 7);
        func_001E3710(p, 0x16);
    }
    if (p->f213 == 3) func_00183D90(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001863F0(p);
    if (func_00175700(p) < 0) func_001843A0(p);
}




typedef struct {
    u8 p0[7]; u8 f7; u8 p00[0x1C - 8]; s16 f1c; u8 p01[0x34 - 0x1E]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x160 - 0x70]; s8 b[10]; s8 f16a; u8 p5[0x2BC - 0x16B]; f32 f2bc;
} P29ED;

