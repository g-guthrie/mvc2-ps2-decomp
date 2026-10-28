typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct { u8 pad0[0x14]; s32 w14; s32 w18; u32 w1C; u32 w20; s32 w24; } C40a;
typedef struct { s32 e0; s32 e4; } T8a;
typedef struct { s32 a; s32 b; s32 c; } T12a;
typedef struct {
    u8 pad0[0xC];
    u32 w0C;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    u8 pad2C[0x14];
    C40a *w40;
    u8 pad44[0xC];
    u8 b50[0x20];
} OBJa;
typedef struct { f32 x, y, z; f32 nx, ny, nz; u32 rgba; } V28;
typedef struct { f32 x, y, z; f32 nx, ny, nz; u32 rgba; f32 u, v; } V36;
typedef struct { f32 x, y, z; f32 nx, ny, nz; u32 rgba; f32 u, v; u32 c2; } V40;
typedef struct { u32 flags; s32 cnt; u16 *ptr; u32 type; u8 *verts; } SRCa;
typedef struct { s32 v[4]; } I4;

extern T8a D_00478E10[];
extern T12a D_00478E60[];
extern u32 D_00478DF0[];
extern I4 D_0062C7A0;
extern I4 D_0062C7B0;
extern char D_004BABD0[];

#define GIFTAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | ((u64)(flg) << 58) | ((u64)(nreg) << 60))

