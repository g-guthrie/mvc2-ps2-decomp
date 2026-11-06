#include "objects.h"
extern void (*table_0c23f9c0[])(struct Actor *);
extern void func_0c056bb8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c05aa64(struct Actor *a) { table_0c23f9c0[a->b6](a); }
void func_0c05aa76(struct Actor *a)
{
    if (a->b255 == 6) { a->b3f0 = 255; a->b3f1 = 16; }
    a->b6++;
    func_0c056bb8(a);
    a->b1a1 = 40;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 11);
}
void func_0c05aad2(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        a->b1a1 = 40;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->f96 = 34.285714f;
        a->f108 = -0.80357140303f;
        func_0c02a0c4(a, 21, 12);
        position.x = -40.0f;
        position.y = 154.28571f;
        func_0c0429a4(a, &position, 1);
    }
}
