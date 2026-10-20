typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001FD2A0(void *);
typedef struct { u8 pad0[0x60]; f32 f60; u32 f64; u32 f68; u32 f6c; } P1FD320;
void func_001FD320(u8 *p) {
    s8 *q = (s8 *)p + 0x2B8;
    if (((s8 *)p)[0x2D1] != 0) {
        f32 z = 0.0f; P1FD320 *s = (P1FD320 *)p;
        q[0x19] = 0;
        if (s->f60 > z) { s->f60 = z; }
        ((P1FD320 *)p)->f68 = 0;
        ((P1FD320 *)p)->f6c = 0xBF4DB6DB;
    }
    {
        u8 m = p[0x212];
        if (m == 0 && (((s8 *)p)[0x1EA] & 0xF) != 0) {
            func_001FD2A0(p);
        } else if (m != 0 && (((s8 *)p)[0x1EA] & 0xF0) != 0) {
            func_001FD2A0(p);
        }
    }
}

extern s8 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; } Q390;
typedef struct { u8 pad0[0x5]; u8 f5; u8 pad6[0x12]; Q390* f18; u8 pad1C[0x18]; f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5C; f32 f60; u8 pad64[0x4]; f32 f68; f32 f6C; } P390;
void func_00390230(P390 *p) {
    if (func_00175700(p) < 0) {
        u32 t = p->f5;
        p->f5 = t + 1;
        func_001757E0(p, 0x17, 0xA);
        return;
    }
    p->f5C += p->f68;
    p->f60 += p->f6C;
    p->f34 = p->f18->f34 + p->f5C;
    p->f38 = p->f18->f38 + p->f60;
}

typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x2d]; f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5C; f32 f60; u8 pad64[0x4]; f32 f68; f32 f6C; u8 pad70[0x2ee]; u16 f35E; u8 pad360[0x1d9]; s8 f539; } P205;
void func_00205280(P205 *p) {
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (func_00175700(p) < 0 || (p->f539 == 0 && (p->f35E & 0x800) != 0)) {
        u32 t = p->f6;
        p->f6 = t + 1;
        func_001757E0(p, 2, 3);
    }
}

extern void func_00175670(void *);
extern void func_001754A0(void *, s32, s32);
typedef struct { u8 pad0[0x430]; f32 f430; } Q19A;
typedef struct { u8 pad0[0x5]; u8 f5; u8 pad6[0x2e]; f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5C; f32 f60; u8 pad64[0x4]; f32 f68; f32 f6C; } P19A;
void func_0019ADE0(P19A *p, Q19A *q) {
    func_00175670(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->f38 <= q->f430) {
        u32 t = p->f5;
        p->f5 = t + 1;
        p->f38 = q->f430;
        func_001754A0(p, 0x1B, 5);
    }
}

extern void func_00183d50(void *);
extern void func_001E3240(void *, s32);
typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x2d]; f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5C; f32 f60; u8 pad64[0x4]; f32 f68; f32 f6C; u8 pad70[0x3c0]; f32 f430; } P306;
void func_00306980(P306 *p) {
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->f38 < p->f430) {
        u32 t;
        p->f38 = p->f430;
        t = p->f6;
        p->f6 = t + 1;
        func_001757E0(p, 1, 3);
        func_00183d50(p);
        func_001E3240(p, 0x30);
    }
}

extern void func_00154400();
typedef struct { u8 pad0[0x10]; void* f10; u8 pad14[0x20]; f32 f34; f32 f38; u32 f3C; u8 pad40[0x10]; u32 f50; u32 f54; u32 f58; u8 pad5C[0x1c]; u32 f78; u32 f7C; u32 f80; u8 pad84[0x4c]; u32 fD0; u8 padD4[0x68]; u8 f13C; } O154;
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad3C[0x104]; s16 f140; u8 pad142[0x2ee]; f32 f430; } P154;
extern O154 *func_003DA750(s32, s32, s32);
void func_00154650(P154 *p) {
    O154 *o;
    if ((o = func_003DA750(0, 0x13, 1)) != 0) {
        o->f13C = 1;
        o->f10 = func_00154400;
        o->fD0 = 0x800011;
        o->f34 = p->f34;
        o->f38 = p->f38;
        o->f3C = 0;
        o->f34 += (f32)(p->f140 ? -0x20 : 0x20);
        o->f38 = p->f430;
        o->f78 = 0x3F800000;
        o->f7C = 0x3F800000;
        o->f80 = 0x3F800000;
        o->f50 = 0x3F800000;
        o->f54 = 0x3F800000;
        o->f58 = 0;
    }
}

extern void func_003C3CE0(void *);
extern void func_003C3DA0(void *, s32);
extern void func_001E7F60();
extern s8 D_00475DB0[];
typedef struct { u8 pad0[0x4]; u8 f4; u8 f5; u8 pad6[0x16]; s16 f1C; s16 f1E; u8 pad20[0x14]; f32 f34; u8 pad38[0x108]; s16 f140; } P3C4;
void func_003C4090(P3C4 *p, s32 x) {
    s32 v;
    func_003C3CE0(p);
    func_003C3DA0(p, x);
    if (p->f1E != 0) {
        p->f1E = p->f1E - 1;
        func_001E7F60();
    }
    v = D_00475DB0[p->f1E];
    if (p->f140 != 0) v = (s8)-v;
    p->f34 += (f32)v;
    {
        s16 t = p->f1C;
        p->f1C = t - 1;
        if (t == 0) {
            u32 u = p->f4;
            p->f4 = u + 1;
            p->f5 = 0;
        }
    }
}

