typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_002BB860(u8 *p) {
    extern void func_002BA590();
    extern void func_00175700();
    extern void func_00186A20();
    u32 t;
    f32 f;
    if (*(s8 *)(p + 0x1B2) != 0) {
        t = p[6];
        p[6] = t + 1;
        func_002BA590(p);
        return;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
        if (p[0x1E6] != 0) {
            f = 33.33333206176758f;
        } else {
            f = -33.33333206176758f;
        }
        *(f32 *)(p + 0x5C) = f;
        if (p[0x1E6] != 0) {
            f = -2.0833332538604736f;
        } else {
            f = 2.0833332538604736f;
        }
        *(f32 *)(p + 0x68) = f;
        *(u32 *)(p + 0x60) = 0x422B6DB6;
        *(u32 *)(p + 0x6C) = 0xBFAB6DB6;
    }
}

typedef struct { u8 pad00[0x1C]; s16 h1c; u8 pad0[0x14]; f32 f34; u8 pad1[0x18]; f32 f50; f32 f54; u8 pad2[4]; f32 f5c; u8 pad3[8]; f32 f68; u8 pad4[0xAC]; f32 f118; } S37_n;
void func_0037D0D0(S37_n *p, u8 *q) {
    extern void func_0037CF30();
    extern void func_00175700();
    s16 v;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f50 += 0.07142857462167740f;
    p->f54 += 0.07142857462167740f;
    if (((u8 *)p)[1] != q[1]) {
        func_0037CF30(p, q);
        return;
    }
    v = p->h1c - 1;
    p->h1c = v;
    if (v < 0) {
        *(s32 *)&p->f118 = 0;
        ((u8 *)p)[4] = 2;
        ((u8 *)p)[0x13C] = 0;
        return;
    }
    if (p->h1c < 7) {
        p->f118 -= 0.14285714924335480f;
    }
    func_00175700(p);
}

typedef struct { u8 pad6[0x6]; u8 b6; u8 pad34[0x2D]; f32 f34; f32 f38; u8 pad5C[0x20]; f32 f5c; f32 f60; u8 pad68[0x4]; f32 f68; f32 f6c; u8 pad1E6[0x176]; u8 b1e6; u8 pad209[0x22]; u8 b209; u8 pad211[0x7]; s8 b211; } S14_r;
void func_002ADEA0(S14_r *p) {
    extern void func_00185490();
    extern void func_002ADE20();
    extern double func_00119058(f32);
    extern void func_00175700();
    extern void func_001757E0();
    u32 t;
    func_00185490();
    func_002ADE20(p);
    p->b209 = 2;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_00119058(p->f68 * p->f5c) < 0.0) {
        if ((p->b211 & (1 << (p->b1e6 ^ 1))) == 0) {
            func_00175700(p);
            return;
        }
    }
    t = p->b6;
    p->b6 = t + 1;
    func_001757E0(p, 0x15, 0x2C);
}

typedef struct { u8 pad4[0x4]; u8 b4; u8 b5; u8 pad1C[0x16]; s16 h1c; u8 pad34[0x16]; f32 f34; f32 f38; u8 pad5C[0x20]; f32 f5c; u32 w60; f32 f64; u8 pad1E0[0x178]; u8 *p1e0; } S16_t;
typedef struct { u8 pad34[0x34]; f32 f34; f32 f38; u8 pad1B5[0x179]; u8 b1b5; u8 pad1E0[0x2A]; u8 *p1e0; u8 pad1FE[0x1A]; u8 b1fe; u8 pad20A[0xB]; u8 b20a; } S16b_t;
void func_003772A0(S16_t *p, u8 *q) {
    extern void func_00377860();
    extern void func_00175700();
    extern void func_001757E0();
    S16b_t *s0 = (S16b_t *)p->p1e0;
    if (((S16_t *)s0->p1e0) != p) {
        p->b4 = 2;
        p->b5 = 4;
        func_00377860(p);
        return;
    }
    p->h1c = p->h1c - 1;
    if (p->h1c <= 0) {
        p->b4 = 2;
        p->b5 = 1;
        s0->b20a = 1;
        s0->b1b5 = 0x30;
        p->f5c = -p->f5c / 2.0f;
        p->w60 = 0x40892492;
        func_001757E0(p, 0x17, 0xD);
    } else {
        q[0x1FE] = 1;
        func_00175700(p);
        p->f34 = s0->f34 + p->f64;
        p->f38 = s0->f38 + *(f32 *)&p->w60;
    }
}

typedef struct { u8 pad6[0x6]; u8 b6; u8 pad5C[0x55]; u32 w5c; u32 w60; u8 pad68[0x4]; u32 w68; u32 w6c; u8 pad1DC[0x16C]; u8 *p1dc; u8 pad1E6[0x6]; u8 b1e6; } S17_u;
typedef struct { u8 pad1B5[0x1B5]; u8 b1b5; u8 pad1C8[0x12]; u8 *p1c8; u8 pad20A[0x3E]; u8 b20a; u8 pad20D[0x2]; u8 b20d; } S17b_u;
void func_0020FFB0(S17_u *p) {
    extern s32 func_00175700();
    extern void func_001266A0();
    extern void func_001757E0();
    u32 t;
    f32 f;
    S17b_u *q;
    if ((s8)func_00175700(p) < 0) {
        t = p->b6;
        p->b6 = t + 1;
        q = (S17b_u *)p->p1dc;
        q->p1c8 = (u8 *)p;
        q->b20a = 1;
        q->b20d = 2;
        q->b1b5 = 0x23;
        func_001266A0(p, 0, 0);
        p->w5c = 0;
        p->w60 = 0;
        p->w68 = 0;
        p->w6c = 0;
        if (p->b1e6 != 0) {
            f = 13.333333015441895f;
        } else {
            f = -13.333333015441895f;
        }
        *(f32 *)&p->w5c = f;
        if (p->b1e6 != 0) {
            f = 0.2083333283662796f;
        } else {
            f = -0.2083333283662796f;
        }
        *(f32 *)&p->w68 = f;
        func_001757E0(p, 0xF, 8);
    }
}

typedef struct { u8 pad6[0x6]; u8 b6; u8 pad34[0x2D]; f32 f34; f32 f38; f32 f3c; u8 pad60[0x20]; f32 f60; u8 pad6C[0x8]; f32 f6c; u8 pad1E6[0x176]; u8 b1e6; u8 pad20D[0x26]; u8 b20d; u8 pad430[0x222]; f32 f430; } S19_w;
typedef struct { f32 x, y, z; } V3_w;
extern u8 D_004F1F45, D_004F1F46;
void func_0020FEC0(S19_w *p) {
    extern void func_00175700();
    extern void func_00158C70();
    extern void func_001E3A40();
    extern void func_001757E0();
    u32 t;
    V3_w v;
    func_00175700();
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20d = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        v = *(V3_w *)&p->f34;
        v.x += (f32)((p->b1e6 != 0) ? -8 : 8);
        func_00158C70(&v, -1);
        func_001E3A40(p);
        func_001757E0(p, 0xF, 7);
    }
}

