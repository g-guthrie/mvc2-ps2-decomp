typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w189_h.c "-O3 -Op -sdatathreshold 8" */
typedef struct G397 { u8 pad[0x7C]; s16 h7C[1]; } G397;
extern G397 *D_004C2794;

typedef struct P397 {
    u8 pad0[2]; u8 b2; u8 pad3; u8 b4; u8 pad5[0x18 - 5]; struct P397 *p18; u8 pad1C[0x13C - 0x1C]; u8 b13C;
    u8 pad13D[0x1B2 - 0x13D]; s8 b1B2; u8 pad1B3; s8 b1B4; u8 b1B5; u8 pad1B6[0x1C0 - 0x1B6]; u16 h1C0;
    u8 pad1C2[0x1D8 - 0x1C2]; s32 w1D8;
} P397;
typedef struct X397 { s8 b0; u8 b1; u8 b2; u8 pad3[2]; u8 b5; u8 b6; u8 b7; } X397;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
void func_003973F0(P397 *p, X397 *x, X397 *y) {
    u32 one;
    u8 st;
    s8 h;
    u32 t;
    extern void func_003DAA40();
    extern void func_00396FD0(P397 *, X397 *, X397 *);
    extern void func_001E7F60(P397 *);
    if (p->p18->b4 >= 2) {
        t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        func_003DAA40(p);
        return;
    }
    one = 1;
    if (D_004D18DC[0] & (one << D_004D18DB[0])) return;
    x->b1 = 1;
    p->b13C = 1;
    if (y->b2 < x->b6) {
        p->b13C = 0;
        return;
    }
    if (y->b2 == x->b6) {
        x->b1 = 2;
        x->b0 = -1;
        p->b13C = 1;
    }
    if (p->b1B2 != 0) {
        x->b1 = 1;
        x->b0 = -1;
        y->b7 = 0xFF;
        h = p->b1B4 - 1;
        p->b1B4 = h;
        if (h == 0) {
            st = 0x56;
            t = x->b5;
            x->b5 = t + 1;
            if ((u8)(t + 1) >= 3) {
                x->b5 = 0;
                st = 0x55;
            }
            p->b1B5 = st;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        }
    }
    func_00396FD0(p, x, y);
    if (y->b7 == 0) func_001E7F60(p);
}
