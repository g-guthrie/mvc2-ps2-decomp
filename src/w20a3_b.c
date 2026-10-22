typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct P4 {
    u8 pad0[0x18];
    struct P4 *f18;
    u8 pad1c[2];
    s16 f1E;
    u8 pad20[3];
    u8 f23;
    u8 pad24[0x60];
    s32 f84;
    u8 pad88[0x44];
    s16 fCC;
    u8 padCE[0x6];
} P4;
typedef struct { s8 pad[4]; s8 f4; s8 f5; s8 f6; } G4;
typedef struct { s8 b[24]; } E4;
extern G4 *D_004C2840;
extern s32 D_004C27FC;
extern E4 D_004D157B[];
extern E4 D_004F7D3B[];

static void func_0014E770(P4 *p) { p->f84 = 0; }

void func_0014FB00(P4 *p) {
    G4 *g;
    s32 v;
    func_0014E770(p);
    *(s8 *)((u8 *)p + 0x13C) = *(s8 *)((u8 *)p->f18 + 0x13C);
    if (p->f23 != 0) {
        g = D_004C2840;
        if (g->f4 != 0) v = ((s8 *)D_004D157B)[(g->f6 + p->f1E) * 24] / 10;
        else v = ((s8 *)D_004F7D3B)[(g->f6 + p->f1E) * 24] / 10;
        p->fCC = v + 0x25;
        p->f84 = D_004C27FC;
    } else {
        g = D_004C2840;
        if (g->f4 != 0) v = ((s8 *)D_004D157B)[(g->f6 + p->f1E) * 24] % 10;
        else v = ((s8 *)D_004F7D3B)[(g->f6 + p->f1E) * 24] % 10;
        p->fCC = v + 0x25;
        p->f84 = D_004C27FC;
    }
    *(f32 *)((u8 *)p + 0x74) = *(f32 *)((u8 *)p->f18 + 0x74);
}
