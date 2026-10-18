typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b, c; } E6;
extern E6 D_0044B470[];

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x20 - 5];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    f32 f34, f38;
    u8 pad3c[0x13C - 0x3C];
    u8 b13C;
    u8 pad13D[0x140 - 0x13D];
    s16 h140;
} S1A7;

void func_001A7DC0(S1A7 *p, S1A7 *q) {
    extern s32 func_00175670(S1A7 *);
    E6 *e;
    if ((s8)func_00175670(p) < 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    e = &D_0044B470[p->b20];
    if (p->h140 == 0) {
        p->f34 = q->f34 + 1.6666666269302368f * (f32)e->a;
    } else {
        p->f34 = q->f34 - 1.6666666269302368f * (f32)e->a;
    }
    p->f38 = q->f38 + 2.142857074737549f * (f32)e->b;
}
