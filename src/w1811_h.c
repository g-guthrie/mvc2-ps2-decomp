typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x34 - 5];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x13C - 0x40];
    u8 b13C;
    u8 pad13D[3];
    s16 s140;
} Q;

typedef struct P {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x14 - 5];
    Q *p14;
    u8 pad18[0x23 - 0x18];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x13C - 0x40];
    u8 b13C;
    u8 pad13D[3];
    s16 s140;
} P;

void func_003716D0(P *p) {
    f32 k, x;
    if (p->p14->b4 == 2) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    p->s140 = p->p14->s140;
    p->f34 = p->p14->f34;
    p->f38 = p->p14->f38;
    p->f3C = p->p14->f3C;
    if (p->b23 != 0) {
        k = 112.0f;
        x = (p->s140 != 0) ? k : -k;
        p->f34 += x;
    } else {
        k = -18.66666603088379f;
        x = (p->s140 != 0) ? k : -k;
        p->f34 += x;
    }
    p->f38 -= 96.0f;
}
