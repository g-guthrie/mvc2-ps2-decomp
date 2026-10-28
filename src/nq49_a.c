typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3n49;
typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x34 - 6];
    V3n49 pos;
    u8 pad40[0x5C - 0x40];
    f32 f5c;
    f32 f60;
    f32 pad64;
    f32 f68;
    f32 f6c;
    u8 pad70[0x13C - 0x70];
    s8 b13c;
    u8 pad13d[3];
    s16 h140;
    u8 pad142[0x151 - 0x142];
    s8 b151;
} On49;

void residual_0019A9E0(On49 *p, On49 *q) {
    f32 d;
    s8 k;
    p->b13c = 1;
    k = q->b151;
    switch (k) {
    case 0:
        p->b13c = 0;
        return;
    case 3: {
        u32 t = p->b5;
        p->b5 = t + 1;
        *(u32 *)&p->f68 = 0;
        *(u32 *)&p->f5c = 0x3FD55555;
        if (p->h140 == 0) p->f5c = -p->f5c;
        *(u32 *)&p->f60 = 0x414DB6DB;
        *(u32 *)&p->f6c = 0xBF092492;
        return;
    }
    }
    p->pos = q->pos;
    if (q->b151 == 1) {
        d = 0.0f;
        p->pos.y += 240.0f;
    } else {
        d = -13.333333015441895f;
        p->pos.y += 274.28570556640625f;
    }
    if (p->h140 == 0) d = -d;
    p->pos.x += d;
}
