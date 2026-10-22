typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa3_f.c "-O3 -Op -sdatathreshold 8" */
typedef struct {
    u8 pad0[0x1C]; s16 h1C; s16 h1E; u8 pad20; u8 b21; u8 pad22[0x22]; s32 w44; u8 pad48[8];
    f32 f50; f32 f54; f32 f58; u8 pad5C[0x1C]; f32 f78; f32 f7c; f32 f80; s32 w84;
    u8 pad88[0x44]; s16 hCC;
} P_h;
extern f32 D_00445380[];
extern s32 D_004C2838;
extern void func_003DAA40(P_h *);

void func_0015DE10(P_h *p) {
    s32 d;
    f32 c1, c2;
    if (p->h1C < 7) {
        p->h1C = p->h1C + 1;
        return;
    }
    if (p->h1E > 10) {
        func_003DAA40(p);
        return;
    }
    p->hCC = 0xAA;
    p->w84 = D_004C2838;
    p->f78 = D_00445380[p->h1C];
    p->f7c = D_00445380[p->h1C];
    p->f80 = D_00445380[p->h1C];
    p->f50 += 0.1363636404f;
    p->f58 += 0.1363636404f;
    p->f54 -= 0.04545454681f;
    d = (p->b21 != 0) ? 0xBA3 : -0xBA3;
    p->w44 += d;
    p->h1E = p->h1E + 1;
}
