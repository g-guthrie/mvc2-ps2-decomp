typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct S215 S215;
typedef struct T215 {
    u8 pad0[0x1B5];
    u8 b1B5;
    u8 pad1B6[0x1C8 - 0x1B6];
    S215 *w1C8;
    u8 pad1CC[0x1E6 - 0x1CC];
    u8 b1E6;
    u8 pad1E7[0x20A - 0x1E7];
    u8 b20A;
} T215;
struct S215 {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 h1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34, f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60, f64, f68, f6c;
    u8 pad70[0x1B5 - 0x70];
    u8 pad1B5[0x1DC - 0x1B5];
    T215 *t1DC;
    u8 pad1E0[0x1E6 - 0x1E0];
    u8 b1E6;
    u8 pad1E7[0x2B8 - 0x1E7];
    u8 b2B8, b2B9;
    s16 h2BA;
    u8 b2BC;
    u8 pad2BD[0x430 - 0x2BD];
    f32 f430;
};

void func_00215550(S215 *p) {
    extern void func_00175700(S215 *);
    extern void func_00352670(S215 *, s32, s32, s32);
    T215 *t;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < 274.28570556640625f + p->f430) {
        u32 n = p->b6;
        p->b6 = n + 1;
        p->h1C = 10;
        *(u32 *)&p->f6c = 0x3F092492;
        func_00175700(p);
        t = p->t1DC;
        t->w1C8 = p;
        t->b20A = 1;
        t->b1E6 = p->b1E6;
        t->b1B5 = 0x24;
        p->b2B8 = 8;
        p->b2B9 = 0x40;
        p->h2BA = 5;
        p->b2BC = 0xFF;
        func_00352670(p, 1, 0, 0);
    }
}
