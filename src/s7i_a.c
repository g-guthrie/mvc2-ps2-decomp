/* Metrowerks 3.0: ./try30.sh src/s7i_a.c "-O4,p -sdatathreshold 8". The static functions are verbatim copies of the real callees (each verified exact at its own address; credited in their own files). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u32 flags;
    s32 n;
    u16 *buf;
    s32 kind;
    u8 *tab;
    s32 n2;
    s32 tabsz;
    s32 bufsz;
} Mdl;

typedef struct {
    f32 a[3];
    f32 b[3];
    u32 col;
} Ent;

typedef struct { u32 n; s32 v[1]; } Rec;
extern u8 *(*D_004C2B0C)(s32);
extern s32 func_003F3700(void *);
extern u32 func_00119098(f32);

static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

static s32 func_003F1FF0(void *p)
{
    s32 *r = (s32 *)func_003F1F90(p, 0x100);
    if (r == 0)
        return -1;
    return r[1];
}

static s32 func_003F2030(void *p)
{
    s32 *r = (s32 *)func_003F1F90(p, 0x800);
    if (r != 0)
        return r[1];
    return -1;
}

static s32 func_003F2060(u32 *a, s32 idx)
{
    u32 *r = func_003F1F90(a, 0x400);
    if (r == 0) return -1;
    return *(s32 *)((s32)r + 0xC + idx * 4);
}

static s32 func_003F20A0(u8 *p, s32 n)
{
    u8 *q;
    s32 i;
    u32 sz;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        q += 12;
        for (i = 0; i <= n; i++) {
            sz = *(u32 *)q & 0x7FFFFFFF;
            q += sz * 4 + 4;
        }
        return sz;
    }
    return -1;
}

static s32 func_003F21F0(u8 *p, s32 n)
{
    u8 *q;
    s32 i;
    u32 sz;
    u32 f;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        q += 12;
        for (i = 0; i <= n; i++) {
            sz = *(u32 *)q;
            f = sz & 0x80000000;
            q += (sz & 0x7FFFFFFF) * 4 + 4;
        }
        return f != 0;
    }
    return -1;
}

static s32 func_003F2350(u8 *p, s32 n, s32 k)
{
    u8 *q;
    u8 *t;
    s32 i;
    s32 r, sz;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        t = q + 12;
        for (i = 0; i < n; i++) {
            t += (*(u32 *)t & 0x7FFFFFFF) * 4 + 4;
        }
        sz = *(u32 *)t & 0x7FFFFFFF;
        if (k >= sz) r = -1; else r = ((s32 *)(t + 4))[k];
        return r;
    }
    return -1;
}

typedef struct { s32 a, b, c; } E12;
static u8 *func_003F24D0(u8 *a, s32 n)
{
    u8 *r;
    E12 *q;
    r = (u8 *)func_003F1F90((u32 *)a, 0x800);
    q = (E12 *)(r + 12);
    if (r == 0) return 0;
    return (u8 *)&q[n];
}

static u32 *func_003F2510(u32 *p, u32 n) {
    u32 *e = func_003F1F90(p, 0x1000);
    u32 *b = e + 3;
    u32 *r;
    if (e == 0) r = 0; else r = (u32 *)((u8 *)b + n * 12);
    return r;
}

static u8 *func_003F2590(u32 *p, s32 a1)
{
    u32 *r = func_003F1F90(p, 0x8000);
    if (r == 0) return 0;
    return (u8 *)((u32)r + 0xC + (a1 << 4));
}

s32 func_003F2BF0(Mdl *m, u8 *f)
{
    f32 *x;
    s32 k;
    s32 j;
    s32 i;
    Ent *e;
    s32 t;
    u16 *q;
    s32 sz;
    s32 c;

    m->flags = 0x21000;
    m->n = func_003F1FF0(f);
    if (func_003F3700(f) == 1) {
        m->flags |= 0x400000;
    }
    t = 0;
    for (i = 0; i < m->n; i++) {
        t += func_003F20A0(f, i);
    }
    sz = (m->n + t) * 2;
    if (m->flags & 0x400000) {
        sz += m->n * 2;
    }
    if ((m->buf = (u16 *)D_004C2B0C(sz)) == 0) return 0;
    m->bufsz = sz;
    q = m->buf;
    for (i = 0; i < m->n; i++) {
        c = func_003F20A0(f, i);
        *q = c;
        if (func_003F21F0(f, i)) {
            *q |= 0x8000;
        } else {
            *q |= 0x4000;
        }
        q++;
        if (m->flags & 0x400000) {
            *q = func_003F2060((u32 *)f, i);
            q++;
        }
        if (m->flags & 0x1000) {
            for (j = 0; j < c; j++) {
                *q = func_003F2350(f, i, j);
                q++;
            }
        }
    }
    m->kind = 0x25;
    m->n2 = func_003F2030(f);
    sz = m->n2 * 28;
    if ((m->tab = D_004C2B0C(sz)) == 0) return 0;
    m->tabsz = sz;
    e = (Ent *)m->tab;
    for (k = 0; k < m->n2; k++) {
        f32 *w;
        f32 *v;
        v = (f32 *)func_003F24D0(f, k);
        e->a[0] = v[0];
        e->a[1] = v[1];
        e->a[2] = v[2];
        w = (f32 *)func_003F2510((u32 *)f, k);
        e->b[0] = w[0];
        e->b[1] = w[1];
        e->b[2] = w[2];
        x = (f32 *)func_003F2590((u32 *)f, k);
        e->col = (func_00119098(x[3]) << 24) | (func_00119098(x[0]) << 16) | (func_00119098(x[1]) << 8) | func_00119098(x[2]);
        e++;
    }
    return 1;
}
