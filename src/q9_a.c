typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[0x6]; u8 f6; u8 p7[0x17]; s16 f1c; s16 f1e;
} X_0;
typedef struct {
    u8 p0[0x1E]; s16 f1e; u8 p20[0x20]; s32 f40; u8 p44[0xC]; f32 f50, f54, f58; u8 p5c[0x10]; f32 f6c, f70; u8 p74[4]; f32 f78, f7c, f80;
} A_0;
void func_00145E40(A_0 *p) {
    s16 v = p->f1e;
    if (v != 0) {
        p->f1e = v - 1;
        p->f50 += p->f6c;
        p->f54 += p->f6c;
        p->f58 += p->f6c;
        p->f78 -= p->f70;
        p->f7c -= p->f70;
        p->f80 -= p->f70;
        p->f40 += 0xE39;
    }
}


typedef struct {
    u8 p0[0x34]; f32 f34, f38; u8 p3c[0x104]; s16 f140;
} P_1;
typedef struct {
    u8 p0[0x20]; u8 f20; u8 p21[0x13]; f32 f34, f38;
} Q_1;
void func_00353F90(P_1 *a, Q_1 *b) {
    s16 s;
    s = b->f20 ? -0x20 : -0x38;
    if (a->f140 != 0) s = -s;
    a->f34 = b->f34 + 0.9f * (1.6666666269302368f * (f32)s);
    a->f38 = b->f38;
}


extern void func_001757E0();
typedef struct {
    u8 p0[0x34]; f32 f34, f38; u8 p3c[0x104]; s16 f140;
} P_2;
typedef struct {
    u8 p0[0x1C]; s16 f1c, f1e; u8 p20; u8 f21; u8 p22[2]; u8 f24; u8 p25[0xF]; f32 f34, f38; u8 p3c[0x94]; P_2 *fd0;
} Q_2;
void func_001DC940(Q_2 *a) {
    P_2 *o = a->fd0;
    s32 v;
    s32 c;
    a->f24 = 7;
    v = -0x40; if (o->f140 != 0) v = 0x40;
    a->f34 = o->f34 + 1.6666666269302368f * (f32)v;
    a->f38 = 308.5714111328125f + o->f38;
    a->f1c = 0x8C;
    a->f1e = 0;
    c = 9; if (a->f21 != 0) c = 8;
    func_001757E0(a, 0x16, (u8)c);
}


extern s32 func_00175700();
typedef struct {
    u8 p0[6]; u8 f6; u8 p7[0x55]; f32 f5c; f32 f60; f32 f64; f32 f68, f6c; u8 p70[0xE1]; s8 f151; u8 p152[0x94]; u8 f1e6;
} P_3;
void func_00296A40(P_3 *a) {
    u32 t; f32 x;
    func_00175700(a);
    if (a->f151 == 0) {
        t = a->f6; a->f6 = t + 1;
        a->f60 = 0;
        a->f6c = 0;
        if (a->f1e6 != 0) x = 20.0f; else x = -20.0f;
        a->f5c = x;
        if (a->f1e6 != 0) x = -0.625f; else x = 0.625f;
        a->f68 = x;
    }
}


extern void func_00185510();
extern void func_00178E10();
extern void func_0017EBB0();
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[6]; u8 f6; u8 p7[0x2D]; f32 f34, f38; u8 p3c[0xC]; s32 f48; u8 p4c[4]; V3 f50; u8 p5c[0xBC]; f32 f118; u8 p11c[0x20]; u8 f13c;
    u8 p13d[0x15B]; V3 f298; u8 p2a4[0x18C]; f32 f430;
} P_4;
void func_0017EB20(P_4 *a) {
    u32 t = a->f6;
    a->f6 = t + 1;
    func_00185510(a);
    a->f13c = 1;
    a->f48 = 0;
    a->f50 = a->f298;
    a->f118 = 1.0f;
    func_00178E10(a);
    if (a->f38 < a->f430) a->f38 = a->f430;
    *(s16*)((u8*)a + 0x1C) = 0;
    func_0017EBB0(a);
}


extern void func_001843A0();
typedef struct {
    u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0xE1]; s8 f151;
} P_5;
void func_0024F670(P_5 *a) {
    if (a->f151 != 0) {
        a->f34 += a->f5c;
        a->f5c += a->f68;
        a->f38 += a->f60;
        a->f60 += a->f6c;
    }
    if ((s8)func_00175700(a) < 0) func_001843A0(a);
}


