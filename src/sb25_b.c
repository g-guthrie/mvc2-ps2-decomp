typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GGb {
    u8 pad[0x7C];
    s16 h7C[8];
} GGb;

typedef struct SSb {
    u8 pad0[2];
    u8 b2;
    u8 pad1[3];
    u8 b6;
    u8 pad2[0x1C - 7];
    s16 h1C;
    u8 pad2b[0x34 - 0x1E];
    f32 f34;
    u8 pad3[0x5C - 0x38];
    f32 f5C;
    u8 pad4[0x68 - 0x60];
    f32 f68;
    u8 pad5[0x140 - 0x6C];
    s16 s140;
    u8 pad6[0x15B - 0x142];
    u8 b15B;
    u8 pad7[0x1B2 - 0x15C];
    u8 b1B2;
    u8 pad8[2];
    u8 b1B5;
    u8 pad9[0x1C0 - 0x1B6];
    u16 h1C0;
    u8 padA[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 padB[0x2D4 - 0x1DC];
    s8 b2D4;
    u8 padC[0x2EC - 0x2D5];
    s32 w2EC;
    u8 padD[0x33B - 0x2F0];
    u8 b33B;
    u8 b33C;
} SSb;

extern GGb *D_004C2794;

void func_002F0600(SSb *p) {
    extern s8 func_00175700(SSb *);
    extern void func_001E3710(SSb *, s32);
    extern void func_001E3210(SSb *, s32);
    extern void func_001757E0(SSb *, s32, s32);
    s32 t;
    s16 h;
    u32 st;
    s32 c;
    u32 t15;
    f32 a, b;
    p->b33C = 5;
    t = p->w2EC - 1;
    p->w2EC = t;
    if (t < 0) {
        p->w2EC = 8;
        func_001E3710(p, 0x1A);
    }
    p->f34 += p->f5C;
    p->f5C += p->f68;
    if (func_00175700(p) < 0) {
        func_001E3210(p, 3);
    } else {
        h = p->h1C - 1;
        p->h1C = h;
        if (h < 0) {
            p->b33B = 0;
            p->b33C = 0;
            st = p->b6;
            p->b6 = st + 1;
            a = -6.666666507720947f;
            b = 0.15625f;
            if (p->s140 != 0) {
                a = -a;
                b = -b;
            }
            p->f5C = a;
            p->f68 = b;
            p->b1B5 = 0x3C;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
            func_001757E0(p, 0x16, 7);
        }
    }
    t15 = p->b15B;
    if (t15 != 0) {
        c = p->b2D4;
        p->b1B5 = (s8)t15 + c;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        p->b15B = 0;
    }
}
