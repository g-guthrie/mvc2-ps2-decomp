typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_0027F270(u8 *a)
{
    s8 v = *(s8 *)(a + 0x1B2);
    u8 *q;
    if ((v & 0x80) == 0)
        return 0;
    q = *(u8 **)(a + 0x1C4);
    if (q[3] != 0)
        return 0;
    if ((v & 0x11) != 0)
        return 0;
    if (a != *(u8 **)(q + 0x1C8))
        return 0;
    if (q[0x425] != 0)
        return 0;
    if (q[0x20D] == 3)
        return 0;
    if ((*(u32 *)(q + 0x428) & 0x7000000) != 0)
        return 0;
    return (q[5] != 3) ^ 1;
}

extern s32 D_004AD200[];
extern s32 D_004AD230[];
extern s32 D_004AD260[];
extern s32 D_004AD290[];

extern u8 *D_004C2840;

static s32 func_0012BFB0(s32 n)
{
    u32 *m = (u32 *)(D_004C2840 + 0x30);
    if (n >= 0x18)
        m++;
    return (*m & (1 << (n & 0x1F))) != 0;
}

s32 func_0012BFF0(s32 c)
{
    s32 *t;
    s32 i, o;
    if (c != 0x20 && c != 0x36 && c != 0x3A && c != 0x34)
        return 1;
    switch (c) {
    case 0x20:
        t = D_004AD200;
        break;
    case 0x36:
        t = D_004AD230;
        break;
    case 0x34:
        t = D_004AD260;
        break;
    case 0x3A:
        t = D_004AD290;
        break;
    }
    i = 0; o = 0;
    do {
        if (func_0012BFB0(*(s32 *)((u8 *)t + o)) != 0)
            return 1;
        i++;
        o += 4;
    } while (i < 12);
    return 0;
}

extern u8 D_004BF514[4];
extern s8 D_004F7FC8[];

u8 func_00189DD0(u8 *a, void *b, u8 *q)
{
    extern u8 func_00189500(u8 *, void *, u8 *);
    extern void func_0018A920(u8 *, u8 *);
    s32 t;
    s8 v;
    u32 w, u;
    v = (s8)q[1] - 1;
    q[1] = v;
    if (v <= 0) {
        return q[0] = 0;
    }
    t = (u16)((*(u16 *)(a + 0x35E) & 0x3C00) >> 10);
    if (t == 0)
        return 0;
    if ((u16)t != D_004BF514[(q[3] + q[4]) & 3])
        return 0;
    w = q[2] - 1;
    q[2] = w;
    if ((u8)w == 0) {
        a[0x370] = 0;
        u = q[0];
        q[0] = u + 1;
        q[1] = D_004F7FC8[a[2]] * 10 + 0xF;
        q[2] = 0;
        return func_00189500(a, b, q);
    }
    q[3] = ((s8)q[3] + (s8)q[4]) & 3;
    func_0018A920(a, q);
    return 0;
}
