typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 f0[4];
    s8 f4;
    s8 f5;
    u8 f6[2];
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    u8 f10[8];
    s8 f18;
    s8 f19;
    u8 f1a[0x10];
    s8 f2a;
    u8 f2b[0x5D];
    s8 f88;
    u8 f89[6];
    s8 f8f;
    u8 f90[0xF];
    s8 f9f;
} G_b;

extern G_b *D_004C2840;
extern u8 D_004C27C0;
extern u8 D_004C27C4;
extern s8 D_004D18DE[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern u8 D_004F2601[];
extern u8 D_004F2602[];

void func_00127290(void)
{
    extern void func_001E3CE0(u8);
    extern void func_001E6D80(s32, s32);
    extern void func_001237A0();
    extern void func_0016F0D0();
    extern void func_0016D190();
    G_b *g;
    s32 t;
    s32 a;
    s16 v;
    s32 k;

    D_004C2840->f19 = (D_004C2840->f88 != 0) ? 0 : 1;
    g = D_004C2840;
    t = g->f88;
    if (t == 0) t = g->f18;
    if (((t & 1) != 0 && (D_004F4480[0] & 0x360) != 0 && D_004C2840->fe != 0)
        || ((t & 2) != 0 && (D_004F4494[0] & 0x360) != 0 && D_004C2840->fe != 0)
        || (v = D_004C2840->f8 - 1, D_004C2840->f8 = v, v == 0)) {
        D_004C2840->f4 = D_004C2840->f4 + 1;
    }
    if (D_004C2840->f8 == 0x168) D_004C2840->fe = 1;
    if (D_004C2840->f8 == 0x14A) D_004C2840->fe = 2;
    g = D_004C2840;
    if (g->fe == 2) {
        if (g->f8f != 0) {
            a = D_004F2602[g->f9f * 0x5B8];
        } else {
            a = D_004F2601[g->f9f * 0x5B8];
        }
        if (a == 0x14) a = 0;
        g->fc = g->fc + 1;
        if (D_004C2840->fc >= 8) {
            D_004C2840->fc = 0;
            D_004C2840->fa = D_004C2840->fa + 1;
            if (D_004C2840->fa >= 8) D_004C2840->fa = 0;
            D_004C2840->f5 = D_004C2840->f5 - 1;
            if (D_004C2840->f5 == (a / 5) * 5 - 2) {
                D_004C2840->fe = 3;
                k = 0x29;
                if (D_004D18DE[0] >= 0) {
                    k = 0x2E;
                    if (D_004C2840->f88 != 0 || D_004C2840->f2a != 0) k = 0x2D;
                }
                func_001E3CE0(k);
            }
            D_004C27C4 = 1;
            D_004C27C0 = 0xB;
            func_001E6D80(D_004C2840->f5, 7 - D_004C2840->fa);
        }
    }
    func_001237A0();
    func_0016F0D0();
    func_0016D190();
}
