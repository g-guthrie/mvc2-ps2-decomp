typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GG {
    u8 pad[0x7C];
    s16 h7C[8];
} GG;

typedef struct SS {
    u8 pad0[2];
    u8 b2;
    u8 pad1[3];
    u8 b6;
    u8 pad2[0x34 - 7];
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
    u8 b2D4;
    u8 padC[0x2EC - 0x2D5];
    s32 w2EC;
} SS;

extern GG *D_004C2794;
extern void func_001E3710(SS *, s32);
extern void func_001757E0(SS *, s32, s32);

void func_002F01E0(SS *p) {
    extern s8 func_00175700(SS *);
    s32 t;
    u32 st;
    u32 c;
    u32 t15;
    f32 a, b;
    t = p->w2EC - 1;
    p->w2EC = t;
    if (t < 0) {
        p->w2EC = 8;
        func_001E3710(p, 0x1A);
    }
    p->f34 += p->f5C;
    p->f5C += p->f68;
    if (func_00175700(p) < 0) {
        st = p->b6;
        p->b6 = st + 1;
        a = -6.666666507720947f;
        b = 0.20833333134651184f;
        if (p->s140 != 0) {
            a = -a;
            b = -b;
        }
        p->f5C = a;
        p->f68 = b;
        p->b1B5 = 0x35;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        func_001757E0(p, 0x15, 0x40);
    }
    t15 = p->b15B;
    if (t15 != 0) {
        c = p->b2D4;
        p->b1B5 = t15 + c;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        p->b15B = 0;
    }
}
