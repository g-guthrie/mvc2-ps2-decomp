typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00475AB0[];
extern s16 D_00475AB2[];

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x16];
    s16 h1c;
    u8 pad1e[4];
    u8 b22;
    u8 pad23[0x11];
    f32 f34;
    f32 f38;
    u8 pad3c[0x14];
    f32 f50;
    f32 f54;
    u8 pad58[4];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
} A43;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x2E];
    f32 f34;
    f32 f38;
    u8 pad3c[0x104];
    s16 h140;
    u8 pad142[0xF];
    s8 b151;
} B43;

void func_003BDE30(A43 *p, B43 *q)
{
    extern void func_003BE5C0(A43 *, B43 *);
    s32 v;
    s32 k;
    s32 i;
    if (q->b5 != 0) {
        func_003BE5C0(p, q);
        return;
    }
    if (q->b151 < 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        q->b151 = 4;
        *(u32 *)&p->f50 = 0x3F800000;
        p->h1c = 16;
        *(u32 *)&p->f5c = 0;
        *(u32 *)&p->f60 = 0;
        *(u32 *)&p->f68 = 0;
        *(u32 *)&p->f6c = 0;
        v = 0x71600;
        k = 8;
        if (q->h140 == 0) {
            v = -0x71600;
            k = 0x18;
        }
        p->f5c = 1.6666666f * (f32)v / 65536.0f;
        p->b22 = k;
    }
    i = q->b151;
    p->f50 += 0.1f;
    if (p->f50 > 1.0f) p->f50 = 1.0f;
    p->f54 = p->f50;
    {
        s32 x = D_00475AB0[i * 2];
        s32 y = D_00475AB2[i * 2];
        if (q->h140 != 0) x = -x;
        p->f34 = (p->f34 + q->f34 + 1.6666666f * (f32)x) / 2.0f;
        p->f38 = (p->f38 + q->f38 + 2.142857074737549f * (f32)y) / 2.0f;
    }
}
