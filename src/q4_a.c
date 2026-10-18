typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00278710(void *);
extern void func_00186CE0(void *, s32);
typedef struct { u8 b0; u8 pad[0x3D]; s8 b3E; } G;
extern G *D_004C2794;
void func_00278680(u8 *p) {
    func_00278710(p);
    {
        G *g = D_004C2794;
        if (g->b0 >= 5) {
            s32 t = g->b3E;
            if (t < 0 || t != p[2]) {
                if (p[5] == 0 && p[0x1E4] == 0) {
                    func_00186CE0(p, 0x15);
                    p[0x1FD] = 4;
                }
            }
        }
    }
    if (*(s16 *)(p + 0x434) == 0) p[0x209] = 1;
}

extern void func_001754A0(void *, s32, s32);
extern void func_001CF780(void *);
extern void func_001CF6A0(void *);
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x161-0x3C]; s8 b161; u8 pad2[6]; u16 h168; } Q1CF310;
typedef struct { u8 pad0[0x18]; Q1CF310 *f18; u8 pad1[0x34-0x1C]; f32 f34; f32 f38; u8 pad2[0x13C-0x3C]; u8 b13C; } P1CF310;
extern u16 *D_004C2718;
extern u8 D_004BFA70[2];
void func_001CF310(P1CF310 *p) {
    p->b13C = 1;
    p->f34 = p->f18->f34;
    p->f38 = p->f18->f38;
    if (*D_004C2718 == p->f18->h168 && p->f18->b161 != 0) {
        func_001754A0(p, 0x1B, D_004BFA70[(s8)p->f18->b161]);
    } else { func_001CF780(p); func_001CF6A0(p); }
}

extern s8 func_00175670();
extern s32 func_001AFC90(void *);
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad3C[0x12c]; u16 f168; } Q1AD;
typedef struct { u8 pad0[0x5]; u8 f5; u8 pad6[0x12]; Q1AD* f18; u8 pad1C[0x5]; u8 f21; u8 pad22[0x12]; f32 f34; f32 f38; } P1AD;
extern u16 *D_004C26D4;
s32 func_001ADF90(P1AD *p) {
    p->f34 = p->f18->f34;
    p->f38 = p->f18->f38;
    if (p->f5 == 0) {
        func_00175670(p);
        if (*D_004C26D4 != p->f18->f168) {
            u32 t = p->f5;
            p->f5 = t + 1;
            func_001754A0(p, 0x1B, (u8)(p->f21 + 0xC));
        }
    } else {
        if (func_00175670(p) < 0) return func_001AFC90(p);
    }
}

extern s32 func_00153AA0();
extern void func_00170DA0(void *, s32, s32, s16);
typedef struct { f32 a; f32 b; } T160;
extern T160 D_004B3DF0[];
extern void *D_004C2838;
typedef struct { u8 pad0[0x1c]; s16 f1C; u8 pad1E[0xae]; s16 fCC; u8 padCE[0x2]; u32 fD0; u8 padD4[0x8]; u32 fDC; f32 fE0; f32 fE4; } P160;
void func_001601A0(P160 *p) {
    T160 *t = D_004B3DF0; t += p->f1C;
    if (p->fDC != 0) {
        func_00170DA0(D_004C2838, 0x6B, func_00153AA0(), p->fCC);
    } else {
        func_00170DA0(D_004C2838, 0x69, func_00153AA0(), p->fCC);
    }
    { f32 y = t->b; p->fE0 = t->a; p->fE4 = y; }
    p->fD0 |= 0x20000;
}

extern void func_00184540();
extern void func_001843A0();
extern u8 D_00448990[];
extern void (*D_004489A0[])(void *);
typedef struct { u8 b0; } G178;
typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x15]; s16 f1C; u8 pad1E[0x11e]; u8 f13C; u8 pad13D[0x1c]; u8 f159; u8 pad15A[0x7a]; void* f1D4; u8 pad1D8[0x35]; u8 f20D; } P178;
void func_00178680(P178 *p) {
    s16 t = p->f1C - 1;
    p->f1C = t;
    if (t <= 0 || D_004C2794->b0 >= 5) {
        p->f13C = 1;
        p->f159 = 0;
        if (p->f20D == 2) func_00184540(p); else func_001843A0(p);
        return;
    }
    p->f13C = 0;
        p->f159 = 0xFF;
        p->f1D4 = D_00448990;
        D_004489A0[p->f6](p);
}
