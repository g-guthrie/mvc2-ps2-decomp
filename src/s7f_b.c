/* func_001A23D0: MW 3.0.3 -O3 -Op -sdatathreshold 0 (also exact on 3.0). The 0x140 flag and the loop counter share one local, which gives retail i its early colour. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044AE00[];
typedef struct { s16 x, y; } P2;
extern P2 D_0044AF00[];

void func_001A23D0(u8 *p, u8 *q)
{
    f32 yd;
    f32 xa;
    u32 k;
    s32 i;
    f32 ya;
    f32 xb;
    f32 fa;
    s16 *g;
    f32 yb;
    f32 xd;
    f32 xc;
    s16 *h;
    s32 n;
    u8 *par;
    f32 fb;
    f32 yc;
    u8 *e;

    e = q + 0x2B8;
    g = &D_0044AE00[p[0x22] * 4 + 2];
    fa = 1.66666662693f * (f32)g[0];
    fb = 2.14285707474f * (f32)g[1];
    i = *(s16 *)(p + 0x140);
    if (i != 0) {
        fa = -fa;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(e + 0x24) - fa;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(e + 0x28) - fb;
    n = *(s16 *)(p + 0x1E) - 1;
    i = 1;
    if (n > 1) {
        do {
            par = *(u8 **)(p + 0xC);
            g = &D_0044AE00[p[0x22] * 4];
            xa = 1.66666662693f * (f32)g[0];
            ya = 2.14285707474f * (f32)g[1];
            h = &D_0044AE00[par[0x22] * 4 + 2];
            xb = 1.66666662693f * (f32)h[0];
            yb = 2.14285707474f * (f32)h[1];
            if (*(s16 *)(p + 0x140) != 0) {
                xa = -xa;
                xb = -xb;
            }
            i++;
            *(f32 *)(par + 0x34) = *(f32 *)(p + 0x34) + xa - xb;
            *(f32 *)(par + 0x38) = *(f32 *)(p + 0x38) + ya - yb;
            p = par;
        } while (i < n);
    }
    par = *(u8 **)(p + 0xC);
    g = &D_0044AE00[p[0x22] * 4];
    xc = 1.66666662693f * (f32)g[0];
    yc = 2.14285707474f * (f32)g[1];
    k = ((par[0x22] + 2) & 0x1F) >> 2;
    h = &D_0044AF00[k].x;
    xd = 1.66666662693f * (f32)h[0];
    yd = 2.14285707474f * (f32)h[1];
    if (*(s16 *)(p + 0x140) != 0) {
        xc = -xc;
        xd = -xd;
    }
    *(f32 *)(par + 0x34) = *(f32 *)(p + 0x34) + xc - xd;
    *(f32 *)(par + 0x38) = *(f32 *)(p + 0x38) + yc - yd;
}
/* func_001A5090: same shared flag/counter local as func_001A23D0. */

typedef struct { s16 x, y; } R336P;
extern s16 D_0044B170[];
extern R336P D_0044B270[];


void func_001A5090(u8 *a, u8 *b) {
    f32 fx, fy, gx, gy;
    f32 lx, ly, mx, my;
    s32 n; s32 i; u8 *par; u8 *q; s16 *e; s16 *e2; s16 *e3; R336P *rp;
    q = b + 0x2B8;
    e = D_0044B170 + (a[0x22] * 4 + 2);
    fx = 1.6666666f * (f32)e[0];
    fy = 2.142857f * (f32)e[1];
    i = *(s16 *)(a + 0x140);
    if (i != 0) fx = -fx;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(q + 0xC) - fx;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(q + 0x10) - fy;
    n = *(s16 *)(a + 0x1E) - 1;
    i = 1;
    if (n > 1) {
        do {
            par = *(u8 **)(a + 0xC);
            if (*(s8 *)(par + 0x13C) == 0) {
                ly = my = lx = mx = 0.0f;
            } else {
                e2 = D_0044B170 + a[0x22] * 4;
                e3 = D_0044B170 + (par[0x22] * 4 + 2);
                lx = 1.6666666f * (f32)e2[0];
                ly = 2.142857f * (f32)e2[1];
                mx = 1.6666666f * (f32)e3[0];
                my = 2.142857f * (f32)e3[1];
                if (*(s16 *)(a + 0x140) != 0) {
                    lx = -lx;
                    mx = -mx;
                }
            }
            i++;
            *(f32 *)(par + 0x34) = *(f32 *)(a + 0x34) + lx - mx;
            *(f32 *)(par + 0x38) = *(f32 *)(a + 0x38) + ly - my;
            a = par;
        } while (i < n);
    }
    par = *(u8 **)(a + 0xC);
    e2 = D_0044B170 + a[0x22] * 4;
    fx = 1.6666666f * (f32)e2[0];
    fy = 2.142857f * (f32)e2[1];
    i = ((par[0x22] + 2) & 0x1F) >> 2;
    rp = &D_0044B270[i];
    gx = 1.6666666f * (f32)rp->x;
    gy = 2.142857f * (f32)rp->y;
    if (*(s16 *)(a + 0x140) != 0) {
        fx = -fx;
        gx = -gx;
    }
    *(f32 *)(par + 0x34) = *(f32 *)(a + 0x34) + fx - gx;
    *(f32 *)(par + 0x38) = *(f32 *)(a + 0x38) + fy - gy;
}
/* func_001A0620: twin of func_001A5090 (shared flag/counter local); final block reuses lx/ly. */



