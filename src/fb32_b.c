typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 pad6[0x50 - 6];
    f32 f50;
    u8 pad54[0xDC - 0x54];
    s32 wDC;
    u8 pad_E0[0x13C - 0xE0];
    u8 b13C;
} P14C4C0;

typedef struct {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20[0x38 - 0x20];
    f32 f38;
    u8 pad3C[0x74 - 0x3C];
    f32 f74;
    u8 pad78[0x13C - 0x78];
    u8 b13C;
} G14C4C0;

extern G14C4C0 *D_004CAFF0;
extern G14C4C0 *D_004CAFF4;
extern G14C4C0 *D_004CAFF8;

void func_0014C4C0(P14C4C0 *p)
{
    extern s32 func_0012ABC0(s32, s32);
    extern void func_001E3CE0(s32);
    extern s32 func_00131660(void);
    extern s32 func_00131720(void);
    u32 a1;
    u32 s0;
    f32 f;

    a1 = func_0012ABC0(3, 0) & 0xFFFF;
    switch (p->b4) {
    case 0:
        return;
    case 1:
        p->b13C = 1;
        p->f50 += 0.2f;
        f = p->f50;
        if (f < 1.0f) return;
        p->f50 = 1.0f;
        D_004CAFF0->b13C = 1;
        D_004CAFF4->b13C = 1;
        D_004CAFF8->b13C = 1;
        p->b4++;
        p->b5 = 1;
        D_004CAFF8->f38 = -0.9f;
        break;
    case 2:
        s0 = a1 & 0xFFFF;
        if (s0 & 0x1000) {
            if (p->b5 == 0) {
                p->b5 = 1;
                D_004CAFF8->f38 = -0.9f;
                D_004CAFF8->f74 = 1.0f;
                D_004CAFF8->h1E = -9;
                func_001E3CE0(1);
            }
        }
        if (s0 & 0x2000) {
            if (p->b5 != 0) {
                p->b5 = 0;
                D_004CAFF8->f38 = 0.9f;
                D_004CAFF8->f74 = 1.0f;
                D_004CAFF8->h1E = -9;
                func_001E3CE0(1);
            }
        }
        if (func_00131660() != 0) {
            p->wDC = 1;
            goto inc;
        }
        if (func_00131720() == 0) return;
        p->wDC = 0;
        p->b5 = 1;
        goto inc;
    case 3:
        f = p->f50 - 0.2f;
        p->f50 = f;
        if (!(f <= 0.0f)) return;
        p->f50 = 0.0f;
        p->b4 = 0;
        break;
    default:
        break;
    }
    return;
inc:
    D_004CAFF0->b13C = 0;
    D_004CAFF4->b13C = 0;
    D_004CAFF8->b13C = 0;
    p->b4++;
}
