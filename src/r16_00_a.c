/* func_00188860: MW 3.0 (./try30.sh "-O3 -sdatathreshold 8"). Key: u8 x built with |= keeps x in one IRO_SplitLifetimes range (compound assignment links def and use), so it interferes with the third byte load and takes a3 like retail. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 b0; u8 pad1[0x28A]; u8 b28B; u8 pad2[0x28]; s16 f2B4; u8 pad3[0x17E]; s16 f434; } OA;
typedef struct { OA *tab[3]; } EA;
typedef struct { u8 pad[0x18]; EA e[2]; } GA1;
typedef struct { u8 pad[0xB9]; s8 fB9; s8 fBA; } GB1;
extern GA1 *D_004C2794;
extern GB1 *D_004C2840;
extern u8 D_004D18A0[];
extern s8 D_004D18D4[];

s32 func_00188860(u8 *p, u8 k)
{
    extern s32 func_0018A580(u8 *);
    extern void func_00186A60(u8 *, s32);
    s8 *q;
    u8 m;
    u32 kk;
    s8 v;
    u8 x;
    OA *o;
    u16 mask;
    GA1 *g;
    EA *e;
    OA **t;
    s8 ba;
    s32 i;

    m = k;
    kk = m;

    if (m == 1) {
        q = (s8 *)(p + 0x26E);
        mask = 0x80;
    } else if (m == 2) {
        q = (s8 *)(p + 0x26F);
        mask = 0x10;
    } else if (m == 3) {
        q = (s8 *)(p + 0x25E);
        mask = 0x80;
        m = m - 2;
    } else {
        q = (s8 *)(p + 0x25F);
        mask = 0x10;
        m = m - 2;
    }
    if (*(s8 *)(p + 0x539) == 0) {
        if (*q == 0) {
            if ((s32)kk < 3) {
                if ((*(u16 *)(p + 0x35C) & mask) == 0) goto end0;
                if ((*(u16 *)(p + 0x35E) & 0xC00) == 0) *q = 0x10;
                goto end0;
            }
            if ((*(u16 *)(p + 0x35C) & mask) != 0) *q = 0x10;
            goto end0;
        }
        v = *q - 1;
        *q = v;
        if (v == 0) goto end0;
        if ((*(u16 *)(p + 0x354) & mask) != 0) goto end0;
    }
    if (p[5] != 0) return 0;
    if ((s32)kk < 3) {
        if (p[0x20D] == 3 || p[0x20D] == 2) return 0;
    } else {
        if (p[0x20D] == 3 || (p[0x20D] == 2 && p[0x210] != 0)) return 0;
        if (p[0x1E4] == 0x14 && p[0x213] == 2) return 0;
    }
    i = p[2];
    g = D_004C2794;
    ba = D_004C2840->fBA;
    x = g->e[i ^ 1].tab[0]->b28B;
    x |= g->e[i ^ 1].tab[1]->b28B;
    x |= g->e[i ^ 1].tab[2]->b28B;
    if (ba == 0 && x) return 0;
    if (D_004D18A0[0] >= 5) return 0;
    if (D_004C2840->fB9 != 0) return 0;
    if (ba == 0 && D_004D18D4[p[2]] > 1) return 0;
    if (*(s8 *)(p + 0x205) != 0) return 0;
    o = g->e[p[2]].tab[m];
    if (o->b0 != 0) return 0;
    if (o->f2B4 != 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    e = D_004C2794->e;
    t = e[p[2]].tab;
    if (t[m]->f434 == 0) {
        k = ((kk - 1) ^ 1) + 1;
        m = (((s8)m - 1) ^ 1) + 1;
        o = t[m];
        if (o->b0 != 0) return 0;
        if (o->f2B4 != 0) return 0;
        if (o->f434 == 0) return 0;
    }
    if (k < 3) {
        p[0x26B] = m;
        func_00186A60(p, 0x1C);
        p[7] = 0;
        p[6] = 0;
        if (p[0x20D] != 2) p[0x26A] = 0;
        else p[0x26A] = 1;
    } else {
        p[0x26B] = m;
        *(s8 *)(p + 0x2B0) = -1;
    }
    *q = 0;
    return 1;
end0:
    return 0;
}
