typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s8 *D_004C299C;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
static void func_0037F3A0() {
    u8 *p = (u8 *)D_004C299C;
    if (p[2] < 10) {
        if (--p[3] <= 0) {
            ((u8 *)D_004C299C)[3] = 1;
            ((u8 *)D_004C299C)[2]++;
        }
    }
}
static void func_0037F3F0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        ((s16 *)p)[14] = 1;
        D_004C299C[0]++;
        if (7 <= D_004C299C[0]) D_004C299C[0] = 4;
    }
}
typedef struct { u8 b0; u8 b1; u8 pad2[2]; u8 b4; u8 b5; u8 pad6[0x12]; u8 *q18; s16 h1C; u8 pad1E[0x11E]; u8 b13C; } PS;
typedef struct { u8 pad[0x168]; u16 h168; } QS;
void func_0037F7C0(u8 *actor, void *owner) {
    PS *p = (PS *)actor;
    u32 t;
    if (p->b1 != p->q18[1]) {
        t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    if (((QS *)p->q18)->h168 != 0x1503) {
        t = p->b5;
        p->b5 = t + 1;
        D_004C299C[0] = 3;
        p->h1C = 1;
        return;
    }
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        D_004C299C[7] = 0;
        if (*(s16 *)(p->q18 + 0x1C) <= 0) {
            t = p->b5;
            p->b5 = t + 1;
            D_004C299C[0] = 3;
            p->h1C = 1;
        }
        func_0037F3A0(p);
        func_0037F3F0((u8 *)p);
    }
}
