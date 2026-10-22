typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f0; f32 f4; s32 w8; u8 bC; u8 bD; u8 bE; u8 bF; } T34;
extern T34 D_00462090[];
extern u8 *D_004C2794;

void func_0034D080(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *r = *(u8 **)(p + 0x18);
    T34 *t = &D_00462090[p[0x22]];
    f32 a = t->f0;
    f32 b;
    u32 n;
    s32 *dp;
    dp = (s32 *)(p + 0xD0);
    if (p[0x20] != 0) a = -a;
    a += *(f32 *)(r + 0x34);
    b = a - *(f32 *)(p + 0x34);
    n = t->bF;
    *(f32 *)(p + 0x5C) = b / (f32)n;
    b = t->f4 + *(f32 *)(r + 0x38);
    b -= *(f32 *)(p + 0x38);
    n = t->bF;
    *(f32 *)(p + 0x60) = b / (f32)n;
    *dp = (t->w8 - *(s32 *)(p + 0x48)) / t->bF;
    *(s16 *)(p + 0x1C) = t->bF;
    func_001757E0(p, 0x16, t->bC);
    {
        u32 c = t->bD;
        p[0x1B5] = c;
        if (c != 0) {
            u32 d = p[0x1B5];
            s16 *q;
            p[0x1B5] = d;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
            q[0x3E] = q[0x3E] + 1;
            *(s16 *)(p + 0x1C0) = 0x10;
        }
    }
}
