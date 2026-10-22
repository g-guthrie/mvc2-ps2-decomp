typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/sa9_g.c "-O3,p -sdatathreshold 8" */

typedef struct { u8 b0; u8 pad[23]; } R14F;
typedef struct { u8 pad0[4]; s8 b4; u8 pad1; s8 b6; } G14F;
typedef struct Q14F {
    u8 pad0[0x18];
    struct Q14F *f18;
    u8 pad1[0x1E - 0x1C];
    s16 h1E;
    u8 pad2[0x23 - 0x20];
    u8 b23;
    u8 pad3[0x74 - 0x24];
    f32 f74;
    u8 pad4[0x84 - 0x78];
    s32 f84;
    u8 pad5[0xCC - 0x88];
    s16 hCC;
    u8 pad6[0x13C - 0xCE];
    s8 b13C;
} Q14F;

extern G14F *D_004C2840;
extern s32 D_004C27FC;
extern R14F D_004D1578[];
extern R14F D_004F7D38[];

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

void func_0014F2D0(Q14F *p)
{
    u32 v;
    func_0014E770((u8 *)p);
    if (p->b23 != 0) {
        if (D_004C2840->b4 != 0) v = D_004D1578[D_004C2840->b6 + p->h1E].b0 / 10;
        else v = D_004F7D38[D_004C2840->b6 + p->h1E].b0 / 10;
        if (v != 0) {
            p->b13C = 1;
            p->b13C = p->f18->b13C;
            p->hCC = v + 0x25;
            p->f84 = D_004C27FC;
        } else {
            p->b13C = 0;
        }
    } else {
        if (D_004C2840->b4 != 0) v = D_004D1578[D_004C2840->b6 + p->h1E].b0 % 10;
        else v = D_004F7D38[D_004C2840->b6 + p->h1E].b0 % 10;
        p->b13C = p->f18->b13C;
        p->hCC = v + 0x25;
        p->f84 = D_004C27FC;
    }
    p->f74 = p->f18->f74;
}
