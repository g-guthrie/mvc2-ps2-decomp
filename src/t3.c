typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[1]; u8 b1; u8 pad2[0xE]; void *f10; void *p18; u8 pad1c[0]; } X;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; } S_00249DC0;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; u8 p152[0x2DE]; f32 f430; } S_002BAB60;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x3C0]; f32 f430; } S_0020E9C0;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x3C0]; f32 f430; } S_0022C130;
typedef struct { u8 p0[0x420]; s8 *p420; u8 p424[0x32]; s16 h456; u16 h458; u8 p45a[0x6E]; s32 w4c8; } A_00168810;
typedef struct { u8 p0[4]; u16 h4; } B_00168810;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x3C0]; f32 f430; } S_0025EB90;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x1A]; u8 b21; u8 p22[0x12]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x3C0]; f32 f430; } S_002C3360;
extern u8 *func_003DA750();
extern void func_003B7AB0();
extern void func_00185490();
extern void func_001757E0();
extern s32 func_00175700();
extern void func_001843A0();
extern void func_00126400();
extern void func_0038EDE0();
extern void func_00183D90();
extern void func_001863F0();
extern void func_001A78D0();
typedef struct { f32 x, y, z; } V3;
extern void func_001B9D40();
extern void func_00175580();
extern void func_00183d50();
extern void func_0022C6B0();
extern void func_0016B0C0();
extern void residual_001487B0();
extern V3 D_00442AA0;
extern void func_003DC950();
extern void func_00100F00(s32, s32);
extern void func_00101400(void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_00104060(s32);
extern void func_001016C0(void *, s32);
extern void func_001754A0();
extern s32 func_00175670();
extern void (*D_00459B70[])(void *);

void func_003B79A0(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_003B7AB0;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x3501;
        o[0x20] = 0;
        *(s16 *)(o + 0x1C) = *(s16 *)(p + 0x1C) - 0x10;
        *(s16 *)(o + 0x1E) = p[0x168];
    }
}

void func_002FA490(u8 *p) {
    u32 v = p[6];
    if (v == 0) {
        p[6] = v + 1;
        func_00185490(p);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x14, 3);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) func_001843A0(p);
    }
}

void func_00222140(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[0x151] != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
        (*(u8 **)(p + 0x1DC))[0x20A] = 1;
        (*(u8 **)(p + 0x1DC))[0x1E6] = p[0x1E6];
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x21;
        (*(u8 **)(p + 0x1DC))[0x20D] = 2;
        func_00126400();
    }
}

static void func_00297F90(u8 *p) {
    f32 *v = (f32 *)(p + 0x60);
    f32 *w = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *v += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *v = 0;
        *w = 0;
    }
}
void func_00298270(u8 *p) {
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_00297F90(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x16, 5);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        *(s16 *)(p + 0x1C) = 4;
        func_0038EDE0(p);
    }
}

void func_00249DC0(S_00249DC0 *p) {
    if (*((u8 *)p + 0x213) == 3) func_00183D90(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001863F0(p);
    func_00175700(p);
    if (p->b151 != 0) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        func_001A78D0(p, 0x11);
    }
}

void func_001B9F60(u8 *p) {
    s8 *q = *(s8 **)(p + 0x18);
    s32 t;
    if (p[1] != (u8)q[1]) {
        func_001B9D40(p);
        return;
    }
    *(s8 *)(p + 0x24) = q[0x24];
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    t = (*(s8 **)(p + 0x18))[0x161];
    if (t == 9) {
        func_001B9D40(p);
    } else if (t != 0) {
        func_00175580(p, 0x1B, p[0x168], t - 1);
        (*(u8 **)(p + 0x18))[0x161] = 0;
    }
}

void func_002BAB60(S_002BAB60 *p) {
    s32 *a;
    s32 *b;
    if (p->b151 == 0) func_00175700(p);
    a = (s32 *)&p->f60;
    b = (s32 *)&p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        p->f38 = p->f430;
        *((u8 *)p + 0x20D) = 0;
        *a = 0;
        *b = 0;
        func_00183d50(p);
    }
}

