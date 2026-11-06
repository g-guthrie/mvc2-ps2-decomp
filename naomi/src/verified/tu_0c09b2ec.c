#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c148d54(struct Actor *, int, int);
extern void (*table_0c24355c[])(struct Actor *, struct ActorSub2a4 *);
void func_0c09b3e6(struct Actor *a, struct ActorSub2a4 *sub);

void func_0c09b2ec(struct Actor *a)
{
    table_0c24355c[a->b6](a, &a->sub2a4);
}

void func_0c09b302(register struct Actor *a, struct ActorSub2a4 *sub)
{
    register void *zero;
    a->b6++;
    zero = 0;
    if (a->b255 == 3)
        a->b1a1 = 83;
    else {
        goto L; L: a->b1a1 = 54; }
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(unsigned int *)&a->p1c4 = (unsigned int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    goto M; M:
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = (int)zero;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    if (func_0c148d54(a, 0, 0))
        *(unsigned char *)&sub->w8 = (int)zero;
    else
        *(unsigned char *)&sub->w8 = 1;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, a->b1a3 + 15);
}

void func_0c09b3b6(struct Actor *a, struct ActorSub2a4 *sub)
{
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c09b3e6(a, sub);
    }
}

void func_0c09b3e6(struct Actor *a, struct ActorSub2a4 *sub)
{
    func_0c02a026(a);
    if (*(unsigned char *)&sub->w8) {
        a->b6++;
        func_0c02a0c4(a, 21, a->b1a3 + 17);
    }
}
