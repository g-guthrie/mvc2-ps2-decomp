typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G34E6;
extern G34E6 *D_004C2794;
extern f32 D_00462300[];
extern s16 D_00462320[];

void func_0034E630(u8 *p)
{
    extern void func_0034E760();
    extern s32 func_00417A40();
    extern void func_001757E0(u8 *, s32, s32);
    f32 sp;
    f32 fv;
    s32 r;
    p[0x13C] = 0;
    p[0x24] = 0;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x56;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_0034E760();
    if (*(s16 *)(p + 0x140) != 0) {
        sp = 15.0f;
    } else {
        sp = -15.0f;
    }
    *(f32 *)(p + 0x5C) = sp;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
    r = func_00417A40();
    fv = (f32)(r & 0x3000);
    *(f32 *)(p + 0x6C) -= 3.26974040945e-05f * fv;
    *(f32 *)(p + 0x38) += D_00462300[p[0x21]];
    *(s16 *)(p + 0x1C) = D_00462320[p[0x21]];
    func_001757E0(p, 0x17, 0x23);
}

typedef struct { s16 v; u8 pad[6]; } E16;
typedef struct { u8 v; u8 pad[7]; } E8u;
typedef struct { s8 v; u8 pad[7]; } E8s;
extern E16 D_00474BF0[][8];
extern E16 D_00474BF2[][8];
extern E8u D_00474BF4[][8];
extern E8s D_00474BF5[][8];
typedef struct { u8 p0; u8 f1; u8 p1[0x34 - 2]; f32 f34; f32 f38; u8 p2[0x140 - 0x3C]; s16 f140; } Q3BD;
typedef struct { u8 p0[0x21]; u8 f21; u8 p00[2]; s8 f24; u8 p1[0x34 - 0x25]; f32 f34; f32 f38; u8 p2[0xD0 - 0x3C]; Q3BD *fd0; u8 p3[0x140 - 0xD4]; s16 f140; } P3BD;

void func_003BD670(P3BD *p)
{
    Q3BD *q = p->fd0;
    f32 f;
    p->f34 = q->f34;
    p->f38 = q->f38;
    p->f140 = q->f140;
    f = 1.6666666269302368f * (f32)D_00474BF0[q->f1][p->f21].v;
    if (q->f140 == 0) f = -f;
    p->f34 += f;
    p->f38 += 2.142857074737549f * (f32)D_00474BF2[q->f1][p->f21].v;
    p->f140 = q->f140;
    if (D_00474BF4[q->f1][p->f21].v != 0) p->f140 ^= 1;
    p->f24 = D_00474BF5[q->f1][p->f21].v;
}

typedef struct {
    u8 p0[6]; u8 f6; u8 p00[0x34 - 7]; f32 f34; u8 p2[0x6C - 0x38]; u32 f6c;
    u8 p4[0x140 - 0x70]; s16 f140; u8 p5[0x150 - 0x142]; s8 f150; s8 f151; u8 p6[0x15B - 0x152]; u8 f15b;
    u8 p7[0x1DC - 0x15C]; u8 *f1dc; u8 p8[0x1E6 - 0x1E0]; u8 f1e6; u8 p9[0x20D - 0x1E7]; u8 f20d;
} P277B;

void func_00277BE0(P277B *p)
{
    extern void func_00175700();
    extern void func_001266A0(P277B *, s32, s32);
    extern void func_00184540(P277B *);
    extern void func_001843A0();
    f32 f;
    f32 z = 0.0f;
    func_00175700(p);
    f = (f32)(u32)p->f15b;
    if (f != z) {
        if (p->f140 != 0) f = -f;
        p->f34 += f;
        p->f15b = 0;
    }
    if (p->f6 == 0) {
        if (p->f151 != 0) {
            u8 a = p->f6;
            u8 *q;
            p->f6 = a + 1;
            p->f151 = 0;
            if (p->f20d == 2) p->f6c = 0xBF4DB6DB;
            q = p->f1dc;
            *(P277B **)(q + 0x1C8) = p;
            q[0x20A] = 1;
            q[0x1B5] = 0x20;
            q[0x1E6] = p->f1e6;
            func_001266A0(p, 0, 0);
        }
    } else if (p->f150 != 0) {
        if (p->f20d == 2) {
            func_00184540(p);
        } else {
            func_001843A0(p);
        }
    }
}