extern void func_0019B110(void *, s32);
extern void func_00354460(void *, s32);
extern void func_001E3210(void *, s32);
typedef struct { u8 pad0[0x6]; u8 f6; u8 f7; u8 pad8[0x14]; s16 f1C; s16 f1E; u8 pad20[0x3c]; f32 f5C; u8 pad60[0x157]; u8 f1B7; u8 pad1B8[0x2e]; u8 f1E6; u8 pad1E7[0x155]; u8 f33C; u8 pad33D[0xcf]; u8 f40C; } P31F;
void func_0031FBA0(P31F *p) {
    u32 t;
    p->f40C = 2;
    p->f33C = 5;
    t = p->f6;
    p->f6 = t + 1;
    p->f7 = 0;
    p->f1C = 0x11;
    p->f1E = 0;
    p->f1B7 = 0;
    *(u32 *)&p->f5C = 0xC1055555;
    if (p->f1E6 != 0) p->f5C = -p->f5C;
    func_0019B110(p, 5);
    func_00354460(p, 0);
    func_001E3210(p, 0x1F);
    func_001757E0(p, 0x16, 7);
}

extern void func_001D6B20(void *, void *);
typedef struct { u8 pad0[0x24]; s8 f24; u8 pad25[0xf]; f32 f34; f32 f38; f32 f3C; u8 pad40[0x129]; u8 f169; } Q1D6;
typedef struct { u8 pad0[0x4]; u8 f4; u8 pad5[0x1c]; u8 f21; u8 pad22[0x2]; s8 f24; u8 pad25[0xc]; s8 f31; u8 pad32[0x2]; f32 f34; f32 f38; f32 f3C; } P1D6;
void func_001D6430(P1D6 *p, Q1D6 *q) {
    p->f24 = q->f24 + p->f31;
    if (p->f24 > 7) p->f24 = 7;
    if (p->f24 < 0) p->f24 = 0;
    func_00175700(p);
    p->f34 = q->f34;
    p->f38 = q->f38;
    p->f3C = q->f3C;
    if (q->f169 != p->f21) {
        u32 t = p->f4;
        p->f4 = t + 1;
        func_001D6B20(p, q);
    }
}

extern void func_001830D0(void *, void *, s32);
extern void func_0036A8D0(void *, s32);
typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x14a]; s8 f151; u8 pad152[0x166]; s16 f2B8; u8 pad2BA[0x82]; u8 f33C; u8 pad33D[0xcf]; u8 f40C; } P25A;
typedef struct { f32 a; f32 b; } V25A;
void func_0025A260(P25A *p) {
    p->f40C = 2;
    p->f33C = 5;
    if (p->f151 == 1) {
        p->f151 = 0;
        if (p->f2B8 == 0) {
            u32 v[3];
            v[0] = 0xC1555555;
            v[1] = 0x432B6DB6;
            func_001830D0(p, &v, 1);
        }
    }
    if (p->f151 == 2) {
        u32 t;
        p->f151 = 0;
        t = p->f6;
        p->f6 = t + 1;
        func_0036A8D0(p, 0);
    }
    func_00175700(p);
}

extern void func_0036A9B0(void *, s32);
typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x14a]; s8 f151; } P259;
static void func_002555E0(void *arg, s32 a, s32 b, void *q) {
    u8 *p = arg;
    if (*(s16 *)(p + 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}
void func_00259C60(P259 *p, s32 a1, s32 a2) {
    s16 *q = (s16 *)((u8 *)p + 0x2B8);
    func_002555E0(p, a1, a2, q);
    if (p->f151 == 1) {
        u32 v[3];
        p->f151 = 0;
        v[0] = 0;
        v[1] = 0x432B6DB6;
        if (*q == 0) func_001830D0(p, v, 1);
        else func_001830D0(p, v, 0);
    }
    if (p->f151 == 2) {
        u32 t = p->f6;
        p->f6 = t + 1;
        p->f151 = 0;
        func_0036A9B0(p, 7);
    }
    func_00175700(p);
}

typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x15]; s16 f1C; u8 pad1E[0x133]; s8 f151; u8 pad152[0x117]; u8 f269; u8 pad26A[0xd2]; u8 f33C; u8 pad33D[0xc7]; u8 f404; u8 f405; u8 pad406[0x6]; u8 f40C; } P323;
void func_00323C80(P323 *p) {
    u32 v[3];
    u32 t;
    p->f40C = 2;
    p->f33C = 5;
    p->f405 = (p->f269 == 6) ? 2 : 0;
    func_00175700(p);
    if (p->f151 != 0) {
        p->f404 = 0;
        p->f405 = 0;
        t = p->f6; p->f6 = t + 1; p->f151 = 0; p->f1C = 0xF0; v[1] = 0x425EDB6D; v[0] = 0;
        func_001830D0(p, v, 1);
    }
}
