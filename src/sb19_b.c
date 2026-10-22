typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044B170[];

void func_001A6350(u8 *p, u8 *q)
{
    f32 fa;
    f32 fb;
    u8 *cur;
    u8 *par;
    s32 n;
    s32 i;
    u8 *e;
    f32 xb, yb, xa, ya;
    s16 *g;
    s16 *h;

    e = q + 0x2B8;
    g = &D_0044B170[p[0x22] * 4 + 2];
    fa = 1.66666662693f * (f32)g[0];
    fb = 2.14285707474f * (f32)g[1];
    if (*(s16 *)(p + 0x140) != 0) {
        fa = -fa;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(e + 0xC) - fa;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(e + 0x10) - fb;
    n = *(s16 *)(p + 0x1E);
    if (n > 1) {
        i = 1;
        cur = p;
        do {
            par = *(u8 **)(cur + 0xC);
            g = &D_0044B170[cur[0x22] * 4];
            xa = 1.66666662693f * (f32)g[0];
            ya = 2.14285707474f * (f32)g[1];
            h = &D_0044B170[par[0x22] * 4 + 2];
            xb = 1.66666662693f * (f32)h[0];
            yb = 2.14285707474f * (f32)h[1];
            if (*(s16 *)(cur + 0x140) != 0) {
                xa = -xa;
                xb = -xb;
            }
            i++;
            *(f32 *)(par + 0x34) = *(f32 *)(cur + 0x34) + xa - xb;
            *(f32 *)(par + 0x38) = *(f32 *)(cur + 0x38) + ya - yb;
            cur = par;
        } while (i < n);
    }
}
