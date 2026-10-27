typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w20b2_f.c "-O3 -sdatathreshold 8" */
typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G_g;
extern G_g *D_004C2794;
typedef struct {
    u8 pad0[5]; u8 b5; u8 b6; u8 b7; u8 pad8[0x22 - 8]; u8 b22;
    u8 pad23[0x1B7 - 0x23]; u8 b1b7; u8 pad1b8[0x1E6 - 0x1B8]; u8 b1e6;
    u8 pad1e7[0x1FD - 0x1E7]; u8 b1fd; u8 pad1fe[0x20D - 0x1FE]; u8 b20d;
    u16 h20e; u8 pad210[0x2B8 - 0x210]; u8 b2b8;
    u8 pad2b9[0x354 - 0x2B9]; u16 h354; u8 pad356[0x539 - 0x356]; s8 b539;
} P_h;
extern u8 D_0045DA10[];


typedef struct {
    u8 pad0[2]; u8 b2; u8 pad3[0x150 - 3]; s8 b150; s8 b151;
    u8 pad152[0x1B2 - 0x152]; u8 b1b2; u8 pad1b3[2]; u8 b1b5;
    u8 pad1b6[0x1C0 - 0x1B6]; u16 h1c0; u8 pad1c2[0x1D8 - 0x1C2]; s32 w1d8;
    u8 pad1dc[0x201 - 0x1DC]; u8 b201;
    u8 pad202[0x33B - 0x202]; u8 b33b; u8 b33c;
    u8 pad33d[0x40C - 0x33D]; u8 b40c; u8 b40d;
} P_i;
typedef struct { u8 pad0[0x16]; u8 b16; } Q_i;

void func_002F9E60(u8 *actor, void *context) {
    Q_i *q = (Q_i *)context;
    P_i *p = (P_i *)actor;
    extern s8 func_00175700(P_i *);
    extern void func_00175C00(P_i *, s32);
    extern void func_002F8EB0(P_i *);
    extern void func_00176160(P_i *, s32, s32, s32);
    p->b40c = 2;
    p->b33c = 5;
    p->b33c = 5;
    p->b201 = 2;
    if (func_00175700(p) < 0) {
        p->b40d = 0;
        p->b40c = 0;
        p->b33b = 0;
        p->b33c = 0;
        func_00175C00(p, 0);
        func_002F8EB0(p);
        return;
    }
    if (p->b151 != 0) {
        func_00176160(p, 0, p->b150, 2);
        switch (p->b151) {
        case 1:
            p->b1b5 = 0x34;
            p->b1b2 = p->h1c0 = 0;
            p->w1d8 = 0;
            D_004C2794->h7c[p->b2] += 1;
            break;
        case 2:
            p->b1b5 = 0x35;
            p->b1b2 = p->h1c0 = 0;
            p->w1d8 = 0;
            D_004C2794->h7c[p->b2] += 1;
            break;
        case 3:
            p->b1b5 = 0x36;
            p->b1b2 = p->h1c0 = 0;
            p->w1d8 = 0;
            D_004C2794->h7c[p->b2] += 1;
            q->b16 = 0;
            break;
        }
        p->b151 = 0;
    }
}
