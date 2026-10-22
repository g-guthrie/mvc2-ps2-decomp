typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s8 *D_004C29C4;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
static void func_0038E660() {
    u8 *q = (u8 *)D_004C29C4;
    if (q[2] < 12) {
        u32 v = ((u8 *)D_004C29C4)[3] - 1;
        ((u8 *)D_004C29C4)[3] = v;
        if ((u8)v <= 0) {
            ((u8 *)D_004C29C4)[3] = 2;
            ((u8 *)D_004C29C4)[2]++;
        }
    }
}
typedef struct { u8 pad[0x1C]; s16 f; } S1C;
static void func_0038E6B0(S1C *p) {
    s16 v = p->f - 1;
    p->f = v;
    if (v <= 0) {
        p->f = 2;
        *D_004C29C4 += 1;
        if (*D_004C29C4 >= 8) *D_004C29C4 = 5;
    }
}
typedef struct { u8 b0; u8 b1; u8 pad2[2]; u8 b4; u8 b5; u8 pad6[0x12]; u8 *q18; s16 h1C; u8 pad1E[0x11E]; u8 b13C; } PS;
typedef struct { u8 pad[0x168]; u8 b168; u8 b169; } QS;
void func_0038E930(PS *p) {
    u32 t;
    if (p->b1 != p->q18[1]) {
        t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    if (((QS *)p->q18)->b169 != 0x16) {
        t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    if (((QS *)p->q18)->b168 != 8) {
        t = p->b5;
        p->b5 = t + 1;
        D_004C29C4[0] = 4;
        p->h1C = 2;
        return;
    }
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        D_004C29C4[7] = 0;
        if (*(s16 *)(p->q18 + 0x1C) <= 0) {
            t = p->b5;
            p->b5 = t + 1;
            D_004C29C4[0] = 4;
            p->h1C = 2;
        }
        func_0038E660(p);
        func_0038E6B0((S1C *)p);
    }
}
