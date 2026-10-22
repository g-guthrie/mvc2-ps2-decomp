typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; u8 p152[0x94]; u8 b1e6; } S_002BB1E0;

void func_002BB1E0(S_002BB1E0 *p) {
    extern s32 func_00175700();
    s32 *a;
    s32 *b;
    if (p->b151 == 0) func_00175700();
    a = (s32 *)&p->f5c;
    b = (s32 *)&p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if ((p->b1e6 == 0 && p->f5c < 0.0f) || (p->b1e6 != 0 && p->f5c > 0.0f)) return;
    {
        u32 t = p->b6;
        p->b6 = t + 1;
        *a = 0;
        *b = 0;
    }
}

typedef struct { u8 p0[6]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x16]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; u8 p152[0x2D3]; u8 b425; } S_00259320;

void func_00259320(S_00259320 *p) {
    extern void func_001AFCB0(S_00259320 *, s32);
    extern void func_00175700(S_00259320 *);
    s32 v;
    func_00175700(p);
    v = p->b151;
    if (v == 1) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_00259320(p);
        return;
    }
    if (p->b425 == 0 && v == 2) {
        func_001AFCB0(p, 1);
        p->h1c = p->h1c + 1;
        p->b151 = 0;
    }
    if (p->f5c * p->f68 < 0.0f) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
}