extern void func_00184540();
extern void func_001CEA00();
typedef struct R_6 { u8 p0[0x1B5]; u8 f1b5; u8 p1b6[0x12]; void *f1c8; u8 p1cc[0x3E]; u8 f20a; } R_6;
typedef struct {
    u8 p0[0x151]; s8 f151; u8 p152[0x8A]; R_6 *f1dc;
} P_6;
void func_002CBAB0(P_6 *a) {
    R_6 *q;
    if ((s8)func_00175700(a) < 0) {
        func_00184540(a);
        return;
    }
    if (a->f151 == 2) {
        a->f151 = 0;
        func_001CEA00(a, 5);
    }
    if (a->f151 == 1) {
        a->f151 = 0;
        q = a->f1dc;
        q->f1c8 = a;
        q->f20a = 1;
        q->f1b5 = 0x21;
    }
}


typedef struct {
    u8 p0[6]; u8 f6; u8 p7[0x2D]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0xE1]; s8 f151;
} P_7;
void func_001F8E40(P_7 *a) {
    f32 *p5c, *p60, *p68, *p6c;
    u32 t;
    p5c = &a->f5c;
    p68 = &a->f68;
    p60 = &a->f60;
    a->f34 += a->f5c;
    a->f5c += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    p6c = &a->f6c;
    if (a->f151 != 0) {
        a->f151 = 0;
        t = a->f6; a->f6 = t + 1;
        *p5c = 0;
        *p60 = 0;
        *p68 = 0;
        *p6c = 0;
    } else {
        func_00175700(a);
    }
}


typedef struct {
    u8 p0[0x430]; f32 f430;
} B_8;
typedef struct {
    u8 p0[5]; u8 f5; u8 p6[0x16]; s16 f1c; u8 p1e[0x16]; f32 f34, f38; u8 p3c[0x24]; f32 f60; u8 p64[8]; f32 f6c;
} P_8;
void func_001DA020(P_8 *a, B_8 *b) {
    s16 v;
    u32 t;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    func_00175700(a);
    v = a->f1c - 1;
    a->f1c = v;
    if (v == 0) {
        t = a->f5; a->f5 = t + 1;
        a->f38 = b->f430;
        a->f1c = 0x10;
        func_001757E0(a, 0x12, 7);
    }
}


extern s32 func_001E7FD0();
typedef struct {
    u8 p0[0x1B7]; u8 f1b7; u8 p1b8[0x53]; u8 f20b; u8 p20c; u8 f20d; u16 f20e_; u8 p210[2]; u8 f212;
} P_9;
s32 func_002D8900(P_9 *a) {
    s32 r = 0;
    if ((*(u16*)((u8*)a + 0x20E) & 0xC00) != 0 && a->f1b7 != 0) {
        if (a->f20d == 2) {
            if (a->f212 == 0) {
                if ((r = func_001E7FD0(a)) != 0) a->f20b = 2;
            }
        } else {
            if ((r = func_001E7FD0(a)) != 0) {
                if (a->f212 == 0) a->f20b = 1; else a->f20b = 0;
            }
        }
    }
    return r;
}


extern void func_00186A20();
typedef struct { f32 a, b, c, d; } E_10;
extern E_10 D_004B7580[];
typedef struct {
    u8 p0[6]; u8 f6; u8 p7[0x55]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0xE1]; s8 f151;
} P_10;
void func_002B5320(P_10 *a) {
    E_10 *t;
    u32 v;
    func_00175700(a);
    if (a->f151 >= 0) {
        v = a->f6; a->f6 = v + 1;
        func_00186A20(a);
        t = &D_004B7580[*(u8*)((u8*)a + 0x1B7)];
        a->f5c = t->a;
        a->f68 = t->b;
        a->f60 = t->c;
        a->f6c = t->d;
        if (*(s16*)((u8*)a + 0x140) != 0) {
            a->f5c = -a->f5c;
            a->f68 = -a->f68;
        }
    }
}


