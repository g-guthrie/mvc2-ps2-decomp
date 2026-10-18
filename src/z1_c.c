typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00299CA0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00183920(u8 *, u32 *);
    u32 v[4];
    f32 k;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        v[0] = 0x42195555;
        v[1] = 0x434B9249;
        func_00183920(p, v);
    }
    if (*(s8 *)(p + 0x150) != 0) {
        if (p[0x1E6] != 0) k = 3.3333332538604736f; else k = -3.3333332538604736f;
        *(f32 *)(p + 0x34) += k;
    }
}

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34, f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60, f64, f68, f6c;
} T235;

void func_00235A00(T235 *p) {
    extern s8 func_00175700(T235 *);
    extern void func_001757E0(T235 *, s32, s32, s32);
    f32 z = 0.0f;
    f32 *a, *b;
    p->f34 += p->f5c;
    a = &p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    b = &p->f68;
    if (!(p->f5c * p->f68 < z)) *a = z;
    *(u32 *)b = 0;
    if (func_00175700(p) < 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        *(u32 *)&p->f60 = 0xC14DB6DB;
        *(u32 *)&p->f6c = 0xBFCDB6DB;
        func_001757E0(p, 0x15, 4, t + 1);
    }
}