void func_001A0620(u8 *a, u8 *b) {
    f32 fx, fy, gx, gy;
    f32 lx, ly, mx, my;
    s32 n; s32 i; u8 *par; u8 *q; s16 *e; s16 *e2; s16 *e3; P2 *rp;
    q = b + 0x2B8;
    e = D_0044AE00 + (a[0x22] * 4 + 2);
    fx = 1.6666666f * (f32)e[0];
    fy = 2.142857f * (f32)e[1];
    i = *(s16 *)(a + 0x140);
    if (i != 0) fx = -fx;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(q + 0x24) - fx;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(q + 0x28) - fy;
    n = *(s16 *)(a + 0x1E) - 1;
    i = 1;
    if (n > 1) {
        do {
            par = *(u8 **)(a + 0xC);
            if (*(s8 *)(par + 0x13C) == 0) {
                mx = my = lx = ly = 0.0f;
            } else {
                e2 = D_0044AE00 + a[0x22] * 4;
                e3 = D_0044AE00 + (par[0x22] * 4 + 2);
                lx = 1.6666666f * (f32)e2[0];
                ly = 2.142857f * (f32)e2[1];
                mx = 1.6666666f * (f32)e3[0];
                my = 2.142857f * (f32)e3[1];
                if (*(s16 *)(a + 0x140) != 0) {
                    lx = -lx;
                    mx = -mx;
                }
            }
            i++;
            *(f32 *)(par + 0x34) = *(f32 *)(a + 0x34) + lx - mx;
            *(f32 *)(par + 0x38) = *(f32 *)(a + 0x38) + ly - my;
            a = par;
        } while (i < n);
    }
    par = *(u8 **)(a + 0xC);
    e2 = D_0044AE00 + a[0x22] * 4;
    lx = 1.6666666f * (f32)e2[0];
    ly = 2.142857f * (f32)e2[1];
    i = ((par[0x22] + 2) & 0x1F) >> 2;
    rp = &D_0044AF00[i];
    gx = 1.6666666f * (f32)rp->x;
    gy = 2.142857f * (f32)rp->y;
    if (*(s16 *)(a + 0x140) != 0) {
        lx = -lx;
        gx = -gx;
    }
    *(f32 *)(par + 0x34) = *(f32 *)(a + 0x34) + lx - gx;
    *(f32 *)(par + 0x38) = *(f32 *)(a + 0x38) + ly - gy;
}
/* func_001861B0: the earlier speed local v is reused for the 0x68 limit, which gives retail f-register order. */

extern s16 D_00447280[];
extern s16 D_00447370[];
extern s16 D_00447460[];
extern s16 D_00448780[];

void func_001861B0(u8 *p) {
    f32 f;
    f32 g;
    f32 v;
    f32 x;

    f32 z;
    if ((p[0x1E6] != 0 && *(f32 *)(p + 0x5C) > 0.0f) ||
        (p[0x1E6] == 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        if (p[0x214] != 0) {
            f = 1.6666666269302368f * (f32)D_00447370[p[1] * 2] / 256.0f;
        } else if (p[0x216] & 0x80) {
            f = 1.6666666269302368f * (f32)D_00447460[p[1] * 2] / 256.0f;
        } else {
            f = 1.6666666269302368f * (f32)D_00447280[p[1] * 2] / 256.0f;
        }
        if (p[0x1E6] == 0) {
            f = -f;
        }
        v = *(f32 *)(p + 0x5C);
        if (v < 0.0f) {
            f = -f;
            v = -v;
        }
        if (!(f < v)) {
            *(f32 *)(p + 0x5C) = 0.0f;
        }
    }
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
g = 1.6666666269302368f * (f32)D_00448780[p[1]] / 256.0f; x = *(f32 *)(p + 0x5C); z = 0.0f; v = *(f32 *)(p + 0x68); if (x != z) { if (x < z) { g = -g; if (!(g <= v)) *(f32 *)(p + 0x68) = g; } else if (g < v) *(f32 *)(p + 0x68) = g; }
}

