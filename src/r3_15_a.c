/* MW 3.0, -O3 -sdatathreshold 0 -fp off, warmed by src/nf10_b.c (MWWARM_30) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Psa1f {
    u8 pad0[7];
    u8 b7;
    u8 pad1[0x34 - 8];
    f32 f34, f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5C, f60;
    u8 pad3[0x68 - 0x64];
    f32 f68, f6C;
} Psa1f;

void func_002308E0(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_00230670(u8 *, u8 *);

    Psa1f *s = (Psa1f *)p;
    f32 v;
    s32 st;
    u32 t7;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_00230670(p, q);
    st = *(s8 *)(p + 0x150);
    if (st != 3) {
        s->f34 += s->f5C;
        s->f5C += s->f68;
        s->f38 += s->f60;
        s->f60 += s->f6C;
        { s32 i = (s32)*(f32 *)(p + 0x430);
        if (s->f38 <= (f32)i) { s->f38 = (f32)i; } else { return; } }
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    t7 = p[7];
    p[7] = t7 + 1;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
}
