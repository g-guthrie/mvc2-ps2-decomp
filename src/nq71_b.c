typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x430]; f32 f430; } OW;
typedef struct {
    u8 pad0[5]; u8 b5; u8 pad6[0x16]; s16 h1C; u8 pad1E[0x16];
    f32 f34, f38; u8 pad3C[0x20]; f32 f5c, f60, f64, f68, f6c;
    u8 pad70[0x1B2 - 0x70]; s8 b1B2, b1B3;
} AC;

void residual_003B23B0(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001E7F60(u8 *);
    AC *a = (AC *)p;
    OW *o = (OW *)q;
    f32 z;
    f32 *v, *w;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = (f32 *)(p + 0x5C);
    w = (f32 *)(p + 0x68);
    z = 0.0f;
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) {
        *v = z;
        *w = z;
    }
    if (!(o->f430 < a->f38)) {
        a->b5++;
        a->f38 = o->f430;
        a->h1C = 12;
        return;
    }
    switch (a->b1B3) {
    case 0: break;
    default: a->b5++; a->h1C = 1; return;
    }
    func_001E7F60(p);
    if (a->b1B2 != 0) { a->b5++; a->h1C = 1; }
}
