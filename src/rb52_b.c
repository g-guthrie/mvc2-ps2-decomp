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
    u8 b6;
    u8 pad7[0x11];
    u8 *p18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x1C];
    f32 f3C;
    u8 pad40[0x24];
    f32 f64;
    u8 pad68[8];
    f32 f70;
    u8 pad74[4];
    f32 f78;
    f32 f7C;
    f32 f80;
    s32 w84;
    u8 pad88[0x44];
    s16 hCC;
    u8 padCE[0x6E];
    s8 b13C;
} P62;

typedef struct {
    u8 pad[0x9C];
    s8 b9C;
} G62;

extern G62 *D_004C2840;
extern s32 D_004C2838;
extern u8 D_004D18A6[];

void func_00162460(P62 *p)
{
    extern void func_00161880(P62 *);
    extern void func_00152550(P62 *, s32);
    s8 t;
    u32 u;
    s16 h;
    u8 r;

    t = D_004C2840->b9C;
    p->b13C = t;
    if (t == 0 || ((D_004C2840->b9C & 0xF) == 1 && D_004D18A6[0] != 0)) {
        p->b13C = 0;
        p->h1E = 0;
    }
    func_00161880(p);
    u = p->b6;
    p->b6 = u + 1;
    r = (u32)p->b6 % 5;
    p->b6 = r;
    if (r == 0) {
        h = p->h1C + 1;
        p->h1C = h;
        p->h1C = p->h1C % 16;
        if (p->h1C == 0) {
            p->b5 ^= 1;
            switch (p->b5) {
            default:
                p->hCC = 0x4F;
                p->w84 = D_004C2838;
                break;
            case 0:
                p->hCC = 0x4D;
                p->w84 = D_004C2838;
                break;
            }
        }
    }
    if (p->h1E != 0) {
        p->h1E -= 1;
        p->f64 += p->f70;
        p->f3C += p->f64;
        if (p->h1E <= 8) {
            p->f78 -= 0.125f;
            p->f7C -= 0.125f;
            p->f80 -= 0.125f;
        }
    } else {
        u8 *q = p->p18;
        u = q[6];
        q[6] = u - 1;
        u = p->b4;
        p->b4 = u + 1;
        func_00152550(p, 0);
    }
}
