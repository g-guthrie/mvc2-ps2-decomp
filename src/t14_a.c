typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x38]; f32 f38; u8 p1[0x24]; f32 f60; u8 p2[8]; f32 f6c; } S_00364E20;

s32 func_00364E20(S_00364E20 *p, f32 lim) {
    s32 n = 0;
    f32 z = 0.0f;
    f32 x = p->f38;
    f32 v = p->f60;
    do {
        x += v;
        v += p->f6c;
        n++;
    } while (v > z || x > lim);
    return n;
}

extern u8 *func_001E7FD0(u8 *);
typedef struct { u8 p0[0x22]; u8 b22; u8 p1[0x1B7-0x23]; u8 b1B7; u8 p2[0x20B-0x1B8]; u8 b20B; u8 p3[2]; u16 h20E; u8 p4[2]; u8 b212; } S_0025B4C0;
u8 *func_0025B4C0(u8 *actor) {
    S_0025B4C0 *p = (S_0025B4C0 *)actor;
    s32 b = (p->h20E & 0xC00) >> 10;
    p->b22 = b;
    if ((u8)b != 0) {
        if (p->b212 == 1 && p->b1B7 == 1) {
            u8 *r = func_001E7FD0(actor);
            if (r != 0) { p->b20B = 2; return r; }
        }
    }
    return 0;
}

extern u8 D_004D18A0;
extern s16 D_004D18EE[];
typedef struct { u8 p0[2]; u8 b2; u8 p1[2]; u8 b5; u8 p2[0x16]; s16 h1C; u8 p3[0x2]; u8 b20; u8 p4[0x11D]; s16 h13E; s16 h140; u8 p5[0x136]; s16 h278; } S_001341B0;
s32 func_001341B0(S_001341B0 *p, S_001341B0 *q) {
    s32 v;
    if (D_004D18A0 != 4) return 1;
    v = D_004D18EE[p->b2];
    if (v < 2) return 1;
    p->h13E = v;
    p->h140 |= q->h278;
    p->b5 = 0;
    p->h1C = 0;
    p->b20 = 2;
    return 0;
}

extern s8 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[6]; u8 b6; u8 p1[0x15]; s16 h1C; u8 p2[0x16]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c; } S_002DA090;
void func_002DA090(S_002DA090 *p) {
    s16 h;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    h = p->h1C - 1;
    p->h1C = h;
    if (h < 0) {
        { u32 t = p->b6; p->b6 = t + 1; }
        func_001757E0(p, 2, 2);
    }
}

extern f32 D_0044BAF0[];
extern f32 D_0044BAF4[];
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x11F]; u8 b15B; } Q_001AF4A0;
typedef struct { u8 p0[0x14]; Q_001AF4A0 *q14; u8 p1[9]; u8 b21; u8 p2[0x12]; f32 f34; f32 f38; u8 p3[0x104]; s16 h140; } S_001AF4A0;
void func_001AF4A0(S_001AF4A0 *p) {
    f32 f;
    p->f34 = p->q14->f34;
    p->f38 = p->q14->f38;
    f = *(f32 *)((u8 *)D_0044BAF0 + ((p->b21 + p->q14->b15B * 3) << 3));
    p->f34 += (p->h140 != 0) ? f : -f;
    p->f38 += *(f32 *)((u8 *)D_0044BAF4 + ((p->b21 + p->q14->b15B * 3) << 3));
}

extern s8 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[0x430]; f32 f430; } Q_00392E50;
typedef struct { u8 p0[5]; u8 b5; u8 p1[0x12]; Q_00392E50 *q18; u8 p2[0x18]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c; } S_00392E50;
void func_00392E50(S_00392E50 *p) {
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->q18->f430) {
        u32 t = p->b5;
        p->b5 = t + 1;
        p->f38 = p->q18->f430;
        func_001757E0(p, 0x17, 8);
    }
}

extern s8 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[6]; u8 b6; u8 p1[0x15]; s16 h1C; u8 p2[0x16]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c; } S_003260E0;
void func_003260E0(S_003260E0 *p) {
    f32 z = 0.0f;
    s16 h;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    h = p->h1C - 1;
    p->h1C = h;
    if (p->f60 < z) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_001757E0(p, 0xF, 1);
    }
}

typedef struct { f32 x, y, z; } V3_00146CD0;
typedef struct { f32 x, y, z, w; } V4_00146CD0;
extern V3_00146CD0 D_00442890;
extern V4_00146CD0 D_004428A0;
extern void D_00147560();
extern u8 *func_003DA750(s32, s32, s32);
typedef struct { u8 p0[0x10]; void *w10; u8 p1[0xC]; u8 b20; u8 p2[2]; u8 b23; u8 p3[0x2C]; V3_00146CD0 v50; u8 p4[0x18]; V4_00146CD0 v74; u8 p5[0x4C]; s32 wD0; u8 p6[0x68]; u8 b13C; } S_00146CD0;
void func_00146CD0(s32 a, s32 b) {
    S_00146CD0 *o;
    if ((o = (S_00146CD0 *)func_003DA750(0, 0xD, 0)) != 0) {
        o->b13C = 0;
        o->w10 = (void *)D_00147560;
        o->b23 = a;
        o->b20 = b;
        o->v50 = D_00442890;
        o->v74 = D_004428A0;
        o->wD0 = 0x431;
    }
}

