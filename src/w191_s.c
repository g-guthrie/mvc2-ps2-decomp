typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    u8 pad0[0x34];
    V3 v34;
} R1D2;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 pad6[0x1C - 6];
    s16 h1C;
    u8 pad1E[2];
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 pad24[0x34 - 0x24];
    V3 v34;
    u8 pad40[0x13C - 0x40];
    s8 s13C;
} P1D2;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x1B2 - 6];
    s8 s1B2;
    u8 pad1B3;
    s8 s1B4;
    u8 pad1B5[0x1C4 - 0x1B5];
    R1D2 *w1C4;
    u8 pad1C8[0x1E4 - 0x1C8];
    u8 b1E4;
    u8 pad1E5[0x1FD - 0x1E5];
    u8 b1FD;
} Q1D2;

void func_001D2230(P1D2 *p, Q1D2 *q)
{
    extern s8 func_00175700();
    extern void func_001757E0(P1D2 *, s32, s32);
    u32 t;

    if (q->b1E4 != p->b22 || q->b5 != 0 || q->b1FD != p->h1C) {
        goto reset;
    }
    if (q->s1B2 != 0 && ((s8)q->s1B2 & 1) == 0 && p->b23 == 0) {
        p->s13C = 1;
        p->b23 = 1;
        p->v34 = q->w1C4->v34;
    }
    if (p->s13C != 0) {
        if (p->b5 == 0) {
            if (func_00175700(p) < 0) {
                if (q->s1B4 == 0) {
                    if (p->b21 != 0) {
                        goto reset;
                    }
                    t = p->b5;
                    p->b5 = t + 1;
                    func_001757E0(p, 0x17, (u8)(p->b20 * 3 + 0xE));
                }
            }
        } else {
            if (func_00175700(p) < 0) {
reset:
                t = p->b4;
                p->b4 = t + 1;
                p->s13C = 0;
            }
        }
    }
}
