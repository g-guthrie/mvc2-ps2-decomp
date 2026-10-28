typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x1E8]; s8 a; u8 pad1[0x24]; u8 c; u8 pad2[2]; u8 b;} S_002AB9A0;
s32 func_002AB9A0(S_002AB9A0 *p) {
    if (p->c != 2) return 1;
    if (p->b == 0) {
        s32 x = p->a;
        if (x != 0) return 0;
        p->a = x + 1;
    }
    return 1;
}

typedef float f32;
typedef struct { u8 p0[0x1E]; s16 h; u8 p1[0xB0]; u32 fl; u8 p2[0x0C]; f32 f; s32 z; } S_00145050;
void func_00145050(S_00145050 *p) {
    p->h = p->h + 1;
    if (p->h >= 200) p->h = 0;
    p->fl |= 0x20000;
    p->f = 1.0f - 0.005f * (f32)p->h;
    p->z = 0;
}

typedef struct N_00194100 { u8 p0; u8 b1; u8 p1[0xE]; void *fn; struct N_00194100 *par; s32 w; u8 p2[4]; u8 f20; s8 f21; u8 p3[4]; s16 h; } N_00194100;
extern void func_00194170(void);
extern N_00194100 *func_003DA750(N_00194100 *, s32, s32);
typedef struct { u8 p0[5]; u8 x5, x6, x7; u8 p1[0x1B7-8]; u8 b; u8 p2[0x45]; u8 a; u8 p3[0x2DF]; s8 m; } S_0030C5D0;
extern void func_00186A60(S_0030C5D0 *, s32);
void func_0030C5D0(S_0030C5D0 *p) {
    p->x5 = 0; p->x7 = 0; p->x6 = 0;
    switch (p->m) {
    case 0: p->a = 2; p->b = 0; break;
    case 1: p->a = 3; p->b = 1; break;
    case 2: p->a = 10; p->b = 1; break;
    }
    func_00186A60(p, 0x15);
}

typedef struct { u8 p0[0x20]; u8 st; } S_tbl;
extern s32 func_003D92F0(S_tbl *);
extern void func_00126400(void);
extern void func_003266E0(S_tbl *);
extern void (*D_0045DEE0[])(S_tbl *);
void func_00323420(S_tbl *p) {
    if (func_003D92F0(p)) {
        func_00126400();
        func_003266E0(p);
    } else {
        D_0045DEE0[p->st](p);
    }
}
extern void func_001843A0(S_tbl *);
extern void func_00275950(S_tbl *);
extern void (*D_00454BE0[])(S_tbl *);
void func_002756A0(S_tbl *p) {
    if (func_003D92F0(p)) {
        func_001843A0(p);
    } else {
        if (p->st == 0) func_00275950(p);
        D_00454BE0[p->st](p);
    }
}
typedef struct { u8 p0[7]; u8 c7; u8 p1[0x14]; s16 h1C; s16 h1E; u8 p2[2]; u8 c22; u8 p3[0x319]; u8 c33C; u8 p4[0xCF]; u8 c40C; } S_002A53A0;
typedef struct { u8 p0[9]; u8 c9; } T_002A53A0;
extern void func_001CBDA0(S_002A53A0 *, s32, s32);
void func_002A53A0(S_002A53A0 *a, T_002A53A0 *b) {
    s32 two = 2;
    s32 five = 5;
    s16 h;
    a->c40C = two;
    a->c33C = five;
    h = a->h1C - 1;
    a->h1C = h;
    if (h == 0) {
        u32 t = a->c7;
        a->c7 = t + 1;
        a->h1C = 0x3C;
        b->c9 = 1;
        a->h1E = 0;
        a->c22 = five;
        func_001CBDA0(a, two, 0);
    }
}

typedef struct { u8 p0[0x151]; s8 f; } S_002E3810;
extern s8 func_00175700(void *);
extern void func_00183920(S_002E3810 *, void *);
void func_002E3810(S_002E3810 *p) {
    if (func_00175700(p) < 0) {
        func_001843A0((S_tbl *)p);
    } else if (p->f != 0) {
        f32 v[4];
        p->f = 0;
        v[0] = 0.0f;
        v[1] = 171.42855834960938f;
        func_00183920(p, v);
    }
}

typedef struct { u8 p0[5]; u8 c5; } B_003C8D70;
typedef struct { u8 p0[7]; u8 c7; u8 p1[0xC8]; B_003C8D70 *b; } A_003C8D70;
extern void (*D_00476230[])(A_003C8D70 *, B_003C8D70 *);
extern void func_003C9200(A_003C8D70 *, s32);
void func_003C8D70(A_003C8D70 *a, s32 x) {
    B_003C8D70 *b = a->b;
    if (b->c5 == 3) {
        D_00476230[a->c7](a, b);
    } else {
        func_003C9200(a, x);
    }
}

typedef struct { u8 p0[0x1C]; s16 h1C; u8 p1[2]; u8 c20; u8 p2[0x3F]; f32 f60; u8 p3[0x2F8]; u16 u35C; } S_002D0130;
void func_002D0130(S_002D0130 *a) {
    f32 z = 0.0f;
    if (a->f60 != z) {
        if (a->u35C & 0x60) {
            u32 t = a->c20;
            a->c20 = t + 1;
            if (a->c20 > 2) {
                s16 h;
                a->c20 = 0;
                h = a->h1C + 1;
                a->h1C = h;
                if (h > 6) a->h1C = 6;
            }
        }
    }
}

