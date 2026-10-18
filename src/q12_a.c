typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00175700(void *p);

void func_00398140(u8 *p)
{
    s16 v;
    p[0x24] = 0;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    v = *(s16 *)(p + 0x1C);
    if (v <= 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (v < 30) {
        if (v & 1) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = 0;
            return;
        }
    }
    func_00175700(p);
}

typedef float f32;

extern s32 func_00186120(void);
extern void func_001843A0(void *p);
void func_001774C0(u8 *p)
{
    s16 v;
    if (*(s16 *)(p + 0x434) != 0) {
        if (func_00186120() == 0) {
            if ((p[0x245] & 7) == 5 || *(s8 *)(p + 0x1F7) != 0) {
                v = *(s16 *)(p + 0x1F8) - 1;
                *(s16 *)(p + 0x1F8) = v;
                if (v >= 0) return;
            }
        }
    }
    p[0x203] = 8;
    func_001843A0(p);
}
extern void func_002A33E0(void *p, void *q);
extern void func_00183d50(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
void func_002A32F0(u8 *p, u8 *q)
{
    u8 t;
    func_00175700(p);
    func_002A33E0(p, q);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        { u32 c = p[7]; p[7] = c + 1; }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        t = (p[0x1B7] != 0) ? 7 : 6;
        func_001757E0(p, 0x15, t);
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; } S;
void func_002100A0(S *p)
{
    s8 r;
    if (*(s8 *)((u8 *)p + 0x151) == 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    r = func_00175700(p);
    if (r < 0) {
        *(u32 *)&p->f5c = 0;
        *(u32 *)&p->f60 = 0;
        *(u32 *)&p->f68 = 0;
        *(u32 *)&p->f6c = 0;
        func_001843A0(p);
    }
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001BE8F0(void);
s32 func_001BE7E0(u8 *p, V3 *v, s32 t)
{
    u8 *q = p + 0x2B8;
    u8 *o;
    if (q[3] >= 5) return 0;
    if ((o = func_003DA750(0, 4, 0)) != 0) {
        u32 c;
        *(void **)(o + 0x10) = func_001BE8F0;
        *(u8 **)(o + 0x18) = p;
        *(V3 *)(o + 0x5C) = *v;
        o[0x20] = t;
        c = q[3];
        q[3] = c + 1;
    }
    return (s32)o;
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; } S36;
extern void func_001757E0(void *p, s32 a, s32 b);
void func_0036A760(u8 *a, S36 *b)
{
    func_00175700(b);
    b->f34 += b->f5c;
    b->f5c += b->f68;
    b->f38 += b->f60;
    b->f60 += b->f6c;
    if (b->f60 < 0.0f) {
        u32 c = a[6];
        a[6] = c + 1;
        func_001757E0(b, 0xD, 0x15);
    }
}

extern void func_001391E0(void *p);
void func_001390F0(u8 *p)
{
    u32 c;
    u8 a = p[5];
    switch (a) {
    case 0:
        p[5] = a + 1;
        *(s16 *)(p + 0x1C) = 0x3A;
        p[6] = 0;
        break;
    case 1:
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        if (*(s16 *)(p + 0x1C) < 0) {
            c = p[5];
            p[5] = c + 1;
            c = p[4];
            p[4] = c + 1;
            (*(u8 **)(p + 0x18))[0x22] |= (u8)(1 << *(s8 *)(p + 0x21));
        }
        break;
    case 2:
        func_001391E0(p);
        break;
    }
}

extern void func_00175C00(void *p, s32 a);
void func_00212C70(u8 *p, u8 *q)
{
    u32 c;
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q[4] = 0xFF;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        c = p[6];
        p[6] = c + 1;
        q[4] = 0;
        {s32 v; if (p[0x20D] == 2) v = 0x2C; else v = 0x1A; p[0x168] = v;}
        func_001757E0(p, 0x15, p[0x168]);
        func_00175C00(p, 0);
    }
}

extern void func_0024B9B0(void *p);
extern void func_001E3710(void *p, s32 a);
extern void func_00176160(void *p, s32 a, s32 b, s32 c);
extern void func_001A78D0(void *p, s32 a);
extern void func_0024BA20(void *p);
void func_0024B610(u8 *p)
{
    u32 c;
    func_0024B9B0(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        c = p[7];
        p[7] = c + 1;
        *(u32 *)(p + 0x5C) = 0;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x68) = 0xC0555555;
        } else {
            *(u32 *)(p + 0x68) = 0x40555555;
        }
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001E3710(p, 0x4B);
        func_00176160(p, 5, 4, 1);
        func_001A78D0(p, 0xF);
    }
    func_0024BA20(p);
}

extern void func_001830D0(void *p, void *v, s32 n);
void func_00251BF0(u8 *p)
{
    u32 c;
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        c = p[6];
        p[6] = c + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2CEAAAA;
        v[1] = 0x43272492;
        v[2] = 0;
        func_001830D0(p, v, 1);
        *(s16 *)(p + 0x1C) = 7;
        *(s16 *)(p + 0x1E) = 0;
    }
}

s32 func_00237B70(u8 *a, u8 *b, u8 c)
{
    u8 t;
    s32 r;
    b[0x1A] = 1;
    b[0x1E] = a[0x22];
    t = a[0x22];
    r = 0;
    if (t == 0x10 || t == 0x30) {
        c = 0x20;
        r = 1;
    }
    a[0x22] = (t ^ (s8)c) & 0x30;
    return r;
}
