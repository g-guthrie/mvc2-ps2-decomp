typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004CBE80[];
extern u32 D_004CBE84[];
extern u32 D_004CBE88[];
extern f32 D_004CBE8C[];
extern f32 D_004CBE90[];
extern s32 D_004C2720;

void func_001E5070(s32 a, s32 b, s32 c, f32 f) {
    extern s32 func_00422FB0(s32);
    s32 t;
    s32 r;
    s32 o;
    t = D_004C2720;
    o = t * 20;
    if (D_004CBE80[o] != 0) {
        if (D_004CBE80[o] >= 4) {
            r = func_00422FB0((t & 0x7F) | (((D_004CBE84[t * 5] & 0x7F) << 16) | ((D_004CBE88[t * 5] & 0x7F) << 8)));
        } else {
            r = func_00422FB0(((D_004CBE84[t * 5] & 0x7F) << 16) | ((D_004CBE88[t * 5] & 0x7F) << 8) | 1);
        }
        if (r < 0) {
            D_004C2720 = D_004C2720 + 1;
            if (D_004C2720 >= 36) D_004C2720 = 0;
            return;
        }
    }
    t = D_004C2720;
    D_004CBE80[t * 20] = 3;
    D_004CBE84[t * 5] = (u8)a;
    D_004CBE88[t * 5] = (u8)b;
    D_004CBE8C[t * 5] = (f32)c;
    D_004CBE90[t * 5] = f;
    D_004C2720 = D_004C2720 + 1;
    if (D_004C2720 >= 36) D_004C2720 = 0;
}

typedef struct {
    u8 b0, b1, b2, b3, b4, b5;
    u8 pad6[0x16];
    s16 h1C;
    s16 h1E;
    u8 pad20[0x14];
    f32 f34;
    f32 f38;
    u8 pad3C[0x20];
    f32 f5C;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6C;
    u8 pad70[0xEB];
    u8 b15B;
    u8 pad15C[0x56];
    s8 b1B2;
    s8 b1B3;
    s8 b1B4;
    u8 b1B5;
    u8 pad1B6[0xA];
    u16 h1C0;
    u8 pad1C2[0x16];
    s32 w1D8;
} K1;
typedef struct {
    u8 pad[0x7C];
    s16 f7C[1];
} G1;
extern G1 *D_004C2794;

void func_003CBC70(K1 *p, u8 *q) {
    extern s32 func_00174780();
    extern s32 func_00174470(K1 *);
    extern void func_003CAB20(K1 *, u8 *, s32);
    extern void func_003CAB00(K1 *, u8 *);
    extern void func_001E3210(K1 *, s32);
    extern void func_00175700(K1 *);
    extern void func_001E7F60(K1 *);
    s16 t;
    s16 t2;
    s32 w;
    if (q[5] != 0) {
        func_003CAB20(p, q, 5);
        return;
    }
    if (func_00174780() == 0 || func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    *(s32 *)(q + 0x2B8) = 4;
    if (p->b1B2 & 0x11) {
        func_003CAB20(p, q, 0xD);
        return;
    }
    if (p->b1B3 != 0) {
        func_001E3210(p, 0x34);
        func_003CAB20(p, q, 9);
        return;
    }
    t = p->h1C - 1;
    p->h1C = t;
    if (t == 0) func_001E3210(p, p->b15B);
    if (p->b1B4 != 0) {
        p->b1B4 = p->b1B4 - 1;
    } else {
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        func_00175700(p);
        if (p->f60 > 0.0f) func_003CAB20(p, q, 5);
        if (p->b1B2 != 0) {
            t2 = p->h1E - 1;
            p->h1E = t2;
            if (t2 > 0) {
                p->b1B5 = 0x50;
                p->b1B2 = p->h1C0 = 0;
                p->w1D8 = 0;
                D_004C2794->f7C[p->b2]++;
            }
        }
    }
    func_001E7F60(p);
}
