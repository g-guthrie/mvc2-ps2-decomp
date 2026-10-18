typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern s16 D_004C0958[4];

typedef struct Q286 {
    u8 pad0[0xD];
    u8 b0D;
    u8 pad1[0x10];
    s16 h1E;
} Q286;
typedef struct P286 {
    u8 pad0[0x34];
    f32 f34;
    u8 pad1[0x17C];
    s8 b1B4;
    u8 pad2[0x103];
    Q286 q;
} P286;
typedef struct G286 {
    u8 pad[0x1C];
    u32 w1C;
} G286;
extern G286 *D_004C2840;

void func_00286C70(P286 *p) {
    Q286 *q = &p->q;
    if (p->b1B4 == 0) {
        s16 v = q->h1E;
        if (v != 0) {
            q->h1E = v - 1;
        }
    }
    if (q->b0D != 0) {
        if (p->b1B4 != 0) {
            p->f34 += 1.6666666f * (f32)D_004C0958[D_004C2840->w1C & 3];
        } else {
            q->b0D = 0;
        }
    }
}
