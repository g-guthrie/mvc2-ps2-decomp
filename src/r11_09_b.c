typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct RC6B_K { u8 pad0[0x211]; s8 b211; u8 pad212[0x434 - 0x212]; s16 h434; } RC6B_K;
typedef struct RC6B_Q { f32 f0; f32 f4; f32 f8; f32 fC; u8 pad10[8]; s16 h18; } RC6B_Q;
typedef struct RC6B_N {
    u8 pad0[5]; u8 b5; u8 pad6[6]; struct RC6B_N *w0C;
    u8 pad10[0x10]; u8 b20; u8 b21; u8 b22; u8 pad23[0x34 - 0x23];
    f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C]; f32 f5C; f32 f60;
    u8 pad64[0x88 - 0x64]; RC6B_Q q;
    u8 padA4[0x140 - 0xA4]; s16 h140; u8 pad142[0x151 - 0x142]; s8 b151;
    u8 pad152[0x1B7 - 0x152]; u8 b1B7; u8 pad1B8[0x1DC - 0x1B8]; RC6B_K *w1DC;
} RC6B_N;
typedef struct RC6B_T { s16 x; s16 y; } RC6B_T;

extern RC6B_T D_00473E70[];
extern s16 D_00473FF0[];
extern s16 D_00474070[];

/* MW 3.0 (try30.sh) -O3 -Op -fp off -sdatathreshold 8: the native (s32) casts lower to jal fptosi. */
s32 func_003B56B0(RC6B_N *a, RC6B_N *b) {
    extern void func_00178F20(RC6B_N *, RC6B_K *);
    extern void func_00175700(RC6B_N *);
    extern void func_00175910(RC6B_N *, s32, u8, s8);
    RC6B_Q *q;
    RC6B_N *src;
    RC6B_K *k;
    f32 d, f20, x, y;
    s32 i, s1, dv;
    s16 qt;
    q = &a->q;
    d = a->f34 - (b->f34 + q->f8);
    if (b->h140 == 0) d = -d;
    if (d < 0.0f) return 0;
    f20 = 1.6666666269302368f * (f32)*(volatile s16 *)&D_00473E70[b->b1B7].x / 256.0f;
    s1 = (s16)(s32)(d / 1.6666666269302368f);
    dv = (s16)(s32)(f20 / 1.6666666269302368f);
    qt = s1 / dv;
    q->h18 = qt;
    if (b->b1B7 == 0) {
        a->f38 = q->fC + (b->f38 + ((f32)qt * (2.142857074737549f * (f32)D_00473E70[b->b1B7].y / 256.0f)
              + 2.142857074737549f * (f32)D_00473FF0[(s16)(s1 % dv) & 0x3F] / 256.0f));
    } else if ((u8)b->b1B7 == 2) {
        f32 t, u;
        t = 2.142857074737549f * (f32)D_00474070[(s16)(s1 % dv) & 0x3F] / 256.0f;
        u = (f32)qt * (2.142857074737549f * (f32)D_00473E70[b->b1B7].y / 256.0f);
        a->f38 = q->fC + (b->f38 + (t + u));
    }
    if (a->b22 == 1 && a->b20 == 0 && a->b5 <= 0) {
        k = b->w1DC;
        if (k->b211 == 0 && k != 0 && k->h434 != 0) func_00178F20(a, k);
    }
    a = a->w0C;
    src = a;
    x = b->f34 + a->q.f8;
    y = b->f38 + a->q.fC;
    a->f34 = x;
    a->f38 = y;
    func_00175700(a);
    if (q->h18 - 1 < 0) return 0;
    i = 0;
    while (i < q->h18) {
        a = a->w0C;
        if (a == 0) return 0;
        x += src->f5C;
        a->f34 = x;
        y += src->f60;
        a->f38 = y;
        if (src->b151 != a->b151) func_00175910(a, 0x15, a->b21, src->b151);
        i++;
    }
    return 0;
}
