typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef int s32;
typedef struct { f32 x, y, z; } V3_45A0;
extern f32 D_004B7CF0[];
extern V3_45A0 D_004B7D40[];
extern s16 D_004B7D00[];
void residual_003345A0(u8 *p)
{
    extern void func_003346D0(u8 *);
    f32 *f = D_004B7CF0;
    V3_45A0 *v = D_004B7D40;
    s16 *q = D_004B7D00;
    V3_45A0 *e;
    s32 i;
    for (i = 0; i < p[4]; i++) q += *q * 2;
    e = &v[p[7]];
    *(f32 *)(p + 0x34) = e->x;
    *(f32 *)(p + 0x3C) = e->z;
    p[0x21] = *(s8 *)q;
    q += p[0x21];
    *(f32 *)(p + 0x38) = f[*q];
    p[5] = 1;
    p[6] = 1;
    func_003346D0(p);
}
