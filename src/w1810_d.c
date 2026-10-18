typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[6]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x16]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x144]; u8 b1b4; u8 p1b5[0x31]; u8 b1e6; } P20;
void func_0020F770(P20 *p) {
    extern void func_00175700(P20 *);
    extern void func_0015D010(P20 *, f32 *);
    extern void func_001757E0(P20 *, s32, s32);
    f32 v[3];
    s16 t;
    f32 c;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    t = p->h1c - 1;
    p->h1c = t;
    if (t == 0) {
        p->b6++;
        if (p->b1e6 != 0) c = 6.666666507720947f; else c = -6.666666507720947f;
        p->f5c = c;
        p->f68 = 0.0f;
        p->f60 = 6.4285712242126465f;
        p->f6c = -0.8035714030265808f;
        p->b1b4 = 10;
        v[0] = 20.0f;
        v[1] = 115.71427917480469f;
        v[2] = 0.0f;
        func_0015D010(p, v);
        func_001757E0(p, 15, 1);
    }
}