extern s8 func_00175700(void *);
extern f32 func_001AC390(void *, s32);
typedef struct { u8 p0[0x151]; s8 b151; } Q_001AB780;
typedef struct { u8 p0[7]; u8 b7; u8 p1[0x2C]; f32 f34; u8 p2[0x24]; f32 f5c; u8 p3[8]; f32 f68; u8 p4[0xD4]; s16 h140; } S_001AB780;
void func_001AB780(S_001AB780 *p, Q_001AB780 *q) {
    f32 r;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    r = func_001AC390(q, 0x38);
    if ((p->h140 == 0 && p->f34 <= r) || (p->h140 != 0 && !(p->f34 < r))) {
        p->b7 = 3;
        p->f34 = r;
    }
    if (q->b151 != 0) {
        p->b7 = 3;
        p->f34 = r;
    }
}

extern s8 func_00175700(void *);
extern s32 func_001864a0(void *);
extern void func_001F72E0(void *);
extern void func_001757E0(void *, s32, s32);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
typedef struct { u8 p0[7]; u8 b7; u8 p1[0x2C]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0x196]; u8 b206; } S_001F2A80;
void func_001F2A80(S_001F2A80 *p) {
    u32 t;
    p->b206 = 3;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (func_001864a0(p) != 0) {
        t = p->b7;
        p->b7 = t + 1;
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        func_001F72E0(p);
        func_001757E0(p, 0xF, 0x20);
    }
}

extern s8 func_00175700(void *);
extern void func_00390300(void *, u8);
extern void func_0029FA00(void *);
void func_0029FDB0(u8 *p) {
    u32 t;
    func_00175700(p);
    if ((*(s8 *)(p + 0x151) & 0x80) != 0) {
        t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) & 0x7F;
        *(u32 *)(p + 0x5C) = 0x3FD55555;
        *(u32 *)(p + 0x68) = 0xBCD55555;
        *(u32 *)(p + 0x60) = 0x40F00000;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_00390300(p, p[0x1B7] + 4);
    }
    func_0029FA00(p);
}

extern s8 func_00175700(void *);
extern s32 func_003657D0(void *, void *, s32);
extern void func_001757E0(void *, s32, s32);
extern void func_001E7F60(void *);
typedef struct { u8 p0[5]; u8 b5; u8 p1[0x12]; void *q18; u8 p2[0x18]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c; } S_00365330;
void func_00365330(S_00365330 *p) {
    u32 t;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (func_003657D0(p, p->q18, 0x60) == 0) {
        t = p->b5;
        p->b5 = t + 1;
        *(u32 *)&p->f60 = 0x41092492;
        *(u32 *)&p->f6c = 0xBF092492;
        func_001757E0(p, 0x17, 1);
    }
    func_001E7F60(p);
}

extern s8 func_00175700(void *);
extern void func_00362C20(void *, void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[0x34]; f32 f34; } Q_00362FB0;
typedef struct { u8 p0[6]; u8 b6; u8 p1[0x2D]; f32 f34; u8 p2[0x108]; s16 h140; } S_00362FB0;
void func_00362FB0(S_00362FB0 *p, Q_00362FB0 *q) {
    u8 flag = 0;
    f32 z = 0.0f;
    u32 t;
    if (func_00175700(p) < 0) {
        f32 d = p->f34 - q->f34;
        if (d < z) flag = 1;
        if (p->h140 == flag) {
            p->b6 = 6;
            func_00362C20(p, q);
            return;
        }
        t = p->b6;
        p->b6 = t + 1;
        p->h140 = flag;
        func_001757E0(p, 0x17, 0xE);
    }
}

extern s8 func_00175700(void *);
extern void func_00183d50(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[6]; u8 b6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0x19D]; u8 b20D; u8 p5[0x222]; f32 f430; } S_002538F0;
void func_002538F0(S_002538F0 *p) {
    f32 z = 0.0f;
    u32 t;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f60 <= z && p->f38 <= p->f430) {
        t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20D = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 5);
    }
}

extern void func_003DE720(f32 *, f32 *);
void func_003DDB70(f32 *m) {
    f32 a, b;
    f32 y, z;
    func_003DE720(&a, &b);
    y = m[1]; z = m[2];
    m[1] = b * y - a * z;
    m[2] = a * y + b * z;
    y = m[5]; z = m[6];
    m[5] = b * y - a * z;
    m[6] = a * y + b * z;
    y = m[9]; z = m[10];
    m[9] = b * y - a * z;
    m[10] = a * y + b * z;
}
