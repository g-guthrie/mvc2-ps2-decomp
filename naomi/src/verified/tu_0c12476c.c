/* Six actor callbacks, initializer fallthrough, and their shared pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*dat_0c24d6e8[])(struct Actor *);
extern void (*dat_0c24d6f4[])(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c042ad2(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c0344a0(struct Actor *, int), func_0c0346da(struct Actor *, int);
void func_0c124820(struct Actor *, char *);
void func_0c12476c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c12478e(struct Actor *a) { dat_0c24d6e8[a->b6](a); }
void func_0c1247a0(struct Actor *a, char *flags)
{
    int zero;
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1f9 = zero;
    a->f56 = a->f41c;
    a->b205 = 40;
    a->pad205[0] = 40;
    a->b1a1 = 59;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 3);
    func_0c124820(a, flags);
}
void func_0c124820(struct Actor *a, char *flags)
{
    struct LinkedActorVec3 position;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        int zero = 0;
        a->b141 = zero;
        a->b6++;
        position.x = 8.33333302f;
        position.y = 199.28571f;
        func_0c042ad2(a, &position, zero);
        a->s28 = 16;
        func_0c0344a0(a, 29);
        func_0c0346da(a, 80);
    }
}
void func_0c12487a(struct Actor *a)
{
    a->b328 = 5;
    func_0c02a026(a);
    if (a->s28-- == 0)
        func_0c0437b8(a);
}
void func_0c1248aa(struct Actor *a) { dat_0c24d6f4[a->b6](a); }
