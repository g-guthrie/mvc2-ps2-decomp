typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 st;
    u8 pad8[0x34 - 8];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
    u8 pad70[0x151 - 0x70];
    s8 b151;
    u8 pad152[0x20D - 0x152];
    u8 b20d;
    u8 pad20e[0x430 - 0x20E];
    f32 f430;
} A;

void func_002DFB90(A *p)
{
    extern void func_00183D90(u8 *);
    extern int func_00175700(u8 *);
    extern void func_001757E0(A *, s32, s32);
    extern void func_00183d50(A *);
    extern void func_001843A0(A *);
    f32 *s1, *s2, *s3, *s4;
    f32 *u1, *u2, *u3, *u4;
    f32 z = 0.0f;

    switch (p->st) {
    case 0:
        s1 = &p->f5c;
        s3 = &p->f68;
        s2 = &p->f60;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        s4 = &p->f6c;
        if (p->f5c > z) func_00183D90((u8 *)p);
        func_00175700((u8 *)p);
        if (p->b151 != 0) {
            p->st = 2;
            p->b151 = 0;
            *s1 = 0; *s2 = 0; *s3 = 0; *s4 = 0;
        }
        break;
    case 1:
        u1 = &p->f5c;
        u3 = &p->f68;
        u2 = &p->f60;
        u4 = &p->f6c;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700((u8 *)p);
        if (p->f38 < p->f430) {
            u32 t = p->st;
            p->st = t + 1;
            p->b20d = 0;
            p->f38 = p->f430;
            *u1 = 0; *u2 = 0; *u3 = 0; *u4 = 0;
            func_001757E0(p, 1, 3);
            func_00183d50(p);
        }
        break;
    case 2:
        if ((s8)func_00175700((u8 *)p) < 0) func_001843A0(p);
        break;
    }
}
