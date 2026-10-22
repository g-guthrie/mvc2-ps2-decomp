typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0xA]; u8 bA; u8 padB; u16 hC; } Q_d;
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
    u8 pad33D[0x35C - 0x33D];
    u16 h35C;
    u8 pad35E[0x366 - 0x35E];
    u16 h366;
    u8 pad368[0x40C - 0x368];
    u8 b40C;
    u8 pad40D[0x430 - 0x40D];
    f32 f430;
    u8 pad434[0x539 - 0x434];
    s8 b539;
} P_d;

extern f32 D_004F1FE0[];
extern G_d *D_004C2794;

void func_0025FB00(P_d *p) {
    extern void func_0036BFF0(P_d *, s32, s32, s32);
    extern void func_00175700(P_d *);
    extern void func_00175C00(P_d *, s32);
    extern void func_00183d50(P_d *);
    extern void func_001757E0(P_d *, s32, s32);
    extern void func_002601B0(P_d *);
    extern void func_00260070(P_d *);
    f32 lim;
    Q_d *q;
    f32 *s1, *s2, *s3, *s4;
    u32 h;
    s16 k;
    u8 v;

    lim = D_004F1FE0[0] - 102.85713958740234f;
    if (lim < p->f38) {
        p->f38 = lim;
    }
    if (p->f430 + 2.142857074737549f > p->f38) {
        p->f38 = 17.142856597900391f + p->f430;
    }
    p->b209 = 2;
    if (p->b151 == 2) {
        p->b151 = 0;
        func_0036BFF0(p, 0x15, 0x13, 0x15);
    }
    p->b40C = 2;
    p->b33C = 5;
    q = &p->q;
    h = q->hC;
    q->hC = h - 1;
    if ((s32)h > 0) {
        return;
    }
    q->hC = 0;
    if (p->b1B2 != 0 && q->bA < 2) {
        if (q->bA == 1) {
            p->b1B5 = 0x3A;
            p->b1B2 = *(u16 *)&p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        } else {
            p->b1B5 = 0x39;
            p->b1B2 = *(u16 *)&p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        }
        q->bA++;
        q->hC = 4;
    }
    s1 = &p->f5C;
    s3 = &p->f68;
    s2 = &p->f60;
    s4 = &p->f6C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->f38 < p->f430) {
        p->b6 = 5;
        func_00175C00(p, 0);
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        *s4 = 0;
        p->f38 = p->f430;
        func_00183d50(p);
        func_001757E0(p, 0x16, 8);
        return;
    }
    k = p->h1C - 1;
    p->h1C = k;
    if (k == 0) {
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
    if (p->b539 != 0 && p->b151 != 1) {
        func_002601B0(p);
    } else if (p->b151 != 1) {
        if ((p->h35C & 0x300) != 0 || (p->h366 & 0x300) != 0) {
            func_00260070(p);
        }
    }
}
