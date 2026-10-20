/* MWCCPS2 3.0-011126: -O3 -Op -sdatathreshold 0. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x, y; } Pair;

extern Pair D_00462A40[];
extern Pair D_00462A80[];
extern void func_00352FA0(u8 *, u8 *);
extern void func_00353060(u8 *, u8 *);
extern void func_003530D0(u8 *, u8 *);

void func_00353140(u8 *p, u8 *sequence, u8 *q)
{
    f32 fx;
    f32 fy;

    if (q[0x1E4] == 0x15) {
        if (q[0x1FD] == 0) {
            func_00352FA0(p, q);
            return;
        }
        if (q[0x1FD] != 8)
            goto skip8;
        func_00353060(p, q);
        return;
    skip8:
        ;
    }
    if (q[0x169] == 0x13) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = 291.4285583496094f + *(f32 *)(q + 0x38);
        return;
    }
    if (q[0x169] == 0xF) {
        if (q[0x168] == 8 || q[0x168] == 9) {
            func_003530D0(p, q);
            return;
        }
    }
    if (q[0x20D] != 2) {
        fx = 1.6666666269302368f * (f32)D_00462A40[p[0x22]].x;
        fy = 2.142857074737549f * (f32)D_00462A40[p[0x22]].y;
    } else {
        fx = 1.6666666269302368f * (f32)D_00462A80[p[0x22]].x;
        fy = 2.142857074737549f * (f32)D_00462A80[p[0x22]].y;
    }
    if (*(s16 *)(q + 0x140) != 0)
        fx = -fx;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + fx;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) - fy;
}
