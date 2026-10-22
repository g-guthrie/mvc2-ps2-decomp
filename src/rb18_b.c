typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C283C;

typedef struct { u8 p0[0x1C]; s16 h1C, h1E; u8 p1[0x50-0x20]; f32 f50; u8 p2[0x74-0x54]; f32 f74; u8 p3[0x84-0x78]; s32 w84; u8 p4[0xCC-0x88]; s16 hCC; } SB;

s32 func_00334C40(SB *p)
{
    f32 z;
    s32 v;
    f32 a;
    if (p->h1E > 8) {
        p->h1C = 0;
        p->h1E = 0;
        z = 0.0f;
        if (z == p->f74) {
            p->f74 = 1.0f;
        }
        return 1;
    }
    if (p->h1C == 0) {
        v = (s16)(p->h1E + 0x1B);
        if (v > 0x22) {
            v = 0x22;
        }
        p->hCC = v;
        p->w84 = D_004C283C;
    }
    p->h1C = p->h1C + 1;
    p->f74 -= 0.0125f;
    z = 0.0f;
    if (p->f74 < z) {
        p->f74 = z;
    }
    if (p->f50 < 1.0f) {
        p->f50 += 0.0125f;
        if (p->f50 >= 1.0) {
            p->f50 = 1.0f;
        }
    }
    if (p->h1C > 7) {
        p->h1C = 0;
        p->h1E = p->h1E + 1;
    }
    return 0;
}
