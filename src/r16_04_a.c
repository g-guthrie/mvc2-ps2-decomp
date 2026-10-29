/* func_003F3190 (ConvertModelMeshAMO_WeightModel, Capcom fl AMO lib) with its real callees as statics.
   MW 3.0: ./try30.sh src/r16_04_a.c "-O4,p -sdatathreshold 8". Every static verifies exact at its own address. */
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
    f32 c[2];
    u32 w;
} Ent40;

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

static u8 *func_003F2550(u32 *p, s32 i) {
    u8 *r = (u8 *)func_003F1F90(p, 0x4000);
    if (r == 0) {
        return 0;
    }
    return (u8 *)((s32)r + 0xC) + i * 8;
}

static u8 *func_003F2590(u32 *p, s32 a1)
{
    u32 *r = func_003F1F90(p, 0x8000);
    if (r == 0) return 0;
    return (u8 *)((u32)r + 0xC + (a1 << 4));
}

static u32 func_003F25D0(u32 *p, s32 n)
{
    u32 *r = func_003F1F90(p, 0x10000);
    u32 *q;
    s32 i;
    if (r == 0) return -1;
    q = r + 3;
    for (i = 0; i < n; i++) { u32 w = *q; q++; q += w * 2; }
    return *q;
}

static u8 *func_003F26E0(u32 *a, s32 n, s32 k) {
    u8 *p;
    s32 i, x;
    p = (u8 *)func_003F1F90(a, 0x10000);
    if (p == 0) return 0;
    p += 12;
    for (i = 0; i < n; i++) {
        x = *(s32 *)p;
        p += 4;
        p += x * 8;
    }
    if (k >= *(s32 *)p) return 0;
    p += 4;
    p += k * 8; return p;
}

static s32 func_003F2810(u32 *a, s32 n)
{
    u32 *r = func_003F1F90(a, 0x20000);
    u32 *q;
    s32 i;
    u32 t;
    if (r == 0) return 0;
    q = r + 3;
    for (i = 0; i <= n; i++) {
        t = *q;
        q++;
        q += t;
    }
    return t;
}

static u32 func_003F2920(u32 *p, s32 n, u32 idx)
{
    u32 *r = func_003F1F90(p, 0x20000);
    u32 *q;
    s32 i;
    if (r == 0) return 0;
    q = r + 3;
    for (i = 0; i < n; i++) { u32 w = *q; q++; q += w; }
    if (*q < idx) return 0;
    return q[1 + idx];
}

s32 func_003F3190(Mdl *m, u8 *f)
{
    u32 w[4];
    s32 n;
    s32 i;
    u16 *q;
    s32 c;
    s32 sz;
    u32 k2;
    u32 *pw;
    u32 k1;
    s32 t;
    Ent40 *e;
    s32 jC;
    s32 stride;
    s32 j;
    s32 cnt2;
    s32 cnt;
    f32 *v;
    u32 *x;
    f32 *v3;
    f32 *v1;

    m->flags = 0x21000;
    m->n = n = func_003F1FF0(f);
    if (func_003F3700(f) == 1) {
        m->flags |= 0x400000;
    }
    m->flags |= 0x100000;
    c = 0;
    for (i = 0; i < m->n; i++) {
        c += func_003F20A0(f, i);
    }
    sz = (m->n + c) * 2;
    if (m->flags & 0x400000) {
        sz += m->n * 2;
    }
    if (m->flags & 0x100000) {
        sz += m->n * 4;
    }
    if ((m->buf = (u16 *)D_004C2B0C(sz)) == 0) return 0;
    m->bufsz = sz;
    q = m->buf;
    for (i = 0; i < m->n; i++) {
        n = func_003F20A0(f, i);
        *q = n;
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
        if (m->flags & 0x100000) {
            q[0] = 0;
            *(u16 *)((u8 *)q + 2) = 0;
            cnt2 = func_003F2810((u32 *)f, i);
            if ((u32)cnt2 > 4) return 0;
            w[0] = w[1] = w[2] = w[3] = 0;
            j = 0;
            goto T;
        L:
            w[j] = func_003F2920((u32 *)f, i, j);
            j++;
        T:
            if (j < cnt2) goto L;
            q[0] = (w[0] << 8) | w[1];
            *(u16 *)((u8 *)q + 2) = (w[2] << 8) | w[3];
            q += 2;
        }
        if (m->flags & 0x1000) {
            for (j = 0; j < n; j++) {
                *q = func_003F2350(f, i, j);
                q++;
            }
        }
    }
    m->kind = 0x35;
    m->kind |= 0x200;
    m->n2 = func_003F2030(f);
    switch (m->kind & 0xF00) {
    case 0x100:
    case 0x200:
    case 0x300:
    case 0x400:
        stride = 40;
        break;
    }
    sz = stride * m->n2;
    if ((m->tab = D_004C2B0C(sz)) == 0) return 0;
    m->tabsz = sz;
    e = (Ent40 *)m->tab;
    for (t = 0; t < m->n2; t++) {
        v1 = (f32 *)func_003F24D0(f, t);
        e->a[0] = v1[0];
        e->a[1] = v1[1];
        e->a[2] = v1[2];
        v = (f32 *)func_003F2510((u32 *)f, t);
        e->b[0] = v[0];
        e->b[1] = v[1];
        e->b[2] = v[2];
        v3 = (f32 *)func_003F2550((u32 *)f, t);
        e->c[0] = v3[0];
        e->c[1] = v3[1];
        v = (f32 *)func_003F2590((u32 *)f, t);
        e->col = (func_00119098(v[3]) << 24) | (func_00119098(v[0]) << 16) | (func_00119098(v[1]) << 8) | func_00119098(v[2]);
        pw = &e->w;
        *pw = 0;
        cnt = func_003F25D0((u32 *)f, t);
        for (jC = 0; jC < cnt; jC++) {
            x = (u32 *)func_003F26E0((u32 *)f, t, jC);
            switch (m->kind & 0xF00) {
            case 0x100:
                k1 = x[0];
                if (k1 < 2) {
                    { u32 v = (s32)(((f32 *)x)[1] * 65535.0f / 100.0f) & 0xFFFF; v <<= 16 - k1 * 16; *pw |= v; }
                }
                break;
            case 0x200:
                k2 = x[0];
                if (k2 < 4) {
                    { u32 v = (s32)(((f32 *)x)[1] * 255.0f / 100.0f) & 0xFF; v <<= 24 - k2 * 8; *pw |= v; }
                }
                break;
            case 0x300:
            case 0x400:
                break;
            }
        }
        e++;
    }
    return 1;
}
