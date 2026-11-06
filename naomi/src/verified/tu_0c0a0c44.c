/* The direction flag negates both values; strength indexes unsigned float pairs. */
#include "objects.h"

typedef void (*ActorHandler_0c0a0c44)(struct Actor *);

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c2437b4[];
extern ActorHandler_0c0a0c44 table_0c243a14[];
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c19ee9c(struct Actor *, int);

void func_0c0a0c44(struct Actor *a)
{
    register float *motion;
    a->b6 = a->b6 + 1;
    if (a->b255 == 3) {
        a->b1a1 = 85;
    } else {
        goto L; L:
        a->b1a1 = a->b1a3 + 50;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    ++dat_0c2f83f8->arr[a->b2];

    goto M; M:
    motion = dat_0c2437b4;
    motion += (unsigned char)a->b1a3 * 2;
    a->f92 = a->b1d2 ? -motion[0] : motion[0];
    a->f104 = a->b1d2 ? -motion[1] : motion[1];
    func_0c0432ca(a);
}

void func_0c0a0cc4(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;

    if (a->b411 == 0 && a->b141 == 2) {
        func_0c19ee9c(a, 1);
        a->s28 = a->s28 + 1;
        a->b141 = 0;
    }
    if (a->f92 * a->f104 > 0.0f) {
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a0d64(struct Actor *a)
{
    table_0c243a14[a->b6](a);
}
