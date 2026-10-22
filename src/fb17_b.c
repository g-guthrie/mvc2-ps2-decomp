typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C2664[1];
extern u8 D_004C2668[1];
extern u8 D_004C266C[1];

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x17];
    s16 h1c;
    u8 pad1e[2];
    u8 b20;
    u8 pad21[0x3F];
    f32 f60;
    u8 pad64[0x90];
    f32 fF4;
    u8 padF8[4];
    f32 fFC;
    f32 f100;
    f32 f104;
    f32 f108;
    f32 f10C;
    f32 f110;
    u8 pad114[4];
    f32 f118;
} P17;

void func_0016C060(P17 *p)
{
    extern void func_003DAA40(P17 *);
    f32 x, y, c1, c2;
    if (p->b4 == 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->h1c = 0x20;
        switch (p->b20) {
        case 0x26: x = 0.25f; y = 0.75f; break;
        case 0x2D: x = 0.375f; y = 0.75f; break;
        case 0x2E: x = 0.5f; y = 0.75f; break;
        case 0x21: x = 0.625f; y = 0.75f; break;
        case 0x28: x = 0.75f; y = x; break;
        case 0x29: x = 0.875f; y = 0.75f; break;
        default: {
            s32 n = p->b20 - 0x41;
            x = (f32)((n & 7) << 3) / 64.0f;
            y = (f32)((n >> 3) << 2) / 16.0f;
            break;
        }
        }
        c1 = 0.125f;
        c2 = 0.25f;
        p->f104 = x;
        p->f10C = c1 + x;
        p->f108 = y;
        p->f110 = c2 + y;
        if (D_004C2664[0] == 0) {
            p->fFC = c1;
            p->f100 = c2;
        } else {
            p->fFC = c2;
            *(u32 *)&p->f100 = 0x3F000000;
        }
    }
    if (D_004C266C[0] == 0) {
        p->fF4 += p->f60;
    }
    if (D_004C2668[0] != 0) {
        p->f118 -= 0.03125f;
        if (--p->h1c < 0) {
            func_003DAA40(p);
        }
    }
    if (p->fF4 < -48.0f) {
        func_003DAA40(p);
    }
}
