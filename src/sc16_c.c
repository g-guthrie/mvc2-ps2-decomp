typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[6]; u8 b6; u8 b7; u8 p1[0x2C]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0x142]; s8 b1B2; u8 p6[4]; u8 b1B7; u8 p7[0x55]; u8 b20D; u8 p5[0x222]; f32 f430;} A_00235AE0;

void func_00235AE0(A_00235AE0 *p)
{
    extern void func_00175700(A_00235AE0 *);
    extern void func_001757E0(A_00235AE0 *, s32, s32);
    extern void func_00183d50(A_00235AE0 *);
    f32 *v1, *a3, *t0, *t1;
    s32 v;
    v1 = &p->f5c; t0 = &p->f68; a3 = &p->f60; t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f38 < p->f430) {
        p->b6++;
        p->b7 = 0;
        p->f38 = p->f430;
        p->b20D = 0;
        *(s32*)v1 = 0; *(s32*)a3 = 0; *(s32*)t0 = 0; *(s32*)t1 = 0;
        if ((p->b1B2 & 1) != 0 || p->b1B7 == 1) v = 6; else v = 5;
        func_001757E0(p, 0x15, (u8)v);
        func_00183d50(p);
    }
}
