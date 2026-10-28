typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* MWCC 3.0.3: ./try.sh src/nq137_a.c "-O3 -Op -sdatathreshold 0" (also exact on 3.0) */
extern s16 D_0044B170[];
extern s16 D_0044AE00[];

void func_001A64D0(u8 *p, u8 *q)
{
    f32 z;
    s16 *g;
    u8 *e;
    f32 ya;
    f32 xb;
    s32 n;
    u8 *cur;
    f32 fa;
    u8 *par;
    f32 fb;
    f32 zy;
    f32 xa;
    f32 yb;
    s16 *h;
    s32 i;

    p = *(u8 **)(p + 0x14);
    z = 0.0f;
    zy = -4.285714149475098f;
    e = q + 0x2B8;
    par = *(u8 **)(p + 8);
    g = &D_0044B170[par[0x22] * 4];
    fa = 1.66666662693f * (f32)g[0];
    fb = 2.14285707474f * (f32)g[1];
    if (*(s16 *)(p + 0x140) != 0) {
        z = -z;
        fa = -fa;
    }
    *(f32 *)(par + 0x34) = *(f32 *)(p + 0x34) + z - fa;
    *(f32 *)(par + 0x38) = *(f32 *)(p + 0x38) + zy - fb;
    n = *(s16 *)(p + 0x1E) - 1;
    for (i = 1; i < n; i++) {
        cur = par;
        g = &D_0044B170[cur[0x22] * 4 + 2];
        xa = 1.66666662693f * (f32)g[0];
        ya = 2.14285707474f * (f32)g[1];
        par = *(u8 **)(cur + 8);
        h = &D_0044B170[par[0x22] * 4];
        xb = 1.66666662693f * (f32)h[0];
        yb = 2.14285707474f * (f32)h[1];
        if (*(s16 *)(cur + 0x140) != 0) {
            xa = -xa;
            xb = -xb;
        }
        *(f32 *)(par + 0x34) = *(f32 *)(cur + 0x34) + xa - xb;
        *(f32 *)(par + 0x38) = *(f32 *)(cur + 0x38) + ya - yb;
    }
    if (*(s8 *)(e + 0x20) == 0) {
        *(f32 *)(q + 0x34) = *(f32 *)(par + 0x34) - *(f32 *)(e + 0xC);
        *(f32 *)(q + 0x38) = *(f32 *)(par + 0x38) - *(f32 *)(e + 0x10);
    }
}

void func_001A2D60(u8 *p, u8 *q)
{
    f32 z;
    s16 *g;
    u8 *e;
    f32 ya;
    f32 xb;
    s32 n;
    u8 *cur;
    f32 fa;
    u8 *par;
    f32 fb;
    f32 zy;
    f32 xa;
    f32 yb;
    s16 *h;
    s32 i;

    p = *(u8 **)(p + 0x14);
    z = 0.0f;
    zy = -4.285714149475098f;
    e = q + 0x2B8;
    par = *(u8 **)(p + 8);
    g = &D_0044AE00[par[0x22] * 4];
    fa = 1.66666662693f * (f32)g[0];
    fb = 2.14285707474f * (f32)g[1];
    if (*(s16 *)(p + 0x140) != 0) {
        z = -z;
        fa = -fa;
    }
    *(f32 *)(par + 0x34) = *(f32 *)(p + 0x34) + z - fa;
    *(f32 *)(par + 0x38) = *(f32 *)(p + 0x38) + zy - fb;
    n = *(s16 *)(p + 0x1E) - 1;
    for (i = 1; i < n; i++) {
        cur = par;
        g = &D_0044AE00[cur[0x22] * 4 + 2];
        xa = 1.66666662693f * (f32)g[0];
        ya = 2.14285707474f * (f32)g[1];
        par = *(u8 **)(cur + 8);
        h = &D_0044AE00[par[0x22] * 4];
        xb = 1.66666662693f * (f32)h[0];
        yb = 2.14285707474f * (f32)h[1];
        if (*(s16 *)(cur + 0x140) != 0) {
            xa = -xa;
            xb = -xb;
        }
        *(f32 *)(par + 0x34) = *(f32 *)(cur + 0x34) + xa - xb;
        *(f32 *)(par + 0x38) = *(f32 *)(cur + 0x38) + ya - yb;
    }
    if (*(s8 *)(e + 0x3A) == 0) {
        *(f32 *)(q + 0x34) = *(f32 *)(par + 0x34) - *(f32 *)(e + 0x24);
        *(f32 *)(q + 0x38) = *(f32 *)(par + 0x38) - *(f32 *)(e + 0x28);
    }
}
