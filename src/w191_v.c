typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x40];
    s8 b40;
} G280;

typedef struct P280 P280;
struct P280 {
    u8 pad0[0x220];
    P280 *p220;
    u8 pad224[0x434 - 0x224];
    s16 h434;
    u8 pad436[0x470 - 0x436];
    u8 b470;
    u8 pad471[0x496 - 0x471];
    u8 b496;
};

extern G280 *D_004C2794;
extern u8 D_00455490[];
extern u8 D_004554A0[];

s32 func_00280750(P280 *p)
{
    s32 x;
    s32 t;
    s32 u;
    s32 v;
    s32 w;
    u8 old;

    if (p->b496 != 0) {
        return 0;
    }
    t = D_004C2794->b40;
    x = (s16)(p->h434 - p->p220->h434 + 0x90);
    u = D_00455490[9 - t / 10];
    v = D_004554A0[0x28 - x / 10];
    if (u < v) {
        u = v;
    }
    old = p->b470;
    w = (u8)u % 4;
    p->b470 = w;
    if (p->b470 != old) {
        return 1;
    }
    return 0;
}
