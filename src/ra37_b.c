typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

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

typedef struct G14F { u8 pad0[6]; s8 b6; } G14F;
typedef struct P14F {
    u8 pad0[0x18]; struct P14F *f18; u8 pad1c[2]; s16 h1E; u8 pad20[3]; u8 b23;
    u8 pad24[0x74 - 0x24]; f32 f74; u8 pad78[0x84 - 0x78]; s32 f84;
    u8 pad88[0xCC - 0x88]; s16 hCC; u8 padCE[0x13C - 0xCE]; s8 b13C;
} P14F;

extern G14F *D_004C2840;
extern s32 D_004C27FC;

void func_0014F0E0(P14F *p)
{
    s32 x, r;
    func_0014E770((u8 *)p);
    if (p->b23 != 0) {
        x = D_004C2840->b6 + p->h1E + 1;
        r = x / 10;
        if (r != 0) {
            p->b13C = 1;
            p->b13C = p->f18->b13C;
            p->hCC = r + 0x1A;
            p->f84 = D_004C27FC;
        } else {
            p->b13C = 0;
        }
    } else {
        x = D_004C2840->b6 + p->h1E + 1;
        r = x % 10;
        p->b13C = p->f18->b13C;
        p->hCC = r + 0x1A;
        p->f84 = D_004C27FC;
    }
    p->f74 = p->f18->f74;
}
