/* Three actor phase callbacks and their shared pool. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
void func_0c124174(struct Actor *, char *);
void func_0c1240d8(struct Actor *a, char *flags)
{
    int zero;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1f9 = zero;
    a->f56 = a->f41c;
    flags[19] = zero;
    flags[2] = zero;
    a->b1a1 = 57;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 11);
    func_0c124174(a, flags);
}
void func_0c124174(struct Actor *a, char *flags)
{
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        int zero = 0;
        a->b141 = zero;
        a->b7++;
        a->b3f0 = zero;
        a->b3f1 = zero;
        position.x = 80.0f;
        position.y = 120.0f;
        func_0c0429a4(a, &position, 1);
    }
}
void func_0c1241dc(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 22, 12);
        a->s28 = a->b141;
    }
}
