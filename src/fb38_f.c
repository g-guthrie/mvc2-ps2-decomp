typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x14];
    s16 h14;
    s16 h16;
    s16 h18;
    s16 h1a;
    s16 h1c;
    s16 h1e;
    s16 h20;
    u8 pad22[0x2E - 0x22];
    s16 h2e;
    s16 h30;
    s16 h32;
    u8 pad34[2];
    s16 h36;
} GF;

extern u8 D_004F7F90[];
extern u8 D_0043CD60[];
extern u8 D_0043CD70[];
extern u8 D_0043CD74[];
extern u8 D_0043CD78[];
extern s32 D_0043CD30[];
extern u8 *D_004C2840;

void func_0012C120(u8 *a0)
{
    extern s32 func_0012BB80();
    extern void func_0012BC00(GF *, s32);
    extern void func_0012BDC0(GF *, s32);
    extern s32 func_00417A40(void);
    extern s32 func_0012BFF0(s32);
    extern s32 func_0012C0D0(s32);
    extern void func_0012BA70(GF *, s32, s32);
    extern void func_0012BE30(GF *, s32);
    GF *g;
    u8 *d;
    s32 n1;
    u8 *tab1;
    s32 v;
    u8 *tab2;
    s32 n2;
    s32 idx1;
    s32 cnt1;
    s32 cnt2;
    s32 idx2;
    s32 w;
    u8 *pw;
    s32 k;

    g = (GF *)a0;
    d = D_004F7F90;
    g->h1c = 0;
    g->h20 = 0;
    g->h1e = 0;
    if (func_0012BB80(g) < 0x1D) {
        func_0012BC00(g, 0);
    } else if ((func_00417A40() & 1) != 0) {
        func_0012BC00(g, 0);
        if (g->h14 == -1) func_0012BDC0(g, 0);
    } else {
        func_0012BDC0(g, 0);
        if (g->h14 == -1) func_0012BC00(g, 0);
    }
    if (g->h14 == -1) g->h36++;
    for (;;) {
        if (d[0] >= 0x32) {
            n1 = 0x10;
            tab1 = D_0043CD60;
        } else {
            tab1 = D_0043CD60;
            n1 = 8;
        }
        idx1 = func_00417A40() % n1;
        for (cnt1 = 0; cnt1 < n1; cnt1++) {
            v = tab1[idx1];
            if (v >= 0x20) pw = D_004C2840 + 0x34; else pw = D_004C2840 + 0x30;
            if ((*(s32 *)pw & (1 << v)) == 0) break;
            idx1 = (idx1 + 1) & (n1 - 1);
        }
        if (cnt1 == n1) {
            g->h16 = -1;
            g->h36++;
            break;
        }
        if (func_0012BFF0(v) != 0) {
            g->h16 = v;
            func_0012BA70(g, 1, func_0012C0D0(v));
            break;
        }
    }
    for (;;) {
        if (d[0] >= 0x32) {
            n2 = 0x10;
            tab2 = D_0043CD70;
        } else {
            k = D_0043CD30[d[0] % 10];
            if (k == 2) {
                n2 = 8;
                tab2 = D_0043CD78;
            } else {
                if (k == 0) tab2 = D_0043CD70;
                else tab2 = D_0043CD74;
                n2 = 4;
            }
        }
        idx2 = func_00417A40() % n2;
        for (cnt2 = 0; cnt2 < n2; cnt2++) {
            v = tab2[idx2];
            if (v >= 0x20) pw = D_004C2840 + 0x34; else pw = D_004C2840 + 0x30;
            if ((*(s32 *)pw & (1 << v)) == 0) break;
            idx2 = (idx2 + 1) & (n2 - 1);
        }
        if (cnt2 == n2) {
            g->h18 = -1;
            g->h36++;
            break;
        }
        if (func_0012BFF0(v) != 0) {
            g->h18 = v;
            func_0012BA70(g, 2, func_0012C0D0(v));
            break;
        }
    }
    g->h2e = 0;
    g->h32 = 0;
    g->h30 = 0;
    func_0012BE30(g, 3);
    if (g->h1a == -1) g->h36++;
}
