struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[6]; u8 c6; u8 p1[0x55]; f32 f5C; u8 p2[8]; s32 w68; u8 p3[0xE5]; s8 f151; u8 p4[0x65]; u8 c1B7; u8 p5[0x2E]; u8 c1E6; } S_002D8080;
extern void func_00175700(S_002D8080 *);
extern f32 D_004C0FD0[2];
void func_002D8080(S_002D8080 *p) {
    func_00175700(p);
    if (p->f151 != 0) {
        u32 t = p->c6;
        p->c6 = t + 1;
        p->f5C = D_004C0FD0[p->c1B7];
        if (p->c1E6 == 0) p->f5C = -p->f5C;
        p->w68 = 0;
    }
}

extern s8 D_004F1F42[16];
extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
void func_001264D0(void) {
    if (D_004F1F42[0] != 2) {
        if (D_004C25D4[1] == 0x1A) {
            D_004F1F42[0] = 4;
        } else if (D_004C25D0[1] == 0x1A) {
            D_004F1F42[0] = 3;
        } else {
            D_004F1F42[0] = 0;
        }
    }
}

typedef struct { u8 p0[0x91]; u8 c91; } G_003D3E10;
typedef struct { u8 p0[2]; u8 c2; u8 p1[5]; s16 h8; s16 hA; s8 cC; } S_003D3E10;
extern G_003D3E10 *D_004C2840;
extern void func_003D3DD0(void);
extern void func_003D7310(void (*)(void));
void func_003D3E10(S_003D3E10 *a) {
    D_004C2840->c91 = 1;
    if (a->cC == 0) {
        if (a->hA != 0) {
            a->hA = a->hA - 1;
        } else {
            a->cC = a->cC + 1;
            a->hA = 1;
        }
    } else {
        if (a->h8 != 0) {
            a->h8 = a->h8 - 1;
        } else {
            u32 t = a->c2;
            if (t != 0x60) a->c2 = t + 1;
        }
    }
    func_003D7310(func_003D3DD0);
}

typedef struct { u8 p0[2]; u8 c2; u8 p1[3]; u8 c6; u8 p2[0x55]; s32 w5C, w60; u8 p3[4]; s32 w68, w6C; u8 p4[0x142]; u8 c1B2; u8 p5[2]; u8 c1B5; u8 p6[10]; u16 h1C0; u8 p7[0x16]; s32 w1D8; } S_002F5530;
extern void func_00185490(S_002F5530 *);
extern void func_001757E0(S_002F5530 *, s32, s32);
typedef struct { u8 pad[0x7C]; s16 h[16]; } G_002F5530;
extern G_002F5530 *D_004C2794;
void func_002F5530(S_002F5530 *p) {
    u32 t = p->c6;
    p->c6 = t + 1;
    func_00185490(p);
    p->w5C = 0;
    p->w60 = 0;
    p->w68 = 0;
    p->w6C = 0;
    p->c1B5 = 0x3D;
    p->c1B2 = p->h1C0 = 0;
    p->w1D8 = 0;
    D_004C2794->h[p->c2] = D_004C2794->h[p->c2] + 1;
    func_001757E0(p, 0x16, 2);
}

typedef struct { u8 p0[0x1C]; s16 h1C, h1E; u8 p1[0x54]; f32 f74; u8 p2[0xC]; s32 w84; u8 p3[0x44]; s16 hCC; } S_0015DF20;
typedef struct { s16 v; s16 pad; } E_0015DF20;
extern void func_003DAA40(struct Object *);
extern E_0015DF20 D_004453E0[];
extern f32 D_004453B0[];
extern s32 D_004C2838;
void func_0015DF20(S_0015DF20 *a) {
    if (a->h1C < 9) {
        a->h1C = a->h1C + 1;
    } else if (a->h1E > 10) {
        func_003DAA40((struct Object *)a);
    } else {
        a->hCC = D_004453E0[a->h1E].v;
        a->w84 = D_004C2838;
        a->f74 = D_004453B0[a->h1E];
        a->h1E = a->h1E + 1;
    }
}
