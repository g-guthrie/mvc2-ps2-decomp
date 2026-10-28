typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct { f32 x, y; } V2_175;
typedef struct {
    u8 pad0[0x142];
    u16 h142;
    u8 pad144[0xC];
    V2_175 v150;
    s32 w158;
    s32 w15C;
    s32 w160;
    u8 *volatile cur;
    u8 b168;
    u8 b169;
    u8 pad16A[0xE];
    u8 *base;
} P175;

typedef struct { u8 pad0[0x152]; s8 b152; s8 b153; } PB175;

s32 func_00175580(P175 *p, u8 a, u8 b, s32 c)
{
    u8 *t;
    PB175 *pb = (PB175 *)p;
    p->b169 = a;
    p->b168 = b;
    t = p->base + p->h142;
    t = p->base + *(s32 *)(t + a * 4);
    p->cur = p->base + *(s32 *)(t + b * 4);
    p->cur += c * 8;
    p->v150 = *(V2_175 *)p->cur;
    p->w158 = 0;
    p->w15C = 0;
    p->w160 = 0;
    if (pb->b152 == 0) {
        do {
            p->cur += 8;
            if (pb->b153 & 0x80) {
                p->cur = p->base + *(s32 *)p->cur;
            }
            p->v150 = *(V2_175 *)p->cur;
            p->w158 = 0;
            p->w15C = 0;
            p->w160 = 0;
        } while (pb->b152 == 0);
    }
    return 0;
}
