typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x34]; f32 f34, f38; } Sc;
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern f32 D_004F1FD0[];

void residual_003646E0(u8 *p, s32 a1)
{
    extern s32 func_00364E20(u8 *, f32);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_0015E630(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_003648A0(u8 *, s32);
    Sc *P = (Sc *)p;
    Sc *q;
    f32 t;
    f32 a;
    s32 r;
    p[5]++;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x18;
    p[0x14F] = 0x18;
    *(s16 *)(p + 0x140) = 0;
    p[0x24] = 8;
    *(s8 *)(p + 0x31) = -2;
    if (p[0x23] == 0) {
        P->f34 = 53.33333206176758f + D_004F1FCC[0];
    } else {
        P->f34 = D_004F1FC8[0] - 53.33333206176758f;
    }
    P->f38 = D_004F1FD0[0] - 137.14285278320312f;
    q = *(Sc **)(p + 0x14);
    if (p[0x23] == 0) {
        t = (26.66666603088379f + q->f34) - P->f34;
    } else {
        t = (q->f34 - 26.66666603088379f) - P->f34;
    }
    a = -34.28571319580078f + q->f38;
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    r = func_00364E20(p, a);
    *(f32 *)(p + 0x5C) = t / (f32)r;
    *(u32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1C) = r;
    func_001757E0(p, 0x17, p[0x23] + 0x47);
    p[0] = 1;
    func_0015E630(p);
    if (p[0x23] == 0) {
        func_001E3210(p, 0x1B);
    }
    func_003648A0(p, a1);
}
