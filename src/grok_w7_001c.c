typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    u8 pad[16];
    void (*callback)(void);
    void *field20;
    void *arg;
    u8 pad28[4];
    u8 mode;
} Entry;

extern s32 func_00174470(u8 *);
extern s32 func_001745B0(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001C48E0(void);
extern void func_001C0A70(void);
extern Entry *func_003DA750(s32, s32, s32);
extern void func_001C1CA0(u8 *, u8 *, void *);
extern void func_001C3DC0(u8 *, u8 *, void *);
extern void func_001C84D0(u8 *, u8 *, void *);
extern void func_001DC1F0(u8 *);
extern void func_001DC440(u8 *);

s32 func_001C1D40(u8 *p, u8 *q)
{
    u8 *v = p + 208;
    s32 r = 1;
    if ((u8)(--p[212]) == 0) {
        if (v[5] != 0)
            r = 0;
        func_001C1CA0(p, q, *(void **)v);
    }
    return r;
}

s32 func_001C3E60(u8 *p, u8 *q)
{
    u8 *v = p + 208;
    s32 r = 1;
    if ((u8)(--p[212]) == 0) {
        if (v[5] != 0)
            r = 0;
        func_001C3DC0(p, q, *(void **)v);
    }
    return r;
}

s32 func_001C8570(u8 *p, u8 *q)
{
    u8 *v = p + 208;
    s32 r = 1;
    if ((u8)(--p[212]) == 0) {
        if (v[5] != 0)
            r = 0;
        func_001C84D0(p, q, *(void **)v);
    }
    return r;
}

void func_001DC1A0(u8 *p, u8 *q)
{
    q = P(p, 24);
    if (p[33] != 0)
        *(s32 *)(q + 724) = 4;
    if (p[32] == 0)
        func_001DC1F0(p);
    else
        func_001DC440(p);
}

void func_001C1100(u8 *p)
{
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (func_00174470(p) == 0)
        p[4]++;
}

void func_001C2370(u8 *p)
{
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (func_001745B0(p) == 0) {
        p[6] = 5;
        p[7] = 0;
        p[0] = 0;
        p[316] = 0;
    }
}

void func_001C1330(u8 *p, u8 *q)
{
    s16 face;
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    face = S(q, 320);
    S(p, 320) = face;
    if (face == 0)
        F(p, 52) += F(p, 92);
    else
        F(p, 52) -= F(p, 92);
    F(p, 56) += F(p, 96);
}

void func_001C1390(u8 *p, u8 *q)
{
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    if (S(q, 320) == 0)
        F(p, 52) += F(p, 92);
    else
        F(p, 52) -= F(p, 92);
    F(p, 56) += F(p, 96);
}

void func_001C4830(u8 *p, u8 mode)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001C48E0;
        e->mode = mode;
        e->arg = P(p, 24);
        e->field20 = p;
    }
}

void func_001C3140(u8 *p)
{
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (func_00174470(p) == 0)
        p[4]++;
}

void func_001C37D0(u8 *p)
{
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (func_001745B0(p) == 0) {
        p[7]++;
        p[0] = 0;
        p[316] = 0;
    }
}

void func_001C0A00(u8 *p, s32 a1, u8 mode)
{
    Entry *e = func_003DA750(a1, 3, 2);
    if (e) {
        e->callback = func_001C0A70;
        e->arg = p;
        e->field20 = (void *)a1;
        e->mode = mode;
    }
}

void func_001C82C0(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        S(p, 28) = 16;
        S(p, 320) ^= 1;
        func_001757E0(p, 25, 20);
    }
}

void func_001C35B0(u8 *p, u8 *q)
{
    u8 *r = q + 696;
    if (q[707] == 0 || r[10] != 0) {
        p[7]++;
        p[0] = 1;
        p[316] = 1;
        S(p, 320) = S(q, 320);
        *(V3 *)(p + 52) = *(V3 *)(q + 52);
    }
}