typedef struct { u8 p0[6]; u8 c6; u8 c7; u8 p1[0x16]; s16 h1E; u8 p2[0x131]; s8 f151; u8 p3[0x1EA]; u8 c33C; u8 p4[0xCF]; u8 c40C; } S_00293A60;
extern void func_00294BC0(S_00293A60 *);
extern void func_00126400(void);
extern void func_00294B20(S_00293A60 *, void *);
extern void func_001C09A0(S_00293A60 *, s32);
extern u8 D_00456E60[];
void func_00293A60(S_00293A60 *p) {
    p->c40C = 2;
    p->c33C = 5;
    func_00294BC0(p);
    func_00175700(p);
    if (p->f151 != 0) {
        u32 t = p->c6;
        p->c6 = t + 1;
        func_00126400();
        p->h1E = 4;
        p->c7 = 0;
        func_00294B20(p, D_00456E60);
        func_001C09A0(p, 9);
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x20]; f32 f5C, f60; u8 p2[4]; f32 f68, f6C; u8 p3[0x3C0]; f32 f430; } S_0036A810;
void func_0036A810(void *unused, S_0036A810 *p) {
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->f38 <= p->f430) p->f38 = p->f430;
}

typedef struct { u8 p0[0x20]; u8 c20; u8 p1[0x13]; f32 f34, f38; u8 p2[0x104]; s16 h140; } S_001DBD60;
extern int func_00174170(void);
extern f32 D_0044EA40[][4];
extern f32 D_0044EAD0[];
void func_001DBD60(S_001DBD60 *p) {
    f32 v = D_0044EA40[p->c20][func_00174170() & 3];
    if (p->h140 != 0) v = -v;
    p->f34 = p->f34 + v;
    p->f38 = p->f38 - D_0044EAD0[p->c20];
}

typedef struct { u8 p0[6]; u8 c6; u8 p1[0x14A]; s8 f151; u8 p2[0x1EA]; u8 c33C; } S_00279CF0;
extern void func_0037F080(S_00279CF0 *, s32, f32, f32);
extern void *func_001BC660(void *, int);
void func_00279CF0(S_00279CF0 *a) {
    a->c33C = 5;
    func_00175700(a);
    if (a->f151 != 0) {
        u32 t;
        a->f151 = 0;
        t = a->c6;
        a->c6 = t + 1;
        func_0037F080(a, 0, 93.33332824707031f, 227.14285278320312f);
        func_001BC660(a, 0xD);
        func_001BC660(a, 0x15);
    }
}

typedef struct { f32 x, y, z; } V3_0017DB70;
typedef struct { u8 p0[6]; u8 c6; u8 p1[0x14]; s16 h1C; u8 p2[0x1A]; f32 f38; u8 p3[0xC]; s32 w48; u8 p4[4]; V3_0017DB70 v50; u8 p5[0xBC]; f32 f118; u8 p6[0x20]; u8 c13C; u8 p7[0x15B]; V3_0017DB70 v298; u8 p8[0x18C]; f32 f430; } S_0017DB70;
extern void func_00185510(S_0017DB70 *);
extern void func_00178E10(S_0017DB70 *);
extern void func_0017DC00(S_0017DB70 *);
void func_0017DB70(S_0017DB70 *a) {
    u32 t = a->c6;
    a->c6 = t + 1;
    func_00185510(a);
    a->c13C = 1;
    a->w48 = 0;
    a->v50 = a->v298;
    a->f118 = 1.0f;
    func_00178E10(a);
    if (a->f38 < a->f430) a->f38 = a->f430;
    a->h1C = 0;
    func_0017DC00(a);
}

typedef struct { u8 p0[8]; f32 f90, f94; u8 p1[4]; s32 w14, w18; } P_001937E0;
typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x4C]; P_001937E0 sub; } A_001937E0;
typedef struct { u8 p0[0x34]; f32 f34, f38; } B_001937E0;
extern s32 func_00417690(f32, f32);
extern s32 func_00119D88(s32);
void func_001937E0(A_001937E0 *a, B_001937E0 *b) {
    P_001937E0 *p = &a->sub;
    f32 dx = b->f34 + p->f90;
    f32 dy = b->f38 + p->f94;
    p->w18 = func_00417690(dy - a->f38, dx - a->f34);
    if (func_00119D88(p->w18 - p->w14) >= 0x400) {
        if (p->w18 - p->w14 > 0) {
            p->w14 = p->w14 - 0x400;
        } else {
            p->w14 = p->w14 + 0x400;
        }
    }
}

typedef struct { u8 p0[6]; u8 c6; u8 p1[0x159]; s8 b[2]; } S_002A9050;
extern void func_001E3210(S_002A9050 *, s32);
extern void func_00394780(S_002A9050 *, s32, s32);
extern void func_001757E0(S_002A9050 *, s32, s32);
void func_002A9050(S_002A9050 *a) {
    if (func_00175700(a) >= 0) {
        s8 *p = a->b;
        s8 f = p[1];
        s8 *q = p + 1;
        if (f & 1) {
            *q = f & ~1;
            func_001E3210(a, 0x1E);
            func_00394780(a, 0, 0);
        }
    } else {
        u32 t = a->c6;
        a->c6 = t + 1;
        func_001757E0(a, 0x15, 1);
    }
}
