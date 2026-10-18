typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[6]; u8 b6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0x19D]; u8 b20D; u8 p5[0x222]; f32 f430;} A_002F38A0;
typedef struct { u8 p0[6]; u8 b6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0x176]; u8 b1E6; u8 p5[0x249]; f32 f430;} A_002D7030;
typedef struct { u8 p0[0x34]; f32 f34; } A_00263850;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3c; } A_001DEF80;

void func_002F38A0(A_002F38A0 *p)
{
    extern void func_00175700(A_002F38A0 *);
    extern void func_001757E0(A_002F38A0 *, s32, s32);
    f32 *v1, *a3, *t0, *t1;
    func_00175700(p);
    v1 = &p->f5c; t0 = &p->f68; a3 = &p->f60; t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        p->b6++;
        p->f38 = p->f430;
        *(s32*)v1 = 0; *(s32*)a3 = 0; *(s32*)t0 = 0; *(s32*)t1 = 0;
        p->b20D = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_00299130(u8 *a)
{
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[3];
    f32 t;
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        a[6]++;
        a[0x151] = 0;
        *(u32 *)(a + 0x5C) = 0;
        *(u32 *)(a + 0x60) = 0;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x6C) = 0;
        if (a[0x1E6] != 0) t = 16.66666603088379f; else t = -16.66666603088379f;
        *(f32 *)(a + 0x5C) = t;
        if (a[0x1E6] != 0) t = -0.625f; else t = 0.625f;
        *(f32 *)(a + 0x68) = t;
        a[0x404] = 0;
        a[0x405] = 0;
        v[0] = -25.0f;
        v[1] = 100.71427917480469f;
        v[2] = 0;
        func_001830D0(a, v, 1);
    }
}

void func_002D7030(A_002D7030 *p)
{
    extern void func_00175700(A_002D7030 *);
    extern void func_001757E0(A_002D7030 *, s32, s32);
    f32 *v1, *a3, *t0, *t1;
    f32 t;
    v1 = &p->f5c; t0 = &p->f68; a3 = &p->f60; t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (!(p->f430 < p->f38)) {
        p->b6++;
        *(s32*)v1 = 0; *(s32*)a3 = 0; *(s32*)t0 = 0; *(s32*)t1 = 0;
        p->f38 = p->f430;
        if (p->b1E6 != 0) t = -6.666666507720947f; else t = 6.666666507720947f;
        p->f5c = t;
        func_001757E0(p, 2, 3);
    }
}

void func_00263850(u8 *a)
{
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    f32 f;
    s8 v;
    switch (a[0x1FC]) {
    case 2:
        if (func_00175700(a) < 0) {
            func_001843A0(a);
            return;
        }
        v = *(s8 *)(a + 0x151);
        if (v != 0) {
            if (a[0x1E6] != 0) f = 1.6666666269302368f * (f32)v;
            else f = -(1.6666666269302368f * (f32)v);
            ((A_00263850 *)a)->f34 += f;
            a[0x151] = 0;
        }
        break;
    case 1:
        if (func_00175700(a) < 0) func_001843A0(a);
        break;
    case 0:
        if (func_00175700(a) < 0) func_001843A0(a);
        break;
    }
}

void func_003132E0(u8 *a, u8 *b)
{
    extern void func_00175700(u8 *);
    extern void func_001DD920(u8 *, s32, s32);
    extern void func_001830D0(u8 *, f32 *, s32);
    extern u8 *func_003C11D0(u8 *, s32, s32);
    extern void func_001843A0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    f32 v[3];
    s8 t;
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    t = *(s8 *)(a + 0x151);
    if (t & 2) {
        a[0x151] = t & ~2;
        func_001DD920(a, 0xD, 0);
    }
    if (*(s8 *)(a + 0x151) & 1) {
        a[6]++;
        v[0] = -5.0f;
        v[1] = 186.42855834960938f;
        a[0x404] = 0;
        a[0x405] = 0;
        func_001830D0(a, v, 1);
        *(u8 **)(a + 0x14) = func_003C11D0(a, 0, 0);
        if (*(u8 **)(a + 0x14) == 0) {
            func_001843A0(a);
            return;
        }
        b[0xC] = 1;
        func_001266A0(a, 1, 1);
        *(s16 *)(a + 0x1C) = 0x50;
    }
}

void func_001DEF80(A_001DEF80 *a, u8 *b)
{
    extern void func_001DEE30(A_001DEF80 *);
    extern void func_001DEEB0(A_001DEF80 *, u8 *);
    extern void func_001DEEF0(A_001DEF80 *, u8 *);
    extern s16 func_00118FA8(f32);
    extern void func_00163F00(f32 *, s32);
    u8 *s1;
    f32 v[4];
    s16 d;
    s1 = b + 0x2B8;
    func_001DEE30(a);
    func_001DEEB0(a, b);
    func_001DEEF0(a, b);
    d = func_00118FA8(a->f34 - *(f32 *)(b + 0x34));
    if (d < 0) d = -d;
    if (d < 0x10) {
        s1[0x14] = 1;
        if (*(s16 *)((u8 *)a + 0x140) == 0) v[0] = 102.85713958740234f + a->f34;
        else v[0] = a->f34 - 102.85713958740234f;
        v[1] = 102.85713958740234f + a->f38;
        v[2] = a->f3c;
        func_00163F00(v, *(u8 *)((s32)a + 0x140));
        *(s16 *)((u8 *)a + 0x1C) = 8;
        ((u8 *)a)[5]++;
    }
}
