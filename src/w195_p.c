typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PP {
    u8 pad0[0x20];
    u8 b20;
    u8 pad1;
    u8 b22;
    u8 pad2[0x34 - 0x23];
    f32 f34;
    f32 f38;
    u8 pad3[0x140 - 0x3C];
    s16 s140;
} PP;

typedef struct RR {
    u8 pad[0x34];
    f32 f34;
    f32 f38;
} RR;

extern s16 D_00462930[];
extern s16 D_00462932[];
extern s16 *D_004628B0[];
extern s16 *D_004628F0[];

void func_003532F0(PP *p, u8 *q, RR *r, u8 *idx) {
    f32 a, b, k;
    s16 *t;
    if (q[3] != 0) {
        a = 1.6666666269302368f * (f32)D_00462930[p->b22 * 2];
        b = 2.142857074737549f * (f32)D_00462932[p->b22 * 2];
    } else {
        if (p->b20 == 1) {
            t = D_004628B0[p->b22];
        } else {
            t = D_004628F0[p->b22];
        }
        t += (*idx >> 3);
        a = 1.6666666269302368f * (f32)t[0];
        b = 2.142857074737549f * (f32)t[1];
        if (p->b22 < 8) {
            a = -a;
        }
    }
    if (p->s140 != 0) {
        a = -a;
    }
    k = 0.9800000190734863f;
    p->f34 = r->f34 + k * a;
    p->f38 = r->f38 - k * b;
}
