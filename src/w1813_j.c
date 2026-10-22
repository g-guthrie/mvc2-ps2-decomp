typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4]; u8 b4; u8 b5; u8 pad6[0x16]; s16 h1C; s16 h1E; u8 pad20[0x18];
    f32 f38; u8 pad3c[0x24]; f32 f60; u8 pad64[0x10]; f32 f74; u8 pad78[0x64];
    s32 wDC; u8 padE0[0x5C]; u8 b13C;
} S14E;

extern f32 D_004442D0[];

void func_0014E1D0(u8 *actor_data)
{
    S14E *p = (S14E *)actor_data;
    s16 t = p->h1C;
    if (t != 0) {
        s16 v = p->h1C - 1;
        p->h1C = v;
        if (p->wDC != 0) {
            p->f38 += p->f60;
            p->f74 += 0.1f;
        } else {
            if (p->b4 == 1) {
                if (p->h1E == 2) p->f74 -= 0.1f;
            } else {
                if (p->h1E == 0) p->f74 -= 0.1f;
            }
            p->f38 += p->f60;
        }
    } else {
        p->b4 = 0;
        p->b5 = 0;
        if (p->wDC != 0) {
            p->b13C = 0;
            p->f74 = 0;
        } else {
            p->b13C = 1;
            p->f74 = 1.0f;
            p->f38 = D_004442D0[p->h1E];
        }
    }
}