void func_0020E9C0(S_0020E9C0 *p) {
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        p->f38 = p->f430;
        func_00183d50(p);
        *((u8 *)p + 0x20D) = 0;
        func_001757E0(p, 1, 3);
    }
}

void func_0022C130(S_0022C130 *p) {
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f38 <= p->f430)) {
        func_00175700(p);
    } else {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        p->f38 = p->f430;
        *((u8 *)p + 0x20D) = 0;
        func_001757E0(p, 0xF, 2);
        func_0022C6B0(p);
    }
}

s32 func_00168810(A_00168810 *a, B_00168810 *b) {
    u32 t;
    func_0016B0C0(a, b, 0);
    a->h458 = b->h4;
    t = b->h4;
    b->h4 = t + 5;
    func_0016B0C0(a, b, 1);
    if (*a->p420 < a->w4c8) {
        t = b->h4;
        b->h4 = t + 2;
        a->h456 = 0;
        return 1;
    } else {
        func_0016B0C0(a, b, 2);
        if (a->w4c8 < 0) a->w4c8 = 0;
        a->h456 = *(s16 *)((u8 *)a + 0x4C8);
    }
    return 1;
}

void func_00147870(s8 a, u8 b) {
    u8 *o;
    if (a == 2 || a == 6) {
        o = func_003DA750(0, 0xD, 1);
    } else {
        o = func_003DA750(0, 0xD, 0);
    }
    if (o != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = residual_001487B0;
        o[0x23] = a;
        o[0x20] = b;
        *(V3 *)(o + 0x50) = D_00442AA0;
        *(s32 *)(o + 0xD0) = 0x431;
    }
}

void func_0025EB90(S_0025EB90 *p) {
    if (p->f38 < p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        *(s32 *)&p->f5c = 0;
        *(s32 *)&p->f68 = 0;
        *(s32 *)&p->f60 = 0;
        *(s32 *)&p->f6c = 0;
        p->f38 = p->f430;
        func_00183d50(p);
        func_001757E0(p, 0x15, 8);
    } else {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700(p);
    }
}

void func_003DC190(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s16 i) {
    u8 buf[0x70];
    func_003DC950(a);
    func_00100F00(0, 0);
    func_00101400(buf, c, d, e, f, g, h, i);
    func_00104060(0);
    func_001016C0(buf, a);
    func_00100F00(0, 0);
}

void func_003C1F30(u8 *a, u8 *b) {
    if (b[5] != 0) {
        u32 t = a[4];
        a[4] = t + 1;
        return;
    }
    if (b[0x169] != 0x16) {
        u32 t = a[4];
        a[4] = t + 1;
        return;
    }
    {
        s8 r = func_00175700(a);
        if (r < 0) {
            u32 t = a[4];
            a[4] = t + 1;
        }
    }
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24) + *(s8 *)(a + 0x31);
    if (*(s8 *)(a + 0x24) > 7) *(s8 *)(a + 0x24) = 7;
    if (*(s8 *)(a + 0x24) < 0) *(s8 *)(a + 0x24) = 0;
}

void func_001C9E50(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (p[5] == 0) {
        s16 v;
        if (q[0x1E4] == 0x1D && q[0x1FD] == 1) {
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v < 0) goto L;
        } else {
        L:
            {
                u32 t = p[5];
                p[5] = t + 1;
            }
            func_001754A0(p, 0x1B, 0x2A);
        }
        func_00175670(p);
    } else {
        s8 r = func_00175670(p);
        if (r < 0) p[4] = 2;
    }
}

void func_002C3360(S_002C3360 *p) {
    f32 lim;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        if (p->b21 == 0) {
            func_00183d50(p);
            p->b21 = 1;
        }
    }
    D_00459B70[p->b6](p);
}
