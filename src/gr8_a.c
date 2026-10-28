/* gr8: MW 3.0.3, ./try.sh src/gr8_a.c "-O3 -sdatathreshold 8" (also matches on 3.0) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G56c;
extern G56c *D_004C2794;

typedef struct { u8 pad[0x434]; s16 h434; s16 h436; s16 h438; } P18;

void func_0018F9E0(P18 *p, s32 a) {
    extern void func_0018FB70();
    extern void func_001902F0();
    s16 v, b, n;
    if (*(u8 *)D_004C2794 != 4 || (v = p->h434) == 0) return;
    b = a;
    if (b == 0) return;
    if (b < 0) {
        func_0018FB70(p, a);
    } else {
        p->h434 = n = v + a;
        if (n > 0x90) p->h434 = 0x90;
        if (p->h434 > p->h438) p->h434 = p->h438;
    }
    func_001902F0(p);
}

void func_0024BA20(u8 *p)
{
    extern s32 func_0018AB10();
    s16 v;
    u8 *q;
    u32 t;

    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        if (func_0018AB10() == 0) return;
        t = p[0x2BE];
        p[0x2BE] = t + 1;
        q = p + 0x2B8;
        if ((s32)p[0x2BE] <= 0 || (q[6] = 0, *(s16 *)(p + 0x1E) -= 3, *(s16 *)(p + 0x1E) > 0)) return;
    }
    *(s16 *)(p + 0x1E) = 4;
    if (p[0x20D] == 0) {
        p[0x1B5] = 0x37;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}
