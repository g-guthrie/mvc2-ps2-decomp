typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PB {
    u8 _p0[2];
    u8 b2;
    u8 _p0b[3];
    u8 b6;
    u8 b7;
    u8 _p1[0x1C - 8];
    s16 h1c;
    s8 b1e;
    u8 _p2[0x34 - 0x1F];
    f32 f34;
    f32 f38;
    u8 _p3[0x5C - 0x3C];
    f32 f5c;
    u8 _p4[0x68 - 0x60];
    f32 f68;
    u8 _p5[0x151 - 0x6C];
    s8 b151;
    u8 _p6[0x1B2 - 0x152];
    s8 b1b2;
    u8 _p7[0x1B5 - 0x1B3];
    u8 b1b5;
    u8 _p8[0x1C0 - 0x1B6];
    u16 h1c0;
    u8 _p8b[2];
    struct PB *q1c4;
    u8 _p9[0x1D8 - 0x1C8];
    u32 w1d8;
    u8 _pa[0x1E6 - 0x1DC];
    u8 b1e6;
    u8 _pb[0x20D - 0x1E7];
    u8 b20d;
    u8 _pc[0x33B - 0x20E];
    u8 b33b;
    u8 b33c;
    u8 _pd[0x40C - 0x33D];
    u8 b40c;
    u8 b40d;
    u8 _pe[0x430 - 0x40E];
    f32 f430;
} PB;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GB;
extern GB *D_004C2794;

void func_002DEB60(PB *p)
{
    extern void func_00175700(PB *);
    extern void func_001D1EB0(PB *);
    extern void func_001D20B0(PB *, s32, s32);
    extern s32 func_00185980(PB *);
    extern void func_001757E0(PB *, s32, u8);
    s16 h;
    u32 t;
    f32 v;
    PB *q;

    p->b40c = 2;
    p->b33c = 5;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    func_00175700(p);
    if (p->b151 != 0) {
        p->b151 = 0;
        *(u32 *)&p->f5c = 0xC27D5555;
        *(u32 *)&p->f68 = 0;
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
        }
        p->b1b5 = p->b1e + 0x35;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
        func_001D1EB0(p);
        func_001D20B0(p, (*(s16 *)&p->b1e & 1) ^ 1, 0);
        func_001D20B0(p, (*(s16 *)&p->b1e & 1) ^ 1, 1);
    }
    h = p->h1c - 1;
    p->h1c = h;
    if (h == 0) {
        if (p->b1b2 != 0 && ((s8)p->b1b2 & 1) == 0 && func_00185980(p) != 0) {
            v = 26.66666603088379f;
            q = p->q1c4;
            if (p->b1e6 != 0) {
                v = -v;
            }
            q->f34 += v;
            q->f38 = p->f430;
            q->b20d = 0;
            t = p->b7;
            p->b7 = t + 1;
            *(u32 *)&p->f5c = 0xC0D55555;
            *(u32 *)&p->f68 = 0x3FD55555;
            if (p->b1e6 != 0) {
                p->f5c = -p->f5c;
                p->f68 = -p->f68;
            }
            func_001757E0(p, 0x16, 5);
            return;
        }
        p->b40d = 0;
        p->b40c = 0;
        p->b33b = 0;
        p->b33c = 0;
        t = p->b6;
        p->b6 = t + 1;
        p->b7 = 0;
        *(u32 *)&p->f5c = 0xC0D55555;
        *(u32 *)&p->f68 = 0x3ED55555;
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001757E0(p, 0x16, 8);
    }
}
