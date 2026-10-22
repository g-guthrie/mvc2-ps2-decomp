typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct G28 {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
    s8 b6;
    s8 b7;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u8 pad10[4];
    s32 w14;
    u8 pad18[0x4C - 0x18];
    s8 b4C;
    u8 pad4D[0x59 - 0x4D];
    s8 b59;
} G28;

extern G28 *D_004C2840;
extern u16 D_004C25F4;
extern s8 D_0043CCC3[];
extern s8 D_0043CCCD[];

void func_00128CD0(void)
{
    extern s32 func_003299D0(void);
    extern s32 func_00128CA0(void);
    extern void func_001E3CE0(s32);
    extern void func_00129140(void);
    extern void func_0012E6B0(void);
    G28 *g;
    s16 t, h;
    s32 v;
    s16 *q;

    v = (g = D_004C2840)->b2;
    if (v == 0) {
        if (func_003299D0() == 0) {
            D_004C2840->b2 = D_004C2840->b2 + 1;
            D_004C2840->hA = 8;
            D_004C2840->h8 = D_004C2840->b4C;
        }
    } else if ((s8)v == 1) {
        q = &g->hA;
        if (*q == 0) {
            if (D_004C25F4 & 0x800) {
                q = &g->h8;
                h = *q;
                if (h >= 5) {
                    *q = h + 1;
                    if (D_004C2840->h8 > 8) D_004C2840->h8 = 5;
                } else {
                    *q = h - 1;
                    if (D_004C2840->h8 == 1) {
                        if (func_00128CA0() != 0) D_004C2840->h8 = 0;
                    }
                    if (D_004C2840->h8 < 0) D_004C2840->h8 = 3;
                }
                func_001E3CE0(1);
                D_004C2840->hA = 4;
            }
            if (D_004C25F4 & 0x400) {
                h = D_004C2840->h8;
                if (h >= 5) {
                    D_004C2840->h8 = h - 1;
                    if (D_004C2840->h8 < 5) D_004C2840->h8 = 8;
                } else {
                    D_004C2840->h8 = h + 1;
                    if (D_004C2840->h8 == 1) {
                        if (func_00128CA0() != 0) D_004C2840->h8 = 2;
                    }
                    if (D_004C2840->h8 >= 4) D_004C2840->h8 = 0;
                }
                func_001E3CE0(1);
                D_004C2840->hA = 4;
            }
            if ((D_004C25F4 & 0x2000) || (D_004C25F4 & 0x1000)) {
                h = D_004C2840->h8;
                if (h >= 5) {
                    D_004C2840->h8 = D_0043CCC3[h];
                    if (D_004C2840->h8 == 1) {
                        if (func_00128CA0() != 0) D_004C2840->h8 = 0;
                    }
                } else {
                    D_004C2840->h8 = D_0043CCCD[h];
                }
                func_001E3CE0(1);
                D_004C2840->hA = 4;
            }
            if (D_004C2840->h8 == 1) {
                if (func_00128CA0() != 0) D_004C2840->h8 = 0;
            }
            D_004C2840->b4C = D_004C2840->h8;
            func_00129140();
            return;
        } else {
            t = *q - 1;
            *q = t;
            if (t < 0) D_004C2840->hA = 0;
        }
    } else {
    if (func_003299D0() == 0) {
        func_0012E6B0();
        D_004C2840->w14 = 0x40;
        D_004C2840->b0 = 1;
        D_004C2840->b1 = 7;
        D_004C2840->b2 = D_004C2840->b3 = D_004C2840->b4 = D_004C2840->b5 = D_004C2840->b6 = D_004C2840->b7 = D_004C2840->h8 = D_004C2840->hA = D_004C2840->hC = D_004C2840->hE = 0;
        D_004C2840->b4C = 0;
        D_004C2840->b59 = 0;
    }
    }
}
