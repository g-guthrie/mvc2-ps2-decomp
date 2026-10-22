typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct SA37_LQ {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x24 - 6];
    s8 b24;
    u8 pad25[0x34 - 0x25];
    f32 f34, f38, f3c;
    u8 pad40[0x169 - 0x40];
    u8 b169;
} SA37_LQ;

typedef struct SA37_LP {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 pad6[0x21 - 6];
    u8 b21;
    u8 pad22[0x24 - 0x22];
    s8 b24;
    u8 pad25[0x31 - 0x25];
    s8 b31;
    u8 pad32[0x34 - 0x32];
    f32 f34, f38, f3c;
    u8 pad40[0x140 - 0x40];
    s16 h140;
} SA37_LP;

extern s16 D_004C1F90[16];
extern s16 D_004C1F92[16];
extern void (*D_00473CF0[])(SA37_LP *, SA37_LQ *);

void func_003B1360(SA37_LP *p, SA37_LQ *q) {
    extern void func_003B1A50();
    u32 t;
    p->b24 = q->b24 + p->b31;
    if (p->b24 > 7) p->b24 = 7;
    if (p->b24 < 0) p->b24 = 0;
    if (q->b169 != 0x15) {
        t = p->b4;
        p->b4 = t + 1;
        func_003B1A50(p, q);
        return;
    }
    if (q->b5 != 0) {
        t = p->b4;
        p->b4 = t + 1;
        func_003B1A50(p, q);
    } else {
        p->f34 = q->f34;
        p->f38 = q->f38;
        p->f3c = q->f3c;
        if (p->h140 == 0) {
            p->f34 += 1.6666666269302368f * (f32)D_004C1F90[p->b21 * 2];
        } else {
            p->f34 -= 1.6666666269302368f * (f32)D_004C1F90[p->b21 * 2];
        }
        p->f38 += 2.142857074737549f * (f32)D_004C1F92[p->b21 * 2];
        D_00473CF0[p->b5](p, q);
    }
}