extern void func_001830D0();
typedef struct {
    u8 p0[6]; u8 f6; u8 f7; u8 p8[0x261]; u8 f269; u8 p26a[0xD2]; u8 f33c; u8 p33d[0xC7]; u8 f404; u8 f405; u8 p406[6]; u8 f40c;
} P_11;
void func_00230B50(u8 *p, void *context) {
    P_11 *a = (P_11 *)p;
    f32 v[4];
    u32 t;
    a->f40c = 2;
    a->f33c = 5;
    a->f405 = (a->f269 == 6) ? 2 : 0;
    if ((s8)func_00175700(a) < 0) {
        t = a->f6; a->f6 = t + 1;
        a->f7 = 0;
        a->f404 = 0;
        a->f405 = 0;
        v[0] = 40.0f;
        v[1] = 199.28570556640625f;
        func_001830D0(a, v, 1, t + 1);
    }
}


extern s32 func_00175670();
extern void func_001754A0();
extern void func_001E3710();
typedef struct {
    u8 p0[4]; u8 f4; u8 p5[0x57]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0xD0]; s16 f140;
} P_12;
void func_001B7800(P_12 *a) {
    u32 t;
    if ((s8)func_00175670(a) < 0) {
        t = a->f4; a->f4 = t + 1;
        if (a->f140 != 0) a->f5c = 2.5f; else a->f5c = -3.3333332538604736f;
        a->f68 = 0;
        a->f60 = 17.14285659790039f;
        a->f6c = -0.5357142686843872f;
        a->f140 ^= 1;
        func_001754A0(a, 0x1B, 5);
        func_001E3710(a, 0x2F);
    }
}


typedef struct O_13 {
    u8 p0[0x10]; void *f10; void *f14; u8 p18[4]; s16 f1c, f1e; u8 f20; u8 p21[5]; s16 f26; u8 p28[0xC]; s32 f34, f38; f32 f3c; u8 p40[0x44]; s32 f84; u8 p88[0x48]; s32 fd0; u8 pd4[0x68]; u8 f13c;
} O_13;
extern O_13 *func_003DA750(void *, s32, s32);
extern void func_00136370();
extern s16 D_0043F160[];
u8 *func_001362C0(u8 *a, s32 i) {
    O_13 *o;
    s32 c;
    c = 3;
    if (a == 0) c = 1;
    if ((o = func_003DA750(a, 0xF, (u8)c)) != 0) {
        o->f13c = 0;
        o->f10 = (void*)func_00136370;
        o->f84 = 0;
        o->fd0 = 0;
        o->f26 = 8;
        o->f20 = i;
        o->f34 = 0;
        o->f38 = 0;
        o->f3c = -40.0f;
        o->f14 = a;
        o->f1c = D_0043F160[i];
        o->f1e = 0x78 - o->f1c;
    }
    return (u8 *)o;
}


extern void func_00174A40();
typedef struct S_14 { u8 p0[0x34]; V3 f34; } S_14;
typedef struct {
    u8 p0[5]; u8 f5; u8 p6[0xE]; S_14 *f14; u8 p18[4]; s16 f1c, f1e; u8 p20[0x14]; V3 f34; u8 p40[0x10]; f32 f50, f54;
} P_14;
void func_00364510(P_14 *a) {
    u32 t;
    s16 v;
    S_14 *o;
    o = a->f14;
    a->f50 -= 0.10000000149011612f;
    a->f54 -= 0.10000000149011612f;
    v = a->f1e - 200;
    a->f1e = v;
    a->f34 = o->f34;
    func_00174A40(a, a->f1e);
    v = a->f1c - 1;
    a->f1c = v;
    if (v == 0) {
        t = a->f5; a->f5 = t + 1;
        a->f50 = 0.5f;
        a->f54 = 0.5f;
        a->f1c = 6;
    }
}


extern s32 func_00174470();
extern s32 func_001745B0();
extern void func_003BE2C0(u8 *,u8 *);
typedef struct {
    u8 p0[4]; u8 f4; u8 p5[0x2F]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c;
} P_15;
void func_003BE1A0(u8 *a, void *b) {
    u32 t;
    ((P_15 *)a)->f34 += ((P_15 *)a)->f5c;
    ((P_15 *)a)->f5c += ((P_15 *)a)->f68;
    ((P_15 *)a)->f38 += ((P_15 *)a)->f60;
    ((P_15 *)a)->f60 += ((P_15 *)a)->f6c;
    if (func_00174470(a) == 0 || func_001745B0(a) == 0) {
        t = ((P_15 *)a)->f4; ((P_15 *)a)->f4 = t + 1;
    }
    func_003BE2C0((u8 *)a, (u8 *)b);
}
