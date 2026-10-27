typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z, w; } V4;
typedef struct { s32 m[16]; } M4;
extern u32 D_00457860[];
extern u8 D_00457040[];
typedef struct { u8 *ptr; s32 b; s32 c; } E12;
extern E12 D_004D18B8[];
typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x34 - 7];
    f32 f34, f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60; u8 pad64[0x68 - 0x64];
    f32 f68, f6c;
} S;


void func_003DE3D0(V4 *out, V4 *in, M4 *mat)
{
    V4 a;
    V4 r;
    M4 m;
    M4 *pm;
    V4 *pa;
    V4 *pr;
    a = *in;
    m = *mat;
    pm = &m;
    pa = &a;
    pr = &r;
    asm {
        lqc2 vf4, 0(pa)
        lqc2 vf5, 0(pm)
        lqc2 vf6, 0x10(pm)
        lqc2 vf7, 0x20(pm)
        lqc2 vf8, 0x30(pm)
        vmulax.xyzw ACC, vf5, vf4x
        vmadday.xyzw ACC, vf6, vf4y
        vmaddaz.xyzw ACC, vf7, vf4z
        vmaddw.xyzw vf4, vf8, vf4w
        sqc2 vf4, 0(pr)
    }
    *out = r;
}

void func_00291610(u8 *p)
{
    extern s32 func_00294BC0(u8 *);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern s32 func_00174170(void);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_003888B0(u8 *, s32);
    extern void func_00294B20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    u8 *q;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    if (func_00294BC0(p) == 0) {
        p[6]++;
        q[0xA] = 0;
        q[0x19] = 0;
        *(s16 *)(q + 0x1E) = 0xB4;
        func_00131AB0(p, q + 0x1E, 6);
        *(u32 *)(q + 0x14) = D_00457860[func_00174170() & 3];
        q[0x1B] = 1;
        func_00185490(p);
        func_00175C00(p, 0);
        func_003888B0(p, 0);
        func_003888B0(p, 1);
        func_003888B0(p, 3);
        func_003888B0(p, 4);
        func_00294B20(p, D_00457040);
        func_001757E0(p, 0x16, 8);
        func_001E3210(p, 0x1E);
    }
}

void func_00252AC0(u8 *p)
{
    extern s32 func_00252C80(u8 *);
    extern void func_001AD170(u8 *, s32, s32);
    extern void func_0018FAA0(u8 *, s16);
    extern void func_0015F4B0(u8 *, s8);
    extern void func_001757E0(u8 *, s32, u8);
    u8 *e;
    s16 v;
    e = D_004D18B8[p[2]].ptr;
    if (func_00252C80(p) != 0) {
        if (*(s16 *)(e + 0x434) != 0 || e[0x425] == 0) {
            p[6]++;
            func_001AD170(p, 8, p[0x1E]);
            func_0018FAA0(e, *(s16 *)(p + 0x1E) ? 0x14 : 0xA);
            func_0015F4B0(e, 4);
            func_001757E0(p, 0x15, *(s16 *)(p + 0x1E) + 0x15);
            return;
        }
        *(s16 *)(p + 0x1C) = 1;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[6] += 2;
        func_001757E0(p, 0x15, *(s16 *)(p + 0x1E) + 0x17);
    }
}

void func_0020E290(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00350FF0(u8 *);
    S *q = (S *)p;
    f32 *s0, *s1, *s2, *s3;
    u8 *t;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    s0 = &q->f5c;
    s2 = &q->f68;
    s1 = &q->f60;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    s3 = &q->f6c;
    q->f60 += q->f6c;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[6]++;
        t = *(u8 **)(p + 0x1DC);
        *(u8 **)(t + 0x1C8) = p;
        t[0x20A] = 0xD;
        t[0x20D] = 2;
        t[0x1B5] = 0x22;
        func_001266A0(p, 0, 0);
        func_00350FF0(p);
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0xC0;
        *(s32 *)s0 = 0;
        *(s32 *)s1 = 0;
        *(s32 *)s2 = 0;
        *(s32 *)s3 = 0;
    }
}

void func_003CC2E0(u8 *p, u8 *a1)
{
    extern void func_00175700(u8 *);
    extern void func_003CC420(u8 *, u8 *);
    extern s32 func_00182C90(u8 *);
    extern void func_003CAB20(u8 *, u8 *, u32);
    extern void func_001843A0(u8 *);
    extern void func_001845F0(u8 *);
    u8 *s0;
    s16 v;
    s32 a2;
    s0 = *(u8 **)(p + 0xD4);
    func_00175700(p);
    func_003CC420(p, a1);
    if (p != *(u8 **)(s0 + 0x1E0) || (*(s8 *)(s0 + 0x1B3) != 0 && s0[5] == 3)) {
        *(s32 *)(p + 0x5C) = 0;
        func_003CAB20(p, a1, 0x11);
        p[7] = 0xA;
        return;
    }
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (func_00182C90(s0) != 0) {
        *(s16 *)(p + 0x1C) -= 3;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        s0[0x20A] = 0;
        s0[0x203] = 8;
        if (*(s16 *)(s0 + 0x434) > 0) {
            if (s0[0x20D] != 2) {
                func_001843A0(s0);
            } else {
                func_001845F0(s0);
            }
        }
        *(s32 *)(p + 0x5C) = 0;
        s0 = (u8 *)0xB;
        a2 = 0x11;
        if (*(s16 *)(p + 0x1E) <= 0) {
            s0 = (u8 *)0xC;
            a2 = 0x13;
        }
        func_003CAB20(p, a1, a2);
        p[7] = (u8)(s32)s0;
    }
}
