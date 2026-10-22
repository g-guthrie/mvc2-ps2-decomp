/* sd7_c: ./try.sh src/sd7_c.c "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[10]; u8 bA; u8 padB; u16 hC; } Q_d;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G_d;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[3];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 h1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6C;
    u8 pad70[0x151 - 0x70];
    s8 b151;
    u8 pad152[0x1B2 - 0x152];
    s8 b1B2;
    u8 pad1B3[2];
    u8 b1B5;
    u8 pad1B6[0x1C0 - 0x1B6];
    u16 h1C0;
    u8 pad1C2[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 pad1DC[0x209 - 0x1DC];
    u8 b209;
    u8 pad20A[0x2B8 - 0x20A];
    Q_d q;
    u8 pad2C6[0x33C - 0x2C6];
    u8 b33C;
    u8 pad33D[0x430 - 0x33D];
    f32 f430;
} P_d;

extern f32 D_004F1FE0[];
extern G_d *D_004C2794;

void func_002613E0(P_d *p) {
    extern void func_00175700(P_d *);
    extern void func_00175C00(P_d *, s32);
    extern void func_001757E0(P_d *, s32, s32);
    extern void func_0036BFF0(P_d *, s32, s32, s32);
    f32 lim;
    Q_d *q;
    u32 h;
    s16 k;

    p->b33C = 5;
    lim = D_004F1FE0[0] - 102.85713958740234f;
    if (lim < p->f38) {
        p->f38 = lim;
    }
    if (!(2.142857074737549f + p->f430 <= p->f38)) {
        p->f38 = 17.14285659790039f + p->f430;
    }
    if (p->b151 == 2) {
        p->b151 = 0;
        func_0036BFF0(p, 0x15, 0x13, 0x15);
    }
    q = &p->q;
    h = q->hC;
    q->hC = h - 1;
    if ((s32)h > 0) {
        return;
    }
    q->hC = 0;
    if (p->b1B2 != 0 && q->bA < 9) {
        p->b1B5 = 0x47;
        p->b1B2 = *(u16 *)&p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        q->bA++;
        q->hC = 4;
    }
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    k = p->h1C - 1;
    p->h1C = k;
    if (k == 0) {
        p->b209 = 2;
        p->b6 = 4;
        func_00175C00(p, 0);
        p->f6C = -1.0f;
        if (!(p->f38 <= 66.66666412353516f + p->f430)) {
            func_001757E0(p, 0x16, 2);
            return;
        } else {
            func_001757E0(p, 0x16, 0x11);
            return;
        }
    }
}
