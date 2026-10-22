typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x176]; u8 b1e6; } S_002BA800;

void func_002BA800(S_002BA800 *p) {
    int *a;
    int *b;
    a = (int *)&p->f5c;
    b = (int *)&p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if ((p->b1e6 == 0 && p->f5c < 0.0f) || (p->b1e6 != 0 && p->f5c > 0.0f)) return;
    {
        u32 t = p->b6;
        p->b6 = t + 1;
        *a = 0;
        *b = 0;
    }
}
