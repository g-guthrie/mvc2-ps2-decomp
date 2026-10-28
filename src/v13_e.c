typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001CFEA0(u8 *p) {
    extern s16 D_0044DEF0[], D_0044DEF2[];
    f32 x;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    x = 1.66666663f * (f32)D_0044DEF0[p[0x20] * 2];
    if (*(s16 *)(p + 0x140) != 0) x = -x;
    *(f32 *)(p + 0x34) += x;
    *(f32 *)(p + 0x38) += (f32)D_0044DEF2[p[0x20] * 2];
    if (*(s16 *)(p + 0x1C) != 0) *(f32 *)(p + 0x38) -= 34.2857132f;
}

typedef struct FB {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad1[0x1C - 8];
    s16 h1c;
    s16 h1e;
    u8 pad1b[0x34 - 0x20];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad4[0x1E6 - 0x70];
    u8 b1e6;
    u8 pad5[0x1FE - 0x1E7];
    u8 b1fe;
    u8 pad6[2];
    u8 b201;
    u8 pad7[7];
    u8 b209;
} FB;

void func_002BD720(FB *p) {
    s16 v;
    p->b1fe = 1;
    p->b201 = 2;
    p->b209 = 2;
    v = p->h1e - 1;
    p->h1e = v;
    if (v == 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f5c = (p->b1e6 != 0) ? 3.33333325f : -3.33333325f;
        p->f60 = -17.1428566f;
        p->f6c = -2.14285707f;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
}

typedef struct Q430 { u8 pad[0x430]; f32 f430; } Q430;
typedef struct FC {
    u8 pad0[5];
    u8 b5;
    u8 pad1[0x18 - 6];
    Q430 *q;
    u8 pad1b[0x38 - 0x1C];
    f32 f38;
    u8 pad2[0x60 - 0x3C];
    f32 f60;
    u8 pad3[0x6C - 0x64];
    f32 f6c;
    u8 pad4[0x118 - 0x70];
    f32 f118;
} FC;

void func_001AF770(FC *p) {
    extern int func_00175670(u8 *);
    extern void func_001AFC90();
    if (p->b5 == 0) {
        func_00175670((u8 *)p);
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (p->f38 <= p->q->f430) {
            u32 t = p->b5;
            p->b5 = t + 1;
            p->f38 = p->q->f430;
            *(f32 *)&p->f118 = 1.0f;
        }
    } else {
        f32 z = 0.0f;
        p->f118 -= 0.0500000007f;
        if (p->f118 <= z) func_001AFC90(p);
    }
}

typedef struct FD {
    u8 pad0[6];
    u8 b6;
    u8 pad1[0x1C - 7];
    s16 h1c;
    u8 pad1b[0x20 - 0x1E];
    u8 b20;
    u8 b21;
    u8 pad1c[0x38 - 0x22];
    f32 f38;
    u8 pad2[0x151 - 0x3C];
    s8 b151;
} FD;

void func_002C23F0(FD *p) {
    extern int func_00175700(u8 *);
    s16 v;
    func_00175700((u8 *)p);
    if (p->b151 != 0) {
        if (p->b20 == 0) {
            u32 t = p->b6;
            p->b6 = t + 1;
            p->h1c = 6;
            p->b21 = 0;
        }
        if (p->b21 == 0) {
            p->f38 += 2.14285707f;
        } else {
            p->f38 -= 2.14285707f;
        }
        v = p->h1c - 1;
        p->h1c = v;
        if (v == 0) {
            p->h1c = 6;
            *(s8 *)&p->b21 = *(s8 *)&p->b21 ^ 1;
        }
    }
}

typedef struct FE {
    u8 pad0[7];
    u8 b7;
    u8 pad1[0x5C - 8];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad3b[0x151 - 0x70];
    s8 b151;
    u8 pad4[0x1E6 - 0x152];
    u8 b1e6;
    u8 pad5[0x1FE - 0x1E7];
    u8 b1fe;
    u8 pad6[2];
    u8 b201;
    u8 pad7[2];
    u8 b204;
    u8 pad8;
    u8 b206;
    u8 pad9[2];
    u8 b209;
} FE;

void func_001F1340(FE *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    p->b1fe = 1;
    p->b201 = 2;
    p->b209 = 2;
    p->b206 = 3;
    if (p->b151 != 0) p->b151 = 0;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->f5c = 5.0f;
        p->f68 = -0.104166664f;
        p->f60 = 17.1428566f;
        p->f6c = -0.669642806f;
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001757E0(p, 0xF, 0xE);
    }
}

