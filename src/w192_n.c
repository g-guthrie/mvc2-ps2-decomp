typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct P {
    u8 pad0[6]; u8 b6; u8 pad7[0x1E - 7]; s16 h1E; u8 pad20[0x34 - 0x20]; f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x151 - 0x70]; s8 b151; u8 pad152[0x15B - 0x152]; u8 b15B;
    u8 pad15C[0x1B2 - 0x15C]; s8 b1B2; u8 pad1B3[0x20D - 0x1B3]; u8 b20D; u8 pad20E[0x430 - 0x20E]; f32 f430;
} P;
extern void func_00175700(P *);
extern void func_00186A20(P *);
extern void func_00183d50(P *);
extern void func_001E3710(P *, s32);

void func_00283AC0(P *p)
{
    f32 *a, *b, *c, *d;
    s32 v;
    if (p->b1B2 != 0) {
        if (p->h1E == 0)
            p->h1E = 1;
    }
    if (p->b15B == 0)
        func_00175700(p);
    v = p->b151;
    if (v != 0) {
        if ((s8)v >= 0) {
            p->f34 += p->f5C;
            p->f5C += p->f68;
        } else {
            func_00186A20(p);
            a = &p->f5C;
            c = &p->f68;
            b = &p->f60;
            d = &p->f6C;
            p->f34 += p->f5C;
            p->f5C += p->f68;
            p->f38 += p->f60;
            p->f60 += p->f6C;
            if (p->f38 <= p->f430) {
                p->b6++;
                p->f38 = p->f430;
                p->b20D = 0;
                *a = 0;
                *b = 0;
                *c = 0;
                *d = 0;
                func_00183d50(p);
                func_001E3710(p, 0x34);
            }
        }
    }
}