void func_003EEC30(SRCa *src, OBJa *o)
{
    extern u8 *func_003DD030(s32);
    extern u32 *func_003DBB90(u8 *, u32, s32);
    extern u8 *func_003DBB40(u8 *);
    extern void func_003DBA00(u8 *, s32, s32, s32);
    extern void func_003DBAF0(u8 *, s32, s32, s32);
    extern void func_003DBA90(u8 *, u32, u8 *, s32, s32);
    extern void func_003ED0D0(char *, ...);
    u32 fmt;
    u16 *p;
    V28 *v28;
    V36 *v36;
    V40 *v40;
    u8 *s;
    s32 j;
    u32 pos;
    s32 i;
    u8 *base;
    u8 *bc;
    s32 cnt;
    s32 prev;
    s32 cur;
    u32 sz;
    u8 *gs;
    s32 count;
    u32 w;
    s32 *tab;
    u32 prim;
    u32 regs;
    u32 nreg;
    C40a *c;
    u32 lim;
    u32 *q;
    u32 d;
    I4 uv;
    I4 col;

    c = o->w40;
    fmt = D_00478E10[c->w18].e4;
    uv = D_0062C7A0;
    col = D_0062C7B0;
    prim = D_00478E60[c->w1C].a;
    regs = D_00478E60[c->w1C].b;
    nreg = D_00478E60[c->w1C].c;
    if ((o->w0C & 0x18000) == 0x8000) prim |= 0x20;
    base = func_003DD030(o->w1C);
    p = src->ptr;
    count = src->cnt;
    s = base;
    bc = s;
    s += 0x10;
    lim = c->w20 + 0x20;
    cur = 0;
    prev = -1;
    cnt = 0;
    tab = (s32 *)func_003DD030(o->w24);
    for (i = 0; i < count; i++) {
        u32 fl;
        w = *p++;
        fl = src->flags;
        if (fl & 0x400000) cur = *p++;
        if (fl & 0x100000) {
            uv.v[0] = (s32)p[0] >> 8;
            uv.v[1] = p[0] & 0xFF;
            uv.v[2] = (s32)p[1] >> 8;
            uv.v[3] = p[1] & 0xFF;
            p += 2;
        }
        if (prev != cur) {
            prev = cur;
            if (cnt != 0) {
                q = func_003DBB90(gs, pos >> 4, 0);
                q[0] = 1;
                q[1] = (((nreg << 4) * (cnt + 2)) >> 4) + 1;
                q[2] = 0;
                q[3] = 0;
                *(u64 *)(q + 4) = GIFTAG(cnt, 1, 1, prim, 0, nreg);
                q[6] = regs;
                q[7] = 0;
                s = func_003DBB40(s);
                func_003DBA00(bc, ((u32)(s - bc) >> 4) - 1, 0, 0);
                bc = s;
                cnt = 0;
                s += 0x10;
            }
            for (j = 0; j < o->w28; j++) {
                if (o->b50[j] == cur) break;
            }
            {
                u8 *t = func_003DD030(o->w20);
                u32 e = D_00478DF0[c->w14];
                t += j * e;
                func_003DBA90(bc, e >> 4, t, 0, 0);
            }
            pos = 0x10;
            pos += 0x10;
            *tab = j;
            bc = s;
            tab++;
            gs = s + 0x10;
            s += 0x40;
        }
        for (j = 0; j < (w & 0x3FFF); j++) {
            sz = D_00478E10[c->w18].e0;
            if (pos + sz >= c->w20) {
                q = func_003DBB90(gs, pos >> 4, 0);
                q[0] = 1;
                q[1] = (((nreg << 4) * (cnt + 2)) >> 4) + 1;
                q[2] = 0;
                q[3] = 0;
                *(u64 *)(q + 4) = GIFTAG(cnt, 1, 1, prim, 0, nreg);
                q[6] = regs;
                q[7] = 0;
                s = func_003DBB40(s);
                d = s - bc;
                if (lim + d >= 0x100000) {
                    func_003DBA00(bc, (d >> 4) - 1, 0, 0);
                    bc = s;
                    s += 0x10;
                }
                gs = s;
                pos = 0x10;
                s += 0x30;
                pos += 0x10;
                cnt = 0;
            }
            pos += sz;
            cnt++;
            switch (src->type) {
            case 0x25:
                if (src->flags & 0x1000) v28 = (V28 *)src->verts + *p++;
                else v28++;
                if (fmt & 1) {
                    ((f32 *)s)[0] = v28->x;
                    ((f32 *)s)[1] = v28->y;
                    ((f32 *)s)[2] = v28->z;
                    if (j < 2) ((u32 *)s)[3] = 0x8000;
                    else ((u32 *)s)[3] = 0;
                    s += 0x10;
                }
                if (fmt & 2) {
                    ((f32 *)s)[0] = v28->nx;
                    ((f32 *)s)[1] = v28->ny;
                    ((f32 *)s)[2] = v28->nz;
                    ((u32 *)s)[3] = 0x3F800000;
                    s += 0x10;
                }
                if (fmt & 4) {
                    ((f32 *)s)[0] = (f32)((v28->rgba >> 16) & 0xFF);
                    ((f32 *)s)[1] = (f32)((v28->rgba >> 8) & 0xFF);
                    ((f32 *)s)[2] = (f32)(v28->rgba & 0xFF);
                    ((f32 *)s)[3] = 0.5f * (f32)((v28->rgba >> 24) & 0xFF);
                    s += 0x10;
                }
                break;
            case 0x35:
                if (src->flags & 0x1000) v36 = (V36 *)src->verts + *p++;
                else v36++;
                if (fmt & 1) {
                    ((f32 *)s)[0] = v36->x;
                    ((f32 *)s)[1] = v36->y;
                    ((f32 *)s)[2] = v36->z;
                    if (j < 2) ((u32 *)s)[3] = 0x8000;
                    else ((u32 *)s)[3] = 0;
                    s += 0x10;
                }
                if (fmt & 2) {
                    ((f32 *)s)[0] = v36->nx;
                    ((f32 *)s)[1] = v36->ny;
                    ((f32 *)s)[2] = v36->nz;
                    ((u32 *)s)[3] = 0x3F800000;
                    s += 0x10;
                }
                if (fmt & 4) {
                    ((f32 *)s)[0] = 0.5f * (f32)((v36->rgba >> 16) & 0xFF);
                    ((f32 *)s)[1] = 0.5f * (f32)((v36->rgba >> 8) & 0xFF);
                    ((f32 *)s)[2] = 0.5f * (f32)(v36->rgba & 0xFF);
                    ((f32 *)s)[3] = 0.5f * (f32)((v36->rgba >> 24) & 0xFF);
                    s += 0x10;
                }
                if (fmt & 8) {
                    ((f32 *)s)[0] = v36->u;
                    ((f32 *)s)[1] = v36->v;
                    ((u32 *)s)[2] = 0x3F800000;
                    ((u32 *)s)[3] = 0;
                    s += 0x10;
                }
                break;
            case 0x235:
                if (src->flags & 0x1000) v40 = (V40 *)src->verts + *p++;
                else v40++;
                if (fmt & 1) {
                    ((f32 *)s)[0] = v40->x;
                    ((f32 *)s)[1] = v40->y;
                    ((f32 *)s)[2] = v40->z;
                    if (j < 2) ((u32 *)s)[3] = 0x8000;
                    else ((u32 *)s)[3] = 0;
                    s += 0x10;
                }
                if (fmt & 2) {
                    ((f32 *)s)[0] = v40->nx;
                    ((f32 *)s)[1] = v40->ny;
                    ((f32 *)s)[2] = v40->nz;
                    ((u32 *)s)[3] = 0x3F800000;
                    s += 0x10;
                }
                if (fmt & 4) {
                    ((f32 *)s)[0] = 0.5f * (f32)((v40->rgba >> 16) & 0xFF);
                    ((f32 *)s)[1] = 0.5f * (f32)((v40->rgba >> 8) & 0xFF);
                    ((f32 *)s)[2] = 0.5f * (f32)(v40->rgba & 0xFF);
                    ((f32 *)s)[3] = 0.5f * (f32)((v40->rgba >> 24) & 0xFF);
                    s += 0x10;
                }
                if (fmt & 8) {
                    ((f32 *)s)[0] = v40->u;
                    ((f32 *)s)[1] = v40->v;
                    ((u32 *)s)[2] = 0x3F800000;
                    ((u32 *)s)[3] = 0;
                    s += 0x10;
                }
                if ((fmt & 0x10) && (fmt & 0x20)) {
                    f32 *b;
                    s32 *cg, *cb, *ca;
                    u32 *a;
                    f32 k255 = 255.0f;
                    cg = &col.v[1];
                    cb = &col.v[2];
                    ca = &col.v[3];
                    a = (u32 *)s;
                    b = (f32 *)(s + 0x10);
                    s += 0x20;
                    col.v[0] = (v40->c2 >> 24) & 0xFF;
                    *cg = (v40->c2 >> 16) & 0xFF;
                    *cb = (v40->c2 >> 8) & 0xFF;
                    *ca = v40->c2 & 0xFF;
                    *(u128 *)a = 0;
                    *(u128 *)b = 0;
                    a[0] = c->w24 + uv.v[0] * 4;
                    b[0] = (f32)col.v[0] / k255;
                    a[1] = c->w24 + uv.v[1] * 4;
                    b[1] = (f32)*cg / k255;
                    a[2] = c->w24 + uv.v[2] * 4;
                    b[2] = (f32)*cb / k255;
                    a[3] = c->w24 + uv.v[3] * 4;
                    b[3] = (f32)*ca / k255;
                }
                break;
            }
        }
    }
    if (cnt != 0) {
        q = func_003DBB90(gs, pos >> 4, 0);
        q[0] = 1;
        q[1] = (((nreg << 4) * (cnt + 2)) >> 4) + 1;
        q[2] = 0;
        q[3] = 0;
        *(u64 *)(q + 4) = GIFTAG(cnt, 1, 1, prim, 0, nreg);
        q[6] = regs;
        q[7] = 0;
        s = func_003DBB40(s);
    }
    func_003DBAF0(bc, ((u32)(s - bc) >> 4) - 1, 1, 0);
    if ((d = o->w18) != s - base) func_003ED0D0(D_004BABD0, base, s, d);
}