typedef struct {
    u8 p0[7]; u8 f7; u8 p00[0x34 - 8]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60;
} P2E71;

void func_002E71E0(P2E71 *p)
{
    extern void func_00175700();
    extern s32 func_00118FA8(f32);
    extern void func_001757E0(P2E71 *, s32, s32);
    extern void func_001E3270(P2E71 *, s32, f32);
    s32 x, y, d1, d2;
    f32 a, b, c = 16.0f;
    ((u8 *)p)[0x40C] = 2;
    ((u8 *)p)[0x33C] = 5;
    ((u8 *)p)[0x1FE] = 1;
    func_00175700(p);
    b = p->f5c;
    a = p->f34;
    p->f34 = a + (b - a) / c;
    b = p->f60;
    a = p->f38;
    b = b - a;
    p->f38 = a + b / c;
    x = (s16)func_00118FA8(p->f34);
    d1 = x - (s16)func_00118FA8(p->f5c);
    y = (s16)func_00118FA8(p->f38);
    d2 = y - (s16)func_00118FA8(p->f60);
    if (d1 < 0) d1 = -d1;
    if (d2 < 0) d2 = -d2;
    if (d1 < 2 && d2 < 2) {
        u32 t = p->f7;
        p->f7 = t + 1;
        p->f34 = p->f5c;
        p->f38 = p->f60;
        func_001757E0(p, 0xF, 7);
        func_001E3270(p, 0x21, 32.0f);
    }
}

typedef struct {
    u8 p0[5]; u8 f5; u8 p00[0x1C - 6]; s16 f1c; u8 p01[0xD4 - 0x1E]; s32 fd4; u8 p5[0x1C4 - 0xD8]; u8 *f1c4;
} P3BFA;
typedef struct {
    u8 p0[0x5C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; u32 f6c; u8 p4[0x1B4 - 0x70]; s8 f1b4; u8 p5[0x20A - 0x1B5]; u8 f20a; u8 f20b; u8 p6; u8 f20d;
} R3BFA;
typedef struct {
    u8 p0[0x16A]; s8 f16a; u8 p1[0x1DC - 0x16B]; s32 f1dc; u8 p2[0x1FE - 0x1E0]; u8 f1fe; u8 p3[0x20B - 0x1FF]; u8 f20b; u8 p4[0x425 - 0x20C]; u8 f425;
} Q3BFA;

void func_003BFA40(P3BFA *p, Q3BFA *q)
{
    extern void func_00175700();
    extern void func_001757E0(R3BFA *, s32, s32);
    extern void func_00185870(P3BFA *, R3BFA *);
    extern void func_00182C30(s32, s32);
    R3BFA *r = (R3BFA *)p->f1c4;
    f32 z = 0.0f;
    s32 v;
    func_00175700(p);
    if (r->f1b4 == 0) {
        u32 t = p->f5;
        p->f5 = t + 1;
        func_001757E0(r, 0xE, 0);
        func_00185870(p, r);
        p->fd4 = q->f1dc;
        v = 0x5A;
        if (q->f425 != 0) v = 0x3C;
        p->f1c = v;
        func_00182C30(q->f1dc, 1);
        r->f20a = 6;
        q->f20b = 0xC2;
        r->f20b = 0xC2;
        q->f1fe = 1;
        q->f16a = -1;
        if (r->f20d == 2) {
            r->f5c /= 4.0f;
            r->f68 /= 4.0f;
            if (r->f60 > z) r->f60 /= 4.0f;
            r->f6c = 0xBF4DB6DB;
        }
    }
}
