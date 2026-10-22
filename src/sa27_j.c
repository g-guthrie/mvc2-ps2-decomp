typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x1C - 8];
    s16 h1C;
    s16 h1E;
    u8 pad20[2];
    u8 b22;
    u8 pad23[0x34 - 0x23];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6C;
    u8 pad70[0x1B2 - 0x70];
    s8 b1B2;
    u8 pad1B3[4];
    u8 b1B7;
    u8 pad1B8[0x1E6 - 0x1B8];
    u8 b1E6;
} A25;

void func_002506D0(A25 *p, A25 *q)
{
    extern void func_00175700(A25 *);
    extern void func_00250940(A25 *, s32);
    extern void func_001757E0(A25 *, s32, u8);
    s16 v;
    f32 f;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    v = p->h1C - 1;
    p->h1C = v;
    if (v == 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        if (p->b1E6 != 0)
            f = 5.0f;
        else
            f = -5.0f;
        p->f5C = f;
        if (p->b1E6 != 0)
            f = -0.1041666641831398f;
        else
            f = 0.1041666641831398f;
        p->f68 = f;
        func_00250940(p, 1);
        func_001757E0(p, 0x15, p->b1B7 + 9);
        return;
    }
    if (p->b1B2 != 0) {
        u32 t = p->b22;
        t = t - 1;
        p->b22 = t;
        if ((u8)t == 0) {
            u32 u;
            p->b22 = 1;
            p->h1C = p->h1C + 1;
            u = q->b7;
            q->b7 = u + 1;
            v = p->h1E - 1;
            p->h1E = v;
            if (v == 0) {
                p->h1C = 1;
            } else if (q->b7 > 1) {
                func_00250940(p, 2);
            } else {
                func_00250940(p, 0);
            }
        }
    }
}