void func_001C3830(u8 *p, u8 *q) {
    extern f32 D_004F1FD0;
    extern void func_001757E0();
    u8 *a2 = q + 0x2B8;
    if (q[0x2C3] == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        a2[0xB] = 0;
        p[0] = 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        if (*(s16 *)(q + 0x140) == 0) {
            *(f32 *)(p + 0x34) = 80.0f + *(f32 *)(q + 0x34);
        } else {
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 80.0f;
        }
        *(f32 *)(p + 0x38) = 34.2857132f + D_004F1FD0;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x60) = -17.1428566f;
        *(f32 *)(p + 0x6C) = -0.803571403f;
        func_001757E0(p, 0x19, 0xC);
    }
}

typedef struct FF {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad1[0x1C - 8];
    s16 h1c;
    u8 pad1b[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad4[0x20B - 0x70];
    u8 b20b;
} FF;

void func_001F00E0(FF *p) {
    extern int func_00175700(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_00185640(u8 *, u8 *);
    extern void func_001757E0();
    u8 *r;
    s16 v;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700((u8 *)p);
    if ((r = func_001E7FD0((u8 *)p)) != 0) {
        p->b7 = 0;
        p->b6 = 0;
        p->b20b = 7;
        func_00185640((u8 *)p, r);
    } else {
        v = p->h1c - 1;
        p->h1c = v;
        if (v == 0) {
            u32 t = p->b6;
            p->b6 = t + 1;
            func_001757E0(p, 0xF, 5);
        }
    }
}



void func_00364060(u8 *a0, u8 *a1) {
    extern void func_00364270();
    extern void func_001757E0();
    extern void func_00185870();
    extern void func_00182C30();
    u8 *s0 = *(u8 **)(a0 + 0x1C4);
    func_00364270(a0);
    if (*(s8 *)(s0 + 0x1B4) == 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
        func_001757E0(s0, 0xE, 0);
        func_00185870(a0, s0);
        *(u32 *)(a0 + 0xD4) = *(u32 *)(a1 + 0x1DC);
        *(s16 *)(a0 + 0x1C) = 0xB4;
        func_00182C30(*(u32 *)(a1 + 0x1DC), 1);
        s0[0x20A] = 6;
        a1[0x20B] = 0xC3;
        s0[0x20B] = 0xC3;
        a1[0x1FE] = 1;
        *(s8 *)(a1 + 0x16A) = -1;
        if (s0[0x20D] == 2) {
            *(u32 *)(s0 + 0x6C) = 0;
            *(u32 *)(s0 + 0x60) = 0;
            *(u32 *)(s0 + 0x68) = 0;
            *(u32 *)(s0 + 0x5C) = 0;
        }
    }
}

typedef struct FI {
    u8 pad0[0x34];
    f32 f34;
    u8 pad1[0x1E4 - 0x38];
    u8 b1e4;
    u8 pad1b[1];
    u8 b1e6;
    u8 b1e7;
    u8 pad2[0x20E - 0x1E8];
    s16 h20e;
    u8 pad3[0x211 - 0x210];
    s8 b211;
    u8 pad4[0x451 - 0x212];
    u8 b451;
    u8 pad5[0x460 - 0x452];
    f32 f460;
    f32 f464;
    s32 w468;
    s16 h46c;
    u8 pad6[0x4F0 - 0x46E];
    s16 h4f0;
} FI;

s32 func_001640A0(FI *p) {
    extern u8 D_004D18EC;
    f32 z = 0.0f;
    f32 d;
    if (p->b1e4 == p->w468 && D_004D18EC == 0) {
        s32 a1 = p->b211;
        if (a1 == 0 || (a1 & (2 >> p->b1e6)) == 0) {
            d = p->f34 - p->f464;
            if (d < z) d = -d;
            p->f460 = p->f460 - d;
            if (p->f460 > z) {
                p->f464 = p->f34;
                p->h4f0 = p->h46c;
                if (p->w468 == 0x1A) p->h20e = p->h46c;
                p->b1e7 = 0;
                return 0;
            }
        }
    }
    {
        u32 t = p->b451;
        p->b451 = t - 1;
        p->h4f0 = 0;
    }
    return 1;
}
